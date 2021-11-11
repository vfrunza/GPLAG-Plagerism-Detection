#include <stdio.h>

void unesi(char *niz, int velicina)
{
	char znak=getchar();
	int i=0;
	if(znak=='\n') znak=getchar();
	while(i<velicina-1 && znak!='\n')
	{
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';}
	
	void Sortiraj(int niz[], int sort[], int ind[])
	{
		int i,j, pomocna;
		for(i=0;i<127;i++)
		{
			for(j=i;j<127;j++)
			{
				if(niz[i]<niz[j])
				{
					pomocna=niz[i];
					niz[i]=niz[j];
					niz[j]=pomocna;
					pomocna=ind[i];
					ind[i]=ind[j];
					ind[j]=pomocna;
					
					
				}
				else if(niz[i]==niz[j] && ind[i]>ind[j])
				{
					pomocna=ind[i];
					ind[i]=ind[j];
					ind[j]=pomocna;
				}
			}
		}
	}
	
	void Pretvaraj(char *s, char *codebook)
	{
		char *p=s; char *key=codebook;
		int broj;
		while(*p!='\0')
		{
			broj=0;
			key=codebook;
			while(*key!='\0')
			{
				if(*p==*key++)
				{
				*p=126-broj; break;
				
				}
				broj++;
			}
			p++;
		}
	}
	char *kodiraj(char *s, char *codebook)
	{
		char *p=s;
		char *q=codebook;
		int i;
		int niz[127], sort[127],ind[127];
		for(i=0;i<127;i++)
		{
			if(i<32)
			{
				niz[i]=-1;
				 ind[i]=-1;
			}
			else
		{
			niz[i]=0; ind[i]=i;
		} }
			while(*p!='\0')
			{
				niz[*p+0]++;
				p++;
			}
			for(i=0;i<127;i++)
			sort[i]=niz[i];
			Sortiraj(niz,sort,ind);
			
			for(i=0;i<127;i++)
			{
				if(ind[i]!=-1)
				{*q=ind[i];
				q++;
			}
		}
		Pretvaraj(s, codebook);
		return s;
	} 
	char *dekodiraj(char *s, char *codebook)
	{
		char *p=s;
		while(*s!='\0')
		{
			*s=codebook[126-*s];
		s++;
		
	}
	return p;}
int main() {
	char text[1000];
	char *pok=text;
	char *dekodirani=text;
	char code[96]; 
	printf("Unesite neki text: ");
	unesi(text,1000);
	
	pok=kodiraj(text, code);
	printf("Kodirani tekst glasi: %s", pok);
	dekodirani=dekodiraj(pok, code);
	printf("Dekodirani tekst glasi: %s", dekodirani);
	return 0;
}
