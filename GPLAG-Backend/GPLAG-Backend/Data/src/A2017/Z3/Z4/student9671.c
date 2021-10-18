#include <stdio.h>

int max(int matrica[100][100],int visina,int sirina){
	int i,j,clan,br,max_clan,brojac,prvi_put=1,k,l;

	for(i = 0; i < visina;i++){
		for(j = 0; j < sirina; j++){
			clan = matrica[i][j];  br=0;
	
		for(k = 0; k < visina; k++)
			for(l = 0; l < sirina; l++)
					if(matrica[k][l] == clan)br++;	
	     

		if(prvi_put){	brojac=br;  max_clan = clan;  prvi_put=0;  	}
			
			else {
					if(br >= brojac){
							if(br > brojac)	{	brojac=br; max_clan=clan;	}
							else if(max_clan > clan)max_clan = clan;
					}
				}
		}
	}
	return max_clan;
}

int izbaci_kolone(int matrica[100][100],int visina,int sirina,int n){
	int i,j,k,l,izbacio;
	for(i = 0; i < visina; i++){
		izbacio = 0;
		for(j = 0; j < sirina; j++){
			if(matrica[i][j] == n){
				izbacio = 1;
				for(k = 0; k < visina; k++){
					for(l = j; l < sirina - 1; l++)
						matrica[k][l] = matrica[k][l + 1];
				}
				sirina--;
			}
		}
		if(izbacio == 1){ i--; izbacio = 0; }
	}
	return sirina;
}

int main() {
	int mat[100][100] = {{1,2,3},{4,5,6},{7,-8,-8}},n,i,j,sirina,visina,prolaz;
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d%d",&sirina,&visina);
	for(i = 0; i < visina; i++){
		printf("Unesite elemente %d. reda: ",i + 1);
			for(j = 0; j < sirina; j++)
				scanf("%d",&mat[i][j]);
	}
	printf("\n");
		prolaz=1;
		while (sirina != 0) {
			n = max(mat,visina,sirina);
			sirina = izbaci_kolone(mat,visina,sirina,n);
			if(sirina == 0){printf("Nakon %d. prolaza matrica je prazna!",prolaz);return 0;}
			printf("Nakon %d. prolaza matrica glasi:\n",prolaz);
				for(i = 0; i < visina; i++){
					for(j = 0; j < sirina; j++)
						printf("%5d",mat[i][j]);
					printf("\n");
				}
			prolaz++;
		}
}
