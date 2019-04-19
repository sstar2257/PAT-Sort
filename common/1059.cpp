#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int main()
{
	long int num;
	int root;
	cin >> num;
	int num2 = num;
	vector<int> res;
	for (int i = 2; i <= sqrt(num2); i++) {
		int yu = num2 % i;
		if (yu == 0) {
			num2 /= i;
			res.push_back(i);
			i--;
		}
	}
	//最后剩下部分
	res.push_back(num2);
	int len = res.size();
	int power = 1;
	int last = res[0];
	if (len == 0) {
		cout << num << "=" << num;
	}
	else {
		cout << num << "=";
		for (int i = 1; i < len; i++) {
			if (res[i] == last) {
				power++;
			}
			else {
				if (power == 1) {
					cout << last << "*";
					last = res[i];
				}
				else {
					cout << last << "^" << power << "*";
					power = 1;
					last = res[i];
				}
			}
		}
		if (power != 1) {
			cout << res[len - 1] << "^" << power;
		}
		else {
			cout << res[len - 1];
		}
	}
	return 0;
}