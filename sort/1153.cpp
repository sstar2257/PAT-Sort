#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct owner{
	string card;
	int score;
};

struct site {
	int num;
	int total;
};

struct date {
	int no;
	int sum;
};

map<int, vector<owner>> levels;
map<int, site> sites;
map<int, map<int, int>> dates;

void levels_insert(string card, int score) {
	owner tmp = { card,score };
	if (card[0] == 'B') {
		levels[0].push_back(tmp);
	}
	else if (card[0] == 'A') {
		levels[1].push_back(tmp);
	}
	else {
		levels[2].push_back(tmp);
	}
}

void sites_insert(string card, int score) {
	int no = stoi(card.substr(1, 3));
	sites[no].num++;
	sites[no].total += score;
}

void dates_insert(string card) {
	int day = stoi(card.substr(4, 6));
	int no = stoi(card.substr(1, 3));
	dates[day][no]++;
}

bool comp_lvl(owner a, owner b) {
	if (a.score != b.score)
		return a.score > b.score;
	else
		return a.card < b.card;
}

bool comp_date(date a, date b) {
	if (a.sum != b.sum)
		return a.sum > b.sum;
	else
		return a.no < b.no;
}
//一次过。。。虽然被烦的要死，还是很欣慰的
//意料中的超时问题竟然没有出现
int main()
{
	int N, K;
	cin >> N >> K;
	string card;
	int score;
	for (int i = 0; i < N; i++) {
		cin >> card >> score;
		levels_insert(card, score);
		sites_insert(card, score);
		dates_insert(card);
	}
	for (int i = 0; i < 3; i++) {
		sort(levels[i].begin(), levels[i].end(), comp_lvl);
	}
	int type;
	int index;
	for (int i = 1; i <= K; i++) {
		cin >> type;
		printf("Case %d: %d ", i, type);
		if (type == 1) {
			char val;
			cin >> val;
			printf("%c\n", val);
			if (val == 'B') {
				index = 0;
			}
			else if (val == 'A') {
				index = 1;
			}
			else {
				index = 2;
			}
			if (levels[index].empty()) {
				printf("NA\n");
			}
			else {
				for (int j = 0; j < levels[index].size(); j++) {
					printf("%s %d\n", levels[index][j].card.c_str(), levels[index][j].score);
				}
			}
		}
		else if(type == 2){
			int val;
			cin >> val;
			printf("%d\n", val);
			if (sites[val].num == 0) {
				printf("NA\n");
			}
			else {
				printf("%d %d\n", sites[val].num, sites[val].total);
			}
		}
		else if (type == 3) {
			int val;
			cin >> val;
			printf("%06d\n", val);
			if (dates[val].empty()) {
				printf("NA\n");
			}
			else {
				vector<date> res;
				date tmp;
				for (auto it = dates[val].begin(); it != dates[val].end();it++) {
					tmp.no = it->first;
					tmp.sum = it->second;
					res.push_back(tmp);
				}
				sort(res.begin(), res.end(), comp_date);
				for (int j = 0; j < res.size(); j++) {
					printf("%d %d\n", res[j].no, res[j].sum);
				}
			}
		}
	}
	return 0;
}