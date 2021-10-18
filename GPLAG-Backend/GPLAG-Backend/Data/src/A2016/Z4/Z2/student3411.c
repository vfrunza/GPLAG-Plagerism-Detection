#include <stdio.h>
char *kodiraj(char *tekst, char* tablica){
	char *pocetak=tekst;
	char *s=tekst;
	char *pocetak1=tablica;
	char x;
	int niz[127]={0}, i=0, br=0,br1=0,max,max_ind=0;
	//niz int-ova u kojem index predstavlja ascii vrijednost, a niz[index] koliko se puta ponovio znak cija je ascii vrijednost=indexu i tekstu
	while(*s!='\0'){
		niz[*s]++;
		s++;
	}
	//broji koliko clanova vecih od nule ima u nizu, tj koliko se razlicitih karatkera nalazi u tekstu
	for(i=32; i<127; i++){
		if(niz[i]>0) br++;
	}
	//petlja koja u tablicu ubacuje ascii vrijednosti karatkera koji su se pojavili u tekstu(od najviseg broja ponavljanja do najmanjeg)
	while(br>0){
		max=-1;
		for(i=32; i<127; i++){
			if(niz[i]>max) {
				max=niz[i];
				max_ind=i;
			}
		}
		x=max_ind;
		*tablica=x;
		tablica++;
		niz[max_ind]=-2;
		br--;
	}
	tablica=tablica+br1;
	//petlja koja ubacuje ascii vrijednosti znakova koje su se ponavljali 0 puta u tekstu
	for(i=32; i<127; i++){
		if(niz[i]==0){
			x=i;
			*tablica=x;
			tablica++;
		}
	}
	*tablica='\0';
	tablica=pocetak1;
	tekst=pocetak;
	//petlja koja kodira zadani tekst
	while(*tekst!='\0'){
		br1=0;
		tablica=pocetak1;
		while(*tablica!='\0'){
			if(*tekst==*tablica){
				x=126-br1;
				*tekst=x;
				break;
			}
			tablica++;
			br1++;
		}
		tekst++;
	}
	return pocetak;
	
}
char *dekodiraj(char *tekst, char *tablica){
	char *pocetak=tekst;
	char *pocetak1=tablica;
	int niz[127]={0}, i=0, br=0,br1=0,br2=0;
	//niz int-ova u kojem index predstavlja ascii vrijednost, a niz[index] koliko se puta ponovio znak, cija je ascii vrijednost=indexu, u tekstu
	while(*tekst!='\0'){
		niz[*tekst]++;
		tekst++;
		br2++;
	}
	//broji koliko clanova vecih od nule ima u nizu, tj koliko se razlicitih karatkera nalazi u tekstu
	for(i=32; i<127; i++){
		if(niz[i]>0) br++;
	}
	
	//zamjena karatkera teksta, tako da se dobije početni tekst
	tablica=pocetak1;
	while(br>0){
		tekst=pocetak;
		while(*tekst!='\0'){
			if(*tekst==126-br1){
				*tekst=*(tablica+br1);
				br2--;
				if(br2==0) break; 
				
			}
			tekst++;
		}
		if(br2==0) break;
		br--;
		br1++;
	}
	return pocetak;
}
int main() {
	    char tekst[] = "Ovo cemo kodirati i dekodirati u istoj liniji";
    char sifrarnik[100] = "";
    int i;
    dekodiraj(kodiraj(tekst, sifrarnik), sifrarnik);
    printf("%s", tekst);
    for(i = 0; i < 20; i++) printf("%c", sifrarnik[i]);
	return 0;
}
