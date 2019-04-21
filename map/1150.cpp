#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

int N, M;
int graph[201][201];
int visited[201];
char desc[3][40] = { "TS simple cycle", "TS cycle", "Not a TS cycle" };

int main()
{
	cin >> N >> M;
	int x, y, dis;
	for (int i = 0; i < M; i++) {
		cin >> x >> y >> dis;
		graph[x][y] = graph[y][x] = dis;
	}
	int K;
	cin >> K;
	int num, start, last, city;
	int total;
	int min_total = 0x3f3f3f3f;
	int min_path = -1;
	int is_cycle;
	int is_simple;
	int is_na;
	for (int i = 1; i <= K; i++) {
		memset(visited, 0, 201 * sizeof(int));
		is_cycle = 1;
		is_simple = 1;
		is_na = 0;
		total = 0;
		cin >> num;
		if (num > 0){
			cin >> start;
			//visited[start] = 1;
			last = start;
		}
		for (int j = 1; j < num; j++) {
			cin >> city;
			if (graph[last][city]) {
				total += graph[last][city];
				last = city;
				if (!visited[city]) {
					visited[city] = 1;
				}
				else {
					is_simple = 0;
				}
			}
			else {
				is_na = 1;
			}
		}
		for (int i = 1; i <= N; i++) {
			if (!visited[i]) {
				is_cycle = 0;
				break;
			}
		}
		if (city != start) {
			is_cycle = 0;
		}
		if (!is_na && is_cycle && total < min_total) {
			min_total = total;
			min_path = i;
		}
		if (is_na) {
			printf("Path %d: NA (%s)\n", i, desc[2]);
		}
		else if (!is_cycle) {
			printf("Path %d: %d (%s)\n", i, total, desc[2]);
		}
		else if (is_cycle && !is_simple) {
			printf("Path %d: %d (%s)\n", i, total, desc[1]);
		}
		else {
			printf("Path %d: %d (%s)\n", i, total, desc[0]);
		}
	}
	printf("Shortest Dist(%d) = %d\n", min_path, min_total);
	return 0;
}