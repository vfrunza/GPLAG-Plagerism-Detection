#include <stdio.h>
#include <limits.h>

void unesi(char niz[], int velicina){
	char znak = getchar();
	int i = 0;
	if(znak == '\n') znak = getchar();
	while(i < velicina-1 && znak != '\n'){
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	niz[i] = '\0';
}

int _strlen(char *s){
	int len = 0;
	if(s[0] == '\0') return len;
	while(s[++len] != '\0');
	return len;
}

int _isdigit(char c){
	if('0' <= c && c <= '9') return 1;
	else return 0;
}

/* Pretpostavka da se tekst sastoji od znakov asci [32, 126] */
char* kodiraj(char *text, char *table){
	int len = _strlen(text);
	char count[256];
	char taken[256];
	char pos[256];
	int index = 1, current = 0;
	int i;
	for(i = 0; i < 256; i++){
		pos[i] = 0;
		count[i] = 0;
		taken[i] = 0;
	}
	
	for(i = 0; i < len; i++){
		count[text[i]]++;
	}
	
	while(index > -1){
		index = -1;
		int max = 0;
		for(i = 0; i < 256; i++){
			if(!taken[i] && count[i] > max){
				max = count[i];
				index = i;
			}
		}
		
		if(index > -1){
			table[current++] = index;
			taken[index] = 1;
		}
	}
	
	
	table[current] = '\0';
	
	for(i = 32; i < 127; i++)
		if(!taken[i]) table[current++] = i;
		
	table[current] = '\0';
	
	for(i = 0; i < current; i++)
		pos[table[i]] = i;
		
	for(i = 0; i < len; i++){
		text[i] = (char)(126 - pos[text[i]]);
	}
	
	
	return text;
}

char* dekodiraj(char *text, char *table){
	int textlen = _strlen(text), tablelen = _strlen(table);
	char pos[256];
	int i;
	for(i = 0; i < tablelen; i++) pos[table[i]] = i;
	for(i = 0; i < textlen; i++) text[i] = table[-text[i] + 126];
	
	return text;
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

	return 0;
}
