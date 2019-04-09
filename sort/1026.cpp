#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

struct mem {
	int h, m, s;
	int time;
	int vip;
	int wait_time;
};

struct table {
	int no;
	int time;
	int vip;
	int count;
};

bool comp(mem a, mem b) {
	if (a.h != b.h)
		return a.h < b.h ? true : false;
	else if (a.m != b.m)
		return a.m < b.m ? true : false;
	else
		return a.s < b.s ? true : false;
}

bool comp_tables(table a, table b) {
	if (a.time != b.time)
		return a.time < b.time;
	else
		return a.no < b.no;
}
//wait_Time单位是s！！！！因为这个卡了好久
bool comp_serve(mem a, mem b) {
	int a_arr = a.h * 60 * 60 + a.m * 60 + a.s;
	int b_arr = b.h * 60 * 60 + b.m * 60 + b.s;
	int a_serve = a_arr + a.wait_time;
	int b_serve = b_arr + b.wait_time;
	if (a_serve != b_serve) {
		return a_serve < b_serve;
	}
	else {
		return a_arr < b_arr;
	}
}
bool comp_table_no(table a, table b) {
	return a.no < b.no;
}

int count_s(mem a) {
	return  a.h * 60 * 60 + a.m * 60 + a.s;
}

void format_s(int a) {
	int h = a / 3600;
	int m = (a % 3600) / 60;
	int s = a % 60;
	printf("%02d:%02d:%02d", h, m, s);
}

int main()
{
	int N;
	cin >> N;
	mem *record = new mem[N+1]();

	for (int i = 0; i < N; i++) {
		scanf("%d:%d:%d", &record[i].h, &record[i].m, &record[i].s);
		cin >> record[i].time >> record[i].vip;
	}

	int K, M;
	cin >> K >> M;
	
	vector<table> tables(K);
	const int begin_time = 8 * 60 * 60;
	for (int i = 0; i < K; i++) {
		tables[i].no = i + 1;
		tables[i].time = begin_time;
		tables[i].vip = 0;
		tables[i].count = 0;
	}
	int num;
	for (int i = 0; i < M; i++) {
		cin >> num;
		tables[num - 1].vip = 1;
	}

	sort(record, &record[N], comp);
	
	deque<mem> list;
	for (int i = 0; i < N; i++) {
		list.push_back(record[i]);
	}
	//当有多个乒乓球台空闲时，vip顾客到了会使用最小id的vip球台，而不是最小id的球台
	vector<mem> res;
	int table_time;
	int mem_time;
	int is_vip;
	while (!list.empty()) {
		is_vip = 0;
		sort(tables.begin(), tables.end(), comp_tables);
		mem t_mem = list.front();
		table t_table = tables.front();
		table_time = t_table.time;
		mem_time = count_s(t_mem);
		if (table_time >= 21 * 60 * 60 || mem_time >= 21 * 60 * 60) {
			break;
		}
		if (mem_time >= table_time) {
			//如果是vip，会去选择vip座位,所以要先检查是否有vip桌
			if (t_mem.vip) {
				auto it = tables.begin();
				while (mem_time >= it->time && it != tables.end()) {
					if (it->vip) {
						t_mem.wait_time = 0;
						it->count++;
						if (t_mem.time <= 2 * 60)
							it->time = mem_time + t_mem.time * 60;
						else
							it->time = mem_time + 2 * 60 * 60;
						res.push_back(t_mem);
						list.pop_front();
						is_vip = 1;
						break;
					}
					it++;
				}
			}
			//当前有vip用户，没有空余的vip桌子时，vip当做普通用户进入队列排序；
			//有空余的vip桌子时，应该先就坐vip座位
			//没找到vip座位
			if(!is_vip){
				t_mem.wait_time = 0;
				tables.front().count++;
				if (t_mem.time <= 2 * 60)
					tables.front().time = mem_time + t_mem.time * 60;
				else
					tables.front().time = mem_time + 2 * 60 * 60;
				res.push_back(t_mem);
				list.pop_front();
			}
		}
		else if (!tables.begin()->vip) {//即将空出普通座位
			t_mem.wait_time = table_time - mem_time;
			tables.front().count++;
			if (t_mem.time <= 2 * 60)
				tables.front().time = table_time + t_mem.time * 60;
			else
				tables.front().time = table_time + 2 * 60 * 60;
			res.push_back(t_mem);
			list.pop_front();
		}
		else {//即将空出来的是vip座位,检查排队的人里是否有vip
			//front 和 begin 返回的东西不一样
			auto it = list.begin();
			while (count_s(*it) <= table_time && it!=list.end()) {
				if (it->vip) {
					it->wait_time = table_time - count_s(*it);
					tables.front().count++;
					if (it->time <= 2 * 60)
						tables.front().time = table_time + it->time * 60;
					else
						tables.front().time = table_time + 2 * 60 * 60;
					res.push_back(*it);
					list.erase(it);
					is_vip = 1;
					break;
				}
				it++;
			}
			if (is_vip) {
				continue;
			}
			else {
				t_mem.wait_time = table_time - mem_time;
				tables.front().count++;
				if (t_mem.time <= 2 * 60)
					tables.front().time = table_time + t_mem.time * 60;
				else
					tables.front().time = table_time + 2 * 60 * 60;
				res.push_back(t_mem);
				list.pop_front();
			}
		}
	}

	sort(res.begin(), res.end(), comp_serve);

	for (int i = 0; i < res.size(); i++) {
		format_s(count_s(res[i]));
		cout << " ";
		format_s(count_s(res[i]) + res[i].wait_time);
		cout << " ";
		//cout << (res[i].wait_time + 30) / 60 << endl;
		cout << (res[i].wait_time + 30) / 60 << endl;
	}

	sort(tables.begin(), tables.end(), comp_table_no);
	for (int i = 0; i < K; i++) {
		cout << tables[i].count;
		if (i != K - 1)
			cout << " ";
	}
	return 0;
}