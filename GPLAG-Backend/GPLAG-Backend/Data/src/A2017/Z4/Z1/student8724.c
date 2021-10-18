#include <stdio.h>

void unesi (char niz[], int velicina) {
	char znak=getchar();
	if (znak=='\n') znak=getchar();
	int i=0;
	while (i<velicina-1 && znak!='\n')
	      {
	      	niz[i]=znak;
	      	i++;
	      	znak=getchar();
	      }
	niz[i]='\0';      
}

int broj_cifara (const int broj) {
	int brojac=0; int kopija=broj;
	if (broj<0) brojac++;
	while (broj) 
	      {
	      	if (kopija<0) kopija=-kopija;
	        brojac++;
	        kopija/=10;
	      }
	return brojac;      
}
int broj_rijeci (const char *tekst) {
	int brojac=0, razmak=1;
	while (*tekst!='\0')
          {
            if (*tekst==' ') razmak=1;
            else if (razmak)
                     {
                     	razmak=0;
                     	brojac++;
                     }
            tekst++;         
          }	   
    return brojac;      
}

char* ubaci_broj (char *tekst, int broj) {
    char *pocetak=tekst; 
	int br_cifara=broj_cifara(broj), cifra, niz[12], i;
 /*ako tekst pocinje razmakom*/
	if (*tekst==' ')
	    do {
	    	 tekst++;
	    } while (*tekst!=' ');
	char *pom=tekst;    
	while (*pom!='\0')
	      {
	     	if (*pom!=' ') 
	     	  do {
	      	   	   pom++;
	      	   	 } while (*pom==' ');
	      	   	 char *kraj=pom;
	      	   	 while (*kraj!='\0') kraj++;
	      	   	 while (kraj>pom)
	      	   	       {
	      	   	       	 *(kraj+br_cifara)=*kraj;
	      	   	       	 kraj--;
	      	   	       }
	      	   	 i=0;      
	      	   	 while (broj)
	      	   	       {
	      	   	       	 cifra=broj%10;
	      	   	       	 niz[i]=cifra;
	      	   	       	 int *pok=niz[i];
	      	   	       	 *pom++=*pok;
	      	   	       	 broj/=10;
	      	   	       }	 
	      	  	 if (broj<0)  *tekst++='-';
	      	   	 pom++;     
	      	     if (*pom==' ') continue; 
	      	   
	       }
   return pocetak;
	
}
int main() {
	char string[1000]; int br;
	unesi(string, 1000);
	scanf ("%d", &br);
	ubaci_broj(string, br);
	printf ("%s", string);
	return 0;
}
