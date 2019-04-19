#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct mem {
	int id;
	int vir;
	int tal;
};

int low, high;

bool judge_grade(mem a, mem b) {
	int sum_a = a.vir + a.tal;
	int sum_b = b.vir + b.tal;
	if (sum_a != sum_b) {
		return sum_a > sum_b;
	}
	else if (a.vir != b.vir) {
		return a.vir > b.vir;
	}
	else {
		return a.id < b.id;
	}
}

bool comp(mem a, mem b) {
	if (a.vir >= high && a.tal >= high) {
		if (b.vir >= high && b.tal >= high) {
			return judge_grade(a, b);
		}
		else {
			return true;
		}
	}
	else if (a.vir >= high && a.tal < high) {
		if (b.vir >= high) {
			if (b.tal >= high) {
				return false;
			}
			else {
				return judge_grade(a, b);
			}
		}
		else {
			return true;
		}
	}
	else if (a.vir < high && a.vir >= a.tal) {
		if (b.vir >= high) {
			return false;
		}
		else if (b.vir >= b.tal) {
			return judge_grade(a, b);
		}
		else {
			return true;
		}
	}
	else {
		if (b.vir < high && b.vir < b.tal) {
			return judge_grade(a, b);
		}
		else {
			return false;
		}
	}
}

int main()
{
	int N;
	cin >> N >> low >> high;
	vector<mem> list;
	mem input;
	for (int i = 0; i < N; i++) {
		//cin >> input.id >> input.vir >> input.tal;
		scanf("%d %d %d", &input.id, &input.vir, &input.tal);
		if (input.vir >= low && input.tal >= low) {
			list.push_back(input);
		}
	}
	sort(list.begin(), list.end(), comp);

	int len = list.size();
	cout << len << endl;
	for (int i = 0; i < len; i++) {
		//cout << list[i].id << " " << list[i].vir << " " << list[i].tal << endl;
		printf("%08d %d %d\n", list[i].id, list[i].vir, list[i].tal);
	}
	return 0;
}