#include <stdio.h>
char* p,*k;

int broj_cifara(int br){
    int brojac=0;
    if(br == 0) return 1;
    while(br != 0){
        br/=10;
        brojac++;
    }
    return brojac;
}

char* kraj(char* s){
    while(*s) s++;
    return s;
}

char* ubaci_broj(char* tekst, int broj){
    int i=0,temp=0,sirina=0,razmaci=0;
    int negativan = (broj < 0);
    if(negativan){
        broj = -broj;
    }
    temp=broj;
    sirina=broj_cifara(broj) ;
    if(negativan) sirina++; /*razmak za znak '-'*/
    
    while(tekst[i]!='\0'){
        if(razmaci == 1) sirina--;
        razmaci=0;
        /*razmaci na pocetku stringa*/
        while(tekst[i] == ' ') i++;
        while(tekst[i] != ' ' && tekst[i] != '\0') i++;
        /*razmaci na kraju stringa*/
        p=tekst + i;
        while(*p == ' '){ p++; razmaci++; }
        if(razmaci == 1) sirina++;
        if(*p == '\0') break;
        
        k=kraj(tekst) + sirina;
        while(k != tekst + i){
            *k = *(k - sirina);
            k--;
        }
        i+=sirina;
        broj=temp;
        
        k = tekst + i;
        if(razmaci == 1) k--;
        if(broj == 0) *k = '0';
        while(broj != 0){
            *k = broj%10 + '0';
            broj/=10;
            k--;
        }
        broj = temp;
        if(negativan) *k = '-';
        i++;
    }
    return tekst;
}
int main(){
    char tekst[100] = "   ovo je    neki tekst    ";
    printf("%s", ubaci_broj(tekst, -99));
    return 0;
}