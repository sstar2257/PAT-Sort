#include <iostream>
#include <string>
using namespace std;
//只需要考虑到B等于0的可能性就行
void judge(string input) {
	int len = input.size();
	int num = stoi(input);
	int a = stoi(input.substr(0, len/2));
	int	b = stoi(input.substr(len / 2));
	if (b != 0 && num % (a * b) == 0) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return;
}


int main()
{
	int N;
	cin >> N;
	string num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		judge(num);
	}
	return 0;
}