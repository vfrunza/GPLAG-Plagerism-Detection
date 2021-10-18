#include <stdio.h>

int main() {
	int m,n,i,j,k;
	int A[100][100],B[100][100],C[100][100];
	int nizA[10000],nizB[10000],nizC[10000],a=0,b=0,c=0;
	int postavi,ubaci;
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&m,&n);
	}while(m>100 || n>100);
	printf("Unesite clanove matrice A: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&A[i][j]);
			nizA[a]=A[i][j];
			a++;
		}
	}
	for(i=1;i<a;i++){
		postavi=nizA[i];
		ubaci=i;
		while(ubaci>0 && nizA[ubaci-1]>postavi){
			nizA[ubaci]=nizA[ubaci-1];
			ubaci--;
		}
		nizA[ubaci]=postavi;
	}
	printf("Unesite clanove matrice B: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&B[i][j]);
			nizB[b]=B[i][j];
			b++;
		}
	}
	for(i=1;i<b;i++){
		postavi=nizB[i];
		ubaci=i;
		while(ubaci>0 && nizB[ubaci-1]>postavi){
			nizB[ubaci]=nizB[ubaci-1];
			ubaci--;
		}
		nizB[ubaci]=postavi;
	}
	printf("Unesite clanove matrice C: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&C[i][j]);
			nizC[c]=C[i][j];
			c++;
		}
	}
	for(i=1;i<c;i++){
		postavi=nizC[i];
		ubaci=i;
		while(ubaci>0 && nizC[ubaci-1]>postavi){
			nizC[ubaci]=nizC[ubaci-1];
			ubaci--;
		}
		nizC[ubaci]=postavi;
	}
	if(m==0 && n==0){
		printf("DA");
		return 0;
	}
	for(i=0;i<a;i++){
		if(nizA[i]!=nizB[i] || nizA[i]!=nizC[i]){
			printf("NE\n");
			return 0;
		}
	}
	printf("DA");
	return 0;
}
