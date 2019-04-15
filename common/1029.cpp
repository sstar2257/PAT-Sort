/*题解：
第一个队列存好后，把第二个队列边读，边和第一个队列比较，选择出队。这样可以不用一次存完第二个队列，解决超内存的问题。

思路：
第一、二个序列分别有n, m个元素，所以需要从队头剔除（n + m - 1） / 2个元素，
最后答案就是两个队头的最小值。对于最终答案在第一第二个队列中的情况要分开处理。
若答案在第二个队列中，在输入数据时就可以提前得出答案并退出，若答案在第一个队列中，要二次出队才能找到答案。

注意：
在所有元素入队列完毕后，把INT_MAX入队列，一是这样队列永不为空，方便处理。
-------------------- -
作者：xmj15715216140
来源：CSDN
原文：https ://blog.csdn.net/xmj15715216140/article/details/80925186 
版权声明：本文为博主原创文章，转载请附上博文链接！
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <climits>
#include <queue>
using namespace std;
int main() {
	queue<int> a, b;
	int n, m, num, cnt = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		a.push(num);
	}
	a.push(INT_MAX);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &num);
		b.push(num);
		if (cnt == (n + m - 1) / 2) {
			printf("%d", min(a.front(), b.front()));
			return 0;
		}
		if (a.front() < b.front())
			a.pop();
		else
			b.pop();
		cnt++;
	}
	b.push(INT_MAX);
	for (; cnt < (n + m - 1) / 2; cnt++) {
		if (a.front() < b.front())
			a.pop();
		else
			b.pop();
	}
	printf("%d", min(a.front(), b.front()));
	return 0;
}
