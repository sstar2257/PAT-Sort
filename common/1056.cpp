#include <iostream>
#include <queue>
using namespace std;

struct each {
	int w;
	int rank;
};
//有groups个组，那么晋级下一轮的就有groups个人，所有没晋级的并列第groups+1名。
int main()
{
	int P, G;
	cin >> P >> G;
	each *list = new each[P]();
	for (int i = 0; i < P; i++) {
		cin >> list[i].w;
	}
	queue<int> que;
	int num;
	for (int i = 0; i < P; i++) {
		cin >> num;
		que.push(num);
	}
	while (!que.empty()) {
		int len = que.size();
		int turns = len / G;
		int yu = len%G;
		int max;
		int index;
		for (int i = 0; i < turns; i++) {
			max = -1;
			index = -1;
			for (int j = 0; j < G; j++) {
				int front = que.front();
				que.pop();
				if (list[front].w > max) {
					max = list[front].w;
					index = front;
				}
				list[front].rank = yu ? turns + 2 : turns+1;
			}
			que.push(index);
		}
		if (yu) {
			max = -1;
			index = -1;
			for (int j = 0; j < yu; j++) {
				int front = que.front();
				que.pop();
				if (list[front].w > max) {
					max = list[front].w;
					index = front;
				}
				list[front].rank = turns + 2;
			}
			que.push(index);
		}

		if (que.size() == 1) {
			int front = que.front();
			list[front].rank = 1;
			break;
		}
	}

	for (int i = 0; i < P; i++) {
		cout << list[i].rank;
		if (i != P - 1)
			cout << " ";
		else
			cout << endl;
	}
	return 0;
}