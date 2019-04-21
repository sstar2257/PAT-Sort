#include <iostream>
#include <cmath>
using namespace std;

//1不是质数
int is_prime(int num) {
	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0) {
			return 0;
		}
	}
	return 1;
}


int find_prime(int num) {
	if (num <= 1) {
		num = 2;
	}
	while (!is_prime(num)) {
		num++;
	}
	return num;
}
//我晕。。。完全没看懂题目
//解决冲突的二次探测法。。。
int main()
{
	int M, N;
	cin >> M >> N;
	int size = find_prime(M);
	int *mark = new int[size]();
	int input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		int m = input % size;
		if (!mark[m]) {
			cout << m << ((i == N - 1) ? "" : " ");
			mark[m] = 1;
		}
		else {
			//二次冲突探测
			int j;
			for (j = 1; j < size; j++) {
				m = (input + j*j) % size;
				if (!mark[m]) {
					cout << m << ((i == N - 1) ? "" : " ");
					mark[m] = 1;
					break;
				}
			}
			if (j >= size) {
				cout << "-" << ((i == N - 1) ? "" : " ");
			}
		}
	}
	return 0;
}