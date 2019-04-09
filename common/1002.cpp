#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	int K;
	double poly[1001]={0};
	cin >> K;
	for(int i=0;i<K;i++){
		int exp;
		double eff;
		cin >> exp >> eff;
		poly[exp] = eff;
	}
	cin >> K;
	for(int i=0;i<K;i++){
		int exp;
		double eff;
		cin >> exp >> eff;
		poly[exp] += eff;
	}
	int cnt = 0;
	int j=0;
	while(j<1001){
		if(poly[j]!=0)
			cnt++;
		j++;
	}
	cout << cnt;
	for(int i=1000;i>=0;i--){
		if(poly[i]!=0)
			printf(" %d %.1lf",i,poly[i]);
	}
	return 0;
}