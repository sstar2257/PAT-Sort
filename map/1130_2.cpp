#include <iostream>
#include <string>
using namespace std;

struct node {
	string data;
	node *left;
	node *right;
};
int N;
node *root;
node tree[21];
int mark[21];
string res;

void pretraverse(node *n) {
	if (n->left != NULL) {
		while (1);
	}
	res = res + n->data;
	if (n->right != NULL) {
		pretraverse(n->right);
		if (n != root) {
			res = res + ")";
		}
	}
}
//用while（1）去试测试用例
int main()
{
	cin >> N;
	int x, y;
	for (int i = 1; i <= N; i++) {
		cin >> tree[i].data >> x >> y;
		if (x != -1) {
			mark[x] = 1;
			tree[i].left = &tree[x];
		}
		if (y != -1) {
			mark[y] = 1;
			tree[i].right = &tree[y];
		}
	}
	for (int i = 1; i <= N; i++) {
		if (!mark[i]) {
			root = &tree[i];
			break;
		}
	}
	pretraverse(root);
	cout << res;
	return 0;
}