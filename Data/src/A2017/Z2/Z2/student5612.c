#include <stdio.h>

int main() {
	int niz1[100],n,i,niz2[1000],j;
	int broj_cifara_niza, neka_cifra;
	int nepromjenjeni_niz;
	int broj_cifara_drugog_niza = 0;
	int niz_cifara;
	int brojac_uzastopnih = 0, brojaci=0,niz3[1000];
	
	/*Unos velicine niza*/
	do{
		
		printf("Unesite velicinu niza: ");
		scanf("%d", &n);
		
	} while(n <0 || n > 100);
	
	
	/*Unos clanova niza velicine n*/
	printf("Unesite clanove niza: ");
		for(i = 0; i < n; i++){
			scanf("%d", &niz1[i]);
	}
	
	/*Prebrojavanje ukupnog broja cifara koje sadrzi niz*/
	
	for(i = 0; i < n; i++){
		nepromjenjeni_niz = niz1[i]; /*Ovo se koristi da niz ne dobije nove vrijednosti nakon izlaska iz petlje*/
		
		broj_cifara_niza = 1; /*Broj cifara se stavlja na 1 jer ce sigurno biti minimalno jedna cifra prilikom unosa*/
		
		neka_cifra = nepromjenjeni_niz % 10;
		
		nepromjenjeni_niz=nepromjenjeni_niz/10;
		
		while(nepromjenjeni_niz != 0){
			
			neka_cifra = nepromjenjeni_niz % 10;
			
			broj_cifara_niza++;
			
			nepromjenjeni_niz = nepromjenjeni_niz / 10;
			
		}
		broj_cifara_drugog_niza =  broj_cifara_niza + broj_cifara_drugog_niza;
		
	}
	
	/*Formiranje novog niza*/
	
	j = 0; /*Postavljamo brojac j na 0, a to ce biti brojac za niz_cifara*/
	
	for(i = n-1; i >= 0; i--){	/*Niz ide sa kraja jer je tako lakse upisivati cifre u njega*/
	
		niz_cifara = niz1[i];	/*Ovo se koristi da niz ne promijeni svoju vrijednost nakon izlaska iz petlje*/
		
		neka_cifra = niz_cifara % 10;
		
		niz_cifara = niz_cifara / 10;
		
		niz2[j] = neka_cifra;
		
		while(niz_cifara != 0){
			
			j++;
			
			neka_cifra = niz_cifara % 10;
			
			niz2[j] = neka_cifra;
			
			niz_cifara = niz_cifara / 10;
		}
		
		j++;
		
		if(j == broj_cifara_drugog_niza){
			break;
		}
		
	}
	
	/*Formiranje finalnog niza*/
	for(i = broj_cifara_drugog_niza-1; i >= 0; i--){
		
		 brojac_uzastopnih = 1;
		 
		for(j = i-1; j >= 0; j--){
		
			if(niz2[i] == niz2[j]) {
				
				brojac_uzastopnih++;
				
				niz2[j] = niz2[i];
				
				i--;
				
				broj_cifara_drugog_niza--;
			}
			
		else if(niz2[i] != niz2[j]){
			break;
		}
	}
		niz3[brojaci] = niz2[i];
		niz3[brojaci+1] = brojac_uzastopnih;
		brojaci = brojaci + 2;
}
	printf("Finalni niz glasi:\n");
	for(i = 0; i < brojaci; i++){
		printf("%d ", niz3[i]);
	}
	
	return 0;
	
}
