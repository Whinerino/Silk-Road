#include "fun.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int input(const char*sf, int ***v, int *n, int *m)
{
FILE *f;
int i,j;
 f=fopen(sf, "r");
 if(f)
 {
  if (fscanf(f, "%d %d", n, m)!=2) {fclose(f); return -2;}
  if (*n==0 || *m==0) {fclose(f); *n=*m=0; v=NULL; return 0;}
  *v=(int**)malloc(*n*sizeof(int*)+sizeof(int)*(*n)*(*m));
  for(i=0;i<*n;i++) 

  (*v)[i]=((int*)((*v)+*n))+i*(*m);
  for(i=0;i<*n;i++)
  
   for(j=0;j<*m;j++)
  {
   if (fscanf(f, "%d", (*v)[i]+j)!=1)
   {
    fclose(f);
    free(*v); 
    *v = NULL; 
    return -3;
    }
  }
  fclose(f); return 0;
 }
 else 
 return -1;
}