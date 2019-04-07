#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
int main()
{
	int M, N;
	cin >> M >> N;
	map<int, int> table;
	int color;
	int max = -1;
	table[-1] = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &color);
			if (table.find(color) != table.end()) {
				table[color]++;

			}
			else {
				table[color] = 1;
			}
			if (table[color] > table[max]) {
				max = color;
			}
		}
	}
	cout << max;
	return 0;
}