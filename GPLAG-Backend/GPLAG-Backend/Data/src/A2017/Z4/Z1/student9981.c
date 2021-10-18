/*Napisati funkciju sa prototipom

char* ubaci_broj (char* tekst, int broj)

koja prima string i neki cijeli broj tipa int, te u primljenom stringu ubacuje broj između svake dvije riječi.
Radi lakšeg lančanog pozivanja, funkcija vraća pokazivač na početak primljenog stringa. Pretpostaviti da je primljeni 
string dovoljno velik da primi sve dodatne karaktere. Obratite pažnju da broj može biti i negativan. 

Riječ se definiše kao niz karaktera omeđenih znakom razmaka, početkom i krajem stringa, tako da se npr. string "auto-stop"
smatra za jednu riječ. Prilikom ubacivanja broja razmak se treba nalaziti prije i poslije broja. Ako se između dvije riječi
nalazi dva ili više razmaka, broj treba ubaciti nakon prvog razmaka a ostale razmake ostaviti između broja i sljedeće riječi

Primjer: Ako je primljen string:
Ovo   je neki     primjer   teksta
i broj -123, nakon poziva funkcije string treba da glasi:
Ovo -123  je -123 neki -123    primjer -123   teksta

U programu je zabranjeno koristiti funkcije iz biblioteka string.h i stdlib.h, te funkcije sprintf i sscanf iz biblioteke 
stdio.h. Također je strogo zabranjeno kreirati pomoćni niz/string u funkciji!
*/

#include <stdio.h>

void unesi(char niz[], int velicina) {			/*Unesi recenicu*/
	int i = 0;
	
	char znak = getchar();
	if (znak == '\n') znak=getchar();
	
	while (i < velicina-1 && znak != '\n') {
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	niz[i]='\0';
}

int broj_cifri(int*s){
	int brojac=0;
	while (*s!='\0'){
		brojac++;
		s++;
	}
	return brojac;
}

char* ubaci_broj (char* tekst, int broj){
	
	int broj1[200],i;
	char* krajnji=tekst;
	int duzina=broj_cifri(broj);
	
	for( i=duzina; i>0; i--){
	broj1[i]=broj%10;
	broj=broj/10;
	}
	
	while (*tekst!='\0'){
		if (*tekst==' '){
			char *kraj=tekst;
			while (*kraj != '\0') kraj++;
			while (kraj>tekst){
				*(kraj+duzina)=*kraj;
				kraj--;
			}
			char*p=broj1[i];
			while (*p!='\0'){
			*tekst++=*p++;
			i++;
			}
		}
		tekst++;
	}
	
	return krajnji;
}
    
    
    
    
    /*char*krajnja=tekst;
    int istina=0;
	int brojac;
	brojac=broj_cifri(broj);
	
	
		 while (*tekst != '\0') {
   		  if (*tekst==' ' || *tekst=='\n' || *tekst=='\t'){
        if (istina==0){
       char * kraj = tekst;
   			 while (*kraj != '\0') kraj++;
   			 while (kraj > tekst) {
   				 *(kraj+brojac) = *kraj;
   				 kraj--;
   			 }
   			char *t=broj;
   			 while (*t!='\0'){
   		 		*tekst=*t;
   		 		tekst++;
   		 		t++;
   			 	
   			 }
   			 tekst--;
   	 }
   	    	 tekst++;
   	    	 istina=1;
}
        
        
        if (*tekst!=' ' && *tekst!='\n' && *tekst!='\t'){
            istina=0;
        }
    
   
    if(istina==0)   {    
    
   			 char* kraj = tekst;
   			 while (*kraj != '\0')
   			 kraj++;
   			 while (kraj > tekst) {
   				 *(kraj+brojac) = *kraj;
   				 kraj--;
   			 }
   			char *t=broj;
   			 while (*t!='\0'){
   		 		*tekst=*t;
   		 		tekst++;
   		 		t++;
   			 	
   			 }
   			 tekst--;
   	 }
   	    	 tekst++;
      	 
}
return krajnja;
}
*/


int main() {
	
	return 0;
}
