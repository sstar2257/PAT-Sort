#include <iostream>
using namespace std;

int max(int a, int b) {
	return a >= b ? a : b;
}

int main()
{
	int N;
	cin >> N;
	int M;
	cin >> M;
	int *fav = new int[M];
	for (int i = 0; i < M; i++) {
		cin >> fav[i];
	}
	int **table = new int*[M]();
	int L;
	cin >> L;
	int *piece = new int[L]();
	for (int i = 0; i < M; i++) {
		table[i] = new int[L]();
	}
	for (int i = 0; i < L; i++) {
		cin >> piece[i];
	}

	//填充第一行第一列
	int num = 0;
	for (int i = 0; i < L; i++) {
		if (piece[i] == fav[0]) {
			table[0][i] = ++num;
		}
		else {
			table[0][i] = num;
		}
	}
	for (int i = 1; i < M; i++) {
		if (piece[i] == fav[0]) {
			table[i][0] = table[i - 1][0] + 1;
		}
		else {
			table[i][0] = table[i - 1][0];
		}
	}

	for (int i = 1; i < M; i++) {
		for (int j = 1; j < L; j++) {
			if (fav[i] == piece[j]) {
				//table[i - 1][j]表示不取当前这个喜欢颜色时，j处能取到的最大值
				//table[i][j - 1])表示前面取了这个喜欢的颜色，j处能达到的最大值
				//table其实不记录具体所取的状态
				table[i][j] = max(table[i - 1][j], table[i][j - 1]) + 1;
			}
			else {
				table[i][j] = max(table[i - 1][j], table[i][j - 1]);
			}
		}
	}
	cout << table[M - 1][L - 1];
	return 0;
}