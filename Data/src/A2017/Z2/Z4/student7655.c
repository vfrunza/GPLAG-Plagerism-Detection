#include <stdio.h>

int main() {
	int A[100][100];
	int B[100][100];
	int C[100][100];
	int i,j,m,n,b=0;
	int nizA[1000],nizB[1000],nizC[1000];
	int tacnost=1, temp=0;
	
	do{
	printf("Unesite brojeve M i N: ");
	scanf("%d%d",&m,&n);
	} while (m<0 || n<0 || m>100 || n>100);
	
	/* unos elemenata matrica A, B i C formata MxN */
	printf ("Unesite clanove matrice A: ");
	b = 0;
	for (i=0;i<m;i++){
	for (j=0;j<n;j++){
		scanf("%d",&A[i][j]);
		nizA[b++]=A[i][j];
	}}
	b = 0;
	printf ("Unesite clanove matrice B: ");
	for (i=0;i<m;i++){
	for (j=0;j<n;j++){
		scanf("%d",&B[i][j]);
		nizB[b++]=B[i][j];
	}}
	b = 0;
	printf ("Unesite clanove matrice C: ");
	for (i=0;i<m;i++){
	for (j=0;j<n;j++){
		scanf("%d",&C[i][j]);
		nizC[b++]=C[i][j];
	}}
	

	for (i=0; i<b-1; i++){
		for (j=i+1; j<b; j++)
		{
			if (nizA[j]<nizA[i]) {
				temp = nizA[i];
				nizA[i] = nizA[j];
				nizA[j] = temp;
			}
		}
	}
	for (i=0; i<b-1; i++){
		for (j=i+1; j<b; j++)
		{
			if (nizB[j]<nizB[i]) {
				temp = nizB[i];
				nizB[i] = nizB[j];
				nizB[j] = temp;
			}
		}
	}	
	for (i=0; i<b-1; i++){
		for (j=i+1; j<b; j++)
		{
			if (nizC[j]<nizC[i]) {
				temp = nizC[i];
				nizC[i] = nizC[j];
				nizC[j] = temp;
			}
		}
	}
	
	for (i=0; i<n; i++){
		if (nizB[i]!=nizA[i] || nizC[i]!=nizA[i]) tacnost=0;}
	
	
	if (tacnost) printf("DA\n");
	else printf("NE\n");
	
	return 0;
}
