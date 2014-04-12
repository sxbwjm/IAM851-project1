//
//  InitConditions.c
//  Project1
//
//  Created by Xiaobo Sun on 4/11/14.
//  Copyright (c) 2014 Xiaobo Sun. All rights reserved.
//

#include <stdio.h>
#include <math.h>

/*************************************************************
 *               functions for inital condition
 **************************************************************/

// u(x,0) = N(N+1)/cosh(x)^2
double initFunc1(double x)
{
    double N = 0.25;
    double tmp = cosh(x - 10);
    return N * (N + 1) / (tmp * tmp);
}

// one solition
double initFunc2(double x)
{
    double c = 10 ;
    double tmp = cosh( sqrt(c) * (-x+20) / 2);
    return -c / (tmp * tmp) / 2;
}

// two solitions
double initFunc3(double x)
{
    double c1 = 10;
    double c2 = 1;
    double tmp1 = cosh( sqrt(c1) * (x-10) / 2);
    double tmp2 = cosh( sqrt(c2) * (x-20) / 2);
    return c1 / (tmp1 * tmp1) / 2 + c2/ (tmp2 * tmp2) / 2;
}
