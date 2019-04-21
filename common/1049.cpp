#include <iostream>
using namespace std;

int countones(int N) {
	int cnt = 0, i = 1;
	while (N / i != 0) {
		int high = N / (i * 10);
		int low = N - (N / i)*i;
		int index = (N / i) % 10;
		if (index == 0) {
			cnt += high *i;
			//cout << "index = 0 " << "cnt = " << cnt << " | " << high << " " << low << " " << endl;
		}
		else if (index == 1) {
			cnt += high*i + low + 1;
			//cout << "index = 1 " << "cnt = " << cnt << " | " << high << " " << low << " " << endl;
		}
		else {
			cnt += (high + 1)*i;
			//cout << "index = else " << "cnt = " << cnt << " | " << high << " " << low << " " << endl;
		}
		i *= 10;
	}
	return cnt;
}

int main()
{
	int N;
	cin >> N;
	cout << countones(N);
	return 0;
}
