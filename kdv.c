//
//  discrete.c
//  Project1
//
//  Created by Xiaobo Sun on 4/5/14.
//  Copyright (c) 2014 Xiaobo Sun. All rights reserved.
//

#include <stdio.h>
#include <math.h>


double DxU(double u1, double u2, double deltaX)
{
    return (u2 - u1) / deltaX;
}

double DxxU(double u_1, double u, double u1, double deltaX)
{
    return DxU(DxU(u_1, u, deltaX), DxU(u, u1, deltaX), deltaX );
}

double DxxxU(double u_2, double u_1, double u,
             double u1, double u2, double deltaX)
{
   // return (u2 - 2 * u1 + 2 * u_1 - u_2) / ( 2 * deltaX * deltaX * deltaX);
    return DxU( DxxU(u_2, u_1, u, deltaX), DxxU(u, u1, u2, deltaX), 2 * deltaX);
}

double rhs(double u_2, double u_1, double u,
           double u1, double u2, double deltaX)
{
    return 6 * u * DxU(u_1, u1, 2 * deltaX) -
           DxxxU(u_2, u_1, u, u1, u2, deltaX);
}