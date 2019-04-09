//这份代码写的太好啦啦啦啦
#include<iostream>
#include<vector>
using namespace std;
#define MAX 505
#define INF 10000

int cap, N, sp, M;
int vex;
int dist[MAX][MAX];
int bike[MAX];
#define PF cap/2

vector<int> curpath;
vector<int> shortpath;
int minsend = INF, minback = INF;
int minlen = INF;
int cursend = 0, curback = 0;
int curlen = 0;
bool visit[MAX] = { 0 };

void dfs(int cur) {
	if (curlen>minlen)
		return;
	if (cur == sp) {
		//到达目标点，看是否最优 
		if (curlen<minlen) {
			minlen = curlen;
			minsend = cursend;
			minback = curback;
			shortpath = curpath;
		}
		else if (curlen == minlen) {
			if (cursend<minsend || (cursend == minsend&&curback<minback)) {
				minsend = cursend;
				minback = curback;
				shortpath = curpath;
			}
		}
		return;
	}
	for (int i = 1; i<vex; i++) {
		if (visit[i] == true || dist[cur][i] == INF)
			continue;
		int lastsend = cursend;
		int lastback = curback;
		//计算到达当前点的send和back数 
		if (bike[i] + curback<PF) {
			cursend += PF - bike[i] - curback;
			curback = 0;
		}
		else {
			curback = bike[i] + curback - PF;
		}
		visit[i] = true;
		curpath.push_back(i);
		curlen += dist[cur][i];
		dfs(i);
		curpath.pop_back();//回溯
		visit[i] = false;
		curlen -= dist[cur][i];
		cursend = lastsend;
		curback = lastback;
	}
}
int main() {
	cin >> cap >> N >> sp >> M;
	//初始化,距离置为INF 
	vex = N + 1;
	for (int i = 0; i<vex; i++) {
		for (int j = 0; j<vex; j++) {
			dist[i][j] = dist[j][i] = INF;
		}
	}

	for (int i = 1; i<vex; i++) {
		cin >> bike[i];
	}
	for (int k = 0; k<M; k++) {
		int i, j;
		cin >> i >> j;
		cin >> dist[i][j];
		dist[j][i] = dist[i][j];
	}

	dfs(0);

	printf("%d 0", minsend);
	for (int i = 0; i<shortpath.size(); i++) {
		printf("->%d", shortpath[i]);
	}
	printf(" %d", minback);
	return 0;
}
