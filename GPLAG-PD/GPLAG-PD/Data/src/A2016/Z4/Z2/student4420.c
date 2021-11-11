#include <stdio.h>
struct kod{
	char znak;
	int brojPonavljanja;
};
char* kodiraj(char* text, char* sifrarnik);
char* dekodiraj(char* text, char* sifrarnik);
int ponavljanjeChara(char* string, char znak);
void sortacijaNiza(struct kod niz[]);
int maksimalnaPozicija(struct kod niz[], int duzina);
void ispisNiza(struct kod niz[]);
void unesi(char niz[], int velicina);
int mjestoUTabeli(char* tabela, char znak);
int main() {
	
	char text[] = "LLMLNLNMONM";
	char sifrarnik[100] = "";
	int i;
	kodiraj(text, sifrarnik);
	printf("%s\n", text);
	for (i=0; i<10; i++) printf("%c", sifrarnik[i]);
	dekodiraj(text, sifrarnik);
	printf("\n%s", text);	
	return 0;
}
 
char* kodiraj(char* text, char* sifrarnik){
	char i;
	char* startSifrarnika= sifrarnik;
	char* start= text;
	struct kod sifra[95];
 	i=32;
	while(i<127){
		sifra[i-32].znak= i;
		sifra[i-32].brojPonavljanja= ponavljanjeChara(text, i);
		i++;
	}
	sortacijaNiza(sifra);
 	i=0;
	while(i<95){
		*sifrarnik++= sifra[i].znak;
		i++;
	}
	*sifrarnik= '\0';
	sifrarnik= startSifrarnika;
 
	while (*text!='\0') {
		*text= 126 - mjestoUTabeli(sifrarnik, *text);
		text++;
	}
 
	return start;
}
int ponavljanjeChara(char* string, char znak){
	int brojac=0;
	while(*string!='\0')
		if(*string++==znak)
			brojac++;
	return brojac;
}
void sortacijaNiza(struct kod niz[]){
	struct kod temp;
	int i, index;
	i = 0;
	while(i<95){
		index= maksimalnaPozicija(niz+i, 95-i)+i;
		temp= niz[index];
		for(; index>i; index--){
			niz[index]= niz[index-1];
		}
		niz[i]=temp;
		i++;
	}
 
}
int maksimalnaPozicija(struct kod niz[], int duzina){
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
int mjestoUTabeli(char* tabela, char znak){
	int i;
	for(i=0; i<95; i++)
		if(*(tabela+i)== znak)
			return i;
}
char* dekodiraj(char* text, char* sifrarnik){
	int mjestoUTabeli;
	char* start= text;
	printf("\n");
	while (*text!='\0') {
		*text= *(sifrarnik+ (126 - *text));
		text++;
	}
	return start;
}