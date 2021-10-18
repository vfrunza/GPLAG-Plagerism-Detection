#include <stdio.h>

int koliko_puta_se_ponovio_clan(int n, int matrica[100][100], int visina,int sirina){
    int br=0,i=0,j;
    while(i<visina){
        for(j=0;j<sirina;j++){
            if(n==matrica[i][j]){
                br++;
            } 
        } i++;
    } return br;
}

int max(int C[100][100],int visina, int sirina){
    int i,j,matricabrojaca[100][100],matrica_sa_najvise_ponavljanja[100][100];
    i=0;
    while(i<visina){
        for(j=0;j<sirina;j++){
            matricabrojaca[i][j]=0;
        } i++; 
    }
    i=0;
    while(i<visina){
        for(j=0;j<sirina;j++){
            matricabrojaca[i][j]=koliko_puta_se_ponovio_clan(C[i][j],C,visina,sirina);
        } i++; 
    }
    
    int najveci_brojac=matricabrojaca[0][0];
    i=0;
    while(i<visina){
        for(j=0;j<sirina;j++){
            if(matricabrojaca[i][j]>najveci_brojac)
             najveci_brojac=matricabrojaca[i][j];
        } i++;
    }
    i=0;
    while(i<visina){
        for(j=0;j<sirina;j++){
            matrica_sa_najvise_ponavljanja[i][j]=0;
        } i++;
    }
    i=0;
    while(i<visina){
        for(j=0;j<sirina;j++){
            if(matricabrojaca[i][j]==najveci_brojac)
            matrica_sa_najvise_ponavljanja[i][j]=1;
        } i++;
    }
    
    int minimum_od_maksimuma;
    int min;
    i=0;
    while(i<visina){ 
        for(j=0;j<sirina;j++){ 
            if(matrica_sa_najvise_ponavljanja[i][j]==1){
                minimum_od_maksimuma=matrica_sa_najvise_ponavljanja[i][j];
                min=C[i][j];
                break;
            } 
        } i++;
    }
    i=0;
    while(i<visina){
        for(j=0;j<sirina;j++){
            if(matrica_sa_najvise_ponavljanja[i][j]==1 && C[i][j]<min)
            min=C[i][j];
        } i++;
    } return min;
}

int izbaci_kolone(int matrica[100][100], int visina, int sirina,int N){
    int i,j;
    for(i=0;i<visina;i++){
        for(j=0;j<sirina;j++){
            if(matrica[i][j]==N){
                int p,d;
                for(p=0;p<visina;p++){
                    for(d=0;d<sirina;d++){
                        matrica[p][d]=matrica[p][d+1];
                    }
                }sirina--;
            }
        }
    } return sirina;
}




int main() {
    printf("Unesite sirinu i visinu matrice: ");
    printf("Unesite elemente 1. reda: ");
    printf("Unesite elemente 2. reda: \n");
    printf("Nakon 1. prolaza matrica je prazna!");
}












