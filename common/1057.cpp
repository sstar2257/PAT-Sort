#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <stack>
#include <set>
#include <string>
#include <vector>
using namespace std;

multiset<int> set1, set2;
int mid;

void Adjust() {
	if (set1.size() > set2.size()+1) {
		auto it = --set1.end();
		set2.insert(*it);
		//insert要在erase前面，不然erase后it指向就不存在了
		set1.erase(it);
	}
	else if (set1.size() < set2.size()) {
		auto it = set2.begin();
		set1.insert(*it);
		set2.erase(it);
	}
	if (!set1.empty()) {
		mid = *set1.rbegin();
	}
}

int main()
{
	int N;
	scanf("%d", &N);
	//cin >> N;
	stack<int> st;
	string order;
	//这里不能用resize，否则下面的==会出问题
	//string重载的==可能会出问题，可以用strcmp
	//order.resize(10);
	int num;
	int top;
	for (int i = 0; i < N; i++) {
		cin >> order;
		//scanf("%s", order.c_str());
		if (order == "Pop") {
			if (st.empty()) {
				//cout << "Invalid" << endl;
				printf("Invalid\n");
			}
			else {
				//cout << st.top() << endl;
				top = st.top();
				printf("%d\n", top);
				if (st.top() > mid) {
					set2.erase(set2.find(top));
				}
				else {
					set1.erase(set1.find(top));
				}
				st.pop();
				Adjust();
			}
		}
		else if (order == "Push") {
			//cin >> num;
			scanf("%d", &num);
			if (st.empty()) {
				set1.insert(num);
				mid = num;
			}
			else {
				if (num > mid) {
					set2.insert(num);
				}
				else {
					set1.insert(num);
				}
				Adjust();
			}
			st.push(num);

		}
		else if (order == "PeekMedian") {
			if (st.empty()) {
				//cout << "Invalid" << endl;
				printf("Invalid\n");
			}
			else {
				//cout << *set1.rbegin() << endl;
				printf("%d\n", *set1.rbegin());
			}
		}
		else {
			printf("Invalid\n");
			//cout << "Invalid" << endl;
		}
	}
	return 0;
}