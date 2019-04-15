#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

string palin(string str1) {
	string res;
	string str2 = str1;
	reverse(str1.begin(), str1.end());
	int len1 = str1.size();
	int len2 = str2.size();
	int len = len1 > len2 ? len2 : len1;
	int flag = 0;
	int num;
	for (int i = 0; i < len; i++) {
		num = str1[i] + str2[i] - '0' - '0' + flag;
		if (num >= 10) {
			flag = 1;
			res += num - 10 + '0';
		}
		else {
			flag = 0;
			res += num + '0';
		}
	}
	while (len < len1) {
		num = str1[len] - '0' + flag;
		if (num >= 10) {
			flag = 1;
			res += num - 10 + '0';
		}
		else {
			flag = 0;
			res += num + '0';
		}
	}
	while (len < len2) {
		num = str2[len] - '0' + flag;
		if (num >= 10) {
			flag = 1;
			res += num - 10 + '0';
		}
		else {
			flag = 0;
			res += num + '0';
		}
	}
	if (flag)
		res += '1';
	reverse(res.begin(), res.end());
	return res;
}

int is_palin(string str) {
	int len = str.size();
	for (int i = 0; i < len / 2; i++) {
		if (str[i] != str[len - 1 - i])
			return 0;
	}
	return 1;
}

int main()
{
	string N;
	int K;
	cin >> N >> K;
	int ret;
	ret = is_palin(N);
	if (ret) {
		cout << N << endl;
		cout << "0" << endl;
		return 0;
	}
	for (int i = 0; i < K; i++) {
		N = palin(N);
		ret = is_palin(N);
		if (ret) {
			cout << N << endl;
			cout << i + 1 << endl;
			return 0;
		}
	}
	cout << N << endl;
	cout << K << endl;
	return 0;
}