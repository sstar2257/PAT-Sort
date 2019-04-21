#include <iostream>
#include <queue>
using namespace std;

struct node {
	int data;
	int height;
	node *left;
	node *right;
};

int max(int a, int b) {
	return a > b ? a : b;
}

int get_h(node *tree) {
	if (tree != NULL)
		return tree->height;
	else
		return 0;
}

node *LL(node *root) {
	node *tmp;
	tmp = root->left;
	//这里不能加判断，不然回形成死循环
	//给指针赋NULL没问题
	//if (tmp->right != NULL) {
		root->left = tmp->right;
	//}
	tmp->right = root;

	tmp->height = max(get_h(tmp->left), get_h(tmp->right)) + 1;
	root->height = max(get_h(root->left), get_h(root->right)) + 1;
	return tmp;
}

node *RR(node *root) {
	node *tmp;
	tmp = root->right;
	//if (tmp->left != NULL) {
		root->right = tmp->left;
	//}
	tmp->left = root;

	tmp->height = max(get_h(tmp->left), get_h(tmp->right)) + 1;
	root->height = max(get_h(root->left), get_h(root->right)) + 1;
	return tmp;
}

node *LR(node *root) {
	root->left = RR(root->left);
	return LL(root);
}

node *RL(node *root) {
	root->right = LL(root->right);
	return RR(root);
}

node *insert(node *root, int key) {
	if (root == NULL) {
		root = new node();
		root->data = key;
	}
	else if(key < root->data){
		root->left = insert(root->left, key);
		if (get_h(root->left) - get_h(root->right) == 2) {
			if (key < root->left->data) {
				root = LL(root);
			}
			else {
				root = LR(root);
			}
		}
	}
	else if (key > root->data) {
		root->right = insert(root->right, key);
		if (get_h(root->right) - get_h(root->left) == 2) {
			if (key < root->right->data) {
				root = RL(root);
			}
			else {
				root = RR(root);
			}
		}
	}
	root->height = max(get_h(root->left), get_h(root->right)) + 1;

	return root;
}

queue<node> que;
int mark;
void lvl(node *root) {
	que.push(*root);
	cout << root->data;
	while (!que.empty()) {
		node tmp = que.front();
		que.pop();
		if (tmp.left != NULL) {
			cout << " " <<tmp.left->data;
			que.push(*tmp.left);
			if (mark) {
				mark = 2;
			}
		}
		else if(!mark){//这里必须要严格等于0，不然变成2之后又会变回1
			mark = 1;
		}
		if (tmp.right != NULL) {
			cout << " " << tmp.right->data;
			que.push(*tmp.right);
			if (mark) {
				mark = 2;
			}
		}
		else if(!mark){
			mark = 1;
		}
	}
	cout << endl;
	if (mark == 2) {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
	}
}

int main()
{
	node *root = NULL;
	int N;
	cin >> N;
	int key;
	for (int i = 0; i < N; i++) {
		cin >> key;
		root = insert(root, key);
	}
	lvl(root);
	return 0;
}