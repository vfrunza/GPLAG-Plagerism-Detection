#include <stdio.h>

	int max(int matrica[100][100], int visina, int sirina){
		int i,j,k,l;
		int maxx=matrica[0][0];
		int pom;
		int brmax=0,br;
		for(i=0;i<visina;i++){
			for(j=0;j<sirina;j++){
				br=0;
				pom=matrica[i][j];
				for(k=0;k<visina;k++){
					for(l=0;l<sirina;l++){
						if(pom==matrica[k][l]) br++;
					}
				}
				if(br>brmax) { brmax=br; maxx=pom; }
				if(br==brmax && pom<maxx) maxx=pom;
			}
		}
		return maxx;
	}
	
	int izbaci_kolone(int matrica[100][100], int visina, int sirina, int n){
		int i,j,k,l;
		
		for(i=0;i<visina;i++){
			for(j=0;j<sirina;j++){
				if(n==matrica[i][j]) {
					for(k=0;k<visina;k++){
						for(l=j;l<sirina-1;l++){
							matrica[k][l]=matrica[k][l+1];
						}
					}
					sirina--;
					i--;
					i=0;j=0;
					
				}
			}
		}
		
		return sirina;
	}

	

int main() {
	int sirina,visina;
	int i,j,k,pom;
	int matrica[100][100];
	int maxx;
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d", &sirina);
	scanf("%d", &visina);
	
	for(i=0;i<visina;i++){
		printf("Unesite elemente %d. reda: ",i+1);
		for(j=0;j<sirina;j++){
			scanf("%d", &matrica[i][j]);
		}
	}
	pom=sirina;
	
	
	for(j=0;j<pom;j++){
		maxx=max(matrica,visina,sirina);
		sirina=izbaci_kolone(matrica,visina,sirina,maxx);
		if(!sirina) {printf("\nNakon %d. prolaza matrica je prazna!",j+1); break;}
		printf("\nNakon %d. prolaza matrica glasi: \n",j+1);
		for(i=0;i<visina;i++){
			for(k=0;k<sirina;k++){
				printf("%5d",matrica[i][k]);
			}
			printf("\n");
		}
	}	
	return 0;
}
