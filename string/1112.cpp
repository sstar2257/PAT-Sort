#include <iostream>
#include <string>
using namespace std;
int main()
{
	int K;
	cin >> K;
	string str;
	cin >> str;
	str.append("#");
	int len = str.length();
	char a = str[0];
	char b;
	int same = 1;
	int mark[128] = { 0 };
	string res;
	for (int i = 1; i < len; i++) {
		b = str[i];
		if (a == b) {
			same++;
		}
		else {
			if (same % K == 0) {
				res += a;
			}
			else {
				mark[a] = 1;
			}
			same = 1;
			a = b;
		}
	}
	for (int i = 0; i < res.length(); i++) {
		if (!mark[res[i]]) {
			cout << res[i];
			mark[res[i]]--;
		}
	}
	cout << endl;
	for (int i = 0; i < len - 1; i++) {
		if (mark[str[i]] > 0) {
			cout << str[i];
		}
		else {
			cout << str[i];
			i += K - 1;
		}
	}

	return 0;
}