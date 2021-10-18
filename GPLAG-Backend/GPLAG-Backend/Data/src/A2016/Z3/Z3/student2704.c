#include <stdio.h>
#define V 200 /*Max. dimenzije matrice*/

int main() {
	int m, n, i, j, k, isti=1, a, b;
	double mat[V][V];
	
	/*Unos dimenzija matrice*/ 
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &m, &n);
		if(m<=0 || m>200 || n<=0 || n>200) {printf("Brojevi nisu u trazenom opsegu.\n");}
	} while (m<=0 || m>200 || n<=0 || n>200);
	
	/*Unos elemenata matrice*/
	printf("Unesite elemente matrice: ");
	
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			scanf("%lf", &mat[i][j]);
		}
	}
	
	/*Provjera redova matrice*/
	for(i=0; i<m; i++) {  /*po redovima, spora petlja*/
		for(k=i+1; k<m; k++) { /*po redovima ali od i+1, poredbena petlja*/
			isti=1;				
			for(j=0; j<n; j++) { 
				
				if (mat[i][j]!=mat[k][j]) {
				isti=0; break;}}
			
			if(isti==1) {  /*Redovi su isti-izbacivanje uz ocuvanje redoslijeda*/
				for(a=k; a<m-1; a++){ 
					for(b=0; b<n; b++){
						mat[a][b]=mat[a+1][b];
					}	
				}				
					m--;				
					k--;
			}
		}
	}		

	if(m==1) goto jednodm; /*ako je 1 red ostao-jednodimenz izbacivanje, preskace se slj for petlja*/
	
	/*Provjera kolona matrice*/
	for(j=0; j<n; j++) { /*po kolonama, spora petlja*/
		for(k=j+1; k<n; k++) { /*po kolonama ali od j+1, poredbena petlja*/
			isti=1; 
			for(i=0; i<m; i++) { 
				if (mat[i][j]!=mat[i][k]) {
				isti=0; break;}
			}
			
			if(isti==1) { /*Kolone su iste-izbacivanje uz ocuvanje redoslijeda*/
				for(a=k; a<n-1; a++){
					for(b=0; b<m; b++){
						mat[b][a]=mat[b][a+1];	
					}
				}
					n--;
					k--;
			}
		}
	}
	
	/*Samo ako matrica ima jedan red*/
	jednodm:
	if(m==1){ 
	for(i=0;i<n;i++){ 
		for(j=i+1;j<n;j++){ 
			if(mat[0][i]==mat[0][j]){ /*2 elementa ista-izbacivanje uz ocuvanje redoslijeda*/
				for(a=j;a<n-1;a++){ 
					mat[0][a]=mat[0][a+1]; 
					}
				n--;
				j--;
				}
			}
		}
	}
	
	/*Ispis matrice*/
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			printf("%5g", mat[i][j]);
		}
		printf("\n");
	}
	
	return 0;
} 