#include <stdio.h>

char* ubaci_broj(char* tekst,int broj) {
	char* pocetak = tekst;
	char* kraj = tekst;
	char *pomocni = tekst;
	int duzina_broja=0,negativan=0;
	int temp = broj;
	if(temp<0) {
		temp*=-1;
		duzina_broja++;
	}
	do {
		duzina_broja++;
	 	temp/=10;
	}while(temp!=0);
	
	// Preskacem eventualne razmake do prve rijeci
	while(*tekst==' ') 
		tekst++;
	
	// Glavna petlja

	while(*tekst!='\0') {
		temp=broj;
		if(temp<0)
			temp*=-1;

		if(*tekst==' ') {
			// Ako je jedan "space" izmedju dvije rijeci onda ubaci jos jedan...
			if(*(tekst+1) != ' ') {
				kraj=tekst;
				while(*kraj!='\0')
					kraj++;
				while(kraj>tekst) {
					*(kraj+1) = *kraj;
					kraj--;
				}
				*(kraj+1) = ' ';
			} 
			// 
			
			// Ovo ce rjesiti razmake na kraju
			pomocni = tekst;
			while(*pomocni==' ')
				pomocni++;
			if(*pomocni=='\0')
				break;
			//
			
			// Ubaci broj izmedju svih riječi 
			kraj=tekst;
			pomocni=tekst;
			while(*kraj!='\0') {
				kraj++;
			}
			
			while(kraj>pomocni) {
				*(kraj+duzina_broja) = *kraj;
				kraj--;
			}
			kraj = kraj + duzina_broja;
			while(kraj>pomocni) {
				*kraj = temp%10 + '0';
				temp/=10;
				kraj--;
			} 
			// Ako je negativan dodaj minus ispred..
			if(broj<0)
				*(kraj+1)='-';
			// Treba pomaknuti "tekst" na iduci razmak poslije broja
			tekst+=duzina_broja+1;
			// Pomakni "tekst" do iduce rijeci
			while(*tekst==' ')
				tekst++;
		}
		else 
			tekst++;
	}
	return pocetak;
}
int main() {
	char test[100] = "Ovo je  neki primjer";
	printf("Ovo je  neki");
	printf("\n");
	ubaci_broj(test,-123);
	printf("%s",test);
	return 0;
}
