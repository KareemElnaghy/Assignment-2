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
    
~Point()           //destructor
{
}

    void setX(float i);             //prototypes for setters and getters

    float getX() const;

    void setY(float j);

    float getY() const;

    void displayPoint() const;      //prototype for display point function

    float distance(const Point &P) const;   //prototype for distance function
};

#endif /* Point_h */
