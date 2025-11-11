#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
using namespace std;
int main() 
{
    int n, m;
    cin >> n >> m;
    map<string, vector<string>> graph;
    for (int i = 0; i < m; i++) 
    {
        string u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) 
    {
        string x, y;
        cin >> x >> y;
        if (x == y) 
        {
            cout << 1 << endl;
            continue;
        }
        if (graph.find(x) == graph.end() || graph.find(y) == graph.end()) 
        {
            cout << -1 << endl;
            continue;
        }
        map<string, int> dist;
        queue<string> q_bfs;
        dist[x] = 1;
        q_bfs.push(x);
        bool found = false;
        while (!q_bfs.empty()) 
        {
            string current = q_bfs.front();
            q_bfs.pop();
            
            if (current == y) 
            {
                cout << dist[current] << endl;
                found = true;
                break;
            }
            for (string neighbor : graph[current]) 
            {
                if (dist.find(neighbor) == dist.end()) 
                {
                    dist[neighbor] = dist[current] + 1;
                    q_bfs.push(neighbor);
                }
            }
        }
        if (!found) 
        {
            cout << -1 << endl;
        }
    }
    
    return 0;
}