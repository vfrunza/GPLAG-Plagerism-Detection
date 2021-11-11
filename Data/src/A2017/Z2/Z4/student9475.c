#include <stdio.h>
#define BROJ_EL 100
#define BROJAC 1000

int main() {
	int A[BROJ_EL][BROJ_EL], B[BROJ_EL][BROJ_EL], C[BROJ_EL][BROJ_EL], M, N, i, j;
	int brojac_ap[BROJAC]={0}, brojac_bp[BROJAC]={0}, brojac_cp[BROJAC]={0}, brojac_an[BROJAC]={0}, brojac_bn[BROJAC]={0}, brojac_cn[BROJAC]={0}, brojac=0;
	
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &M, &N);
	} while(M>100 || N>100 || M<0 || N<0);
	
	
	printf("Unesite clanove matrice A: ");
	for(i=0; i<M; i++)
	{
		for(j=0; j<N; j++)
		{
			scanf("%d", &A[i][j]);
			if(A[i][j]>0) brojac_ap[A[i][j]]++;
			else brojac_an[(A[i][j]*(-1))]++;
		}
	}

	
	printf("Unesite clanove matrice B: ");
	for(i=0; i<M; i++)
	{
		for(j=0; j<N; j++)
		{
			scanf("%d", &B[i][j]);
			if(B[i][j]>0) brojac_bp[B[i][j]]++;
			else brojac_bn[(B[i][j]*(-1))]++;
		}
	}
	
	printf("Unesite clanove matrice C: ");
	for(i=0; i<M; i++)
	{
		for(j=0; j<N; j++)
		{
			scanf("%d", &C[i][j]);
			if(C[i][j]>0) brojac_cp[C[i][j]]++;
			else brojac_cn[(C[i][j]*(-1))]++;
		}
	}
	
	
	for(i=0; i<BROJAC; i++)
	{
		if(brojac_ap[i]==brojac_bp[i] && brojac_an[i]==brojac_bn[i] && brojac_ap[i]==brojac_cp[i] && brojac_an[i]==brojac_cn[i]) 
		{
			brojac++;
		}
		else
		{
			printf("NE\n");
			return 0;
		}
	}
	printf("DA\n");
	
	
	return 0;
}
