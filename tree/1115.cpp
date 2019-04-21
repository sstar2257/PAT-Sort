#include <iostream>
#include <vector>
using namespace std;

struct node {
	int data;
	int level;
	node *left;
	node *right;
};

int lvl[1001];
int lowest = 1;

void insert(int key, node *root) {
	if (key <= root->data) {
		if (root->left == NULL) {
			node *tmp = new node();
			tmp->data = key;
			tmp->level = root->level + 1;
			lvl[tmp->level]++;
			if (tmp->level > lowest) {
				lowest = tmp->level;
			}
			root->left = tmp;
		}
		else {
			insert(key, root->left);
		}
	}
	else {
		if (root->right == NULL) {
			node *tmp = new node();
			tmp->data = key;
			tmp->level = root->level + 1;
			lvl[tmp->level]++;
			if (tmp->level > lowest) {
				lowest = tmp->level;
			}
			root->right = tmp;
		}
		else {
			insert(key, root->right);
		}
	}
}

int main()
{
	int N;
	node *root = new node();
	cin >> N;
	int key;
	cin >> key;
	root->data = key;
	root->level = 1;
	lvl[1]++;
	for (int i = 1; i < N; i++) {
		cin >> key;
		insert(key, root);
	}
	cout << lvl[lowest] << " + " << lvl[lowest - 1] << " = " << lvl[lowest] + lvl[lowest - 1];
 	return 0;
}