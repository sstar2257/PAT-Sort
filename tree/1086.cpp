#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;

vector<int> preorder;
vector<int> inorder;
vector<int> stack;
vector<int> postorder;
int mark[30];//中序的访问标记
int N;

void pre2post(int root, int tail) {
	if (root > tail) {
		return;
	}
	int i;
	for (i = 0; i < N; i++) {
		if (inorder[i] == preorder[root]) {
			mark[i] = 1;
			break;
		}
	}
	int left = 0, right = 0;
	for (int j = i-1; j >= 0; j--) {
		if (!mark[j]) {
			left++;
		}
		else {
			break;
		}
	}
	for (int j = i+1; j < N; j++) {
		if (!mark[j]) {
			right++;
		}
		else{
			break;
		}
	}
	pre2post(root + 1, root + left);
	pre2post(tail - right + 1, tail);
	postorder.push_back(preorder[root]);
}

int main()
{
	cin >> N;
	cin.get();
	string input;

	for (int i = 0; i < 2 * N; i++) {
		input.clear();
		getline(cin, input);
		if (input[1] == 'u') {
			int no = atoi(&input[5]);
			preorder.push_back(no);
			stack.push_back(no);
		}
		else {
			int no = stack.back();
			inorder.push_back(no);
			stack.pop_back();
		}
	}
	pre2post(0, N - 1);
	cout << postorder[0];
	for (int i = 1; i < postorder.size(); i++) {
		cout << " " << postorder[i];
	}
	return 0;
}