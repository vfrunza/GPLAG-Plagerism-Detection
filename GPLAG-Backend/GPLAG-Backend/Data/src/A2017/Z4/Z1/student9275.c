#include <stdio.h>


#include <math.h>

char *ubaci_broj(char *tekst, int broj){
	int cs = 0,pom,duz=0,pomocni_broj,suma = 0,br_cifre = 0,duzina;
	char *poc,*kraj;
	if(broj < 0 ){cs=1; broj = -broj;duz++;} //ako je negativan da zapamti
	pom = broj;
	while(pom != 0){duz++;suma = suma*10 + pom%10; pom/=10; br_cifre++;}
	duz+=1;
	duzina = duz;
	char *pocetak = tekst;
	while (*tekst != '\0') {
	
		duz = duzina;
				if(*tekst != ' ' && *tekst != '\0'){
					while(*tekst != ' ' && *tekst != '\0' )tekst++;
					kraj = tekst;
					poc = tekst;
					while(*kraj != '\0')kraj++; 
					while(*poc == ' ' && *poc != '\0')poc++;
					if(*poc == '\0')return pocetak; //ako je posljednja rijec,to ispituje poc
				
					if((poc - tekst) >= 2)duz--;
					//pomjeranje
					while (tekst < kraj) {
						*(kraj + duz) = *kraj;
						kraj--;
					}
					
					tekst++;
					pomocni_broj = suma;
					if(cs)*tekst++='-';
					pom = br_cifre;
					while(pomocni_broj != 0){
						*tekst = pomocni_broj%10 + '0';
						pomocni_broj/=10;
						tekst++;
						pom--;
					}
					if(pom != 0)*tekst++ = '0';
					*tekst = ' ';
				}
		tekst++;
		
	}
	return pocetak;
}

int main() {
char s[15] = "hello world";
printf("\"%s\"", ubaci_broj(s,15));
	return 0;
}
