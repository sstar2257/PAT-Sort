#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <map>
//#include <set>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//直接村存会内存超限，这里先做一个转换
vector<string> name2id;

bool comp(int a, int b) {
	return name2id[a] < name2id[b];
}

int main()
{
	int N, K;
	cin >> N >> K;
	map<int, vector<int>> table;
	string name;
	name.resize(4);
	int num;
	int no;
	for (int i = 0; i < N; i++) {
		scanf("%s %d", &name[0], &num);
		name2id.push_back(name);
		for (int j = 0; j < num; j++) {
			scanf("%d", &no);
			table[no].push_back(i);
		}
	}

	for (int i = 0; i < K; i++) {
		printf("%d %d\n", i + 1, table[i + 1].size());
		sort(table[i + 1].begin(), table[i + 1].end(), comp);
		for (auto it = table[i + 1].begin(); it != table[i + 1].end(); it++) {
			printf("%s\n", name2id[*it].c_str());
		}
	}
	return 0;
}