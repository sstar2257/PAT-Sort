#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct node {
	int data;
	int black;//到根节点的黑色数
	int left;
	int right;
};

vector<node> tree;
int len;

void build(int prel, int prer) {
	if (prel >= prer) {
		return;
	}
	int key = abs(tree[prel].data);
	int i;
	for (i = prel + 1; i <= prer; i++) {
		if (abs(tree[i].data) > key) {
			break;
		}
	}
	if (prel + 1 < i) {
		tree[prel].left = prel + 1;
		if (tree[prel + 1].data < 0) {
			tree[prel + 1].black = tree[prel].black;
		}
		else {
			tree[prel + 1].black = tree[prel].black + 1;
		}
	}
	if (i <= prer) {
		tree[prel].right = i;
		if (tree[i].data < 0) {
			tree[i].black = tree[prel].black;
		}
		else {
			tree[i].black = tree[prel].black + 1;
		}
	}
	build(prel + 1, i - 1);
	build(i, prer);
}

void judge() {
	//term2
	if (tree[0].data < 0) {
		cout << "No" << endl;
		return;
	}
	//term4
	for (int i = 0; i < len; i++) {
		if (tree[i].data < 0) {
			if (tree[i].left != -1 && tree[tree[i].left].data < 0) {
				cout << "No" << endl;
				return;
			}
			if (tree[i].right != -1 && tree[tree[i].right].data < 0) {
				cout << "No" << endl;
				return;
			}
		}
	}
	//term5 and term3!!!加不加性质三能影响是否是一颗红黑树
	int num = -1;
	for (int i = 0; i < len; i++) {
		if (tree[i].left == -1 || tree[i].right == -1) {
			if (num == -1) {
				num = tree[i].black + 1;
			}
			else if((tree[i].black + 1) != num){
				cout << "No" << endl;
				return;
			}
		}
	}
	cout << "Yes" << endl;
	return;
}

int main()
{
	int K, N;
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> N;
		tree.clear();
		tree.resize(N);
		for (int j = 0; j < N; j++) {
			cin >> tree[j].data;
			tree[j].left = tree[j].right = -1;
		}
		len = N;
		tree[0].black = 1;
		build(0, N - 1);
		judge();
	}
	return 0;
}