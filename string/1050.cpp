#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main()
{
	string a, b;
	getline(cin, a);
	getline(cin, b);
	int table[128] = { 0 };
	int lenb = b.length();
	for (int i = 0; i < lenb; i++) {
		table[b[i]] = 1;
	}
	int lena = a.length();
	for (int i = 0; i < lena; i++) {
		if (!table[a[i]])
			printf("%c", a[i]);
	}

	return 0;
}