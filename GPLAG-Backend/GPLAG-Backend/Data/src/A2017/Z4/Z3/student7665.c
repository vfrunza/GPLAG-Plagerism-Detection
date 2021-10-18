#include <stdio.h>

void najduzi_bp(char* s1, char* s2) {
	char* p1=s1;
	char* p2;
	char* p3;
	int brojac=0;
	
	while(p1!=' ') p1++;
	p3=p1;
	while(p1!='\0') {
		while((*p1>='A' && *p1<='Z') || (*p1>='a' && *p1<='z')) {
			brojac++;
		}
		p2=p1;
		while(p1!=p3) {
			
		}
	}
	
}

int main() {
	printf("Zadaća 4, Zadatak 3");
	return 0;
}
