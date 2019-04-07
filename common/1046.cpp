#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int N;
	cin >> N;
	//存储各地到编号1的距离
	int *table = new int[N]();
	table[0] = 0;
	int sum = 0;
	int input;
	for (int i = 1; i < N; i++) {
		cin >> input;
		sum += input;
		table[i] = sum;
	}
	cin >> input;
	sum += input;
	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int x, y, gap;
		cin >> x >> y;
		gap = table[x-1] - table[y-1];
		gap = gap > 0 ? gap : -gap;
		if (gap >= sum / 2) {
			gap = sum - gap;
		}
		cout << gap << endl;
	}

	return 0;
}