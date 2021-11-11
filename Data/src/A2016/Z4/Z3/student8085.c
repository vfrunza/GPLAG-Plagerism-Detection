#include <stdio.h>

int duzina(char *p)
{
	int brojac=0;
	while(*p!='\0')
	{
		brojac++;
		p++;
	}
	
	return brojac;
}

char* zamjena_rijeci(char* tekst, char** rijeci, char** zamjene, int broj_rijeci)
{
	char *p1=tekst;
	char *p2;
	int i,iste,razlika,j,duzinaRijeci,brojac;
	char *pomocni1, *pomocni2;
	
	while(*p1!='\0')
	{
		while(*p1==' ')
		{
			p1++;
		}
		p2=p1;
		
		while( *p2!='\0' && *p2!=' ')
		{
			p2++;
		}
	
		for(i=0;i<broj_rijeci;i++)
		{
			if(duzina(rijeci[i])==(p2-p1))
			{
				iste=1;
				pomocni1=rijeci[i];
				pomocni2=p1;
				while(*pomocni1!='\0')
				{
					if(*pomocni1!=*pomocni2)
					{
						iste=0;
						break;
					}
					pomocni1++; pomocni2++;
				}
				
				if(iste)
				{
					razlika=duzina(rijeci[i])-duzina(zamjene[i]);
	
					if(razlika<0)
					{
						razlika*=-1;
						
						duzinaRijeci=duzina(tekst);
						
						for(j=duzinaRijeci;j>=p2-tekst;j--)
						{
							tekst[j+razlika]=tekst[j];
						}
						p2+=razlika;
						
					}else if(razlika>0)
					{
					
						duzinaRijeci=duzina(tekst);
						for(j=p2-tekst-razlika;j<=duzinaRijeci-razlika;j++)
						{
							tekst[j]=tekst[j+razlika];
						}
						p2-=razlika;
					}
					brojac=0;
					while(p1!=p2)
					{
						*p1=zamjene[i][brojac];
						p1++; brojac++;
					}
				}
				
			
			}
		}
		p1=p2;
	}
	return tekst;
}
int main() {
	char* rijeci[2] = { "beli", "sneg" };
	char* zamjene[2] = { "bijeli", "snijeg" };
	char tekst[100] = "beli sneg je pokrio beli breg";
	printf("%s", zamjena_rijeci(tekst, rijeci, zamjene, 2));
	/* Da li je promijenjen i polazni string? */
	printf("%s", tekst);
	return 0;
}
