#include <stdio.h>
/*Funkcija za unos stringa*/
void unesi(char tekst1[], int velicina)
{
	char znak=getchar();
	if(znak=='\n') znak = getchar();
	int i=0;
	while(i<velicina-1 && znak!='\n') {
		tekst1[i]=znak;
		i++;
		znak=getchar();
	}
	tekst1[i]='\0';
}

int provjeri_duzine(char* s, int niz[], int vel)
{
	int  znakBrojac=0, i=0, brojRijeci=1, j=0;


	while(s[i]!='\0') {
		/*Uslov koji sluzi za brojanje rijeci*/
		if(!((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z'))) {
			brojRijeci++;
		}
		i++;
	}

	i=0;
	if (brojRijeci!=vel) return 0;
	else {
		do {
			/*Uslov za brojanje znakova*/
			if(!((s[j]>='A' && s[j]<='Z') || (s[j]>='a' && s[j]<='z'))) {
				if(s[j+1]=='\0')
					znakBrojac++;
				/*Uslov za provjeru jednakosti niza brojeva i broja slova  u stringu*/
				if(niz[i]==znakBrojac) {
					i++;
					znakBrojac=-1;
				} else return 0;

			}
			znakBrojac++;
			j++;

		} while(s[j]!='\0');
		return 1;
	}
}

int main()
{
	char tekst[1000];
	int vel, i, niz[1000];

	printf("Unesite recenicu: ");
	unesi(tekst, 1000);

	printf("Unesite velicinu niza: ");
	scanf("%d", &vel);
	printf("Unesite niz: ");
	for(i=0; i<vel; i++) {
		scanf("%d", &niz[i]);
	}

	printf("%d ", provjeri_duzine(tekst, niz, vel));
	return 0;
}
