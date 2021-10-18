#include <stdio.h>

int ubaci(char karakter,char* tablica, int* pomocnaTablica, int velicina){
	int i=0;
	int found = 0;
	for( i = 0; i < velicina; i++){
		if(karakter == tablica[i]){
			pomocnaTablica[i]++;
			found = 1;
			break;
		}
	}
	if(found == 0){
		tablica[velicina] = karakter;
		pomocnaTablica[velicina] = 1;
		return velicina +1;
	}
	return velicina;
}
void sortPoVelicini(char* tablica,int* pomocnaTablica,int velicina){
	int i = 0, j = 1;
	for(i = 0; i < velicina; i++){
		for(j = 1; j < velicina; j++){
			if(pomocnaTablica[j - 1] < pomocnaTablica[j] || (pomocnaTablica[j -1] == pomocnaTablica[j] && tablica[j - 1] > tablica[j])){
				int tmp = pomocnaTablica[j];
				pomocnaTablica[j] = pomocnaTablica[j-1];
				pomocnaTablica[j -1] = tmp;
				
				char tmpc = tablica[j];
				tablica[j] = tablica[j - 1];
				tablica[j - 1] = tmpc;
				
			}
		}
	}
}
void popuni(char* tablica,int velicina){
	int i = 0, j = 0, novaVelicina = velicina;
	for(i = 0; i < 96; i++){
		int found = 0;
		for(j = 0; j < velicina; j++){
			if(tablica[j] == (char)(i+32)){
				found = 1;
			}
		}
		if(found == 0){
			tablica[novaVelicina] = (char)(i + 32);
			novaVelicina++;
			
		}
	}
	tablica[95] = '\0';
	return;
}
char* kodiraj(char* tekst, char* tablica){
	int pomocnaTablica[100];
	int velicina = 0;
	char* pok = tekst;
	while(*pok != '\0'){
		velicina = ubaci(*pok,tablica,pomocnaTablica,velicina);
		pok++;
	}
	//for(i = 0; i < velicina; i++) printf("%c",tablica[i]);
	sortPoVelicini(tablica,pomocnaTablica,velicina);
	popuni(tablica, velicina);
	
	pok = tekst;
	while(*pok !='\0'){
		int counter = 0;
		while(tablica[counter] != *pok) counter++;
		*pok = (char)(126 - counter);
	//	printf("%c",*pok);
		pok++;
	}
	return tekst;
}
char* dekodiraj(char* tekst, char* tablica){
	char* pok = tekst;
	while(*pok != '\0'){
		int counter = 126 - (int)(*pok);
		*pok = (char)(tablica[counter]);
		pok++;
	}
	return tekst;
}
int main() {
	char tekst[100] = "LLMLNLNMONM";
	char tabela[100] = "";
	int i = 0;
	printf(" %s |||",kodiraj(tekst,tabela));
	for(i = 0; i < 10; i ++) printf("%c",tabela[i]);
	printf(" %s |||",dekodiraj(tekst,tabela));
	return 0;
}
