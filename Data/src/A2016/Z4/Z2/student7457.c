#include <stdio.h>
struct kod{
	char znak;
	int brojPonavljanja;
};
char* kodiraj(char* tekst, char* sifrarnik);
char* dekodiraj(char* tekst, char* sifrarnik);
int brojPonavljanjaChara(char* string, char znak);
void sortirajNiz(struct kod niz[]);
int pozicijaMax(struct kod niz[], int duzina);
void printajNiz(struct kod niz[]);
void unesi(char niz[], int velicina);
int pozicijaUTabeli(char* tabela, char znak);
int main() {
	//printf("Zadaća 4, Zadatak 2");
	char tekst[] = "LLMLNLNMONM";
	char sifrarnik[100] = "";
	int i;
	kodiraj(tekst, sifrarnik);
	printf("%s\n", tekst);
	for (i=0; i<10; i++) printf("%c", sifrarnik[i]);
	dekodiraj(tekst, sifrarnik);
	printf("\n%s", tekst);	
	return 0;
}

char* kodiraj(char* tekst, char* sifrarnik){
	char i;
	char* pocetakSifrarnika= sifrarnik;
	char* pocetak= tekst;
	struct kod sifra[95];
	
	for(i=32; i<127; i++){
		sifra[i-32].znak= i;
		sifra[i-32].brojPonavljanja= brojPonavljanjaChara(tekst, i);
	}
	sortirajNiz(sifra);
	
	for(i=0; i<95; i++){
		*sifrarnik++= sifra[i].znak;
	}
	*sifrarnik= '\0';
	sifrarnik= pocetakSifrarnika;
	
	while (*tekst!='\0') {
		*tekst= 126 - pozicijaUTabeli(sifrarnik, *tekst);
		tekst++;
	}
	
	return pocetak;
}
int brojPonavljanjaChara(char* string, char znak){
	int brojac=0;
	while(*string!='\0')
		if(*string++==znak)
			brojac++;
	return brojac;
}
void sortirajNiz(struct kod niz[]){
	struct kod temp;
	int i, index;
	for(i=0; i<95; i++){
		index= pozicijaMax(niz+i, 95-i)+i;
		temp= niz[index];
		for(; index>i; index--){
			niz[index]= niz[index-1];
		}
		niz[i]=temp;
	}
	
}
int pozicijaMax(struct kod niz[], int duzina){
	int i, max=0;
	for(i=0; i<duzina; i++){
		if(niz[max].brojPonavljanja < niz[i].brojPonavljanja)
			max= i;
	}
	return max;
}
void unesi(char niz[], int velicina){
    char znak = getchar();
    if (znak == '\n') znak=getchar();
    int i = 0;
    while (i < velicina-1 && znak != '\n') {
        niz[i] = znak;
        i++;
        znak = getchar();
    }
    niz[i]='\0';
}
int pozicijaUTabeli(char* tabela, char znak){
	int i;
	for(i=0; i<95; i++)
		if(*(tabela+i)== znak)
			return i;
}
char* dekodiraj(char* tekst, char* sifrarnik){
	int pozicijaUnutarTabele;
	char* pocetak= tekst;
	printf("\n");
	while (*tekst!='\0') {
		*tekst= *(sifrarnik+ (126 - *tekst));
		tekst++;
	}
	return pocetak;
}