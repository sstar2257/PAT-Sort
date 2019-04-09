#include <iostream>
using namespace std;

bool table[1001][1001];
int N;

void row(int y) {
	for (int i = 1; i <= N; i++) {
		table[i][y] = true;
	}
}

void col(int x) {
	for (int i = 1; i <= N; i++) {
		table[x][i] = true;
	}
}

void diag(int x, int y) {
	int i, j;
	for (i = x - 1, j = y - 1; i > 0 && j > 0; i--, j--) {
		table[i][j] = true;
	}
	for (i = x + 1, j = y - 1; i <= N && j > 0; i++, j--) {
		table[i][j] = true;
	}
	for (i = x + 1, j = y + 1; i <= N && j <= N; i++, j++) {
		table[i][j] = true;
	}
	for (i = x - 1, y = j + 1; i > 0 && j <= N; i--, j++) {
		table[i][j] = true;
	}
}

void init() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			table[i][j] = false;
		}
	}
}

int main()
{
	int K;
	cin >> K;
	int input, flag;
	for (int i = 0; i < K; i++) {
		init();
		cin >> N;
		flag = 1;
		for (int j = 1; j <= N; j++) {
			cin >> input;
			if (flag) {
				if (table[j][input])
					flag = 0;
				else {
					row(input);
					//col(j);
					diag(j, input);
				}
			}
		}
		if (flag) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	return 0;
}