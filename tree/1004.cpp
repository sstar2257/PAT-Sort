#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX_SIZE 100
struct PTNode
{
	int num;//num of children
	int parent;//no of parent
	int generation;
}pTree[MAX_SIZE];

int main()
{	
	pTree[1].parent = -1;
	pTree[1].generation = 1;
	vector<int> old,young;
	int N,M;
	cin >> N;
	if(N==0)
		return 0;
	cin >> M;
	int id, num, child;
	for(int i=0;i<M;i++){
		cin >> id;
		cin >> num;
		pTree[id].num = num;
		for(int j=0;j<num;j++){
			cin >> child;
			pTree[child].parent = id;
		}
	}
	young.push_back(1);
	int generation = 1;
	do{
		old = young;
		young.clear();
		for(int i=1;i<=N;i++){
			if(find(old.begin(), old.end(), pTree[i].parent) != old.end()){
				young.push_back(i);
				pTree[i].generation = generation + 1;
			}
		}
		generation++;
	}while(young.size() != 0);

	int count;
	for(int i=1;i<generation;i++){
		count = 0;
		for(int j=1;j<=N;j++){
			if(pTree[j].generation == i){
				if(pTree[j].num == 0){
					count++;
				}
			}
		}
		cout << count << (i==(generation-1)?"":" ");
	}
	return 0;
}