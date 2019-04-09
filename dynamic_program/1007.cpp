#include <iostream>
using namespace std;
//可以用O(n）的联机算法
//核心思想，当当前元素加入序列后，如果子序列和小于0，即抛弃已有子序列，重开新的计数
int main()
{
	int K;
	cin >> K;
	int *list = new int[K]();
	for(int i=0;i<K;i++){
		cin >> list[i];
	}
	//题目意思弄清楚，关于0的处理要注意
	double max = -1;
	int first, last;
	double sum;
	for(int i=0;i<K;i++){
		if(list[i]<0){
			continue;
		}
		else{
			sum = 0;
			for(int j=i;j<K;j++){
				sum += list[j];
				if(sum > max){
					max = sum;
					first = list[i];
					last = list[j];
				}
			}
		}
	}
	if(max == -1){
		cout << 0 << " " << list[0] << " " << list[K-1];
	}
	else{
		cout << max << " " << first << " " << last;
	}
	return 0;
}