#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() 
{
	vector<string> cards(54);
	for (int i = 0; i < 4; i++) {
		char ch;
		switch (i) {
		case 0:ch = 'S'; break;
		case 1:ch = 'H'; break;
		case 2:ch = 'C'; break;
		case 3:ch = 'D'; break;
		default:;
		}
		for (int j = 0; j < 13; j++) {
			cards[13 * i + j] += ch + to_string(j + 1);
		}
	}
	cards[52] = "J1";
	cards[53] = "J2";

	int repeat;
	int pos[54];
	cin >> repeat;
	for (int i = 0; i < 54; i++) {
		cin >> pos[i];
	}
	vector<string> new_cards(54);
	for (int i = 0; i < repeat; i++) {
		for (int j = 0; j < 54; j++) {
			new_cards[pos[j] - 1] = cards[j];
		}
		cards.swap(new_cards);
	}
	cout << cards[0];
	for (int i = 1; i < 54; i++) {
		cout << " " << cards[i];
	}
	return 0;
}