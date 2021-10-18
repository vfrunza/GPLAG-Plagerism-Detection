#include <stdio.h>


int  provjeri_duzine(char *string, int niz[],int duzina){
	
	int i=0,brojac;
	
	while(*string!='\0'){
	 
		brojac=0;
		while(( *string>64 && *string<91) ||(*string>96 && *string<123)  && *string!='\0'){
			brojac++;
			string++;
		}
		if(brojac==0){ string ++;
		continue;}
		else if(brojac!=niz[i]) return 0;
		else i++;
			
	}
	if(i>duzina || i<duzina) return 0;
	return 1;
}

int main() {
char tekst[] = "Sada cemo dati jedan malo duzi string sa nesto vise rijeci nego u prethodnim testovima";
int niz[] = {4, 4, 4, 5, 4, 4, 6, 2, 5, 4, 6, 4, 1, 10, 9, 
/* Sada pocinju suvisni elementi */
1, 2, 3};


printf("%d ", provjeri_duzine(tekst, niz, 15));

	return 0;
}
