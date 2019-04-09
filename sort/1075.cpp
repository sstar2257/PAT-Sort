#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

struct mem {
	int rank;
	int id;
	int sum;
	int grade[5];//K的限制是小于等于5，如果这里是4的话最后一个测试点通不过
	int perfect;
};

int problem[5];

bool comp(mem a, mem b) {
	if (a.sum != b.sum)
		return a.sum > b.sum;
	else if (a.perfect != b.perfect)
		return a.perfect > b.perfect;
	else
		return a.id < b.id;
}
//提交没有通过编译和提交得零分完全是两个概念，所以在这里输出的时候一定要注意，后者是需要输出的,否则测试点2过不去
//这解法可待优化。。。
//可以不用map转vector来剔除不符合要求的人，直接sort，然后在输出时进行判断，就这题看来能快不少
int main()
{
	int N, K, M;
	scanf("%d %d %d", &N, &K, &M);
	for (int i = 0; i < K; i++) {
		scanf("%d", &problem[i]);
	}
	map<int, vector<int>> table;
	int id, num, grade;
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &id, &num, &grade);
		if (table.find(id) != table.end()) {
			if (table[id][num - 1] < grade) {
				table[id][num - 1] = grade;
			}
		}
		else {
			table[id].resize(K, -2);
			table[id][num - 1] = grade;
		}
	}
	vector<mem> res;
	for (auto it = table.begin(); it != table.end(); it++) {
		mem tmp;
		tmp.sum = 0;
		tmp.perfect = 0;
		int  flag = 0;
		for (int i = 0; i < K; i++) {
			if (it->second[i] >= 0) {
				flag = 1;
				tmp.sum += it->second[i];
				if (it->second[i] == problem[i]) {
					tmp.perfect++;
				}
			}
			tmp.grade[i] = it->second[i];
		}
		if (flag) {
			tmp.id = it->first;
			res.push_back(tmp);
		}
	}

	sort(res.begin(), res.end(), comp);
	res.begin()->rank = 1;
	int same = 1;
	for (int i = 1; i < res.size(); i++) {
		if (res[i].sum == res[i - 1].sum) {
			res[i].rank = res[i - 1].rank;
			same++;
		}
		else {
			res[i].rank = res[i - 1].rank + same;
			same = 1;
		}
	}
	for (int i = 0; i < res.size(); i++) {
		printf("%d %05d %d", res[i].rank, res[i].id, res[i].sum);
		for (int j = 0; j < K; j++) {
			if (res[i].grade[j] >= 0) {
				printf(" %d", res[i].grade[j]);
			}
			else if (res[i].grade[j] == -1) {
				printf(" 0");
			}
			else {
				printf(" -");
			}
		}
		printf("\n");
	}

	return 0;
}