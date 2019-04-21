#include <iostream>
#include <string>
using namespace std;

int main() {
	int bead[128] = { 0 };
	string shop, eva;
	cin >> shop >> eva;
	int len = shop.length();
	int missing = 0;
	for (int i = 0; i < len; i++) {
		bead[shop[i]]++;
	}
	int need_len = eva.length();
	for (int i = 0; i < need_len; i++) {
		if (bead[eva[i]] > 0) {
			bead[eva[i]]--;
		}
		else {
			missing++;
		}
	}
	if (missing) {
		cout << "No " << missing;
	}
	else {
		cout << "Yes " << len - need_len;
	}
	return 0;
}