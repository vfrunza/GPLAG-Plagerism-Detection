#include <stdio.h>

char* zamjena_rijeci(char* tekst, char** rijeci, char** zamjene, int broj_rijeci)
{
	char *p=tekst, *q, *k;
	int ima, indeks, i, j, duz, duzz, rduz, ista, duzteksta=0, produz, putapomjereno=0;
	
	while(*p!='\0')
	{
		duzteksta++;
		p++;
	}
	p=tekst;
	
	while(*p!='\0')
	{
		// Trazenje rijeci koje treba mijenjati
		
		if((p==tekst || *(p-1)==' ') && *p!=' ')
		{
			ima=0;
			for(i=0;i<broj_rijeci;i++)
			{
				ista=1;
				j=0;
				rduz=0;
				q=p;
				while(*q!='\0' && *q!=' ' && rijeci[i][j]!='\0')
				{
					if(*q!=rijeci[i][j]) ista=0;
					q++;
					j++;
					rduz++;
				}
				if(rijeci[i][j]!='\0' || (rijeci[i][j]=='\0' && *q!='\0' && *q!=' ')) ista=0;
				if(ista)
				{
					indeks=i;
					ima=1;
					duz=rduz;
				}
			}
			
			if(ima)
			{
				// Mijenjanje rijeci sa rijeci sa odgovarajucim indeksom
				q=p;
				j=0;
				duzz=0;
				while(zamjene[indeks][j]!='\0')
				{
					duzz++;
					j++;
				}
				if(duzz>=duz)
				{
					//Pomjeranje teksta ako je rijec koju mijenjamo kraca od one sa kojom je mijenjamo
					
					for(i=duz;i<duzz;i++)
					{
						k=tekst + duzteksta + 1 + putapomjereno;
						putapomjereno++;
						while(k>q)
						{
							*k=*(k-1);
							k--;
						}
					}
					
				}
				else
				{
					//Pomjeranje teksta ako je rijec koju mijenjamo duza od one sa kojom je mijenjamo
					
					for(i=duzz;i<duz;i++)
					{
						k=q;
						putapomjereno--;
						while(k<tekst+duzteksta)
						{
							*k=*(k+1);
							k++;
						}
						duzteksta--;
					}
				}
				j=0;
				
				// Sama zamijena rijeci
				
				while(zamjene[indeks][j]!='\0')
				{
					*q=zamjene[indeks][j];
					q++;
					j++;
				}
			}
		}
		p++;
	}

	return tekst;
}

int main() {
	char* rijeci[2] = { "bijeli", "snijeg" };
	char* zamjene[2] = { "beli", "sneg" };
	char tekst[100] = "bijeli snijeg je pokrio bijeli breg";
	printf("%s", zamjena_rijeci(tekst, rijeci, zamjene, 2));
	return 0;
}
