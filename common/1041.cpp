#include <iostream>
#include <vector>
using namespace std;
int flag[100001];
int main()
{
	int N;
	cin >> N;
	vector<int> list(N);
	for (int i = 0; i < N; i++) {
		cin >> list[i];
		flag[list[i]]++;
	}
	for (int i = 0; i < N; i++){
		if (flag[list[i]] == 1) {
			cout << list[i];
			return 0;
		}
	}

	cout << "None";
	return 0;
}