#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct stu {
	string name;
	string id;
	int grade;
};

bool comp(stu a, stu b) {
	return a.grade > b.grade;
}

bool comp_up(stu a, stu b) {
	return a.grade < b.grade;
}

int main()
{
	int N;
	cin >> N;
	vector<stu> male;
	vector<stu> female;
	for (int i = 0; i < N; i++) {
		stu one;
		char c;
		cin >> one.name >> c >> one.id >> one.grade;
		if (c == 'M')
			male.push_back(one);
		else
			female.push_back(one);
	}

	int is_absent = 0;

	if (!female.empty()) {
		sort(female.begin(), female.end(), comp);
		cout << female[0].name << " " << female[0].id << endl;
	}
	else {
		cout << "Absent" << endl;
		is_absent = 1;
	}

	if (!male.empty()) {
		sort(male.begin(), male.end(), comp_up);
		cout << male[0].name << " " << male[0].id << endl;
	}
	else {
		cout << "Absent" << endl;
		is_absent = 1;
	}

	if (is_absent) {
		cout << "NA" << endl;
	}
	else {
		cout << female[0].grade - male[0].grade << endl;
	}
	return 0;

}