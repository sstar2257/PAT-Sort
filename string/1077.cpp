#include <iostream>
#include <string>
using namespace std;
int main()
{
	int N;
	cin >> N;
	string str[100];
	cin.get();
	for (int i = 0; i < N; i++) {
		getline(cin, str[i]);
	}
	string comp = str[0];
	string res = "";
	//int flag = 0;
	for (int i = 1; i < N; i++) {
		int j = comp.size() - 1;
		int k = str[i].size() - 1;
		for (; j >= 0 && k >= 0; j--, k--) {
			if (comp[j] != str[i][k]) {
				break;
			}
			res = comp[j] + res;
		}
		if (res == "") {
			break;
		}
		comp.clear();
		comp = res;
		if (i != N - 1) {
			res.clear();
		}
	}
	if (res != "") {
		cout << res;
	}
	else {
		cout << "nai";
	}
	return 0;
}