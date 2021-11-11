#include <stdio.h>

int jeSlovo(char karakter){
	if(karakter >= 'a' && karakter <= 'z' ) return 1;
	if(karakter >= 'A' && karakter <= 'Z' ) return 1;
	return 0;
}
char umaloSlovo(char karakter){
	if(karakter >= 'A' && karakter <= 'Z') return (karakter + ('a' - 'A'));
	else return karakter;
}
int isteRijeci(char* pocetakPrve, char* krajPrve, char* pocetakDruge, char* krajDruge){
	int iste = 1;
	while(pocetakPrve != krajPrve && pocetakDruge != krajDruge){
		if(umaloSlovo(*pocetakPrve) != umaloSlovo(*pocetakDruge)){
			iste = 0;
		}
		pocetakPrve++;
		pocetakDruge++;
	}
	if(pocetakPrve != krajPrve || pocetakDruge != krajDruge)
		iste = 0;
	return iste;
}
void izbaciRijec(char* pocetak, char* kraj){
	while(*kraj != '\0'){
		*pocetak = *kraj;
		pocetak++;
		kraj++;
	}
	*pocetak = '\0';
}

char* izbaci_najcescu(char* s){
	
	int redniBrojRijeci = 1, redniBrojNajcesce = -1, brojPonavljanja = -1, ponavljanjeNajcesce = -1;
	char* pok = s, *najcescaPocetak = '\0', *najcescaKraj = '\0';
	char* pocetakRijeci, *krajRijeci, *noviPocetak;
	if(*pok == '\0') return s;
	while(*pok != '\0'){
		while(*pok != '\0' && !jeSlovo(*pok)){
			pok++;	
		}
		pocetakRijeci = pok;
		while(*pok != '\0' && jeSlovo(*pok)){
			//printf("%c",*pok);
			pok++;
		}
		krajRijeci = pok;
		
		brojPonavljanja = 0;
		noviPocetak = pok;
		while( *noviPocetak != '\0' ){
			while(*noviPocetak != '\0' && !jeSlovo(*noviPocetak)){
				noviPocetak++;
			}
			 
			char* drugiPocetak = noviPocetak;
			while(*noviPocetak != '\0' && jeSlovo(*noviPocetak)){
				//printf("%c",*noviPocetak);
				noviPocetak++;
			}
			char* drugiKraj = noviPocetak;
			
			if(isteRijeci(pocetakRijeci, krajRijeci, drugiPocetak, drugiKraj)){
				brojPonavljanja++;		
			}
		}
		if(brojPonavljanja > ponavljanjeNajcesce){
			ponavljanjeNajcesce = brojPonavljanja;
			redniBrojNajcesce = redniBrojRijeci;
			najcescaPocetak = pocetakRijeci;
			najcescaKraj = krajRijeci;
			
		}
		redniBrojRijeci++;
	}
	pok--;
	while(pok+1 != najcescaKraj){
		
		while(!jeSlovo(*pok)){
			pok--;
		}
		if(pok+1 == najcescaKraj) break;
		char* drugiKraj = pok;
		while(jeSlovo(*pok)){
			pok--;
		}
		if(isteRijeci(najcescaPocetak,najcescaKraj,pok+1,drugiKraj+1)){
			izbaciRijec(pok+1,drugiKraj+1);
		}
		
		
	}
	izbaciRijec(najcescaPocetak,najcescaKraj);
	
	
	return s;
}
int main() {
	printf("Zadaća 4, Zadatak 1");
	char recenica[100] = "jedna dva         tri       dva      tri jedan tri";
	printf("%s",izbaci_najcescu(recenica));
	return 0;
}
