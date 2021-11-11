#include <stdio.h>

void sortiraj1(char *s, int *niz, int vel)
{
	int temp=0, i=0, j=0;
	char t=32;
	
	for(i=0; i<vel-1; i++)
		for(j=i+1; j<vel; j++)
			if(niz[i]<niz[j])
			{
				temp=niz[i];
				niz[i]=niz[j];
				niz[j]=temp;
				
				t=s[i];
				s[i]=s[j];
				s[j]=t;
			}
	for(i=0; i<vel-1; i++)
		for(j=i+1; j<vel; j++)
			if(niz[i]==niz[j])
				if(s[j]<s[i])
					{
						temp=niz[i];
						niz[i]=niz[j];
						niz[j]=temp;
				
						t=s[i];
						s[i]=s[j];
						s[j]=t;
					}
}

void sortiraj2(char *s, int *niz, int vel)
{
	int temp=0, i=0, j=0;
	char t=32;
	
	for(i=0; i<vel-1; i++)
		for(j=i+1; j<vel; j++)
			if(niz[i]<niz[j])
			{
				temp=niz[i];
				niz[i]=niz[j];
				niz[j]=temp;
				
				t=s[i];
				s[i]=s[j];
				s[j]=t;
			}
	for(i=0; i<vel-1; i++)
		for(j=i+1; j<vel; j++)
			if(niz[i]==niz[j])
				if(s[j]>s[i])
					{
						temp=niz[i];
						niz[i]=niz[j];
						niz[j]=temp;
				
						t=s[i];
						s[i]=s[j];
						s[j]=t;
					}
}

char* kodiraj(char *tekst, char* tablica)
{
	char *s=tekst, *t=tablica, *p;
	char slova[100]={' '}, znak=32;
	int brojevi[100]={0};
	int i=0, j=0, br=0, vel=0, da=0, pret=0;
	while(*s!='\0')
	{
		br=0;
		znak=*s;
		p=s;
		while(*p!='\0')
		{
			if(*p==znak)
				br++;
			p++;
		}
		da=1;
		for(i=0; i<vel; i++)
			if(znak==slova[i])
				da=0;
		if(da)
		{
			slova[vel]=znak;
			brojevi[vel]=br;
			vel++;
		}
		s++;
	}
	sortiraj1(slova, brojevi, vel);
	for(i=0; i<vel; i++)
	{
		*t=slova[i];
		t++;
	}
	for(i=32; i<127; i++)
	{
		pret=1;
		for(j=0; j<vel; j++)
			if(i==slova[j])
				pret=0;
		if(pret)
		{
			*t=i;
			t++;
			*t='\0';
		}
	}
	s=tekst;
	while(*s!='\0')
	{
		for(i=0; i<vel; i++)
			if(*s==slova[i])
			{
				*s=126-i;
				break;
			}
		s++;
	}
	return tekst;
}

char* dekodiraj(char *tekst, char *tablica)
{
	char *s=tekst, *t=tablica, *p;
	char slova[100]="", znak=32;
	int brojevi[100]={0};
	int i=0, br=0, vel=0, da=0;
	while(*s!='\0')
	{
		br=0;
		znak=*s;
		p=s;
		while(*p!='\0')
		{
			if(*p==znak)
				br++;
			p++;
		}
		da=1;
		for(i=0; i<vel; i++)
			if(znak==slova[i])
				da=0;
		if(da)
		{
			slova[vel]=znak;
			brojevi[vel]=br;
			vel++;
		}
		s++;
	}
	sortiraj2(slova, brojevi, vel);
	s=tekst;
	while(*s!='\0')
	{
		for(i=0; i<vel; i++)
			if(*s==slova[i])
			{
				*s=*(t+i);
				break;
			}
		s++;
	}
	return tekst;
}


int main() {
	char tekst[200]="LLMLNLNMONM", tablica[200]="";
	printf("%s\n%s", kodiraj(tekst, tablica), tablica);
	printf("\n%s", dekodiraj(tekst, tablica));
	return 0;
}