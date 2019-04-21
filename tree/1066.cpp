#include <iostream>
using namespace std;
//AVL构建和插入旋转
struct node {
	int height;
	int key;
	node *left;
	node *right;
};

int max(int a, int b) {
	return a > b ? a : b;
}

int height(node *tree) {
	if (tree != NULL)
		return tree->height;
	else
		return 0;
}

node* leftLeftRotation(node *tree) {
	node *k;
	k = tree->left;
	tree->left = k->right;
	k->right = tree;

	tree->height = max(height(tree->left), height(tree->right)) + 1;
	k->height = max(height(k->left), tree->height) + 1;

	return k;
}

node* rightRightRotation(node *tree) {
	node *k;
	k = tree->right;
	tree->right = k->left;
	k->left = tree;

	tree->height = max(height(tree->left), height(tree->right)) + 1;
	k->height = max(height(k->right), tree->height) + 1;

	return k;
}

node* leftRightRotation(node *tree) {
	tree->left = rightRightRotation(tree->left);
	return leftLeftRotation(tree);
}

node* rightLeftRotation(node *tree) {
	tree->right = leftLeftRotation(tree->right);
	return rightRightRotation(tree);
}



node* insert(node *tree, int key) {

	if (tree == NULL) {
		//新建节点
		tree = new node();
		tree->key = key;
	}
	else if (key < tree->key) {
		//将key递归插入左子树
		tree->left = insert(tree->left, key);
		//插入节点后，若失去平衡，则进行相应的旋转
		if (height(tree->left) - height(tree->right) == 2) {
			if (key < tree->left->key)
				tree = leftLeftRotation(tree);
			else
				tree = leftRightRotation(tree);
		}
	}
	else if(key > tree->key){
		//将key递归插入右子树
		tree->right = insert(tree->right, key);
		if (height(tree->right) - height(tree->left) == 2) {
			if (key > tree->right->key)
				tree = rightRightRotation(tree);
			else
				tree = rightLeftRotation(tree);
		}
	}
	else {
		//key值相等的情况
	}
	tree->height = max(height(tree->left), height(tree->right)) + 1;
	return tree;
}

int main()
{
	int N;
	cin >> N;
	int num;
	node *root = NULL;
	for (int i = 0; i < N; i++) {
		cin >> num;
		root = insert(root, num);
	}
	cout << root->key;
	return 0;
}