#include <stdio.h>
#include <ctype.h>

int da_li_su_iste(char *p,char *pom)
{
	int	iste=1;

		while(*pom!='\0')
		{
			if(*pom++!=*p++) {
				iste=0;
				break;
			}
			if(*pom=='\0' && (*p!=' ' && *p!='\0')) {
				iste=0;
				break;
			}
		}
	return iste;
		
}

void zamjeni_rijeci(char *rec, char *rijec)
{
	while(*rijec!='\0')
	{
		*rec++=*rijec++;
	}
	rec++;
}

int provjera(char **rijeci,char **zamjene,int broj_rijeci)
{
	int i,iste=1;
	char *pom1,*pom2;
	
		for(i=0;i<broj_rijeci;i++)
		{
			pom1=rijeci[i];
			pom2=zamjene[i];
			while(*pom1!='\0' || *pom2!='\0')
			{
				if(*pom1++!=*pom2++)iste=0;
			}
			if (iste==0) break;
		}
		return iste;
}

char* zamjena_rijeci(char* tekst, char** rijeci,char** zamjene, int broj_rijeci)
{
	char *p=tekst;
	char *pom,*poc,*kraj,*sumica;
	int i,brojac;
	     
	     
	    if(provjera(rijeci,zamjene,broj_rijeci)) return tekst;
	     
		while(*p!='\0')
		{
			if(p==tekst || *(p-1)==' ')
			{
				while(*p==' ') p++;
				poc=p;
				
				for(i=0;i<broj_rijeci;i++)
				{	
					brojac=0;
					p=poc;
					pom=rijeci[i];
					
					if(da_li_su_iste(p,pom))
					{	
						kraj=poc;
						
						while(*p!='\0' && *p!=' ') p++;
						
						
						while(*p!='\0')
						{
							*kraj++=*p++;
						}						
						*kraj='\0';
						
						p=poc;
						pom=zamjene[i];
						while(*pom!='\0')
						{
							brojac++;
							pom++;
						}
					
						sumica=kraj+brojac;
						p--;
						
						while(kraj!=p)
						{
							*sumica--=*kraj--;
						}
						
						pom=zamjene[i];
						zamjeni_rijeci(poc,pom);			
					}
				}
			}
			p++;
				
		}
	return tekst;
}


int main() {
    char* rijeci[2] = { "beli", "sneg" };
	char* zamjene[2] = { "bijeli", "snijeg" };
	char tekst[100] = "beli sneg je pokrio beli breg";
	printf("%s", zamjena_rijeci(tekst, rijeci, zamjene, 2));
	return 0;
}




