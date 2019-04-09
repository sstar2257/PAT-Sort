//#include <iostream>
//#include <cstdio>
//#include <vector>
//using namespace std;
//
//struct ch {
//	char letter;
//	int next;
//};
//
//ch table[100000];
//
//int main()
//{
//	int a1, a2, N;
//	cin >> a1 >> a2 >> N;
//	int x, y;
//	char c;
//	for (int i = 0; i < N; i++) {
//		cin >> x >> c >> y;
//		table[x].letter = c;
//		table[x].next = y;
//	}
//	vector<ch> str1, str2;
//	ch tmp = table[a1];
//	while (tmp.next != -1) {
//		str1.push_back(tmp);
//		tmp = table[tmp.next];
//	}
//	str1.push_back(tmp);
//
//	tmp = table[a2];
//	while (tmp.next != -1) {
//		str2.push_back(tmp);
//		tmp = table[tmp.next];
//	}
//	str2.push_back(tmp);
//
//	int len1 = str1.size();
//	int len2 = str2.size();
//
//	if (str1[len1 - 1].letter != str2[len2 - 1].letter) {
//		cout << "-1";
//	}
//	else {
//		//知道为什么有一个大的测试点过不去了。。。。因为这边判断条件是letter，大数据中letter大概率会重复！！！！
//		while (len1 >= 1 && len2 >= 1) {
//			if (str1[len1 - 1].letter != str2[len2 - 1].letter) {
//				break;
//			}
//			len1--;
//			len2--;
//		}
//		if (len1 >= 1 && len2 >= 1) {
//			printf("%05d", str1[len1 - 1].next);
//		}
//		else if (len1 == 0) {
//			printf("%05d", a1);
//		}
//		else if (len2 == 0) {
//			printf("%05d", a2);
//		}
//	}
//	return 0;
//}


//只要是链表中第一个出现的节点就可以，不需要整个后缀都相同,因为那个表的后续节点是一致的。。。。。想太复杂了
#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
struct node {
	char key;
	int address;
	int next;
};

int flag[100005];
node nodes[100005];
int main() {
	for (int root1, root2, n; scanf("%d%d%d", &root1, &root2, &n) != EOF;) {
		memset(flag, 0, sizeof(int) * 100005);
		while (n--) {
			int address;
			scanf("%d", &address);
			scanf(" %c %d", &nodes[address].key, &nodes[address].next);
			nodes[address].address = address;
		}
		int index = -1;
		while (root1 != -1) {
			flag[root1]++;
			root1 = nodes[root1].next;
		}
		while (root2 != -1) {
			if (flag[root2]) {
				index = nodes[root2].address;
				break;
			}
			root2 = nodes[root2].next;
		}
		if (index != -1) {
			printf("%05d\n", index);
		}
		else {
			printf("-1\n");
		}
	}
	return 0;
}
