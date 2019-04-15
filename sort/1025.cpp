#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct stu {
	string no;
	int grade;
	int final_rank;
	int location;
	int local_rank;
};

bool comp(stu a, stu b) {
	if (a.grade > b.grade)
		return true;
	else if (a.grade == b.grade)
		return a.no < b.no;
	else
		return false;
}

int main()
{
	int N;
	cin >> N;
	vector<stu> ranking;
	int sum = 0; 
	for (int i = 0; i < N; i++) {
		int K;
		cin >> K;
		sum += K;
		stu *local = new stu[K]();
		for (int j = 0; j < K; j++) {
			cin >> local[j].no >> local[j].grade;
			local[j].location = i + 1;
		}
		sort(local, &local[K], comp);
		int tmp = 1;
		local[0].local_rank = 1;
		for (int j = 1; j < K; j++) {
			if (local[j].grade == local[j - 1].grade) {
				local[j].local_rank = tmp;
			}
			else {
				local[j].local_rank = j + 1;
				tmp = j + 1;
			}
		}
		ranking.insert(ranking.end(), local, local + K);
		delete[]local;
	}

	sort(ranking.begin(), ranking.end(), comp);
	int tmp2 = 1;
	ranking[0].final_rank = 1;
	for (int j = 1; j < sum; j++) {
		if (ranking[j].grade == ranking[j - 1].grade) {
			ranking[j].final_rank = tmp2;
		}
		else {
			ranking[j].final_rank = j + 1;
			tmp2 = j + 1;
		}
	}
	cout << sum << endl;
	for (int i = 0; i < sum; i++) {
		cout << ranking[i].no << " " << ranking[i].final_rank << " " << ranking[i].location << " " << ranking[i].local_rank << endl;
	}
	return 0;
}