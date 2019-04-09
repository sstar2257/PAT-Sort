#include <iostream>
using namespace std;

int table[201][201];
//考察哈密顿回路
//题目刚开始看了好几遍没理解意思。。。其实就是下面4个判断
//满足了以下条件即输出YES，只要有不满足的就输出NO：
//1.路径节点个数等于n + 1
//2.相邻点之间存在连通的边
//3.前n点各只出现过1次
//4.第一个节点等于最后一个节点，构成回路
int main()
{
	int N, M;
	cin >> N >> M;
	int x, y;
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		table[x][y] = table[y][x] = 1;
	}
	int count;
	cin >> count;
	int num, no;
	int flag;
	int begin, end;
	for (int i = 0; i < count; i++) {
		flag = 1;
		cin >> num;
		if (num != N + 1) {
			flag = 0;
		}
		int *list = new int[N + 1]();
		cin >> begin;
		list[begin] = 1;
		int tmp = begin;
		for (int j = 1; j < num - 1; j++) {
			cin >> no;
			if (!list[no] && table[tmp][no]) {
				list[no] = 1;
			}
			else {
				flag = 0;
			}
			tmp = no;
		}
		cin >> end;
		if (begin != end || !table[tmp][end]) {
			flag = 0;
		}
		if (flag) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
		delete[]list;
	}
	return 0;
}