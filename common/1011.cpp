#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	double input;
	double tmp;
	int flag;
	char ch[3] = {'W', 'T', 'L'};
	double product = 1;
	for(int i=0;i<3;i++){
		tmp = 0;
		flag = 0;
		for(int j=0;j<3;j++){
			cin >> input;
			if(input > tmp){
				tmp = input;
				flag = j;
			}
		}
		product *= tmp;
		cout << ch[flag] << " ";
	}
	product = (product * 0.65 - 1) * 2;
	printf("%.2lf",product);
	return 0;
}