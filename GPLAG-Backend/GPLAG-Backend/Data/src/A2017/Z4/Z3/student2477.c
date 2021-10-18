#include <stdio.h>


void unesi(char niz[], int velicina)
{
	char znak = getchar();
	if (znak == '\n') znak=getchar();
	int i = 0;
	while (i < velicina-1 && znak != '\n') {
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	niz[i]='\0';
}

void najduzi_bp(char* s1, char* s2)
{
	char *p = *s1;
	char *q = *s2;
	int c;
	while(s1 != '\0') {
		if(s1 <= 'Z' && s1 >= 'A' || s1 <= 'z' && s1 >='a') {
			c++;
			
		}
		else if (c > max) max = c;	
	}
}

int main()
{
	char tekst1[100], tekst2[100];
	printf("Unesite tekst: ");
	unesi(tekst1, 100);
	return 0;
}
