#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

struct mooncake {
	double inventory;
	double price;
}list[1001];

bool comp(mooncake a, mooncake b) {
	double aa = a.price / a.inventory;
	double bb = b.price / b.inventory;
	return aa > bb;
}
//存量也要使用double，不然过不去
int main()
{
	int N;
	double D;
	scanf("%d %lf", &N, &D);
	for (int i = 0; i < N; i++) {
		scanf("%lf", &list[i].inventory);
	}
	for (int i = 0; i < N; i++) {
		scanf("%lf", &list[i].price);
	}
	sort(list, &list[N], comp);

	double sum = 0;
	double profit = 0;
	for (int i = 0; i < N && sum < D; i++) {
		if (sum + list[i].inventory <= D) {
			sum += list[i].inventory;
			profit += list[i].price;
		}
		else {
			double gap = D - sum;
			sum = D;
			profit += (list[i].price / list[i].inventory)*gap;
		}
	}
	printf("%.02lf", profit);

	return 0;
}