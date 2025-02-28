#include "fun.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int fun(int **v, int *n, int m)
{
int i, j, sum = 0, k = 0;
 if (*n<=0 || m<=0) return -1;
 for(j=0;j<m;j++) for(i=0;i<*n;i++) sum+=v[i][j];
 for(j=0;j<m;j++) for(i=0;i<*n;i++)
 {
  if ((v[i][j]*m*(*n)==sum))
  { k=i;
    (*n)--;
    for(i=k;i<*n;i++) for(j=0;j<m;j++) v[i][j]=v[i+1][j];
    return 0;
  } 
 }
 return 0;
}