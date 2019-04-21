#include <iostream>
using namespace std;
//忘记了题目说的取模。。。
int main()
{
	char ch;
	cin.get(ch);
	long long int count_p = 0;
	//int count_a = 0;
	long long int count_pat = 0;
	long long int count_pa = 0;
	do {
		if (ch == 'P') {
			count_p++;
		}
		else if (ch == 'A') {
			//count_a++;
			count_pa += count_p;
		}
		else if(ch == 'T'){
			count_pat += count_pa;
		}
		cin.get(ch);
	} while (ch != '\n');
	cout << count_pat % 1000000007;
	return 0;
}