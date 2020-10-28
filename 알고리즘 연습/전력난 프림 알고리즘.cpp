#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>

#define endl "\n"
#define MAX 200010
using namespace std;

int M, N, Total, Result, Answer;
bool Visit[MAX];
bool Inp_Flag;
vector<pair<int, int>> Node[MAX];
//�ִ��뿡�� �ּҺ���� ���� ����// �ִ� ���� ����ġ���� �ּҰ�������ġ�� ���� ������ �� �ִ� �ִ밣������ġ
void Initialize()
{
    Total = Result = 0;
    for (int i = 0; i < MAX; i++)
    {
        Visit[i] = false;
        Node[i].clear();
    }
}

void Input()
{
    cin >> M >> N;
    if (M == 0 && N == 0)
    {
        Inp_Flag = true;
        return;
    }
    for (int i = 0; i < N; i++)
    {
        int a, b, c; cin >> a >> b >> c;
        Node[a].push_back(make_pair(b, c)); //c�� a�� b������ �Ÿ� c�� cost
        Node[b].push_back(make_pair(a, c));
        Total = Total + c; //��� ���� ����ġ�� ��
    }
}

void Solution()
{
    priority_queue<pair<int, int>> PQ;
    for (int i = 0; i < Node[0].size(); i++)
    {
        int Next = Node[0][i].first;
        int Cost = Node[0][i].second;
        PQ.push(make_pair(-Cost, Next));
    }

    Visit[0] = true;
    while (PQ.empty() == 0)
    {
        int Cost = -PQ.top().first;
        int Cur = PQ.top().second;
        PQ.pop();

        if (Visit[Cur] == false)
        {
            Visit[Cur] = true;
            Result = Result + Cost;

            for (int i = 0; i < Node[Cur].size(); i++)
            {
                int Next = Node[Cur][i].first;
                int nCost = Node[Cur][i].second;

                if (Visit[Next] == false) PQ.push(make_pair(-nCost, Next)); //�� ����� �ϱ� ����
            }
        }
    }
    Answer = Total - Result;
}

void Solve()
{
    while (1)
    {
        Initialize();
        Input();
        if (Inp_Flag == true) return;
        Solution();
        cout << Answer << endl;
    }
}

int main(void)
{
    ios::sync_with_stdio(false); //cin,cout ����ȭ
    cin.tie(NULL);
    cout.tie(NULL);

    //freopen("Input.txt", "r", stdin);
    Solve();

    return 0;
}


//��ó: https://yabmoons.tistory.com/402 [�幮's Coding World..]
//Priority_Queue<pair<int, int>> �� ������ ���
//
//���ο����� "���� Ŭ ���� �켱������ ����" ��� �Ǵ��Ͽ���, �� ū ���ϼ��� �տ� ������(���Լ���) ���õȴ�.
//��, 1�������� ����� �������� ���̰�{ 2, 3, 5 } ��� ���� ��, MST�� ������ �ϴ� �츮 ���忡���� '2'�� ����
//
//�켱������ �����ؾ� �ϴµ�, ������ ������ ���{ 5, 3, 2 } ������ �켱������ ������ �ȴ�.
//
//���� ���� ������ �ٲ������ν� ũ�⸦ �ٲ��� ������ ���̴�.
//
//�ٽ� �� ���� ���� ����� ������ - ���� �ٿ��� ����� ���ָ� �ȴ�.


