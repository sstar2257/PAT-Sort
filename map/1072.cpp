#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int dis[1011][1011];
struct sta {
	string id;
	double min;
	double ave;
};

bool comp(sta a, sta b) {
	if (a.min != b.min) {
		return a.min > b.min;
	}
	else if (a.ave != b.ave) {
		return a.ave < b.ave;
	}
	else {
		return a.id < b.id;
	}
}

//用Floyd算法会超时，只需要对几个加油站用dijksra算法
//还有一个隐藏的限制条件
//1.到各个居民点的距离必须小于等于 加油站的最大服务距离Ds。
//2.再满足1的加油站点中，优先选择min_dis最大的那个点。
int main()
{
	int N, M, K, D;
	cin >> N >> M >> K >> D;
	memset(dis, 0x3f, 1011 * 1011 * sizeof(int));
	string str1, str2;
	//str1.resize(3);
	//str2.resize(3);
	int x, y, val;
	for (int i = 0; i < K; i++) {
		cin >> str1 >> str2 >> val;
		//scanf("%s %s %d", str1.c_str(), str2.c_str(), &val);
		if (str1[0] == 'G') {
			str1 = str1.substr(1);
			x = stoi(str1) + N;
		}
		else {
			x = stoi(str1);
		}
		if (str2[0] == 'G') {
			str2 = str2.substr(1);
			y = stoi(str2) + N;
		}
		else {
			y = stoi(str2);
		}
		dis[x][y] = dis[y][x] = val;

	}
	int u, v, w;
	for (u = 1; u <= N + M; u++) {
		for (v = 1; v <= N + M; v++) {
			for (w = 1; w <= N + M; w++) {
				if (dis[v][u] + dis[u][w] < dis[v][w])
					dis[v][w] = dis[v][u] + dis[u][w];
			}
		}
	}

	int is_ok;
	vector<sta> list;
	for (int i = N + 1; i <= N + M; i++) {
		sta tmp;
		tmp.min = 0x3f3f3f3f;
		tmp.ave = 0;
		tmp.id = "G" + to_string(i - N);
		is_ok = 1;
		for (int j = 1; j <= N; j++) {
			if (dis[i][j] > D) {
				is_ok = 0;
				break;
			}
			if (dis[i][j] < tmp.min) {
				tmp.min = dis[i][j];
			}
			tmp.ave += dis[i][j];
		}
		if (!is_ok) {
			continue;
		}
		else {
			tmp.ave /= N;
			list.push_back(tmp);
		}
	}

	int len = list.size();
	if (!len) {
		cout << "No Solution";
	}
	else {
		sort(list.begin(), list.end(), comp);
		printf("%s\n", list.begin()->id.c_str());
		printf("%.1lf %.1lf", list.begin()->min, list.begin()->ave);
	}

	return 0;
}