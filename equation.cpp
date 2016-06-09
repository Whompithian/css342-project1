/**
 * @file    equation.cpp
 * Purpose  To define a non-linear equation and evaluate it at a given value.
 * @author  Brendan Sweeney, SID 1161837
 * @date    October 11, 2011
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include "equation.h"
using namespace std;

typedef double param;

/** Determine whether a given angle, in radians, will cause a projectile fired
 *   at a set trajectory in earth normal gravity to hit a set target. A value
 *   of 0 means success.
 * @param   x  The angle of fire, in radians.
 * @pre     x is not in the set (PI / 2, 3 * PI / 2, ...). This would result in
 *           an undefined value for tan(x) and a later division by zero.
 * @post    The equation is evaluated and the resulting value returned.
 * @return  The solution to the trajectory equation at the given value.
 */
double trajectory(double theta)
{
    const param s = 3300.0;    // distance to base of target, in m
    const param g = 9.81;      // acceleration from gravity, in m/s/s
    const param v = 250.0;     // velocity of projectile, in m/s
    const param h = 3.0;       // height from base of target, in m

    if(fmod((theta - M_PI / 2.0), M_PI) == 0)   // tan(PI / 2) is undefined
    {
        cerr << "INVALID INPUT: tan(theta) undefined" << endl;
        exit(EXIT_FAILURE);
    } // end if(fmod((theta - M_PI / 2.0), M_PI) == 0)

    return s * tan(theta) - 0.5 * g * s * s / (v * v * pow(cos(theta), 2)) - h;
} // end trajectory()
