#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct Point{
    int x;
    int y;
};

int side(Point A,Point B,Point P){
    return (B.x - A.x) * (P.y - A.y) - (B.y - A.y) * (P.x - A.x);
}

int distanceFromLine(Point A,Point B,Point P){
    return abs(side(A,B,P));
}

void findHull(vector<Point> points,Point A,Point B){
    if(points.empty()){
        return;
    }
    int farthest = 0;
    for(int i = 1; i<points.size(); i++){
        if(distanceFromLine(A,B,points[i]) > distanceFromLine(A,B,points[farthest])){
            farthest = i;
        }
    }
    Point C = points[farthest];
    cout << "( " << C.x << ", " << C.y << " )" << endl;

    vector<Point> set1;
    vector<Point> set2;
    for(Point P : points){
        if(P.x == C.x && P.y == C.y){
            continue;
        }
        if(side(A,C,P) > 0){
            set1.push_back(P);
        }
        else if(side(C,B,P) > 0){
            set2.push_back(P);
        }
    }
    findHull(set1,A,C);
    findHull(set2,C,B);
}

void quickHull(vector<Point> points){
    int n = points.size();
    if(n < 3){
        cout << "At least 3 points required." << endl;
        return;
    }
    Point left = points[0];
    Point right = points[0];
    for(Point P : points){
        if(P.x < left.x){
            left = P;
        }
        if(P.x > right.x){
            right = P;
        }
    }
    vector<Point> upper;
    vector<Point> lower;
    for(Point P : points){
        int value = side(left,right,P);
        if(value > 0){
            upper.push_back(P);
        }
        else if(value < 0){
            lower.push_back(P);
        }
    }
    cout << "Convex Hull Points: " << endl;
    cout << "( " << left.x << ", " << left.y << " )" << endl;
    cout << "( " << right.x << ", " << right.y << " )" << endl;
    findHull(upper,left,right);
    findHull(lower,right,left);
}

int main(){

    vector <Point > points = {{0, 3},{1, 1}, {2, 2}, {4, 4}, {0, 0}, {1, 2},{3, 1},{3, 3}};
    quickHull(points);
    
    return 0;
}