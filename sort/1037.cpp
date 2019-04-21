#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int Nc, Np;
	cin >> Nc;
	long int *coupons = new long int[Nc + 1]();
	for (int i = 0; i < Nc; i++) {
		cin >> coupons[i];
	}
	cin >> Np;
	long int *products = new long int[Np + 1]();
	for (int i = 0; i < Np; i++) {
		cin >> products[i];
	}
	sort(coupons, &coupons[Nc]);
	sort(products, &products[Np]);

	//cout << sizeof(int) << endl;
	//cout << sizeof(long int) << endl;
	//cout << sizeof(long long) << endl;

	//两边的序列都要判断，否则会越界出现未知问题
	long long int sum = 0;
	for (int i = 0; i < Np && i < Nc && products[i] < 0 && coupons[i] < 0; i++) {
		sum += products[i] * coupons[i];
	}
	//这里注意判断条件可以等于啊！！！，不然就遍历不到所有元素
	for (int i = Np - 1, j = Nc - 1; i >= 0 && j >= 0 && products[i] > 0 && coupons[j] > 0; i--, j--) {
		sum += products[i] * coupons[j];
	}
	cout << sum << endl;
	return 0;
}

//8：00！！！！！