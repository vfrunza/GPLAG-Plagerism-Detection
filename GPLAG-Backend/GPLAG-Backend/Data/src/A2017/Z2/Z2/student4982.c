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

int provjeri_duzine(char *s, int *cifre, int velicina)
{
	int razmak = 0;
	int duzina = 0;
	while (*s != '0') {
		if(!(*s >= 'A' && *s <= 'Z' || *s >= 'a' && *s <= 'z')) {
			razmak = 1;
			
			if(duzina != cifre) {
				return 0;
			}
			cifre++;
			duzina = 0;
		} else if (razmak == 0) {
			duzina ++;
		}
		s++;
	}
	return 1;
}
	

int main()
{
	char text[100];
	int cifre[100];
	int vel,i;
	printf("Unesite recenicu: \n");
	unesi(text,100);
	printf("Unesite velicinu niza cifara: ");
	scanf("%d", &vel);
	printf("Unesite niz cifara: \n");
	for(i=0; i<vel; i++) {
		scanf("%d", &cifre[i]);
	}
	printf("%d", provjeri_duzine(text,cifre,vel));

	return 0;
}
