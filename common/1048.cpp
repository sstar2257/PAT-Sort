#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main() 
{
	int N, M;
	cin >> N >> M;
	vector<int> coins(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &coins[i]);
	} 
	sort(coins.begin(), coins.end());
	/*int half = M / 2;
	for (auto it = coins.begin(); *it <= half && it!=coins.end(); it++) {
		int another = M - *it;
		if (find(it + 1, coins.end(), another) != coins.end()) {
			printf("%d %d", *it, another);
			return 0;
		}
	}*/
	int i = 0, j = N - 1;
	//从两边逼近
	while (i < j) {
		int sum = coins[i] + coins[j];
		if (sum > M) {
			j--;
		}
		else if (sum < M) {
			i++;
		}
		else {
			printf("%d %d", coins[i], coins[j]);
			return 0;
		}
	}
	printf("No Solution");
	return 0;
}