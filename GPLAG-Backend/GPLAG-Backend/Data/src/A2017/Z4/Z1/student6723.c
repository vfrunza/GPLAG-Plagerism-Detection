#include <stdio.h>

char* ubaci_broj(char* tekst, int broj) {
	char* first = tekst, previous = *tekst, tempp, tempn, space = ' ';
	int i,j,sizeBroj = 0, position = 1, txtSize = 0, need, count, 
	number = broj, minus = 0;
	
	if(number<0) {
		number*=-1;
		minus = 1;
	}
	
	//Size: broj
	while(number>0) {
		number/=10;
		sizeBroj++;
	}
	
	//Size: text
	while(*tekst != '\0') {
		txtSize++;
		tekst++;
	} 
	
	tekst = first;
	need = sizeBroj+1;
	number = broj;
	tekst++;
	
	//Input
	while(*tekst!='\0') {
		if(*tekst == ' ' && previous != ' ') {
			for(i=0; i<sizeBroj; i++) {
				tekst++;
				tempp = *tekst;
				need--;
				
				//Input: broj
				if(minus) {
					*tekst = 13;
					minus = 0;
				} else {
					number = broj;
					for(count = 1; count < need; count++) {
						number/=10;
					}
					//printf("%d ", number%10);
							*tekst = 48 + number%10;
							count=0;
				}
				txtSize++;
				position++;
				count = 0;
				
				//Input: ostalo
				while(count<txtSize-position) {
					tekst++;
					tempn = *tekst;
					if(!count) {
						tekst = space;
						tekst++;
					}
				   *tekst = tempp;
					tekst++;
					tempp = *tekst;
					*tekst = tempn;
					count+=2;
				}
					tekst = first;
		tekst += position;
		previous = *tekst;
		tekst++;
		position++;
			}
		}
		need=sizeBroj+1;
		tekst = first;
		tekst += position;
		previous = *tekst;
		tekst++;
		position++;
	}
	return first;
}

int main() {
	char s[44] = "Ovo je neki primjer teksta";
	printf("\"%s\"", ubaci_broj(s, 123));
	return 0;
}
