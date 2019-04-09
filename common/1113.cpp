#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <set>
using namespace std;
int main()
{
	int N;
	scanf("%d", &N);
	multiset<long long int> table;
	long long int num;
	for (int i = 0; i < N; i++) {
		scanf("%lld", &num);
		table.insert(num);
	}
	int size = table.size();
	int min;
	long long int sum1 = 0, sum2 = 0;
	if (size % 2) {
		min = 1;
	}
	else {
		min = 0;
	}

	auto it = table.begin();
	for (int i = 0; i < size / 2; i++) {
		sum1 += *it;
		it++;
	}
	for (int i = size / 2; i < size; i++) {
		sum2 += *it;
		it++;
	}
	printf("%d %lld", min, sum2 - sum1);
	return 0;
}