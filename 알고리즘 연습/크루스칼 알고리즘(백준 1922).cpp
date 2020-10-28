#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


// �θ� ���(�� ���� ������ ���)�� ������ 
int getParent(int set[], int x) {
	if (set[x] == x) return x;
	return set[x] = getParent(set, set[x]);
}

// �θ� ��带 ���� 
void unionParent(int set[], int a, int b) {
	a = getParent(set, a);
	b = getParent(set, b);
	// �� ���ڰ� ���� �θ�� ���� (1�ϰ� 7�� ����������� 1�� 7�� �θ���)
	if (a < b) set[b] = a;
	else set[a] = b;
}

// ���� �θ� �������� Ȯ��
int find(int set[], int a, int b) {
	a = getParent(set, a);
	b = getParent(set, b);
	if (a == b) return 1;
	else return 0;
}

// ���� Ŭ���� ���� 
class Edge {
public:
	int node[2];
	int distance;
	Edge(int a, int b, int distance) {
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}
	bool operator <(Edge& edge) { //sort �Լ� ����
		return this->distance < edge.distance;
	}
};

int main(void) {
	
	int n, m;
	
	int a, b, c;

	cin >> n >> m;


	vector<Edge> v;

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		v.push_back(Edge(a,b,c));
		
		if (i == m - 1) cout << "0 0"<<endl;
	}



	// ������ ������� �������� ���� 
	sort(v.begin(), v.end());
	//���� �Ÿ�����ġ���� ���� ���۵Ǵϱ� ���߿� �ߺ��Ǵ� �������� �ѱ�� �� ������ �� ��������ġ���� ū ��.
	//���� ���߿� �ּҽ���Ʈ�� ����⿡ ���� 

	int* set = new int[n]; //�迭 �����Ҵ�
	for (int i = 0; i < n; i++) {
		set[i] = i; //�ϴ� ������ �θ���� ���ڳ��� ���Ѵ�.
	}

	// �Ÿ��� ���� 0���� �ʱ�ȭ 
	int sum = 0;
	int max = 0;

	for (int i = 0; i < v.size(); i++) {
		// ������ �θ� ����Ű�� �ʴ� ���, �� ����Ŭ�� �߻����� ���� ���� ���� 
		if (!find(set, v[i].node[0] , v[i].node[1])) {	
			sum += v[i].distance;
			unionParent(set, v[i].node[0] , v[i].node[1] );
			
		}
	}

	printf("%d\n", max-sum); 


	delete[] set;
}