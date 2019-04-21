#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;
bool mark[100002];
//乍看很复杂。。。其实因为是输出最小的数，所以只需要考虑1-100000之间的数就可以了
int main()
{
	int N;
	scanf("%d", &N);
	int input;
	for (int i = 0; i < N; i++) {
		scanf("%d", &input);
		if (input > 0 && input <= 100000) {
			mark[input] = true;
		}
	}
	for (int i = 1; i < 100002; i++) {
		if (!mark[i]) {
			printf("%d", i);
			break;
		}
	}
	return 0;
}