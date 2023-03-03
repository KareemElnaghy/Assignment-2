//
//  main.cpp
//  Assignment 2
//
//  Created by Kareem Elnaghy on 2/27/23.
//  900223587


#include <iostream>
#include "Point.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


const int N = 200;      //declare the number of points to be created for both clusters
const int M = 20;       //declare the number of points to be created

Point Center(Point *C, int N);              //Function prototypes
void closer_Cluster(Point *A, Point *B, const Point &P);
void GenerateA(Point *A, int N);
void GenerateB(Point *B, int N);
void GenerateP(Point *p, int M);

int main()                  //main function
{
    Point *A = new Point[N];         //declare pointers that point to new array objects of type Point
    Point *B = new Point[N];
    Point *P = new Point[M];

    GenerateA(A, N);    //call function that fills cluster A, B and points P randomly
    GenerateB(B, N);
    GenerateP(P, M);

    Point centerA = Center(A, N);
    Point centerB = Center(B, N);
    
    cout<<"Center of Cluster A: ";centerA.displayPoint();cout<<endl;
    cout<<"Center of Cluster B: ";centerB.displayPoint();cout<<endl<<endl;
    
    for (int i = 0; i < M; i++)
    {
        closer_Cluster(A, B, *(P+i));    //function call to determine which cluster point P in each index is closer to
    }

}

Point Center(Point *C, int N) {       //Function to determine the center of the array of type Point
    float averageX = 0;
    float averageY = 0;
    float sumX = 0;
    float sumY =0;

    for (int i = 0; i < N; i++) {
        sumX += (C+i)->getX();
        sumY += (C+i)->getY();
    }

    averageX = sumX / N;
    averageY = sumY / N;

    Point center(averageX, averageY);

    return center;
}

void closer_Cluster(Point *A, Point *B, const Point &P) {  //Function that determines which cluster a point belongs to
    Point centerA = Center(A, N);   //finds center points for cluster A and B
    Point centerB = Center(B, N);

    float distPA = P.distance(centerA);  //Finds the distance between point P and the clusters and outputs results
    float distPB = P.distance(centerB);
 
     if (distPA < distPB) {   //tests to see which distance is shorter between the point and clusters and outputs the results
        cout << "The Point ";P.displayPoint();cout<<" belongs to Cluster A" << endl;
    }
    else if(distPA > distPB) {
        cout << "The Point ";P.displayPoint();cout<<" belongs to Cluster B" << endl;
    }
    else
    {
        cout << "The Point ";P.displayPoint();cout<<" is distance equally between both Cluster A and B" << endl;     //Unlikely, but incase the distance is equal to both clusters
    }
}

void GenerateA(Point *A, int N) {           //Functions to generate random points for cluster A within 70-90, excluding 70 and 90.
    srand(time(0));                 //seed the random number generator

    for (int i = 0; i < N; i++) {
        float x = (rand() % 19)+ 71;
        float y = (rand() % 19) + 71;
        *(A+i) = Point(x, y);
    }
}

void GenerateB(Point *B, int N) {           //Functions to generate random x and y points for cluster B within 20-40, excluding 20 and 40.
    srand(time(0));

    for (int i = 0; i < N; i++) {
        float x = (rand() % 19) + 21;
        float y = (rand() % 19) + 21;
        *(B+i) = Point(x, y);
    }
}

void GenerateP(Point *p, int M) {           //Functions to generate random x and y points within 5-100, excluding 5 and 100
    srand(time(0));

    for (int i = 0; i < M; i++) {
        float x = (rand() % 94 )+ 6;
        float y =(rand() % 94 )+ 6;
        *(p+i) = Point(x, y);
    }
}

void Point::displayPoint() const {         //Function to display x and y coordinate
    cout << "(" << x << "," << y << ")";
}

float Point::distance(const Point &P) const { //Function that calculates distance between two points
    float dist = sqrt(pow(x - P.getX(), 2) + pow(y - P.getY(), 2));
    return dist;
}

void Point::setX(float i) {            //setter for x coordinate
    x = i;
}

float Point::getX() const {            //getter for x coordinate
    return x;
}

void Point::setY(float j) {            //setter for y coordinate
    y = j;
}

float Point::getY() const {            //getter for y coordinate
    return y;
}
