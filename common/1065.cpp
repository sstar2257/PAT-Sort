#include <iostream>
#include <string>
using namespace std;

//完全不用string，在long long int范围内，只需要考虑大值相加是否会溢出即可
//两个正数相加
string sum(string a, string b) {
	int flag = 0;
	int lena = a.size();
	int lenb = b.size();
	string res;
	int i, j;
	for (i = lena - 1, j = lenb - 1; i >= 0 && j >= 0; i--, j--) {
		int tmp = a[i] - '0' + b[j] - '0' + flag;
		if (tmp >= 10) {
			res = to_string(tmp - 10) + res;
			flag = 1;
		}
		else {
			res = to_string(tmp) + res;
			flag = 0;
		}
	}
	while (i >= 0) {
		int tmp = a[i] - '0' + flag;
		if (tmp >= 10) {
			res = to_string(tmp - 10) + res;
			flag = 1;
		}
		else {
			res = to_string(tmp) + res;
			flag = 0;
		}
		i--;
	}
	while (j >= 0) {
		int tmp = b[j] - '0' + flag;
		if (tmp >= 10) {
			res = to_string(tmp - 10) + res;
			flag = 1;
		}
		else {
			res = to_string(tmp) + res;
			flag = 0;
		}
		j--;
	}
	if (flag) {
		res = '1' + res;
	}
	return res;
}
//return 1 if a>b
//return 0 others
int judge(string a, string b) {
	if (a[0] != '-' && b[0] == '-') {
		return 1;
	}
	else if (a[0] == '-' && b[0] != '-') {
		return 0;
	}
	else if (a[0] != '-' && b[0] != '-') {
		int lena = a.size();
		int lenb = b.size();
		if (lena > lenb) {
			return 1;
		}
		else if (lena < lenb) {
			return 0;
		}
		else {
			for (int i = 0; i < lena; i++) {
				if (a[i] > b[i]) {
					return 1;
				}
				else if (a[i] < b[i]) {
					return 0;
				}
			}
			return 0;
		}
	}
	else {
		int lena = a.size();
		int lenb = b.size();
		if (lena > lenb) {
			return 0;
		}
		else if (lena < lenb) {
			return 1;
		}
		else {
			for (int i = 1; i < lena; i++) {
				if (a[i] > b[i]) {
					return 0;
				}
				else if (a[i] < b[i]) {
					return 1;
				}
			}
			return 0;
		}
	}
}

int main()
{
	int N;
	cin >> N;
	string a, b, c;
	string res;
	int flag;
	for (int i = 1; i <= N; i++) {
		cin >> a >> b >> c;
		if (a[0] != '-') {
			if (b[0] != '-') {
				res = sum(a, b);
				flag = judge(res, c);
			}
			else {
				if (c[0] != '-') {
					b = b.substr(1);
					res = sum(b, c);
					flag = judge(a, res);
				}
				else {
					c = c.substr(1);
					b = b.substr(1);
					res = sum(a, c);
					flag = judge(res, b);
				}
			}
		}
		else {
			if (b[0] != '-') {
				if (c[0] != '-') {
					a = a.substr(1);
					res = sum(a, c);
					flag = judge(b, res);
				}
				else {
					a = a.substr(1);
					c = c.substr(1);
					res = sum(b, c);
					flag = judge(res, a);
				}
			}
			else {
				if (c[0] != '-') {
					a = a.substr(1);
					res = sum(a, c);
					flag = judge(b, res);
				}
				else {
					a = a.substr(1);
					b = b.substr(1);
					c = c.substr(1);
					res = sum(a, b);
					flag = judge(c, res);
				}
			}
		}
		if (flag) {
			cout << "Case #" << i <<": true" << endl;
		}
		else {
			cout << "Case #" << i << ": false" << endl;
		}
	}

	return 0;
}