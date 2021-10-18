#include <stdio.h>

int max(int matrica[100][100], int visina, int sirina) {
    int i,j,k,br_el=0,nalazi=1;
    int niz[10000], nizbrojaca[10000];
    for(i=0; i<visina; i++){
        for(j=0; j<sirina; j++){
            nalazi=1;
            for(k=0;k<br_el;k++){
                if(matrica[i][j]==niz[k]){
                    nalazi =0;
                    break;
                }
            }
            if(nalazi==1){
                niz[br_el++]=matrica[i][j];
            }
        }
    }
   
    for(i=0; i<br_el; i++){
        int brojac=0;
        for(j=0;j<visina;j++){
            for(k=0;k<sirina;k++){
                if(niz[i]==matrica[j][k]){
                    brojac++;
                }
            }
        }
        nizbrojaca[i]=brojac;
    }

   
    int maximum=nizbrojaca[0];
    int najmanji,index;
    for(i=1;i<br_el;i++){
        if(nizbrojaca[i]>maximum){
            maximum=nizbrojaca[i];
            index =i;
        }
    }
    najmanji = niz[index];
    for(i=0;i<br_el;i++){
        if(nizbrojaca[i]==maximum){
            if(najmanji>niz[i]){
                najmanji =niz[i];
            }
        }
    }
    return najmanji;
}

int izbacikolone(int matrica[100][100], int visina, int sirina,int N){
    
    int i,j,k,t;
    for(i=0; i<sirina;i++){
        for(j=0; j<visina;j++){
            if(matrica[j][i]==N ){
                if(i==sirina-1){
                    sirina--;
                    return sirina;
                }
                for(k=i+1;k<sirina;k++){
                    for(t=0;t<visina;t++){
                            matrica[t][k-1]=matrica[t][k];
                       
                    }
                }
                sirina--;
                }
                
        }
    }
    return sirina;
}
int main() {
	int matrica[100][100], i, j, visina, sirina,k;
	printf("Unesite sirinu i visinu matrice : "); scanf("%d %d", &sirina, &visina);
	for(i=0; i<visina; i++) {
	    printf("Unesite elemente %d. reda: ", i+1);
	    for(j=0; j<sirina; j++) {
	        scanf("%d", &matrica[i][j]);
	    }
	}
	i=1;
	while(sirina!=0) {
	    printf("Nakon %d. prolaza matrica glasi: ", i);
	    i++;
	    printf("\n");
	    sirina = izbacikolone(matrica, visina, sirina, max(matrica, visina, sirina));
	    for(j=0; j<visina; j++) {
	        for(k=0; k<sirina; k++) {
	            printf("%d\t", matrica[j][k]);
	        }
	        printf("\n");
	    }
	    
	} 
	printf("Nakon %d. prolaza matrica je prazna! ",i);
	
	return 0;
}
