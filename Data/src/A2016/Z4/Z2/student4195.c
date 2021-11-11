#include <stdio.h>


char* kodiraj(char *tekst, char tablica_sifri[])
{
	char *pocetna_adresa_teksta=tekst,*pocetna_adresa_sifri=tablica_sifri,znak,*zadnja_adresa_teksta=tekst,*tmp;
	int broj_ponavljanja[40]={0},brojac=0,temp,i,j,ascii_kodovi_slova[40],razlicit=1;

	while(*tekst!='\0') {
		znak=*tekst;
		*tablica_sifri++=znak;
		ascii_kodovi_slova[brojac]=znak;
		razlicit=0;
		/*Prebrojimo ponavljanje znaka*/
		while(*tekst!='\0') {
			if(*tekst == znak)
				broj_ponavljanja[brojac]++;
			tekst++;
		}
		/*Pomjerimo brojac za jedno mjesto da ga "pripremimo" za novi znak*/
		brojac++;
		tekst=++zadnja_adresa_teksta; 
		tmp=tablica_sifri;
		tablica_sifri=pocetna_adresa_sifri;
		/*Trazimo sljedeci razlicit znak */
		while(!razlicit && *tekst!='\0') {
			razlicit=1;
			temp=brojac;
			while(temp){
				if(tablica_sifri[temp-1] == *tekst) {
					razlicit=0;
					break;
				}
				temp--;
			}
			if(razlicit)
				zadnja_adresa_teksta=tekst;
			else
				tekst++;
		}
		tablica_sifri=tmp;
	}
	
	brojac--;
	tekst=pocetna_adresa_teksta;
	tablica_sifri=pocetna_adresa_sifri;
	for(i=0; i<brojac; i++) {
		for(j=i+1; j<=brojac; j++) {
			if(broj_ponavljanja[i]<broj_ponavljanja[j]) {
				temp = broj_ponavljanja[i];
				broj_ponavljanja[i] = broj_ponavljanja[j];
				broj_ponavljanja[j] = temp;
				znak = *(tablica_sifri+i);
				tablica_sifri[i] = tablica_sifri[j];
				tablica_sifri[j]=znak;
			}
			else if (broj_ponavljanja[i]==broj_ponavljanja[j]) {
				if(tablica_sifri[j]<tablica_sifri[i]) {
				znak = tablica_sifri[i];
				tablica_sifri[i] = tablica_sifri[j];
				tablica_sifri[j]=znak;
				}
			}
		}
	}
	
	tablica_sifri=pocetna_adresa_sifri+brojac+1;
	
	/*Dodavanje svih onih koji se ponavljaju nula puta*/
	for(i=32; i<=126; i++) {
		razlicit=1;
		for(j=0; j<=brojac; j++) {
			if(ascii_kodovi_slova[j]==i) {
				razlicit=0;
				break;
			}
		}
		if(razlicit){
			*tablica_sifri++=i;
		}
	}
	/*Kodiranje*/
	tablica_sifri=pocetna_adresa_sifri;
	while(*tekst!='\0') {
		for(i=0; ; i++) {
			if(*tekst==tablica_sifri[i]) {
				*tekst=126-i;
				break;
			}
		}
		tekst++;
	}
	
	tekst=pocetna_adresa_teksta;
	tablica_sifri=pocetna_adresa_sifri;
	return tekst;
}

char* dekodiraj(char* tekst,char* tablica_sifri) {
	char *pocetna_adresa_teksta=tekst;
	int i;
	while(*tekst!='\0') {
		i = 126 - *tekst;
		*tekst = tablica_sifri[i];
		tekst++;
	}
	tekst=pocetna_adresa_teksta;
	return tekst;
}


int main()
{
	
	char tekst[100]="LLMLNLNMONM";
	char tablica[100] = "";
	dekodiraj(kodiraj(tekst,tablica),tablica);
	printf("\n%s",tekst);
	return 0;
}
