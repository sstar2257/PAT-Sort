#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
using namespace std;

int follow[1001][1001];
int N, L;

//从no开始进行广度优先搜索

void BFS(int no) {
	queue<int> que;
	int mark[1001] = {0};
	int level = 0;
	int count_n = 0;
	que.push(no);
	mark[no] = 1;
	int tail = no;
	int last = -1;
	while (!que.empty() && level < L) {
		int front = que.front();
		que.pop();
		for (int i = 1; i <= N; i++) {
			if (follow[front][i] && !mark[i]){
				que.push(i);
				mark[i] = 1;
				count_n++;
				last = i;
			}
		}
		if (tail == front && last != -1) {
			tail = last;
			level++;
		}
	}
	printf("%d\n", count_n);
}


//深度优先搜索最后一个测试点超时
int main()
{
	scanf("%d %d", &N, &L);
	int num, no;
	for (int i = 1; i <= N; i++) {
		scanf("%d", &num);
		for (int j = 0; j < num; j++) {
			scanf("%d", &no);
			follow[no][i] = 1;
		}
	}
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%d", &no);
		BFS(no);
	}
	return 0;
}
