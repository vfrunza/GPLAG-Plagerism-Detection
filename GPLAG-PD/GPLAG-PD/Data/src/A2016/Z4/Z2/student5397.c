#include <stdio.h>

void unesi (char niz[], int velicina)
{
	char znak=getchar();
	if (znak=='\n') znak=getchar();
	int i=0;
	while (i<velicina-1 && znak!='\n')
	{
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}

char* kodiraj (char *tekst, char *sifrarnik)
{
	int counts, max, c, cs, sif, lista;
	char *l;
	char *s;
	char *maxl;
	char *count;
	char *vrati;
	char *sifra;
	char kopi;
	kopi=127;
	max=0;
	sif=0;
	cs=1;
	c=0;
	lista=0;
	count=tekst;
	vrati=tekst;
	sifra=sifrarnik;
	while (*count!='\0')
	{
		c++;
		count++;
	}
	
	while (*tekst!='\0')
	{
		
		l=tekst;
		if (((*tekst>=65 && *tekst<=90) || (*tekst>=97 && *tekst<=122) || (*tekst==32)))
		{
			counts=0;
			l=tekst;
			s=tekst;
			while (*s>=32 && *s<=126)
			{
				if (*s==*l)
				{
					counts++;
				}
				s++;
			}
			if (counts>max)
			{
				max=counts;
				maxl=l;
				kopi=*l;
			}
			
			if (*(tekst+1)!='\0')
		    {
		    	sifrarnik=sifra;
			    *sifrarnik=(*sifrarnik)+kopi;
			    lista++;
			    sifra++;
			    
			   if (sifrarnik!='\0')
			   {
				while (cs<=c)
				{
				   sifrarnik++;
				   if (*sifrarnik!=kopi)
				   {	
					  *sifrarnik=32+sif;
					  sif++;
				      cs++;
				   }
				}
				*sifrarnik='\0';
		       }	
				tekst=maxl;
				l=tekst;
				s=tekst;
				while (*s>=32 && *s<=126)
			    {
				   if (*s==*l)
				   {
					   *s=126-lista-1;
				   }
				s++;
			    }
		     }
		     tekst++;
		}
		
		else
		{
			tekst++;
		}
	}
	return vrati;
}

int main() 
{
	char niz[100];
	char sifrarnik[100]="";
	printf("Napisi tekst: ");
	unesi (niz, 100);
	kodiraj (niz,sifrarnik);
	printf ("Kodiran tekst glasi: %s", sifrarnik);
	return 0;
}
