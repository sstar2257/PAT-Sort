#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string.h>
using namespace std;

struct node {
	int data;
	node *left;
	node *right;
};

int M, N;
int flag;
node tree[1000];

void build() {
	for (int i = 0, j = 1; j < N; j++) {
		tree[i].left = &tree[j];
		j++;
		if (j < N) {
			tree[i].right = &tree[j];
			i++;
		}
	}
}

int judge_max() {
	for (int i = 0; i < N; i++) {
		if (tree[i].left != NULL && tree[i].data < tree[i].left->data) {
			return 0;
		}
		if (tree[i].right != NULL && tree[i].data < tree[i].right->data) {
			return 0;
		}
	}
	return 1;
}

int judge_min() {
	for (int i = 0; i < N; i++) {
		if (tree[i].left != NULL && tree[i].data >= tree[i].left->data) {
			return 0;
		}
		if (tree[i].right != NULL && tree[i].data >= tree[i].right->data) {
			return 0;
		}
	}
	return 1;
}

void post(node *root) {
	if (root->left != NULL) {
		post(root->left);
	}
	if (root->right != NULL) {
		post(root->right);
	}
	if (flag) {
		printf(" ");
	}
	printf("%d", root->data);
	flag = 1;
}

int main()
{
	scanf("%d %d", &M, &N);
	for (int i = 0; i < M; i++) {
		memset(tree, 0, 1000 * sizeof(node));
		flag = 0;
		for (int j = 0; j < N; j++) {
			scanf("%d", &tree[j].data);
		}
		build();
		if (tree[0].data >= tree[1].data) {
			if (judge_max()) {
				printf("Max Heap\n");
			}
			else {
				printf("Not Heap\n");
			}
		}
		else {
			if (judge_min()) {
				printf("Min Heap\n");
			}
			else {
				printf("Not Heap\n");
			}
		}
		post(tree);
		printf("\n");
	}
	return 0;
}