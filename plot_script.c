//
//  plot_script.c
//  Project1
//
//  Created by Xiaobo Sun on 4/12/14.
//  Copyright (c) 2014 Xiaobo Sun. All rights reserved.
//

#include <stdio.h>
#include "common.h"

int createPlotScript(char* fileName, int type)
{
    FILE* f = fopen(fileName, "w");
    if(f == NULL)
    {
        return -1;
    }
    
    float yRange = 0.35;
    switch(type)
    {
        case 0:
            yRange = 0.35;
            break;
        case 1:
            yRange = 2.5;
            break;
        case 2:
            yRange = 3;
            break;
        case 3:
            yRange = 6;
            break;
        default:
            break;
    }
    fprintf(f, "if (exist(\"n\")==0 || n<0) n=0\n");
    fprintf(f, "plot [0:40] [-0.3:%f] sprintf(\"output/data-%%d\", n) with lines", yRange);
    fprintf(f, " title sprintf(\"time:%%f\", n * %f)\n",  DELTA_T * T_STEPS_PER_FILE);
    fprintf(f,"if (n<1999) n=n+1; reread\n");
    fprintf(f,"n=-1\n");
    
    fclose(f);
    
    return 0;
    
    
}