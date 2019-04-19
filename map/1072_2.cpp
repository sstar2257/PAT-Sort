#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

struct sta {
	string id;
	double min;
	double ave;
};

int dis[1011][1011];
int N, M, K, D;
vector<sta> list;

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

void dijksra(int no) {
	int *d = new int[N + M + 1]();
	int *visit = new int[N + M + 1]();
	for (int i = 1; i <= N + M; i++) {
		d[i] = dis[no][i];
	}
	d[no] = 0;
	visit[no] = 1;
	int min, index;
	int flag = 0;
	for (int i = 1; i <= N + M; i++) {
		min = 0x3f3f3f3f;
		index = -1;
		for (int j = 1; j <= N + M; j++) {
			if (d[j] < min && !visit[j]) {
				min = d[j];
				index = j;
			}
		}
		if (index == -1) {
			sta tmp;
			tmp.id = "G" + to_string(no - N);
			tmp.min = 0x3f3f3f3f;
			tmp.ave = 0;
			for (int j = 1; j <= N; j++) {
				if (d[j] > D) {
					flag = 1;
					break;
				}
				if (tmp.min > d[j]) {
					tmp.min = d[j];
				}
				tmp.ave += d[j];
			}
			if (!flag) {
				tmp.ave /= N;
				list.push_back(tmp);
			}
			break;
		}
		visit[index] = 1;
		for (int j = 1; j <= M + N; j++) {
			if (!visit[j] && d[index] + dis[index][j] < d[j]) {
				d[j] = d[index] + dis[index][j];
			}
		}

	}

}

//dijksra算法
//还有一个隐藏的限制条件
//1.到各个居民点的距离必须小于等于 加油站的最大服务距离Ds。
//2.再满足1的加油站点中，优先选择min_dis最大的那个点。
int main()
{
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

	for (int i = N + 1; i <= N + M; i++) {
		dijksra(i);
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