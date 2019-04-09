#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> table[10000];
int color[10000];
int N, M;
set<int> coloring;

int main()
{
	cin >> N >> M;
	int x, y;
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		table[x].push_back(y);
	}
	int K;
	cin >> K;
	int flag;
	for (int i = 0; i < K; i++) {
		flag = 1;
		coloring.clear();
		for (int j = 0; j < N; j++) {
			cin >> color[j];
			coloring.insert(color[j]);
		}
		for (int j = 0; j < N; j++) {
			if (!table[j].empty()) {
				for (int k = 0; k < table[j].size(); k++) {
					if (color[j] == color[table[j][k]]) {
						flag = 0;
						break;
					}
				}
				if (!flag) {
					break;
				}
			}
		}
		if (!flag) {
			cout << "No" << endl;
		}
		else {
			cout << coloring.size() << "-coloring" << endl;
		}
	}

	return 0;
}