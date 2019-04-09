#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <stack>
using namespace std;

struct node {
	int addr;
	int data;
	int next;
};

node table[100000];

void reserve(int begin, int K) {
	
}

int main()
{
	int begin, N, K;
	scanf("%d %d %d", &begin, &N, &K);
	int address;
	for (int i = 0; i < N; i++) {
		scanf("%d", &address);
		table[address].addr = address;
		scanf("%d %d", &table[address].data, &table[address].next);
	}
	int index = begin;
	int k = 0;
	int count = 0;
	stack<node> sta;
	int last_end;
	while (table[index].next != -1) {
		for (int i = 0; i < K; i++) {
			sta.push(table[index]);
			index = table[index].next;
			if (index == -1) {
				break;
			}
		}
		if (sta.size() != K) {
			break;
		}
		else {
			if (!count) {
				begin = sta.top().addr;
			}
			for (int i = 0; i < K; i++) {
				node tmp = sta.top();
				sta.pop();
				if (!sta.empty()) {
					table[tmp.addr].next = sta.top().addr;
				}
				else {
					table[tmp.addr].next = index;
				}
				if (i == 0 && count) {//一轮翻转后要把上一轮最后一个节点的next替换为新一组的第一个节点的addr
					table[last_end].next = tmp.addr;
				}
				if (i == K - 1) {
					last_end = tmp.addr;
				}
			}

		}
		count++;
		if (index == -1) {
			break;
		}
	}
	while (table[begin].next != -1) {
		printf("%05d %d %05d\n", begin, table[begin].data, table[begin].next);
		begin = table[begin].next;
	}
	printf("%05d %d %d\n", begin, table[begin].data, table[begin].next);

	return 0;
}