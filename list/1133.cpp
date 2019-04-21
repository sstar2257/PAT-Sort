#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;

struct node {
	int addr;
	int data;
	int next;
};

node arr[100001];
vector<node> neg;
vector<node> les;
vector<node> greater;

//容器的size()返回值是一个unsigned int值，如果等于0的时候，再减1的话，会是一个非常大的值
//所以如果对size进行运算，先转换成int
int main()
{
	int enter;
	scanf("%d", &enter);
	int N, K;
	scanf("%d %d", &N, &K);
	int addr;
	for (int i = 0; i < N; i++) {
		scanf("%d", &addr);
		arr[addr].addr = addr;
		scanf("%d %d", &arr[addr].data, &arr[addr].next);
	}
	//do {
	//	int key = arr[enter].data;
	//	if (key < 0) {
	//		neg.push_back(arr[enter]);
	//	}
	//	else if (key > K) {
	//		greater.push_back(arr[enter]);
	//	}
	//	else {
	//		les.push_back(arr[enter]);
	//	}
	//	enter = arr[enter].next;
	//} while (enter != -1);
	while (enter != -1) {
		int key = arr[enter].data;
		if (key < 0) {
			neg.push_back(arr[enter]);
		}
		else if (key > K) {
			greater.push_back(arr[enter]);
		}
		else {
			les.push_back(arr[enter]);
		}
		enter = arr[enter].next;
	}

	int len1 = neg.size();
	for (int i = 0; i < len1 - 1; i++) {
		//while (1);
		printf("%05d %d %05d\n", neg[i].addr, neg[i].data, neg[i + 1].addr);
	}
	if (!neg.empty()) {
		if (!les.empty()) {
			printf("%05d %d %05d\n", neg.back().addr, neg.back().data, les.front().addr);
		}
		else if (!greater.empty()) {
			printf("%05d %d %05d\n", neg.back().addr, neg.back().data, greater.front().addr);
		}
		else {
			printf("%05d %d -1\n", neg.back().addr, neg.back().data);
			return 0;
		}
	}

	int len2 = les.size();
	for (int i = 0; i < len2 - 1; i++) {
		printf("%05d %d %05d\n", les[i].addr, les[i].data, les[i + 1].addr);
	}
	if (!les.empty()) {
		if (!greater.empty()) {
			printf("%05d %d %05d\n", les.back().addr, les.back().data, greater.front().addr);
		}
		else {
			printf("%05d %d -1\n", les.back().addr, les.back().data);
			return 0;
		}
	}

	int len3 = greater.size();
	for (int i = 0; i < len3 - 1; i++) {
		printf("%05d %d %05d\n", greater[i].addr, greater[i].data, greater[i + 1].addr);
	}
	if (!greater.empty()) {
		printf("%05d %d -1\n", greater.back().addr, greater.back().data);
	}

	return 0;
}