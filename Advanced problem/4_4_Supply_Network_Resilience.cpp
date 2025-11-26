#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int maxn = 100005;
vector<int> graph[maxn];
int x[maxn];
long long dp[maxn][2];

void dfs(int u, int parent)
{
    if (x[u] == 0)
    {
        dp[u][0] = 1;
        dp[u][1] = 0;
    }
    else
    {
        dp[u][0] = 0;
        dp[u][1] = 1;
    }

    for (int v : graph[u])
    {
        if (v == parent) continue;
        dfs(v, u);

        long long dp0 = 0, dp1 = 0;
        dp0 = (dp0 + dp[u][0] * dp[v][0]) % mod;
        dp1 = (dp1 + dp[u][0] * dp[v][1] + dp[u][1] * dp[v][0]) % mod;
        dp0 = (dp0 + dp[u][0] * dp[v][1]) % mod;
        dp1 = (dp1 + dp[u][1] * dp[v][1]) % mod;
        dp[u][0] = dp0;
        dp[u][1] = dp1;
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int p;
        cin >> p;
        graph[p].push_back(i);
        graph[i].push_back(p);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    dfs(0, -1);
    cout << dp[0][1] << endl;
    return 0;
}