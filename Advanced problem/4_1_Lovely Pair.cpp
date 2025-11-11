#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    int n;
    cin >> n;
    
    vector<int> degree(n + 1, 0);
    
    for (int i = 0; i < n - 1; i++) 
    {
        int a, b;
        cin >> a >> b;
        degree[a]++;
        degree[b]++;
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) 
    {
        if (degree[i] >= 2) 
        {
            long long d = degree[i];
            ans += d * (d - 1) / 2;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}