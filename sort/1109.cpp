#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct people {
	string name;
	int height;
};

people list[10000];

bool comp(people a, people b) {
	if (a.height != b.height) {
		return a.height > b.height;
	}
	else {
		return a.name < b.name;
	}
}

void sort_people(int begin, int len) {
	vector<string> que;
	que.resize(len);
	int center = len / 2;
	que[center] = list[begin++].name;
	int flag = 1;
	int tmp = 1;
	for (int i = center - 1, j = center + 1; ;) {
		//判断位置要提前，防止len =1 的时候出现段错误
		if (tmp == len) {
			break;
		}
		if (flag) {
			que[i--] = list[begin++].name;
			flag = 0;
		}
		else {
			que[j++] = list[begin++].name;
			flag = 1;
		}
		tmp++;
	}
	for (int i = 0; i < len; i++) {
		if (i) {
			cout << " ";
		}
		cout << que[i];
	}
	cout << endl;
}

int main()
{
	int N, K;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> list[i].name >> list[i].height;
	}
	sort(list, &list[N], comp);
	int num = N / K;
	int yu = N%K;
	sort_people(0, num + yu);
	for (int i = 1; i < K; i++) {
		sort_people(num + yu + (i - 1)*num, num);
	}

	return 0;
}