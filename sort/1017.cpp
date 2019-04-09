#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

struct person
{
	int h, m, s;
	int time;
};

bool comp(person a, person b) {
	if (a.h != b.h)
		return a.h > b.h ? false : true;
	else if (a.m != b.m)
		return a.m > b.m ? false : true;
	else
		return a.s > b.s ? false : true;
}

int count_s(person a) {
	return  a.h * 60 * 60 + a.m * 60 + a.s;
}

int main()
{
	int N, K;
	cin >> N >> K;
	person *table = new person[N]();
	for (int i = 0; i < N; i++) {
		scanf("%d:%d:%d %d", &table[i].h, &table[i].m, &table[i].s, &table[i].time);
	}

	sort(table, &table[N], comp);
	int wait_time = 0;
	queue<person> line;
	for (int i = 0; i < N; i++) {
		if (table[i].h < 8) {
			wait_time += 8 * 60 * 60 - count_s(table[i]);
			table[i].h = 8;
			table[i].m = 0;
			table[i].s = 0;
		}
		line.push(table[i]);
	}
	
	int *w_time = new int[K]();
	const int begin_time = 8 * 60 * 60;
	const int end_time = 17 * 60 * 60;
	for (int i = 0; i < K; i++) {
		w_time[i] = begin_time;
	}
	int now_time;
	int need_time;
	int count = 0;
	//以人作单位
	while (!line.empty()) {
		
		sort(w_time, &w_time[K]);
		now_time = count_s(line.front());
		if (now_time > end_time) { break; }
		need_time = line.front().time * 60;
		if (now_time >= w_time[0]) {
			w_time[0] = now_time + need_time;
			line.pop();
		}
		else {
			wait_time += w_time[0] - now_time;
			w_time[0] += need_time;
			line.pop();
		}
		count++;
	}
	
	printf("%.1lf", double(wait_time) / (60 * count));
	//for (int i = 0; i < N; i++) {
	//	cout << table[i].h << ":" << table[i].m << ":" << table[i].s << " " << table[i].time << endl;
	//}
	return 0;
}