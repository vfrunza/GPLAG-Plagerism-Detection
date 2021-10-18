#include <stdio.h>
#define BROJ_EL 50

int main() {
	float A[BROJ_EL][BROJ_EL], B[BROJ_EL][BROJ_EL];
	int i, j, sirina_a, visina_a, sirina_b, visina_b, brojac=0;
	
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &sirina_a, &visina_a);
	printf("Unesite clanove matrice A: ");
	for(i=0; i<visina_a; i++)
	{
		for(j=0; j<sirina_a; j++)
		{
			scanf("%f", &A[i][j]);
		}
	}
	
	
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d", &sirina_b, &visina_b);
	printf("Unesite clanove matrice B: ");
	for(i=0; i<visina_b; i++)
	{
		for(j=0; j<sirina_b; j++)
		{
			scanf("%f", &B[i][j]);
		}
	}
	
	
	if(visina_a!=sirina_b || sirina_a!=visina_b) 
	{
		printf("NE");
	}
	else
	{
		for(i=0; i<sirina_a; i++)
		{
			for(j=visina_a-1; j>-1; j--)
			{
				if(A[j][i]==B[i][visina_a-1-j]) brojac++;
			} 
		}
		
		if(brojac==visina_b*sirina_b) printf("DA");
		else printf("NE");
	}
	
	
	return 0;
}
