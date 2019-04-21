#include <iostream>
#include <string>
using namespace std;

//string output(int num, string str) {
//	string res;
//	int pos = str.find('.');
//	int power;
//	if (pos == string::npos) {
//		power = str.length();
//	}
//	else {
//		power = pos;
//	}
//	int mark = 0;
//	//0.xx
//	if (pos == 1 && str[0] == '0') {
//		power = 0;
//		res += "0.";
//		for (int i = 2; i < str.length() && mark < num; i++) {
//			if (str[i] == '0' && !mark) {
//				power++;
//			} 
//			else {
//				res += str[i];
//				mark++;
//			}
//		}
//		while (mark < num) {
//			res += "0";
//			mark++;
//		}
//		res += "*10^-";
//		res += (power + '0');
//	}
//	else {//a.xx while a!=0
//		res += "0.";
//		for (int i = 0; i < str.length() && mark < num; i++) {
//			if (i != pos) {
//				res += str[i];
//				mark++;
//			}
//		}
//		while (mark < num) {
//			res += "0";
//			mark++;
//		}
//		res += "*10^";
//		res += (power + '0');
//	}
//	return res;
//}

//需要考虑各种奇葩情况。。。
string output(int num, string str) {
	int point = str.find('.');
	int first = str.find_first_not_of("0.");
	string res;
	int power = 0;
	int mark = 0;
	res += "0.";
	if (first == string::npos) {
		while (mark < num) {
			res += '0';
			mark++;
		}
		res += "*10^0";
	}
	else {
		if (point == string::npos || point > first) {
			if (point == string::npos) {
				power = str.size() - first;
			}
			else {
				power = point - first;
			}
			for (int i = first; i < str.length() && mark < num; i++) {
				if (str[i] != '.') {
					res += str[i];
					mark++;
				}
			}
			while (mark < num) {
				res += '0';
				mark++;
			}
			res += "*10^";
			res += to_string(power);
		}
		else {
			power = -(first - point - 1);
			for (int i = first; i < str.length() && mark < num; i++) {
				if (str[i] != '.') {
					res += str[i];
					mark++;
				}
			}
			while (mark < num) {
				res += "0";
				mark++;
			}
			res += "*10^";
			res += to_string(power);
		}

	}
	return res;
}


int main()
{
	int N;
	cin >> N;
	string A, B;
	cin >> A >> B;

	string a = output(N, A);
	string b = output(N, B);
	if (a == b) {
		cout << "YES" << " " << a;
	}
	else {
		cout << "NO" << " " << a << " " << b;
	}
	return 0;
}