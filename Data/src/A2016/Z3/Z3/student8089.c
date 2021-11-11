#include <stdio.h>

int main() {
	int a,b,i,j,equal,k,h;
	int niz[200][200];
	// Sada pisemo petlju koja ce nam provjeravati dozvoljeni opseg brojeva!
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&a,&b);
		if(a<=0 || a>200 || b<=0 || b>200) printf("Brojevi nisu u trazenom opsegu.\n");
	}	while(a<=0 || b<=0 || a>200 || b>200);
	
	// Sada cemo napisati blok naredbi da unesemo elemente matrice!
	printf("Unesite elemente matrice: ");
	for(i=0; i<a; i++){
		for(j=0; j<b; j++){
		scanf("%d",&niz[i][j]);
		}
	} //Sada cemo porediti clanove!
	for(i=0; i<a; i++){
		for(j=i+1; j<a; j++){
			equal=1;
			for(k=0; k<b; k++){
				if (niz[i][k] != niz[j][k]){
				equal=0;} }
				if(equal==1){
					for(k=j; k<b-1; k++){
						for(h=0; h<a; h++){
							niz[k][h]=niz[k+1][h];
						}
					}
					a--;
					j--;
				}}}
				for(i=0; i<b; i++){
					for(j=i+1; j<b; j++){
						equal=1;
						for(k=0; k<a; k++){
							if(niz[k][i]!=niz[k][j]){
								equal=0;
							}
						}
						if (equal==1){
							for(k=j; k<b-1; k++){
								for(h=0; h<a; h++){
									niz[h][k]=niz[h][k+1];
								}
							}
							b--;
							j--;
						}
					}
				}
				
				
				printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
				for(i=0; i<a; i++){
					for(j=0; j<b; j++){
						printf("%5d",niz[i][j]);
					}
					printf("\n");
				}
	
	return 0;
}