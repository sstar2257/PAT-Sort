#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;

int N;
int initial[100];
int res[100];
int process[100];
int merge[100];

void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void insert(int index) {
	int input = initial[index];
	for (int i = 0; i < index + 1; i++) {
		if(input < process[i] || i == index){
			swap(input, process[i]);
		}
	}
}

void mer_insert(int i, int j, int m, int n, int index) {
	while (i <= j && m <= n) {
		if (merge[i] < merge[m]) {
			process[index] = merge[i];
			i++;
			index++;
		}
		else {
			process[index] = merge[m];
			m++;
			index++;
		}
	}
	while (i <= j) {
		process[index] = merge[i];
		i++;
		index++;
	}
	while (m <= n) {
		process[index] = merge[m];
		m++;
		index++;
	}
}

void mer(int num) {
	int cou = N / (2 * num);
	int yu = N % (num * 2);
	if (cou) {
		for (int i = 0; i < cou; i++) {
			int l1 = 2 * i*num;
			int r1 = 2 * i*num + num - 1;
			int l2 = 2 * i*num + num;
			int r2 = 2 * i*num + 2 * num - 1;
			mer_insert(l1, r1, l2, r2, l1);
		}
	}
	if (yu) {
		if (yu <= num) {
			//memcpy的字节数计算错了！！！！
			memcpy(&process[N - yu], &merge[N - yu], yu * sizeof(int));
		}
		else{
			mer_insert(2 * num*cou, 2 * num*cou + num - 1, 2 * num*cou + num, N - 1, 2 * num*cou);
		}
	}
	//int first = 0;
	//int mid = first + num - 1;
	//int last = first + 2 * num - 1;
	//while (last <= N - 1) {
	//	mer_insert(first, mid, mid + 1, last, first);
	//	first += 2 * num;
	//	mid += 2 * num;
	//	last += 2 * num;
	//}
	//if (mid<N - 1) {
	//	mer_insert(first, mid, mid + 1, N-1, first);
	//}
	//else if (first <= N - 1) {
	//	memcpy(&process[first], &merge[first], (N - first) * sizeof(int));
	//}


	memcpy(merge, process, N * sizeof(int));
	memset(process, 0, N * sizeof(int));
}

int comp_insert(int index) {
	for (int i = 0; i <= index; i++) {
		if (process[i] != res[i]) {
			return 0;
		}
	}
	for (int i = index + 1; i < N; i++) {
		if (initial[i] != res[i]) {
			return 0;
		}
	}
	return 1;
}

int comp_merge() {
	for (int i = 0; i < N; i++) {
		if (merge[i] != res[i]) {
			return 0;
		}
	}
	return 1;
}

//这样写有一个insert的测试点过不去，感觉应该是题目问题
//比如1，2，4，3和1，2，4，3不知道是插入了一次还是两次
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> initial[i];
		merge[i] = initial[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> res[i];
	}

	memset(process, 0x3f, 100 * sizeof(int));
	for (int i = 0; i < N; i++) {
		insert(i);
		if (comp_insert(i)) {
			cout << "Insertion Sort" << endl;
			insert(i + 1);
			cout << process[0];
			for (int j = 1; j <= i + 1; j++) {
				cout << " " << process[j];
			}
			for (int j = i + 2; j < N; j++) {
				cout << " " << initial[j];
			}

			return 0;
		}
	}
	memset(process, 0, N * sizeof(int));
	cout << "Merge Sort" << endl;
	int num = 0;
	for (int i = 0; num < N; i++) {
		num = pow(2, i);
		mer(num);
		if (comp_merge()) {
			mer(num * 2);
			cout << merge[0];
			for (int j = 1; j < N; j++) {
				cout << " " << merge[j];
			}
		}
	}

	return 0;
}
