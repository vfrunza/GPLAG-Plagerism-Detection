#include <stdio.h>


#define BR_RED 100
#define BR_KOL 100
int main() {
	int A[BR_RED][BR_KOL], B[BR_RED][BR_KOL], C[BR_RED][BR_KOL];
	int nizA[BR_RED*BR_KOL],nizB[BR_RED*BR_KOL],nizC[BR_RED*BR_KOL];
	int velA=0,velB=0,velC=0;
	int M,N,i,j,min,temp,iste;
	
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&M,&N);
	}while( M<0 || N<0 || M>100|| N>100 );

	printf("Unesite clanove matrice A: ");
	for (i = 0; i < M; i++) {
		for ( j = 0; j < N; j++) {
			scanf("%d",&A[i][j]);
			nizA[velA++]=A[i][j];
		}
	}
	
	printf("Unesite clanove matrice B: ");
	for (i = 0; i < M; i++) {
		for ( j = 0; j < N; j++) {
			scanf("%d",&B[i][j]);
			nizB[velB++]=B[i][j];
		}
	}
	
	
	printf("Unesite clanove matrice C: ");
	for (i = 0; i < M; i++) {
		for ( j = 0; j < N; j++) {
			scanf("%d",&C[i][j]);
			nizC[velC++]=C[i][j];
		}
	}
	
	
	for ( i = 0; i < velA; i++) {
		min=i;
		for(j=i+1;j<velA;j++){
			if(nizA[j]<nizA[min]){
				min=j;
			}
		}
		temp=nizA[i];
		nizA[i]=nizA[min];
		nizA[min]=temp;
	}
	for ( i = 0; i < velB; i++) {
		min=i;
		for(j=i+1;j<velB;j++){
			if(nizB[j]<nizB[min]){
				min=j;
			}
		}
		temp=nizB[i];
		nizB[i]=nizB[min];
		nizB[min]=temp;
	}
	for ( i = 0; i < velC; i++) {
		min=i;
		for(j=i+1;j<velC;j++){
			if(nizC[j]<nizC[min]){
				min=j;
			}
		}
		temp=nizC[i];
		nizC[i]=nizC[min];
		nizC[min]=temp;
	}
	
	iste=1;
	

	for ( i = 0; i < velA; i++) {
		if(nizA[i]!=nizB[i] || nizA[i]!=nizC[i]){
			iste=0;
			break;
		}
	}
	
	if(iste){
		printf("DA");
	}
	else{
		printf("NE");
	}
	
	return 0;
}
