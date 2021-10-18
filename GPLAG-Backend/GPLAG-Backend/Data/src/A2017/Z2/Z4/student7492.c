#include <stdio.h>

int main() {
	int M,N,i,sumaA,sumaB,sumaC;
	int A[100]={0},B[100]={0},C[100]={0},brojaciA[101]={0},brojaciB[101]={0},brojaciC[101]={0};
	do
	{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&M,&N);
		if(M>0 && M<100 && N>0 && N<100)
		{
			break;
		}
	}while(M<0 || M>100 || N<0 || N>100);
	
	printf("Unesite clanove matrice A: ");
	for(i=0;i<(M*N);i++)
	{
		scanf("%d",&A[i]);
		brojaciA[A[i]]++;
	}
	
	printf("Unesite clanove matrice B: ");	
	for(i=0;i<(M*N);i++)
	{
		scanf("%d",&B[i]);
		brojaciB[B[i]]++;
	}
	
	printf("Unesite clanove matrice C: ");	
	for(i=0;i<(M*N);i++)
	{
		scanf("%d",&C[i]);
		brojaciC[C[i]]++;
	}
	
	for(i=0;i<100;i++)
	{
		if(brojaciA[A[i]]!=0) { sumaA+=brojaciA[A[i]]; }
		if(brojaciB[B[i]]!=0) {	sumaB+=brojaciB[B[i]]; }
		if(brojaciC[C[i]]!=0) { sumaC+=brojaciC[C[i]]; }
	}
	
	if(sumaA==sumaB && sumaB==sumaC && sumaA==sumaC) { printf("DA"); }
	else { printf("NE"); }
	return 0;
}