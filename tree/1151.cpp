#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string.h>
#include <map>
using namespace std;

int M, N;
int inorder[10000];
int preorder[10000];
map<int, int> parent;//孩子->跟的下标对应关系
map<int, int> val;//值与下标的对应关系
int x, y;
bool mark[10000];

void build(int root, int inl, int inr) {
	if (inl >= inr) {
		return;
	}
	int key = preorder[root];
	int index = 0;
	for (int i = inl; i <= inr; i++) {
		if (inorder[i] == key) {
			index = i;
			break;
		}
	}
	if (index > inl) {//存在左子树
		parent[root + 1] = root;
	}
	if (index < inr) {//存在右子树
		parent[root + (index - inl) + 1] = root;
	}
	build(root + 1, inl, index - 1);
	build(root + (index - inl) + 1, index + 1, inr);
}
//用map直接记录key的访问记录会超时。。。
//改用map记录下标的方法，同时另外加一个map映射值和下标
void find_lca() {
	int a = val[x], b = val[y];
	memset(mark, false, 10000 * sizeof(bool));
	while (a != -1) {
		mark[a] = true;
		a = parent[a];
	}
	while (b != -1) {
		if (!mark[b]) {
			mark[b] = true;
		}
		else {
			if (preorder[b] == y) {
				printf("%d is an ancestor of %d.\n", y, x);
			}
			else if (preorder[b] == x) {
				printf("%d is an ancestor of %d.\n", x, y);
			}
			else {
				printf("LCA of %d and %d is %d.\n", x, y, preorder[b]);
			}
			break;
		}
		b = parent[b];
	}
}

int main()
{
	scanf("%d %d", &M, &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &inorder[i]);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &preorder[i]);
		val[preorder[i]] = i;
	}
	parent[0] = -1;
	build(0, 0, N - 1);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &x, &y);
		bool find_x = (val.find(x) != val.end());
		bool find_y = (val.find(y) != val.end());
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
			find_lca();
		}
	}
	return 0;
}

//因为这题纠结了很久，所以另外再记录两种方法
//看了柳大佬的代码，其实不用建树，只需要判断给定的两个点与当前根节点的相对位置就行了
//具体为：
//已知某个树的根结点，若a和b在根结点的左边，则a和b的最近公共祖先在当前子树根结点的左子树寻找
//如果a和b在当前子树根结点的两边，在当前子树的根结点就是a和b的最近公共祖先
//如果a和b在当前子树根结点的右边，则a和b的最近公共祖先就在当前子树的右子树寻找
//#include <iostream>
//#include <vector>
//#include <map>
//using namespace std;
//map<int, int> pos;
//vector<int> in, pre;
//void lca(int inl, int inr, int preRoot, int a, int b) {
//	if (inl > inr) return;
//	int inRoot = pos[pre[preRoot]], aIn = pos[a], bIn = pos[b];
//	if (aIn < inRoot && bIn < inRoot)
//		lca(inl, inRoot - 1, preRoot + 1, a, b);
//	else if ((aIn < inRoot && bIn > inRoot) || (aIn > inRoot && bIn < inRoot))
//		printf("LCA of %d and %d is %d.\n", a, b, in[inRoot]);
//	else if (aIn > inRoot && bIn > inRoot)
//		lca(inRoot + 1, inr, preRoot + 1 + (inRoot - inl), a, b);
//	else if (aIn == inRoot)
//		printf("%d is an ancestor of %d.\n", a, b);
//	else if (bIn == inRoot)
//		printf("%d is an ancestor of %d.\n", b, a);
//}
//int main() {
//	int m, n, a, b;
//	scanf("%d %d", &m, &n);
//	in.resize(n + 1), pre.resize(n + 1);
//	for (int i = 1; i <= n; i++) {
//		scanf("%d", &in[i]);
//		pos[in[i]] = i;
//	}
//	for (int i = 1; i <= n; i++) scanf("%d", &pre[i]);
//	for (int i = 0; i < m; i++) {
//		scanf("%d %d", &a, &b);
//		if (pos[a] == 0 && pos[b] == 0)
//			printf("ERROR: %d and %d are not found.\n", a, b);
//		else if (pos[a] == 0 || pos[b] == 0)
//			printf("ERROR: %d is not found.\n", pos[a] == 0 ? a : b);
//		else
//			lca(1, n, 1, a, b);
//	}
//	return 0;
//}


//另一个纠结了好久的建树递归的方法，记录了节点的高度值以及节点的上一个节点
//看了下代码，其实和我用的记录前置节点然后往前推的方法有点像
//经过测试后发现，这个代码的时间是最少的。。。把几百ms的运算时间缩短到了几十ms
//核心思想是调整高度
//#include <iostream>
//#include <cstdio>
//#include <algorithm>
//#include <map>
//using namespace std;
//struct tree
//{
//	int Data, Height;
//	tree *Last, *Left, *Right;
//}*head;
//int q[10001], z[10001], m, n;
//map<int, tree *> mp;///根据序号映射到结点
//tree *createNode(int d, int h)///创建新结点并返回
//{
//	tree *p = new tree();
//	p->Data = d;
//	mp[d] = p;
//	p->Height = h;
//	p->Last = p->Left = p->Right = NULL;
//	return p;
//}
//tree *createTree(int ql, int qr, int zl, int zr, int h)///前中序 还原树
//{
//	tree *p = createNode(q[ql], h);
//	for (int i = zl; i <= zr; i++)
//	{
//		if (z[i] == q[ql])
//		{
//			if (i > zl)p->Left = createTree(ql + 1, ql + i - zl, zl, i - 1, h + 1), p->Left->Last = p;
//			if (i < zr)p->Right = createTree(ql + i - zl + 1, qr, i + 1, zr, h + 1), p->Right->Last = p;
//			break;
//		}
//	}
//	return p;
//}
//void check(int a, int b)///判断两点
//{
//	if (mp[a] == NULL && mp[b] == NULL)printf("ERROR: %d and %d are not found.\n", a, b);
//	else if (mp[a] == NULL)printf("ERROR: %d is not found.\n", a);
//	else if (mp[b] == NULL)printf("ERROR: %d is not found.\n", b);
//	else {
//		tree *t1 = mp[a], *t2 = mp[b];
//		while (t1->Height != t2->Height) {
//			if (t1->Height > t2->Height)t1 = t1->Last;
//			else t2 = t2->Last;
//		}///调整至高度相同
//		if (t1 == t2) {///一个点是另一个点的祖先
//			printf("%d is an ancestor of %d.\n", t1->Data, a == t1->Data ? b : a);
//			return;
//		}while (t1 != t2) {
//			t1 = t1->Last;
//			t2 = t2->Last;
//		}
//		printf("LCA of %d and %d is %d.\n", a, b, t1->Data);
//	}
//}
//int main() {
//	int a, b;
//	scanf("%d%d", &m, &n);
//	for (int i = 0; i < n; i++) {
//		scanf("%d", &z[i]);
//	}
//	for (int i = 0; i < n; i++) {
//		scanf("%d", &q[i]);
//	}
//	head = createTree(0, n - 1, 0, n - 1, 0);
//	for (int i = 0; i < m; i++) {
//		scanf("%d%d", &a, &b);
//		check(a, b);
//	}
//}
