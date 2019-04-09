#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int N, M;
vector<int> table[1001];
bool mark[1001];

int main()
{
	cin >> N >> M;
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		table[b].push_back(a);
	}
	int K, num;
	int flag = 0;
	cin >> K;
	for (int i = 0; i < K; i++) {
		memset(mark, false, 1001 * sizeof(bool));
		int j;
		for (j = 0; j < N; j++) {
			cin >> num;
			if (!mark[num]) {
				for (int k = 0; k < table[num].size(); k++) {
					mark[table[num][k]] = true;
				}
			}
			else {
				break;
			}
		}
		if (j != N) {
			if (flag) {
				cout << " ";
			}
			flag = 1;
			cout << i;
			while (j + 1 < N) {//j被break出来之后，少加了一个1
				cin >> num;
				j++;
			}
		}
	}
	return 0;
}