#include <stdio.h>

int provjeri_duzine(char *s,int *niz,int vel){
    int i = 0,razmak=1,broj_rijeci = 0,duzina_rijeci = 0;
    char *p = s,*poc;
    
    while(*s != '\0'){
        if(!(*s >= 'a' && *s <= 'z' || *s >= 'A' && *s <= 'Z'))razmak = 1;
        else if(razmak == 1){
            razmak = 0;
            p = s;
            broj_rijeci++;
        }
        
        s++;
        if(razmak == 0 && (!(*s >= 'a' && *s <= 'z' || *s >= 'A' && *s <= 'Z') || *s == '\0')){
            poc = p;
            duzina_rijeci = 0;
                
            while(p < s){
                duzina_rijeci++;
                p++;
                
            }
            if(duzina_rijeci != niz[i] && i < vel)return 0;
            i++;
            duzina_rijeci = 0;
        }    
    }
   if((i-1) >= vel || broj_rijeci != vel)return 0;
return 1;
}

int main() {
char tekst[] = "Kakav je ovo test!?!?";
int niz3[] = {5,2,3,4,0};

printf("%d ", provjeri_duzine(tekst, niz3, 5));
}