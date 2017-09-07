#include <iostream>
#include <new>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <armadillo>
#include <cstring>

using namespace std;
using namespace arma;

// Using inline functions to save time (functions are initialized at compile time instead of runtime)

inline double f(double x){return 100.0*exp(-10.0*x);
                         }
inline double u(double x){return 1.0-(1.0-exp(-10.0))*x-exp(-10.0*x);
                         }

// Main program
int main(int argc, char *argv[])
{
    // First setting up the variables and all the sorts
    int exponent = 1;           // power of 10 for number of steps
    int n = (int) pow(10.0,exponent);  // number of steps we're taking
    double h = 1.0/(n);         // step size
    double hh = h*h;            // step size squared

    int a,b;
    int j = n-1;
    // Using the form Ax=c where A is the matrix, x and c are column vectors
    mat A(n,n);
    vec x(n);
    vec c(n);

    for (a = 0; a <= j; a++)
        for (b = 0; b <= j; b++)
            if ( a==b ) {
                A(a,b) = 2;
            }
            else if ((a-1)==b) {
                A(a,b) = -1;
            }
            else if ((a+1)==b) {
                A(a,b) = -1;
            }
            else {
                A(a,b) = 0;
            }

    A.print("A:");



    return 0;
}
