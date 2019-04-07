#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int table[1001];
vector<int> lv[20];

//把输出和函数分开
void putnode(int begin, int end, int lvl) {
	if (begin == end) { 
		lv[lvl].push_back(table[begin]);
		return; 
	}
	else if (begin > end) {
		return;
	}
	int len = end - begin + 1;
	int num = 1;
	while (num * 2 - 1 <= len) {
		num *= 2;
	}
	num -= 1;
	int rest = len - num;
	int index;
	if (rest <= (num + 1) / 2) {
		index = (num - 1) / 2 + rest + begin;
	}
	else {
		index = (num - 1) / 2 + (num + 1) / 2 + begin;
	}
	lv[lvl].push_back(table[index]);
	putnode(begin, index - 1, lvl + 1);
	putnode(index + 1, end, lvl + 1);
}

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> table[i];
	}
	sort(table, &table[N]);

	putnode(0, N-1, 0);
	printf("%d", lv[0][0]);
	for (int i = 1; i < 20; ++i) {
		for (int j = 0; j < lv[i].size(); ++j) {
			printf(" %d", lv[i][j]);
		}
	}
	return 0;
}