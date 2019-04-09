#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

void fac(int N, int& m, int& n) {
	int tmp = sqrt(N);
	for (int i = tmp; i > 0; i--) {
		if (N%i == 0) {
			n = i;
			m = N / i;
			break;
		}
	}
}

bool comp(int a, int b) {
	return a > b;
}

int main()
{
	int N;
	scanf("%d", &N);
	int m, n;
	fac(N, m, n);
	int *list = new int[N + 1]();
	for (int i = 0; i < N; i++) {
		scanf("%d", &list[i]);
	}
	sort(list, &list[N], comp);
	int **table = new int*[m]();
	for (int i = 0; i < m; i++) {
		table[i] = new int[n]();
	}
	int x, y;
	int i = 0;
	int mode = 1;
	for (x = 0, y = 0; i < N;) {
		switch (mode)
		{
		case 1: {
			if (y < n && !table[x][y]) {
				table[x][y++] = list[i++];
				break;
			}
			else {
				y--;
				x++;
				mode++;
			}
		}
		case 2: {
			if (x < m && !table[x][y]) {
				table[x++][y] = list[i++];
				break;
			}
			else {
				x--;
				y--;
				mode++;
			}
		}
		case 3: {
			if (y >= 0 && !table[x][y]) {
				table[x][y--] = list[i++];
				break;
			}
			else {
				y++;
				x--;
				mode++;
			}
		}
		case 4: {
			if (x >= 0 && !table[x][y]) {
				table[x--][y] = list[i++];
				break;
			}
			else {
				x++;
				y++;
				mode = 1;
			}
		}
		default:break;
		}
	}

	for (int j = 0; j < m; j++) {
		printf("%d", table[j][0]);
		for (int k = 1; k < n; k++) {
			printf(" %d", table[j][k]);
		}
		printf("\n");
	}

	return 0;
}