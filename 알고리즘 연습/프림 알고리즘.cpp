#include <iostream>
#include <vector>

using namespace std;

const int MAX_V = 100;  //���������� ����
const int INF = 987654321;

int V = 6;//6���� ����

vector<pair<int, int> > adj[MAX_V];

int prim(vector<pair<int, int> >& selected) { //������ ����
	selected.clear();

	vector<bool> added(V, false);
	vector<int> minWeight(V, INF), parent(V, -1);

	int ret = 0;
	minWeight[0] = parent[0] = 0;
	for (int iter = 0; iter < V; iter++) { //6���� 
		int u = -1;
		for (int v = 0; v < V; v++) {
			if (!added[v] && (u == -1 || minWeight[u] > minWeight[v]))
				u = v;
		}

		if (parent[u] != u) //�θ� ���� �ʴٸ�
			selected.push_back(make_pair(parent[u], u));

		ret += minWeight[u];
		added[u] = true;

		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i].first, weight = adj[u][i].second;
			if (!added[v] && minWeight[v] > weight) { //�ߺ��� ���� ������ ������ ���� ���� ����ġ�� ���� ������ 
				parent[v] = u;
				minWeight[v] = weight;
			}
		}
	}
	return ret; //�ּ� ���д� Ʈ���� ��� ������ ��
}

int main() {
	adj[0].push_back(make_pair(1, 5));
	adj[1].push_back(make_pair(0, 5));

	adj[1].push_back(make_pair(2, 3));
	adj[2].push_back(make_pair(1, 3));

	adj[2].push_back(make_pair(3, 4));
	adj[3].push_back(make_pair(2, 4));

	adj[1].push_back(make_pair(4, 3));
	adj[4].push_back(make_pair(1, 3));

	adj[0].push_back(make_pair(3, 7));
	adj[3].push_back(make_pair(0, 7));

	adj[2].push_back(make_pair(4, 2));
	adj[4].push_back(make_pair(2, 2));

	adj[3].push_back(make_pair(5, 1));
	adj[5].push_back(make_pair(3, 1));

	adj[4].push_back(make_pair(5, 4));
	adj[5].push_back(make_pair(4, 4));

	vector<pair<int, int> > selected; //�츮�� ������ ������ ���������� ����
	int mst = prim(selected);
	printf("mst:%d\n", mst);
	for (int i = 0; i < selected.size(); i++) {
		printf("%d-%d\n", selected[i].first, selected[i].second);
	}
	printf("\n");
}