#include <iostream>
#include <string.h>
#include <string>
#include <map>
#include <vector>
using namespace std;
//基本算法dijksra，深度优先搜索应该也可以
//几个判断比较恶心
int main()
{
	int N, K;
	string begin;
	cin >> N >> K >> begin;
	//map<string, int> happiness;
	int happiness[200] = { 0 };
	map<string, int> city2num;
	map<int, string> num2city;
	city2num[begin] = 0;
	num2city[0] = begin;
	string city;
	int happy;
	for (int i = 0; i < N - 1; i++) {
		cin >> city >> happy;
		city2num[city] = i + 1;
		happiness[i + 1] = happy;
		num2city[i + 1] = city;
	}
	string city1, city2;
	int cost;

	int table[200][200];
	memset(table, 0x3f, 200 * 200 * sizeof(int));
	for (int i = 0; i < K; i++) {
		cin >> city1 >> city2 >> cost;
		table[city2num[city1]][city2num[city2]] = table[city2num[city2]][city2num[city1]] = cost;
	}

	int mark[200] = { 0 };
	int dis[200];
	int happ_sum[200] = { 0 };
	int city_pass[200] = { 0 };
	int pre[200];
	int paths[200] = { 0 };
	paths[0] = 1;
	memset(pre, -1, 200 * sizeof(int));
	happ_sum[0] = 0;
	mark[0] = 1;
	dis[0] = 0;
	for (int i = 1; i < N; i++) {
		dis[i] = table[0][i];
		happ_sum[i] = happiness[i];
		if (dis[i] != 0x3f3f3f3f) {
			pre[i] = 0;
			city_pass[i] = 1;
			paths[i] = 1;
		}
	}

	int min;
	int index;

	for (int i = 0; i < N; i++) {
		min = 0x3f3f3f3f;
		index = -1;
		for (int j = 1; j < N; j++) {
			if (dis[j] < min && !mark[j]) {
				min = dis[j];//!!!!!犯了sb的错误
				index = j;
			}
		}
		if (index == -1) {
			break;
		}
		mark[index] = 1;
		//在进行计算时多使用直接赋值，不要用+=，容易边界外出错
		for (int j = 1; j < N; j++) {
			if (!mark[j] && dis[index] + table[index][j] < dis[j]) {
				dis[j] = dis[index] + table[index][j];			
				happ_sum[j] = happ_sum[index] + happiness[j];
				pre[j] = index;
				city_pass[j] = city_pass[index] + 1;
				paths[j] = paths[index];
			}
			else if (!mark[j] && dis[index] + table[index][j] == dis[j]) {
				paths[j] += paths[index];
				//if (happ_sum[index] > happ_sum[pre[j]]) {
				if (happ_sum[index] + happiness[j] > happ_sum[j]) {
					happ_sum[j] = happ_sum[index] + happiness[j];
					pre[j] = index;
					city_pass[j] = city_pass[index] + 1;
				}
				//else if (happ_sum[index] == happ_sum[pre[j]]) {
				else if (happ_sum[index] + happiness[j] == happ_sum[j]) {
					if (city_pass[j] > city_pass[index] + 1) {
						city_pass[j] = city_pass[index] + 1;
						pre[j] = index;
					}
				}
			}
		}
	}
	int rom = city2num["ROM"];
	vector<int> res;
	while (pre[rom]) {
		res.push_back(rom);
		rom = pre[rom];
	}
	res.push_back(rom);
	rom = city2num["ROM"];
	cout << paths[rom] << " " << dis[rom] << " " << happ_sum[rom] << " " << happ_sum[rom] / res.size() << endl;
	cout << begin;
	for (int i = res.size() - 1; i >= 0; i--) {
		cout << "->" << num2city[res[i]];
	}

	return 0;
}