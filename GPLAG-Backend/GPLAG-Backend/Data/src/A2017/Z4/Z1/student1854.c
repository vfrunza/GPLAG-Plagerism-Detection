#include <stdio.h>
#include <math.h>



char* ubaci_broj (char* tekst, int broj)
{
    int brojac=0,cifrica,pomocni=broj,cifra,duzina=0,sss=broj;
    char* kraj,*temp=tekst;

    while(pomocni!=0){
        
        pomocni/=10;
        duzina++;
        brojac++;
    }
    duzina++;
    
         
    
    while(*tekst!='\0'){
        if(*tekst==' '){
         kraj=tekst;
         while(*kraj!='\0')kraj++;
            while(kraj>tekst){
                *(kraj+duzina)=*kraj;
                kraj--;
        }
        pomocni=broj;
        sss=broj;
        *tekst++=' ';
        cifrica=brojac;
        //printf("%d",cifrica);
        while(pomocni!=0){
            
        cifra=sss/((int)pow(10,cifrica-1));
        sss=sss%((int)pow(10,cifrica-1));
       // printf("%d\n",cifra);
        *tekst++=cifra+'0';
        pomocni/=10;
        cifrica--;
    }
        *tekst++=' ';
    }
    tekst++;
    }
    return temp;
}
int main(){
    
    char s[44] = "Ovo je neki primjer teksta";
printf("\"%s\"", ubaci_broj(s, 123));

    return 0;
}