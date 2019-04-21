#include <iostream>
#include <string>
using namespace std;

int judge(string str) {
	int len = str.length();
	for (int i = 0; i < len / 2; i++) {
		if (str[i] != str[len - 1 - i]) {
			return 0;
		}
	}
	return 1;
}

string add(string a) {
	string res, b;
	for (auto it = a.rbegin(); it != a.rend(); it++) {
		if (*it != '0') {
			b.append(it, a.rend());
			break;
		}
	}
	int flag = 0;
	int num;
	int len_a = a.length();
	int len_b = b.length();
	int i;
	for (i = 0; i < len_a && i < len_b; i++) {
		num = a[len_a - 1 - i] - '0' + b[len_b - 1 - i] - '0' + flag;
		if (num >= 10) {
			num -= 10;
			flag = 1;
		}
		else {
			flag = 0;
		}
		res = to_string(num) + res;
	}
	while (i < len_a) {
		num = a[len_a - 1 - i] - '0' + flag;
		if (num >= 10) {
			num -= 10;
			flag = 1;
		}
		else {
			flag = 0;
		}
		i++;
		res = to_string(num) + res;
	}
	while (i < len_b) {
		num = b[len_b - 1 - i] - '0' + flag;
		if (num >= 10) {
			num -= 10;
			flag = 1;
		}
		else {
			flag = 0;
		}
		i++;
		res = to_string(num) + res;
	}
	if (flag) {
		res = "1" + res;
	}
	cout << a << " + " << b << " = " << res << endl;
	return res;
}

int main()
{
	string str;
	cin >> str;
	int found = 0;
	for (int i = 0; i < 10; i++) {
		if (judge(str)) {
			cout << str << " is a palindromic number." << endl;
			found = 1;
			break;
		}
		else {
			str = add(str);
		}
	}
	if (!found) {
		cout << "Not found in 10 iterations." << endl;
	}

	return 0;
}