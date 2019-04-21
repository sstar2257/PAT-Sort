#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct node {
	int left;
	int right;
};

node tree[20];
int mark[20];
queue<node> que;

int find_root(int N) {
	for (int i = 0; i < N; i++) {
		if (!mark[i]) {
			return i;
		}
	}
	return -1;
}

int judge(int root, int N) {
	que.push(tree[root]);
	int num = 1;
	int tail = 0;//N=1的情况
	while (!que.empty()) {
		node tmp = que.front();
		que.pop();
		if (tmp.left != -1) {
			tail = tmp.left;
			que.push(tree[tmp.left]);
			num++;
		}
		else {
			if (num != N) {
				return -1;
			}
			else {
				return tail;
			}
		}
		if (tmp.right != -1) {
			tail = tmp.right;
			que.push(tree[tmp.right]);
			num++;
		}
		else {
			if (num != N) {
				return -1;
			}
			else {
				return tail;
			}
		}
	}
}

int main()
{
	int N;
	cin >> N;
	string l, r;
	int ll, rr;
	//低级错误，N的范围是<=20，输入数字可能是两位数，所以不能用char来读入。。。
	for (int i = 0; i < N; i++) {
		cin >> l >> r;
		if (l[0] != '-') {
			ll = stoi(l);
			tree[i].left = ll;
			mark[ll] = 1;
		}
		else {
			tree[i].left = -1;
		}
		if (r[0] != '-') {
			rr = stoi(r);
			tree[i].right = rr;
			mark[rr] = 1;
		}
		else {
			tree[i].right = -1;
		}
	}
	int root = find_root(N);
	int res = judge(root, N);
	if (res == -1) {
		cout << "NO " << root;
	}
	else {
		cout << "YES " << res;
	}
	return 0;
}