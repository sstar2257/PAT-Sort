#include <iostream>
using namespace std;

int N;
int said[101];

//assume x and y are wolves
//test if only one human being lies and one wolf lies
int judge(int x, int y) {
	int liar = 0;
	//x lies
	if (said[x] > 0 && said[x] == y) {
		liar++;
	}
	if (said[x] < 0 && -said[x] != y) {
		liar++;
	}
	if (said[y] > 0 && said[y] == x) {
		liar++;
	}
	if (said[y] < 0 && -said[y] != x) {
		liar++;
	}
	if (liar != 1) {
		return 0;
	}
	for (int i = 1; i <= N; i++) {
		if (i == x || i == y) {
			continue;
		}
		else {
			if (said[i] > 0) {
				if (said[i] != x && said[i] != y)
					continue;
				else
					liar++;
			}
			else if(-said[i] != x && -said[i] != y)
				liar++;
		}
		if (liar > 2) {
			return 0;
		}
	}
	return 1;
}

//暴力穷举
int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> said[i];
	}
	int flag = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			if (judge(i, j)) {
				flag = 1;
				cout << i << " " << j;
				break;
			}
		}
		if (flag) {
			break;
		}
	}
	if (!flag) {
		cout << "No Solution";
	}
	return 0;
}