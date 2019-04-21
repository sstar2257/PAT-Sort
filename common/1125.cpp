#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

int seg[10001];

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &seg[i]);
	}
	sort(seg, &seg[N]);
	double sum = seg[0];
	for (int i = 1; i < N; i++) {
		sum = (sum + seg[i]) / 2;
	}
	printf("%d", (int)sum);
	return 0;
}