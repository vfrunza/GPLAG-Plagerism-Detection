#include <stdio.h>
#include <ctype.h>

//Provjeravamo da li su rijeci iz "rijeci" i "teksta" iste//
int JesuIsti(char *p,char *temp)
{
	int	isti=1;

		while(*temp!='\0')
		{
			if(*temp++!=*p++){isti=0;break;}
			if(*temp=='\0' && (*p!=' ' && *p!='\0')){isti=0;break;}
		}
	return isti;
		
}
//Upisujemo rijezi iz "zamjene" u mjesto koje smo ostavili za zamjenu//
void ZamijeniRijeci(char *recenica,char *rijec)
{
	while(*rijec!='\0')
	{
		*recenica++=*rijec++;
	}
	recenica++;
}
//Vrsimo poredbu rijeci iz "rijeci" i "zamjena"//
int Rjecnik(char **rijeci,char **zamjene,int broj_rijeci)
{
	int i,isti=1;
	char *pom,*pom1;
	
		for(i=0;i<broj_rijeci;i++)
		{
			pom=rijeci[i];
			pom1=zamjene[i];
			while(*pom!='\0' || *pom1!='\0')
			{
				if(*pom++!=*pom1++)isti=0;
			}
			if (isti==0) break;
		}
		return isti;
}

//Algoritam za izbacivanje te ubacivanje u niz rijeci koje treba zamjeniti//
char* zamjena_rijeci(char* tekst, char** rijeci,char** zamjene, int broj_rijeci)
{
	char *p=tekst;
	char *temp,*pt,*kt,*ht;
	int i,br;
	     
	     
	    if(Rjecnik(rijeci,zamjene,broj_rijeci)) return tekst;
	     
		while(*p!='\0')
		{
			if(p==tekst || *(p-1)==' ')
			{
				while(*p==' ') p++;
				pt=p;
				
				for(i=0;i<broj_rijeci;i++)
				{	
					br=0;
					p=pt;
					temp=rijeci[i];
					
					if(JesuIsti(p,temp))
					{	
						kt=pt;
						
						while(*p!='\0' && *p!=' ') p++;
						
						
						while(*p!='\0')
						{
							*kt++=*p++;
						}						
						*kt='\0';
						
						p=pt;
						temp=zamjene[i];
						while(*temp!='\0')
						{
							br++;
							temp++;
						}
					
						ht=kt+br;
						p--;
						
						while(kt!=p)
						{
							*ht--=*kt--;
						}
						
						temp=zamjene[i];
						ZamijeniRijeci(pt,temp);			
					}
				}
			}
			p++;
				
		}
	return tekst;
}

//Testni main//
int main() {
	
	char* rijeci[3] = { "beli", "sneg","breg"};
	char* zamjene[3] = { "bijeli", "snijeg","brijeg"};
	char tekst[100] = "beli sneg je pokrio beli breg";
	printf("'%s'", zamjena_rijeci(tekst, rijeci, zamjene, 3));
	
	return 0;
}