#include <iostream>
#include <vector>
using namespace std;

//我这里用了一个二维数组，采用下面的结构会好一点
//struct Node {
//	int weight;
//	vector<int>son;
//}
int table[100][100];
int w[100];
int visited[100];
int non_leaf[100];
vector<int> path;
int len;
int N, M, S;

void DFS(int root) {
	path.push_back(root);
	visited[root] = 1;
	len += w[root];
	if (len > S)
		return;
	else if (len == S) {
		if (non_leaf[root]) {
			return;
		}
		else {
			for (int i = 0; i < path.size(); i++) {
				cout << w[path[i]];
				if (i == path.size() - 1) {
					cout << endl;
				}
				else {
					cout << " ";
				}
			}
			return;
		}
	}
	else {
		if (!non_leaf[root]) {
			return;
		}
	}
	//find the max not found
	while (1) {
		int max = 0;
		int index = -1;
		for (int i = 0; i < N; i++) {
			if (table[root][i] && !visited[i] && w[i] > max) {
				max = w[i];
				index = i;
			}
		}
		if (index == -1) {
			//path.pop_back();
			//len -= w[root];
			break;
		}
		DFS(index);
		path.pop_back();
		len -= w[index];
	}
	return;
}


int main()
{
	cin >> N >> M >> S;
	for (int i = 0; i < N; i++) {
		cin >> w[i];
	}

	for (int i = 0; i < M; i++) {
		int root, num, child;
		cin >> root >> num;
		non_leaf[root] = 1;
		for (int j = 0; j < num; j++) {
			cin >> child;
			table[root][child] = 1;
		}
	}

	DFS(0);

	return 0;
}