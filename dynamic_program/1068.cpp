#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<algorithm>

using namespace std;

int dp[10005][105];
int flag[10005][105];
int num[10005];

bool cmp(int a, int b) {
	return a>b;

}
int calculate(int n, int m) {

	for (int i = 1; i<n + 1; i++) {
		for (int j = 1; j <= m; j++) {
			if (j<num[i] || dp[i - 1][j - num[i]] + num[i]<dp[i - 1][j])//j<num[i]，说明只能从前i-1个里面找满足不大于j的最大数额
				dp[i][j] = dp[i - 1][j];
			else {
				dp[i][j] = dp[i - 1][j - num[i]] + num[i];
				flag[i][j] = 1;//记录下有没有取

			}
		}


	}
	return dp[n][m];

}
//01背包问题
//可以把硬币看成w=v(即容量=价值)的物品，现在要选取这些物品放入到容量为m的背包中，求能装的最大价值。
//如果最大价值恰好等于容量m，那么方案则是可行的，否则输出No Solution。
//由于要输出排列最小的方案，所以先将硬币按价值从大到小排列，相当于我先装大的，再装小的。
//状态方程：F（n,m）=max{F（n-1,m）,F(n-1,m-num[n])+num[n]}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", num + 1 + i);
	sort(num + 1, num + 1 + n, cmp);
	memset(dp, 0, sizeof(dp));
	memset(flag, 0, sizeof(flag));
	int t = calculate(n, m);

	if (t != m) {
		printf("No Solution\n");

	}
	else {
		int first = 1;
		while (m) {
			while (!flag[n][m])
				n--;
			if (first) {
				printf("%d", num[n]);
				first = 0;
			}
			else
				printf(" %d", num[n]);

			m = m - num[n];
			n--;
		}

	}

	return 0;
}