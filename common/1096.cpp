#include <iostream>
#include <cmath>
using namespace std;

//想了半天没找到规律，还是用了个类似穷举的办法
int main() {
	int n;
	cin >> n;
	int m = sqrt((double)n);
	int maxCount = 0;
	int first = n;
	for (int i = 2; i <= m; i++) {
		int count = 0;
		int start = i;
		int tmp = n;
		while (tmp%start == 0) {
			count++;
			tmp = tmp / start;
			start++;//一旦找到可以整除的i就缩小n并检测i+1
		}
		if (start - i>maxCount) {
			maxCount = start - i;
			first = i;
		}
	}
	if (maxCount == 0) {//n只能被自己和1整除
		cout << 1 << endl;
		cout << n;
		return 0;
	}
	cout << maxCount << endl;
	cout << first;
	for (int i = 1; i<maxCount; i++)
		cout << "*" << first + i;
	return 0;
}