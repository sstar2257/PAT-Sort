#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

int N;
double P, R;
vector<int> table[100000];
vector<int> same_lvl;
int tail;
int lvl;
queue<int> que;

void BFS(int no) {
	tail = no;
	que.push(no);
	while (!que.empty()) {
		int front = que.front();
		same_lvl.push_back(front);
		que.pop();
		for (int i = 0; i < table[front].size(); i++) {
			que.push(table[front][i]);
		}
		if (front == tail && !que.empty()) {
			tail = que.back();
			lvl++;
			same_lvl.clear();
		}
	}
}

int main()
{
	scanf("%d %lf %lf", &N, &P, &R);
	int index;
	int root;
	for (int i = 0; i < N; i++) {
		scanf("%d", &index);
		if (index != -1) {
			table[index].push_back(i);
		}
		else {
			root = i;
		}
	}

	BFS(root);
	double price = P * pow((1 + R / 100), lvl);
	printf("%.2lf %d", price, same_lvl.size());
	return 0;
}