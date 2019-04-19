#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//注意开头是零的问题
//尽量把零多的放开头，这样后来能减少好几位
bool comp(string a, string b) {
	string a_b = a + b;
	string b_a = b + a;
	return a_b < b_a;
}

int main()
{
	int N;
	cin >> N;
	vector<string> list(N);
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
	sort(list.begin(), list.end(), comp);
	int flag = 0;
	auto it = list.begin();
	for (; it != list.end(); it++) {
		for (int i = 0; i < it->size(); i++) {
			if ((*it)[i] != '0' || flag) {
				cout << (*it)[i];
				flag = 1;
			}
		}
		if (flag) {
			it++;
			break;
		}
	}
	//注意输出0的情况
	if (!flag) {
		cout << "0";
	}
	while (it != list.end()) {
		cout << (*it);
		it++;
	}
	return 0;
}