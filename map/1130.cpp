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
int parent;
int extra;
int last;
int mode;

//int is_symbol(string str) {
//	if (str.size() != 1)
//		return 0;
//	else {
//		char ch = str[0];
//		if (ch != '+' && ch != '-' && ch != '*' && ch != '/' && ch != '%')
//			return 0;
//		else
//			return 1;
//	}
//}
//���������(
//���������)
//�븴���ˡ�����������ʵ����ȥ������������ȼ�ɶ��
//void pretraverse(node *n) {
//	
//	if (n != root && n->right != NULL) {
//		res = res + "(";
//	}
//	if (n->left != NULL) {
//		//if (n != root) {
//		//	res = res + "(";
//		//}
//		pretraverse(n->left);
//	}
//	//else if (n->right != NULL) {
//	//	res = res + "(";
//	//}
//	//������δ��������⡣�����ᵼ�������ļ��ų����������ʱ��Ӧ����ĳ�ڵ��������Ϊ��
//	//if (n->data == "-" && n->right != NULL) {
//	//	res = res + "(";
//	//}
//	res = res + n->data;
//	if (n->right != NULL) {
//		pretraverse(n->right);
//		//if (n != root) {
//		//	res = res + ")";
//		//}
//	}
//	if (n != root && n->right != NULL) {
//		res = res + ")";
//	}
//}
//test1
void pretraverse(node *n) {

	//if (n != root && n->right != NULL) {
	//	res = res + "(";
	//}
	if (n->left != NULL) {
		if (n != root) {
			res = res + "(";
		}
		pretraverse(n->left);
	}
	//else if (n->right != NULL) {
	//	res = res + "(";
	//}
	//������δ��������⡣�����ᵼ�������ļ��ų����������ʱ��Ӧ����ĳ�ڵ��������Ϊ��
	else if (n->right != NULL && n!= root) {//!!!!!!���ﻹ��Ҫ�ж�һ��n!=root�����Ӹ���ʼ��û�������������!!!!!!!!!!!!
		res = res + "(";
	}
	res = res + n->data;
	if (n->right != NULL) {
		pretraverse(n->right);
		if (n != root) {
			res = res + ")";
		}
	}
	//if (n != root && n->right != NULL) {
	//	res = res + ")";
	//}
}

//void pretraverse(node *root) {
//	if (root->left != NULL) {
//		pretraverse(root->left);
//	}
//	if (!is_symbol(root->data)) {
//		if (!parent) {
//			res = res + "(" + root->data;
//			parent = 1;
//		}
//		else {
//			res = res + root->data + ")";
//			parent = 0;
//			if (extra) {
//				res = res + ")";
//			}
//		}
//		last = 0;
//	}
//	else {
//		if (last) {
//			res = res + "(" + root->data;
//			extra++;
//		}
//		else {
//			res = res + root->data;
//		}
//		last = 1;
//	}
//	if (root->right != NULL) {
//		pretraverse(root->right);
//	}
//}

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
//�����е�˼·��ֵ�ý��
//��Ŀ���⣺��һ���������������׺���ʽ���Ҽ������ű�ʾ��������ȼ���
//���������ȸ������к��ӽ����Ѱ��1��n��û�г��ֹ��ı�ű��Ϊroot�������ĸ���㡫Ȼ����д�root��㿪ʼdfs��dfs�ݹ�ƴ�� ��(�� + ������ + �� + ������ + ��)��
//�ݹ��������������Ч��ֻ�����֣���
//1. ������������ ���� ��(�� + �� + ��)��
//2. ����Ҳ��� ���� ��(�� + �� + ������ + ��)��
//3. �󲻿��ҿ� �������������
//4. ���Ҷ����� ���� ��(�� + ������ + �� + ������ + ��)��
//���ݹ鷵�ص�ans���������ܻᱻ���Ű�������Ҳ���ܲ�����������Ҫ�ж�һ�£�������������������������ȥ�����ɡ�
//#include <iostream>
//using namespace std;
//struct node {
//	string data;
//	int l, r;
//}a[100];
//string dfs(int root) {
//	if (a[root].l == -1 && a[root].r == -1) return a[root].data;
//	if (a[root].l == -1 && a[root].r != -1)  return "(" + a[root].data + dfs(a[root].r) + ")";
//	if (a[root].l != -1 && a[root].r != -1) return "(" + dfs(a[root].l) + a[root].data + dfs(a[root].r) + ")";
//}
//int main() {
//	int have[100] = { 0 }, n, root = 1;
//	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i].data >> a[i].l >> a[i].r;
//		if (a[i].l != -1) have[a[i].l] = 1;
//		if (a[i].r != -1) have[a[i].r] = 1;
//	}
//	while (have[root] == 1) root++;
//	string ans = dfs(root);
//	if (ans[0] == '(') ans = ans.substr(1, ans.size() - 2);
//	cout << ans;
//	return 0;
//}