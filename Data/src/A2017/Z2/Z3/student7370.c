#include <stdio.h>

int main() {
	int A[100][100],B[100][100],M1,M2,N1,N2;
	int i,j;
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d",&M1,&N1);
	
	printf("Unesite clanove matrice A: ");
	for(i=0;i<M1;i++){
		for(j=0;j<N1;j++){
			scanf("%d",&A[i][j]);
		}
	}
	
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d",&M2,&N2);
	
	printf("Unesite clanove matrice B: ");
	for(i=0;i<M2;i++){
		for(j=0;j<N2;j++){
			scanf("%d",&B[i][j]);
		}
	}
	
	int A90[100][100]={0};
	
	for(i=0;i<M1;i++){
		for(j=0;j<N1;j++){
			A90[i][j]=A[j][i];
		}
	}
	i=0;
	j=N1-1;
	while(j>i){
	int k,temp;
	for(k=0;k<M1;k++){
		temp=A90[k][i];
		A90[k][i]=A90[k][j];
		A90[k][j]=temp;
	}
	i++;
	j--;
		
	}
	
	
	
	for(i=0;i<M2;i++){
		for(j=0;j<N2;j++){
			if(A90[i][j]!=B[i][j]){
				printf("NE\n");
				return 0;
			}
		}
	}
	printf("DA\n");
	return 0;
}
