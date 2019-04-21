#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <set>
//using namespace std;
using std::set;

//这个数组不能在main里面申请，会栈溢出
int input[100001];
int max[100001];
int min[100001];

int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &input[i]);
	}

	int tmp = 0;
	for (int i = 0; i < N; i++) {
		if (tmp < input[i]) {
			tmp = input[i];
		}
		max[i] = tmp;
	}
	tmp = 0x7fffffff;
	for (int i = N - 1; i >= 0; i--) {
		if (tmp > input[i]) {
			tmp = input[i];
		}
		min[i] = tmp;
	}
	set<int> list;
	if (N == 1) {
		list.insert(input[0]);
	}
	else if (N >= 2) {
		if (input[0] < min[1]) {
			list.insert(input[0]);
		}
		if (input[N - 1] > max[N - 2]) {
			list.insert(input[N - 1]);
		}
		for (int i = 1; i < N - 1; i++) {
			if (input[i] > max[i - 1] && input[i] < min[i + 1]) {
				list.insert(input[i]);
			}
		}
	}

	printf("%d\n", list.size());
	if (list.size() == 0) {
		printf("\n");//如果是0的话要输出一个空行，否则会格式错误
	}
	for (auto it = list.begin(); it != list.end(); it++) {
		if (it == list.begin()) {
			printf("%d", *it);
		}
		else {
			printf(" %d", *it);
		}
	}
	return 0;
}