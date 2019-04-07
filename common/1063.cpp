#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <set>
#include <vector>
using namespace std;
//用set在最后一个测试点会超时
//set的插入还是很费时间的
int main()
{
	int N, M;
	scanf("%d", &N);
	//int **table = new int*[N]();
	//int num;
	//for (int i = 0; i < N; i++) {
	//	scanf("%d", &num);
	//	table[i] = new int[num+1]();
	//	table[i][0] = num;
	//	for (int j = 1; j <= num; j++) {
	//		scanf("%d", &table[i][j]);
	//	}
	//}
	vector<set<int>> list(N);
	int num;
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		int input;
		for (int j = 0; j < num; j++) {
			scanf("%d", &input);
			list[i].insert(input);
		}
	}
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		//set<int> seta = list[a-1];
		//set<int> setb = list[b-1];
		set<int> com;
		//set<int> all;
		//int lena = table[a - 1][0];
		//int lenb = table[b - 1][0];
		//for (int i = 1; i <= lena; i++) {
		//	seta.insert(table[a - 1][i]);
		//}
		//for (int i = 1; i <= lenb; i++) {
		//	setb.insert(table[b - 1][i]);
		//}
		//for (auto it = seta.begin(); it != seta.end(); it++) {
		//	if (setb.find(*it) != setb.end()) {
		//		com.insert(*it);
		//	}
		//}
		for (auto ita = list[a-1].begin(), itb = list[b-1].begin(); ita != list[a-1].end() && itb != list[b-1].end();) {
			if (*ita == *itb) {
				com.insert(*ita);
				ita++;
				itb++;
			}
			else if (*ita > *itb) {
				itb++;
			}
			else {
				ita++;
			}
		}
		//这里不需要在做插入求并集。。。只需要求出并集的大小即可
		//all.insert(list[a-1].begin(), list[a-1].end());
		//all.insert(list[b-1].begin(), list[b-1].end());
		double com_size = com.size();
		double all_size = list[a - 1].size() + list[b - 1].size() - com_size;
		printf("%.1lf%%\n", com_size / all_size * 100);
	}
	return 0;
}