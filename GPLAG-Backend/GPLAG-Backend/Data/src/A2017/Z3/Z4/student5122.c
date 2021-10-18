#include <stdio.h>
#define SIRINA 100
#define VISINA 100

int max(int matrica[100][100],int visina,int sirina){
	int i,j,brojac[101]={0},maks;
	for(i=0;i<visina;i++){
		for(j=0;j<=100;j++){
			if(matrica[i]==j)brojac[j]++;
		}
		
	}
	
	maks=0;
	for(i=0;i<=100;i++){
		if(brojac[i]>brojac[maks]) maks=i;
	}
	
	
	return maks;
}



int main() {
	int mat[SIRINA][VISINA],i,j,sir,vis,N;
	printf("Unesite sirinu i visinu matrice: ");
    scanf("%d",&sir);
    scanf("%d",&vis);
    
    for(i=0;i<vis;i++){
      
       
        printf("Unesite elemente %d. reda: ",i+1);
        for(j=0;j<sir;j++){
        scanf("%d",&mat[i][j]);
    	
    	
    	}
    }
	
	printf("Unijeti broj N: ");
	scanf("%d",&N);
	
	
	
	
	return 0;
}
