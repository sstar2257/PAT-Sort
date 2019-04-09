#include <iostream>
#include <cstdio>
using namespace std;
//注意最后的空格，不要在if里在放判断
int main(int argc, char const *argv[])
{
	int A,B;
	cin >> A;
	double *aN1 = new double[A]();
	int *N1 = new int[A]();
	for(int i=0;i<A;i++){
		cin >> N1[i] >> aN1[i];
	}
	cin >> B;
	double *aN2 = new double[B]();
	int *N2 = new int[B]();
	for(int i=0;i<B;i++){
		cin >> N2[i] >> aN2[i];
	}

	//输出多项式的最多可能项数
	int C = N1[0]+ N2[0]+1;
	double *aN3 = new double[C]();
	int coeff;
	for(int i=0;i<A;i++){
		for(int j=0;j<B;j++){
			coeff = N1[i] + N2[j];
			aN3[coeff] += aN1[i]*aN2[j];
		}
	}

	int count = 0;
	for(int i=0;i<C;i++){
		if(aN3[i] != 0){
			count ++;
		}
	}
	cout << count;

	for(int i=C-1;i>=0;i--){
		if(aN3[i] != 0){
			//cout << (C-i) << " " << aN3[C-i] << (i==C-1?"":" ");
			printf(" %d %.1lf", i, aN3[i]);
		}
	}

	return 0;
}