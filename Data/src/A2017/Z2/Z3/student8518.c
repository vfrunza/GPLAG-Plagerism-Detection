#include <stdio.h>

int main() 
{
	int A[100][100], B[100][100], a, b, c, d, i, j, k, temp, s=0;
	
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &a, &b);
	
	printf("Unesite clanove matrice A: ");
	for(i=0; i<b; i++) for(j=0; j<a; j++) scanf("%d", &A[i][j]);
	
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d", &c, &d);
	
	printf("Unesite clanove matrice B: ");
	for(i=0; i<d; i++) for(j=0; j<c; j++) scanf("%d", &B[i][j]);
	
	if(a!=c || b!=d)
	{
		printf("NE");
		return 0;
	}
	
	for(i=0; i<a; i++)
	{
		for(j=i; j<b; j++)
		{
			temp=A[i][j];
			A[i][j]=A[j][i];
			A[j][i]=temp;
		}
	}
	
	for(i=0; i<b; i++)
	{
		for(j=0, k=b-1; j<k; j++, k--)
		{
			temp=A[i][j];
			A[i][j]=A[i][k];
			A[i][k]=temp;
		}
	}
	
	for(i=0; i<b; i++)
	{
		for(j=0; j<a; j++)
		{
			if(A[i][j]!=B[i][j]) s++;
		}
	}
	
	if(s>0) printf("NE");
	else printf("DA");
	
	printf("\n");
	
	return 0;
}