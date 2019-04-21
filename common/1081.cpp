#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

long long int numerator[100];
long long int denominator[100];

long long int gcm(long long int m, long long int n) {
	long long int a;
	if (m < n) {
		a = m;
		m = n;
		n = a;
	}
	if (n < 0) {
		n = -n;
	}
	long long int c;
	while (n != 0) {
		c = m%n;
		m = n;
		n = c;
	}
	return m;
}

int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%lld/%lld", &numerator[i], &denominator[i]);
	}
	
	long long int x1, y1, x2, y2;
	long long int x, y;
	long long int gcm_xy;
	x1 = numerator[0];
	y1 = denominator[0];
	for (int i = 1; i < N; i++) {
		x2 = numerator[i];
		y2 = denominator[i];
		y = y1*y2;
		x = x1*y2 + x2*y1;
		gcm_xy = gcm(x, y);
		x1 = x / gcm_xy;
		y1 = y / gcm_xy;
	}
	
	if (x1 == 0) {
		printf("0");
		
	}
	else {
		if (x1 < 0) {
			x1 = -x1;
			printf("-");	
		}
		long long inter = x1 / y1;
		long long fac = x1%y1;
		if (inter != 0) {
			printf("%lld", inter);
			if (fac != 0) {
				gcm_xy = gcm(fac, y1);
				printf(" %lld/%lld", fac / gcm_xy, y1 / gcm_xy);
			}
		}
		else{
			if (fac != 0) {
				gcm_xy = gcm(fac, y1);
				printf("%lld/%lld", fac / gcm_xy, y1 / gcm_xy);
			}
		}


	}
	return 0;
}
