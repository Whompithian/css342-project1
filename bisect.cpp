/**
 * @file    Bisect.cpp
 * Purpose  To recursively bisect a range of test values for a function until
 *           the tested interval reaches a defined minimum value or a desired
 *           value is returned by equation().
 * @author  Brendan Sweeney, SID 1161837
 * @date    October 11, 2011
 */

#include <cstdlib>
#include <iostream>
#include "bisect.h"
using namespace std;

/** Recursively locate the midpoint of an interval until it lands sufficiently
 *   close to the root of a specified non-linear equation. Finding a real root
 *   should also result in success.
 * @param   f  A reference to the equation to be evaluated. Defined in
 *           equation.h.
 * @param   xLeft  The left boundary in the range to be evaluated. Should be
 *           less than xRight. Should not be a root of the equation.
 * @param   xRight  The right boundary in the range to be evaluated. Should be
 *           greater than xLeft. Should not be a root of the equation.
 * @param   epsilon  The desired accuracy of the solution. Execution will stop
 *           if the input range falls within this vlue.
 * @pre     xRight >= xLeft. epsilon > 0. In the interval (xLeft, xRight), F()
 *           is continuous with an odd number of roots. F(xLeft) and F(xRight)
 *           both evaluate to some real number != 0.
 * @post    A value within epsilon of a real root of the equation will be
 *           determined.
 * @return  A value between xLeft and xRight that evaluates sufficiently close
 *           to 0.
 */
double Bisect(functionType f, double xLeft, double xRight, double epsilon)
{
    /* Error checks. If the bounds of the interval are given in reverse order,
     *  switch them. If the interval does not contain an odd number of roots,
     *  return an error code.
     */
    if(xLeft > xRight)      // boundaries reversed, should be switched
    {
        cerr << "Boundaries reversed: retrying with left and right"
             << " boundaries switched." << endl;
        return (Bisect(f, xRight, xLeft, epsilon));
    } // end if(xLeft > xRight)
    if((f(xLeft)) * (f(xRight)) > 0)    // same signs, even number of roots
    {
        cerr << "INVALID INPUT: interval contains even number of roots" << endl;
        exit(EXIT_FAILURE);
    } // end if((f(xLeft)) * (f(xRight)) > 0)
    if(epsilon <= 0)        // epsilon can never be reached
    {
        cerr << "INVALID INPUT: epsilon must be positive" << endl;
        exit(EXIT_FAILURE);
    } // end if(epsilon <= 0)

   /* Bisect() will check for and respond to three scenarios:
    * if the midpoint evaluates to 0 or the range is less than epsilon, return
    *  the midpoint value and exit.
    * if the midpoint evaluates to have the same sign as f(xLeft), call
    *  Bisect() with the midpoint and xRight.
    * if the midpoint evaluates to have the same sign as f(xRight), call
    *  Bisect() with xLeft and the midpoint.
    */
    if((f((xRight + xLeft) / 2) == 0) || ((xRight - xLeft) < epsilon))
        return (xRight + xLeft) / 2;            // solution has been found

    if((f(xLeft) * f((xRight + xLeft) / 2)) > 0)
        return Bisect(f, (xRight + xLeft) / 2, xRight, epsilon);

    return Bisect(f, xLeft, (xRight + xLeft) / 2, epsilon);
} //end Bisect()
