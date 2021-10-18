#include <stdio.h>

int main() {
	double matricat[100][100], suma_redova[100]={0};
	int M,N,i, j, tep=1,cir=1;
	do{
		printf("Unesite M i N: ");
		scanf("%d", &M);
		scanf("%d", &N);
		if(M>100 || N>100 || M<1 || N<1)
		printf("Pogresan unos!\n");
	}while(M>100 || N>100 || M<1 || N<1);
	/*unos elemenata*/
	
	printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++){for(j=0;j<N;j++){
	scanf("%lf",&matricat[i][j]);}}
	
	
	for(i=0;i<M-1;i++){for(j=0;j<N-1;j++)
		{
			if(matricat[i][j]!=matricat[i+1][j+1])
			tep=0;
		}
	}
	/*redovi imaju iste clanove=> suma redova je jednaka*/
	if(tep)
	{
		for(i=0;i<M-1;i++){for(j=0;j<N-1;j++){
			suma_redova[i]=suma_redova[i]+matricat[i][j];
		}}
		for(i=0;i<M-1;i++){
			if(suma_redova[i]!=suma_redova[i+1])
			cir=0;
		}
	}
	if(tep==1 && cir==1)printf("Matrica je cirkularna");
	else if(tep==1 && cir==0)printf("Matrica je Teplicova");
	else printf("Matrica nije ni cirkularna ni Teplicova");
	return 0;
}
