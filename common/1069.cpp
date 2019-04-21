#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

string sub(string a, string b) {
	int flag = 0;
	string res;
	for (int i = 3; i >= 0; i--) {
		if (flag) {
			if (a[i] - 1 < b[i]) {
				res = to_string(a[i] + 10 - b[i] - flag) + res;
			}
			else {
				res = to_string(a[i] - b[i] - flag) + res;
				flag = 0;
			}
		}
		else {
			if (a[i] < b[i]) {
				res = to_string(a[i] + 10 - b[i]) + res;
				flag = 1;
			}
			else {
				res = to_string(a[i] - b[i]) + res;
			}
		}
	}
	return res;
}

string max_s(string a) {
	char ch;
	for (int i = 0; i < 4; i++) {
		for (int j = i + 1; j < 4; j++) {
			if (a[i] < a[j]) {
				ch = a[i];
				a[i] = a[j];
				a[j] = ch;
			}
		}
	}
	return a;
}

string min_s(string a) {
	char ch;
	for (int i = 0; i < 4; i++) {
		for (int j = i + 1; j < 4; j++) {
			if (a[i] >= a[j]) {
				ch = a[i];
				a[i] = a[j];
				a[j] = ch;
			}
		}
	}
	return a;
}

void op(string &input) {
	string big = max_s(input);
	string small = min_s(input);
	input = sub(big, small);
	cout << big << " - " << small << " = " << input << endl;
}

//注意输入的数不一定是4位的，需要先进行补零操作
int main()
{
	string input;
	cin >> input;
	input.insert(0, 4 - input.length(), '0');
	
	//sort(input.begin(), input.end());
	do {
		op(input);
	} while (input != "6174" && input != "0000");
	return 0;
}