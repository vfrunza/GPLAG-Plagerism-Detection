#include <stdio.h>

char* kodiraj(char* string,char* sifrarnik){
	int i,j;
	char* kopija;
	char *kopijaSifrarnika;
	int brojaci[95]={0};
	
	kopija=string;
	kopijaSifrarnika=sifrarnik;
	
	int indeks;
	
	while(*kopija!='\0'){
		indeks = *kopija;
		indeks -=32;
		brojaci[indeks]++;
		kopija++;
	}
	int max=0;
	for(i=0;i<95;i++){
		
		if(brojaci[i]>max){
			max=brojaci[i];
		}
	}
	char znak;
	while(max>0){
		for(i=0;i<95;i++){
			if(brojaci[i]==max){
				*kopijaSifrarnika = (char)i+32;
				kopijaSifrarnika++;
				znak=i+32;
			}
		}
		max--;
	}
	*kopijaSifrarnika=' ';
	for(i=0;i<95;i++){
		if(brojaci[i]==0){
			*kopijaSifrarnika = (char)i+32;
			kopijaSifrarnika++;
		}
	}
	*kopijaSifrarnika='\0';
	kopijaSifrarnika = sifrarnik;
	kopija = string;
	int pozicija=0;
	while(*kopija !='\0'){
		kopijaSifrarnika = sifrarnik;
		pozicija = 0;
		while(*kopijaSifrarnika != znak){
			if(*kopijaSifrarnika == *kopija){
				break;
			}
			kopijaSifrarnika++;
			pozicija++;
		}
		*kopija = 126-pozicija;
		kopija++;
	}
	return string;
}
char* dekodiraj(char* string,char* sifra){
	char* pok=string;
	int pozicija;
	for(;;){
		if(*string!='\0'){
			pozicija=126-*string;
			*string=sifra[pozicija];
		}
		else break;
		
		string++;
	}
	return pok;
}

int main() {
	char tekst[]="LLMLNLNMONM";
	char sifrarnik[100];
	kodiraj(tekst,sifrarnik);
	printf("%s",tekst);
	return 0;
}
