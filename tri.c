#include <stdio.h>
#include <stdlib.h>
int main(void)
{
int **m=NULL, *v=NULL,n, i, j ,k, I, count, l, tmp,max;
char str[256];
char *s=NULL;
FILE *f; 
for(I=0;I<2;I++)
{
 f=fopen("data.txt", "r");
 if (f==NULL){printf("уебище не открылось"); return -1;}
 if (fscanf(f, "%d\n", &n) != 1) {printf("75 процентов мне 25 а тебе n хуй с маслом"); fclose(f); return -2;}
 for(count=0; fgets(str, sizeof(str), f); count++)
 {
 if(I==1)
  { s = str;
   for(j=0;j<n;j++)
   {
    if(sscanf(s, "%d%n", &m[count][j], &l)!=1) {printf("ERROR 1"); fclose(f); free(m); return-3;}
    s += l;
   }
 if(sscanf(s, "%d%n", &m[count][j], &l)==1) {printf("ERROR 2"); fclose(f); free(m); return-4;}
  }
 }
 if(I==0)
  {
   m = (int**)malloc(sizeof(int*)*count + sizeof(int)*n*count);
   for(m[0]=(int*)(m + count),i=1;i<count;i++) m[i] = m[0] + n*i;
  }
 fclose(f);
}
for(i=0;i<count;i++)
 for(j=0;j<count-1;j++)
  if(m[j][0]<m[j+1][0])
   for(k=0;k<n;k++)
   { 
    tmp = m[j][k]; m[j][k]=m[j+1][k]; m[j+1][k]=tmp;
   }
v = malloc(sizeof(int)*count);
for(i=0;i<count;i++)
 {
  max = m[i][0];
  for(j=0;j<n;j++)
  { 
   if(m[i][j] > max) max = m[i][j];
  }
  v[i] = max; 
 }
for(i=0;i<count;i++)
 for(j=0;j<count-1;j++)
  if(v[j]<v[j+1])
   {tmp = v[j]; v[j] = v[j+1]; v[j+1]=tmp;}
for(i=0;i<count;i++){
 for(j=0;j<n;j++)
  {printf("%d ", m[i][j]);}
  printf("\n");
}
for(i=0;i<count;i++)
 printf("%d ", v[i]);
free(m);
free(v);
}