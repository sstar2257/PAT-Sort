#include <iostream>
#include <vector>
using namespace std;

vector<int> table;

void trans(long num, long base) {
	int yu;
	if (!num) {
		table.push_back(0);
	}
	while (num != 0) {
		yu = num%base;
		table.push_back(yu);
		num /= base;
	}
	return;
}

int comp() {
	int size = table.size();
	for (int i = 0; i < size / 2; i++) {
		if (table[i] == table[size - 1 - i]) {
			continue;
		}
		else
			return 0;
	}
	return 1;
}

int main()
{
	int N, b;
	cin >> N >> b;
	trans(N, b);
	if (comp())
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	for (int i = table.size() - 1; i > 0; i--) {
		cout << table[i] << " ";
	}
	cout << table[0];

	return 0;
}