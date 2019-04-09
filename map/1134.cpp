#include <iostream>
#include <vector>
#include <set>
using namespace std;

int N, M;
vector<int> table[10000];//table中记录的是边的编号
set<int> alone;

void judge(vector<int> a) {
	set<int> connect;
	for (int i = 0; i < a.size(); i++) {
		if (!table[a[i]].empty()) {
			connect.insert(table[a[i]].begin(), table[a[i]].end());
		}
	}
	if (connect.size() == M) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}
//题目意思理解了好久。。。。因为第一个样例不明白为什么是NO
//找了一些博客，才发现题目意思是：一幅图的顶点的集合是这样的一个集合：图中的每一条边都能关联到集合内的一个点
//因此样例1中，1-9的边没有关联到任何点，所以是错误的
//开始一直以为是集合中的点能够遍历到所有点。。。图论做多的后遗症
int main()
{
	cin >> N >> M;
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		table[a].push_back(i);
		table[b].push_back(i);
	}
	int K, num, input;
	cin >> K;
	vector<int> query;
	for (int i = 0; i < K; i++) {
		cin >> num;
		query.clear();
		for (int j = 0; j < num; j++) {
			cin >> input;
			query.push_back(input);
		}
		judge(query);
	}

	return 0;
}

//也可以不用set，大佬们各有各的方法,比如用数组进行边的标记，下面的大佬用了hash的思想将顶点和边唯一确定下来
//很受启发，mark下
//#include<iostream> //水题
//#include<vector> 
//using namespace std;
//int main() {
//	int n, m;
//	cin >> n >> m;
//	vector<int> edge(m, 0);
//	for (int i = 0; i<m; i++) {
//		int s, e;
//		cin >> s >> e;
//		edge[i] = s * 10000 + e;
//	}
//	int k;
//	cin >> k;
//	for (int i = 0; i<k; i++) {
//		int nv, flag = 0;
//		cin >> nv;
//		vector<int> visited(n + 1, 0);
//		for (int j = 0; j<nv; j++) {
//			int t;
//			cin >> t;
//			visited[t] = 1;
//		}
//		for (int j = 0; j<m; j++) {
//			int s = edge[j] / 10000;
//			int e = edge[j] % 10000;
//			if (visited[s] == 0 && visited[e] == 0)
//				flag = 1;
//		}
//		flag == 1 ? cout << "No" << endl : cout << "Yes" << endl;
//	}
//	return 0;
//}