#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, K, P, maxFacSum = -1;
vector<int> v, ans, tempAns;

void init() {
	int temp = 0;
	int index = 1;
	while (temp <= N) {
		v.push_back(temp);
		temp = pow(index, P);
		index++;
	}
}
//dfs深度优先搜索。先把i从0开始所有的i的p次方的值存储在v[i]中，直到v[i] > n为止。
//然后深度优先搜索，记录当前正在相加的index（即v[i]的i的值），
//当前的总和tempSum，当前K的总个数tempK，以及因为题目中要求输出因子的和最大的那个，
//所以保存一个facSum为当前因子的和，让它和maxFacSum比较，如果比maxFacSum大就更新maxFacSum和要求的ans数组的值。
//在ans数组里面存储因子的序列，tempAns为当前深度优先遍历而来的序列，
//从v[i]的最后一个index开始一直到index == 1，因为这样才能保证ans和tempAns数组里面保存的是从大到小的因子的顺序。
//一开始maxFacSum == -1，如果dfs后maxFacSum并没有被更新，还是-1，那么就输出Impossible，否则输出答案
void dfs(int index, int tmpSum, int tmpK, int facSum) {
	if (tmpK == K) {
		if (tmpSum == N && facSum > maxFacSum) {
			ans = tempAns;
			maxFacSum = facSum;
		}
		return;
	}
	//从最大因数递减到1
	while (index >= 1) {
		//最初的tmpSum和tmpK一直是0
		if (tmpSum + v[index] <= N)  {
			tempAns[tmpK] = index;
			dfs(index, tmpSum + v[index], tmpK + 1, facSum + index);
		}
		if (index == 1)return;
		index--;
	}
}

//这题根本不适合用动态规划。。。想歪了结果搞得更加复杂
//看了大佬们的解法，直接从大到小遍历递归就行了。。。外加一点剪枝
//下面是柳大佬的代码
int main()
{
	cin >> N >> K >> P;
	init();
	tempAns.resize(K);
	dfs(v.size() - 1, 0, 0, 0);
	if (maxFacSum == -1) {
		cout << "Impossible";
	}
	else {
		cout << N << " = ";
		for (int i = 0; i < ans.size(); i++) {
			if (i != 0) {
				cout << " + ";
			}
			cout << ans[i] << "^" << P;
		}
	}

	return 0;
}