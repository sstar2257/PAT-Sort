#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int N;
int preorder[50000];
int inorder[50000];
//int mark[50000];

//加了后面两个参数之后，就不需要再去遍历找左右子树的大小了
//看了网上的代码。。。甚至连前序的右值都不需要。。。
void post(int prel, int prer, int inl, int inr) {
	if (prel >= prer) {
		printf("%d\n", preorder[prel]);
		return;
	}
	int root = preorder[prel];
	int i;
	for (i = inl; i <= inr; i++) {
		if (inorder[i] == root) {
			break;
		}
	}
	//mark[i] = 1;
	//int l = 0, r = 0;
	//for (int j = i - 1; j >= inl; j--) {
	//	if (!mark[j])
	//		l++;
	//	else
	//		break;
	//}
	if (i > inl) {//存在左子树
		post(prel + 1, prel + i - inl, inl, i - 1);
	}
	else {
		post(prer - (inr - i) + 1, prer, i + 1, inr);
	}
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &preorder[i]);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &inorder[i]);
	}
	post(0, N - 1, 0, N - 1);
	return 0;
}