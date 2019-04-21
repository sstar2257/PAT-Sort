#include <iostream>
#include <vector>
using namespace std;

struct node {
	int data;
	int left;
	int right;
};

int N;
node lvl[1000];
vector<int> path;
int is_heap = 1;

void build() {
	for (int i = 0, j = 1; j < N; i++) {
		if (lvl[i].left == 0) {
			lvl[i].left = j;
			j++;
		}
		if (j < N && lvl[i].right == 0) {
			lvl[i].right = j;
			j++;
		}
	}
}

void output() {
	for (int i = 0; i < path.size(); i++) {
		if (i) {
			cout << " ";
		}
		cout << path[i];
	}
	cout << endl;
}

void judge_max(int root) {
	int key = lvl[root].data;
	path.push_back(key);
	if (lvl[root].right != 0) {
		if (key < lvl[lvl[root].right].data) {
			is_heap = 0;
		}
		judge_max(lvl[root].right);
	}
	if (lvl[root].left != 0) {
		if (key < lvl[lvl[root].left].data) {
			is_heap = 0;
		}
		judge_max(lvl[root].left);
	}
	if (lvl[root].left == 0 && lvl[root].right == 0) {
		output();
	}
	path.pop_back();
}

void judge_min(int root) {
	int key = lvl[root].data;
	path.push_back(key);
	if (lvl[root].right != 0) {
		if (key >= lvl[lvl[root].right].data) {
			is_heap = 0;
		}
		judge_min(lvl[root].right);
	}
	if (lvl[root].left != 0) {
		if (key >= lvl[lvl[root].left].data) {
			is_heap = 0;
		}
		judge_min(lvl[root].left);
	}
	if (lvl[root].left == 0 && lvl[root].right == 0) {
		output();
	}
	path.pop_back();
}

//我晕。。。找了半天结果是最后输出的大小写搞错了
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> lvl[i].data;
	}
	build();
	if (lvl[0].data >= lvl[1].data) {
		judge_max(0);
		if (is_heap) {
			cout << "Max Heap" << endl;
		}
		else {
			cout << "Not Heap" << endl;
		}
	}
	else {
		judge_min(0);
		if (is_heap) {
			cout << "Min Heap" << endl;
		}
		else {
			cout << "Not Heap" << endl;
		}
	}
	return 0;
}