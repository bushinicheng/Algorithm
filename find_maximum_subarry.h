#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#ifndef _find_maximum_subarry_
#define _find_maximum_subarry_
typedef struct mystruct{
    int low;
    int high;
    int maxsum;
}mystruct;
mystruct find_maximum_subarry(int *a,int low,int high);
#endif

