#include <stdio.h>
#include <math.h>

/*Unesi metoda za testiranje*/
void unesi(char niz[], int velicina){
	int i=0;
	char znak = getchar();
	if (znak == '\n') znak=getchar();
	while (i < velicina - 1 && znak != '\n') {
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	niz[i]='\0';
}

char* kodiraj (char* s1, char* s2){
	char *reset1=s2;
	char *reset = s1, znak = ' ', najPonSlov[96], poredbeni[97];
	int tabZaSifre[96] = {0}, i=-1, max, j, index, brojac=-1;
	

	/*Broji koliko puta se ponavljaju odredjene rijeci*/
	while (*s1 != '\0') {
		i=0;
		while (znak != '~'){
		
			if (znak == *s1){
				tabZaSifre[i]++;
			}
			i++;
			znak++;
		}
		znak=' ';
		s1++;
	}
	

	/*Kod za glavni dio programa*/
	for (j=0; j<96; j++){
		max = 0;
		index = -1;
		for (i=0; i<96; i++){
			if (tabZaSifre[i]>max){
				max = tabZaSifre[i];
				
				index = i;
				/*Nalazi index najcesce ponovljenog slova*/
			}
		}
		if (index != -1)
		{
			brojac++;
			/*Dodaje slovo u niz. Index+32 jer ne pocinjemo od ASCII-0*/
			najPonSlov[brojac] = index+32;
			tabZaSifre[index] = -1;
		}
	}
	brojac++;
	
	for (i=0; i<96; i++) {
		if (tabZaSifre[i] == 0) {
			najPonSlov[brojac] = i+32;
			brojac++;
		}
	}
	
	najPonSlov[--brojac] = '\0';

	

	/*Kreranje poredbenog niza za komparaciju*/
	znak = '~';
	for (i = 0; i < brojac; i++){
		poredbeni[i] = znak;
		znak--;
	}
	poredbeni[i]='\0';

	s1 = reset;
	
	
	while (*s1 != '\0'){
		for (i=0; i<brojac; i++){
			if (*s1 == najPonSlov[i]){
				break;
			}
			
		}
		*s1 = poredbeni[i];
		s1++;
	}
	*s1 ='\0';
	
	
	
	i = 0;
	while (i < brojac){
		*s2 = najPonSlov[i];
		i++;
		s2++;
	}
	*s2 = '\0';
	
	s1 = reset;
	s2 = reset1;
	
	return reset;
}


char* dekodiraj (char* s1, char* s2) {
	char* reset1 = s2;
	char* reset = s1, znak, poredbeni[96]; 
	int i;
	
	/*Popunjava poredbeni niz koji ce kasnije biti koristen za dekodiranje*/
	znak = '~';
	for (i = 0; i < 96; i++){
		poredbeni[i] = znak;
		znak--;
	}
	
	/*Dekodiranje stringa*/
	while (*s1 != '\0'){
		for (i=0; i<96; i++){
			if (*s1 == poredbeni[i]){
				break;
			}
			
		}
	
		*s1 = *(s2+i);
		s1++;
	}
	
	return reset;
}


int main() {
	/*Sav kod ispod je napisan samo za testiranje programa*/
	char test[]="LLMLNLNMONM";
	char kod [100]="";
	
	printf("Unesite tekst za kodiranje: ");
	unesi(test,100);
	kodiraj(test, kod);
	printf("%s", test);
	printf("\n%s", kod);
	
	dekodiraj(test, kod);
	printf("\n%s", test);
	
	return 0;
}
