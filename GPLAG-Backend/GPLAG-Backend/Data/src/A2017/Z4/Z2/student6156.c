#include <stdio.h>

int provjeri_duzine(char* s,int* niz,int velicina);
int rijec(char slovo)
{
	if( (slovo>='a' && slovo<='z') || ( slovo>='A' && slovo<='Z') )return 1;
	return 0;
}

int main()
{
	char tekst[]="Ovo je neki primjer teksta";
	int niz[]= {3,2,4,7,6};
	printf("\n%d",provjeri_duzine(tekst,niz,5));
	return 0;
}


int provjeri_duzine(char* recenica,int* niz,int velicina)
{
	int i,brojac=0;
	int neslovo=1;
	char* s=recenica;

	while(*s!='\0')
	{
		if(!(rijec(*s))&& *s!='\0')
		{
			neslovo=1;
		}
		else if(rijec(*s)&& *s!='\0'&& neslovo==1)
		{
			//pocetak rijeci
			neslovo=0;
			for(i=0; i<niz[brojac]; i++)
			{
				if(!(rijec(*s)))return 0;
				s++;
			}
			if((rijec(*s)))return 0;
			brojac++;
			s--;
		}
		s++;
	}
	if(brojac==velicina)return 1;
	else return 0;
	return 0;
}