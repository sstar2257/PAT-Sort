#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <vector>
#include <string>

using namespace std;

#define N 100002

struct person {
	char name[9];
	int age;
	int worth;
};

bool cmp(person p1, person p2)
{
	if (p1.worth > p2.worth)
		return true;
	if (p1.worth == p2.worth)
	{
		if (p1.age < p2.age)
			return true;
		if (p1.age == p2.age)
		{
			if (strcmp(p1.name, p2.name) < 0)
				return true;
		}
	}
	return false;
}

person num[N];
//这题需要剪枝（需要仔细读题目）
int main()
{
	//freopen("in", "r", stdin);  
	int n, k;
	scanf("%d%d", &n, &k);
	person pt;
	for (int i = 0; i < n; ++i) {
		scanf("%s%d%d", num[i].name, &num[i].age, &num[i].worth);
	}
	sort(num, num + n, cmp); // 对所有的直接排序先

	int ageCount[201] = { 0 };

	int filter[N];

	int filter_num = 0;
	for (int i = 0; i < n; i++)
	{
		if (ageCount[num[i].age] < 100) // ageCount[] 存相应年龄的人数 M (<= 100)
		{
			ageCount[num[i].age]++;
			filter[filter_num++] = i;
		}
	}
	for (int i = 1; i <= k; i++) {
		int m, amin, amax;
		scanf("%d%d%d", &m, &amin, &amax);
		printf("Case #%d:\n", i);
		int index = 0;
		for (int j = 0; j < filter_num; j++)
		{
			int k = filter[j];
			if (num[k].age >= amin && num[k].age <= amax && index < m)
			{
				printf("%s %d %d\n", num[k].name, num[k].age, num[k].worth);
				index++;
			}
		}
		if (index == 0)
			printf("None\n");
	}
	return 0;
}

//#include <cstdio>
//#include <vector>
//#include <string>
//#include <map>
//#include <algorithm>
//using namespace std;
//
//struct mem {
//	string name;
//	int age;
//	int worths;
//};
//
//bool comp(mem a, mem b) {
//	if (a.worths != b.worths)
//		return a.worths > b.worths;
//	else if (a.age != b.age)
//		return a.age < b.age;
//	else
//		return a.name < b.name;
//}
//
//int main()
//{
//	map<int, vector<mem>> table;
//	int N, K;
//	scanf("%d %d", &N, &K);
//
//	for (int i = 0; i < N; i++) {
//		mem one;
//		one.name.resize(8);
//		scanf("%s %d %d", one.name.c_str(), &one.age, &one.worths);
//		table[one.age].push_back(one);
//	}
//
//	//这种做法每次都要排序，时间消耗比只用一个vector且排序一次要大。
//	for (int i = 0; i < K; i++) {
//		int M, Amin, Amax;
//		scanf("%d %d %d", &M, &Amin, &Amax);
//		printf("Case #%d:\n", i + 1);
//		vector<mem> out;
//		for (auto it = table.begin(); it != table.end(); it++) {
//			int age = it->first;
//			if (age >= Amin && age <= Amax) {
//				if (it->second.size() > 100) {
//					sort(it->second.begin(), it->second.end(), comp);
//					out.insert(out.end(), it->second.begin(), it->second.begin() + 100);
//				}
//				else {
//					out.insert(out.end(), it->second.begin(), it->second.end());
//				}
//			}
//		}
//		int len = out.size();
//		if (!len) {
//			printf("None\n");
//		}
//		else {
//			sort(out.begin(), out.end(), comp);
//			for (int i = 0; i < len && i < M; i++) {
//				mem tmp = out[i];
//				printf("%s %d %d\n", tmp.name.c_str(), tmp.age, tmp.worths);
//			}
//		}
//	}
//	return 0;
//}