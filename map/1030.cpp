#include <iostream>
using namespace std;
//注意给定了起点和终点，起点不一定是0
int main()
{
	const int inf = 0x3F3F3F3F;
	int N, M, S, D;
	cin >> N >> M >> S >> D;
	int **dis = new int*[N]();
	int **cost = new int*[N]();
	for (int i = 0; i < N; i++) {
		dis[i] = new int[N]();
		cost[i] = new int[N]();
	}
	//初始化邻接矩阵
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			dis[i][j] = cost[i][j] = inf;
		}
	}
	//邻接矩阵赋值
	int x, y;
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		cin >> dis[x][y] >> cost[x][y];
		dis[y][x] = dis[x][y];
		cost[y][x] = cost[x][y];
	}
	//初始化标记数组
	int *visit = new int[N]();
	int *shortest = new int[N]();
	int *least = new int[N]();
	for (int i = 0; i < N; i++) {
		shortest[i] = dis[S][i];
		least[i] = cost[S][i];
	}

	visit[S] = 1;
	least[S] = 0;
	int *prev = new int[N]();

	//前置节点需要被初始化为起始点
	for (int i = 0; i < N; i++) {
		prev[i] = S;
	}
	int min;
	int u;
	for (int i = 0; i < N; i++) {
		min = inf;
		u = -1;
		for (int j = 0; j < N; j++) {
			if (shortest[j] < min && !visit[j]) {
				min = shortest[j];
				u = j;
			}
		}
		if (u == -1) {
			break;
		}
		visit[u] = 1;
		for (int j = 0; j < N; j++) {
			if (!visit[j] && dis[u][j] != inf) {
				if (shortest[j] > shortest[u] + dis[u][j]) {
					shortest[j] = shortest[u] + dis[u][j];
					prev[j] = u;
					least[j] = least[u] + cost[u][j];
				}
				else if (shortest[j] == shortest[u] + dis[u][j]) {
					if (least[j] > least[u] + cost[u][j]) {
						prev[j] = u;
						least[j] = least[u] + cost[u][j];
					}
					/*if (cost[u][j] < cost[prev[j]][j]) {
						prev[j] = u;
					}*///这样子判断是有问题的，不能用这种方法做判断
				}
			}	
		}
	}

	int tmp = prev[D];
	int *path = new int[N]();
	path[0] = D;
	int index = 1;
	while (tmp != S) {
		path[index] = tmp;
		tmp = prev[tmp];
		index++;
	}
	cout << S << " ";
	for (int i = index - 1; i >= 0; i--) {
		cout << path[i] << " ";
	}
	cout << shortest[D] << " " << least[D] << endl;
	return 0;
}