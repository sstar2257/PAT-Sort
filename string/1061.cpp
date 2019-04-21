#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

//感觉以后会挂在读题目上
char day[7][4] = { "MON" , "TUE", "WED","THU","FRI" ,"SAT", "SUN" };
int main()
{
	string str[4];
	int len[4];
	for (int i = 0; i < 4; i++) {
		cin >> str[i];
		len[i] = str[i].length();
	}

	int i, j;
	for (i = 0; i < len[0] && i < len[1]; i++) {
		if (str[0][i] == str[1][i] && str[0][i] <= 'G'  && str[0][i] >= 'A') {
			break;
		}
	}
	cout << &day[str[0][i] - 'A'][0] << " ";
	int hour;
	for (i = i+1; i < len[0] && i < len[1]; i++) {
		if (str[0][i] == str[1][i]) {
			if (str[0][i] <= 'N' && str[0][i] >= 'A') {
				hour = str[0][i] - 'A' + 10;
				break;
			}
			else if (str[0][i] >= '0' && str[0][i] <= '9') {
				hour = str[0][i] - '0';
				break;
			}
		}
	}
	printf("%02d:", hour);
	for (j = 0; j <= 60; j++) {
		if (str[2][j] == str[3][j] && ((str[2][j] <= 'Z' && str[2][j] >= 'A') || (str[2][j] <= 'z' && str[2][j] >= 'a'))) {
			break;
		}
	}
	printf("%02d", j);
	return 0;
}