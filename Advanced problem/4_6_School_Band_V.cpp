#include <bits/stdc++.h>
using namespace std;

const int MXN = 105;
const int MOD = 1e9 + 7;

int n, m, k;

struct Matrix
{
    long long mat[MXN][MXN];
    
    Matrix()
    {
        memset(mat, 0, sizeof(mat));
    }
};

Matrix mul(Matrix a, Matrix b)
{
    Matrix res;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            long long sum = 0;
            for (int t = 0; t < n; t++)
            {
                sum = (sum + a.mat[i][t] * b.mat[t][j]) % MOD;
            }
            res.mat[i][j] = sum;
        }
    }
    return res;
}

Matrix fpow(Matrix a, int power)
{
    Matrix res;
    for (int i = 0; i < n; i++)
    {
        res.mat[i][i] = 1;
    }
    
    while (power > 0)
    {
        if (power & 1)
        {
            res = mul(res, a);
        }
        a = mul(a, a);
        power >>= 1;
    }
    return res;
}

int main()
{
    cin >>n >> m>> k;
    
    Matrix adj;
    
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj.mat[u][v] = (adj.mat[u][v] + 1) % MOD;
    }
    
    Matrix result = fpow(adj, k);
    
    cout << result.mat[0][n-1] << endl;
    
    return 0;
}