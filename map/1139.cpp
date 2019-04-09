#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <string>
using namespace std;

vector<int> table[10000];//用来存同性好友
map<int, bool> list;//用来映射好友关系,true说明两个人是好友
vector <pair< int, int >> line;

void connect(int a, int b) {
	for (int i = 0; i < table[abs(a)].size(); i++) {
		for (int j = 0; j < table[abs(b)].size(); j++) {
			int x = table[abs(a)][i];
			int y = table[abs(b)][j];
			if (x == abs(b) || y == abs(a)) {//保证不直接找同性好友
				continue;
			}
			if (list.find(x * 10000 + y) != list.end()) {
				line.push_back(make_pair(x, y));
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
//只是-表示女生，而不是负数表示女生,所以用int读入0的时候，会出问题
//还要保证A的好友C不能认识B，同理亦然
//看了下大佬的代码。。。好像没有上面这个要求。。。只要同性的时候不直接找对象就好了。。。
//那这样我原来的思路是可以写的。。。
int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	string a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		if (a.length() == b.length()) {
			table[abs(stoi(a))].push_back(abs(stoi(b)));
			table[abs(stoi(b))].push_back(abs(stoi(a)));
		}
		list[abs(stoi(a)) * 10000 + abs(stoi(b))] = list[abs(stoi(b)) * 10000 + abs(stoi(a))] = true;
	}
	int K;
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		line.clear();
		cin >> a >> b;
		connect(stoi(a), stoi(b));
		sort(line.begin(), line.end(), comp);
		printf("%d\n", line.size());
		for (int j = 0; j < line.size(); j++) {
			printf("%04d %04d\n", line[j].first, line[j].second);
		}
	}
	return 0;
}