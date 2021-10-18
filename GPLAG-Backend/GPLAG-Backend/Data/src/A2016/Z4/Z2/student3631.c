#include <stdio.h>
#include <stdlib.h>



char* kodiraj(char*tekst, char*tabela){
    int brojaci[96]={0};
   
    int i,j;
    char *pok=tekst;

    
    
    while (*tekst ){
        char temp=*tekst;
        brojaci[temp-32]++;
        tekst++;
    }
    
  int ascii[96];  
  /* upisivanje ascii vrijednosti u prazan niz */
  for (i=0;i<95;i++)
  
    ascii[i]=32+i;   
  
  /* sortiranje niza prema učestalosti u stringu */
   for (i=0;i<95;i++)
      
     for (j=i;j<95;j++)
     {
          if (brojaci[i]<brojaci[j]){  
       
       int temp=brojaci[i];
       brojaci[i]=brojaci[j];
       brojaci[j]=temp;
       temp=ascii[i];
       ascii[i]=ascii[j];
       ascii[j]=temp;
   }
   
   else if(brojaci[i]==brojaci[j]){
       if(ascii[i]>ascii[j]){
             int temp=brojaci[i];
       brojaci[i]=brojaci[j];
       brojaci[j]=temp;
       temp=ascii[i];
       ascii[i]=ascii[j];
       ascii[j]=temp;
       }
           
       }
   }
  
  for (i=0;i<95;i++) {
     *tabela=ascii[i];
     tabela++;
  }
  *tabela='\0';
  tekst=pok;
  
  /*kodiranje teksta*/
  
  while(*tekst)
  {
      int indeks;
      char temp=*tekst;
      for (i=0;i<96;i++)
          if (ascii[i]==temp)
          {indeks=i;
          break;
      }
      *tekst=126-indeks;
      tekst++;
      
     
  }
  
    return pok;
}



char* dekodiraj (char *tekst, char *tabela) {
    char *pok=tekst;

    while(*pok){
        
        int brojac=0;
        char* kod=tabela;
        
        /*dekodiranje ovog teksta */
        while(*kod){
            
            if(*pok == 126 - brojac){
                *pok=*kod;
                break;
            }
            
            brojac++;
            kod++;
        }
        
        pok++;
       
    }

return tekst;
}

int main() {
    
/* unos teksta koji ce biti kodiran i praznog stringa pomocu kojeg obavljam kodiranje*/
char tekst[]="LLMLNLNMONM";
char sifrarnik[100]="";

/* pozivanje funkcije za kodiranje teksta*/
kodiraj(tekst,sifrarnik);
printf ("%s\n", tekst);

/* pozivanje funkcije za dekodiranje */
dekodiraj (tekst,sifrarnik);
printf ("%s", tekst);

return 0;
}
