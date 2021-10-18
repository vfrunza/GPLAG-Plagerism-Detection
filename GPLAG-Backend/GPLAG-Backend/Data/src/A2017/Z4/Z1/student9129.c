#include <stdio.h>

int daj_naopak(int broj) {
	int naopak=0;
	while(broj!=0) {
		naopak*=10;
		naopak+=broj%10;
		broj/=10;
	}
	return naopak;
}

char* ubaci_broj(char* tekst, int broj) {
	char* ret=tekst;
	char* pom_pok;
	int naopak=0, br_cifara=0,pomocni=0,i, negativan=0, posljednja_rijec=1;
	if(broj<0) {
		negativan=1;
		naopak=daj_naopak(-1*(broj));
	}
	else
	naopak=daj_naopak(broj);
	
	pomocni=broj;
	while(pomocni!=0) {
		pomocni/=10;
		br_cifara++;
	}
	
	while(*tekst!='\0') {
	/*ako je na pocetku razmak, pomjeramo sve dok je razmak*/
	if(*tekst==' ') {
		while(*tekst==' ') tekst++;
	}

	while(*tekst!=' ' && *tekst!='\0') tekst++;  /*pomjeramo do prve rijeci*/
	
	/*provjeravamo da li je posljednja rijec u stringu*/
	pom_pok=tekst;
	posljednja_rijec=1;
	while(*pom_pok!='\0' && *pom_pok!=' ') pom_pok++; /*pomjerimo do kraja trenutne rijeci, tj do prvog razmaka */
	while(1) {
		if(*pom_pok=='\0') break;
		else if(*pom_pok!=' ') {
			posljednja_rijec=0;
			break;
		}
		pom_pok++;
	}
	if(posljednja_rijec==1) return ret; 
	
	else {
		if(*tekst==' ') 
			tekst++;
		/*pravimo mjesto za ubacivanje broja	*/
			char* kraj=tekst;
			while(*kraj!='\0') {
				kraj++;
			} 
		if(negativan) {
			while(kraj>=tekst) {
			*(kraj+br_cifara+1)=*kraj;
			kraj--;
		}
		*tekst='-';
		tekst++;
		for(i=0; i<br_cifara; i++) {
			*tekst=(naopak%10+'0');
			naopak/=10;
			tekst++;
		}
	}
		else {
		while(kraj>=tekst) {
			*(kraj+br_cifara)=*kraj;
			kraj--;
		}
		for(i=0; i<br_cifara; i++) {
			*tekst=(naopak%10+'0');
			naopak/=10;
			tekst++;
		}
	
	}

		/*ubacujemo razmak nakon broja*/
		if(*(tekst+1)!=' ' && *(tekst+1)!='\0' ) {
			char* kraj2=tekst;
			while(*kraj2!='\0') {
				kraj2++;
			} 
			while(kraj2>=tekst) {
				*(kraj2+1)=*kraj2;
				kraj2--;
			}
			*tekst=' ';
		} 

}

	if(*tekst!='\0')
	tekst++;
	if(negativan) naopak=daj_naopak(-1*broj);
	else
	naopak=daj_naopak(broj);
	}
	return ret;
}

int main() {
	int br=0, naopak=0, br_cifara=0;
	printf("broj, string: ");
	scanf("%d", &br);
	naopak=daj_naopak(br);
	printf("\nbroj: %d", naopak%10);

	return 0;
}
