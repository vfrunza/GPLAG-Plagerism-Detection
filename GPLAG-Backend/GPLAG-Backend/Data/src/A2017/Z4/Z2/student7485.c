#include <stdio.h>

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

int Slovo (char c)
{
	if ((c>='a' && c<='z') || (c>='A' && c<='Z'))
		return 1;
	return 0;	
}

int provjeri_duzine(char *s, int niz[], int velicina)
{
	int neslovo=1, i, nova_rijec=0, duzina=0;
	char *p=s;
	
	/*brojanje rijeci*/
	while(*s!='\0')
	{
		if (!(Slovo(*s)))
			neslovo=1;
		else if (neslovo==1)
		{
			neslovo=0;
			nova_rijec++;
		}
		s++;
	}
	if (nova_rijec!=velicina)
		return 0;
	s=p;
	neslovo=1;
	i=0;
	while(*s!='\0')
	{
		if (!(Slovo(*s)))
			neslovo=1;
		else if(neslovo==1)	
		{
			neslovo=0;
			duzina=0;
			/*brojanje duzine rijeci*/
			while(Slovo(*s))
			{
				duzina++;
				s++;
			}
			if (duzina==niz[i])
			{
				i++;
				s--;
			}
			else 
				return 0;
		}
			s++;
	}
		return 1;
}

int main() {
	char recenica[100];
	int niz[100],vel,broj,i;
	
	printf("Unesite broj rijeci: ");
	scanf("%d",&vel);
	
	printf("Unesite niz: ");
	for(i=0; i<vel; i++)
	{
		scanf("%d",&broj);
		niz[i]=broj;
	}
	
	printf("Unesite recenicu: ");
	unesi(recenica,100);
	
	printf("%d ",provjeri_duzine(recenica,niz,vel));
	
	return 0;
}
