#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct node {
	int data;
	int next;
};
//借助辅助数组来简化题目。。。
//唯一遇到的坑是，key值no more than 10000，所以数组要设置为10001，不然最后两个测试点过不去
int main()
{
	node list[100000];
	int mark[10001] = { 0 };
	int begin;
	int N;
	cin >> begin >> N;
	int addr, key, next;
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &addr, &key, &next);
		list[addr].data = key;
		list[addr].next = next;
	}
	int r_begin = -1;
	int last = begin, r_last;
	addr = begin;
	int tmp;
	do{
		
		key = list[addr].data;

		if (!mark[abs(key)]) {
			mark[abs(key)] = 1;
			if (addr != begin) {
				list[last].next = addr;
				last = addr;
			}
			tmp = list[addr].next;
			list[addr].next = -1;
			addr = tmp;
		}
		else {
			if (r_begin == -1) {
				r_begin = addr;
				r_last = addr;
			}
			else {
				list[r_last].next = addr;
				r_last = addr;
			}
			tmp = list[addr].next;
			list[addr].next = -1;
			addr = tmp;
		}
	} while (addr != -1);

	do {
		if (list[begin].next == -1) {
			printf("%05d %d -1\n", begin, list[begin].data);
		}
		else {
			printf("%05d %d %05d\n", begin, list[begin].data, list[begin].next);
		}
		begin = list[begin].next;
	} while (begin != -1);

	if (r_begin != -1) {
		do {
			if (list[r_begin].next == -1) {
				printf("%05d %d -1\n", r_begin, list[r_begin].data);
			}
			else {
				printf("%05d %d %05d\n", r_begin, list[r_begin].data, list[r_begin].next);
			}
			r_begin = list[r_begin].next;
		} while (r_begin != -1);
	}

	return 0;
}