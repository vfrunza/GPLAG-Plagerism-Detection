#include <stdio.h>
char* zamjena_rijeci(char* tekst, char** rijeci, char** zamjene, int broj_rijeci)
{
	int i, br;
	char *pok, *p, *q, *pocetak, *temp;
	
	for(i=0; i<broj_rijeci; i++)
	{
		p=rijeci[i];
		q=zamjene[i];
		pok=tekst;
		while(*pok!='\0')
		{
			if(*pok==*p && (pok==tekst || *(pok-1)==' '))
			{
				pocetak=pok;
				temp=pok;
				
				while(*p++==*pok++ && *pok!='\0' && *p!='\0'){}
				
				
				if(*pok=='\0' && *p=='\0')
				{
					while(*q!='\0')
						*pocetak++=*q++;
					*pocetak='\0';
				}
				else if(*pok==' ')
				{
					 /*izbacivanje rijeci*/
					while(*pok!='\0')
						*pocetak++=*pok++;
					*pocetak='\0';
					/*ubacivanje zamjene*/
					br=0;
					while(*q!='\0')/*broj slova zamjene*/
					{
						br++;
						q++;
					}
					q=zamjene[i];
					while(pok!=temp)
					{
						*(pok+br)=*pok;
						pok--;
					}
					while(*q!='\0')
						*pok++=*q++;
					*pok=' ';
				}
				pok=temp;
			}
			p=rijeci[i];
			q=zamjene[i];
			pok++;
		}
	}
	pok=tekst;
	return tekst;
}

int main() {
	char* rijeci[2]={"dobro", "dobro"};
	char* zamjene[2]={"dobro", "dobro"};
	char tekst[100]="dobro dobro";
	printf("%s", zamjena_rijeci(tekst, rijeci, zamjene, 1));
	return 0;
}
