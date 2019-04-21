#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct pre {
	int id;
	int freq;
};

int freq[50001];
int N, K;
vector<pre> list;

void recommend(int no) {
	cout << no << ":";
	for (int i = 0; i < list.size() && i < K; i++) {
		cout << " " << list[i].id;
	}
	cout << endl;
}

bool comp(pre a, pre b) {
	if (a.freq != b.freq)
		return a.freq > b.freq;
	else
		return a.id < b.id;
}
//重点在于排序的数据量，即list列表里的数据控制在k个
int main()
{
	cin >> N >> K;
	int no;
	cin >> no;
	freq[no]++;
	pre tmp;
	tmp.id = no;
	tmp.freq = freq[no];
	list.push_back(tmp);
	int is_in = 0;
	for (int i = 1; i < N; i++) {
		is_in = 0;
		cin >> no;
		freq[no]++;
		recommend(no);
		for (int i = 0; i < list.size(); i++) {
			if (list[i].id == no) {
				list[i].freq++;
				is_in = 1;
				break;
			}
		}
		if (!is_in) {
			tmp.id = no;
			tmp.freq = freq[no];
			list.push_back(tmp);
			sort(list.begin(), list.end(), comp);
			if (list.size() > K) {
				list.pop_back();
			}
		}
		else {
			sort(list.begin(), list.end(), comp);
		}
	}

	return 0;
}

//看到一个重载结构体小于，然后用set来自动排序的，记录一下
//试了下，速度比上面自己写的快
//#include <cstdio>
//#include <cstring>
//#include <set>
//using namespace std;
//
//struct node {
//	int num, cnt;
//	node(int num, int cnt) :num(num), cnt(cnt) {}
//	bool operator < (const node &a)const { // 重载运算符 
//		return cnt != a.cnt ? cnt > a.cnt : num < a.num;
//	}
//};
//set<node> s;
//int times[50001], n, k;
//int main() {
//	scanf("%d%d", &n, &k);
//	memset(times, 0, sizeof(times));
//	int num;
//	for (int i = 0; i < n; i++) {
//		scanf("%d", &num);
//		if (i) {
//			printf("%d:", num);
//			int cnts = 0; // 记录输出的次数 
//			for (auto it = s.begin(); cnts < k && it != s.end(); it++) {
//				printf(" %d", it->num);
//				cnts++;
//			}
//			puts("");
//		}
//		auto it = s.find(node(num, times[num])); // 判断set中是否存在 
//		if (it != s.end()) s.erase(it);
//		times[num]++; // 更新浏览次数 
//		s.insert(node(num, times[num]));
//	}
//	return 0;
//}
