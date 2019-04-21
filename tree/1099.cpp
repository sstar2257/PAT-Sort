#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct node {
	int data;
	int left;
	int right;
};

int N;
node tree[100];
int list[100];
int mark[100];
int index;
queue<node> que;

void DFS(int no) {
	while (tree[no].left != -1 && !mark[tree[no].left]) {
		DFS(tree[no].left);
	}
	tree[no].data = list[index];
	mark[no] = 1;
	index++;
	while (tree[no].right != -1 && !mark[tree[no].right]) {
		DFS(tree[no].right);
	}
}

void output(int no) {
	que.push(tree[no]);
	cout << tree[no].data;
	while (!que.empty()) {
		node front = que.front();
		que.pop();
		int left = front.left;
		int right = front.right;
		if (left != -1) {
			que.push(tree[left]);
			cout << " " << tree[left].data;
		}
		if (right != -1) {
			que.push(tree[right]);
			cout << " " << tree[right].data;
		}
	}
}

int main()
{

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tree[i].left >> tree[i].right;
	}
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
	sort(list, &list[N]);
	DFS(0);
	output(0);
	return 0;
}