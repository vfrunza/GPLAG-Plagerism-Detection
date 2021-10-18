#include <stdio.h>

int provjeri_duzine(char* string, int* niz, int velicina){
    int brojac=0, broj_rijeci=0;
    while(*string!='\0'){
        while(*string==' ') string++;
        if(*string==' ' || *string=='\0' || *string<65 || (*string>90 && *string<97) || *string>122) break;
        broj_rijeci++;
        brojac=0;
        while(1){
            if(*string=='-'){
                string++;
                continue;
            }
            if(*string==' ' || *string=='\0' || *string<65 || (*string>90 && *string<97) || *string>122) break;
            brojac++;
            string++;
        }
        if(brojac!=*niz) return 0;
        niz++;
        if(*string=='\0') break;
        string++;
    }
    if(broj_rijeci!=velicina) return 0;
    return 1;
}
int main() {

	return 0;
}
