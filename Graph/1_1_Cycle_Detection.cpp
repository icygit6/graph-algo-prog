#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int maxn = 100005;
vector<int> adj[maxn];
int parent[maxn];
bool visit[maxn];

int main() 
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) 
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    if (m == n - 1) 
    {
        cout << "There is no cycle." << endl;
        return 0;
    }

    queue<int> q;
    q.push(1);
    visit[1] = true;
    parent[1] = -1;

    int extra = -1, extraV = -1;

    while (!q.empty() && extra == -1) 
    {
        int u = q.front(); 
        q.pop();

        for (int v : adj[u]) 
        {
            if (!visit[v]) 
            {
                visit[v] = true;
                parent[v] = u;
                q.push(v);
            } 
            else if (v != parent[u]) 
            {
                extra = u;
                extraV = v;
                break;
            }
        }
    }

    if (extra == -1) 
    {
        cout << "There is no cycle." << endl;
        return 0;
    }
    vector<bool> mark(n + 1, false);
    int a = extra;
    while (a != -1) 
    {
        mark[a] = true;
        a = parent[a];
    }

    int cycle = 0;
    int b = extraV;
    while (!mark[b]) 
    {
        cycle++;
        b = parent[b];
    }

    int meet = b;
    a = extra;
    while (a != meet) 
    {
        cycle++;
        a = parent[a];
    }
    cycle++;
    cout << cycle << endl;
    return 0;
}
