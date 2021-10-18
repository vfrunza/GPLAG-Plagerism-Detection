#include <stdio.h>

int DaLiSlovo(char slovo){
	if(slovo<'A' || slovo>'z' || (slovo>'Z' && slovo <'a')) return 1;
	return 0;
}

int provjeri_duzine(char *tekst, int *niz, int broj){
	int j=0,  i=0, razmak=1, ne;
	
	while(*tekst!='\0' ){
		ne=DaLiSlovo(*tekst); /* ne=1 ako neki clan u tekstu nije slovo, a n=0 ako jeste slovo*/
		
		if(ne==1){ razmak=1; /*ako je 1 onda to brojim kao razmak, jer je to definicija rijeci u ovom zadatku*/
		 }
		else if(razmak==1){

			while(ne!=1){ /*sve dok je ne neko slovo, ova while petlja radi*/
				i++;
				tekst++;
				ne=DaLiSlovo(*tekst); /*svaki put daje novu vrijednost ne*/
			}
			
			if(i!=niz[j]) return 0;
			tekst--;
			razmak=0;
			j++;
			
		}
		
		i=0;
		
		tekst++;
	}
	
	if(broj!= j) return 0;
	
	return 1;
}

int main() {
	char tekst[100]={"Ja sam Nadza Buhic"};
	int niz[]={2,3,5,5};
	int broj;
	
	broj=provjeri_duzine(tekst, niz, 4);
	
	if(broj==1) printf("Uslov je ispunjen!");
	else printf("Uslov nije ispunjen!");
	return 0;
}
