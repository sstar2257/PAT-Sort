#include <iostream>
using namespace std;
//主要是学习堆排序
//代码网上找来的，感觉自己对树的结构还是不太清楚
void swap(int arr[], int a, int b) {
	int tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}
//调整大顶堆（仅做了调整，建立在大顶堆已构建的基础上）
void adjust(int arr[], int i, int length) {
	int tmp = arr[i];//取出当前元素
	//k = k * 2 + 1 ?
	//因为当上面的节点被调整之后，可能回影响到下面已经调整过的节点，所以需要对下面的节点进行再次调整
	//这里有个从上而下的过程
	for (int k = 2 * i + 1; k < length; k = k * 2 + 1) {//从i节点的左子节点开始
		if (k + 1 < length && arr[k] < arr[k + 1]) {//如果左子节点小于右子节点，k指向右子节点
			k++;
		}
		if (arr[k] > tmp) {//如果子节点大于父节点，将子节点值赋给父节点
			arr[i] = arr[k];
			i = k;
		}
		else {
			break;
		}
	}
	arr[i] = tmp;//将tmp值放到最终的位置
}

//将一个无序序列构造大顶堆的时候，有一个从下而上进行调整的过程
//构造完大顶堆进行排序的时候，却是一个从上而下的过程
//因为前面已经构造了大顶堆，所以只需要考虑顶部元素的位置即可，其余部分仍满足大顶堆的要求
void heap_sort(int arr[], int length) {
	//1.构造大顶堆
	for (int i = length / 2 - 1; i >= 0; i--) {
		//从第一个非叶子节点，从右往左调整结构
		adjust(arr, i, length);
	}
	//2.调整堆结构+贾环堆顶元素与末尾元素
	for (int i = length - 1; i > 0; i--) {
		swap(arr, 0, i);//将堆顶元素与末尾元素进行交换
		adjust(arr, 0, i);//重新对堆进行调整
	}
}

void insert_sort(int arr[], int i) {
	int tmp = arr[i];
	int index = i;
	for (int j = 0; j < i; j++) {
		if (tmp >= arr[j]) {
			continue;
		}
		else {
			index = j;
			break;
		}
	}
	while (i > index) {
		//在[]里用自加自减符号注意优先级
		arr[i] = arr[i-1];
		i--;
	}
	arr[index] = tmp;
}



int main()
{
	int N;
	cin >> N;
	int num[100];
	int res[100];
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> res[i];
	}
	int i, j;
	for (i = 0; res[i] <= res[i + 1] && i + 1 < N; i++);
	for (j = i + 1; num[j] == res[j] && j < N; j++);
	if (j == N) {
		cout << "Insertion Sort" << endl;
		insert_sort(res, i + 1);
	}
	else {
		cout << "Heap Sort" << endl;
		for (i = N - 1; i > 0 && res[i] >= res[i - 1]; i--);
		//这里第三个参数是length，不是index
		swap(res, 0, i);
		adjust(res, 0, i);
	}
	for (int k = 0; k < N; k++) {
		cout << res[k] << (k == N - 1 ? "" : " ");
	}


	return 0;
}