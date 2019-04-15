#include <iostream>
#include <queue>
using namespace std;

int inorder[30];
int postorder[30];
int visit1[30];//中序的访问记录
int visit2[30];//后序的访问记录
int N;
queue<int> line;

int len(int m) {
	int num = 0;
	for (int i = m + 1; i < N; i++) {
		if (visit1[i])
			break;
		num++;
	}
	return num;
}


//这里不能用递归,类似广度优先搜索
//先序遍历是一个类似递归的过程
//l1,r1 is the begin and end of the left tree
//l2,r2 is for right tree
//N is the number of nodes
void lfs() {
	line.push(postorder[N-1]);
	int val, i, j, k;
	while (!line.empty()) {
		val = line.front();

		for (j = 0; j < N; j++) {//在中序的位置
			if (val == inorder[j])
				break;
		}
		visit1[j] = 1;

		for (i = 0; i < N; i++) {//在后序的位置
			if (val == postorder[i])
				break;
		}
		visit2[i] = 1;

		k = i - len(j) - 1;
		if (k >= 0 && !visit2[k])
			line.push(postorder[k]);//左孩子

		if (i >= 1 && !visit2[i - 1] && len(j))//存在右孩子
			line.push(postorder[i - 1]);//右孩子

		if (val == postorder[N-1])
			cout << val;
		else
			cout << " " << val;
		line.pop();
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> postorder[i];
	for (int i = 0; i < N; i++)
		cin >> inorder[i];

	lfs();
	return 0;
}

