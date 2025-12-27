#include <bits/stdc++.h>
using namespace std;

const int MAXN = 305;
const int INF = INT_MAX;

vector<int> adj[MAXN];
int cap[MAXN][MAXN] = {0};
int parent[MAXN];

int bfs(int s, int t, int n)
{
    fill(parent, parent + n + 1, -1);
    queue<pair<int, int>> q;
    q.push({s, INF});
    parent[s] = s;
    
    while (!q.empty())
    {
        int u = q.front().first;
        int flow = q.front().second;
        q.pop();
        
        for (int v : adj[u])
        {
            if (parent[v] == -1 && cap[u][v] > 0)
            {
                parent[v] = u;
                int new_flow = min(flow, cap[u][v]);
                if (v == t)
                {
                    return new_flow;
                }
                q.push({v, new_flow});
            }
        }
    }
    return 0;
}

int edmondskarp(int s, int t, int n)
{
    int maxflow = 0;
    int newflow;
    
    while ((newflow = bfs(s, t, n)) > 0)
    {
        maxflow += newflow;
        int v = t;
        while (v != s)
        {
            int u = parent[v];
            cap[u][v] -= newflow;
            cap[v][u] += newflow;
            v = u;
        }
    }
    return maxflow;
}

int main()
{
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        if (cap[u][v] == 0)
        {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        cap[u][v] += w;
    }
    
    int ans = edmondskarp(1, n, n);
    cout << ans << endl;
    
    return 0;
}