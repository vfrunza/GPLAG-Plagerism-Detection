#include <stdio.h>
int max(int matrica[100][100],int visina,int sirina) {
	int i,j,k,z;
	int br=0,br_ponavljanja=0;
	int max=matrica[0][0];
	for(i=0;i<visina;i++) {
		for(j=0;j<sirina;j++) {
			br=0;
			for(k=0;k<visina;k++) {
		    for(z=0;z<sirina;z++) {
			if(matrica[i][j]==matrica[k][z]) br++;
		    }
	      }
	      if(br>br_ponavljanja) {
	      	br_ponavljanja=br;
	      	max=matrica[i][j];
	      }
	      else if(br==br_ponavljanja){
	      	if(matrica[i][j]<max)  
	      	max=matrica[i][j];
	      }
		} 
	}
	return max;
}

int izbaci_kolone(int matrica[100][100],int visina,int sirina,int N) {
	int i,j,k,z;
	for(i=0;i<visina;i++) {
	for(j=0;j<sirina;j++) {
			if(matrica[i][j]==N) {
				for(k=0;k<visina;k++) {
					for(z=j;z<sirina-1;z++){
						matrica[k][z]=matrica[k][z+1];
					}
				}
				sirina--;
				j--;
			}
		}
	}
	return sirina;
}
int main() {
	/*printf("Zadaća 3, Zadatak 4");*/
	int sirina,visina,i,j,matrica[100][100],N;
	int br=0;
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d",&sirina,&visina);
	
	for(i=0;i<visina;i++) {
		printf("Unesite elemente %d. reda: ",i+1);
		for(j=0;j<sirina;j++) {
		scanf("%d",&matrica[i][j]);
		}
	}

			while(sirina!=0) {
				N=max(matrica,visina,sirina);
				sirina=izbaci_kolone(matrica,visina,sirina,N);
			    if(sirina==0) break;
			    printf("\nNakon %d. prolaza matrica glasi:\n ",br+1);
				for(i=0;i<visina;i++) {
	        	for(j=0;j<sirina;j++) {
				printf("%4d ",matrica[i][j]);
		        }
		    printf("\n ");
			}
		br++;
	}
	if(sirina==0)
	printf("\nNakon %d. prolaza matrica je prazna!",br+1);
	return 0;
}
