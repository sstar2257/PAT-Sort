#include <iostream>
#include <string>
#include <map>
using namespace std;
string str[1000];
map<string, int> winner;

int main()
{
	int M, N, S;
	cin >> M >> N >> S;
	for (int i = 0; i < M; i++) {
		cin >> str[i];
	}
	if (S > M) {
		cout << "Keep going..." << endl;
	}
	else {
		while (S <= M) {
			if (winner.find(str[S-1]) != winner.end()) {
				S++;
			}
			else {
				winner[str[S-1]] = 1;
				cout << str[S-1] << endl;
				S += N;
			}
		}
	}
	return 0;
}