#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	int *list = new int[N]();
	for(int i=0;i<N;i++){
		cin >> list[i];
	}

	int count = list[0]*6+5;
	for(int i=1;i<N;i++){
		if(list[i]>list[i-1]){
			count += (list[i]-list[i-1])*6+5;
		}
		else{
			count += (list[i-1] - list[i])*4+5;
		}
	}
	cout << count << endl;
	return 0;
}
