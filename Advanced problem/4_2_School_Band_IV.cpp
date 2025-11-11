#include <bits/stdc++.h>
using namespace std;
const int MXN = 2e5 + 5;
vector<int> g[MXN];
int n, sz[MXN];
int bestnode, bestmaxsize;

void dfsize(int u, int pre) 
{
    sz[u] = 1;
    for (int v : g[u]) 
    {
        if (v == pre) continue;
        dfsize(v, u);
        sz[u] += sz[v];
    }
}

void dfscentroid(int u, int pre) 
{
    int maxc = n - sz[u]; 
    for (int v : g[u]) 
    {
        if (v == pre) continue;
        maxc = max(maxc, sz[v]);
    }
    if (maxc < bestmaxsize || (maxc == bestmaxsize && u < bestnode)) 
    {
        bestmaxsize = maxc;
        bestnode = u;
    }
    
    for (int v : g[u]) 
    {
        if (v == pre) continue;
        dfscentroid(v, u);
    }
}

int main() 
{   
    cin >> n;
    for (int i = 0; i < n - 1; i++) 
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfsize(1, -1);
    bestmaxsize = n;
    bestnode = n;
    dfscentroid(1, -1);
    cout << bestnode << endl ;
    return 0;
}