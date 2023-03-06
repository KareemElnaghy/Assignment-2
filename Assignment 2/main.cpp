//
//  main.cpp
//  Assignment 2
//
//  Created by Kareem Elnaghy on 2/27/23.
//  900223587


#include <iostream>
#include "Point.h"
using namespace std;


const int N = 200;      //declare the number of points to be created for both clusters
const int M = 20;       //declare the number of points to be created

int main()                            //main function
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
