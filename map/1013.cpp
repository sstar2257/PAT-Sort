#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
int main()
{
	int N,M,K;
	cin >> N >> M >> K;
	//int (*p)[N] = new int[N][N]();
	int **p = new int *[N]();
	for (int i = 0; i < N; i++) {
		p[i] = new int[N]();
	}
	int *visit = new int[N]();
	int c1,c2;
	for(int i=0;i<M;i++){
		cin >> c1 >> c2;
		p[c1 - 1][c2 - 1] = p[c2 - 1][c1 - 1] = 1;
	}
	int c3, count;
	queue<int> myque;
	for(int j=0;j<K;j++){
		memset(visit, 0, N*sizeof(int));
		count = -1;
		cin >> c3;
		visit[c3-1] = -1;
		for(int i=1;i<=N;i++){
			if(!visit[i-1] && i!=c3){
				myque.push(i);
				visit[i-1] = 1;
				while(!myque.empty()){
					int c4 = myque.front();
					myque.pop();
					for(int k=1;k<=N;k++){
						if(!visit[k-1] && p[c4-1][k-1]){
							myque.push(k);
							visit[k - 1] = 1;
						}
					}
				}
				count++;
			}
		}
		cout << count << endl;
	}
	return 0;
}