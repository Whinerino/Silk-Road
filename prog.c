#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
 int i=1, j, t, c;
 FILE *dat, *res;
 int A[7];
 dat=fopen("data.dat", "r");
 if (dat==NULL) return -1;
 res=fopen("data.res", "w");
 if (res==NULL)
  {fclose(dat); return -2;}
 if (fscanf(dat, "%d", &c)==0)
  {
   fprintf(res, "ERROR\n");
    fclose(dat); 
     fclose(res); 
       return -3;
   }

 A[0]=c;
 if ()


 
 if (i==5) 
 {
   for(j=0; j<4; j++)
    if (A[j]>A[j+1])
    {
     t=A[j]; 
     A[j]=A[j+1];
     A[j+1]=t;
    }
 } 
 else 
 {
   fprintf(res, "NO\n"); 
   fclose(dat); fclose(res); 
   return -4;
 }

 for(i=0;i<5;i++)
  (fprintf(res, "%d\n", A[i]));

 fclose(dat);
 fclose(res);
return 0;         
}
