#include <stdio.h>


int provjeri_duzine(char* tekst, int* niz, int vel) {
	
	int testniz[100];
	int br, i = 0;
	
	
	while(*tekst != '\0') {
		br = 0;
		
		while(*tekst != '\0' && ((*tekst >= 'a' && *tekst <= 'z' || (*tekst >= 'A' && *tekst <= 'Z'))) ) {
			
		
			br++;
			tekst++;
			
		}
		
		/*if((*tekst >= 32 && *tekst <= 64)) {
			
			while(*tekst >= 32 && *tekst <= 64) tekst++;
			tekst--;
		}else continue;*/
		
		testniz[i] = br;
		i++;
		
		
		
		if(*tekst != '\0') tekst++;

		
	}
	
	if(i != vel) return 0;
	
	
	for(i = 0; i < vel; i++) {
		
		if(niz[i] != testniz[i]) return 0;
		
	}
	
	return 1;
	
	
}

int main() {
	
	/* AT6: Ne-slova na kraju stringa */
	char tekst[] = "Kakav je ovo test!?!?";
	int niz[] = {5,2,3,4};

	

	printf("%d ", provjeri_duzine(tekst, niz, 4));
	
	return 0;
}
