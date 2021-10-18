#include <stdio.h>

int duzina (int n){
    int brojac=0;
    while (n!=0) {
        n/=10;
        brojac++;
    }
    return brojac;
}

char*ubaci_broj(char *tekst,int broj){
    char*poc=tekst;
    char *x=tekst;
    char*end=tekst;
    char *temp;
    int razmak=0;
    int pom=broj;
    int duz,n=1;
    duz=duzina(broj);
    n+=duz;
    if(broj<0){
        n++;
        pom=pom*(-1);
    }
    while (*tekst!='\0') {
        if(*tekst==' '){
            if(tekst==x){
                while(*tekst!='\0'&&*tekst==' '){
                    tekst++;
                }
            }
            while(*tekst!=' '&& *tekst!='\0'){
                tekst++;}
                temp=tekst;
                razmak=0;
                while(*temp!='\0'&& *temp==' '){
                    razmak++;
                    temp++;
                }
                if(*temp=='\0')break;
                end=tekst;
                while(*end!='\0'){
                    end++;
                }
                while(end>tekst){
                    *(end+n)=*end;
                    end--;
                }
                tekst+=n;
               *tekst--=' ';
               pom=broj;
               if(broj<0){
                   pom=pom*(-1);
               }
               while(pom!=0){
                   *tekst=(pom%10)+'0';
                   tekst--;
                   pom/=10;
               }
               if(broj<0)*tekst='-';
               tekst+=n;
               if(razmak>1){
                   end=tekst;
                   while(*end!='\0')
{
    *end=*(end+1);
    end++;
}            }
        }
        if(*tekst==' '){
            while(*tekst==' '&&*tekst!='\0'){
                tekst++;
            }
        }
        if(*tekst!='\0')tekst++;
    }
    return poc;
}

int main(){
    char s[77]="Ovo je neki primjer teksta";
    printf("%s",ubaci_broj(s,0));
    return 0;
}
