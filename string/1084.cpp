#include <iostream>
#include <string>
#include <set>
using namespace std;

char upper(char a) {
	if (a >= 'a' && a <= 'z') {
		a += ('A' - 'a');
	}
	return a;
}


int main()
{
	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);
	int len1 = str1.length();
	int len2 = str2.length();
	set<char> table;
	int i, j;
	for (i = 0, j = 0; i < len1 && j < len2;) {
		if (str1[i] == str2[j]) {
			i++;
			j++;
			continue;
		}
		else {
			char ch = upper(str1[i]);
			if (table.find(ch) == table.end()) {
				table.insert(ch);
				cout << ch;
			}
			i++;
		}
	}
	while (i < len1) {
		char ch = upper(str1[i]);
		if (table.find(ch) == table.end()) {
			table.insert(ch);
			cout << ch;
		}
		i++;
	}

	return 0;
}