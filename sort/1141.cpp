#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct institution {
	string school;
	double TWS;
	int NS;
};

void tolowercase(string &str) {
	int len = str.length();
	for (int i = 0; i < len; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] += 32;
		}
	}
}

vector<institution> table;
map<string, int> mapping;

bool comp(institution a, institution b) {
	if (a.TWS != b.TWS)
		return a.TWS > b.TWS;
	else if (a.NS != b.NS)
		return a.NS < b.NS;
	else
		return a.school < b.school;
}

int main()
{
	int N;
	cin >> N;
	string id, school;
	double score;
	int index = 0;
	for (int i = 0; i < N; i++) {
		cin >> id >> score >> school;
		tolowercase(school);
		if (id[0] == 'T') {
			score *= 1.5;
		}
		else if (id[0] == 'B') {
			score /= 1.5;
		}
		if (mapping.find(school) != mapping.end()) {
			table[mapping[school]].TWS += score;
			table[mapping[school]].NS++;
		}
		else {
			mapping[school] = index++;
			institution tmp = { school,score,1 };
			table.push_back(tmp);
		}
	}
	for (int i = 0; i < table.size(); i++) {
		table[i].TWS = (int)table[i].TWS;
	}

	sort(table.begin(), table.end(), comp);
	int rank = 1, same = 1;
	cout << table.size() << endl;
	printf("%d %s %d %d\n", rank, table[0].school.c_str(), (int)table[0].TWS, table[0].NS);
	for (int i = 1; i < table.size(); i++) {
		if (table[i].TWS != table[i-1].TWS) {
			rank += same;
			same = 1;
			printf("%d %s %d %d\n", rank, table[i].school.c_str(), (int)table[i].TWS, table[i].NS);
		}
		else {
			same++;
			printf("%d %s %d %d\n", rank, table[i].school.c_str(), (int)table[i].TWS, table[i].NS);
		}
	}
	return 0;
}