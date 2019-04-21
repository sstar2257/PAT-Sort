#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int dis[500][500];
int mytime[500][500];
int d_pre[500];
int t_pre[500];
int d_mark[500];
int shortest[500];
int t_mark[500];
int fastest[500];
int pass[500];
int pass_time[500];
int N, M;


void dijksra_t(int source, int des) {
	for (int i = 0; i < N; i++) {
		fastest[i] = mytime[source][i];
		if (fastest[i] != 0x3f3f3f3f) {
			pass[i] = 1;
		}
		else {
			pass[i] = 0x3f3f3f3f;
		}
	}
	int min;
	int index;
	t_mark[source] = 1;
	for (int j = 0; j < N; j++) {
		min = 0x3f3f3f3f;
		index = -1;
		for (int i = 0; i < N; i++) {
			if (!t_mark[i] && fastest[i] < min) {
				min = fastest[i];
				index = i;
			}
		}
		if (index == -1) {
			break;
		}
		t_mark[index] = 1;
		if (index == des) {
			break;
		}
		for (int i = 0; i < N; i++) {
			if (!t_mark[i] && fastest[i] > fastest[index] + mytime[index][i]) {
				fastest[i] = fastest[index] + mytime[index][i];
				t_pre[i] = index;
				pass[i] = pass[index] + 1;
			}
			else if (!t_mark[i] && fastest[i] == fastest[index] + mytime[index][i]) {
				//if (pass[index] < pass[t_pre[i]]) {
				if(pass[i] > pass[index] + 1){
					t_pre[i] = index;
					pass[i] = pass[index] + 1;
				}
			}
		}
	}
}

void dijksra_d(int source, int des) {
	for (int i = 0; i < N; i++) {
		shortest[i] = dis[source][i];
		if (mytime[source][i] != 0x3f3f3f3f) {
			pass_time[i] = mytime[source][i];
		}
		else {
			pass_time[i] = 0x3f3f3f3f;
		}
	}
	int min;
	int index;
	d_mark[source] = 1;
	for (int j = 0; j < N; j++) {
		min = 0x3f3f3f3f;
		index = -1;
		for (int i = 0; i < N; i++) {
			if (!d_mark[i] && shortest[i] < min) {
				min = shortest[i];
				index = i;
			}
		}
		if (index == -1) {
			break;
		}
		d_mark[index] = 1;
		if (index == des) {
			break;
		}
		for (int i = 0; i < N; i++) {
			if (!d_mark[i] && shortest[i] > shortest[index] + dis[index][i]) {
				shortest[i] = shortest[index] + dis[index][i];
				d_pre[i] = index;
				pass_time[i] = pass_time[index] + mytime[index][i];
			}
			else if (!d_mark[i] && shortest[i] == shortest[index] + dis[index][i]) {
				//if (fastest[index] + mytime[index][i] < fastest[i]) {
				//	d_pre[i] = index;
				//}
				if (pass_time[i] > pass_time[index] + mytime[index][i]) {
					d_pre[i] = index;
					pass_time[i] = pass_time[index] + mytime[index][i];
				}
			}
		}
	}
}

int judge(vector<int> a, vector<int> b) {
	if (a.size() != b.size()) {
		return 0;
	}
	else {
		for (int i = 0; i < a.size(); i++) {
			if (a[i] != b[i]) {
				return 0;
			}
		}
		return 1;
	}
}
//这里有个问题，当最短路径不唯一时，输出最快的那条，这里对最快的判定，不能直接用fastest中的数据
//原来以为这个最快和求最快路径的数据应该是一致的，所以先求fastest，后求shortest，结果测试点2会过不去
//为了偷懒混淆了概念，其实仔细一想，两边的数据没有确定的联系，所以要各算各的
//fastest里的数是走时间最短的路径得到的数据，shortest里的数是走距离最短的路径得到的数据
int main()
{
	memset(dis, 0x3f, 500 * 500 * sizeof(int));
	memset(mytime, 0x3f, 500 * 500 * sizeof(int));
	cin >> N >> M;
	int flag;
	int v1, v2;
	int d, t;
	for (int i = 0; i < M; i++) {
		cin >> v1 >> v2 >> flag >> d >> t;
		if (flag) {
			dis[v1][v2] = d;
			mytime[v1][v2] = t;
		}
		else {
			dis[v1][v2] = dis[v2][v1] = d;
			mytime[v1][v2] = mytime[v2][v1] = t;
		}
	}
	int source, des;
	cin >> source >> des;
	for (int i = 0; i < N; i++) {
		if (dis[source][i] != 0x3f3f3f3f) {
			d_pre[i] = source;
		}
		if (mytime[source][i] != 0x3f3f3f3f) {
			t_pre[i] = source;
		}
	}
	dijksra_t(source, des);
	dijksra_d(source, des);
	vector<int> dd;
	vector<int> tt;
	int begin = des;
	while (d_pre[begin] != source) {
		dd.push_back(d_pre[begin]);
		begin = d_pre[begin];
	}
	begin = des;
	while (t_pre[begin] != source) {
		tt.push_back(t_pre[begin]);
		begin = t_pre[begin];
	}
	int res = judge(dd, tt);

	if (!res) {
		cout << "Distance = " << shortest[des] << ": " << source;
		for (int i = dd.size() - 1; i >= 0; i--) {
			cout << " -> " << dd[i];
		}
		cout << " -> " << des << endl;
		cout << "Time = " << fastest[des] << ": " << source;
		for (int i = tt.size() - 1; i >= 0; i--) {
			cout << " -> " << tt[i];
		}
		cout << " -> " << des;
	}
	else {
		cout << "Distance = " << shortest[des] << "; ";
		cout << "Time = " << fastest[des] << ": " << source;
		for (int i = tt.size() - 1; i >= 0; i--) {
			cout << " -> " << tt[i];
		}
		cout << " -> " << des;
	}

	return 0;
}