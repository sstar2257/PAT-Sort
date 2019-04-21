#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int inorder[30];
int postorder[30];
int inmark[30];
int postmark[30];
queue<int> que;
vector<int> v;
int N;
//mode = 1 means left -> right
int mode = 1;
int tail;

int right_len(int num) {
	int len = 0;
	for (int i = num + 1; i < N; i++) {
		if (inmark[i])
			break;
		len++;
	}
	return len;
}

void lfs() {
	que.push(postorder[N - 1]);
	cout << postorder[N - 1];
	tail = postorder[N - 1];
	int front, i, j, lchild;
	while (!que.empty()) {
		front = que.front();
		v.push_back(front);
		//在中序中的位置
		for (i = 0; i < N; i++) {
			if (front == inorder[i])
				break;
		}
		inmark[i] = 1;
		//在后序中的位置
		for (j = 0; j < N; j++) {
			if (front == postorder[j])
				break;
		}
		postmark[j] = 1;
		lchild = j - right_len(i) - 1;
		if (lchild >= 0 && !postmark[lchild]) {
			que.push(postorder[lchild]);
		}
		if (j >= 1 && !postmark[j - 1] && right_len(i)) {
			que.push(postorder[j - 1]);
		}
		if (tail == postorder[N - 1]) {
			tail = que.back();
			v.clear();
		}
		else if (tail == front) {
			tail = que.back();
			if (mode) {
				for (int i = 0; i < v.size(); i++) {
					cout << " " << v[i];
				}
				v.clear();
				mode = 0;
			}
			else {
				for (int i = v.size() - 1; i >= 0; i--) {
					cout << " " << v[i];
				}
				v.clear();
				mode = 1;
			}
		}
		que.pop();
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> inorder[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> postorder[i];
	}
	lfs();
	return 0;
}