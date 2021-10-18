#include <stdio.h>

void unesi(char niz[], int velicina) {
    char znak = getchar();
    if (znak == '\n') znak=getchar();
    int i = 0;
    while (i < velicina-1 && znak != '\n') {
        niz[i] = znak;
        i++;
        znak = getchar();
    }
    niz[i]='\0';
}



char* kodiraj (char *prvi, char *sifra){
    int niz[200]={{0}};
    char *pocetni_prvi;
    char *pocetni_sifra;
    pocetni_prvi=prvi;
    pocetni_sifra=sifra;
    int duzina=0;
    int i;
    
    // brojanje ponavljanja
    
    while(*prvi!='\0'){
        niz[*prvi-32]++;
        prvi++;
    }
    prvi=pocetni_prvi;
    
    //redanje po broju ponavljanja
    
    while(1){
        int max=niz[0];
        for(i=0;i<100;i++){
            if(niz[i]>max){
                max=niz[i];
            }
        }
        if(max==0) break;
        for(i=0;i<100;i++){
            if(niz[i]==max){
                *sifra=i+32;
                niz[i]=-1;
                sifra++;
                duzina++;
                break;
            }
        }
    }
    
    //kreiranje sifrarnika
    
    prvi=pocetni_prvi;
    sifra=pocetni_sifra+duzina;
    for(i=0;i<95;i++){
        if(niz[i]==0){
            *sifra=i+32;
            sifra++;
        }
    }
    *sifra='\0';
    
    
    // kodiranje
    
    prvi=pocetni_prvi;
    sifra=pocetni_sifra;
    while(*prvi!='\0'){
        sifra=pocetni_sifra;
        i=0;
        while(*prvi!=*sifra){
            sifra++;
            i++;
        }
        *prvi=126-i;
        prvi++;
    }
    *prvi='\0';
    
    return pocetni_prvi;
}

char* dekodiraj(char *prvi, char *sifra){
    char *pocetni_prvi;
    pocetni_prvi=prvi;
    int i;
    
    // dekodiranje
    
    while(*prvi!='\0'){
        i=126-*prvi;
        *prvi=*(sifra+i);
        prvi++;
    }
    *prvi='\0';
    return pocetni_prvi;
}

int main(){
    
    char recenica[200];
    printf("Unesite: ");
    unesi(&recenica[0],200);
    char sifrarnik[100];
    char* pok;
    pok=&recenica[0];
    pok=kodiraj(pok,&sifrarnik[0]);
    printf("%s\n",recenica);
    pok=dekodiraj(&recenica[0],&sifrarnik[0]);
    printf("%s",recenica);
    
   
    
    return 0;
}