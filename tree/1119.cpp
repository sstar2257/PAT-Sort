#include <iostream>
#include <vector>
using namespace std;

int preorder[30];
int postorder[30];
int unique = 1;
vector<int> in;

void getin(int prel, int prer, int postl, int postr) {
	if (prel == prer) {
		in.push_back(preorder[prel]);
		return;
	}
	if (preorder[prel] == postorder[postr]) {
		int i = prel + 1;
		//以后序的根结点的前面一个结点作为参考，寻找这个结点在前序的位置，就可以根据这个位置来划分左右孩子
		while (i < prer && preorder[i] != postorder[postr - 1])i++;
		if (i - prel > 1) {//存在左孩子
			getin(prel + 1, i - 1, postl, postl + (i - prel - 1) - 1);
		}
		else {
			unique = 0;
		}
		in.push_back(postorder[postr]);
		//遍历右孩子
		getin(i, prer, postl + (i - prel - 1), postr - 1);
	}
}
//借用柳婼大佬的代码
//已知二叉树的前序和后序是无法唯一确定一颗二叉树的
//因为可能会存在多种情况，这种情况就是一个结点可能是根的左孩子也有可能是根的右孩子
//如果发现了一个无法确定的状态，置unique = 0，又因为题目只需要输出一个方案，
//可以假定这个不可确定的孩子的状态是右孩子，接下来的问题是如何求根结点和左右孩子划分的问题了，
//首先我们需要知道树的表示范围，需要四个变量，
//分别是前序的开始的地方prel，前序结束的地方prer，后序开始的地方postl，后序结束的地方postr
//前序的开始的第一个应该是后序的最后一个是相等的，这个结点就是根结点，以后序的根结点的前面一个结点作为参考，
//寻找这个结点在前序的位置，就可以根据这个位置来划分左右孩子，递归处理。
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> preorder[i];c
	}
	for (int i = 0; i < N; i++) {
		cin >> postorder[i];
	}
	getin(0, N - 1, 0, N - 1);
	if (unique) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	cout << in[0];
	for (int i = 1; i < in.size(); i++) {
		cout << " " << in[i];
	}
	cout << endl;
	return 0;
}