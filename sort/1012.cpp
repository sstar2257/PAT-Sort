//https://www.cnblogs.com/8023spz/p/7666883.html
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
int w = 1;
struct stu
{
    string id;
    int c,m,e,a;
    int cc,mm,ee,aa;
}s[2001];
bool cmp(stu a,stu b)
{
    if(w == 1)return a.c>b.c;
    else if(w == 2)return a.m>b.m;
    else if(w == 3)return a.e>b.e;
    else return a.a>b.a;
}
void print(stu a)
{
    char ch = 'A';
    int d = a.aa;
    if(d > a.cc)ch = 'C',d = a.cc;
    if(d > a.mm)ch = 'M',d = a.mm;
    if(d > a.ee)ch = 'E',d = a.ee;
    cout<<d<<' '<<ch<<endl;
}
int main()
{
    int n,m;
    string p;
    map<string,int> match;
    cin>>n>>m;
    for(int i = 0;i < n;i ++)
    {
        cin>>s[i].id>>s[i].c>>s[i].m>>s[i].e;
        s[i].a = s[i].c + s[i].m + s[i].e;
    }
//    for(int i = 0;i < n;i ++)
//    {
//        cout<<s[i].id<<' '<<s[i].a<<endl;
//    }
    sort(s,s+n,cmp);
    for(int i = 0;i < n;i ++)
    {
        if(i > 0 && s[i].c == s[i - 1].c)s[i].cc = s[i - 1].cc;
        else s[i].cc = i + 1;
    }
    w = 2;
    sort(s,s+n,cmp);
    for(int i = 0;i < n;i ++)
    {
        if(i > 0 && s[i].m == s[i - 1].m)s[i].mm = s[i - 1].mm;
        else s[i].mm = i + 1;
    }
    w = 3;
    sort(s,s+n,cmp);
    for(int i = 0;i < n;i ++)
    {
        if(i > 0 && s[i].e == s[i - 1].e)s[i].ee = s[i - 1].ee;
        else s[i].ee = i + 1;
    }
    w = 4;
    sort(s,s+n,cmp);
    for(int i = 0;i < n;i ++)
    {
        if(i > 0 && s[i].a == s[i - 1].a)s[i].aa = s[i - 1].aa;
        else s[i].aa = i + 1;
        match[s[i].id] = i + 1;
    }
    for(int i = 0;i < m;i ++)
    {
        cin>>p;
        if(match[p])print(s[match[p] - 1]);
        else cout<<"N/A"<<endl;
    }
    return 0;
}
// #include <iostream>
// //#include <cstdio>
// #include <vector>
// #include <algorithm>
// using namespace std;

// struct grade
// {
// 	int flag;//whether it exits
// 	int C;
// 	int M;
// 	int E;
// 	double A;
// };

// bool comp(int a, int b){
// 	return a > b;
// }
// bool comp_double(double a, double b){
// 	return a > b;
// }

// int print_max(int c, int m, int e, int a){
// 	//结构体太大直接段错误
// 	int tmp = 1000000;
// 	char ch;
// 	if(e <= tmp){
// 		tmp = e;
// 		ch = 'E';
// 	}
// 	if(m <= tmp){
// 		tmp = m;
// 		ch = 'M';
// 	}
// 	if(c <= tmp){
// 		tmp = c;
// 		ch = 'C';
// 	}
// 	if(a <= tmp){
// 		tmp = a;
// 		ch = 'A';
// 	}
// 	cout << tmp << " " << ch << endl;
// 	return 0; 
// }

// int main()
// {
// 	grade mylist[1000000] = {0};
// 	int N,M;
// 	cin >> N >> M;
// 	vector<int> lc;
// 	vector<int>	lm;
// 	vector<int> le;
// 	vector<double> la;
// 	int no;
// 	int c,m,e;
// 	double a;
// 	for(int i=0;i<N;i++){
// 		cin >> no >> c >> m >> e;
// 		a = (double(c+m+e))/3;
// 		mylist[no] = {1, c, m, e, a};
// 		lc.push_back(c);
// 		lm.push_back(m);
// 		le.push_back(e);
// 		la.push_back(a);
// 	}

// 	sort(lc.begin(), lc.end(), comp);
// 	sort(lm.begin(), lm.end(), comp);
// 	sort(le.begin(), le.end(), comp);
// 	sort(la.begin(), la.end(), comp_double);

// 	for(int i=0;i<M;i++){
// 		cin >> no;
// 		if(mylist[no].flag == 0){
// 			cout << "N/A" << endl;
// 			continue;
// 		}
// 		int rc = distance(lc.begin(), find(lc.begin(), lc.end(), mylist[no].C));
// 		int rm = distance(lm.begin(), find(lm.begin(), lm.end(), mylist[no].M));
// 		int re = distance(le.begin(), find(le.begin(), le.end(), mylist[no].E));
// 		int ra = distance(la.begin(), find(la.begin(), la.end(), mylist[no].A));

// 		print_max(rc, rm, re, ra);
// 	}
// 	return 0;
// }


//分数不重要，重要的是排名，因此先看高排名再去看分数
// struct grade{
// 	double C;
// 	double M;
// 	double E;
// 	double A;
// 	int rank;
// 	char course;
// };

// int ranking(double x, char ch, map<string, grade> mymap){
// 	//排名的方式注意下，出现并列情况
// 	int result = 1;
// 	if(ch == 'A'){
// 		for(auto it = mymap.begin(); it != mymap.end(); it++){
// 			if(it->second.A > x)
// 				result++;
// 		}
// 	}
// 	else if(ch == 'C'){
// 		for(auto it = mymap.begin(); it != mymap.end(); it++){
// 			if(it->second.C > x)
// 				result++;
// 		}
// 	}
// 	else if(ch == 'M'){
// 		for(auto it = mymap.begin(); it != mymap.end(); it++){
// 			if(it->second.M > x)
// 				result++;
// 		}
// 	}
// 	else if(ch == 'E'){
// 		for(auto it = mymap.begin(); it != mymap.end(); it++){
// 			if(it->second.E > x)
// 				result++;
// 		}
// 	}

// 	return result;
// }

// int main()
// {
// 	map<string, grade> mymap;
// 	int N,M;
// 	cin >> N >> M;
// 	for(int i=0;i<N;i++){
// 		string str;
// 		grade gra;
// 		cin >> str >> gra.C >> gra.M >> gra.E;
// 		gra.A = (gra.C + gra.M + gra.E)/3;
// 		mymap[str] = gra;
// 	}

// 	for(auto it = mymap.begin(); it != mymap.end(); it++){
// 		//find max score
// 		double tmp = 0;
// 		if(it->second.E >= tmp){
// 			it->second.course = 'E';
// 			tmp = it->second.E;
// 		}
// 		if(it->second.M >= tmp){
// 			it->second.course = 'M';
// 			tmp = it->second.M;
// 		}
// 		if(it->second.C >= tmp){
// 			it->second.course = 'C';
// 			tmp = it->second.C;
// 		}
// 		if(it->second.A >= tmp){
// 			it->second.course = 'A';
// 			tmp = it->second.A;
// 		}
// 		//ranking
// 		it->second.rank = ranking(tmp, it->second.course, mymap);

// 	}

// 	for(int i=0;i<M;i++){
// 		string in;
// 		cin >> in;
// 		auto it = mymap.find(in);
// 		if(it != mymap.end()){
// 			cout << it->second.rank << " " << it->second.course << endl;
// 		}
// 		else{
// 			cout << "N/A" << endl;
// 		}
// 	}

// 	return 0;
// }