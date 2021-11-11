#include <stdio.h>
#define RED 200
#define KOL 200


int main() {
	int mat[RED][KOL], visina, sirina;
	int i,j,k,z, greska=0;
	int izbaciRed=0, izbaciKolonu=0, pomocni1, pomocni2;
	
	do{	
		if(greska!=0){
			printf("Brojevi nisu u trazenom opsegu.\n");
		}
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &visina, &sirina);
		greska++;
		
	}while(visina<=0 || visina>200 || sirina <=0 || sirina>200);
/*-----------------------------------------------------------------------------*/	
	/*unos*/
	
	pomocni1=visina;
	pomocni2=sirina;
	
	printf("Unesite elemente matrice: ");	
	
	for(i=0; i<visina; i++){
		for(j=0; j<sirina; j++){
			scanf("%d", &mat[i][j]);          
		}
	}
	
	
/*-----------------------------------------------------------------------------*/	
	/*redovi*/														
	
	for(k=0; k<visina-1;k++){
		for(i=k+1;i<visina;i++){
			for(j=0;j<sirina;j++){
				if(mat[k][j]==mat[i][j]){
					izbaciRed=1;
			}
				else if (mat[k][j]!=mat[i][j]){
					izbaciRed=0;
					break;
				}
			}	
			
			if(izbaciRed==1){
			
				if(i+1==visina){
					pomocni1=pomocni1-1;
				}
				else if(i+1 != visina){
					for(j=0; j<sirina;j++){
						for(z=i; z<visina-1;z++){
							mat[z][j]=mat[z+1][j];
						}
					}
				}
			}
		}
	}
/* -----------------------------------------------------------------------------*/			
	/*kolone*/
	
	for(k=0; k<sirina-1;k++){
		for(i=k+1;i<sirina;i++){
			for(j=0; j<visina; j++){
				if(mat[j][k]==mat[j][i]){
					izbaciKolonu=1;
				}
				else if(mat[j][k]!=mat[j][i]){
					izbaciKolonu=0;
					break;
				}
			}
		
			if(izbaciKolonu==1){
				if(i+1==sirina){
					pomocni2=pomocni2-1;
				}
				
				else if(i+1 != sirina){
					for(j=0;j<visina;j++){
						for(z=i; z<sirina-1;z++){
							mat[j][z]=mat[j][z+1];
						}
					}
				}
			}
		}
	}
		
			
			printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
			
			for(i=0; i<pomocni1; i++){
				for(j=0; j<pomocni2; j++){
					printf("%5d", mat[i][j]);
				}
				printf("\n");
			}
				
			
	return 0;
}
