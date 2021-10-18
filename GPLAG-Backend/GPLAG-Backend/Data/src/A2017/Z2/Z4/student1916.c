#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define MAXI 10000
int main() {
	int m, n, A[MAX][MAX], B[MAX][MAX], C[MAX][MAX], i, j, b=0, Ai[MAXI],  Bi[MAXI],  Ci[MAXI], mina, minb, minc, ma, mb, mc;
	do{
		printf("Unesite brojeve M i N: ");		
		scanf("%d %d", &m, &n);
	} while(m<0 || n<0 || m>100 || n>100);
	printf("Unesite clanove matrice A: ");
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			scanf("%d", &A[i][j]);
		}
	}

	printf("Unesite clanove matrice B: ");
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			scanf("%d", &B[i][j]);
		}
	}
	printf("Unesite clanove matrice C: ");
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			scanf("%d", &C[i][j]);
		}
	}
	
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			Ai[b]=A[i][j];
			Bi[b]=B[i][j];
			Ci[b]=C[i][j];
			b++;
		}
	}
	
	for(i=0; i<b; i++){
		mina=i;
		for(j=i+1; j<b; j++){
			if(Ai[j]<Ai[mina]) mina=j;
		}
		ma=Ai[i];
		Ai[i]=Ai[mina];
		Ai[mina]=ma;
	}
	for(i=0; i<b; i++){
		minb=i;
		for(j=i+1; j<b; j++){
			if(Bi[j]<Bi[minb]) minb=j;
		}
		mb=Bi[i];
		Bi[i]=Bi[minb];
		Bi[minb]=mb;
	}
	for(i=0; i<b; i++){
		minc=i;
		for(j=i+1; j<b; j++){
			if(Ci[j]<Ci[minc]) minc=j;
		}
		mc=Ci[i];
		Ci[i]=Ci[minc];
		Ci[minc]=mc;
	}
	
	j=1;
	for(i=0; i<b; i++){
		if(Ai[i]!=Bi[i] || Ai[i]!=Ci[i]){
			j=0;
			break;
		}
	}
	if(j) printf("DA\n");
	else printf("NE\n");
	return 0;
}
