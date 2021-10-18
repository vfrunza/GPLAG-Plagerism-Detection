#include <stdio.h>

int provjeri_duzine (char tekst[], int niz_brojeva[], int velicina_niza){
    int brojac = 0, i = 0;
    char *p = tekst;
    
    while (*p != '\0'){
  	     do { 
             if (((*p>='A') && (*p<='Z')) || ((*p>='a') && (*p<='z'))) brojac++;
  	     	   p++;
  		       if (*p=='\0') break;
  	        } while (((*p>='A') && (*p<='Z')) || ((*p>='a') && (*p<='z')));
  	   
  	     if (brojac != 0){
  	   	     if (brojac != niz_brojeva[i]) return 0;
  	  	     i++;
  	  	     if (i > velicina_niza) return 0;
  	  	     brojac = 0;
  	     }
  	     
  	     if (*p == '\0') break;
  	     p++;
    }
    
    if (i != velicina_niza) return 0;
  
  return 1;
}

int main (){
	
	return 0;
}