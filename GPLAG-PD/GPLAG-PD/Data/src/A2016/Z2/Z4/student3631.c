#include <stdio.h>

int main() {
int t=1,c=1,i,j,M,N;
double mat[100][100];
printf ("Unesite M i N: ");
scanf ("%d %d", &M,&N);

while (M<1 || N<1 || M>100 || N>100)
{
    printf ("Pogresan unos!\nUnesite M i N: ");
   scanf ("%d %d",&M,&N ); 
}
printf ("Unesite elemente matrice: ");
for(i=0;i<M;i++)
{
for (j=0;j<N;j++)
{
    scanf ("%lf", &mat[i][j]);
}
}


if (N==1 && M==1)  {printf ("Matrica je cirkularna");}
else if ( M==1) {printf ("Matrica je cirkularna");}
else if (N==1) printf ("Matrica je Teplicova");


else {
    for (i=1; i<M; i++)
    {if (mat[i][0]!= mat[i-1][N-1]) {c=0; } 
    for (j=1; j<N;j++)
    { if (mat[i][j]!=mat[i-1][j-1]) {c=0; }
       
    }}
    

for(i=0;i<M-1;i++)
{
for (j=0;j<N-1;j++)
{
    if (mat[i][j]!=mat[i+1][j+1] ) {t=0;} 
    
}}
    
    
    
if (c==1) {printf ("Matrica je cirkularna");}    
else if (t==1) {printf ("Matrica je Teplicova");}
else printf ("Matrica nije ni cirkularna ni Teplicova");}


return 0;
}
