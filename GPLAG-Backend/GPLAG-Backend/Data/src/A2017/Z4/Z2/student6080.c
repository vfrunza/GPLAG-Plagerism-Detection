#include <stdio.h>
void unesi(char niz[], int velicina)
{
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

int provjeri_duzine(char* s, int niz[], int vel){
	int razmak=1, broj_rijeci=0, broj_slova=0, niz1[100]={0}, i=0, j=0, jest=1;
	while(*s!='\0'){
		if (!(*s>='A' && *s<='Z' || *s>='a' && *s<='z')){
		razmak=1;
		if(broj_slova!=0){
		niz1[i++]+=broj_slova;
		broj_slova=0;}}
		else if(razmak==1){
		razmak=0;
		broj_slova=0;
		broj_rijeci++;}
		if(razmak==0){
		broj_slova++;}
		s++;}
		char* kraj=s;
		while(*kraj!='\0') kraj++;
		if(*(kraj-1)>='A' && *(kraj-1)<='Z' || *(kraj-1)>='a' && *(kraj-1)<='z'){
		if(broj_slova!=0){
		niz1[i++]+=broj_slova;
		broj_slova=0;}}
		if(broj_rijeci==i && broj_rijeci==vel){
			for(j=0; j<vel; j++)
			if(niz1[j]!=niz[j]){
			jest=0; break;}}
		else return 0;
		if(jest==1)
		return 1;
		else 
		return 0;
	}
int main() {
	char x[100];
	int niz[100],vel,i;
	printf("Unesite string: ");
	unesi(x,100);
	printf("Unesite velicinu niza: ");
	scanf("%d", &vel);
	printf("Unesite niz brojeva: ");
	for(i=0; i<vel; i++){
	scanf("%d", &niz[i]);}
	printf("%d", provjeri_duzine(x,niz,vel));
	return 0;
}
