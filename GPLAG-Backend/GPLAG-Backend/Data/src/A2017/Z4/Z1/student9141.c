#include <stdio.h>

char* ubaci_broj(char* tekst, int broj){
    int broj_mjesta=0, pomocni;
    char* pocetak=tekst;
    char* kraj=tekst;
    
    if(broj<0){
        pomocni=broj;
        while(pomocni<0){
            pomocni=pomocni/10;
            broj_mjesta++;
        }
        broj_mjesta++;
    }
    else if(broj>0){
        pomocni=broj;
        while(pomocni>0){
            pomocni=pomocni/10;
            broj_mjesta++;
        }
    }
    pomocni=broj;
    while(*tekst==' ') tekst++;
    while(*tekst!='\0'){
        if(*tekst==' '){
            kraj=tekst;
            while(*kraj!='\0' && *kraj==' ') kraj++;
            if(*kraj=='\0') break;
            while(*kraj!='\0'){
                kraj++;
            }
            while(kraj>tekst){
                *(kraj+broj_mjesta)=*kraj;
                kraj--;
            }
            tekst+=broj_mjesta;
            while(pomocni!=0){
                if(pomocni<0) pomocni*=-1;
                *tekst=pomocni%10+48;
                pomocni/=10;
                tekst--;
            }
            if(broj<0) *tekst='-';
            pomocni=broj;
            if(broj<0) tekst+=broj_mjesta;
            else tekst+=broj_mjesta+1;
            if(*tekst!=' '){
                while(*kraj!='\0') kraj++;
                while(kraj>=tekst){
                    *(kraj+1)=*kraj;
                    kraj--;
                }
                *tekst=' ';
            }
        }
            while(*tekst==' ') tekst++; 
            tekst++;
    }
    return pocetak;
} 

int main() {
    char s[77] = "Tekst jen dva dri";
    printf("\"%s\"", ubaci_broj(s, 320));
	return 0;
}
