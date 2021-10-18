#include <stdio.h>

void zamjeniChar(char* prvi, char* drugi){
	if(prvi == drugi) return;
	char tmp = *prvi;
	*prvi = *drugi;
	*drugi = tmp;
}
void zamjeniInt(int* prvi, int* drugi){
	if(prvi == drugi) return;
	
	
	int tmp = *prvi;
	*prvi = *drugi;
	*drugi = tmp;
}

char *kodiraj(char tekst[], char tablica[]) {
	int count = 0,i = 0,j = 0;
	int drugatablica[96];
	for(i = 0; i < 95; i ++){
		tablica[i] = 32 + i;
		drugatablica[i] = 0;
	}
	tablica[95] = '\0';
	i = 0;
	while(tekst[i] != '\0'){
		j = 0;
		while(tekst[i] != tablica[j]) j++;
		drugatablica[j]++;
		i++;
	}
	for(i = 0; i < 95; i++){
		int najveci = i;
		for(j = i+1; j < 95; j++){
			if(drugatablica[najveci] < drugatablica[j] || (drugatablica[najveci] == drugatablica[j] && tablica[j]< tablica[najveci]) ){
				najveci = j;
			}	
		}
		zamjeniChar(&tablica[najveci],&tablica[i]);
		zamjeniInt(&drugatablica[najveci],&drugatablica[i]);
	}
	
	i = 0;
	while(tekst[i] != '\0'){
		char kod = 126;
		int brojac = 0;
		while(tablica[brojac] != tekst[i]) {
			brojac++;
			kod--;
		}
		tekst[i] = kod;
		
		i++;
	}
	return tekst;
}

char * dekodiraj(char tekst[],char tablica[]){
	int i =0;
	while(tekst[i] != '\0'){
		char brojac = 126 - tekst[i];
		tekst[i] = tablica[brojac];
		
		
		i++;
	}
	return tekst;
}

int main() {
	
char tekst[] = "LLMLNLNMONM";
char sifrarnik[100] = "";
int i;
kodiraj(tekst, sifrarnik);
printf("%s", tekst);
for (i=0; i<10; i++) printf("%c", sifrarnik[i]);
dekodiraj(tekst, sifrarnik);
printf("%s", tekst);

	printf("Zadaća 4, Zadatak 2");
	return 0;
}
