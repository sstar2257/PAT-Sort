#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct stu {
	string name;
	int gp;
	int gm;
	int gf;
	int g;
};

vector<stu> table;
map<string, int> mapping;

bool comp(stu a, stu b) {
	if (a.g != b.g)
		return a.g > b.g;
	else
		return a.name < b.name;
}
//使用map的时候，如果string作为key，那么在输入的时候要特别注意
//最好先将字符串输入到数组里，再转换为唯一的string，而使用resize这种，map映射常出错
//和string中的空余位置有关
int main()
{
	int P, M, N;
	scanf("%d %d %d", &P, &M, &N);
	char id[21];
	int grade;
	int index = 0;
	for (int i = 0; i < P; i++) {
		scanf("%s %d", id, &grade);
		string name(id);
		if (grade >= 200) {
			stu tmp = { name, grade,-1,-1,-1 };
			table.push_back(tmp);
			mapping[name] = index;
			index++;
		}
	}

	for (int i = 0; i < M; i++) {
		scanf("%s %d", id, &grade);
		string name(id);
		if (mapping.find(name) != mapping.end()) {
			table[mapping[name]].gm = grade;
		}
	}

	for (int i = 0; i < N; i++) {
		scanf("%s %d", id, &grade);
		string name(id);
		if (mapping.find(name) != mapping.end()) {
			table[mapping[name]].gf = grade;
		}
	}

	for (int i = 0; i < table.size(); i++) {
		if (table[i].gf < table[i].gm) {
			table[i].g = (double)table[i].gf * 0.6 + (double)table[i].gm * 0.4 + 0.5;
		}
		else {
			table[i].g = table[i].gf;
		}
	}

	sort(table.begin(), table.end(), comp);

	for (int i = 0; i < table.size(); i++) {
		if (table[i].g >= 60) {
			printf("%s %d %d %d %d\n", table[i].name.c_str(), table[i].gp, table[i].gm, table[i].gf, table[i].g);
		}
		else {
			break;
		}
	}
	return 0;
}
