#include <stdio.h>

int max(int mat[100][100],int visina,int sirina){

	
	int i,j,vel,pom,najveci,br=0;
	int pom_niz[10000]={0},niz[10000]={0};
	int MAX,MAXi;
	
	//PREBACIVANJE MATRICE U NIZ
	
	for(i=0;i<visina;i++){
		for(j=0;j<sirina;j++){
			niz[i*sirina+j]= mat[i][j];
		}
	}
	
	vel=sirina*visina;

	//SORTIRANJE NIZA
	
	for(i=0;i<vel;i++){
		for(j=i+1;j<vel;j++){
			if(niz[i]>niz[j]){
				pom=niz[i];
				niz[i]=niz[j];
				niz[j]=pom;
			}
		}
	}
	 
	
	
	//FORMIRAMO NIZ SASTAVLJEN OD CLANOVA I NJIHOVIH BROJACA I TO REDOSLIJEDOM CLAN-BROJAC-CLAN-...
	j=0;
	
	for(i=0;i<vel;i++){
		br=0;
		pom=niz[i];
		while(niz[i]==pom && i<vel){
			br++;
			i++;
		}
		i--;
		pom_niz[j]=niz[i];
		pom_niz[j+1]=br;
		j+=2;
	}
	
	//TRAZIMO BROJ KOJI JE NAJCESCI U NIZU
	
	MAX=pom_niz[1];
	MAXi=pom_niz[0];
	
	for(i=1;i<j;i+=2){
		if(pom_niz[i]>MAX){
			MAX=pom_niz[i];
			MAXi=pom_niz[i-1];
		}
	}
	
	return MAXi;
}


int izbaci_kolone (int mat[100][100], int visina,int sirina,int N){
	
	int i,j,k,g;
	
	for(i=0;i<visina;i++){
		for(j=0;j<sirina;j++){
			if(mat[i][j]==N && i<visina && j<sirina){
				for(g=i;g<visina;g++){
						for(k=j;k<(sirina-1);k++){
						mat[g][k]=mat[g][k+1];
					}
				}	
				sirina--;
				j--;
			}
		}
	}
	return sirina;
}

int main(){

	int mat[100][100];
	int j,i,sirina,visina,MAX;
	int br=0;
	
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d",&sirina,&visina);
	
	for(i=0;i<visina;i++){
		printf("Unesite elemente %d. reda: ",i+1);
		for(j=0;j<sirina;j++){
			scanf("%d",&mat[i][j]);
		}
	}
	
	while(sirina!=0){
		
		MAX=max(mat,visina,sirina);
		sirina=izbaci_kolone(mat,visina,sirina,MAX);
		br++;
		if(sirina!=0){
	
		printf("\nNakon %d. prolaza matrica glasi:\n",br);
		for(i=0;i<visina;i++){
			for(j=0;j<sirina;j++){
				printf("%5d",mat[i][j]);
			}printf("\n");
		}
		}
	}
	
	printf("\nNakon %d. prolaza matrica je prazna!",br);
	return 0;
}

