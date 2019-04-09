
#include <iostream>
#include <set>
using namespace std;

int sum(int num) {
	int res = 0;
	while (num / 10 != 0) {
		res += num % 10;
		num /= 10;
	}
	res += num;
	return res;
}

int main()
{
	int N;
	cin >> N;
	set<int> table;
	int a, input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		a = sum(input);
		table.insert(a);
	}
	cout << table.size() << endl;
	auto it = table.begin();
	cout << *it;
	for (++it; it != table.end(); it++) {
		cout << " " << *it;
	}
	return 0;
}