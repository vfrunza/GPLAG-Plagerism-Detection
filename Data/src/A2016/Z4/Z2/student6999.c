#include <stdio.h>

char *kodiraj(char *tekst, char *tablica){
	char *p, znk = ' ', ponavljanje[128], poredjenje[128];
	int sifrarnik[128]={0},max,brojac=-1,index,i,j;
	p=tekst;

	/*broj ponavljanja*/

while(*tekst != '\0'){
	i=0;
	while(znk != '~'){
		if(znk == *tekst) sifrarnik[i]++;
		i++;
		znk++;
	}
	znk=' ';
	tekst++;
}

	/* sredjivanje sifrarnika*/ 

for(i=0;i<96;i++){
	max = 0; /*nema negativnih vrijednosti*/
	index = -1;
	for(j=0;j<96;j++){
		if(sifrarnik[j]>max){
			max=sifrarnik[j];
			index=j;
		}
	}
if(index != -1){
	brojac++;
	ponavljanje[brojac] = index+32;
	sifrarnik[index] = -1; /* efektivno se eliminise*/
		}
	}
brojac++;

for(i=0;i<96;i++){
	if(sifrarnik[i] == 0){
		ponavljanje[brojac] = i+32;
		brojac++;
	}
}
ponavljanje[brojac-1] = '\0';
	
	/* poredjenje */

znk='~';
for(i=0;i<brojac;i++){
	poredjenje[i]=znk--;
}
poredjenje[brojac]='\0';

tekst = p;
while(*tekst != '\0'){
	for(i=0;i<brojac;i++){
		if(*tekst == ponavljanje[i]) break;
	}
	*tekst = poredjenje[i];
	tekst++;
}
*tekst = '\0';

i=0;
while(i<brojac){
	*tablica = ponavljanje[i];
	tablica++;
	i++;
}

/* kraj tablice */

*tablica='\0';
return p;
}

char *dekodiraj(char *tekst, char *tablica){
	char *p = tekst;
	char znk,poredjenje[96]; 
	int i;
	
znk='~';
for(i=0;i<96;i++){
	poredjenje[i]=znk--;
}

while(*tekst != '\0'){
	for(i=0;i<96;i++){
		if(*tekst == poredjenje[i]) break;
	}
/*dekodiranje*/
	*tekst = *(tablica+i);
	tekst++;
}
return p;
}

int main() {
	return 0;
}