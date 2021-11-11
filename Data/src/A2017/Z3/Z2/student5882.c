#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int suma_cifara(float br){
    int suma=0;
    br=br*10;
    if(br<0){
        br=br*(-1);
    }
    
int intBr=(int)(br);
while(intBr>0){
    suma+=intBr%10;
    intBr=intBr/10;
} return suma;
}

void zaokruzi1(float brojevi[],int bel){
    float produzena_vrijednost;
    int i=0,kf=1;
    while(i<bel){
        if(brojevi[i]<0){
            kf=-1;
        } else {
            kf=1;
        } 
          float produzena_vrijednost= (int) (brojevi[i]*10+.5*kf);
        brojevi[i]=(float)produzena_vrijednost/10;
        i++;
    }
}

void preslozi(float brojevi[],int bel,int m){
    zaokruzi1(brojevi,bel);
    float manji_od_m[100];
    float veci_od_m[100];
    int i=0,br_vecih=0,br_manjih=0;
    while(i<bel){
        if(suma_cifara(brojevi[i])>=m){
            veci_od_m[br_vecih]=brojevi[i];
            br_vecih++;
        } else {
            manji_od_m[br_manjih]=brojevi[i];
            br_manjih++;
        } i++;
    }
    
    i=0;
    while(i<br_vecih){
        brojevi[i]=veci_od_m[i];
        i++;
    }
    
    i=0;
    while(i<br_manjih){
        brojevi[i+br_vecih]=manji_od_m[i];
        i++;
    }
}

int main(){
    int i=0;
    float niz[]={3.2,-4.301,-123.1999,1.1,0.9};
    preslozi(niz,5,8);
    printf("Niz glasi: ");
    for(i=0;i<5;i++)
    printf("%g", niz[i]);
}














