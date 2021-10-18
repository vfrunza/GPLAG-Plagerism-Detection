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
	char *temp=s2, *pocetak, *pok, *pok2, *pok3, *kraj;
	char mal, velk;
	int brojac=0, max=0;

//funkcija

	while (*s1!=0) {


		if((*s1<='z' && *s1>='a') || (*s1<='Z' && *s1>='A')) {
			pok=s1;
			pok2=s1;
			pok2++;
			pok3=s1;
			while ((*pok3<='z' && *pok3>='a') || (*pok3<='Z' && *pok3>='A'))
					pok3++;
					
			while (((*pok<='z' && *pok>='a') || (*pok<='Z' && *pok>='A')) && pok<pok3) {
			
				while (((*pok2<='z' && *pok2>='a') || (*pok2<='Z' && *pok2>='A')) && pok2<pok3) {
					mal=*pok;
					velk=*pok2;
					
					if (mal>='A' && mal<='Z') {
						mal=mal+32;
					}
					if (velk>='A' && velk<='Z') {
						velk=velk+32;
					}
					
					if (mal==velk) pok3=pok2;
					
					pok2++;

				}
				pok++;
				pok2=pok+1;
			}
			brojac=(pok3-s1);
				if (brojac>max) {
					s2=temp;
					max=brojac;
					pocetak=s1;
					kraj=pok3;
					while (pocetak<kraj)
						*s2++=*pocetak++;
					*s2='\0';
				}


		}
		s1++;
	}



//prebaci u drugi string
	

}
int main()
{
	char s[100], s1[100];
	printf("Zadaća 4, Zadatak 3");
	unesi(s,100);
	najduzi_bp(s,s1);
	printf("%s", s1);
	return 0;
}
