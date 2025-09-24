#include <stdio.h>
#include <stdlib.h>


int main(void)
{
 int i,j,h, *m=NULL,*v=NULL,  n=0, k=1, c=0, l, tmp, max;
 char s[512], *str;
 FILE *f;
 f = fopen("data.txt","r");
 if(f == NULL) {printf("cant open file");return -1;} 
 if(fscanf(f, "%d\n", &n) != 1) {printf("empty file");return -2;}
 m = (int*)malloc(sizeof(int)*n);
 while(fgets(s, sizeof(s), f) != NULL)
 {
  str = s;
  if(c == k) 
  {
   k *= 2;
   m = (int*)realloc(m, sizeof(int)*k*n); 
  }
  for(i=0; i<n; i++)
  {
   if(sscanf(str, "%d%n", &m[i+c*n], &l) != 1){printf("ERROR\n"); free(m); return -3;} 
   str += l;
  }
  c++;
  if(sscanf(str, "%d%n", &m[i+c*n], &l) == 1){printf("ERROR\n"); free(m); return -4;} 
 }
  for(i=0; i<c; i++)
   for(j=0; j<c-1; j++)
    if(m[j*n + n -1] < m[(j+1)*n + n -1])
     for(h=0; h<n; h++)
      {tmp = m[j*n + h]; m[j*n + h] = m[(j+1)*n + h]; m[(j+1)*n + h] = tmp;}
 v = (int*)malloc(sizeof(int)*n);
 for(j=0; j < n; j++){ max = m[j]; 
  for(i = 0; i < c; i++)
   if(m[j+i*n] > max) {max = m[j+i*n];}
  v[j] = max;}
   

 for(i=0; i < c; i++)
 {
  for(j=0; j<n; j++)   
    printf("%d ", m[j+i*n]);
  printf("\n");
 }

 for(i=0;i<n;i++)
  for (j=0;j<n-1;j++)
   if(v[j]<v[j+1]){tmp = v[j]; v[j] = v[j+1]; v[j+1]=tmp;}
    for(i = 0 ;i < n ; i ++) {printf("%d ",v[i]);}

 free(m); free(v);
 fclose(f);
 return 0;  
}