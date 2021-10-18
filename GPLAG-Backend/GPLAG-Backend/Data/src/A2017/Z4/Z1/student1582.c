#include <stdio.h>

char* ubaci_broj (char * tekst, int broj)
{
int i=0;
int y;
y=sizeof(tekst)/sizeof(tekst[0]);

    for (i=1; i<=y; i++)
    {
        if (tekst[i-1]!=' ' && tekst[i]==' ')
        {
            tekst[i+1]=broj;
            y++;
        }
    i++;
    }
return tekst;
}


void unesi(char niz [], int velicina) {
	int i=0;
	char znak=getchar();
	if (znak=='\n') znak=getchar();
	while (i<velicina - 1 && znak!='\n') {
		niz[i]=znak;
		i++;
		znak=getchar();
	}
niz[i]='\0';
}


int main ()
{
    int broj;
    char tekst[100];
    scanf ("%d", &broj);
    unesi (tekst, 100);
    ubaci_broj(tekst, broj);
    printf ("%s", &tekst);
    
return 0;
}