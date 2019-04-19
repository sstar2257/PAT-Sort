#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int N, M;
	cin >> N >> M;
	int *chain = new int[N]();
	for (int i = 0; i < N; i++) {
		cin >> chain[i];
	}
	int min = 0x7FFFFFFF;
	int sum = chain[0];
	vector<int> mark;
	for (int i = 0, j = 0; i < N&&j < N;) {
		if (sum >= M && i<=j) {
			if (sum < min) {
				min = sum;
				mark.clear();
				mark.push_back(i+1);
				mark.push_back(j+1);
				sum -= chain[i];
				i++;
			}
			else if (sum == min) {
				mark.push_back(i+1);
				mark.push_back(j+1);
				sum -= chain[i];
				i++;
				j++;
				sum += chain[j];
			}
			else {
				sum -= chain[i];
				i++;
			}
		}
		else {
			j++;
			sum += chain[j];
		}
	}
	int len = mark.size();
	for (int i = 0; i < len; i+=2) {
		cout << mark[i] << "-" << mark[i + 1] << endl;
	}
	return 0;
}