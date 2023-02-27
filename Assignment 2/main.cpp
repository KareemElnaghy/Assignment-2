//
//  main.cpp
//  Assignment 2
//
//  Created by Kareem Elnaghy on 2/27/23.
//


#include <iostream>
#include "Point.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int n = 200;
const int m = 20;

Point Center(Point *C, int n);
void closer_Cluster(Point *A, Point *B, const Point &P);
void GenerateA(Point *A, int n);
void GenerateB(Point *B, int n);
void GenerateP(Point *p, int m);

int main()
{
    
}

Point Center(Point *C, int n) {
    float averageX = 0;
    float averageY = 0;
    float sumX = 0;
    float sumY =0;

    for (int i = 0; i < n; i++) {
        sumX += *(C+i)->getX();
        sumY += C[i].getY();
    }

    averageX = sumX / n;
    averageY = sumY / n;

    Point center(averageX, averageY);

    return center;
}
