#include <stdio.h>

//zadatak sa usmenog prvi

int prebroj_cifre(int niz[],int vel){
    int pomocni[100],velicina;
    int i, j;
    int cifra, broj,brojac,max,min_br;
    
    for( i = 0 ; i < vel ; i++){
        while(niz[i] != '\0'){
            cifra = niz[i] % 10;
            niz[i] /= 10;
            if(niz[i] == 0) break;
            pomocni[velicina] = cifra;
            velicina++;
        }
    }
    max = 0;
    min_br = pomocni[0];
    for(i = 0; i < velicina; i++){
        brojac = 0;
        for(j = i+1; j < velicina -1 ; j++){
            if(pomocni[j] == pomocni[i]) brojac++;
        }
        if(brojac > max){
            max = brojac;
            broj = pomocni[i];
        }
        if(broj < min_br) min_br = broj; 
    }
    
    broj = 0 ;
    
    for(i = 0; i < vel ; i++){
        broj = 0;
        while(niz[i] != 0){
            if(niz[i] == 0) break;
            cifra = niz[i] % 10;
            niz[i] /= 10;
            if(cifra != min_br){
                broj += 10*cifra; 
            }
        }
        niz[i] = broj;
    }
    return vel;
}


int main() {
    int niz[100],vel,niz2[100],velicina;
    int i,j,x;
    printf("Velicina niza: ");
    scanf("%d",&vel);
    printf("Unesite elemente niza: ");
    for(i = 0 ; i < vel ; i++){
        scanf("%d",&x);
    }
    
    velicina = prebroj_cifre(niz,vel);
    printf("MOdifikovan niz: ");
    for(i = 0 ; i < velicina; i++){
        printf("%d",niz[i]);
    }
    return 0;
}