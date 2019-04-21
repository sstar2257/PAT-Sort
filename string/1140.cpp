#include <iostream>
#include <string>
using namespace std;

string process(string str) {
	string res;
	int len = str.length();
	int same = 1;
	char ch = str[0];
	for (int i = 1; i < len; i++) {
		if (ch == str[i]) {
			same++;
		}
		else {
			//res = res + ch + to_string(same);
			//这里不用+=会超时，第一次发现这个对时间影响这么大
			res += ch + to_string(same);
			same = 1;
			ch = str[i];
		}
	}
	res += ch + to_string(same);
	return res;
}

int main()
{
	string D;
	int N;
	cin >> D >> N;
	for (int i = 1; i < N; i++) {
		D = process(D);
	}
	cout << D;
	return 0;
}