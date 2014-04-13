//
//  main.c
//  Project1
//
//  Created by Xiaobo Sun on 4/5/14.
//  Copyright (c) 2014 Xiaobo Sun. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "common.h"

#define INIT_FUNC_NUM 4

int printMenu(char* funcNames[]);
void Ut0( double (*f)(double x), double U[]);
void writeUtoFile(char* fileName, double U[]);

/*************************************************************
 *              main starts from here
 **************************************************************/
int main(int argc, const char * argv[])
{
    char* outputFile = "output/data";
    
    int t = 0;
    double U[X_N], newU[X_N];
   
    // store different inital functions
    double (*initFuncs[])(double x) = {
        initFunc1,
        initFunc2,
        initFunc3,
        initFunc4
    };
    char* funcNames[] = {
        "u(x,0) = N(N+1)/cosh(x)^2    N = 0.25",
        "u(x,0) = N(N+1)/cosh(x)^2    N = 1  \t\t\t one soliton",
        "u(x,0) = (c/2)/cosh2(√c/2)   c = 10 \t\t\t one soliton",
        "u(x,0) = (c1/2)/cosh2(√c1/2)+(c2/2)/cosh2(√c2/2)\t two soliton"
    };
    
    int useFunc = printMenu(funcNames);
    
    // start processing
    printf("processing: %%0");
    fflush(stdout);
    time_t startTime;
    time(&startTime);
    
    // get inital u
    Ut0(initFuncs[useFunc], U);
    
    // write first frame data
    char fileName[20];
    sprintf(fileName, "%s-%d", outputFile, 0);
    writeUtoFile(fileName, U);
    
    int onePercent = T_N / 100;
    for(t = 1; t < T_N; t++)
    {
        Runge_Kutta(rhsFunc, U, newU);
        
        // save data into file for every specific steps
        if( t % T_STEPS_PER_FILE == 0)
        {
            char fileName[20];
            sprintf(fileName, "%s-%d", outputFile, t / T_STEPS_PER_FILE);
            writeUtoFile(fileName, newU);
        }
        
        // show progress
        if( t % onePercent == 0)
        {
            printf("\rprocessing: %%%d", t / onePercent);
            fflush(stdout);
        }
        
        // update U
        vector_copy(newU, U, X_N);
    }
    
    // create plot script
    createPlotScript("animate.plt", useFunc);
    
    // end processing
    time_t endTime;
    time(&endTime);
    printf("\nprocess time: %.3f secs\n", difftime(endTime, startTime));
    printf("Please run \"gnuplot animate.plt\" to show the result\n\n");
    
    return 0;
}

int printMenu(char* funcNames[])
{
    int i;
    
    printf("choose inital function:\n");
    printf("***********************************************************\n");
    for(i=0; i<INIT_FUNC_NUM; i++)
    {
        printf("%d  %s\n", i, funcNames[i]);
    }
    printf("***********************************************************\n");
    printf("Enter number:");
    
    int result;
    while(1)
    {
        result = getchar();
        if(result == '\n')
            printf("Enter number:");
        
        else
        {
            result -= '0';
            if(result >= 0 && result < INIT_FUNC_NUM)
                break;
        }
    }
    
    return result;
    
}

/*************************************************************
 *               get inital data vector
 * f: initial function
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

