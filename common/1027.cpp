#include <iostream>
#include <cstdio>
using namespace std;

char radix[13] = { '0', '1','2','3','4','5','6','7','8','9','A','B','C' };

void trans(int i) {
	int yu = i % 13;
	int chu = i / 13;
	cout << radix[chu] << radix[yu];
}

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	cout << "#";
	trans(a);
	trans(b);
	trans(c);
	return 0;
}