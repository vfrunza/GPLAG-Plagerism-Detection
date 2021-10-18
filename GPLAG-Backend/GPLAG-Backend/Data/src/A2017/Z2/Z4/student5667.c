#include<stdio.h>
int A[10000],B[10000],C[10000];
int main(){int p=1;
	int m,n;
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&m,&n);
	}while(m<0 || m>100 || n<0 || n>100);
	int i,j;
	printf("Unesite clanove matrice A: ");
	for(i=0;i<m*n;i++)
			scanf("%d",&A[i]);
	printf("Unesite clanove matrice B: ");
	for(i=0;i<m*n;i++)
			scanf("%d",&B[i]);
	printf("Unesite clanove matrice C: ");
	for(i=0;i<m*n;i++)
			scanf("%d",&C[i]);
	for(i=0;i<m*n-1;i++)
		for(j=i+1;j<m*n;j++)if(A[i]>A[j]){A[i] = A[i] ^ A[j];A[j] = A[i] ^ A[j];A[i] = A[i] ^ A[j];}
	for(i=0;i<m*n-1;i++)
		for(j=i+1;j<m*n;j++)if(B[i]>B[j]){B[i] = B[i] ^ B[j];B[j] = B[i] ^ B[j];B[i] = B[i] ^ B[j];}
	for(i=0;i<m*n-1;i++)
		for(j=i+1;j<m*n;j++)if(C[i]>C[j]){C[i] = C[i] ^ C[j];C[j] = C[i] ^ C[j];C[i] = C[i] ^ C[j];}
	for(i=0;i<m*n;i++)if(A[i]!=B[i])p=0;
	for(i=0;i<m*n;i++)if(A[i]!=C[i])p=0;
	if(p)printf("DA");
	else printf("NE");
	return 0;
}