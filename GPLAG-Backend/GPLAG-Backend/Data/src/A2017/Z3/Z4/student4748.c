#include <stdio.h>

int max(int mat[100][100],int visina,int sirina){
	int i,j,k,s,brojac1=0,brojac2=0,broj,max;
	for(i=0;i<visina;i++){
		for(j=0;j<sirina;j++){
			broj=mat[i][j];
			for(k=0;k<visina;k++){
				for(s=0;s<sirina;s++){
					if(broj==mat[k][s]){
						brojac1++;
					}
				}
			}
			if(brojac1>brojac2){
				max=broj;
				brojac2=brojac1;
			}
			if(brojac1==brojac2){
				if(broj<max){
					max=broj;
				}
			}
			brojac1=0;
		}
	}
	return max;
}
int izbaci_kolone(int mat[100][100],int visina,int sirina,int n){
	int i,j,k,s;
	for(i=0;i<visina;i++){
		for(j=0;j<sirina;j++){
			if(mat[i][j]==n){
				for(k=0;k<visina;k++){
					for(s=j;s<sirina-1;s++){
						mat[k][s]=mat[k][s+1];
					}
				}
				sirina--;
			}
		}
	}
	return sirina;
}

int main() {
	int i,j,visina,sirina,mat[100][100],b,x=0;
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d",&sirina,&visina);
	for(i=0;i<visina;i++){
		printf("Unesite elemente %d. reda: ",i+1);
		for(j=0;j<sirina;j++){
			scanf("%d",&mat[i][j]);
			if(i==visina-1)
			{
				printf("\n");
			}
		}
	}
	while (sirina>0){
		x++;
		b=max(mat,visina,sirina);
		sirina=izbaci_kolone(mat,visina,sirina,b);
		if(sirina==0){
			printf("Nakon %d. prolaza matrica je prazna!",x);
			break;
		}
		printf("Nakon %d. prolaza matrica glasi:\n",x);
		for(i=0;i<visina;i++){
			for(j=0;j<sirina;j++){
				printf("%5d",mat[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
