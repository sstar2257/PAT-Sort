#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	vector<int> list[100];
	int num, no;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &no, &num);
		int child;
		for (int j = 0; j < num; j++) {
			scanf("%d", &child);
			list[no].push_back(child);
		}
	}
	int max = 1, max_lvl = 1;
	int lvl = 1;
	num = 0;
	queue<int> que;
	//int mark[100] = { 0 };
	que.push(1);
	//mark[1] = 1;
	int tail = 1;
	while (!que.empty()) {
		int front = que.front();
		que.pop();
		for (int i = 0; i < list[front].size(); i++) {
			que.push(list[front][i]);
		}
		if (tail == front && !que.empty()) {
			tail = que.back();
			num = que.size();
			lvl++;
			if (num > max) {
				max = num;
				max_lvl = lvl;
			}
		}
	}
	printf("%d %d", max, max_lvl);
	return 0;
}