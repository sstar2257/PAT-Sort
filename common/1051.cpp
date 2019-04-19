#include <iostream>
#include <vector>
using namespace std;
//通过计算剩余空间来判断
int main()
{
	int M, N, K;
	cin >> M >> N >> K;
	for (int i = 0; i < K; i++) {
		int is_no = 0;
		int *list = new int[N+1]();
		for (int j = 0; j < N; j++) {
			cin >> list[j];
		}
		vector<int> stack;
		stack.push_back(0);
		int max = 0;
		for (int j = 0; j < N; j++) {
			int top = stack.back();
			if (list[j] > top) {
				while (list[j] > max) {
					stack.push_back(++max);
				}
			}
			else if (list[j] < top) {
				is_no = 1;
				break;
			}
			else {
				stack.pop_back();
				continue;
			}
			if (stack.size() > M + 1) {
				is_no = 1;
				break;
			}
			max = stack.back();
			stack.pop_back();
		}
		if (is_no) {
			cout << "NO" << endl;
		}
		else {
			cout << "YES" << endl;
		}
		delete[]list;
	}
	return 0;
}