#include <stdio.h>
int max(int matrica[100][100], int visina, int sirina)
{
	
	int i,j,brojac_visina,brojac_sirina,br1=0,br2=0;
	int maxi;
	maxi=matrica[0][0];
	
	
	
	for(i=0;i<visina;i++) {
		for(j=0;j<sirina;j++) {
				br1=0;		
			for(brojac_visina=0;brojac_visina<visina;brojac_visina++) {
				for(brojac_sirina=0;brojac_sirina<sirina;brojac_sirina++) {
					if(matrica[i][j]==matrica[brojac_visina][brojac_sirina]) br1++; 
				}	
				}
				if(br1>br2) {
					br2=br1;
					maxi=matrica[i][j];
				}
				else if (br1==br2) {
					if(matrica[i][j]<maxi)
					maxi=matrica[i][j];
				}
			
			
	}
	}
	
	
	return maxi;
	
}

int izbaci_kolone(int matrica[100][100], int visina, int sirina, int N)
{
	int i,brojac_sirina,brojac_visina;
	int j;
	int zamjena;
	
	for(i=0;i<visina;i++) {
	for(j=0;j<sirina;j++){
	if(matrica[i][j]==N) {
			for(brojac_visina=0;brojac_visina<visina;brojac_visina++) {
			for(brojac_sirina=j;brojac_sirina<sirina-1;brojac_sirina++) {
				zamjena=matrica[brojac_visina][brojac_sirina];
				matrica[brojac_visina][brojac_sirina]=matrica[brojac_visina][brojac_sirina+1];
				matrica[brojac_visina][brojac_sirina+1]=zamjena;
				
					}
				}
				j--;
				sirina--;
				
				
			}
		}
	}
	
	
	return sirina;
	
}






int main() {
	
	int matrica[100][100];
	int b,a,i,j;
	int rez;
	int brojac45=1;
	
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d",&b,&a);
	
	for(i=0;i<a;i++) {
		printf("Unesite elemente %d. reda: ",i+1);
		for(j=0;j<b;j++) {
			scanf("%d ",&matrica[i][j]);
		}
	}
	
	rez=max(matrica,a,b);
	b=izbaci_kolone(matrica,a,b,rez);
	

	while (b!=0) {
		
	
		
		printf("\nNakon %d. prolaza matrica glasi: \n", brojac45);
		brojac45++;
		for(i=0;i<a;i++){
			for(j=0;j<b;j++) {
				printf("%5d",matrica[i][j]);
			}
			printf("\n");
		}
		
		
			rez=max(matrica,a,b);
	b=izbaci_kolone(matrica,a,b,rez);
	}
	
	
	
	printf("\nNakon %d. prolaza matrica je prazna!",brojac45);
	
	
	
	
	return 0;
}
