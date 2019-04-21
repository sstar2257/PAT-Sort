#include <iostream>
#include <queue>
using namespace std;

struct node {
	int left;
	int right;
};

int N;
node tree[10];
int root[10];
int mark[10];
queue<node> que;
int space;

int find_root() {
	for (int i = 0; i < N; i++) {
		if (!root[i]) {
			return i;
		}
	}
}

void level_order(int no) {
	que.push(tree[no]);
	cout << no;
	while (!que.empty()) {
		node front = que.front();
		que.pop();
		if (front.left != -1) {
			cout << " " << front.left;
			que.push(tree[front.left]);
		}
		if (front.right != -1) {
			cout << " " << front.right;
			que.push(tree[front.right]);
		}
	}
	cout << endl;
}

void inorder(int no) {
	if (tree[no].left != -1 && !mark[tree[no].left]) {
		inorder(tree[no].left);
	}
	if (!space) {
		cout << no;
		space++;
	}
	else {
		cout << " " << no;
	}
	mark[no] = 1;
	if (tree[no].right != -1 && !mark[tree[no].right]) {
		inorder(tree[no].right);
	}
}

int main()
{
	cin >> N;
	char ch;
	for (int i = 0; i < N; i++) {
		cin >> ch;
		if (ch == '-') {
			tree[i].right = -1;
		}
		else {
			tree[i].right = ch - '0';
			root[tree[i].right] = 1;
		}
		cin >> ch;
		if (ch == '-') {
			tree[i].left = -1;
		}
		else {
			tree[i].left = ch - '0';
			root[tree[i].left] = 1;
		}
	}
	int root = find_root();
	level_order(root);
	inorder(root);
	return 0;
}