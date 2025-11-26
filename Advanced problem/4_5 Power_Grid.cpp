#include <bits/stdc++.h>
using namespace std;

const int maxn = 500005;

vector<int> tree[maxn];
int subtreesize[maxn];
long long add[maxn];
long long val[maxn];

void dfssize(int u, int parent)
{
    subtreesize[u] = 1;
    for (int v : tree[u])
    {
        if (v == parent) continue;
        dfssize(v, u);
        subtreesize[u] += subtreesize[v];
    }
}

void dfssum(int u, int parent, long long curr)
{
    curr += add[u];
    val[u] = curr;
    for (int v : tree[u])
    {
        if (v == parent) continue;
        dfssum(v, u, curr);
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfssize(1, -1);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int x, c;
        cin >> x >> c;
        add[x] += c / subtreesize[x];
    }
    dfssum(1, -1, 0);
    
    for (int i = 1; i <= n; i++)
    {
        cout << val[i];
        if (i < n) cout << " ";
    }
    cout << endl;
    
    return 0;
}