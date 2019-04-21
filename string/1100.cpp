#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

string m_low[13] = { "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
string m_high[12] = { "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };

void e2m(int num) {
	if (num <= 12) {
		cout << m_low[num] << endl;
	}
	else {
		int i_high = num / 13;
		int i_low = num % 13;
		if (i_low) {
			cout << m_high[i_high - 1] << " " << m_low[i_low] << endl;
		}
		else {
			cout << m_high[i_high - 1] << endl;
		}
	}
}

//string e2m(int num) {
//	string res;
//	if (num <= 12) {
//		res = m_low[num];
//	}
//	else {
//		int i_high = num / 13;
//		int i_low = num % 13;
//		if (i_low) {
//			res = (m_high[i_high - 1] + " " + m_low[i_low]);
//		}
//		else {
//			res = m_high[i_high - 1];
//		}
//	}
//	return res;
//}

void m2e(string str) {
	if (str.size() > 3 && str != "tret") {
		string s_high = str.substr(0, 3);
		string s_low = str.substr(4);
		int n_high;
		int n_low;
		for (int i = 0; i < 12; i++) {
			if (s_high == m_high[i]) {
				n_high = i + 1;
				break;
			}
		}
		for (int i = 0; i < 13; i++) {
			if (s_low == m_low[i]) {
				n_low = i;
				break;
			}
		}
		cout << n_high * 13 + n_low << endl;
	}
	else {
		for (int i = 0; i < 13; i++) {
			if (str == m_low[i]) {
				cout << i << endl;
				break;
			}
		}
		for (int i = 0; i < 12; i++) {
			if (str == m_high[i]) {
				cout << (i + 1) * 13 << endl;
			}
		}
	}
}
//int m2e(string str) {
//	if (str.size() > 3 && str != "tret") {
//		string s_high = str.substr(0, 3);
//		string s_low = str.substr(4);
//		int n_high = 0;
//		int n_low = 0;
//		for (int i = 0; i < 12; i++) {
//			if (s_high == m_high[i]) {
//				n_high = i + 1;
//				break;
//			}
//		}
//		for (int i = 0; i < 13; i++) {
//			if (s_low == m_low[i]) {
//				n_low = i;
//				break;
//			}
//		}
//		return n_high * 13 + n_low;
//	}
//	else {
//		for (int i = 0; i < 13; i++) {
//			if (str == m_low[i]) {
//				return i;
//				break;
//			}
//		}
//		for (int i = 0; i < 12; i++) {
//			if (str == m_high[i]) {
//				return (i + 1) * 13;
//			}
//		}
//	}
//}

int main()
{
	int N;
	cin >> N;
	cin.get();
	string str;
	int num;
	for (int i = 0; i < N; i++) {
		getline(cin, str);
		if (str[0] >= '0' && str[0] <= '9') {
			num = atoi(str.c_str());
			e2m(num);
		}
		else {
			m2e(str);
		}
	}
	//for (int i = 0; i < 169; i++) {
	//	string str = e2m(i);
	//	int num = m2e(str);
	//	if (i != num) {
	//		cout << i << " " << str << " " << num << endl;
	//	}
	//}
	return 0;
}