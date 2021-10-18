#include <stdio.h>
void unesi(char niz[], int velicina)
{
	char znak = getchar();
	int i;
	if(znak != '\n') znak = getchar();
	i = 0;
	while(i < velicina - 1 && znak != '\n') {
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	niz[i] = '\0';

}

void najduzi_bp(char* s1, char* s2){
	
	int duzina = 0;
	char *pomocni;
	while(*s1 != '\0'){
		
	}
	
}


int main() {
	printf("Zadaća 4, Zadatak 3");
	return 0;
}
