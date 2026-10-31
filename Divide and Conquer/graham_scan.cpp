#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point{
    int x, y;
};

Point pivot;

// Returns:
//  1  -> left turn / counterclockwise
// -1  -> right turn / clockwise
//  0  -> collinear
int orientation(Point A, Point B, Point C){
    long long value = (long long)(B.x - A.x) * (C.y - A.y) - (long long)(B.y - A.y) * (C.x - A.x);
    if(value > 0)
        return 1;
    if(value < 0)
        return -1;
    return 0;
}

// Squared distance between two points
long long dist(Point A, Point B) {
    long long dx = B.x - A.x;
    long long dy = B.y - A.y;
    return dx * dx + dy * dy;
}

// Compare points based on their angle from the pivot
bool comparePoints(Point A, Point B){
    int turn = orientation(pivot, A, B);
    // Same angle
    if (turn == 0)
        return dist(pivot, A) < dist(pivot, B);
    // Counterclockwise order
    return turn > 0;
}


void grahamScan(vector<Point> points){
    int n = points.size();
    // At least 3 points are required
    if(n < 3){
        cout << "Convex hull is not possible." << endl;
        return;
    }
    int lowest = 0;
    for (int i = 1; i<n; i++){
        if(points[i].y < points[lowest].y || (points[i].y == points[lowest].y && points[i].x < points[lowest].x)){
            lowest = i;
        }
    }
    // Put pivot at index 0
    swap(points[0], points[lowest]);
    pivot = points[0];
    sort(points.begin() + 1, points.end(), comparePoints);
    vector<Point> filtered;
    // Pivot is always included
    filtered.push_back(points[0]);
    for(int i = 1; i<n; i++){
        // Skip points having the same angle
        // Keep the farthest point
        while(i < n - 1 && orientation(pivot, points[i],points[i + 1]) == 0){
            i++;
        }
        filtered.push_back(points[i]);
    }

    if(filtered.size()<3){
        cout << "Convex hull is not possible." << endl;
        return;
    }

    vector<Point> hull;
    // First three points
    hull.push_back(filtered[0]);
    hull.push_back(filtered[1]);
    hull.push_back(filtered[2]);

    // Process remaining points
    for(int i = 3; i<filtered.size(); i++){
        // Remove points that make a right turn
        // or are collinear
        while(hull.size() >= 2 && orientation(hull[hull.size() - 2], hull[hull.size() - 1],filtered[i]) <= 0){
            hull.pop_back();
        }
        // Add current point
        hull.push_back(filtered[i]);
    }

    cout << "Convex Hull Points:" << endl;

    for(Point P : hull){
        cout << "("<< P.x << ", "<< P.y << ")" << endl;
    }

}

int main(){

    vector<Point> points = {
        {0, 3},
        {1, 1},
        {2, 2},
        {4, 4},
        {0, 0},
        {1, 2},
        {3, 1},
        {3, 3}
    };

    grahamScan(points);

    return 0;
}