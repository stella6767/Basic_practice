#include <string>
#include <vector>
#include <queue>
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int N, M, S, D, from, to, w;
vector<pair<int, int> > v[1001];
priority_queue<pair<int, int> > pq;
bool visited[1001];
int dis[1001];
int INF = 1000000000; //크기가 1000 X 100000은 되어야함
int map[1001][1001];

void dijkstra() {
	dis[S] = 0;
	pq.push(make_pair(0, S));
	while (!pq.empty()) {
		int current = pq.top().second;
		int value = -pq.top().first;
		pq.pop();
		if (visited[current] == false) {
			visited[current] = true;
			for (int i = 0; i < v[current].size(); i++) {
				if (dis[v[current][i].first] > value + v[current][i].second) {
					dis[v[current][i].first] = value + v[current][i].second;
					pq.push(make_pair(-dis[v[current][i].first], v[current][i].first));
				}
			}
		}

	}
}
int main(void) {
	for (int i = 1; i < 1001; i++) {
		for (int j = 1; j < 1001; j++) {
			map[i][j] = 100000;
		}
	}
	cin >> N;
	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> from >> to >> w;
		map[from][to] = min(map[from][to], w);
	}

	for (int i = 0; i < 1001; i++) {
		for (int j = 0; j < 1001; j++) {
			if (map[i][j] < 100000) {
				v[i].push_back(make_pair(j, map[i][j]));
			}
		}
	}
	cin >> S >> D;  //출발점과 도착점
	for (int i = 0; i < N; i++) {
		dis[i + 1] = INF;
	}
	dijkstra();
	cout << dis[D];
}