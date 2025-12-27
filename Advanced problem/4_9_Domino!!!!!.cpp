#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

vector<int> graph[MAXN];
vector<int> revgraph[MAXN];
bool visited[MAXN];
vector<int> order;
int comp[MAXN];
int compcount = 0;

void dfs1(int u)
{
    visited[u] = true;
    for (int v : graph[u])
    {
        if (!visited[v])
        {
            dfs1(v);
        }
    }
    order.push_back(u);
}

void dfs2(int u, int id)
{
    visited[u] = true;
    comp[u] = id;
    for (int v : revgraph[u])
    {
        if (!visited[v])
        {
            dfs2(v, id);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--; y--;
        graph[x].push_back(y);
        revgraph[y].push_back(x);
    }
    
    // First pass: order by finish time
    fill(visited, visited + n, false);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs1(i);
        }
    }
    
    // Second pass: find SCCs
    fill(visited, visited + n, false);
    reverse(order.begin(), order.end());
    
    for (int u : order)
    {
        if (!visited[u])
        {
            dfs2(u, compcount);
            compcount++;
        }
    }
    
    // Count indegree of each SCC
    vector<int> indegree(compcount, 0);
    
    for (int u = 0; u < n; u++)
    {
        for (int v : graph[u])
        {
            if (comp[u] != comp[v])
            {
                indegree[comp[v]]++;
            }
        }
    }
    
    int ans = 0;
    for (int i = 0; i < compcount; i++)
    {
        if (indegree[i] == 0)
        {
            ans++;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}