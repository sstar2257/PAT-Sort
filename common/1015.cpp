#include <iostream>
#include <cmath>
using namespace std;

bool is_prime(int num) {	
	if (num <= 1)
		return false;
	int sqr = int(sqrt(num));
	for (int i = 2; i <= sqr; i++) {
		if (num%i == 0) {
			return false;
		}
	}
	return true;
}

int trans(int num, int radix, int *arr) {
	int index = 0;
	while (num) {
		arr[index] = num%radix;
		num /= radix;
		index++;
	}
	return index;
}

int main()
{
	int input;
	int num_base_radix[20];
	int index;
	int radix;
	while (cin >> input && input >= 0)
	{	
		cin >> radix;
		if (!is_prime(input)) { 
			cout << "No" << endl; 
		}
		else {
			index = trans(input, radix, num_base_radix);
			int num2 = 0;
			for (int i = 0; i < index; i++) {
				num2 = num2 * radix + num_base_radix[i];
			}
			if (is_prime(num2)) {
				cout << "Yes" << endl;
			}
			else{ 
				cout << "No" << endl;
			}
		}
		
	}
	return 0;
}