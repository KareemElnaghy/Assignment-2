//
//  Point.h
//  Assignment 2
//
//  Created by Kareem Elnaghy on 2/27/23.
// 900223587

#ifndef Point_h
#define Point_h

#include <cmath>
#include <iostream>
using namespace std;

class Point {
    float x;
    float y;

public:
    Point() {       //default constructor
        x = 0;
        y = 0;
    }

    Point(float a, float b) {       //parameterized constructor
        x = a;
        y = b;
    }

    void setX(float i) {            //setter for x coordinate
        x = i;
    }

    float getX() const {            //getter for x coordinate
        return x;
    }

    void setY(float j) {            //setter for y coordinate
        y = j;
    }

    float getY() const {            //getter for y coordinate
        return y;
    }

    void displayPoint() const;      //prototype for display point function

    float distance(const Point &P) const;   //prototype for distance function
};

#endif /* Point_h */
