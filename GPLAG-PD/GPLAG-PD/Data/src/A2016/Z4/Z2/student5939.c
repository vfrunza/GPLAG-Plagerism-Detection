#include <stdio.h>

void unesi(char niz[], int velicina) {
	char znak = getchar();
	
	if (znak == '\n') {
		znak = getchar();
		
	}
	
	int i = 0;
	while(i<velicina - 1 && znak != '\n') {
		niz[i] = znak;
		i++;
		znak = getchar();
		
	} 
	
	niz[i] = '\0';
	
}


int izbroji(char* ptr, char znak) {
	int br = 0;
	
	while(*ptr != '\0') {
		if (*ptr == znak) {
			br++;
			
		}
		ptr++;
	}
	
	return br;
}


char *kdr (char* txt, char* kod) {
	int i,j;
	char temp;
	
	for(i=0; i<96; i++) {
		*(kod + i) = 32+i;
		
	}
	
	*(kod+i-1) = '\0';
	
	for(i=0; i<95; i++) {
		for (j=i; j<i; j++) {
			if (izbroji(txt, *(kod+j)) > izbroji(txt, *(kod+i))) {
				temp = *(kod+i);
				*(kod + i)=*(kod+j);
				*(kod + j)= temp;
				
			}
			else if (izbroji(txt, *(kod + j))==izbroji(txt,*(kod+i))) {
				if (*(kod+j) < *(kod+i)) {
					temp = *(kod+i);
					*(kod+i)=*(kod+j);
					*(kod+j)=temp;
					
				}
				
			}
		}
	}
	char* ptr= txt;
	
	while(*ptr != '\0') {
		int poz = 0;
		char *b = kod;
		
		while(*b != *ptr) {
			b++;
			poz++;
		}
		
		*ptr = 126 - poz;
		ptr++;
		
	}
	
	return txt;
}


char* dekdr(char* txt, char* kod) {
	char* b = txt;
	char* c;
	
	while(*b != '\0') {
		int poz = 0;
		c = kod;
		
		while (*c != '\0') {
			if (*b == 126-poz) {
				*b = *c;
				break;
			}
			
			c++;
			poz++;
			
		}
		
		b++;
	}
	return txt;
}

int main() {
	char txt[200];
	char kod[100];
	unesi(txt, 200);
	printf("%s\n", txt);
	kdr(txt,kod);
	printf("%s\n%s", kod, txt);
	dekdr(txt, kod);
	printf("\n%s",txt);
	return 0;
}
