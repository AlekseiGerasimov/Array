#include <iostream>
#include "array.h"
#include "tests.h"

using namespace std;

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "Russian");
    float m[]={10,20,30};
    Array A(m,3);
    Tests B(A);
    if(B.debug() == 0)
         cout << "Object is Ok" << endl;

    return 0;
}
