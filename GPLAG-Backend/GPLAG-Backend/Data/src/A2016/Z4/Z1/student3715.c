#include <stdio.h>

void unesi(char niz[], int velicina)
{
	int i = 0;
	char znak = getchar();
	if(znak == '\n') znak = getchar();
	
	while(i < velicina - 1 && znak != '\n')
	{
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	niz[i] = '\0';
}

char* izbaci_najcescu(char* s) 
{
	
	while(s*!='\0') {
		
	}
}

int main() {
	printf("Zadaća 4, Zadatak 1");
	return 0;
}
