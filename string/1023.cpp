#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string double_str(string str) {
	int len = str.size();
	int flag = 0;
	string output;
	for (int i = len - 1; i >= 0; i--) {
		int tmp = (str[i] - '0') * 2 + flag;
		if (tmp >= 10) {
			flag = 1;
			output += tmp - 10 + '0';
		}
		else {
			flag = 0;
			output += tmp + '0';
		}
	}
	if (flag) {
		output += '1';
	}
	reverse(output.begin(), output.end());
	return output;
}

void count(int *arr, string str) {
	int len = str.size();
	int num;
	for (int i = 0; i < len; i++) {
		num = str[i] - '0';
		arr[num]++;
	}
}

int main()
{
	string input;
	int arr1[10] = {0};
	int arr2[10] = {0};
	cin >> input;
	count(arr1, input);
	string dou = double_str(input);
	count(arr2, dou);
	int mark = 0;
	for (int i = 0; i < 10; i++) {
		if (arr1[i] != arr2[i]) {
			mark = 1;
			break;
		}
	}
	if (mark)
		cout << "No" << endl;
	else
		cout << "Yes" << endl;

	cout << dou << endl;
	return 0;
}