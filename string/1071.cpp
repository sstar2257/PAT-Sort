#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool comp(pair<string, int>a, pair<string, int>b) {
	if (a.second != b.second) {
		return a.second > b.second;
	}
	else {
		return a.first < b.first;
	}
}

int main()
{
	char ch;
	cin.get(ch);
	string res;
	map<string, int> table;

	while (ch != '\n') {
		if (ch >= '0' && ch <= '9') {
			res += ch;
		}
		else if (ch >= 'a' && ch <= 'z') {
			res += ch;
		}
		else if (ch >= 'A' && ch <= 'Z') {
			res += 'a' + (ch - 'A');
		}
		else {
			if (res.length() != 0) {
				if (table.find(res) != table.end()) {
					table[res]++;
				}
				else {
					table[res] = 1;
				}
				res.clear();
			}
		}
		cin.get(ch);
	}
	//当输入到\n之后，需要对res做处理
	if (res.length() != 0) {
		if (table.find(res) != table.end()) {
			table[res]++;
		}
		else {
			table[res] = 1;
		}
		res.clear();
	}
	vector<pair<string, int>> list(table.begin(), table.end());
	sort(list.begin(), list.end(), comp);
	cout << list.begin()->first << " " << list.begin()->second;
	return 0;
}