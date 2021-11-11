/* Zadatak: na osnovu broja ponavljanja znaka napisati funkciju koja ga kodira */
/* Zatim na osnovu sifrarnika tekst dekodirati u prvobitni */
#include <stdio.h>
char* kodiraj(char* tekst,char* kod){
	char* poc1;
	char* poc2;
	int max,broj,i=0;
	int ponavljanja[127];
	poc1=tekst;
	poc2=kod;
	while(i<127){
		ponavljanja[i]=0;
		i++;
	}
/* Broj ponavljanja svakog znaka stavlja se u niz, na mjesto odgovarajuceg ASCII koda */	
	while(*tekst!=0){
		broj=*tekst;
		ponavljanja[broj]++;
		tekst++;
	}
	max=ponavljanja[0];
	for(i=31;i<127;i++){
		if (ponavljanja[i]>max)
			max=ponavljanja[i];
	}
/* U sifrarnik se redom upisuju znakovi ciji je broj ponavljanja max,max-1,...do nule */	
	while(max>=0){
		for(i=32;i<127;i++){
			if(ponavljanja[i]==max){ 
				*kod=i;
				kod++;
			}
		}
		max--;
	}
/* Na osnovu sifrarnika kodiramo tekst	*/
	tekst=poc1;
	while(*tekst!=0){
		kod=poc2;
		broj=0;
		while(*tekst!=*kod){
			broj++;
			kod++;
		}
		*tekst=(126-broj);
		tekst++;
	}
	return poc1;
}
char*dekodiraj(char*tekst,char*kod){
	char*poc1;
	poc1=tekst;
	while (*tekst!=0){
		*tekst=*(kod+(126-*tekst));
		tekst++;
	}
	return poc1;
}
int main() {
	char*p;
	char a[]={"LLMLNLNMONM"};
	char b[130]="";
	p=kodiraj(a,b);
	printf("Zadaća 4, Zadatak 2");
	return 0;
}
