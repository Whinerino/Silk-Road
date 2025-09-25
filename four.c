#include <stdio.h>
#include <stdlib.h>

int main(void)
{
 int i,j,k,count,n,l,**m, *v, max_, tmp;
 char str[512], *s=NULL;
 FILE *f;
 f = fopen("data.txt", "r");
 if(f==NULL){printf("No data"); return -1;}
 if(fscanf(f, "%d\n", &n)!=1){printf("ERROR 1"); fclose(f); return -2;}
 for(count=0; fgets(str, sizeof(str), f);count++){}   //  <==>  while(fgets(str, sizeof(str), f)){count++}  ;
 m = (int**)malloc(sizeof(int*)*count + sizeof(int)*count*n);
 for(m[0]=(int*)(m+count),i=1;i<count;i++) {m[i]=m[0]+i*n;} //i*n потому что пробегаем всю строку
 fclose(f);
 f = fopen("data.txt", "r");
 fscanf(f, "%d\n", &n);
 for(count=0; fgets(str, sizeof(str), f);count++)
 {
  s = str;
  for(j=0;j<n;j++)
  {
   if(sscanf(s, "%d%n", &m[count][j], &l)!=1) {printf("ERROR 2");fclose(f);free(m); return -3;}
   s += l;
  }
  if(sscanf(s, "%d%n", &m[count][j], &l)==1) {printf("ERROR 3"); fclose(f); free(m); return -4;}    
 }
 fclose(f);
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
  max_ = m[i][0];
  for(j=0;j<n;j++)
  { 
   if(m[i][j] > max_) max_ = m[i][j];
  }
  v[i] = max_; 
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
