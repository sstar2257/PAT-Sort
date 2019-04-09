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
	int grade[5];//K��������С�ڵ���5�����������4�Ļ����һ�����Ե�ͨ����
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
//�ύû��ͨ��������ύ�������ȫ������������������������ʱ��һ��Ҫע�⣬��������Ҫ�����,������Ե�2����ȥ
//��ⷨ�ɴ��Ż�������
//���Բ���mapתvector���޳�������Ҫ����ˣ�ֱ��sort��Ȼ�������ʱ�����жϣ������⿴���ܿ첻��
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