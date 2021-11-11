#include <stdio.h>

/*  Funkcija kodiraj prima dva niza i svaki znak u prvom stringu zamijeni znakom čija je ASCII vrijednost 126 minus pozicija u tablici,
    dok u drugi stavlja ASCII vrijednosti koje se javljaju u primljenom stringu složene po broju ponavljanja, a nakon njih redom sve preostale ASCII vrijednosti od razmaka do ASCII vrijednosti 126.*/

char* kodiraj (char *s, char *crypt) {
    char* start=s, chars[100], temp_char, ch=' ';
    int  num_rpt[100]={0}, i, num_chars=0, repeating, temp_int, j;
    while(*s){
        repeating=0;
        for(i=0; i<num_chars; i++){
            if(*s==chars[i]){
                repeating=1;
                num_rpt[i]++;
                break;
            }
        }
        if(!repeating){
            chars[num_chars]=*s;
            num_rpt[num_chars]++;
            num_chars++;
        }
        s++;
    }
    for(i=0; i<num_chars; i++){
        for(j=i+1; j<num_chars; j++){
            if(num_rpt[i]<num_rpt[j]){
                temp_int = num_rpt[i];
                num_rpt[i] = num_rpt[j];
                num_rpt[j] = temp_int;
                
                temp_char = chars[i];
                chars[i] = chars[j];
                chars[j] = temp_char;
            }
            else if(num_rpt[i]==num_rpt[j] && chars[i]>chars[j]){
                temp_int = num_rpt[i];
                num_rpt[i] = num_rpt[j];
                num_rpt[j] = temp_int;
                
                temp_char = chars[i];
                chars[i] = chars[j];
                chars[j] = temp_char;
            }
        }
    }
    for(i=0; i<num_chars; i++){
        *crypt=chars[i];
        crypt++;
    }
    for(ch=32; ch<127; ch++){
        repeating=0;
        for(j=0; j<num_chars; j++){
            if(chars[j]==ch){
                repeating=1;
                break;
            }
        }
        if(!repeating){
            *crypt=ch;
        }
        if(j==num_chars) crypt++;
    }
    *crypt=0;
    s=start;
    while(*s){
        for(i=0; i<num_chars; i++){
            if(*s==chars[i]) {
                *s=126-i;
                break;
            }
        }
        s++;
    }
    return start;
}

/*Funkcija dekodiraj prima dva pokazivaca na niz, niz koji se dekodira i sifrarnik i na osnovu sifrarnika dekodira prvi niz i vraca pokazivac na pocetak istog.*/

char* dekodiraj (char *s, char *p) {
    char *start=s, chars[100], temp_char;
    int i, j, repeating, num_chars=0, num_rpt[100]={0}, temp_int;
    while(*s){
        repeating=0;
        for(i=0; i<num_chars; i++){
            if(*s==chars[i]){
                repeating=1;
                num_rpt[i]++;
                break;
            }
        }
        if(!repeating){
            chars[num_chars]=*s;
            num_rpt[num_chars]++;
            num_chars++;
        }
        s++;
    }
    for(i=0; i<num_chars; i++){
        for(j=i+1; j<num_chars; j++){
            if((num_rpt[i]<num_rpt[j]) || ((num_rpt[i]==num_rpt[j] && chars[i]<chars[j]))){
                temp_int = num_rpt[i];
                num_rpt[i] = num_rpt[j];
                num_rpt[j] = temp_int;
                
                temp_char = chars[i];
                chars[i] = chars[j];
                chars[j] = temp_char;
            }
        }
    }
    s=start;
    while(*s){
        for(i=0; i<num_chars; i++){
            if(*s==chars[i]) {
                *s=p[i];
                break;
            }
        }
        s++;
    }
    return start;
}

int main() {
    return 0;
}
