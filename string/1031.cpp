#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str;
	cin >> str;
	int len = str.size();
	int n = (len + 2) / 3;
	int yu = (len + 2) % 3;

	for (int i = 0; i < n-1; i++) {
		cout << str[i];
		for (int j = 0; j < n - 2 + yu; j++) {
			cout << " ";
		}
		cout << str[len - 1 - i] << endl;
	}

	for (int i = 0; i < n + yu; i++) {
		cout << str[n - 1 + i];
	}
	return 0;
}