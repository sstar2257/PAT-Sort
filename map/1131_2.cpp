#include <iostream>
#include <cstdio>
#include <vector>
#include <string.h>
#include <map>
using namespace std;

int N, K;
vector<int> table[10000];
map<pair<int, int>, int> list;
int mark[10000];
vector<int> path;
vector<int> res;
int conjunction;
int transfers;
int start, des;

void store(int a, int b, int line) {
	if (a > b) {
		list[make_pair(b, a)] = line;
	}
	else {
		list[make_pair(a, b)] = line;
	}
}

int query(int a, int b) {
	if (a > b) {
		return list[make_pair(b, a)];
	}
	else {
		return list[make_pair(a, b)];
	}
}

int getTransf(vector<int> a) {
	int cnt = -1, preLine = 0;
	for (int i = 1; i < a.size(); i++) {
		//int tempLine = line[a[i - 1]][a[i]];
		int tempLine = query(a[i - 1], a[i]);
		if (preLine != tempLine) {
			cnt++;
			preLine = tempLine;
		}
	}
	return cnt;
}

void DFS(int sta) {

	//上下两个顺序不能换，否则被压入的des没时机输出了
	if (!mark[sta]) {
		//if (path.size() >= 2 && query(path.back(), sta) != query(path.back(), path[path.size() - 2])) {
		//	transfers++;
		//}
		path.push_back(sta);
		mark[sta] = 1;
	}
	else {
		return;
	}

	if (sta == des) {
		if (path.size() < res.size() || res.empty()) {
			res = path;
			//conjunction = transfers;
			conjunction = getTransf(path);
		}
		else if (path.size() == res.size()) {
			if (getTransf(path) < conjunction) {
				res = path;
				conjunction = getTransf(path);
			}
		}
		path.pop_back();
		mark[sta] = 0;
		return;
	}



	for (int i = 0; i < table[sta].size(); i++) {
		DFS(table[sta][i]);
	}
	int len = path.size();
	//if (len >= 3 && query(path[len - 1], path[len - 2]) != query(path[len - 2], path[len - 3])) {
	//	transfers--;
	//}
	path.pop_back();
	mark[sta] = 0;
}

int main()
{
	cin >> N;
	int num;
	int first, sta;
	for (int i = 1; i <= N; i++) {
		cin >> num >> first;
		for (int j = 1; j < num; j++) {
			cin >> sta;
			store(first, sta, i);
			table[first].push_back(sta);
			table[sta].push_back(first);
			first = sta;
		}
	}
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> start >> des;
		res.clear();
		path.clear();
		conjunction = 0;
		transfers = 0;
		memset(mark, 0, 10000 * sizeof(int));
		DFS(start);
		cout << res.size() - 1 << endl;
		//res.push_back(des);
		int line = query(res[0], res[1]);
		for (int i = 1; i + 1 < res.size(); i++) {
			if (query(res[i], res[i + 1]) == line) {
				continue;
			}
			else {
				//cout << "Take Line#" << line << " from " << start << " to " << res[i] << "." << endl;
				printf("Take Line#%d from %04d to %04d.\n", line, start, res[i]);
				start = res[i];
				line = query(res[i], res[i + 1]);
			}
		}
		//cout << "Take Line#" << line << " from " << start << " to " << des << "." << endl;
		printf("Take Line#%d from %04d to %04d.\n", line, start, des);
		//int line = 0;
		//for (int i = 1; i < res.size(); i++) {
		//	if (query(res[i], res[i - 1]) == line) {
		//		continue;
		//	}
		//	else {
		//		//cout << "Take Line#" << line << " from " << start << " to " << res[i] << "." << endl;
		//		if (line != 0) {
		//			printf("Take Line#%d from %04d to %04d.\n", line, start, res[i - 1]);
		//		}
		//		start = res[i - 1];
		//		line = query(res[i], res[i - 1]);
		//	}
		//}
		////cout << "Take Line#" << line << " from " << start << " to " << des << "." << endl;
		//printf("Take Line#%d from %04d to %04d.\n", line, start, des);
	}

	return 0;
}