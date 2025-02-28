#include "fun.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
FILE *out;
int **v=NULL, n, m, err, i, j;
 out=fopen("data.res","w");
 err=input("data.dat", &v, &n, &m);
 if(err) {printf("error_1\n"); return -1;} 
 for(i=0;i<n;i++, fprintf(out,"\n")) for(j=0;j<m;j++) fprintf(out, "%d ", v[i][j]);
 err=fun(v,&n,m);
 if(err) {printf("error_2\n"); return -1;}
fprintf(out,"------------------------\n");
 for(i=0;i<n;i++, fprintf(out,"\n")) 
 for(j=0;j<m;j++) fprintf(out, "%d ", v[i][j]);
 if(v) {free(v);}

 fclose(out);
 
return 0;
}