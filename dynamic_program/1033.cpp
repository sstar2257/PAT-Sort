#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct station {
	double dis;
	double price;
};

struct oil {
	double price;
	double capa;
};

bool comp(station a, station b) {
	return a.dis < b.dis;
}


//快被自己蠢死了。。。。做数据处理的时候，不要把测试用例的数字写进去。。。。
//正统的做法应该是用贪心算法
//为了计算方便，统一到最后结算油价，先以公里数代替
int main()
{
	double C, D, Avg;
	int N;
	cin >> C >> D >> Avg >> N;
	vector<station> road;
	station tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp.price >> tmp.dis;
		road.push_back(tmp);
	}
	tmp.dis = D;
	tmp.price = 0;
	road.push_back(tmp);

	sort(road.begin(), road.end(), comp);

	double u = C * Avg;

	vector<oil> can;
	double cost = 0;
	//起点加满油,须判断起点是不是有加油站
	oil unit;
	if (road[0].dis != 0) {
		printf("The maximum travel distance = 0.00");
		return 0;
	}

	unit.capa = u;
	unit.price = road[0].price;
	cost = u * road[0].price;
	can.push_back(unit);
	for (int i = 1; i < road.size(); i++) {
		//如果有超过终点的加油站，请忽略
		if (road[i].dis > D)
			break;
		double gap = road[i].dis - road[i-1].dis;
		double new_price = road[i].price;
		//这个点不能写600...不要被测试用例干扰了
		if (gap > u) {
			printf("The maximum travel distance = %.02lf", road[i-1].dis + u);
			return 0;
		}
		//先去除消耗的油,不会出现消耗比已存储多的情况
		double flag = gap;
		while (flag != 0) {
			if (can[0].capa > flag) {
				can[0].capa -= flag;
				flag = 0;
			}
			else {
				flag -= can[0].capa;
				can.erase(can.begin());
			}
		}
		//补充消耗的油
		unit.capa = gap;
		unit.price = new_price;
		//cost += gap*new_price;
		//can.push_back(unit);
		//更新油桶
		vector<oil> tmp_can;
		for (int j = 0; j < can.size(); j++) {
			if (new_price <= can[j].price) {
				//cost -= can[j].capa * (can[j].price - new_price);
				//can[j].price = new_price;
				cost -= can[j].capa * can[j].price;
				unit.capa += can[j].capa;
			}
			else {
				tmp_can.push_back(can[j]);
			}
		}
		cost += unit.capa * unit.price;
		tmp_can.push_back(unit);
		can.clear();
		can.swap(tmp_can);
	}
	//！！！这里不能直接除以12
	printf("%.02lf", cost / Avg);
	return 0;
}

//需要考虑几个特殊情况
//1.出发点没有加油站
//2.目的地后还有加油站,没有这个case
//3.一个地方有多个加油站