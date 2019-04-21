#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str;
	string res;
	cin >> str;
	if (str[0] == '-') {
		res += '-';
	}
	int e = str.find('E');
	string e_l = str.substr(1, e - 1);
	string e_r = str.substr(e + 2);
	int exp = stoi(e_r);
	char symbol = str[e + 1];
	int p = e_l.find('.');
	string p_l = e_l.substr(0, p);
	string p_r = e_l.substr(p + 1);
	res += p_l + p_r;
	if (symbol == '+') {
		if (exp >= p_r.length()) {
			res.insert(res.end(), exp - p_r.length(), '0');
		}
		else {
			res.insert(res.size() - (p_r.length() - exp), 1, '.');
		}
	}
	else {
		if (exp < p_l.length()) {
			res.insert(p_l.length() - exp, 1, '.');
		}
		else {
			//插入的时候要考虑到第一位是否有‘-’
			if (res[0] != '-') {
				res.insert(res.begin(), exp - p_l.length() + 1, '0');
				res.insert(1, 1, '.');
			}
			else {
				res.insert(++res.begin(), exp - p_l.length() + 1, '0');
				res.insert(2, 1, '.');
			}
		}
	}
	cout << res;
	return 0;
}