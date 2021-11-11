#include <stdio.h>

/* Funkcija trazi rijec na koju pokazuje pokazivac s2 u stringu na koji pokazuje s1,
vraca adresu sljedeceg znaka iza rijeci koju je nasao, ili NULL ako ne nadje rijec */
char* trazi_rijec(char* s1, char* s2)
{
	char* p=s1;
	char* q=s2;
	int pocetak=1;
	while(*s1!='\0')
	{
		while(*s1==' ') 
		{
			s1++;
			pocetak=0;
		}
		p=s1;
		q=s2;
		while(*p==*q)
		{
			p++;
			q++;
			if(pocetak==1 && *q=='\0' && (*p==' ' || *p=='\0')) return p;
			if(pocetak==0 && *q=='\0' && (*p==' ' || *p=='\0') && *(s1-1)==' ') return p;
		}
		if(*s1!='\0') 
		{
			s1++;
			pocetak=0;
		}
	}
	return NULL;
}

int broji_slova(char* s1)
{
	int brojac=0;
	while(*s1!='\0')
	{
		brojac++;
		s1++;
	}
	return brojac;
}

/* Funkcija poredi_rij poredi dva niza znakova,
vraca 1 ako su isti, a vraca 0 ako su razliciti */
int poredi_rij(char* s1, char* s2)
{
	char *p=s1, *q=s2;
	while(*q!='\0')
	{
		if(*p!=*q) return 0;
		p++;
		q++;
	}
	if(*p=='\0') return 1;
	else return 0;
}

/* Funkcija ubaci_rijec ubacuje znakove na adresu na koju pokazuje
pokazivac s1 sa adrese na koju pokazuje pokazivac s2 */
void ubaci_rijec(char* s1, char* s2, int duzina)
{
	char *kraj=s1, *temp1=s1, *temp2=s2, *temp3=s1;
	while(*kraj!='\0') kraj++;
	temp3=kraj+duzina;
	
	while(kraj>s1)
	{
		*(kraj+duzina)=*kraj;
		kraj--;
	}
	while(*temp2!='\0')
	{
		*temp1=*temp2;
		temp1++;
		temp2++;
	}
	if(temp1<temp3) *temp1=' ';
	else *temp1='\0';
}

char* zamjena_rijeci(char* tekst, char** rijeci, char** zamjene, int broj_rijeci)
{
	char *poc_tekst=tekst, *adr_rij=tekst, *temp_pok=tekst;
	int i=0, praz_zam=1, praz_rij=0, br_slova=0;
	
	if(broj_rijeci<1) return poc_tekst;
	for(i=0; i<broj_rijeci; i++)
	{
		if(zamjene[i]!='\0') praz_zam=0;
		if(rijeci[i]!='\0') praz_rij=0;
	}
	if(*tekst=='\0' || (praz_zam==1 && praz_rij==1)) return poc_tekst;
	for(i=0; i<broj_rijeci; i++)
	{
		if(poredi_rij(rijeci[i], zamjene[i])) continue;
		do
		{
			adr_rij=trazi_rijec(tekst, rijeci[i]);
			if(adr_rij!=NULL)
			{
				br_slova=broji_slova(rijeci[i]);
				if(br_slova>0)
				{
					/* Izbacivanje rijeci */
					temp_pok=adr_rij-br_slova;
					while(*adr_rij!='\0')
					{
						*(adr_rij-br_slova)=*adr_rij;
						adr_rij++;
					}
					*(adr_rij-br_slova)=*adr_rij;
					br_slova=0;
				}
				adr_rij=temp_pok;
				br_slova=broji_slova(zamjene[i]);
				if(br_slova>0)
				{
					ubaci_rijec(adr_rij, zamjene[i], br_slova);
					br_slova=0;
				}
				tekst=adr_rij;
			}
		} while(adr_rij!=NULL);
		
		if(i==broj_rijeci) *tekst='\0';
		else tekst=poc_tekst;
	}
	if(praz_zam==1 && praz_rij==0) *tekst='\0';
	
	return poc_tekst;
}

int main() 
{
	char* rijeci[2]={"beli", "sneg"};
	char* zamjene[2]={"bijeli", "snijeg"};
	char tekst[100]="beli sneg je pokrio beli breg";
	
	printf("%s", zamjena_rijeci(tekst, rijeci, zamjene, 2));
	return 0;
}
