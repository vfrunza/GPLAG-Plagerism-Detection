#include <stdio.h>
char gg[2000]; //globalni niz u kojem cuvamo nasu recenicu prije kodiranja
int pozicija (char slovo, char* tekst){
//fja treba vratiti indeks naseg slova u tekstu
int i=0;
char*s=tekst; //pokazivac na nas tekst
while(*s!=slovo){
	s++;
	i++;
}
return i;
}

void fun(char slova[], int niz[], char* tekst, char* tablica) { //funkcija fun primi 2 niza, tekst i tablicu
int i,j;
//prvo nas niz charova napunimo asci vrijednostima od 32 do 126 kako je i receno u zadatku
for (i=32; i<=126; i++){
	slova[i-32]=i;
	
}
//poslije toga u nas drugi niz intova spasimo broj ponavljanja,
//tako da nas gornji niz slova pokazuje slovo a nas donji niz koliko se puta to slovo ponavlja
while(*tekst!='\0')
niz [(*tekst++)-32]++;
 // prodjemo kroz niz ponavljanja od vecih ka manjim
 // u slucaju da ima isto ponavljanja sortiramo po asci vrijednostima
 for(i=0;i<=94;i++){
 	for(j=i+1;j<=94;j++){
 		if((niz[j]>niz[i]) || (niz[j]==niz[i] && slova[j]<slova[i])) {
 			char temp2=slova[i];
 			slova[i]=slova[j];
 			slova[j]=temp2;
 			int temp1=niz[i];
 			niz[i]=niz[j];
 			niz[j]=temp1;
 		}
 	}
 }
//poslije ovoga nas sortirani niz slova prekopiramo u tablicu
for (i=0;i<=94;i++){
	*(tablica+i)=slova[i];}
	*(tablica+i)='\0';
}
char* kodiraj(char*tekst, char*tablica)
{
	char*pocetak=tekst,*s=tekst;
	char slova[200];
	int i, niz[200]={0};
	
	char*global=gg;
	while (*s!='\0')
	//global je pokazivac na globalni niz gg i u njega prekopiramo recenicu
	*global++=*s++;
	*global='\0';
	
	fun (slova, niz, tekst, tablica);
	// u fju saljemo nizove tekst i tablicu, a fja ce te nizove napunit, sortirat po broju ponavljanja i to prebacit u tablicu
	//i na kraju sto je i receno u zadatku svaki znak postaje 126-njegova pozicija u tablici
	while(*tekst!='\0'){
		int postaje=126-pozicija(*tekst,tablica);
		*tekst++=postaje;
	}
	return pocetak;
}
char* dekodiraj (char*tekst, char*tablica){
	//posto smo u nas globalni niz spasili tekst, samo ga prekopiramo nazad//
	char*gl=gg,*poc=tekst;
	while(*tekst!='\0'){
		*tekst++=*gl++;
	}
	return poc;
}
	
int main () {
	char tekst[]="Ovo je neki testni tekst";
	char sifrarnik[100]="";
	kodiraj (tekst, sifrarnik);
	printf("%s", tekst);
	dekodiraj(tekst,sifrarnik);
	printf("%s", sifrarnik);
	return 0;
}