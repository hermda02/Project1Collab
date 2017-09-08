//--------------------THIS IS PROJECT1 FOR FYS3150/4150--------------------
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

using namespace std;
using namespace arma;

/* Using inline functions to save time
 (functions are initialized at compile time instead of runtime)
*/
inline double f(double v){return 100.0*exp(-10.0*v);
                         }
inline double u(double v){return 1.0-(1.0-exp(-10.0))*v-exp(-10.0*v);
                         }

// Main program
int main(int argc, char *argv[])
{
    ofstream myfile; // this writes the data to a .txt file
    myfile.open ("project1abc_data.txt");
    myfile << "Writing this to a file.\n" << endl;

    // Initialize all variables
    int exponent = 1;   // power of 10 for number of steps
    int n =(int) pow(10.0,exponent);    // number of steps we are taking
    int i,j;
    double h = 1.0/(n); // step size
    double hh = h*h;    // step size squared
    vec a1(n),b1(n),c1(n), ctil(n), btil(n), fi(n);
    mat A(n,n);
    //mat A = randu<mat>(n,n);
    vec c = randu<vec>(n);
    vec v(n);
    vec x(n);


    // Using the form Av=c where A is the matrix, v and c are column vectors
    //------------------------------Section 1a------------------------------

    // create x vector
    for (i = 0; i < n; i++) { // build vector x and b_tilda
        x(i) = h*(i+1);
        btil(i) = f( x(i) ) * hh;
    }
    a1.fill(-1); // make a vector with all a_i elements of matrix A
    b1.fill(2); // make a vector with all b_i elements of matrix A
    c1.fill(-1); // make a vector with all c_i elements of matrix A

    a1.print("a1="); // print a1 to output screen
    b1.print("b1="); // print b1 to output screen
    c1.print("c1="); // print c1 to output screen










    //------------------------------Section 1b------------------------------



    // plot U(x) with v
    // make axis of x:0 to 1
    // make axis of y:0 to 1



    //------------------------------Section 1c------------------------------








    //------------------------------Section 1d------------------------------








    //------------------------------Section 1e------------------------------
    // Start point for clocking the processing time
    clock_t t;  //  declare start and final time
    t = clock();

    for (i = 0; i < n; i++) {// Build diagonal Matrix A
        for (j = 0; j < n; j++) {
            if ( i==j ) {
                A(i,j) = 2;
            }
            else if ((i-1)==j) {
                A(i,j) = -1;
            }
            else if ((i+1)==j) {
                A(i,j) = -1;
            }
        }
    }


    /*Compare your results with those from the LU decomposition codes for
     the matrix of sizes 10 × 10, 100 × 100 and 1000 × 1000
    */

    //A.print("A ="); // print A to output screen
    myfile << "A = " << endl << A << ' ' << endl;// writes output to file

    //v.print("v="); // print v to output screen
    myfile << "v = " << endl << v << ' ' << endl;// writes output to file

    //c.print("c="); // print c to output screen
    myfile << "c = " << endl << c << ' ' << endl;// writes output to file

    mat L, U, P; // find LU decomp of A, P is the permutation matrix
    lu(L,U,P,A);

    //L.print("L="); // print L to output screen
    myfile << "L = " << endl << L << ' ' << endl;// writes output to file

    //U.print("U="); // print U to output screen
    myfile << "U = " << endl << U << ' ' << endl;// writes output to file

    //Check that A = LU
    //(A-P*L*U).print("test"); // print to output screen
    myfile << "test = " << endl << (A-P*L*U) << ' ' << endl;// writes output to file



    // Stop point for clocking the processing time
    t = (clock() - t);

    //------------------------------------------------------------
    // Answer
    A.print("A=");
    A.i().print("A=");
    btil.print("btil=");
    vec answer = A.i()*btil;
    answer.print("answer=");
    //------------------------------------------------------------
    cout << setprecision(9) << "time= " << t<< endl;
    myfile.close();
    return 0;
}
