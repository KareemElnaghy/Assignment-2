//
//  Point.h
//  Assignment 2
//
//  Created by Kareem Elnaghy on 2/27/23.
// 900223587

#ifndef Point_h
#define Point_h


class Point {
    float x;
    float y;

public:             //Prototyping
    Point();       //default constructor
    
    Point(float , float );      //parameterized constructor
    
    ~Point();          //destructor

    void setX(float );             //prototypes for setters and getters

    float getX() const;

    void setY(float );

    float getY() const;

    void displayPoint() const;      //prototype for display point function

    float distance(const Point & ) const;   //prototype for distance function
};

Point Center(Point *, int );              //Function prototypes
void closer_Cluster(Point *, Point *, const Point &);
void GenerateA(Point *, int );
void GenerateB(Point *, int );
void GenerateP(Point *, int );

#endif /* Point_h */
