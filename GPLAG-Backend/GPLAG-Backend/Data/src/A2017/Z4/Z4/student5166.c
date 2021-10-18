#include <stdio.h>

int provjeri (char* p){
	char *pok1=p, *pok2, *pok3;
	char *niz[100]; /* Niz pokazivaca na char */
	int i=0, j=0, x=0, brojac=0, z=0;
	
	while (*pok1 != '\0'){
		if (*pok1 == '<' && *(pok1+1)!='/'){
			if (*(pok1+1) == '\0') break;
			niz[i] = (pok1+1); /* Postavljamo pokazivace na pocetak svakog imena taga */
			if (*(pok1+1)==' ' || *(pok1+1)=='>') return 0;
			i++;
		}
		pok1++;
	}
	
	pok1=p;
	while (*(pok1+1) != '\0'){
		
		if (*pok1=='<' && *(pok1+1)=='/'){
			
			pok2=(pok1+2);
			for (j=0; j<i; j++){
				pok3=niz[j];
				while (*pok3 != '>' && *pok3!=' '){ /* Trazimo da li je tag uredno zatvoren */
				    if (*pok3!=*pok2 && *pok3-32!=*pok2 && *pok3+32!=*pok2 && *pok3!=*pok2-32 && *pok3!=*pok2+32) break; /* pazimo na velika i mala slova */
				    pok2++;
				    pok3++;
				    z++;
	            }
	            pok2 -= z; /* Vracamo pok2 na pocetak */
	            z=0; 
	            if (*pok3 == '>' || *pok3==' '){
	        	    x=1; 
	        	    brojac++;
	        	    break;
	            }
			}
	        if (x==0) return 0; 
	        x=0;
	
        }
        pok1++;

    } if (brojac!=i) return 0;


return 1;
}

int main (){
	
	return 0;
}