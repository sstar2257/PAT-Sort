#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
using namespace std;

//考虑num<=1的情况
bool is_prime(int num) {
	if (num <= 1)return false;
	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

//二次再散列法的i有限制，只需要加到Tsize - 1就行了
int main()
{
	int Tsize, N, M;
	scanf("%d %d %d", &Tsize, &N, &M);
	while (!is_prime(Tsize)) {
		Tsize++;
	}
	int *mark = new int[Tsize + 1]();
	int input, index, flag;
	for (int i = 0; i < N; i++) {
		flag = 1;
		scanf("%d", &input);
		index = input % Tsize;
		if (!mark[index]) {
			mark[index] = input;
		}
		else {
			for (int j = 1; j < Tsize; j++) {
				index = (input + j*j) % Tsize;
				if (!mark[index]) {
					mark[index] = input;
					flag = 0;
					break;
				}
			}
			if (flag) {
				printf("%d cannot be inserted.\n", input);
			}
		}
	}
	int sum = 0;
	//H(2) = (2 + 1 ^ 2) % 5 = 2，此时hashtable[2]为空（第2次比较），说明这个值不在表中，故查找结束，共查找了2次。
	//就是说如果一个数进行平方探测时，那个位置为空，则说明那个数不在表中，可以直接结束查询
	for (int i = 0; i < M; i++) {
		scanf("%d", &input);
		index = input % Tsize;
		sum++;
		if (mark[index] == input || !mark[index]) {//这里的这个判断要和下面一致，即同样需要判断是否为空，不然测试点0就过不去
			continue;
		}
		else {
			int j;
			for (j = 1; j < Tsize; j++) {
				sum++;
				index = (input + j*j) % Tsize;
				if (mark[index] == input || !mark[index])
					break;
				//若key值在d从0~TSize-1进行枚举后仍然无法解决冲突，PAT里在这种情况下要多加1次，也就是认为key=15总共比较了6次
				if (j == Tsize - 1) {
					sum++;
				}
			}
			//if (j == Tsize)
			//	sum++;
		}
	}
	printf("%.1lf\n", 1.0*sum / M);
	return 0;
}