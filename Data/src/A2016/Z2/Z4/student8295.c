#include <stdio.h>

int main() {
	double a[200][200];
	int i,j,M,N,brojac,teplicova,cirkularna;
	do{
	    printf("Unesite M i N: ");
	    scanf("%d %d",&M,&N);
	    if(M<1 || N<1 || M>100 || N>100){printf("Pogresan unos!\n");}
	}
	while(M>100 || N>100 || N<1 || M<1);
	printf("Unesite elemente matrice: ");
	
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
			scanf("%lf",&a[i][j]);
		}
	}
	
	teplicova=1;
	cirkularna=1;
	for(i=0;i<M-1;i++){
		for(j=0;j<N-1;j++)
		if(a[i][j]!=a[i+1][j+1]) teplicova = 0;
	}
	double pomocni[11000];
for(i=0;i<105;i++)
{
	for(j=i*N;j<(i+1)*N;j++) pomocni[j] = a[0][j-i*N];
}
	brojac = N*(M+1);
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
			if(a[i][j]!=pomocni[j+brojac]) cirkularna = 0;
		}
		brojac--;
	}
	
	if(cirkularna==1) printf("Matrica je cirkularna");
	else if(teplicova==1) printf("Matrica je Teplicova");
	else printf("Matrica nije ni cirkularna ni Teplicova");
	
	return 0;
}
