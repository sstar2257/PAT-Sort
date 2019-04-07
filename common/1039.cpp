#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <string>
using namespace std;
int main()
{
	int N, K;
	cin >> N >> K;
	map<string, set<int>> table;
	string name;
	name.resize(4);
	for (int i = 0; i < K; i++) {
		int no, num;
		//cin >> no >> num;
		scanf("%d %d", &no, &num);
		for (int j = 0; j < num; j++) {
			//cin >> name;
			scanf("%s", &name[0]);
			table[name].insert(no);
		}
	}

	for (int i = 0; i < N; i++) {
		//cin >> name;
		scanf("%s", &name[0]);
		int len = table[name].size();
		//cout << name << " " << len;
		printf("%s %d", name.c_str(), len);
		if (len) {
			for (auto it = table[name].begin(); it != table[name].end(); it++) {
				//cout << " " << *it;
				printf(" %d", *it);
			}
		}
		//cout << endl;
		printf("\n");
	}
	return 0;
}