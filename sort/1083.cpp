#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct stu {
	string name;
	string id;
	int grade;
};

bool comp(stu a, stu b) {
	return a.grade > b.grade;
}

int main()
{
	int N;
	cin >> N;
	stu *table = new stu[N + 1]();
	for (int i = 0; i < N; i++) {
		cin >> table[i].name >> table[i].id >> table[i].grade;
	}
	int low, high;
	cin >> low >> high;
	sort(table, &table[N], comp);
	int flag = 0;
	for (int i = 0; i < N; i++) {
		if (table[i].grade <= high && table[i].grade >= low) {
			flag = 1;
			cout << table[i].name << " " << table[i].id << endl;
		}
		else if (table[i].grade < low) {
			break;
		}
	}
	if (!flag) {
		cout << "NONE";
	}

	return 0;
}