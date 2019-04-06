#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

//���ⲻ�����ڽӾ�������洢�ߵĹ�ϵ�ˣ����ڴ泬�ޣ�����ʹ��vector
//������������

//��һ�γ�����ʼ������������ʼ�����ĸ��ڵ㣩���ҵ��ġ���ǰ���·�����յ㣨�ǣ���һ���ǡ�����ͼ���·���ĵ���ʼ�㣬
//�������Դ�Ϊ��ʼ��ȥ���ѣ��ҵ��ġ���ǰ���·�����յ㣬Ҳһ����Ҫ�ҵġ�����ͼ���·������ʼ�㣨��Ϊ��������ͼ���������յ㣬�յ�������㣩��
//����Щ�㱣������������Ҫ��Ľڵ㡣
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
//������aΪ�������
vector<int> BFS_D(vector<vector<int>> table, int N, int a) {
	queue<int> list;
	int *mark = new int[N]();
	list.push(a);
	mark[a-1] = 1;
	int first;
	int deep = 0;
	int end = a;
	int tmp;
	vector<vector<int>> res;//�洢ͬһlevel�Ľڵ�
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

//��һ����������һ���ڵ㿪ʼ����������ȱ������ҵ�������Զ�Ľڵ㣨���ܲ�ֹһ������Ϊ����A����
//�ڶ������ٴ�A��!!!����!!!ѡһ���ڵ��������������ȱ������ҵ�������Զ�Ľڵ㣨��Ϊ����B�������������������������ϵĲ�����
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
		//�������������ʹ���кܶ�Ҫע��ĵط����������繹�졢������
		//�������Ϊ���������ܻ����ظ������Բ��ܼ򵥵�ʹ��vector��insert������ʹ�ò����ظ���set
		//ֻҪ����ѡһ���ͺ��ˡ��������Բ���ѭ��
		vector<int> B = BFS_D(table, N, A[0]);
		out.insert(B.begin(), B.end());
		for (auto i=out.begin();i!=out.end();i++) 
			cout << *i << endl;
	}

	return 0;
}