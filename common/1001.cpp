#include <iostream>
#include <string>
using namespace std;
int main()
{
	int a,b;
	cin >> a >> b;
	int num = a + b;
	if(num<0){
		num = -num;
		cout << "-";
	}
	string sum = to_string(num);
	string out = "";
	int len = sum.size();
	int cnt = 0;
	for(int i=len-1;i>=0;i--){
		if(cnt!=3){
			out = sum[i] + out;
			cnt++;
		}
		else{
			out = "," + out;
			out = sum[i] + out;
			cnt = 1;
		}
	}
	cout << out;
	return 0;
}