#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

int list[100001];

bool comp(int a, int b) {
	return a > b;
}

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &list[i]);
	}
	sort(list, &list[N], comp);
	for (int i = 0; i < N; i++) {
		if (list[i] <= i + 1) {
			printf("%d", i);
			return 0;
		}
	}
	printf("%d", N);
	return 0;
}