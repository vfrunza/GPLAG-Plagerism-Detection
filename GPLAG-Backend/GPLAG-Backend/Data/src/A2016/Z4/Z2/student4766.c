#include <stdio.h>
#include <stdlib.h>

char *kodiraj(char *kodiraj, char *sifra);
char *dekodiraj(char *kodiraj, char *sifra);
void popuniSifru(char *kodiraj, char *sifra);
void swap(char a, char b, char *niz);
void izbaciIzNiza(char znak, char *niz);

void popuniSifru(char *kodiraj, char *sifra){
	char *startKod = kodiraj;
	char *startSifra = sifra;
	char *temp;
	char *max;
	int size = 1;// za \0
	int num = 0;
	int maxVal = 0;
	char *niz;
	char *startNiz;
	char *pokNiz;
	int i = 0,j;
	int min; 
	char trade;
	char location = ' ';
	while(*kodiraj++ != '\0'){
		size++;
	}
	kodiraj = startKod;
	//pravimo niz koji sigurno moze primiti sve znakove za sifru
	niz = (char*)malloc(size * sizeof(char));
	startNiz = niz;
	pokNiz = niz;
	while(*kodiraj != '\0'){
		niz[i++] = *kodiraj++;
	}
	niz[i] = '\0';
	kodiraj = startKod;
	
	for(i = 32; i <= 126; i++){
		*sifra++ = i;
	}
	*sifra = '\0';
	
	//popunjavamo niz po frekvenciji pojavljivanja
	while(*niz != '\0'){
		
	startNiz = niz;
	maxVal = 0;
		while(*startNiz != '\0'){
			
			temp = pokNiz;
			num = 0;
			while(*pokNiz != '\0'){
				
				if(*pokNiz == *startNiz){
					num++;
				}
				
				pokNiz++;
			}
			if(num >= maxVal){
				if(num > maxVal){
					maxVal = num;
					max = startNiz;
				}
				else if(num == maxVal && *startNiz < *max){
					max = startNiz;
				}
			}
			pokNiz = temp;
			
			startNiz++;
		}
		swap(location++, *max, startSifra);
		izbaciIzNiza(*max, niz);
	}	
	//selection sort
	for (i=location - ' '; i<95; i++) {
        min=i;
        for (j=i+1; j<95; j++) {
            if (startSifra[j] < startSifra[min])
                min = j;
        }
        trade = startSifra[i];
        startSifra[i] = startSifra[min];
        startSifra[min] = trade;
    }
    
	free(niz);
}

void izbaciIzNiza(char znak, char *niz){
	char *p = niz;
	char *temp;
	//funkcija izbacuje znak iz niza
	while(*p != '\0'){
		if(*p == znak){
			temp = p;
			while(*p != '\0'){
				*p = *(p+1);
				p++;
			}
			p = temp - 1;
		}
		p++;
	}
}
void swap(char a, char b, char *niz){
	char *p = niz;
	//funkcija mijenja mjesta dva chara u niz
	while(*p != '\0'){
		if(*p == a)
		*p = b;
		else if(*p == b)
		*p = a;
		p++;
	}	
	
}

char *kodiraj(char *kodiraj, char *sifra){
	char *ret = kodiraj;
	char *startSifra = sifra;
	int i = 0;
	//funkcija popunjava sifru za dati string
	popuniSifru(kodiraj, sifra);
	//kodiramo string kodiraj
	while(*kodiraj != '\0'){
		for(i = 0; i < 96; i++){
			if(*kodiraj == sifra[i]){
				*kodiraj = 126 - i;
				break;
			}
		}
		kodiraj++;
	}
	
	return ret;
}

char *dekodiraj(char *kodiraj, char *sifra){
	char *ret = kodiraj;
	int i = 0;
	//suprotno od kodiraj
	while(*kodiraj != '\0'){
		for(i = 0; i < 96; i++){
			if(*kodiraj == 126 - i){
				*kodiraj = sifra[i];
				break;
			}
		}
		kodiraj++;
	}
	
	return ret;
}

int main() {
	
	return 0;
}
