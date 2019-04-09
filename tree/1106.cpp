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
int tail;
int lvl;
queue<int> que;

void BFS(int no) {
	tail = no;
	que.push(no);
	while (!que.empty()) {
		int front = que.front();
		que.pop();
		if (!table[front].size()) {
			retailer.push_back(front);
		}
		else {
			for (int i = 0; i < table[front].size(); i++) {
				que.push(table[front][i]);
			}
		}
		if (front == tail && !que.empty()) {
			if (retailer.size()) {
				break;
			}
			tail = que.back();
			lvl++;
		}
	}
}

int main()
{
	scanf("%d %lf %lf", &N, &P, &R);
	int num, id;
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		for (int j = 0; j < num; j++) {
			scanf("%d", &id);
			table[i].push_back(id);
		}
	}

	BFS(0);
	double price = P * pow((1 + R / 100), lvl);
	printf("%.4lf %d", price, retailer.size());
	return 0;
}