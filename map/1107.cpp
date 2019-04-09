#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<int> table[2001];
vector<int> res;
int mark[2001];
queue<int> que;
int people;

void BFS(int no) {
	que.push(no);
	mark[no] = 1;
	while (!que.empty()) {
		int tmp = que.front();
		if (tmp > 1000) {
			people++;
		}
		que.pop();
		for (int i = 0; i < table[tmp].size(); i++) {
			int id = table[tmp][i];
			if (!mark[id]) {
				que.push(id);
				mark[id] = 1;
			}
		}
	}
	if (people > 0) {
		res.push_back(people);
		people = 0;
	}
}

int main()
{
	int N;
	cin >> N;
	int num, no;
	for (int i = 1; i <= N; i++) {
		cin >> num;
		cin.get();
		for (int j = 0; j < num; j++) {
			cin >> no;
			table[i + 1000].push_back(no);
			table[no].push_back(i + 1000);
		}
	}
	for (int i = 1; i <= N + 1000; i++) {
		if (!mark[i]) {
			BFS(i);
		}
	}
	sort(res.begin(), res.end());
	cout << res.size() << endl;
	for (int i = res.size() - 1; i >= 0; i--) {
		cout << res[i];
		if (i != 0) {
			cout << " ";
		}
	}
	return 0;
}