#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#include <string.h>
using namespace std;

struct node{
	int num;
	int next;
};

int main()
{
	int N;
	int begin;
	node table[100000];
	memset(table, 0, sizeof(node) * 100000);
	cin >> N >> begin;
	int index;
	for (int i = 0; i < N; i++) {
		scanf("%d", &index);
		scanf("%d %d",&table[index].num, &table[index].next);
	}
	if (begin == -1) {
		cout << "0 -1" << endl;
		return 0;
	}
	map<int, int> list;
	for (int i = begin; i >= 0; i = table[i].next) {
		list[table[i].num] = i;
	}
	//这个地址的输出格式也要注意！！！
	cout << list.size() << " ";
	printf("%05d\n", list.begin()->second);
	for (auto it = list.begin(); it != list.end();) {
		printf("%05d %d ", it->second, it->first);
		if (it != (--list.end())) {
			printf("%05d\n", (++it)->second);
		}
		else {
			cout << "-1" << endl;
			break;
		}
	}
	return 0;
}