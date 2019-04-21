#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;
int main()
{
	int N;
	scanf("%d", &N);
	double *seq = new double[N]();
	for (int i = 0; i < N; i++) {
		scanf("%lf", &seq[i]);
	}
	double sum = 0;
	for (int i = 0; i < N; i++) {
		//int_32范围大约是21亿，两个int先乘会超
		//sum += (N - i)*(i + 1)*seq[i];
		sum += seq[i] * (N - i) * (i + 1);
	}
	printf("%.2lf", sum);
	return 0;
}