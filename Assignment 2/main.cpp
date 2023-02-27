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
    Point *A = new Point[n];
    Point *B = new Point[n];
    Point *P = new Point[m];

    GenerateA(A, n);
    GenerateB(B, n);
    GenerateP(P, m);

    for (int i = 0; i < m; i++)
    {
        closer_Cluster(A, B, P[i]);
    }

}

Point Center(Point *C, int n) {
    float averageX = 0;
    float averageY = 0;
    float sumX = 0;
    float sumY =0;

    for (int i = 0; i < n; i++) {
        sumX += (C+i)->getX();
        sumY += (C+i)->getY();
    }

    averageX = sumX / n;
    averageY = sumY / n;

    Point center(averageX, averageY);

    return center;
}

void closer_Cluster(Point *A, Point *B, const Point &P) {
    Point centerA = Center(A, n);
    Point centerB = Center(B, n);

    float distPA = P.distance(centerA);
    float distPB = P.distance(centerB);

    if (distPA < distPB) {
        cout << "The Point ";P.displayPoint();cout<<" is closer to Cluster A" << endl;
    }
    else {
        cout << "The Point ";P.displayPoint();cout<<" is closer to Cluster B" << endl;
    }
}

void GenerateA(Point *A, int n) {
    srand(time(0));

    for (int i = 0; i < n; i++) {
        float x = rand() % 21 + 70;
        float y = rand() % 21 + 70;
        A[i] = Point(x, y);
    }
}

void GenerateB(Point *B, int n) {
    srand(time(0));

    for (int i = 0; i < n; i++) {
        float x = rand() % 21 + 20;
        float y = rand() % 21 + 20;
        B[i] = Point(x, y);
    }
}

void GenerateP(Point *p, int m) {
    srand(time(0));

    for (int i = 0; i < m; i++) {
        float x = rand() % 91 + 5;
        float y = rand() % 91 + 5;
        p[i] = Point(x, y);
    }
}
