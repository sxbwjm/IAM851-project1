//
//  common.h
//  Project1
//
//  Created by Xiaobo Sun on 4/10/14.
//  Copyright (c) 2014 Xiaobo Sun. All rights reserved.
//

#ifndef Project1_common_h
#define Project1_common_h

#define X_N 200
#define DELTA_X 0.2

#define T_N 4000
#define DELTA_T 0.0005

void vector_init(double result[], int size);
void vector_add(double result[], double v1[], double v2[], int size);
void vector_mul_const(double result[], double v1[], double k, int size);
void vector_copy(double src[], double dest[], int size);

void Runge_Kutta(void (*f)(double u[], double newU[]),
                 double u[], double newU[]);

double rhs(double u_2, double u_1, double u,
           double u1, double u2, double deltaX);

double initFunc1(double x);
double initFunc2(double x);
double initFunc3(double x);
double initFunc4(double x);
#endif
