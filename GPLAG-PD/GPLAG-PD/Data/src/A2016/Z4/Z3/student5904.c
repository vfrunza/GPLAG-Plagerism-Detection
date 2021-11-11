#include <stdio.h>

int je_li_ista_rijec(char *s1, char *s2) {
	char *p=s1;
	char *q=s2;
	
	while (*p == *q) {
		
		if ((*p == ' ' || *p == '\0') && (*q == ' ' || *q == '\0'))
			return 1;
		p++;
		q++;
	}
	if ((*p == ' ' || *p == '\0') && (*q == ' ' || *q == '\0'))
			return 1;
	
	return 0;
}

void izbaci_jednu_rijec(char* s) {
	char *brisac=s;

	while(*s != ' ' && *s != '\0')
		s++;
		
	while (*s != '\0') {
		*brisac++=*s++;
	}
	*brisac='\0';
}

void ubaci_string(char *s, char *rijec){
	char *pom = rijec;
	int duzina = 0, i;
	
	while(*pom != '\0'){
		duzina++;
		pom++;
	}
	
	pom = s;
	while(*pom != '\0')
		pom++;
	
	while(pom != s){
		
		*(pom + duzina) = *pom;
		pom--;
	}
	*(pom + duzina) = *pom;
	
	for(i = 0; i < duzina; i++){
		*(s+i) = *(rijec + i);
	}
}

char* zamjena_rijeci(char* s, char** rijeci, char** zamjene, int broj_rijeci){
	char *reset = s;
	int i;
	
	while(*s != '\0'){
		while(*s == ' ') 
			s++;
		
		
		for(i = 0; i < broj_rijeci; i++){
			if(je_li_ista_rijec(s, rijeci[i])){
				izbaci_jednu_rijec(s);
				ubaci_string(s, zamjene[i]);
				
				break;
			}
		}	
		
		while(*s != ' ' && *s != '\0')
			s++;
	}
	
	return reset;
}

int main(){
	
	char s[]="test ovo testni je neki testni string test";
	char *rijeci[2]= {"test", "testni"};
	char *zamjena[2]= {"testni", "test"};
	
	zamjena_rijeci(s, rijeci, zamjena, 2);
	
	printf("%s", s);
	
	return 0;
}
