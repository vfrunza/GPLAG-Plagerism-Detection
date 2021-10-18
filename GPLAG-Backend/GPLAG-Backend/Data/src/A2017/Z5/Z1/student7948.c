#include <stdio.h>

struct Datum{
    int dan,mjesec,godina;
};

struct Uposlenik{
    char ime_prezime[50];
    struct Datum datum_rodjenja;
};
//januar 31
//februar 28,29
//mart 31
//april 30
//maj 31
//juni 30
//juli 31
//august 31
//septembar 30
//oktobar 31
//novembar 30
//decembar 31

struct Datum obrtanjeDatuma(struct Datum x,int broj_dana){
    int niz[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int tmp=direktor.dan+broj_dana;
    while(i<=12){
        if(i+1==direktor.mjesec)break;
        i++;
    }
    cuvar=
}



int suzi_listu(struct Uposlenik *kandidati,int vel,struct Uposlenik direktor,int broj_dana){
    int i=0;
    int interval;
    struct Datum granica;
    if(vel==0)return 0;
    if(broj_dana<0){
        
    }else{
        granica=obrtanjeDatuma(granica,broj_dana)
        
    }
    
    while(i<vel){
        
        
        
        
        i++;
    }
    return vel;
}

int main() {

	return 0;
}
