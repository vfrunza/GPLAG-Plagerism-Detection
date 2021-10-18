#include <stdio.h>
#include <stdlib.h>

/*unos stringa*/
void unesi(char niz[], int velicina)
{
	int i;
	char znak=getchar();
	if (znak=='\n')
		znak=getchar();
	i=0;
	while(i<velicina-1 && znak!='\n')
	{
		niz[i]=znak;
		znak=getchar();
		i++;
	}
	niz[i]='\0';
}

int stepenuj(int broj)
{
	int i, vracaj=1;
	for(i=0; i<broj; i++)
		vracaj*=10;
	return vracaj;	
}

int Slovo(char c)
{
	if ((c>='a' && c<='z') || (c>='A' && c<='Z'))
		return 1;
	return 0;	
}

char* ubaci_broj(char *tekst, int broj)
{
	int cifre=0,duzina=0,temp,pozitivan=1,brojac=0,temp2,i,ostatak;
	char *s,*p,*q;
	s=tekst;
	if (broj<0)
		pozitivan=0;
	temp=abs(broj);
	while(temp!=0)
	{
		cifre++;
		duzina++;
		temp/=10;
	}
	if (pozitivan==0)
		duzina++;
	while(*s==' ')
		s++;
		
	while(*s!='\0')
	{
		if(*s!=' ')
		{
			while(*s!='\0' && *s!=' ')
				s++;
		}
		p=s;
		p++;
		if (*s==' ')
		{
			brojac=0;
			while(*s!='\0' && *s==' ')
			{
				s++;
				brojac++;
			}
			if (*s=='\0')
				return tekst;
			if (brojac==1)
				duzina++;
			q=s;
			while(*q!='\0')
				q++;
			while(q>=p)
			{
				*(q+duzina)=*q;
				q--;
			}
			if (broj<0)
			{
				*p='-';
				p++;
			}
			temp2=abs(broj);
			
			/*ubacivanje broja*/
			for(i=0; i<cifre; i++)
			{
				ostatak=temp2/stepenuj(cifre-1-i);
				*p=ostatak+'0';
				p++;
				temp2-=ostatak*stepenuj(cifre-1-i);
			}
			if (brojac==1)
			{
				*p=' ';
				duzina--;
			}	
			s=p;
			while(*s==' ')
				s++;
			s--;
		}
		if(*s!='\0')
			s++;
	}
	return tekst;
}

int main() {
	char recenica[100], *p;
	int broj;
	printf("Unesite broj: ");
	scanf("%d",&broj);
	printf("Unesite recenicu: ");
	unesi(recenica,100);
	p=ubaci_broj(recenica, broj);
	printf("%s",p);
	return 0;
}
