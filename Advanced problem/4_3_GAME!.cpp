#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;
const int maxn = 100005;

vector<int> graph[maxn];
int indeg[maxn];
long long dp[maxn];

int main()
{
    int n,m;
    cin >>n>>m;
    
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        indeg[b]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (indeg[i] == 0)
        {
            q.push(i);
        }
    }
    
    dp[1] = 1;
    
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        
        for (int v : graph[u])
        {
            dp[v] = (dp[v] + dp[u]) % mod;
            indeg[v]--;
            if (indeg[v] == 0)
            {
                q.push(v);
            }
        }
    }
    cout << dp[n] << endl;
    return 0;
}