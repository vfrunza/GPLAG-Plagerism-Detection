#include <stdio.h>
int max(int matrica[100][100],int visina,int sirina){
	int i,j,k,l,br,br1,br11=1;
	br1=matrica[0][0];
	for(i=0;i<visina;i++){
		for(j=0;j<sirina;j++){
			br=1;
			for(k=i;k<visina;k++){
				for(l=0;l<sirina;l++){
					if(k!=i || l>j){
						if(matrica[i][j]==matrica[k][l]){
							br++;
						}
					}
				}
			}
			if(br>br11){
				br11=br;
				br1=matrica[i][j];
			}
			if(br==br11){
				if(matrica[i][j]<br1) br1=matrica[i][j];
			}
		}
	}
	return br1;
}
int izbaci_kolone(int matrica[100][100],int visina,int sirina,int n){
	int i,j,k,l;
	for(i=0;i<visina;i++){
		for(j=0;j<sirina;j++){
			if(matrica[i][j]==n){
				for(k=i;k<visina;k++){
					for(l=j;l<sirina-1;l++){
						matrica[k][l]=matrica[k][l+1];
					}
				}
				sirina--;
				i=0;
				j--;
			}
		}
	}
	return sirina;
}

int main() {
	int i,j,sirina,visina,mojamatrica[100][100],mojbrojac;
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d",&sirina,&visina);
	for(i=0;i<visina;i++){
		printf("Unesite elemente %d. reda: ",i+1);
		for(j=0;j<sirina;j++){
			scanf("%d",&mojamatrica[i][j]);
			
		}
		
	}
	mojbrojac=0;
	while(sirina){
		sirina=izbaci_kolone(mojamatrica,visina,sirina,max(mojamatrica,visina,sirina));
		mojbrojac++;
		if(sirina){
			printf("\nNakon %d. prolaza matrica glasi: \n",mojbrojac);
			for(i=0;i<visina;i++){
				for(j=0;j<sirina;j++){
					printf("%5d",mojamatrica[i][j]);
				}
				printf("\n");
			}
		}
		else printf("\nNakon %d. prolaza matrica je prazna!",mojbrojac);
		
	}
	return 0;
}
