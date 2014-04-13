//
//  discrete.c
//  Project1
//
//  Created by Xiaobo Sun on 4/5/14.
//  Copyright (c) 2014 Xiaobo Sun. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include "common.h"

/*************************************************************
 *               One derivative
 *************************************************************/
double DxU(double u1, double u2, double deltaX)
{
    return (u2 - u1) / deltaX;
}

/*************************************************************
 *               Second derivative
 *************************************************************/
double DxxU(double u_1, double u, double u1, double deltaX)
{
    return DxU( DxU(u_1, u, deltaX), DxU(u, u1, deltaX), deltaX );
}

/*************************************************************
 *               Third derivative
 *************************************************************/
double DxxxU(double u_2, double u_1, double u,
             double u1, double u2, double deltaX)
{
    return DxU( DxxU(u_2, u_1, u, deltaX),
                DxxU(u, u1, u2, deltaX),
                2 * deltaX);
}

/*************************************************************
 *            Right hand side expression in KdV
 *************************************************************/
double rhs(double u_2, double u_1, double u,
           double u1, double u2, double deltaX)
{
    return -6 * u * DxU(u_1, u1, 2 * deltaX) -
           DxxxU(u_2, u_1, u, u1, u2, deltaX);
}

/*************************************************************
 *               function for Runge–Kutta
 *
 * right hand side function in the following equation:
 *    u' = f(u)
 **************************************************************/
void rhsFunc(double U[], double newU[])
{
    double u_2, u_1, u, u1, u2;
    int size = X_N;
    int i;
    
    for(i=0; i<size; i++)
    {
        // test boundaries
        u_2 = (i - 2 >= 0) ? U[i - 2] : U[i - 2 + size];
        u_1 = (i - 1 >= 0) ? U[i - 1] : U[i - 1 + size];
        u = U[i];
        u1 = (i + 1 < size) ? U[i + 1] : U[i + 1 - size];
        u2 = (i + 2 < size) ? U[i + 2] : U[i + 2 - size];
        
        newU[i] = rhs(u_2, u_1, u, u1, u2, DELTA_X);
    }
}
