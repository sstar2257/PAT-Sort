#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

int N;
double P, R;
vector<int> table[100000];
vector<int> retailer;
int level[100000];
int stock[100000];
int tail;
queue<int> que;

void BFS(int no) {
	tail = no;
	que.push(no);
	int lvl = 0;
	while (!que.empty()) {
		int front = que.front();
		que.pop();
		level[front] = lvl;
		for (int i = 0; i < table[front].size(); i++) {
			que.push(table[front][i]);
		}
		if (front == tail && !que.empty()) {
			tail = que.back();
			lvl++;
		}
	}
}

int main()
{
	scanf("%d %lf %lf", &N, &P, &R);
	int num, no;
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		if (num) {
			for (int j = 0; j < num; j++) {
				scanf("%d", &no);
				table[i].push_back(no);
			}
		}
		else {
			scanf("%d", &no);
			retailer.push_back(i);
			stock[i] = no;
		}
	}

	BFS(0);

	double sum = 0;
	for (int i = 0; i < retailer.size(); i++) {
		int index = retailer[i];
		sum += P * pow((1 + R / 100), level[index]) * stock[index];
	}
	printf("%.1lf", sum);
	return 0;
}