#include <stdio.h>
int main(){
int M, N,i,j,teplicova=1,cirkularna=1;
double mat[100][100];
printf("Unesite M i N: ");
scanf("%d %d",&M,&N);
while(M<0 || M>100 || N<0 || N>100 || M==0 || N==0)
{
printf("Pogresan unos!\n");
printf("Unesite M i N: ");
scanf("%d %d",&M,&N);
if((M>0 && M<=100) && (N>0 && N<=100))
{
break;
}
else
{
continue;
}
}
printf("Unesite elemente matrice: ");
for(i=0;i<M;i++)
{
for(j=0;j<N;j++)
{
scanf("%lf",&mat[i][j]);
}
}
/*Da li je Teplicova*/
for(i=1;i<M;i++)
{
for(j=1;j<N;j++)
{
if(mat[i][j]!=mat[i-1][j-1])
{
teplicova=0;
}
}
}

/*Da li je cirkularna*/
for(i=1;i<M;i++)
{
if(mat[i][0]!=mat[M-i][0])
{
cirkularna=0;
}
}

/* Ispis */ 
if(teplicova==1 && cirkularna==1)
{
printf("Matrica je cirkularna");
}
if(teplicova==1 && cirkularna==0)
{
printf("Matrica je Teplicova");
}
else if(teplicova==0)
{
printf("Matrica nije ni cirkularna ni Teplicova");
}
return 0;
}