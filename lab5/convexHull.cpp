#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
    int x, y;
};

int orientation(Point p, Point q, Point r) {
    return (q.y - p.y) * (r.x - q.x) -
           (q.x - p.x) * (r.y - q.y);
}

vector<Point> convexHull(vector<Point>& points) {
    int n = points.size();
    if (n <= 1) return points;

    sort(points.begin(), points.end(), [](Point a, Point b) {
        if (a.x == b.x) return a.y < b.y;
        return a.x < b.x;
    });

    vector<Point> lower, upper;

    for (Point p : points) {
        while (lower.size() >= 2 &&
               orientation(lower[lower.size()-2],
                           lower[lower.size()-1], p) >= 0) {
            lower.pop_back();
        }
        lower.push_back(p);
    }

    for (int i = n - 1; i >= 0; i--) {
        Point p = points[i];
        while (upper.size() >= 2 &&
               orientation(upper[upper.size()-2],
                           upper[upper.size()-1], p) >= 0) {
            upper.pop_back();
        }
        upper.push_back(p);
    }

    lower.pop_back();
    upper.pop_back();

    lower.insert(lower.end(), upper.begin(), upper.end());

    return lower;
}

int main() {
    vector<Point> points = {
        {0,3}, {2,2}, {1,1}, {2,1},
        {3,0}, {0,0}, {3,3}
    };

    vector<Point> hull = convexHull(points);

    cout << "Convex Hull:\n";
    for (Point p : hull) {
        cout << p.x << " " << p.y << endl;
    }

    return 0;
}

