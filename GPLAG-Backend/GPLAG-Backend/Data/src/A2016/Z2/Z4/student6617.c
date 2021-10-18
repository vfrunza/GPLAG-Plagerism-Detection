#include <stdio.h>

#define BE 100
int main() {
	int M,N,t,u,cirk,tepl;
	double matrica[BE][BE];
	do{
	printf("Unesite M i N: ");
	scanf("%d %d",&M,&N);
	if(M>100 || M<=0 || N>100 || N<=0)
	printf("Pogresan unos!\n");
	}while(M>100 || M<=0 || N>100 || N<=0);
	printf("Unesite elemente matrice: ");
	cirk=1;
	tepl=1;
	
	for(t=0;t<M;t++)
	{
		for(u=0;u<N;u++)
		{
			scanf("%lf",&matrica[t][u]);
		}
	}
	for(t=0;t<M-1;t++)
	{
		for(u=0;u<N-1;u++)
		{
			if((matrica[t][N-1]!=matrica[t+1][0]) || (matrica[t][u]!=matrica[t+1][u+1]))
			cirk=0;
			
		}
	}
	for(t=0;t<M-1;t++)
	{
		for(u=0;u<N-1;u++)
		{
			if(matrica[t][u]!=matrica[t+1][u+1])
			tepl=0;
			
		}
	}
	if((tepl==1 && cirk==0) || (M==100 && N==1))
	printf("Matrica je Teplicova");
	else if(cirk==1 && tepl==1)
	printf("Matrica je cirkularna");
	else
	printf("Matrica nije ni cirkularna ni Teplicova");
	return 0;
}