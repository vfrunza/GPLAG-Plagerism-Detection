#include <stdio.h>

int main() {
	
	int A[100][100],B[100][100],C[100][100],i,j,M,N,niz1[1000],niz2[1000],niz3[1000],br=0,pom;
	
	
	
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&M,&N);
	}while(M<0 || M>100 || N<0 || N>100);
	
	printf("Unesite clanove matrice A: ");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			scanf("%d",&A[i][j]);
		
		}
	}
	printf("Unesite clanove matrice B: ");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			scanf("%d",&B[i][j]);
		}
	}
	
	printf("Unesite clanove matrice C: ");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			scanf("%d",&C[i][j]);
		}
	}

	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			niz1[br]=A[i][j];
			br++;
		}
	}
	 for(i=0;i<br;i++){
	 	for(j=i;j<br;j++){
	 		if(niz1[i]>niz1[j]){
	 			pom=niz1[i];
	 			niz1[i]=niz1[j];
	 			niz1[j]=pom;
	 		}
	 	}
	 }
	 br=0;
	 for(i=0;i<M;i++){
	 	for(j=0;j<N;j++){
	 		niz2[br]=B[i][j];
	 		br++;
	 	}
	 }
	 for(i=0;i<br;i++){
	 	for(j=i;j<br;j++){
	 		if(niz2[i]>niz2[j]){
	 			pom=niz2[i];
	 			niz2[i]=niz2[j];
	 			niz2[j]=pom;
	 		}
	 	}
	 }
	br=0;
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			niz3[br]=C[i][j];
			br++;
		}
	}
	
	for(i=0;i<br;i++){
		for(j=i;j<br;j++){
			if(niz3[i]>niz3[j]){
				pom=niz3[i];
				niz3[i]=niz3[j];
				niz3[j]=pom;
			}
		}
	}
	
	for(i=0;i<br;i++){
		if(niz1[i]!=niz2[i] || niz1[i]!=niz3[i] ) {printf("NE"); return 0; }
	
		
	}
	printf("DA");
	
	
	
	
	
	
	
	
	return 0;
}
