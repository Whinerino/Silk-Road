#include<stdio.h>
#include<stdlib.h>
int main(void)
{
 int I, i, j, **m, count, n, l;
 FILE *f; 
 char str[514], *s=NULL;
 f = fopen("data.txt", "r");
 if(f==NULL){printf("xui"); return -1;}
 if(fscanf(f,"%d",&n)!=1) {printf("No stroki"); fclose (f); return -2;}
 for(count=0; fgets(str,sizeof(str), f); count++){}
 m = (int**)malloc(sizeof(int*)*count + sizeof(int)*count*n);
 for(m[0]=(int*)(m+count),i=1; i<count;i++) {m[i]=m[0]+i*n;} // i*n потому что проходим всю строку 
 fclose(f);
 f = fopen("data.txt", "r"); 
 fscanf(f,"%d",&n);
 for(count=0; fgets(str,sizeof(str), f); count++)
 {
  s = str; 
  for(j=0;j<n;j++)
  {
    if(sscanf(s,"%d%n", &m[count][j], &l)!= 1){printf("Error1"); fclose(f); free(m); return -3;}
    s+=l;
  }
  if(sscanf(s,"%d%n", &m[count][j], &l)== 1) {printf("Error3"); return -4; fclose(f); free(m); return -4;}
 }
fclose(f);

}