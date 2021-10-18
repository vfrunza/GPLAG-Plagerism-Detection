#include <stdio.h>
//string sa usmenog

int haberbot(char *s){
	char *vrati = s;
	int suma_parna = 0, suma_neparna = 0;
	int suma = 0;
	int vel;
	
	while(*s != '\0'){
		vel++;
		s++;
	}
	s= vrati;
	for(int i = 0 ; i < vel ; i++){
		suma += s[i] - '0';
	}
	return suma;
}
void unesi(char niz[], int velicina) {
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
int main() {
	//printf("Zadaća 1, Zadatak 3");
	int suma;
	char s[100];
	unesi(s,100);
	
	suma = haberbot(s);
	printf("SUma je %d",suma);
	return 0;
}
