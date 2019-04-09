#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <string>
using namespace std;

map<string, set<int>> title;
map<string, set<int>> author;
map<string, set<int>> keywoods;
map<string, set<int>> publisher;
map<int, set<int>> publish_year;

void stringsplit(string str, int id) {
	int pos1 = 0;
	int pos2 = str.find(" ", 0);
	while (pos2 != string::npos) {
		//cout << str.substr(pos1, pos2 - pos1) << endl;
		keywoods[str.substr(pos1, pos2 - pos1)].insert(id);
		pos1 = pos2 + 1;
		pos2 = str.find(" ", pos1);
	}
	keywoods[str.substr(pos1, pos2 - pos1)].insert(id);
	//cout << str.substr(pos1) << endl;
}

int main()
{
	int N, M;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int id;
		string s_title;
		string s_author;
		string s_keywords;
		string s_publisher;
		int year;
		cin >> id;
		getchar();
		getline(cin, s_title);
		getline(cin, s_author);
		getline(cin, s_keywords);
		getline(cin, s_publisher);
		cin >> year;
		title[s_title].insert(id);
		author[s_author].insert(id);
		stringsplit(s_keywords, id);
		publisher[s_publisher].insert(id);
		publish_year[year].insert(id);
	}
	cin >> M;
	getchar();//去掉输入数字后的回车
	for (int i = 0; i < M; i++) {
		string query;
		getline(cin, query);
		cout << query << endl;
		string str = query.substr(query.find(" ", 0)+1);
		int type = query[0] - '0';
		set<int> out;
		switch (type) {
		case 1:out = title[str]; break;
		case 2:out = author[str]; break;
		case 3:out = keywoods[str]; break;
		case 4:out = publisher[str]; break;
		case 5:out = publish_year[atoi(str.c_str())]; break;
		default:;
		}
		if (!out.size())
			cout << "Not Found" << endl;
		else {
			for (auto it = out.begin(); it != out.end(); it++) {
				printf("%07d\n", *it);
			}
		}

	}
	return 0;
}