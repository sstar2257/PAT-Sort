#include <iostream>
#include <vector>
using namespace std;
vector<int> pre, post;
int is_mirror = 0;
//root根节点，tail尾节点
void pre2post(int root, int tail) {
	if (root > tail) return;
	int i = root + 1;
	int j = tail;
	if (!is_mirror) {
		//查找左子树右边界,i为右子树第一位
		//!!!!while中条件的判断是有先后的。。。先把pre[i]放前面可能回产生越界，所以需要先判断i
		while (i <= tail &&pre[i] < pre[root]) { i++;}
		//查找右子树左边界，j为左子树最后一位
		while (j >= root + 1 && pre[j] >= pre[root]) { j--; }
	}
	else {
		//查找左子树右边界,i为右子树第一位
		while (i <= tail  && pre[i] >= pre[root]) { i++; }
		//查找右子树左边界，j为左子树最后一位
		while (j >= root + 1 && pre[j] < pre[root]) { j--; }
	}
	if (i != j + 1) { return; }
	//递归左右子树
	pre2post(root + 1, j);
	pre2post(i, tail);
	post.push_back(pre[root]);
}

int main()
{
	int N;
	cin >> N;
	pre.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> pre[i];
	}
	pre2post(0, N - 1);
	if (post.size() != N) {
		is_mirror = 1;
		post.clear();
		pre2post(0, N - 1);
	}
	if (post.size() == N) {
		cout << "YES" << endl;
		cout << post[0];
		for (int i = 1; i < N; i++) {
			cout << " " << post[i];
		}
	}
	else {
		cout << "NO";
	}
	return 0;
}