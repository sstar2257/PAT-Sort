#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

vector<int> danger[100000];
//map<int, vector<int>> danger;
int mark[100000];

//可能有多种物品相互不兼容。。。
//不是说不兼容的物品都是一对一对的
int main()
{
	int N, K;
	cin >> N >> K;
	int a, b;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		danger[a].push_back(b);
		danger[b].push_back(a);
	}
	int num;
	int is_safe;
	for (int i = 0; i < K; i++) {
		cin >> num;
		is_safe = 1;
		memset(mark, 0, 100000*sizeof(int));
		for (int j = 0; j < num; j++) {
			cin >> a;
			if (is_safe) {
				if (danger[a].empty()) {
					continue;
				}
				else if(!mark[a]){
					for (int k = 0; k < danger[a].size(); k++) {
						mark[danger[a][k]] = 1;
					}
				}
				else {
					is_safe = 0;
				}
			}
		}
		if (is_safe) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
	return 0;
}