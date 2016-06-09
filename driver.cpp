/**
 * @file    driver.cpp
 * Purpose  To call Bisect() with values that will check for proper behavior
 *           and provide output to cout.
 * @author  Brendan Sweeney, SID 1161837
 * @date    October 11, 2011
 */

#include <iostream>
#include <cmath>
#include "bisect.h"
using namespace std;

typedef double param;

/** Pass a set of test values to Bisect(). Output useful information about the
 *   values passed and the expected result.
 * @param   xL  Left limit of testing interval.
 * @param   xR  Right limit of testing interval.
 * @param   eps  Size of smallest interval to test.
 * @pre     Bisect() is able to handle erroneous input.
 * @post    Bisect() will retun a value, which is output to cout, or it will
 *           exit with an error message.
 */
void pass(param xL, param xR, param eps)
{
    cout << "xLeft:\t\t" << xL << '\n'
         << "xRight:\t\t" << xR << '\n'
         << "epsilon:\t" << eps << "\n\n"
         << "Found optimal angle to be  "
         << Bisect(trajectory, xL, xR, eps)
         << "  radians.\n\n" << endl;
} // end pass()

/*
 * 
 */
int main(int argc, char** argv)
{
    param xLeftTest = 0.0;
    param xRightTest = M_PI / 4.0;
    param epsilonTest = 0.0001;
    
    cout << "\n\nGood input. Should return the lower successful angle.\n"
         << endl;
    
    pass(xLeftTest, xRightTest, epsilonTest);
    
    
    xLeftTest = M_PI / 4.0;
    xRightTest = (M_PI - epsilonTest) / 2.0;
    
    cout << "Good input. Should return the upper successful angle.\n" << endl;
    
    pass(xLeftTest, xRightTest, epsilonTest);
    
    
    xLeftTest = -M_PI;
    xRightTest = -3.0 * M_PI / 4.0;
    
    cout << "Okay input. Should return a root.\n" << endl;
    
    pass(xLeftTest, xRightTest, epsilonTest);
    
    
    xLeftTest = M_PI / 4.0;
    xRightTest = 0.0;
    
    cout << "Precondition of Bisect() not met - xLeft > xRight."
         << " Should try again with boundaries switched\n" << endl;
    
    pass(xLeftTest, xRightTest, epsilonTest);
    
    
    xLeftTest = M_PI / 4.0;
    xRightTest = M_PI / 4.0;
    
    cout << "Invalid input - single point given, not an interval."
         << " Should print error message and exit.\n" << endl;
    
    //pass(xLeftTest, xRightTest, epsilonTest);
    
    
    xLeftTest = 0.0;
    xRightTest = (M_PI - epsilonTest) / 2.0;
    
    cout << "Invalid input - even number of roots in interval."
         << " Should print error message and exit.\n" << endl;
    
    //pass(xLeftTest, xRightTest, epsilonTest);


    xRightTest = M_PI / 4.0;
    epsilonTest = 100.0;

    cout << "Unreasonable input - tolerance exceeds initial interval."
         << " Should return xMid.\n" << endl;

    pass(xLeftTest, xRightTest, epsilonTest);
    

    epsilonTest = 0.0;
    
    cout << "Invalid input - base case cannot be reached."
         << " Should print error message and exit.\n" << endl;
    
    //pass(xLeftTest, xRightTest, epsilonTest);


    epsilonTest = -0.0001;

    cout << "Invalid input - base case cannot be reached."
         << " Should print error message and exit.\n" << endl;

    //pass(xLeftTest, xRightTest, epsilonTest);


    xRightTest = M_PI / 2.0;
    epsilonTest = 0.0001;

    cout << "Invalid input - tan(PI / 2) is undefined."
         << " Should print error message and exit.\n" << endl;

    //pass(xLeftTest, xRightTest, epsilonTest);


    cout << "\nUncomment calls to pass() and rebuild to test for specific error"
         << " handling.\n" << endl;
    
    return 0;
} // end main()
