#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string.h>
using namespace std;

//有向图的带深度bfs搜索，用dfs有一些问题要处理，比如一个点离起始点很近，
//但它可能会被其他离起始点很近的点dfs搜索路径上，这时要保证能从这个点dfs一趟，因为这个点下面可能还有点满足题目的条件。
int follow[1001][1001];
int N, L;
int level = 1, count;
int mark[1001];

//从no开始进行深度优先搜索
void DFS(int no) {
	mark[no] = level;
	if (level > L) {
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (follow[no][i]){
			if (!mark[i]) {
				mark[i] = level;
				count++;
				level++;
				DFS(i);
				level--;
			}
			else if(level < mark[i]){
				mark[i] = level;
				level++;
				DFS(i);
				level--;
			}
		}
	}
}
//void DFS(int no) {
//	mark[no] = 1;
//	if (level >= L) {
//		return;
//	}
//	for (int i = 1; i <= N; i++) {
//		if (follow[no][i] && !mark[i]) {
//			mark[i] = 1;
//			count++;
//			level++;
//			DFS(i);
//			level--;
//		}
//	}
//}

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
		DFS(no);
		printf("%d\n", count);
		count = 0;
		level = 1;
		memset(mark, 0, 1001 * sizeof(int));
	}
	return 0;
}
