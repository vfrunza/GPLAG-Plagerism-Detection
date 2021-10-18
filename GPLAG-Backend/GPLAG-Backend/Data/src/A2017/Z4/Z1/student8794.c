#include <stdio.h>

void unesi (char niz[], int velicina){
	int i=0;
	char znak = getchar ();
		if (znak == '\n') znak= getchar();
	while (i<velicina-1 && znak!= '\n'){
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}

int duzina (char*s){
	int duz=0;
	while (*s!='\0'){
		duz++;
		s++;
	}
	return duz;
}

/*int izvrzniNaopako (int broj){
	char sbroj [12]; /* 9 za cifre, 1 za predznak, 1 za \0 
	char *sb = sbroj;
	do{
		*sb= broj%10 + '0';
		broj/=10;
		*sb++;
	}while (broj != 0);
	
	return sb;
}*/

/*char *intUString(int broj, char* brojUstringu){
	char *pom = brojUstringu, *vrati = brojUstringu, temp;
	
	while(broj>0){
		*pom = (broj%10)+48;
		broj/=10;
		pom++;
	}
	
	*pom = '\0';
	pom--;
	while(brojUstringu<pom){
		temp = *pom;
		*pom = *brojUstringu;
		*brojUstringu = temp;
		brojUstringu++;
		pom--;
	}
	return vrati;
}*/
char* ubaci_broj (char* tekst, int broj){
	int i=0, j=0;
	/*int razmak=1, brRijeci=0;*/
	int tmp=broj, brcifri=0;
	int jelNegativan = 0;
	char sbroj [12]; /* 9 za cifre, 1 za predznak, 1 za \0 */
	char *sb = sbroj;
	char *pok = tekst;
	char praviRedoslijed[12];
	
	
	
	/*prebrojavanje rijeci stringa*/
	/*while (*tekst!='\0'){
		if (*tekst==' ') razmak=1;
		else if (razmak==1){
			razmak=0;
			brRijeci++;
		}
		tekst++;
	}*/
	
	/* predznak */
	if (broj<0){
		broj=-broj;
		*sb++='-';
		jelNegativan = 1;
	}
	
	
	
	/* prebrojavamo cifre broja */
	while(tmp!=0) { 
		tmp/=10;
		brcifri++;
		
	}
	
	//*sb++='\0';  
	
	
	
	do{
		*sb= broj%10 + '0';
		broj/=10;
		*sb++;
	}while (broj != 0);
	
	if(jelNegativan==1) brcifri++;
	
	
	/*for(i=0;i<duzinaStringa;i++){
		if(tekst[i] == ' '){
			j=0;
			char *kraj = tekst[duzinaStringa-1];
			while(*kraj!=tekst[i]){
				*(kraj+brcifri) = *kraj;
				kraj--;
			}
			for(j=0;j<brcifri;j++){
				*kraj = sbroj[j];
				kraj++;
			}
			while(*kraj == ' ') kraj++;
			duzinaStringa+=brcifri;
		}
	}*/
	
	while (*pok != '\0'){
		if (*pok == ' '){
			
		i=0;
		char *kraj=pok; 
		
			while (*kraj != '\0') kraj++;
			
			while (kraj >= pok){
				*(kraj+brcifri)=*kraj;
				kraj--;
			}
			
			/*stavljanje broja u pravi redoslijed, upisat ce broj lijepo, ali ne smiju se koristiti pomocni nizovi*/
			/*for (j=0; j<=brcifri; j++){
				praviRedoslijed[brcifri-1-j]=sbroj[j];
				
			}*/
			
		
				
				
			while(i<brcifri){
				
			*pok++ = sbroj[i];
			i++;
				
			}
		/*	pok++;
			while(*pok == ' ') pok++;*/
		}
		
	    
	 	pok++;
	}
	return tekst; 
}

int main() {
	char tekst[100];
	int broj;
	printf("Unesite neki tekst: ");
	unesi (tekst, 100);
	printf ("Unesite broj koji zelite unijeti: ");
	scanf ("%d", &broj);
    
    ubaci_broj(tekst, broj);
    printf ("Nakon ubacivanja broja tekst glasi: %s", tekst);
	
	return 0;
}
