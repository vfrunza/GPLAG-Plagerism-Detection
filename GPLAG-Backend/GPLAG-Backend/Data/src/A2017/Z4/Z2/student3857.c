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

int provjeri_duzine(char *s,int niz,int vel)

{
int i,j=0,brojac=0;
	
	while (*s)
	{
		if(*s==' ' || *s=='\0') {
			if (*s=='\0')
			{
				if(vel>0)
					{
						brojac[j++]=vel;
						vel=0;
					}
					break;
			}
			brojac[j++]=vel;
			vel=0;
		}
		else {
			vel++;
		}
		*s++;
	}
	
	for (i=0;i<vel;i++) {
	
	
}






int main()
{
	char tekst[100];
	int niz[] = {3, 2, 4, 7, 6};
	vel=5;
	printf("Unesite tekst: ");
	unesi(tekst, 100);


	return 0;
}
