#include <stdio.h>

int uporedi(const char* s1, const char* s2, int velicina){
	int  i = 0;
	for (i = 0; i < velicina; i++)
		if(s1[i] != s2[i]) break;
	if (i == velicina) return 1;
	return 0;
}

int duzina(char* s){
		int duz = 0;
		while (*s++) duz++;
		return duz;
}

int provjeri(char* s){
	char niz1[100] = ".";
	int i=0, j, velicina = duzina(s);
	int br_otvorenih=0;
	int brojac = 0, duz_rijeci = 0;
	
	/* prebrojava tagove i zapisuje njihove znakove u novi niz */
	for(i=1; i<velicina-1; i++){
		if (s[i-1] == '<'){
			duz_rijeci = 0;
			while ((s[i] > 'A' && s[i] < 'Z') && (s[i] >= 'a' && s[i] <='z')){
				i++;
				duz_rijeci ++; 
			}
			if((s[i] == '>' || s[i]==' ') && duz_rijeci != 0){
				brojac = br_otvorenih;
				br_otvorenih += duz_rijeci;
				i = i - duz_rijeci;
				for(j=0; j<duz_rijeci; j++){
					niz1[brojac] = s[i]; 
					brojac++;
					i++;
				}
				niz1[br_otvorenih] = '.';
				niz1[br_otvorenih]
			}
		}
			
	}
	/*
	for(i=1; i<velicina-1; i++){
		if (s[i-1] == '<' && s[i+1] == '>'){
			duz_rijeci = 0;
			while ((s[i] > 'A' && s[i] < 'Z') && (s[i] >= 'a' && s[i] <='z')){
				duz_rijeci ++;
			}
			if (duz_rijeci != 0){
				niz[brojac] = s[i]; 
				brojac++;
				br_otvorenih++;
			}
		}
			
	}
	
	for(i=0; i<br_otvorenih+br_zatvorenih);
	*/
	printf("%s", niz1);
	return 0;
	
	
}

int main() {
	char tekst[] = "<a> <href dsa> <div> <<ff>";
	printf("%d", provjeri(tekst));
	return 0;
}
