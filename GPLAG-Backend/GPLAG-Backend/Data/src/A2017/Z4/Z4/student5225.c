#include <stdio.h>
int provjeriHTML(char *s1, char *s2){
	
	while(*s1!= ' \0'){
		if(*s1== ' ' && *s1!='\0') s1++;
		char *s2=s1;
		if(*s2=='<') {
			if(*s2!= ' ' || *s2!= '\0')
			s2++;
		//	<ldldjjfjlf/>
			if(*s2=='>') break;
			
		}
			return 1;
	}
}
int main() {
	printf("Zadaća 4, Zadatak 4");
	return 0;
}
