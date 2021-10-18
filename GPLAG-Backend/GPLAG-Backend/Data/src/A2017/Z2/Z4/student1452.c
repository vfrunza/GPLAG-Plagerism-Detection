#include <stdio.h>
#define BROJ_EL 100

int main() {
	int A[BROJ_EL][BROJ_EL],B[BROJ_EL][BROJ_EL],C[BROJ_EL][BROJ_EL],br=0,pr=0,sr=0,p=0,s=0,i,j,M,N,sa=0,sb=0,sc=0;
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&M,&N);
	} while(M<0 || M>100 || N<0 || N>100);
	printf("Unesite clanove matrice A: ");
	
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			scanf("%d",&A[i][j]);
			sa+=A[i][j];
			
		}
	}
	printf("Unesite clanove matrice B: ");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			scanf("%d",&B[i][j]);
			sb+=B[i][j];
		}
	}
	printf("Unesite clanove matrice C: ");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			scanf("%d",&C[i][j]);
			sc+=C[i][j];
		}
	}
	for(i=0;i<M;i++){
		
		for(j=0;j<N;j++){
			p=0;s=0;
			while(s<M){
				if(A[i][j]==A[s][p]) pr++;
				if(A[i][j]==B[s][p]) br++;
				if(A[i][j]==C[s][p]) sr++;
				p++;
				if(p==N){
					p=0;s=s+1;
				}
			}
		}
	}
	if(br==sr && sr==pr && sa==sb && sa==sc ) printf("DA");
	else printf("NE");
	
return 0;
}
