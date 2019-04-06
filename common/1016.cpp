#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

struct record {
	string name;
	int mon, day, hour, min;
	string status;
};

bool comp(record a, record b) {
	if (a.name != b.name)
		return a.name < b.name ? true : false;
	else if (a.day != b.day)
		return a.day < b.day ? true : false;
	else if (a.hour != b.hour)
		return a.hour < b.hour ? true : false;
	else
		return a.min < b.min ? true : false;
} 

int sum(record a, record b) {
	int sum_a = 24 * 60 * a.day + 60 * a.hour + a.min;
	int sum_b = 24 * 60 * b.day + 60 * b.hour + b.min;
	return sum_a > sum_b ? sum_a - sum_b : sum_b - sum_a;
}

int count(record a, record b, int *arr) {
	int one_day = 0;
	for (int i = 0; i < 24; i++) {
		one_day += arr[i];
	}
	one_day *= 60;
	int count_a = one_day * a.day;
	for (int i = 1; i <= a.hour; i++) {
		count_a += 60 * arr[i - 1];
	}
	count_a += a.min * arr[a.hour];

	int count_b = one_day * b.day;
	for (int i = 1; i <= b.hour; i++) {
		count_b += 60 * arr[i - 1];
	}
	count_b += b.min * arr[b.hour];

	return count_b - count_a;
}

int main()
{
	int toll[24];
	for (int i = 0; i < 24; i++) {
		cin >> toll[i];
	}
	int N;
	cin >> N;
	record *table = new record[N]();
	for (int i = 0; i < N; i++) {
		cin >> table[i].name;
		scanf("%d:%d:%d:%d", &table[i].mon, &table[i].day, &table[i].hour, &table[i].min);
		cin >> table[i].status;
	}
	//cout << "before:" << endl;
	//for (int i = 0; i < N; i++) {
	//	cout << table[i].name << " " << table[i].mon << ":" << table[i].day << ":" << table[i].hour << 
	//		":" << table[i].min << " " << table[i].status << endl;
	//}
	sort(table, &table[N], comp);
	//cout << "after:" << endl;
	//for (int i = 0; i < N; i++) {
	//	cout << table[i].name << " " << setfill('0') << setw(2) << table[i].mon << ":" << setw(2) << table[i].day << ":" << setw(2) << table[i].hour << 
	//		":" << setw(2) << table[i].min << " " << table[i].status << endl;
	//}
	int on_line = 0;
	string name;
	float all_bill = 0;
	int is_new = 0;
	int out_all = 0;
	for (int i = 0; i < N; i++) {
		if (table[i].status == "on-line") {
			on_line = 1;
			if (name != table[i].name) {
				is_new = 1;
				if (out_all) {
					cout << "Total amount: $" << fixed << setprecision(2) << all_bill / 100 << endl;
					out_all = 0;
					all_bill = 0;
				}
			}
			name = table[i].name;
			continue;
		}
		else if (table[i].status == "off-line" && table[i].name == name && on_line == 1 && i > 0) {
			if (is_new) {
				cout << table[i].name << " ";
				cout << setfill('0') << setw(2) << table[i].mon << endl;
			}	
			is_new = 0;
			on_line = 0;
			int gap = sum(table[i - 1], table[i]);
			float bill = (float)count(table[i - 1], table[i], toll);
			cout << setw(2) << table[i - 1].day << ":" << setw(2) << table[i - 1].hour << ":" << setw(2) << table[i - 1].min << " "\
				<< setw(2) << table[i].day << ":" << setw(2) << table[i].hour << ":" << setw(2) << table[i].min << " "\
				<< gap << " $";
			cout << fixed << setprecision(2) << bill / 100 << endl;
			all_bill += bill;
			out_all = 1;
		}
	}
	if (out_all) {
		cout << "Total amount: $" << fixed << setprecision(2) << all_bill / 100 << endl;
	}
	return 0;
}