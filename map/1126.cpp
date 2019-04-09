#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> table[501];
queue<int> que;
int num;
int mark[501];

void BFS(int no) {
	que.push(no);
	mark[no] = 1;
	num++;
	while (!que.empty()) {
		int front = que.front();
		que.pop();
		int len = table[front].size();
		if (len != 0) {
			for (int i = 0; i < len; i++) {
				if (!mark[table[front][i]]) {
					mark[table[front][i]] = 1;
					que.push(table[front][i]);
					num++;
				}
			}
		}
	}
}
//1.要判断联通性，不然有一个5分的点过不去
//2.对table[1]的度不要忘了判断。。。不然测试点5过不去
int main()
{
	int N, M;
	cin >> N >> M;
	int x, y;
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		table[x].push_back(y);
		table[y].push_back(x);
	}
	cout << table[1].size();
	int odd;
	if (table[1].size() % 2 != 0) {
		odd = 1;
	}
	else {
		odd = 0;
	}
	for (int i = 2; i <= N; i++) {
		if (table[i].size() % 2 != 0) {
			odd++;
		}
		cout << " " << table[i].size();
	}
	cout << endl;
	BFS(1);
	if (num != N) {
		cout << "Non-Eulerian" << endl;
	}
	else {
		if (!odd) {
			cout << "Eulerian" << endl;
		}
		else if (odd == 2) {
			cout << "Semi-Eulerian" << endl;
		}
		else {
			cout << "Non-Eulerian" << endl;
		}
	}
	return 0;
}