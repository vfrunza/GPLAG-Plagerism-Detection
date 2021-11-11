#include <stdio.h>

char *kodiraj(char *tekst, char *sifra){
	int ponavljanja[100]={0};
	char tabela[100]={0};
	char *sifra_pomoc=sifra;
	char *poc=tekst;
	int i,j,max;
	//Pravi tabelu ASCII znakova
	for (i=0;i<95;i++){
		tabela[i]=' '+i;
	}
	tabela[i]='\0';

	while (*tekst!='\0'){
		//Broji koliko se puta koji znak ponavlja
		for (i=0;i<95;i++){
			if(*tekst==tabela[i]){
				ponavljanja[i]++;
				break;
			}
		}
		tekst++;
	}
	//Pravi sifrarnik po broju ponavljanja i ASCII vrijednosti
	for(i=0;i<95;i++){
		max=0;
		for(j=0;j<95;j++){
		if(ponavljanja[j]>ponavljanja[max])
		max=j;
		}

		*sifra=tabela[max];
		sifra++;
		for(j=max;j<95;j++){
			tabela[j]=tabela[j+1];
			ponavljanja[j]=ponavljanja[j+1];
		}	
	}
	tekst=poc;
//Mijenja znakove teksta za odgovarajuce iz sifrarnika	
while(*tekst!='\0'){
sifra=sifra_pomoc;
	for(i=0;i<95;i++,sifra++){
		if(*tekst==*sifra){
			*tekst=126-i;
			break;
		}
	}
	tekst++;
  }
return poc;
}

char *dekodiraj(char*tekst, char*sifra){
	int i;
	char *poc=tekst;
	while(*tekst!='\0'){
		for(i=0;i<96;i++){
			if(*tekst==126-i){
				*tekst=sifra[i];
				break;
			}
		}
		tekst++;
	}
	return poc;
}

int main() {
	char sifra[97];
	char tekst[]="Test Test Test\0";
	printf("%s",kodiraj(tekst,sifra));
	printf("\n%s", dekodiraj(tekst,sifra));
	return 0;
}
