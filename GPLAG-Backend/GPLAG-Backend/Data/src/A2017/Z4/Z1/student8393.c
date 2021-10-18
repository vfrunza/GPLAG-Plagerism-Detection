#include <stdio.h>

int broj_znakova(int n){
   int znakova=0;
   if(n<0){
      znakova++;
      n=n*-1;
   }
   while(n!=0){
      n=n/10;
      znakova++;
      
   }
   return znakova;
}

char*napravi_mjesto(char*string, int duzina){
   char*pocetni,*kraj;
   pocetni=string;
   kraj=string;
   while(*kraj!='\0')kraj++;
   kraj = kraj + duzina+1;
   *kraj='\0';
   kraj--;
   while (kraj > pocetni){
      *kraj=*(kraj-duzina-1);
      kraj--;
   }
   return string;
}

char* upisi(char*string, int broj){
   char *pocetni, *krajnji;
   int duzina;
   pocetni=string;
   krajnji=string;
   duzina=broj_znakova(broj);
   krajnji=krajnji+duzina;
   if(broj<0)broj=broj*-1;
   while(broj!=0){
      *krajnji=broj%10+'0';
      broj=broj/10;
      krajnji--;
   }
   if(krajnji != pocetni)*krajnji='-';
   string=string+duzina;
   return string;
}

char* ubaci_broj(char* tekst, int broj){
   char* pomocni,*pok;
   pomocni=tekst;
   int duzina = broj_znakova(broj);
   
   while(*pomocni != '\0'){
      while(*pomocni == ' '&& *pomocni !='\0')pomocni++;
      while(*pomocni != ' '&& *pomocni !='\0')pomocni++;
      if(*pomocni == ' '){
         pok=pomocni;
         while(*pok== ' '&& *pok != '\0')pok++;
         if(*pok=='\0')break;
         
      }
      pomocni=napravi_mjesto(pomocni,duzina);
      pomocni=upisi(pomocni,broj);
      pomocni++;
   }
   return tekst;
}
int main(){
   return 0;
}