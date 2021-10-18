#include <stdio.h>

int main() {
	int m, n, i, j, k, l, brojA=0, brojB=0, d=0, brojC=0, jednak=0, A[100][100], B[100][100], C[100][100], D[1000];
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &m, &n);
	}while (m>100 || n>100);
	printf("Unesite clanove matrice A: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&A[i][j]);
		}
	}
	printf("Unesite clanove matrice B: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&B[i][j]);
		}
	}
	printf("Unesite clanove matrice C: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&C[i][j]);
		}
	}
	
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			jednak=0;
			for(k=0;k<i;k++){
				for(l=0;l<n;l++){
					if (A[i][j]==A[k][l])
						jednak++;
				}
			}
			k=i;
			for(l=0;l<=j;l++){
				if (A[i][j]==A[k][l])
					jednak++;
			}
			if(jednak==1){
				D[d]=A[i][j];
				d++;
			}
		}
	}
	
	for(i=0;i<d;i++){
		brojA=0;
		brojB=0;
		brojC=0;
			for(j=0;j<m;j++){
				for(k=0;k<n;k++){
					if(D[i]==A[j][k]) brojA++;
				}
			}
			for(j=0;j<m;j++){
				for(k=0;k<n;k++){
					if(D[i]==B[j][k]) brojB++;
				}
			}
			for(j=0;j<m;j++){
				for(k=0;k<n;k++){
					if(D[i]==C[j][k]) brojC++;
				}
			} 
			if(brojA!=brojB || brojB!=brojC || brojA!=brojC){
				printf("NE");
				return 0;
			}
	}
	printf("DA");

	return 0;
}
