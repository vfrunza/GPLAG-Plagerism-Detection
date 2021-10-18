#include <stdio.h>

int slovo(char c){

    if(c >= 'A' && c <='Z' || c >= 'a' && c <='z') return 1;
    else return 0;
}


char * ubaci(char *s, char *rijec){

char *p = s;

while(*p != '\0'){

    if(slovo(*p)){
        while(slovo(*p)) p++;
        char *pt = p;
        while(*pt != '\0') pt++;
        char *r = rijec;
        while(*r != '\0') r++;
        int duzina = r - rijec;
        duzina--;
        while(p != pt){
        *(pt+duzina) = *pt;
        pt--;
        } 
        while(*rijec != '\0'){
        *p = *rijec;
        p++; rijec++;
        }
        return s;
    }
    else p++;
}
return s;
}



int main(){

char s[30] = "auto ide ulicom";
char rijec[10] = "dobro";

char *p = ubaci(s,rijec);
printf("%s",p);

// komentar: rijec se nakon prve ubacuje BUKVALNO, pa se ubacuje i preko postojeceg razmaka, tako da ce prve dvije rijeci sada biti spojene (a eventualno i treca, ako je bio samo 1 razmak)

}
