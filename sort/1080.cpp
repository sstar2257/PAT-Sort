#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

struct stu {
	int id;
	int ge;
	int gi;
	int same;
	int school[5];
};

stu table[40000];

int quota[100];
set<int> admission[100];
set<int> same_rank;

//comp里不能用>=这种东西
bool comp(stu a, stu b) {
	double sum_a = ((double)a.ge + a.gi) / 2;
	double sum_b = ((double)b.ge + b.gi) / 2;
	if (sum_a != sum_b)
		return sum_a > sum_b;
	else
		return a.ge > b.ge;
}

int main()
{
	int N, M, K;
	//cin >> N >> M >> K;
	scanf("%d %d %d", &N, &M, &K);


	for (int i = 0; i < M; i++) {
		//cin >> quota[i];
		scanf("%d", &quota[i]);
	}
	for (int i = 0; i < N; i++) {
		table[i].id = i;
		//cin >> table[i].ge >> table[i].gi;
		scanf("%d %d", &table[i].ge, &table[i].gi);
		for (int j = 0; j < K; j++) {
			//cin >> table[i].school[j];
			scanf("%d", &table[i].school[j]);
		}
	}
	sort(table, &table[N], comp);

	for (int i = 1; i < N; i++) {
		if (table[i].ge == table[i - 1].ge && table[i].gi == table[i - 1].gi) {
			table[i].same = 1;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			int num = table[i].school[j];
			if (!table[i].same) {
				same_rank.clear();
				//same_rank.insert(num);
			}
			else {
				if (same_rank.find(num) != same_rank.end()) {
					admission[num].insert(table[i].id);
					same_rank.insert(num);
					break;
				}
				//same_rank.insert(num);
			}

			if (admission[num].size() < quota[num]) {
				admission[num].insert(table[i].id);
				same_rank.insert(num);
				break;
			}
		}
	}

	for (int i = 0; i < M; i++) {
		int len = admission[i].size();
		if (len) {
			auto it = admission[i].begin();
			//cout << *it;
			printf("%d", *it);
			for (it++; it != admission[i].end(); it++) {
				//cout << " " << *it;
				printf(" %d", *it);
			}
		}
		//cout << endl;
		printf("\n");
	}
	return 0;
}