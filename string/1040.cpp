#include <iostream>
#include <string>
using namespace std;
//直接O(n^2)复杂度算法搞定了。。。
int main() 
{
	string str;
	getline(cin, str);
	int len = str.length();
	int max = 0;
	int tmp;
	//回文序列有两种情况，分开考虑
	//成对回文
	for (int i = 0; i < len; i++) {
		tmp = 0;
		for (int l = i, r = i + 1; i >= 0 && r < len; l--, r++) {
			if (str[l] == str[r]) {
				tmp += 2;
			}
			else {
				break;
			}
		}
		if (tmp > max) {
			max = tmp;
		}
	}
	//成单的回文
	for (int i = 0; i < len; i++) {
		tmp = 1;
		for (int l = i - 1, r = i + 1; l >= 0 && r < len; l--, r++) {
			if (str[l] == str[r]) {
				tmp += 2;
			}
			else {
				break;
			}
		}
		if (tmp > max) {
			max = tmp;
		}
	}
	cout << max << endl;
	return 0;
}