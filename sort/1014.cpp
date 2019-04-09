#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

struct person
{
	int id;
	int request_time;
};

int output(int time) {
	if (time == 0) {
		cout << "Sorry" << endl;
		return 0;
	}
	int h = time / 60 + 8;
	int m = time % 60;
	printf("%02d:%02d\n", h, m);
	return 0;
}

int main()
{
	int N, M, K, Q;
	cin >> N >> M >> K >> Q;
	queue<person> wait_line;
	for (int i = 0; i < K; i++) {
		person tmp;
		tmp.id = i + 1;
		cin >> tmp.request_time;
		wait_line.push(tmp);
	}
	vector<queue<person>> list;
	int *finished_time = new int[K]();
	for (int i = 0; i < N; i++) {
		queue<person> que;
		list.push_back(que);
	}

	//初始情况
	for (int i = 0; i < M && wait_line.size(); i++) {
		for (int j = 0; j < N && wait_line.size(); j++) {
			list[j].push(wait_line.front());
			wait_line.pop();
		}
	}
	const int all_time = 540;
	//5点之前
	for (int i = 1; i < all_time; i++) {
		for (int j = 0; j < N; j++) {
			if (list[j].size()){
				--list[j].front().request_time;
				if (!list[j].front().request_time) {
					finished_time[list[j].front().id - 1] = i;
					list[j].pop();
				}
			}
		}
		for (int j = 0; j < N && wait_line.size(); j++) {
			if (list[j].size() < M ) {
				list[j].push(wait_line.front());
				wait_line.pop();
			}
		}
	}
	//5点的临界值处理,16:59之后不再接受业务！！！
	//代码有许多部分还可以简化
	//5点之后
	for (int i = all_time; ; i++) {
		int all_done = 1;
		for (int j = 0; j < N; j++) {
			if (list[j].size()) {
				--list[j].front().request_time;
				if (!list[j].front().request_time) {
					finished_time[list[j].front().id - 1] = i;
					while(!list[j].empty())
						list[j].pop();
				}
				all_done = 0;
			}
		}
		if (all_done)
			break;
	}

	//for (int i = 0; i < K; i++) {
	//	cout << finished_time[i] << " ";
	//}

	for (int i = 0; i < Q; i++) {
		int id;
		cin >> id;
		output(finished_time[id - 1]);
	}
	return 0;
}