//important and difficult!!!
#include <iostream>
using namespace std;

int main()
{
	const int inf = 0x3F3F3F3F;
	int N,M,C1,C2;
	cin >> N >> M >> C1 >> C2;
	//权重
	int *weight = new int[N]();
	//救援队数目之和
	int *w = new int[N]();
	//最短路径的条数
	int *num = new int[N]();
	//wrong
	//int (*e)[N] = new int[N][N]();
	int **e = new int*[N];
	for(int i=0;i<N;i++){
		e[i] = new int[N]();
	}
	int x,y,z;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			e[i][j] = inf;
		}
	}
	for(int i=0;i<N;i++){
		e[i][i] = 0;
	}
	for(int i=0;i<N;i++){
		cin >> weight[i];
	}
	for(int i=0;i<M;i++){
		cin >> x >> y >> z;
		//双向！！！
		e[x][y] = e[y][x] = z;
	}

	w[C1] = weight[C1];
	num[C1] = 1;
	int *dis = new int[N]();
	int *mark = new int[N]();

	for(int i=0;i<N;i++){
		dis[i] = e[C1][i];
	}

	//dijkstra 
	int min;
	int u;

	for(int i=0;i<N;i++){
		min = inf;
		u = -1;
		//find the cloest u
		for(int j=0;j<N;j++){
			if(dis[j]<min && mark[j]!=1){
				min = dis[j];
				u = j;
			}
		}
		if(u == -1)break;
		//set mark to 1
		mark[u] = 1;

		for(int v=0;v<N;v++){
			if(mark[v]!=1 && e[u][v]!=inf){
				if(dis[v]>dis[u]+e[u][v]){
					dis[v] = dis[u]+e[u][v];
					num[v] = num[u];
					w[v] = w[u] + weight[v];
				}
				else if(dis[v] == dis[u]+e[u][v]){
					num[v] = num[v] + num[u];
					if(w[u] + weight[v] > w[v])
						w[v] = w[u] + weight[v];
				}//重点在于第一次循环时，对基础信息的赋值，因此前面mark[C1]不能直接赋1
			}
		}
	}

	cout << num[C2] << " " << w[C2];
	return 0;
}