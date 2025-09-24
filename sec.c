#include <stdio.h>
#include <stdlib.h>

int main(void)
{
int *m=NULL, *h=NULL, i, j, n, k=1, c=0,l, tmp, v, max; 
char s[512], *str; 
 FILE *f; 
 f=fopen("data.txt", "r"); 
 if(f==NULL){printf("Can't opne file"); return -1;}
 if(fscanf(f, "%d\n", &n)!=1) {printf("Empty file"); return -2;}
 m=(int*)malloc(sizeof(int)*n);
 while(fgets(s, sizeof(s), f)!=NULL)
 {
  str = s;
  if(k==c){k*=2; m=(int*)realloc(m, sizeof(int)*n*k);}
  for(i=0;i<n;i++)
  {
    if(sscanf(str,"%d%n", &m[i+c*n],&l)!=1){printf("ERROR"); free(m); return-3;}
    str += l;
  }
  c++;
  if(sscanf(str, "%d%n", &m[i+c*n], &l) == 1){printf("ERROR\n"); free(m); return -4;} 
 }
 for(i=0;i<c;i++)
  for (j=0;j<c-1;j++)
    if(m[j*n]<m[(j+1)*n])
      { for(v=0;v<n;v++)
       {
         tmp = m[j*n+v]; m[j*n+v] = m[(j+1)*n+v]; m[(j+1)*n+v] = tmp;
       }
      }
   for(i=0;i<c;i++)
   {
     for(j=0; j<n; j++)
    {
      printf("%d ", m[i*n+j]);
    }
    printf("\n");
   }

   h=(int*)malloc(sizeof(int)*c); 
    for(i=0;i<c;i++)
    { max = m[i*n]; 
     for(j=0;j<n;j++)
     {
        if(m[i*n+j]>max) {max = m[i*n+j];}
     }
     h[i]=max;
    }
      for(i=0;i<c;i++)
       printf("%d ", h[i]);
    
 free(h);
 free(m);
 fclose(f);


return 0;
}