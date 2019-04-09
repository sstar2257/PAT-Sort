#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int time2num(int h, int m, int s) {
	return h * 3600 + m * 60 + s;
}

void num2time(int time) {
	int h = time / 3600;
	int m = (time % 3600) / 60;
	int s = (time % 3600) % 60;
	printf(" %02d:%02d:%02d", h, m, s);
}

struct car {
	string id;
	int time;
	string state;
};

bool comp(car a, car b) {
	if (a.id != b.id) {
		return a.id < b.id;
	}
	else {
		return a.time < b.time;
	}
}
//注意最后的停车时间是指总的时间
//在for循环里最后一组要考虑下
int main()
{
	int N, K;
	scanf("%d %d", &N, &K);
	vector<car> records(10001);
	int h, m, s;
	for (int i = 0; i < N; i++) {
		records[i].id.resize(7);
		records[i].state.resize(3);
		scanf("%s", records[i].id.c_str());
		scanf("%d:%d:%d", &h, &m, &s);
		records[i].time = time2num(h, m, s);
		scanf("%s", records[i].state.c_str());
	}
	sort(&records[0], &records[N], comp);
	int assist[60 * 60 * 24] = { 0 };
	int table[60 * 60 * 24] = { 0 };
	int max = 0;
	vector<string> car_id;
	int time = 0;
	for (int i = 1; i < N; i++) {
		car tmp = records[i];
		car last = records[i - 1];
		if (tmp.id == last.id) {
			if (tmp.state[0] == 'o' && last.state[0] == 'i') {
				assist[last.time]++;
				assist[tmp.time]--;
				time += tmp.time - last.time;
			}
		}
		else {
			if (time > max) {
				max = time;
				car_id.clear();
				car_id.push_back(last.id);
			}
			else if (time == max) {
				car_id.push_back(last.id);
			}
			time = 0;
		}
	}
	if (time) {
		if (time > max) {
			max = time;
			car_id.clear();
			car_id.push_back(records[N - 1].id);
		}
		else if (time == max) {
			car_id.push_back(records[N - 1].id);
		}
	}

	table[0] = assist[0];
	for (int i = 1; i < 60 * 60 * 24; i++) {
		if (!assist[i]) {
			table[i] = table[i - 1];
		}
		else {
			table[i] = table[i - 1] + assist[i];
		}
	}
	int num;
	for (int i = 0; i < K; i++) {
		scanf("%d:%d:%d", &h, &m, &s);
		num = time2num(h, m, s);
		printf("%d\n", table[num]);
	}

	sort(car_id.begin(), car_id.end());
	printf("%s", car_id[0].c_str());
	for (int i = 1; i < car_id.size(); i++) {
		printf(" %s", car_id[i].c_str());
	}
	num2time(max);
	return 0;
}
