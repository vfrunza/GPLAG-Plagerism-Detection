#include <stdio.h>
#include <math.h>
#define eps 0.001

int main() {
	double a[101][101];
 
	int b,c,e,M,N;
	
	do
	{printf("Unesite M i N: ");
	scanf("%d %d",&M,&N);
	if(M>100 || M<1 || N>100 || N<1)
	printf("Pogresan unos!\n");
	}
	while(M>100 || M<1 || N>100 || N<1);
	printf("Unesite elemente matrice: ");
	for(b=1;b<=M;b++)
	{
		for(c=1;c<=N;c++)
		{
			scanf("%lf",&a[b][c]);
		}
	}


e=100;	
for(c=1;c<=N-1;c++)
{
for(b=1;b<=M-1;b++)
{if(fabs(a[b][c]-a[b+1][c+1])>eps)
e=0;
	}}
if (e==100)
for(b=1;b<=M-1;b++)
{if(fabs(a[b][N]-a[b+1][1])>eps)
break;
else
e++;}

if(e==M+99)
printf("Matrica je cirkularna");
else
{if (e==0)
printf("Matrica nije ni cirkularna ni Teplicova");
else
printf("Matrica je Teplicova");
}
	
	
	
	
	return 0;
}
