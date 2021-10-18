#include <stdio.h>
void unesi(char niz[], int velicina) {
	char znak= getchar();
	if(znak== '\n') znak =getchar();
	int i=0;
	while(i<velicina-1 && znak!='\n') {
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}

int Prebroji(char* s, char znak) {
	int broj=0;
	while(*s!='\0') {
		if(*s==znak) {
			broj++;
			s++;
		}
	}
	return broj;
	
}
char* ubaci_broj(char* tekst, int broj) {
	
}



int main() {
	char a[80];
	unesi(a,80);
	printf("%s", ubaci_broj(a,80));
	return 0;
}
