#include <stdio.h>
char* izbaci_najcescu(char* s) {
	char pok[20][20];
	char*p=s;
	int i,j;
	for(i=0; i<20; i++) {
		for(j=0; j<20; j++) {
			if ((*s>='A' && *s<='Z')||(*s-32>='A' && *s-32<='Z')) {
				pok[i][j]=*s;
				s++;
			}
			else break;
		}
		while(!((*s>='A' && *s<='Z')||(*s-32>='A' && *s-32<='Z'))) {
			if(*s=='\0') return p;
			s++;
		}
	}
	
	return p;	
}

int main() {

	return 0;
}
