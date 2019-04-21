#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <set>
using namespace std;
int couple[100000];
set<int> unknown;
set<int> single;

int main()
{
	int N;
	scanf("%d", &N);
	int c1, c2;
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &c1, &c2);
		couple[c1] = c2 + 1;
		couple[c2] = c1 + 1;//加1处理的原因是：id有可能为0，为了下面判断的方便，对所有值做加1处理。
	}
	int M;
	scanf("%d", &M);
	int num;
	for (int i = 0; i < M; i++) {
		scanf("%d", &num);
		if (!couple[num]) {
			single.insert(num);
		}
		else {
			auto it = unknown.find(couple[num] - 1);
			if (it != unknown.end()) {
				unknown.erase(it);
			}
			else {
				unknown.insert(num);
			}
		}
	}
	if (!unknown.empty()) {
		single.insert(unknown.begin(), unknown.end());
	}
	int len = single.size();
	printf("%d\n", len);
	if (len) {
		auto it = single.begin();
		printf("%05d", *it);
		for (++it; it != single.end(); it++) {
			printf(" %05d", *it);
		}
	}
	return 0;
}