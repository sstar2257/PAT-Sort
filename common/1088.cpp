#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

long long gcd(long long a, long long b) {
	return (b == 0) ? a : gcd(b, a%b);
}

void simple_format(long long a, long long b) {
	if (a == 0) {
		printf("0");
	}
	else {
		long long flag = 0;
		if (a < 0) {
			a = -a;
			flag = 1;
		}
		long long zheng = a / b;
		a = a%b;
		if (flag) {
			printf("-");
		}
		if (zheng) {
			printf("%lld", zheng);
			if (a) {
				printf(" %lld/%lld", a, b);
			}
		}
		else {
			printf("%lld/%lld", a, b);
		}

	}
}

void print(long long a1, long long b1, long long a2, long long b2, long long a3, long long b3, char op) {
	if (a1 < 0) {
		printf("(");
		simple_format(a1, b1);
		printf(")");
	}
	else {
		simple_format(a1, b1);
	}
	printf(" %c ", op);
	if (a2 < 0) {
		printf("(");
		simple_format(a2, b2);
		printf(")");
	}
	else {
		simple_format(a2, b2);
	}
	printf(" = ");
	if (a3 < 0) {
		printf("(");
		simple_format(a3, b3);
		printf(")");
	}
	else {
		simple_format(a3, b3);
	}
	printf("\n");
}

void sum(long long a1, long long b1, long long a2, long long b2) {
	long long a3 = a1*b2 + b1*a2;
	long long b3 = b1*b2;
	long long flag = 0;
	if (a3 < 0) {
		a3 = -a3;
		flag = 1;
	}
	long long gcd3 = gcd(a3, b3);
	a3 /= gcd3;
	b3 /= gcd3;
	if (flag) {
		a3 = -a3;
	}
	print(a1, b1, a2, b2, a3, b3, '+');
}

void diff(long long a1, long long b1, long long a2, long long b2) {
	long long a3 = a1*b2 - b1*a2;
	long long b3 = b1*b2;
	long long flag = 0;
	if (a3 < 0) {
		a3 = -a3;
		flag = 1;
	}
	long long gcd3 = gcd(a3, b3);
	a3 /= gcd3;
	b3 /= gcd3;
	if (flag) {
		a3 = -a3;
	}
	print(a1, b1, a2, b2, a3, b3, '-');
}

void pro(long long a1, long long b1, long long a2, long long b2) {
	long long a3 = a1*a2;
	long long b3 = b1*b2;
	long long flag = 0;
	if (a3 < 0) {
		a3 = -a3;
		flag = 1;
	}
	long long gcd3 = gcd(a3, b3);
	a3 /= gcd3;
	b3 /= gcd3;
	if (flag) {
		a3 = -a3;
	}
	print(a1, b1, a2, b2, a3, b3, '*');
}

void quo(long long a1, long long b1, long long a2, long long b2) {
	long long a3 = a1*b2;
	long long b3 = b1*a2;
	long long flag = 0;
	if (b3 == 0) {
		if (a1 < 0) {
			printf("(");
			simple_format(a1, b1);
			printf(")");
		}
		else {
			simple_format(a1, b1);
		}
		printf(" / 0 = Inf\n");
		return;
	}
	else if (a3 > 0 && b3 < 0) {
		b3 = -b3;
		flag = 1;
	}
	else if (a3 < 0 && b3 < 0) {
		a3 = -a3;
		b3 = -b3;
	}
	else if (a3 < 0 && b3 >0) {
		a3 = -a3;
		flag = 1;
	}
	long long gcd3 = gcd(a3, b3);
	a3 /= gcd3;
	b3 /= gcd3;
	if (flag) {
		a3 = -a3;
	}
	print(a1, b1, a2, b2, a3, b3, '/');
}
//不用long long测试点3会出现浮点错误
//每次进行gcd之前必须都先把负数转换为正数!!!
int main()
{
	long long a1, a2, b1, b2;
	scanf("%lld/%lld %lld/%lld", &a1, &b1, &a2, &b2);
	int flag = 0;
	if (a1 < 0) {
		a1 = -a1;
		flag = 1;
	}
	long long gcd1 = gcd(a1, b1);
	a1 /= gcd1;
	b1 /= gcd1;
	if (flag) {
		a1 = -a1;
		flag = 0;
	}
	if (a2 < 0) {
		a2 = -a2;
		flag = 1;
	}
	long long gcd2 = gcd(a2, b2);
	a2 /= gcd2;
	b2 /= gcd2;
	if (flag) {
		a2 = -a2;
	}
	sum(a1, b1, a2, b2);
	diff(a1, b1, a2, b2);
	pro(a1, b1, a2, b2);
	quo(a1, b1, a2, b2);
	return 0;
}