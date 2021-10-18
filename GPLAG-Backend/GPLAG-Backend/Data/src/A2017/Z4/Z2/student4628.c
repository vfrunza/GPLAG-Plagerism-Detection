#include <stdio.h>
void unesi (char niz[], int velicina)
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


int provjeri_duzine (char *s, int *niz, int vel)
{
	int brojac=0, rijec=0;
	while (*s!='\0')
	{
		if ((*s>='A' && *s<='Z') || (*s>='a' && *s<='z'))
		{
			brojac++;
		}
		else if (brojac>0)
		{
			if (niz[rijec]!=brojac)
			{
				return 0;
			}
			rijec++;
			brojac=0;
		}
		s++;
	}
		 if (brojac>0)
	 {
	 	rijec=rijec+1;
	 }
	
	if (rijec!=vel)
	{
		return 0;
	}
return 1;
}


int main() 
{
	
int vel,i, niz[100];
char tekst[100];
printf ("unesite velicinu niza: ");
scanf ("%d", &vel);
printf ("Unesite niz: ");
for (i=0; i<vel; i++)
{
	scanf ("%d", &niz[i]);
}
printf ("Unesite neki tekst: ");
unesi (tekst,100);

printf ("Funkcija: %d", provjeri_duzine(tekst,niz,vel));
	
	
	
	return 0;
}
