#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

struct mem {
	int id;
	string name;
	int grade;
};

bool comp_1(mem a, mem b) {
	return a.id < b.id;
}

bool comp_2(mem a, mem b) {
	if (a.name != b.name)
		return a.name < b.name;
	else
		return a.id < b.id;
}

bool comp_3(mem a, mem b) {
	if (a.grade != b.grade)
		return a.grade < b.grade;
	else
		return a.id < b.id;
}

int main()
{
	int N, C;
	cin >> N >> C;
	mem *table = new mem[N+1]();
	for (int i = 0; i < N; i++) {
		cin >> table[i].id >> table[i].name >> table[i].grade;
	}

	switch (C) {
	case 1:sort(table, &table[N], comp_1); break;
	case 2:sort(table, &table[N], comp_2); break;
	case 3:sort(table, &table[N], comp_3); break;
	default:;
	}
	for (int i = 0; i < N; i++) {
		printf("%06d %s %d\n", table[i].id, table[i].name.c_str(), table[i].grade);
	
	}
	return 0;
}