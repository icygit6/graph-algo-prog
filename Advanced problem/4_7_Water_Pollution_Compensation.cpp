#include <bits/stdc++.h>
using namespace std;

struct point
{
    long long x, y;
    
    bool operator<(const point& other) const
    {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
    
    point operator-(const point& other) const
    {
        return {x - other.x, y - other.y};
    }
};

long long cross(const point& a, const point& b)
{
    return a.x * b.y - a.y * b.x;
}

long long cross(const point& a, const point& b, const point& c)
{
    return cross(b - a, c - a);
}

vector<point> conhull(vector<point>& points)
{
    int n = points.size();
    if (n <= 1) return points;
    
    sort(points.begin(), points.end());
    
    vector<point> hull;
    
    // Lower hull
    for (int i = 0; i < n; i++)
    {
        while (hull.size() >= 2 && cross(hull[hull.size()-2], hull.back(), points[i]) <= 0)
        {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }
    
    // Upper hull
    int lowers = hull.size();
    for (int i = n - 2; i >= 0; i--)
    {
        while (hull.size() > lowers && cross(hull[hull.size()-2], hull.back(), points[i]) <= 0)
        {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }
    
    hull.pop_back(); // Remove duplicate start point
    return hull;
}

double polyarea(const vector<point>& poly)
{
    int n = poly.size();
    if (n < 3) return 0.0;
    
    long long area = 0;
    for (int i = 0; i < n; i++)
    {
        int j = (i + 1) % n;
        area += poly[i].x * poly[j].y - poly[j].x * poly[i].y;
    }
    
    return abs(area) / 2.0;
}

int main()
{
    int n;
    cin >> n;
    
    vector<point> points(n);
    for (int i = 0; i < n; i++)
    {
        cin >> points[i].x >> points[i].y;
    }
    
    vector<point> hull = conhull(points);
    double area = polyarea(hull);
    
    cout << fixed << setprecision(3) << area << endl;
    
    return 0;
}