#include <stdio.h>

int main() {
int M,N,i,j;
double a[105][105];
while(1)
{
    printf("Unesite M i N: ");
    scanf("%d%d",&N,&M);
    if(M>100||N>100||N<=0||M<=0) printf("Pogresan unos!\n");
    else break;
}
	printf("Unesite elemente matrice: ");
	for(i=0;i<N;i++) for(j=0;j<M;j++) scanf("%lf",&a[i][j]);
    int Teplic = 1;
    for(i=0;i+1<N;i++)
    for(j=0;j+1<M;j++)
    {
        if(a[i][j]!=a[i+1][j+1])
        {
            Teplic = 0;
            break;
        }
    }

int circular = 1;
for(i=1;i<N;i++)
{
    for(j=0;j<M;j++)
    {
        if(a[0][j]!=a[i][(i+j)%M]) 
        {
            circular = 0;
            break;
        }
    }
}

if(circular) printf("Matrica je cirkularna");
else if(Teplic) printf("Matrica je Teplicova");
else printf("Matrica nije ni cirkularna ni Teplicova");

	return 0;
}
