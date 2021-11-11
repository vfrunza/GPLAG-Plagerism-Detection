#include <stdio.h>
int main() {
	int UBV,C,S,B,V,P,M;
	float UDIO;
	char unos;
	C=0;
	B=0;
	S=0;
	V=0;
	P=0;
	M=0;
	printf ("Unesite vozila: ");
	do {
		scanf("%c", &unos);
		if (unos =='C' || unos =='c')
		{
			C++;
			if (C>M) 
			{ M=C;
		}
			
		} else if (unos =='B' || unos =='b')
		{
			B++;
			if(B>M)
			{M=B;
			}
			
		} else if (unos == 'S' || unos == 's')
		{
			S++;
			if(S>M)
			{M=S;
				
			}
		} else if(unos == 'V' || unos== 'v')
		{
			V++;
			if(V>M)
			{M=V;
			}
			
		} else if (unos == 'P' || unos == 'p')
		{
			P++;
			if(P>M)
			{M=P;
			}
			
		} else if (!(unos =='K'|| unos =='k'))
		{
			printf("Neispravan unos\n");
			
		}   
		
	} while (!(unos == 'K' || unos == 'k'));
	    UBV=(C+B+S+V+P);
	    UDIO=(M*100.)/UBV;
	    if (UBV==0)
	    {
	    	printf("\nUkupno evidentirano %d vozila.",UBV);
	    	printf("\nNajpopularnija boja je crna (0.00%%).",UDIO);
	    	return 0;
	    } else 
	    { 
		printf ("Ukupno evidentirano %d vozila.",UBV);
	    	
	    }
		if (M==C) 
		{
			printf("\nNajpopularnija boja je crna (%.2f%%). ",UDIO);
			return 0;
			
		} else if (M==S)
		{
			printf("\nNajpopularnija boja je siva (%.2f%%). ",UDIO);
			return 0;
			
		} else if (M==B)
		{ 
			printf("\nNajpopularnija boja je bijela (%.2f%%). ",UDIO);
			return 0;
			
		} else if (M==V)
		{
			printf("\nNajpopularnija boja je crvena (%.2f%%). ",UDIO);
			return 0;
			
		} else if (M==P)
		{ 
			printf("\nNajpopularnija boja je plava (%.2f%%). ",UDIO);
			return 0;
			
		}
}
