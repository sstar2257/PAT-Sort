#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int mark[10000];

int is_prime(int n) {
	int tmp = sqrt(n);
	for (int i = 2; i <= tmp; i++) {
		if (n % i == 0) {
			return 0;
		}
	}
	return 1;
}

int main()
{
	int N;
	cin >> N;
	int input;
	for (int i = 1; i <= N; i++) {
		cin >> input;
		mark[input] = i;
	}
	int K;
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> input;
		if (!mark[input]) {
			printf("%04d: Are you kidding?", input);
		}
		else if(mark[input] == -1){
			printf("%04d: Checked", input);
		}
		else if(mark[input] == 1){
			printf("%04d: Mystery Award", input);
			mark[input] = -1;
		}
		else {
			int res = is_prime(mark[input]);
			if (res) {
				printf("%04d: Minion", input);
			}
			else {
				printf("%04d: Chocolate", input);
			}
			mark[input] = -1;
		}
		printf("\n");
	}
	return 0;
}