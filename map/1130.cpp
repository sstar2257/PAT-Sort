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
//左子树输出(
//右子树输出)
//想复杂了。。。这里其实不用去考虑运算符优先级啥的
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
//	//下面这段代码有问题。。。会导致正常的减号出错，（的输出时机应该是某节点的子树不为空
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
	//下面这段代码有问题。。。会导致正常的减号出错，（的输出时机应该是某节点的子树不为空
	else if (n->right != NULL && n!= root) {//!!!!!!这里还需要判断一个n!=root，即从根开始就没有左子树的情况!!!!!!!!!!!!
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
//柳大佬的思路很值得借鉴
//题目大意：给一个二叉树，输出中缀表达式，且加上括号表示运算的优先级～
//分析：首先根据所有孩子结点编号寻找1～n中没有出现过的编号标记为root，即树的根结点～然后进行从root结点开始dfs～dfs递归拼接 “(” + 左子树 + 根 + 右子树 + “)”
//递归有四种情况（有效的只有三种）：
//1. 左右子树都空 返回 “(” + 根 + “)”
//2. 左空右不空 返回 “(” + 根 + 右子树 + “)”
//3. 左不空右空 这种情况不存在
//4. 左右都不空 返回 “(” + 左子树 + 根 + 右子树 + “)”
//最后递归返回的ans，最外层可能会被括号包起来，也可能不被包起来。要判断一下，如果被包起来，把最外层括号去掉即可～
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