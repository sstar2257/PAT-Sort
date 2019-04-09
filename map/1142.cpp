#include <iostream>
#include <vector>
using namespace std;

int N, M;
bool table[201][201];
vector<int> query;
int len;

int is_clique() {
	for (int i = 0; i < len; i++) {
		for (int j = i + 1; j < len; j++) {
			if (!table[query[i]][query[j]]) {
				return 0;
			}
		}
	}
	return 1;
}

int is_max() {
	int flag;
	for (int i = 1; i <= N; i++) {
		flag = 1;
		for (int j = 0; j < len; j++) {
			if (!table[i][query[j]]) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			return 0;
		}
	}
	return 1;
}

void judge() {
	len = query.size();
	if (!is_clique()) {
		cout << "Not a Clique" << endl;
	}
	else if (!is_max()) {
		cout << "Not Maximal" << endl;
	}
	else {
		cout << "Yes" << endl;
	}
}

int main()
{
	cin >> N >> M;
	int x, y;
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		table[x][y] = table[y][x] = true;
	}
	int K;
	cin >> K;

	int num;
	for (int i = 0; i < K; i++) {
		cin >> num;
		query.clear();
		query.resize(num);
		for (int j = 0; j < num; j++) {
			cin >> query[j];
		}
		judge();
	}
	return 0;
}