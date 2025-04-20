#include "Matrix.h"
#include <iostream>
using namespace std;

int main()
{
    Matrix A(2, 2);
    A(0,0)=6; A(0,1)=4;
    A(1,0)=8; A(1,1)=3;

    Matrix B(2, 3);
    B(0,0)=1; B(0,1)=2; B(0,2)=3;
    B(1,0)=4; B(1,1)=5; B(1,2)=6;

    Matrix C(2, 3);
    C(0,0)=2; C(0,1)=4; C(0,2)=6;
    C(1,0)=1; C(1,1)=3; C(1,2)=5;

    // solve for D
    Matrix D = A + B.scale(3.0) * C.transpose();
    cout << "D =\n" << D;

    //example
    Matrix expected(2,2);
    expected(0,0)=90;  expected(0,1)=70;
    expected(1,0)=200; expected(1,1)=150;
    if (!D.equals(expected))
    {
        cerr << "Error\n";
        return 1;
    }
    return 0;
}
