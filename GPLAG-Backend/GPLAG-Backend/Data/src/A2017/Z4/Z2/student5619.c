#include <stdio.h>
int provjeri_duzine(char *s,int *niz,int velicina)
{
    int brojac=0,i=0;
    if (velicina==0) return 0;
    while (*s != '\0') {
        if(*s != '\0' && ((*s>='A' && *s<='Z') || (*s>='a' && *s<='z'))){
            while(*s!='\0' && ((*s>='A' && *s<='Z') || (*s>='a' && *s<='z'))){
                s++;
                brojac++;
            } 
            if (brojac!=niz[i]) return 0;
            brojac=0;
            i++;
        }
        if (*s=='\0') break;
        s++;
        
    }
    
    if (i==velicina && *s=='\0') return 1;
    
    return 0;
}
int main() {



	return 0;
}
