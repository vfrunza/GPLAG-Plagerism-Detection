#include <stdio.h>
struct Datum {
	int dan;
	int mjesec;
	int godina; 
	
};
struct Datum d;
struct Uposlenik {
	char ime_prezime[50];
	struct Datum datum_rodjenja;
	
};
struct Uposlenik u;

int suzi_listu ( struct Uposlenik *kandidati, int vel,
struct Uposlenik direktor, int broj_dana) 
{
	int broj_dana[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	int razmak=0,g=0,ukupno=0;
	char *dprezime;
	char *kprezime;
	char *dpok=direktor.ime_prezime;
	while (*dpok!='\0') {
			if(*dpok==' ') {
				razmak=1
				dpok++;
				while(*(dpok+1)!='\0') {
				*dprezime=dpok;
				dprezime++;
				dpok++;
			}
				
			}
			dpok++;
	}
	if (direktor.datum_rodjenja.godina%4==0 && direktor.datum_rodjenja.godina%100!=0 || direktor.datum_rodjenja.godina%400==0){
			prestupna_d=1;
			broj_dana[2]++;
		} else {
			prestupna_d=0;
			//gd=365;
			
		}
		for(i=0;i<vel;i++) {
		if (kandidati[i].datum_rodjenja.godina%4==0 && kandidati[i].datum_rodjenja.godina%100!=0 || kandidati[i].datum_rodjenja.godina%400==0){
			//gk=366;
			broj_dana[2]++;
			prestupna_k=1
		}
		else {
			prestupna_k=1;
			//gk=365;
		} 
			
		}
		for(j=1;j<direktor.datum_rodjenja.godina;j++) {
			ukupnod+=365+prestupna_d;
		}
		for(j=1; j<direktor.datum_rodjenja.mjesec;j++) {
			ukupnod+=bdum[j];
			ukupnod+=direktor.datum_rodjenja.dan;
			
		}
		for(l=0;l<vel;l++) {
		for(k=1;k<kandidati[l].datum_rodjenja.godina;k++) {
			if(kandidati[il].datum_rodjenja.godina%4==0 && kandidati[l].datum_rodjenja.godina%100!=0 || kandidati[l].datum_rodjenja.godina%400==0) {
				gk
			}
	

		
		
	
	
	
	
	
	
	

	
}

int main() {
	printf("Zadaća 5, Zadatak 1");
	return 0;
}
