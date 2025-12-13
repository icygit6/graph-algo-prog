#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct point
{
    ll x, y;
    int id;
};

bool compareX(const point& a, const point& b)
{
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

bool compareY(const point& a, const point& b)
{
    if (a.y != b.y) return a.y < b.y;
    return a.x < b.x;
}

ll dist2(const point& a, const point& b)
{
    ll dx = a.x - b.x;
    ll dy = a.y - b.y;
    return dx * dx + dy * dy;
}

ll closestpair(vector<point>& points, int l, int r)
{
    if (r - l <= 3)
    {
        ll mindist = LLONG_MAX;
        for (int i = l; i <= r; i++)
        {
            for (int j = i + 1; j <= r; j++)
            {
                mindist = min(mindist, dist2(points[i], points[j]));
            }
        }
        return mindist;
    }
    
    int mid = (l + r) / 2;
    ll ldist = closestpair(points, l, mid);
    ll rdist = closestpair(points, mid + 1, r);
    ll d = min(ldist, rdist);
    
    // Collect points in strip
    vector<point> strip;
    for (int i = l; i <= r; i++)
    {
        ll dx = points[i].x - points[mid].x;
        if (dx * dx < d)
        {
            strip.push_back(points[i]);
        }
    }
    
    // Sort strip by y
    sort(strip.begin(), strip.end(), compareY);
    
    // Check points in strip
    for (size_t i = 0; i < strip.size(); i++)
    {
        for (size_t j = i + 1; j < strip.size() && (strip[j].y - strip[i].y)*(strip[j].y - strip[i].y) < d; j++)
        {
            d = min(d, dist2(strip[i], strip[j]));
        }
    }
    
    return d;
}

int main()
{
    
    int n;
    cin >> n;
    
    vector<point> points(n);
    for (int i = 0; i < n; i++)
    {
        cin >> points[i].x >> points[i].y;
        points[i].id = i;
    }
    
    sort(points.begin(), points.end(), compareX);
    
    ll ans = closestpair(points, 0, n - 1);
    
    cout << ans << endl;
    
    return 0;
}