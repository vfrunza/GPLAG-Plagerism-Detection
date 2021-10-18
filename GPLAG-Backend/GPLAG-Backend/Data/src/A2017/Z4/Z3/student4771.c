#include <stdio.h>

void najduzi_bp(char* s1, char* s2) {
	char najduza[100];
	char najduzaTmp[100];
	int trenutnaDuzina = 0;
	int trenutnaTmp = 0;
	int i = 0;
	int postoji = 0;
	int bioSpace = 0;
	char tmpChar1;
	char tmpChar2;

	for(i=0; i<100; i++) {
		najduza[i] = '\0';
		najduzaTmp[i] = '\0';
	}
	
	while(*s1 != '\0') {
		if((*s1 >= 'A' && *s1 <= 'Z') || (*s1 >= 'a' && *s1 <= 'z')) {
			bioSpace = 0;
		}
		else {
			bioSpace = 1;
		}

		postoji = 0;	
		
		for(i=0; i<trenutnaTmp; i++) {
			tmpChar1 = *s1;
			
			if(tmpChar1 >= 'A' && tmpChar1 <= 'Z')
				tmpChar1 += 32;
				
			tmpChar2 = najduzaTmp[i];
			
			if(tmpChar2 >= 'A' && tmpChar2 <= 'Z')
				tmpChar2 += 32;
			
			if(tmpChar1 == tmpChar2) {
				postoji = 1;
			}
		}

		
		if(postoji == 0 && bioSpace == 0) {
			najduzaTmp[trenutnaTmp++] = *s1;
		}
		
		if(postoji == 1 || bioSpace == 1){
			if(trenutnaTmp > trenutnaDuzina) {
				for(i=0; i<trenutnaTmp; i++)
					najduza[i] = najduzaTmp[i];
			
				trenutnaDuzina = trenutnaTmp;
			}
			
			for(i=0; i<100; i++)
				najduzaTmp[i] = '\0';
				
			trenutnaTmp = 0;
			
			postoji = 0;
			bioSpace = 0;
		}
		
		s1++;
	}
	
	if(trenutnaTmp > trenutnaDuzina) {
		for(i=0; i<trenutnaTmp; i++)
			najduza[i] = najduzaTmp[i];
	
		trenutnaDuzina = trenutnaTmp;
	}
	
	for(i=0; i<trenutnaDuzina; i++) {
		*s2 = najduza[i];
		s2++;
	}
	
	*s2 = '\0';
	
}

int main() {
        char niz[10];
        najduzi_bp ("abcde etankera cdefg", niz);
        printf ("Niz: '%s'", niz);
	return 0;
}
