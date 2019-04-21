#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <set>
using namespace std;

int pre[10001];

int find(int x) {
	int r = x;
	while (pre[r] != r) {
		r = pre[r];
	}
	//路径压缩
	int i = x, j;
	while (i != r) {
		j = pre[i];
		pre[i] = r;
		i = j;
	}
	return r;
}

void join(int x, int y) {
	int fx = find(x);
	int fy = find(y);
	if (fx != fy) {
		pre[fx] = fy;
	}
}

//用并查集尝试一下
//在并查集建立过程中统计树的数量比较繁琐而且会出错
//所以在结束之后进行统计
int main()
{
	int N;
	scanf("%d", &N);
	int num, first, no;
	int tree = 0, birds = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		if (num != 0) {
			scanf("%d", &first);
			if (!pre[first]) {
				pre[first] = first;
				birds++;
			}
			else {
				first = find(first);
			}
			for (int i = 1; i < num; i++) {
				scanf("%d", &no);
				if (!pre[no]) {
					pre[no] = first;
					birds++;
				}
				else {
					join(pre[no], first);
				}
			}
		}
	}
	set<int> sets;
	for (int i = 1; i <= birds; i++) {
		sets.insert(find(pre[i]));
	}
	tree = sets.size();
	printf("%d %d\n", tree, birds);
	int K;
	scanf("%d", &K);
	int q1, q2;
	for (int i = 0; i < K; i++) {
		scanf("%d %d", &q1, &q2);
		if (find(q1) == find(q2)) {
			printf("Yes\n");
		}
		else {
			printf("No\n");
		}
	}

	return 0;
}