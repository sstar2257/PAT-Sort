#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;
int list[100001];
int mark[100001];
//考虑0所在的loop和0不在的loop
//找交换所需次数的内在规律
int main()
{
	int N;
	scanf("%d", &N);
	int loop = 0;
	int input;
	int same = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &input);
		list[i] = input;
		if (i == input) {
			mark[i] = 1;
			same++;
		}
	}
	int flag;
	if (mark[0]) {
		flag = 0;
	}
	else {
		flag = 1;
	}

	int output = N - same;
	for (int i = 0; i < N; i++) {
		if (mark[i]) {
			continue;
		}
		else {
			while (!mark[i]) {
				mark[i] = 1;
				i = list[i];
			}
			loop++;
		}
	}
	if (loop == 0) {
		printf("0");
	}
	//else if (loop == 1) {
	//	//0在环内
	//	if (flag) {
	//		printf("%d", output - 1);
	//	}
	//	else {//0不在环内
	//		printf("%d", output + 1);
	//	}
	//}
	else{
		if (flag) {
			printf("%d", output - 1 + (loop)-1);
		}
		else {
			printf("%d", output + loop);
		}
	}
	return 0;
}
