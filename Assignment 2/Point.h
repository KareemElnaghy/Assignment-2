//
//  Point.h
//  Assignment 2
//
//  Created by Kareem Elnaghy on 2/27/23.
//

#ifndef Point_h
#define Point_h

#include <cmath>
#include <iostream>
using namespace std;

class Point {
    float x;
    float y;

public:
    Point() {
        x = 0;
        y = 0;
    }

    Point(float a, float b) {
        x = a;
        y = b;
    }

    void setX(float i) {
        x = i;
    }

    float getX() const {
        return x;
    }

    void setY(float j) {
        y = j;
    }

    float getY() const {
        return y;
    }

    void displayPoint() const {
        cout << "(" << x << "," << y << ")";
    }

    float distance(const Point &P) const {
        float dist = sqrt(pow(x - P.getX(), 2) + pow(y - P.getY(), 2));
        return dist;
    }
};

#endif /* Point_h */
