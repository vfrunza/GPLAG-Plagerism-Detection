#include <stdio.h>
#include <stdbool.h>
#define MAX 100

int main() {
	bool iste1=1, iste2=1;
	int M,N,matricaA[MAX][MAX],matricaB[MAX][MAX],matricaC[MAX][MAX],i,j,k,l,m,n,b;
	int brojaciA[1000]={0},brojaciB[1000]={0},brojaciC[1000]={0};

	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&M,&N);
		
	}while(M<0 || M>100 || N<0 || N>100);
	printf("Unesite clanove matrice A: ");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			scanf("%d",&matricaA[i][j]);
			
			
		}
		
	}
	printf("Unesite clanove matrice B: ");
	for(k=0;k<M;k++) {
		for(l=0;l<N;l++){
			scanf("%d",&matricaB[k][l]);
		}
	}
	printf("Unesite clanove matrice C: ");
	for(m=0;m<M;m++){
		for(n=0;n<N;n++){
			scanf("%d",&matricaC[m][n]);
		}
	}

	 for(k=0;k<M;k++){
	 	for(l=0;l<N;l++){
	 		for(b=0;b<1000;b++)
	 			if (matricaB[k][l]==b) brojaciB[b]++;
	 		}
	 		
	 	}
	 	
	
	
	 for(m=0;m<M;m++){
	 	for(n=0;n<N;n++){
	 		for(b=0;b<1000;b++){
	 			if(matricaC[m][n]==b) brojaciC[b]++;
	 		}
	 	}
	 	
	 }
	
	 for(i=0;i<M;i++){
	 	for(j=0;j<N;j++){
	 		for(b=0;b<1000;b++){
	 		if (matricaA[i][j]==b) brojaciA[b]++;
	 			
	 		}
	 		
	 	}
	 	
	 }
	 for(b=0;b<1000;b++){
	 			if(brojaciA[b]!=brojaciB[b]) { 
	 				iste1=0;
	 				printf("NE\n");
	 				return 0; }
	 			else {
	 				iste1=1;
	 				
	 			}
	 	
	 }
	 for(b=0;b<1000;b++){
	 
	 			if (brojaciA[b]!=brojaciC[b]) {
	 				iste2=0;
	 				printf("NE\n");
	 				return 0;
	 				
	 			}
	 			else {
	 
	 			iste2=1;
	 			}
	 }
	 if(iste1==1 && iste2==1) printf("DA\n"); 
	return 0;
}
