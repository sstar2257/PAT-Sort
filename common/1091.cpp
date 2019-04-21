#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

struct co {
	int x;
	int y;
	int z;
};

//用bool和int速度差很多。。。用int数组的话最后两个测试点过不去
int M, N, L, T;
bool v[60][1286][128];
bool mark[60][1286][128];
queue<co> que;
int region;
int all;

void test(int x, int y, int z) {
	if (!mark[x][y][z]) {
		mark[x][y][z] = true;
		if (v[x][y][z]) {
			que.push({ x,y,z });
			region++;
		}
	}
}

void BFS(int i, int j, int k) {
	region = 1;
	que.push({ i,j,k });
	mark[i][j][k] = true;
	while (!que.empty()) {
		co front = que.front();
		que.pop();
		int x = front.x;
		int y = front.y;
		int z = front.z;
		if (x - 1 >= 0) { test(x - 1, y, z); }
		if (y - 1 >= 0) { test(x, y - 1, z); }
		if (z - 1 >= 0) { test(x, y, z - 1); }
		if (x + 1 < L) { test(x + 1, y, z); }
		if (y + 1 < M) { test(x, y + 1, z); }
		if (z + 1 < N) { test(x, y, z + 1); }
	}
}

//三维空间上的广度优先搜索
int main()
{
	cin >> M >> N >> L >> T;
	for (int i = 0; i < L; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < N; k++) {
				scanf("%d", &v[i][j][k]);
			}
		}
	}

	for (int i = 0; i < L; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < N; k++) {
				if (!mark[i][j][k] && v[i][j][k]) {
					BFS(i, j, k);
					if (region >= T) {
						all += region;
					}
				}
			}
		}
	}
	cout << all;
	return 0;
}