// -------------------- Project 1 file --------------------------
#include <iostream>
#include <new>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <armadillo>
#include <cstring>
#include <string>
#include <math.h>
#include <vector>
#include <fstream>
#include <time.h>
#include <ctime>
#include <stdio.h>

using namespace std;
using namespace arma;
ofstream ofile;

// Using inline functions to save time (functions are initialized at compile time instead of runtime)

inline double f(double x){return 100.0*exp(-10.0*x);
                         }
inline double sol(double x){return 1.0-(1.0-exp(-10.0))*x-exp(-10.0*x);
                         }

// Main program
int main(int argc, char *argv[])
{

    // First setting up the variables and all the sorts
    int exponent = 1;                   // power of 10 for number of steps
    int n = (int) pow(10.0,exponent);   // number of steps we're taking
    double h = 1.0/(n+1.0);                 // step size
    double hh = h*h;                    // step size squared


    vec x(n+2);
    vec b_tild(n+1);

    b_tild(0) = 0;

    // The tridiagonal matrix elements defined in three vectors
    vec a(n+1);
    vec b(n+1);
    vec c(n+1);

    // The new values of the diagonal
    vec diag(n+1);

    // Numerical and analytic solutions
    vec u(n+2);
    vec v(n+2);

    u(0) = 0;
    v(0) = 0;

//------------------------------------------ The Calculation Portion - General Algorithm -----------------------------------------------------------------

    // Start point for clocking the processing time
    clock_t t;  //  declare start and final time
    t = clock();

    // Fills the x array with the values
    for (int j=0; j<=n+1; j++) {
        x(j) = j*h;
    }

    // Filling the tild array (R.H.S.)
    for (int j=0; j<=n; j++) {
        b_tild(j) = hh*f(x(j));
        // cout << "b_tild = " << b_tild(j) << "for x = " << x(j) << endl;
        u(j) = sol(x(j));
        // cout << "u = " << u(j) << "for x = " << x(j) << endl;
        b(j) = 2;
        a(j) = -1;
        c(j) = -1;
    }


    // Algorithm for finding v:
    // Row reduction; forward substitution:
    double b_temp = b(1);
    v(1) = b_tild(1)/b_temp;
    for (int j=2; j<=n;j++) {
        diag(j) = c(j-1)/b_temp;        // temporarily saving a value to calculate in the next step
        b_temp = b(j)-a(j)*diag(j);     // same, again
        v(j) = (b_tild(j)-v(j-1)*a(j))/b_temp;
    }

    // Backward substitution
    for (int j=n-1;j>=1;j--) {
        v(j) -= diag(j+1)*v(j+1);
    }

    // Stop point for clocking the processing time
    t = (clock() - t);






    cout << setprecision(9) << "time= " << t<< endl;

    printf ("It took me %d clicks (%f seconds). \n",t,((float)t)/CLOCKS_PER_SEC);

    ofile.open("testfile.txt");
    ofile << setiosflags(ios::showpoint | ios::uppercase);
    ofile << "       x:             u(x):          v(x):        log10(RelativeError):   " << endl;
    for (int j=1;j<=n;j++) {
        double xval = x(j);
        double RelativeError = fabs((sol(xval)-u(j))/sol(xval));
        ofile << setw(15) << setprecision(8) << x(j);
        ofile << setw(15) << setprecision(8) << u(j);
        ofile << setw(15) << setprecision(8) << v(j) << endl;
    }

    ofile.close();


    return 0;
}
