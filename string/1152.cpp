#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
using namespace std;

bool is_prime(int num) {
	if (num < 2) {
		return false;
	}
	else {
		for (int i = 2; i <= sqrt(num); i++) {
			if (num%i == 0) {
				return false;
			}
		}
		return true;
	}
}
//如果这个数首位0开的话，需要把这些0也打印出来
int main()
{
	int N, K;
	cin >> N >> K;
	string input;
	int num;
	cin >> input;
	for (int i = 0; i <= N - K; i++) {
		num = stoi(input.substr(i, K));
		if (is_prime(num)) {
			string res = to_string(num);
			for (int j = res.length(); j < K; j++) {
				cout << 0;
			}
			cout << res;
			return 0;
		}
	}
	cout << 404 << endl;
	return 0;
}