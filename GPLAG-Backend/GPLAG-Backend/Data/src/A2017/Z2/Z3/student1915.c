#include <stdio.h>

int main() {
	int mat1[100][100],mat2[100][100],matTMP[100][100];
	int i,j,k,l;
	int visina1,visina2,visina3,sirina1,sirina2,sirina3;
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d",&visina1,&sirina1);
	printf("Unesite clanove matrice A: ");
	for(i=0;i<visina1;i++){
		for(j=0;j<sirina1;j++)
		scanf("%d",&mat1[i][j]);
	}
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d",&visina2,&sirina2);
	printf("Unesite clanove matrice B: ");
	for(i=0;i<visina2;i++){
		for(j=0;j<sirina2;j++)
		scanf("%d",&mat2[i][j]);
	}
	if(visina1==sirina1){
		for(i=0;i<visina1;i++)
			for(j=0;j<sirina1;j++)
				matTMP[j][sirina1-1-i]=mat1[i][j];
	}
	else {
		visina3=sirina1;
		sirina3=visina1;
		k=visina1-1;
		for(i=0;i<visina1;i++){
			for(j=0;j<sirina1;j++){
				matTMP[j][k]=mat1[i][j];
			}
			k--;
		}
	}	
	if(visina1==sirina1 && (visina1!=visina2 || sirina1!=sirina2)){
		printf("NE");
		return 0;
	}else if(visina1==sirina1 && visina1==visina2 && sirina1==sirina2);
	else if(visina3!=visina2 || sirina3!=sirina2){
		printf("NE");
		return 0;
	}
	if(visina1==sirina1){
		for(i=0;i<visina1;i++)
				for(j=0;j<sirina1;j++)
				if(matTMP[i][j]!=mat2[i][j]){
					printf("NE");
					return 0;
				}
	}else {
		for(i=0,k=visina2-1;i<visina2;i++,k--)
				for(j=0,l=sirina2-1;j<sirina2;j++,l--)
				if(matTMP[k][l]!=mat2[i][j]){
					printf("NE");
					return 0;
				}
	}
	printf("DA");
	return 0;
}
