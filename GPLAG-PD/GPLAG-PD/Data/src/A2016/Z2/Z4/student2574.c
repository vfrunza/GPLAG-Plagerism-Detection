#include <stdio.h>

int main() {
double mat[100][100];
int M=0,N=0;
int i=0,j=0,TEPLICOVA=1,CIRKULARNA=1;
do
{
printf ("Unesite M i N: ");
scanf ("%d %d",&M,&N);
if ((M>100 || M<1) || (N>100 || N<1))
printf ("Pogresan unos!\n");
}
while ((M>100 || M<1) || (N>100 || N<1));
printf ("Unesite elemente matrice: ");
for (i=0; i<M; i++) {
for (j=0; j<N; j++) 
scanf ("%lf", &mat[i][j]);}
for (i=0; i<M-1; i++) {
for (j=0; j<N-1; j++)  
{
if  ((mat[i][j]!=mat[i+1][j+1]) || (mat[i][N-1]!=mat[i+1][0]))
{CIRKULARNA=0;}
if (mat[i][j]!=mat[i+1][j+1])
{TEPLICOVA=0;}}}
if ((TEPLICOVA==1) && (CIRKULARNA==0))
printf ("Matrica je Teplicova");
if (M==100 && N==1)
printf ("Matrica je Teplicova");
else if (CIRKULARNA==1)
printf ("Matrica je cirkularna");
else if (TEPLICOVA==0 && CIRKULARNA==0)
printf ("Matrica nije ni cirkularna ni Teplicova");
return 0;}