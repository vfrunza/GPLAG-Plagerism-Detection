#include <stdio.h>

int ispravnost_stringa(char *s){
	while (*s != '\0') {
		if(*s != '(')return 0;
		s++;
		if(*s == '-')s++;
		if(!(*s >= '0' && *s <= '9' ) )return 0;
		while (*s >= '0' && *s <= '9' ) s++;
		if(*s == '.'){
			s++;
			while (*s >= '0' && *s <= '9' ) s++;
		}
		if(*s != ',')return 0;
		s++;
		if(*s == '-')s++;
		if(!(*s >= '0' && *s <= '9' ) )return 0;
		while (*s >= '0' && *s <= '9' ) s++;
		if(*s == '.'){
			s++;
			while (*s >= '0' && *s <= '9' ) s++;
		}
		if(*s != ')')return 0;
		s++;
		if(*s == ',')s++;
		if(*s == '\0')return 0;
	}
}

char *obuhvat(char *s,double a,double b,double c,double d){
	char *pocetak = s;
	if(ispravnost_stringa(s) == 0)return NULL;
	return pocetak;
}

int main() {
	printf("Zadaća 4, Zadatak 4");
	return 0;
}
