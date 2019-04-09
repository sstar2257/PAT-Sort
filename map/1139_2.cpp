#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string.h>
#include <string>
using namespace std;

vector<int> table[20001];
bool mark[20001];
vector <pair<int, int>> line;

void connect(int a, int b) {
	if (a >= 10001 && b >= 10001) {//都是男孩子
		for (int i = 0; i < table[b].size(); i++) {
			if (table[b][i] >= 10001 && table[b][i] != a) {//注意b的好友里如果有a，这个a不能置true
				mark[table[b][i]] = true;
			}
		}
		for (int i = 0; i < table[a].size(); i++) {
			if (table[a][i] >= 10001 && table[a][i] != b) {//同理，a的好友里有b，这个b不能计入统计
				for (int j = 0; j < table[table[a][i]].size(); j++) {
					if (mark[table[table[a][i]][j]])
						line.push_back(make_pair(table[a][i] - 10001, table[table[a][i]][j] - 10001));
				}
			}
		}
	}
	else if (a >= 10001 && b <= 10000) {//男追女
		for (int i = 0; i < table[b].size(); i++) {
			if (table[b][i] <= 10000) {
				mark[table[b][i]] = true;
			}
		}
		for (int i = 0; i < table[a].size(); i++) {
			if (table[a][i] >= 10001) {
				for (int j = 0; j < table[table[a][i]].size(); j++) {
					if (mark[table[table[a][i]][j]])
						line.push_back(make_pair(table[a][i] - 10001, 10000 - table[table[a][i]][j]));
				}
			}
		}
	}
	else if (a <= 10000 && b >= 10001) {//女追男
		for (int i = 0; i < table[b].size(); i++) {
			if (table[b][i] >= 10001) {
				mark[table[b][i]] = true;
			}
		}
		for (int i = 0; i < table[a].size(); i++) {
			if (table[a][i] <= 10000) {
				for (int j = 0; j < table[table[a][i]].size(); j++) {
					if (mark[table[table[a][i]][j]])
						line.push_back(make_pair(10000 - table[a][i], table[table[a][i]][j] - 10001));
				}
			}
		}
	}
	else {//都是女孩子
		for (int i = 0; i < table[b].size(); i++) {
			if (table[b][i] <= 10000 && table[b][i] != a) {
				mark[table[b][i]] = true;
			}
		}
		for (int i = 0; i < table[a].size(); i++) {
			if (table[a][i] <= 10000 && table[a][i] != b) {
				for (int j = 0; j < table[table[a][i]].size(); j++) {
					if (mark[table[table[a][i]][j]])
						line.push_back(make_pair(10000 - table[a][i], 10000 - table[table[a][i]][j]));
				}
			}
		}
	}
}

bool comp(pair<int, int> a, pair<int, int>b) {
	if (a.first != b.first)
		return a.first < b.first;
	else
		return a.second < b.second;
}
//另一种映射的思路
//负数+10000，正数+10001，就可以把正负0区分开来了
int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	string x, y;
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		if (x[0] == '-')
			a = stoi(x) + 10000;
		else
			a = stoi(x) + 10001;
		if (y[0] == '-')
			b = stoi(y) + 10000;
		else
			b = stoi(y) + 10001;
		table[a].push_back(b);
		table[b].push_back(a);
	}
	int K;
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		line.clear();
		memset(mark, false, 20001 * sizeof(bool));
		cin >> x >> y;
		if (x[0] == '-')
			a = stoi(x) + 10000;
		else
			a = stoi(x) + 10001;
		if (y[0] == '-')
			b = stoi(y) + 10000;
		else
			b = stoi(y) + 10001;
		connect(a, b);
		sort(line.begin(), line.end(), comp);
		printf("%d\n", line.size());
		for (int j = 0; j < line.size(); j++) {
			printf("%04d %04d\n", line[j].first, line[j].second);
		}
	}
	return 0;
}