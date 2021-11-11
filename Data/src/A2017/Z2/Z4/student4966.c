#include <stdio.h>
#include <stdlib.h>


int main() {
	int A[100][100], B[100][100], C[100][100], pomocnaA[20000], pomocnaB[20000],pomocnaC[20000];
	int velicinaA=0, velicinaB=0, velicinaC=0, m, n, i, j, k;
	int l, ubaci, x, brojac, uslov1,imaB, uslov2,imaC;

		while (1) {
		printf("Unesite brojeve M i N:");
		scanf("%d%d",&m, &n);
		if (m<=100 && m>=0 && n<=100 && n>=0) break;
		}
		
	
		printf("Unesite clanove matrice A: ");
		   for ( i=0; i<m; i++) {
				for ( j=0; j<n; j++) {
					scanf("%d", &A[i][j]);
				}
			}
	
		printf("Unesite clanove matrice B: ");
		   for (i=0; i<m; i++) {
				for (j=0; j<n; j++) {
					scanf("%d", &B[i][j]);
				}
			}
	
		printf("Unesite clanove matrice C: ");
		   for (i=0; i<m; i++) {
				for ( j=0; j<n; j++) {
					scanf("%d", &C[i][j]);
				}
			}
			
			
			  for (i=0; i<m; i++) {
				for ( j=0; j<n; j++) {
					ubaci = 0;
					x = A[i][j];
					brojac = 0;
					for (k=0; k<velicinaA; k++) {
					 if(k%2==0) {
					 	if(x==pomocnaA[k])
					 		ubaci = 0;
					 }
					}
					for(k=1; k<=m; k++) {
						for(l=2; l<n+2; l++) {
						if(x==A[k-1][l-2])
						brojac++;
						}
					}
					if(ubaci == 1) {
						pomocnaA[velicinaA++]=x;
						pomocnaA[velicinaA++]=brojac;
					}
					}
					
						}
						for(i=0;i<m;i++){
						for(j=0;j<n;j++){
			x=B[i][j];
			ubaci=1;
			brojac=0;
			for(k=0;k<velicinaB;k+=2){
				if(x==pomocnaB[k]) ubaci=0;
			}
			for(k=0;k<m;k++){
				for(l=0;l<n;l++) if(x==B[k][l]) brojac++;
			}
	if(ubaci){
				pomocnaB[velicinaB++]=x;
				pomocnaB[velicinaB++]=brojac;
			}
		}
	}
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			x=C[i][j];
			ubaci=1;
			brojac=0;
			for(k=0;k<velicinaC;k+=2){
				if(x==pomocnaC[k]) ubaci=0;
			}
			for(k=0;k<m;k++){
				for(l=0;l<n;l++) if(x==C[k][l]) brojac++;
			}
			if(ubaci){
				pomocnaC[velicinaC++]=x;
				pomocnaC[velicinaC++]=brojac;
			}
		}
	}


for(i=0;i<velicinaB;i+=2){
		uslov1=1;
		imaB=0;
		for(j=0;j<velicinaA;j+=2){
			if(pomocnaB[i]==pomocnaA[j]){
				imaB=1;
				if(pomocnaB[i+1]!=pomocnaA[j+1]){
					uslov1=0;
					break;
				}
			}
		}
	if(imaB==0) uslov1=0;
		if(uslov1==0) break;
	}
	for(i=0;i<velicinaC;i+=2){
		uslov2 = 1;
		imaC=0;
		for(j=0;j<velicinaA;j+=2){
			if(pomocnaC[i]==pomocnaA[j]){
				imaC=1;
				if(pomocnaC[i+1]!=pomocnaA[j+1]){
					uslov2=0;
					break;
				}
			}
		}
		if(imaC==0) uslov2=0;
		if(uslov2==0) break;
	}
	if(uslov1==0 || uslov2==0) printf("NE");
	else printf("DA");


	return 0;

	
	
}


					
	
