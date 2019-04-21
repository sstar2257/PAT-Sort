#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int judge(string str) {
	if (str.size() > 8) {
		return 0;
	}
	if ((str[0] > '9' || str[0] < '0') && str[0] != '-') {
		return 0;
	}
	int point = 0;
	for (int i = 1; i < str.size(); i++) {
		if (str[i] <= '9' && str[i] >= '0') {
			continue;
		}
		else if (str[i] == '.') {
			point++;
			if (point > 1) {
				return 0;
			}
			if (str.size() - 1 - i > 2) {
				return 0;
			}
		}
	}
	return 1;
}

int main()
{
	int N;
	cin >> N;
	double sum = 0;
	int num = 0;
	int flag;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		flag = judge(str);
		if (!flag) {
			cout << "ERROR: " << str << " is not a legal number" << endl;
		}
		else {
			double tmp = atof(str.c_str());
			if (tmp > 1000 || tmp < -1000) {
				cout << "ERROR: " << str << " is not a legal number" << endl;
			}
			else {
				sum += atof(str.c_str());
				num++;
			}
		}
	}
	if (num == 0) {
		printf("The average of 0 numbers is Undefined");
	}
	else if (num == 1) {
		printf("The average of 1 number is %.2lf", sum);
	}
	else {
		printf("The average of %d numbers is %.2lf", num, sum / num);
	}
	return 0;
}