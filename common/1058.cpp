#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;
int main()
{
	int a1, b1, c1;
	int a2, b2, c2;
	scanf("%d.%d.%d", &a1, &b1, &c1);
	scanf("%d.%d.%d", &a2, &b2, &c2);

	int flag = 0;
	int cc = c1 + c2;
	if (cc >= 29) { 
		cc -= 29;
		flag = 1;
	}
	int bb = b1 + b2 + flag;
	if (bb >= 17) {
		bb -= 17;
		flag = 1;
	}
	else {
		flag = 0;
	}
	int aa = a1 + a2 + flag;
	printf("%d.%d.%d", aa, bb, cc);
	return 0;
}