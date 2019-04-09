#include <iostream>
#include <string>
using namespace std;

void trans(int i){
	switch (i){
		case 0:cout << "zero";break;
		case 1:cout << "one";break;
		case 2:cout << "two";break;
		case 3:cout << "three";break;
		case 4:cout << "four";break;
		case 5:cout << "five";break;
		case 6:cout << "six";break;
		case 7:cout << "seven";break;
		case 8:cout << "eight";break;
		case 9:cout << "nine";break;
		default:;
	}
}

int main()
{
	string input;
	cin >> input;
	int sum = 0;
	for(int i=0;i<input.size();i++){
		sum += input[i] - '0';
	}
	//cout << sum << endl;
	if(sum/100){
		trans(sum/100);
		cout << " ";
		sum = sum % 100;
		trans(sum/10);
		cout << " ";
		sum = sum % 10;
		trans(sum);
	}
	else if(sum/10){
		trans(sum/10);
		cout << " ";
		sum = sum % 10;
		trans(sum);
	}
	else{
		trans(sum);
	}
	return 0;
}