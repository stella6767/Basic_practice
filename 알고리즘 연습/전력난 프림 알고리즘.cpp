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
//최대비용에서 최소비용을 빼는 문제// 최대 간선 가중치에서 최소간선가중치를 빼면 절약할 수 있는 최대간선가중치
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
        Node[a].push_back(make_pair(b, c)); //c는 a와 b사이의 거리 c는 cost
        Node[b].push_back(make_pair(a, c));
        Total = Total + c; //모든 간선 가중치의 합
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

                if (Visit[Next] == false) PQ.push(make_pair(-nCost, Next)); //안 끊기게 하기 위해
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
    ios::sync_with_stdio(false); //cin,cout 최적화
    cin.tie(NULL);
    cout.tie(NULL);

    //freopen("Input.txt", "r", stdin);
    Solve();

    return 0;
}


//출처: https://yabmoons.tistory.com/402 [얍문's Coding World..]
//Priority_Queue<pair<int, int>> 로 선언할 경우
//
//내부에서는 "값이 클 수록 우선순위가 높다" 라고 판단하여서, 더 큰 값일수록 앞에 오도록(선입선출) 세팅된다.
//즉, 1번정점과 연결된 간선들의 길이가{ 2, 3, 5 } 라고 했을 때, MST를 만들어야 하는 우리 입장에서는 '2'를 가장
//
//우선적으로 선택해야 하는데, 저렇게 선언할 경우{ 5, 3, 2 } 순으로 우선순위를 가지게 된다.
//
//따라서 값을 음수로 바꿔줌으로써 크기를 바꿔줘 버리는 것이다.
//
//다시 그 값을 빼서 계산할 때에는 - 값을 붙여서 계산을 해주면 된다.


