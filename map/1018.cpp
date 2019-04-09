#include <iostream>
using namespace std;
//三个优先级判断点：题目正文中要求第一优先级为最短路径，第二优先级为派出自行车最少，而在结果输出中有第三优先级，即收回自行车最少。遗漏后两个优先级会导致有的点通不过；
//在统计派出数和收回数时，要注意一个站点中多出来的自行车只能向后面的站点补充，而不能向前面的站点补充，这也是很容易忽视的问题。
//题目意思没理解清楚。。。Dijkstra算法不行
int main()
{
	int C, N, Sp, M;
	cin >> C >> N >> Sp >> M;
	//N是站台的数量，不包括总部，所以N+1
	const int inf = 0x3F3F3F3F;
	int *capa = new int[N+1]();
	for (int i = 1; i <= N; i++) {
		cin >> capa[i];
	}
	int **path = new int *[N+1]();
	for (int i = 0; i <= N; i++) {
		path[i] = new int[N+1]();
	}

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			path[i][j] = inf;
		}
	}

	int x, y, val;
	for (int i = 0; i < M; i++) {
		cin >> x >> y >> val;
		path[x][y] = path[y][x] = val;
		//cout << "path[" << x << "][" << y << "] : " << path[x][y] << endl;
	}
	int *dis = new int[N+1]();
	int *visited = new int[N+1]();
	
	//记录前驱节点
	int *prev = new int[N + 1]();
	for (int i = 0; i <= N; i++) {
		dis[i] = path[0][i];
		if (dis[i] == inf) {
			prev[i] = -1;//表示没有前驱节点
		}
		else {
			prev[i] = 0;//否则以0作为前驱节点
		}
	}
	dis[0] = 0;
	visited[0] = 1;
	
	int min;
	int u;
	int collect = 0;

	for (int i = 0; i <= N; i++) {
		min = inf;
		u = -1;
		for (int j = 1; j <= N; j++) {
			if (dis[j] < min && !visited[j]) {
				min = dis[j];
				u = j;
			}
		}
		if (u == -1) {
			break;
		}
		visited[u] = 1;
		for (int j = 1; j <= N; j++) {
			if (!visited[j] && path[u][j] != inf) {
				if (dis[j] > dis[u] + path[u][j]) {
					dis[j] = dis[u] + path[u][j];
					prev[j] = u;
					if (j == Sp && capa[u] > C / 2) {
						collect += capa[u] - C / 2;
					}
				}
				else if (dis[j] == dis[u] + path[u][j]) {
					if (capa[u] > capa[prev[j]] && capa[u] > C / 2) { 
						collect += capa[u] - capa[prev[j]];
						prev[j] = u;
					}
				}
			}
		}
	}	
	//for (int i = 0; i <= N; i++) {
	//	cout << prev[i] << endl;
	//}

	int tmp = prev[Sp];
	int *shortest_path = new int[N]();
	shortest_path[0] = Sp;
	int index = 1;
	while (tmp != 0) {
		shortest_path[index] = tmp;
		tmp = prev[tmp];
		index++;
	}

	int requied = C / 2 - capa[Sp];
	if (requied <= 0) {
		cout << "0 ";
	}
	else if (requied > 0) {
		if (collect >= requied) {
			cout << "0 ";
		}
		else {
			cout << requied - collect << " ";
		}
	}

	cout << "0->";
	for (int i = index - 1; i >= 0; i--) {
		cout << shortest_path[i];
		if (i != 0) {
			cout << "->";
		}
	}
	cout << " ";

	if (requied <= 0) {
		cout << -requied;
	}
	else {
		cout << "0";
	}

	return 0;
}