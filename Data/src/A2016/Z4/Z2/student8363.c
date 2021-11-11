#include <stdio.h>

char *kodiraj(char *tekst, char sifrarnik[]) {
    int brojPonavljanja [95]= {0},i,max=0,j=0,k=0,z=0;
    char znakovi[95];
    char *tmp = tekst;
    //histogram znakova
    while(*tmp!='\0') {
        brojPonavljanja[(*tmp)-' ']++;
        tmp++;
    }
    tmp=tekst;
    for(i=0; i<=94; i++) {
        znakovi[i]=i+' ';
    }
    
    for(i=0; i<=94; i++) {
        max=0;
        //nadjem koji se znak najvise ponavlja stavim ga na pocetak i 
        //stavim mu histogram na manju od najmanje vrijednosti 0
        for(j=0; j<=94; j++) {
            if(max<brojPonavljanja[j]) {
                max=brojPonavljanja[j];
                k=j;

            }
        }
        if(max!=0) {
            sifrarnik[i]=znakovi[k];
            brojPonavljanja[k]=-1;
            
        } 
        //ako nema vise znakova koji se javljaju u tekstu popunim tablicu preostalim karakterima
        else {
                j=0;
                while(j<95){
                    k=1;
                    for(z=0;z<i;z++){
                        if(j+' '==sifrarnik[z])k=0;
                    }
                    if(k){sifrarnik[i]=j+' ';i++;}
                    j++;
                    
                }
                break;
            }
        
        }
    sifrarnik[95]='\0';
    tmp=sifrarnik;
    tmp=tekst;
    //sifrovanje teksta
    while(*tmp){
        for(i=0;i<95;i++)
         if(*tmp==sifrarnik[i]){
             *tmp = 126 - i;
            break;
        }
        tmp++;
    }
    return tekst;
}
char *dekodiraj(char *tekst, char *sifrarnik){
    int i;
    char *tmp = tekst;
    while(*tmp){
        for(i=0;i<95;i++){
            if((126-*tmp)==i){
                *tmp = sifrarnik[i];
                    break;
            }
        }
        tmp++;
    }
    return tekst;
}
int main() {
    return 0;
}
