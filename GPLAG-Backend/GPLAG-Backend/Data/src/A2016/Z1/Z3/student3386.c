#include <stdio.h>

int main() {
	char c;
	int crna,bijela,siva,crvena,plava,nema,x;
	float posto;
	printf("Unesite vozila: ");
	c='a';
	crna=0;
	bijela=0;
	siva=0;
	crvena=0;
	plava=0;
	x=0;
	posto=0;
	nema=0;
		while(c!='k' && c!='K')
		{
			scanf("%c",&c);
			if(c!='c' && c!='C' && c!='b' && c!='B' && c!='s' && c!='S' && c!='v' && c!='V' && c!='p' && c!='P' && c!='k' && c!='K')
			{	
				printf("Neispravan unos\n");
				nema=nema+1;
				
			}
			else if(c=='\n'){}
	
			else if(c=='c'|| c=='C')
			{
				crna=crna+1;;
				x++;	
			}
			else if(c=='b' || c=='B' )
			{	bijela=bijela+1;
				x++;
			}
			else if(c=='s' || c=='S')
			{	siva=siva+1;
				x++;
			}
			else if(c=='v' || c=='V')
			{	crvena=crvena+1;
				x++;
			}
			else if(c=='p' || c=='P')
			{	plava=plava+1;
				x++;
		
			}
			
		}
	if(x==0)
	{
		
		printf("Ukupno evidentirano %d vozila.\n",x);
		printf("Najpopularnija boja je crna (0.00%%).");
	}
	else
	{
	printf("Ukupno evidentirano %d vozila.\n",x);
	if(crna>=bijela && crna>=siva && crna>=crvena && crna>=plava )
	{	
		posto=((float)crna)/x*100;
	
		printf("Najpopularnija boja je crna (%.2f%%).",posto);
	}
	
	else if(bijela>=crna && bijela>=siva && bijela>=crvena && bijela>=plava )
	{	posto=((float)bijela)/x*100;
	
		printf("Najpopularnija boja je bijela (%.2f%%).",posto);
	}
	
	else if(siva>=crna && siva>=bijela && siva>=crvena && siva>=plava )
	{	posto=((float)siva)/x*100;
	
		printf("Najpopularnija boja je siva (%.2f%%).",posto);
	}
	
	else if(crvena>=crna && crvena>=bijela && crvena>=siva && crvena>=plava )
	{	posto=((float)crvena)/x*100;
	
		printf("Najpopularnija boja je crvena (%.2f%%).",posto);
	}
	
	else if(plava>=crna && plava>=bijela && plava>=siva && plava>=crvena )
	{	posto=((float)plava)/x*100;
	
		printf("Najpopularnija boja je plava (%.2f%%).",posto);
	}
	
	
	}
	
		
	
	
	return 0;
}
