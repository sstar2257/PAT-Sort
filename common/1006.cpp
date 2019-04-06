#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

//写的不好
struct record
{
	string name;
	// int h_in;
	// int m_in;
	// int s_in;
	// int h_out;
	// int m_out;
	// int s_out;
	int time_in;
	int time_out;
};

int main()
{
	int M;
	cin >> M;
	record *table = new record[M]();
	int h_in, m_in, s_in;
	int h_out, m_out, s_out;
	string first, last;
	int min = 0x7fffffff, max = 0;
	for(int i=0;i<M;i++){
		//scanf("%s %d:%d:%d %d:%d:%d", table[i].name, &table[i].h_in, &table[i].m_in, &table[i].s_in, &table[i].h_out, &table[i].m_out, &table[i].s_out);
		cin >> table[i].name;
		scanf("%d:%d:%d %d:%d:%d", &h_in, &m_in, &s_in, &h_out, &m_out, &s_out);
		table[i].time_in = h_in*3600+m_in*60+s_in;
		table[i].time_out = h_out*3600+m_out*60+s_out;
		if(table[i].time_in < min){
			min = table[i].time_in;
			first = table[i].name;
		}
		if(table[i].time_out > max){
			max = table[i].time_out;
			last = table[i].name;
		}
	}
	cout << first << " " << last;
	return 0;
}