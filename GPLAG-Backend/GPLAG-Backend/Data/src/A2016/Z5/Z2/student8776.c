#include <stdio.h>
#include <ctype.h>
#include <string.h>


void unesi(char niz[], int velicina){
	char znak=getchar();
	if(znak=='\n') znak=getchar();
	int i=0;
	while(i<velicina-1 && znak!='\n'){
		niz[i]=znak;
		i++;
		znak=getchar();
		
	}
	niz[i]='\0';
}
//da funkcija vrati 1 ako je znak koji je primila slovo
int slovo(int c){
	if(c>='A' && c<='Z' || c>='a' && c<='z')
	return 1;
	
	return 0;
	
}
//zamjena stringova
void swap(char*p, char*q){
	char temp[100];
	strcpy(temp, p);
	strcpy(p,q);
	strcpy(q,temp);
	
	
}
void kompresuj(char*naziv, char*naziv1){
	FILE*ulaz=fopen(naziv, "r");
	FILE* ulaz1=fopen(naziv, "r");
	FILE * izlaz=fopen(naziv1, "w");
	char rijeci[1000][1000];//1000 rijeci sa 1000znakova
	int brojac[1000]={0};// brojac ponavljanja svake rijeci
	int i;
	
	int broj_rijeci=0;
	char rijec[1000]; // rijec koju trenutno ucitavamo
	int duzina;
	char znak=fgetc(ulaz);
	
	
	while(znak!=EOF){ // uzimamo znak po znak dok ne dodjemo do kraja datoteke
	duzina=0;
	
	while(slovo(znak)){//provjerava da li je nas znak slovo, ako jeste znaci da je to rijec, uzimamo slova i ubacujemo u trenutnu.
		rijec[duzina++]=znak;
		znak=fgetc(ulaz);
		
	}
	rijec[duzina]='\0'; //stavljamo \0 na kraj

	if(duzina<10 && duzina!=0){
		int ima=0;
		int j;
		for(j=0; j<broj_rijeci; j++){//prolazak kroz rijeci da ih upisemo u matricu rijeci
		if(strcmp(rijeci[j], rijec)==0){// ako vec ima ta rijec povecavamo br ponavljanja
			ima=1;
			brojac[j]++;
		
			break;
		}
		
	}
	
	if(ima!=1) {// dodajemo ako je nema
	strcpy(rijeci[broj_rijeci], rijec);
	brojac[broj_rijeci++]=1;
	
	}
	
	
}
znak=fgetc(ulaz);
}
//unijeli u niz sve rijeci a u brojace koliko puta se ponavljaju
int j;

for(i=0; i<broj_rijeci; i++){
	for(j=i+1; j<broj_rijeci; j++){
		if(brojac[j]>brojac[i] || (brojac[j]==brojac[i] && strcmp(rijeci[i], rijeci[j])==1)){
			int temp=brojac[j];
			brojac[j]=brojac[i];
			brojac[i]=temp;
			
			swap(rijeci[i],rijeci[j]);
		}
	}
}


int kraj=10;
char novired='\n';
if(broj_rijeci<10) kraj=broj_rijeci; //10 rijeci treba, ako ih je manje onda  se to koristi

for(i=0; i<kraj; i++){// u izlaz unosimo rijeci iz niza
fputs(rijeci[i], izlaz);
fputc(novired,izlaz);
	
}

char c=fgetc(ulaz1);
while(c!=EOF){
	duzina=0;
	while(slovo(c)){ // uzimanjerijec po rijec
	rijec[duzina++]=c;
	c=fgetc(ulaz1);
}
rijec[duzina]='\0';

int kontrola=0;

if(duzina<10 && duzina!=0){
	for(j=0; j<kraj; j++){ // ako se nalazi u nizu mijenjamo sa znakom
	if(strcmp(rijeci[j], rijec)==0){
		char znk=j+20;
		kontrola=1;
		fputc(znk, izlaz);
		fputc(c,izlaz);
		break;
	}
}
}
if(kontrola==0){ //ako je nema u nizu samo je prekopiramo, odnosno ne mijenjamo
char*r=rijec;
while(*r!='\0'){
	fputc(*r, izlaz);
	r++;
}
fputc(c, izlaz);
}
c=fgetc(ulaz1);

}
printf("Datoteka kompresovana.\n");
fclose(ulaz);
fclose(ulaz1);
fclose(izlaz);
}

void dekompresuj(char * naziv, char* naziv1){
	FILE*ulaz=fopen(naziv,"r");
	FILE*ulaz1=fopen(naziv, "r");
	FILE*izlaz=fopen(naziv1, "w");
	char rijeci[1000][1000]={0}, rijec[1000];
	int broj_rijeci=0, duzina=0, brojackrajeva=0;
	char znak=fgetc(ulaz);
	int kontrola=0;
	while(znak!=EOF){
		duzina=0;
		kontrola=0;
		while(slovo(znak)){ //ponovno smjestanje rijeci u niz
		rijec[duzina++]=znak;
		znak=fgetc(ulaz);
	}
	rijec[duzina]='\0';
	
	if(duzina<10 && duzina!=0){// ako rijec moze biti zadana
	
	strcpy(rijeci[broj_rijeci], rijec);// kopiranje u niz rijeci
	int j;
	for(j=0; j<broj_rijeci; j++){//provjera da li ima ta rijec u nizu
		if(strcmp(rijeci[j], rijec)==0){
			kontrola==1;
			break;
		}}
		if(kontrola)
		break;
		broj_rijeci++;
	}
	znak=fgetc(ulaz);
	
}
brojackrajeva=0; //brojimo rijeci
char c=fgetc(ulaz1);
while(c!=EOF){
	if(c=='\n') brojackrajeva++; //brojanje n. mjesta
	if(brojackrajeva==broj_rijeci) break;//dolaskom na zadnju rijec prekidanje petlje ali pok. ostaje na tekst.poslije
	c=fgetc(ulaz1);
	}
	c=fgetc(ulaz1);
	while(c!=EOF) { //nastavak uzimanja rijeci
	int n=0;
	if(c>=20 && c<=30) { // sve od 20 do 30 mijenja se rijecima
	char *p=rijeci[c-20];
	n=1;
	while(*p!='\0'){// ubacivanje rijeci
	fputc(*p, izlaz);
	p++;
		
	}
	
}
if(n==0)// ako nije znak prepisujemo rijeci
fputc(c,izlaz);
c=fgetc(ulaz1);
}
printf("Datoteka dekompresovana.\n");
fclose(ulaz);
fclose(ulaz1);
fclose(izlaz);

}

int main() {
	int opcija;
	int a=1;
	char ulazna[100], izlazna[100];
	if(a==1){
	do{
		printf("Odaberite: 1 - kompresuj, 2 - dekompresuj, 0 - izlaz: ");
		scanf("%d", &opcija);
	
switch(opcija){
	case 1:

	printf("Unesite ime ulazne datoteke: ");
	unesi(ulazna,40);
	printf("Unesite ime izlazne datoteke: ");
	unesi(izlazna,40);
	kompresuj(ulazna,izlazna);
	break;

case 2:
	printf("Unesite ime ulazne datoteke: ");
	unesi(ulazna,40);
	printf("Unesite ime izlazne datoteke: ");
	unesi(izlazna,40);
	dekompresuj(ulazna,izlazna);
}
}

	while(opcija!=0);
	}
	
	return 0;
}
