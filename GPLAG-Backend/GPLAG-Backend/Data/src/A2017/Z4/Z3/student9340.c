#include <stdio.h>

void najduzi_bp (char* s1, char* s2){
	
	  char *pok1=s1, *pok2;
	  int brojac1=0, brojac2=0, i=0, j=0, ponavlja=0, niz[26]; 
	  for (i=0; i<26; i++){ /* Stavljanje svih clanova niza na 0 (a to su brojaci slova) */
		 niz[i] = 0;
	  }
	  
      while (*pok1 != '\0'){
	  	
	  	  pok2=pok1;
	  	  ponavlja=0;
	  	
	      while (ponavlja!=1 && *pok2!=' ' && *pok2!='\0' && (*pok2>='A' && *pok2<='Z' || *pok2>='a' && *pok2<='z')){
	  	   	   if ((*pok2>='A' && *pok2<='Z') || (*pok2>='a' && *pok2<='z')){
	  	   	
	  	           if (*pok2<='Z') i=*pok2-'A'; /* Trazenje indexa odnosno koji po redu cemo uvecati */
	  	           else i=*pok2-'a';  /* brojac, odnosno koje je slovo trenutno (i=0 je a, i=1 je b itd.) */
	  	              niz[i]++;
	  	      
	  	           for (j=0; j<26; j++){
	  	      	      if (niz[j] > 1){
	  	      	          ponavlja=1;
	  	      	          break;
	  	      	      }
	  	           }
	  	      
	  	           if (ponavlja == 1 || *pok2 == ' ' || *pok2 == '\0') break;
	  	           brojac1++;                                                
	  	        }
	  	        pok2++;
	  	   }
	  
	  	      if (brojac1 > brojac2){
	  	      	  for (j=0; j<brojac1; j++){ /* Prepisivanje podniza */
	  	      		   *s2=*(pok1+j);
	  	      		   s2++;
	              }
	              *s2='\0'; /* Dodavanje \0 za kraj stringa */
	              s2-=brojac1; /* Vracamo s2 na pocetak */
	              brojac2 = brojac1;
              }

              brojac1=0;
              for (j=0; j<26; j++){
	               niz[j]=0;
              }
              
           pok1++;
      }
}

int main (){
	
	return 0;
}