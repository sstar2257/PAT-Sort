#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

//32位int可能会越界
int main() {
	int N;
	long long p;
	scanf("%d %lld", &N, &p);
	int *list = new int[N + 1]();
	for (int i = 0; i < N; i++) {
		scanf("%d", &list[i]);
	}
	sort(list, &list[N]);
	int out = 0;
	int max = 0;
	long long maxi, mini;
	for (int left = 0, right = 0; left < N && right < N;) {
		mini = (long long)list[left];
		maxi = (long long)list[right];
		//printf("%d\n", mini*p);
		if (maxi <= mini * (long long)p) {
			max++;
			right++;
		}
		else {
			max--;
			left++;
		}
		if (max > out) {
			out = max;
		}
	}
	printf("%d", out);
	return 0;
}