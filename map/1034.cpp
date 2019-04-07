#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

struct mem {
	string head;
	int num;
};

bool comp(mem a, mem b) {
	return a.head < b.head;
}

int main()
{
	int N, K;
	cin >> N >> K;
	vector<set<string>> table;
	map<string, int> w;
	for (int i = 0; i < N; i++) {
		string a, b;
		int time;
		vector<int> pos;
		cin >> a >> b >> time;
		if (table.empty()) {
			set<string> gang;
			gang.insert(a);
			gang.insert(b);
			table.push_back(gang);
		}
		else {
			for (int j = 0; j < table.size(); j++) {
				//这里有问题，如果给出的通话记录是A-B,C-D,D-A...结果就不正确...所以还是得用正统的连通分量来做
				if (table[j].find(a) != table[j].end()) {
					table[j].insert(b);
					pos.push_back(j);
					//continue;
				}
				else if (table[j].find(b) != table[j].end()) {
					table[j].insert(a);
					pos.push_back(j);
					//continue;
				}
				//增加了一个合并set的工作
				if (j == table.size() - 1) {
					if (pos.empty()) {
						set<string> gang;
						gang.insert(a);
						gang.insert(b);
						table.push_back(gang);
						break;
					}
					else if (pos.size() == 2) {
						int x = pos[0];
						int y = pos[1];
						table[x].insert(table[y].begin(), table[y].end());
						table.erase(table.begin() + y);
						break;
					}
				}
			}
		}
		if (w.find(a) != w.end()) {
			w[a] += time;
		}
		else {
			w[a] = time;
		}
		if (w.find(b) != w.end()) {
			w[b] += time;
		}
		else {
			w[b] = time;
		}
	}

	int num = 0;
	vector<mem> res;
	for (int i = 0; i < table.size(); i++) {
		int total_time = 0;
		mem tmp;
		int max = 0;
		if (table[i].size() > 2) {
			for (auto j = table[i].begin(); j != table[i].end(); j++) {
				total_time += w[*j];
				if (w[*j] > max) {
					max = w[*j];
					tmp.head = *j;
				}
			}
			if (total_time / 2 > K) {
				tmp.num = table[i].size();
				res.push_back(tmp);
				num++;
			}
		}
	}

	sort(res.begin(), res.end(), comp);
	cout << num << endl;
	for (int i = 0; i < num; i++) {
		cout << res[i].head << " " << res[i].num << endl;
	}
	return 0;
}