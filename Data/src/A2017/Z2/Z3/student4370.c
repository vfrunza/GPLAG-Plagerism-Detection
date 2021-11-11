#include <stdio.h>

int main() {
	int mat_A[100][100],mat_B[100][100];
	int m1,n1,n2,m2,i,j,k,l;
    int brojac=0;
    
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &n1,&m1);
	printf("Unesite clanove matrice A: ");
	for(i = 0 ; i < m1 ; i++){
		for(j = 0 ; j < n1 ; j++){
			scanf("%d", &mat_A[i][j]);
		}
	}
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d", &n2,&m2);
	printf("Unesite clanove matrice B: ");
	for(k = 0 ; k < m2 ; k++){
		for(l = 0 ; l < n2 ; l++){
			scanf("%d", &mat_B[k][l]);
		}
	}

	k=0;
	for (i=0; i<m2;i++){
	
		for(j=0; j<n2; j++){
			if(j>m1-1) {
				i++;
			break;
			}
			else if(mat_A[j][k]==mat_B[i][n2-1-j]){
					brojac++;
		}
		} 
		k++;
	}
	
	if(brojac==n1*m1) printf("DA\n");
	else printf("NE\n");
	brojac=0;
	return 0;
}
