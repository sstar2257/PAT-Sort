#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct mem {
	int id;
	int sets;
	int area;
};

struct family {
	int id;
	int num;
	double sets;
	double area;
};

mem table[10000];
vector<int> list[10000];
bool has_estate[10000];
bool mark[10000];
vector<family> fam;

void BFS(int id) {
	queue<int> que;
	que.push(id);
	family f = { 10000,1,0,0 };
	mark[id] = true;
	while (!que.empty()) {
		int tmp = que.front();
		if (has_estate[tmp]) {
			f.sets += table[tmp].sets;
			f.area += table[tmp].area;
		}
		que.pop();
		if (tmp < f.id) {
			f.id = tmp;
		}
		for (int i = 0; i < list[tmp].size(); i++) {
			if (!mark[list[tmp][i]]) {
				f.num++;
				que.push(list[tmp][i]);
				mark[list[tmp][i]] = true;
			}
		}
	}
	f.sets /= f.num;
	f.area /= f.num;
	fam.push_back(f);
}

bool comp(family a, family b) {
	if (a.area != b.area) {
		return a.area > b.area;
	}
	else {
		return a.id < b.id;
	}
}
//是一个类似图的东西,所以mem之间的关系不能简单的用数组映射去处理
int main()
{
	int N;
	scanf("%d", &N);
	int id, num, dad, mom, child;
	for (int i = 0; i < N; i++) {
		scanf("%d", &id);
		table[id].id = id;
		has_estate[id] = true;
		scanf("%d %d %d", &dad, &mom, &num);
		if (dad != -1) {
			list[id].push_back(dad);
			list[dad].push_back(id);
		}
		if (mom != -1) {
			list[id].push_back(mom);
			list[mom].push_back(id);
		}
		for (int i = 0; i < num; i++) {
			scanf("%d", &child);
			list[id].push_back(child);
			list[child].push_back(id);
		}
		scanf("%d %d", &table[id].sets, &table[id].area);
	}
	for (int i = 0; i < 10000; i++) {
		if (has_estate[i] && !mark[i]) {
			BFS(i);
		}
	}
	sort(fam.begin(), fam.end(), comp);
	printf("%d\n", fam.size());
	for (int i = 0; i < fam.size(); i++) {
		printf("%04d %d %.3lf %.3lf\n", fam[i].id, fam[i].num, fam[i].sets, fam[i].area);
	}

	return 0;
}