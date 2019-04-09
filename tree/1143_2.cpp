#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <set>
using namespace std;

struct node {
	int data;
	int left;
	int right;
};

int M, N;
int x, y;
node tree[10000];
set<int> table;

void build(int prel, int prer) {
	if (prel >= prer) {
		return;
	}
	int key = tree[prel].data;
	int index = prer + 1;
	for (int i = prel + 1; i <= prer; i++) {
		if (tree[i].data > key) {
			index = i;
			break;
		}
	}
	if (prel + 1 < index) {//存在左子树
		tree[prel].left = prel + 1;
	}
	if (index <= prer) {
		tree[prel].right = index;
	}
	build(prel + 1, index - 1);
	build(index, prer);
}
//assume x is less than y
void find_lca(int root) {
	int key = tree[root].data;
	if (key == x) {
		printf("%d is an ancestor of %d.\n", x, y);
		return;
	}
	if (key == y) {
		printf("%d is an ancestor of %d.\n", y, x);
		return;
	}
	if (key < y && key > x) {
		printf("LCA of %d and %d is %d.\n", x, y, key);
		return;
	}
	else if (key > y && key > x) {
		find_lca(tree[root].left);
	}
	else if (key < y && key < x) {
		find_lca(tree[root].right);
	}
}
//其实这份原来的代码也没大问题。。。就是假定x小于y之后，在find_lca前把x，y互换，输出的时候需要换回来。。。
int main()
{
	scanf("%d %d", &M, &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &tree[i].data);
		table.insert(tree[i].data);
		tree[i].left = -1;
		tree[i].right = -1;
	}
	build(0, N - 1);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &x, &y);
		bool find_x = (table.find(x) != table.end());
		bool find_y = (table.find(y) != table.end());
		if (!find_x && !find_y) {
			printf("ERROR: %d and %d are not found.\n", x, y);
		}
		else if (!find_x) {
			printf("ERROR: %d is not found.\n", x);
		}
		else if (!find_y) {
			printf("ERROR: %d is not found.\n", y);
		}
		else {
			if (x > y) {
				int tmp = x;
				x = y;
				y = tmp;
			}
			find_lca(0);
		}
	}
	return 0;
}