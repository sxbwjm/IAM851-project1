//
//  main.c
//  Project1
//
//  Created by Xiaobo Sun on 4/5/14.
//  Copyright (c) 2014 Xiaobo Sun. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include "common.h"


/*************************************************************
 *               function for Runge–Kutta
 * right hand side function in the following equation:
 *    u' = f(u)
 **************************************************************/
void f(double U[], double newU[])
{
    double u_2, u_1, u, u1, u2;
    int size = X_N;
    
    for(int i=0; i<size; i++)
    {
        u_2 = (i - 2 >= 0) ? U[i - 2] : U[i - 2 + size];
        u_1 = (i - 1 >= 0) ? U[i - 1] : U[i - 1 + size];
        u = U[i];
        u1 = (i + 1 < size) ? U[i + 1] : U[i + 1 - size];
        u2 = (i + 2 < size) ? U[i + 2] : U[i + 2 - size];
        
        newU[i] = rhs(u_2, u_1, u, u1, u2, DELTA_X);
    }
}


/*************************************************************
 *               get inital data vector
 **************************************************************/
void Ut0( double (*f)(double x), double U[])
{
    int size = X_N;
    
    for(int i = 0; i < size; i++)
    {
        U[i] = (*f)(i * DELTA_X);
    }
}

/*************************************************************
 *           write one frame of data U to file
 **************************************************************/
void writeUtoFile(char* fileName, double U[])
{
    FILE * file = fopen(fileName, "w");
    
    for(int i = 0; i < X_N; i++)
    {
        fprintf(file, "%g %g\n", i * DELTA_X , U[i]);
    }
    
    fclose(file);
}

/*************************************************************
 *              main starts from here
 **************************************************************/
int main(int argc, const char * argv[])
{
    int t = 0;
    double U[X_N], newU[X_N];
   
    // get inital u
    Ut0(initFunc2, U);
    
    // write first frame data
    char fileName[20];
    sprintf(fileName, "data-0");
    writeUtoFile(fileName, U);
    
    for(t = 1; t < T_N; t++)
    {
        char fileName[20];
        sprintf(fileName, "data-%d", t);

        Runge_Kutta(f, U, newU);
        writeUtoFile(fileName, newU);
        
        // update U
        vector_copy(newU, U, X_N);

    }
    return 0;
}

