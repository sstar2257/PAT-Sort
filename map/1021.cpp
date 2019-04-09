#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

//这题不能用邻接矩阵表来存储边的关系了，会内存超限，可以使用vector
//返回树的数量

//第一次出发开始搜索（不管起始点是哪个节点）所找到的「当前」最长路径的终点（们），一定是「整个图」最长路径的的起始点，
//所以再以此为起始点去深搜，找到的「当前」最长路径的终点，也一定是要找的「整个图」最长路径的起始点（因为这是无向图嘛，起点亦是终点，终点亦是起点）。
//把这些点保存下来，就是要求的节点。
int BFS(vector<vector<int>> table, int N) {
	queue<int> list;
	int *mark = new int[N]();
	list.push(1);
	mark[0] = 1;
	int first;
	int count = 1;
	int part = 1;
	int tmp;
	while (!list.empty()) {
		first = list.front();
		list.pop();
		for (int i = 0; i < table[first-1].size(); i++) {
			tmp = table[first - 1][i];
			if (!mark[tmp-1]) {
				list.push(tmp);
				mark[tmp - 1] = 1;
				count++;
			}
		}
		if (list.empty()) {
			if (count != N) {
				part++;
				for (int i = 0; i < N; i++) {
					if (mark[i])
						continue;
					else {
						list.push(i + 1);
						mark[i] = 1;
						count++;
						break;
					}
				}
			}
		}
	}
	delete[]mark;
	return part;
}
//返回以a为根的深度
vector<int> BFS_D(vector<vector<int>> table, int N, int a) {
	queue<int> list;
	int *mark = new int[N]();
	list.push(a);
	mark[a-1] = 1;
	int first;
	int deep = 0;
	int end = a;
	int tmp;
	vector<vector<int>> res;//存储同一level的节点
	res.resize(N + 1);
	while (!list.empty()) {
		first = list.front();
		res[deep].push_back(first);
		if (end == first) {
			deep++;
			end = 0;
		}
		list.pop();
		//for (int i = 1; i <= N; i++) {
		//	if (table[first - 1][i - 1] && !mark[i - 1]) {
		//		list.push(i);
		//		mark[i - 1] = 1;
		//	}
		//}
		
		for (int i = 0; i < table[first - 1].size(); i++) {
			tmp = table[first - 1][i];
			if (!mark[tmp - 1]) {
				list.push(tmp);
				mark[tmp - 1] = 1;
			}
		}
		if (!end && !list.empty()) {
			end = list.back();		
		}
	}
	delete[]mark;
	return res[deep - 1];
}

//第一步：从任意一个节点开始进行深度优先遍历，找到离他最远的节点（可能不止一个，记为集合A）；
//第二步：再从A中!!!任意!!!选一个节点出发进行深度优先遍历，找到离他最远的节点（记为集合B），最后最深根就是这两个集合的并集。
int main()
{
	int N;
	cin >> N;
	//int **table = new int *[N]();
	//for (int i = 0; i < N; i++) {
	//	table[i] = new int[N]();
	//}
	//int x, y;
	//for (int i = 0; i < N-1; i++) {
	//	cin >> x >> y;
	//	table[x - 1][y - 1] = table[y - 1][x - 1] = 1;
	//}
	vector<vector<int>> table;
	table.resize(N + 1);
	int x, y;
	for (int i = 0; i < N - 1; i++) {
		cin >> x >> y;
		table[x-1].push_back(y);
		table[y-1].push_back(x);
	}

	//int deepest = 0;
	//int deep;
	vector<int> A;
	set<int> out;
	int res = BFS(table, N);
	if (res != 1) {
		cout << "Error: " << res << " components";
	}
	else {
		/*for (int i = 1; i <= N; i++) {
			deep = BFS_D(table, N, i);
			if (deep > deepest) {
				deepest = deep;
				out.clear();
				out.push_back(i);
			}
			else if (deep == deepest) {
				out.push_back(i);
			}
		}*/
		A = BFS_D(table, N, 1);
		out.insert(A.begin(), A.end());
		//这里关于容器的使用有很多要注意的地方。。。比如构造、拷贝等
		//最后所求为并集，可能会有重复，所以不能简单的使用vector的insert，可以使用不会重复的set
		//只要任意选一个就好了。。。所以不用循环
		vector<int> B = BFS_D(table, N, A[0]);
		out.insert(B.begin(), B.end());
		for (auto i=out.begin();i!=out.end();i++) 
			cout << *i << endl;
	}

	return 0;
}