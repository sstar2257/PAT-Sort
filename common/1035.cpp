#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct stu{
	string name;
	string passwd;
};

int modify(string &str, char c, char r_c){
	int pos;
	int res = 0;
	while((pos = str.find(c))!=string::npos){
		str.replace(pos,1,1,r_c);
		res = 1;
	}
	return res;
}

int main()
{
	int N;
	cin >> N;
	stu *table = new stu[N]();
	int flag;
	vector<int> m_list;
	for(int i=0;i<N;i++){
		flag = 0;
		cin >> table[i].name >> table[i].passwd;
		flag = modify(table[i].passwd,'1','@') | modify(table[i].passwd,'l','L') \
			| modify(table[i].passwd,'0','%') | modify(table[i].passwd,'O','o');
		if(flag)
			m_list.push_back(i); 
	}
	if(m_list.empty()){
		if(N==1){
			cout << "There is 1 account and no account is modified";
		}
		else{
			cout << "There are " << N << " accounts and no account is modified";
		}
	}
	else{
		cout << m_list.size() << endl;
		int len = m_list.size();
		for(int i=0;i<len;i++){
			cout << table[m_list[i]].name << " " << table[m_list[i]].passwd << endl;
		}
	}
	return 0;
}