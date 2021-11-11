#include <stdio.h>
#define crna c
#define bijela b
#define crvena v
#define siva s
#define plava p

int main() 
{
	char colour;
	float Postotak,Ukupno;
	int crna=0,bijela=0,siva=0,crvena=0,plava=0;
	int max;

	printf("Unesite vozila: ");
	
	do
	
	
	
	{
		scanf("%c",&colour);
		if(colour=='c'|| colour=='C' || colour=='b' || colour=='B' || colour == 's'|| colour=='S'|| colour=='v'|| colour=='V'|| colour=='p'|| colour=='P'||colour=='k'||colour=='K')
		{
			if(colour=='c' || colour=='C')
			{
				crna+=1;
			}
			else if(colour=='b' || colour=='B')
			{
				bijela+=1;
			}
			else if(colour=='s'||colour=='S')
			{
				siva+=1;
			}
			else if(colour=='v'|| colour=='V')
			{
				crvena+=1;
			}
			else if(colour=='p'||colour=='P')
			{
				plava+=1;
			}
			else if(colour =='k'|| colour =='K')
			{
				break;
			}
			
			
			
			
			
		}
		else if(colour!='c' || colour!='C' || colour!='b'||colour!='B' || colour!='s'|| colour!='S'|| colour!='v'|| colour!='V'||colour!='p'||colour!='P'||colour!='k'||colour!='K')
		{
			printf("Neispravan unos\n");
		}
	}
	while (colour!='k' || colour!='K');
	
	
		Ukupno=crna+bijela+siva+crvena+plava;
		
		printf("Ukupno evidentirano %g vozila.\n",Ukupno);
		
    	
	
		
		if(crna>=bijela && crna>=siva && crna>=crvena && crna>=plava)
		{
			max=crna;
		}
		if(bijela>=crna && bijela>=siva && bijela>=crvena && bijela>=plava)
		{
			max=bijela;
		}
		if(siva>=crna && siva>=bijela && siva>=crvena && siva>=plava)
		{
			max=siva;
		}
		if(crvena>=crna && crvena>=bijela && crvena>=siva && crvena>=plava)
		{
			max=crvena;
		}
		if(plava>=crna && plava>=bijela && plava>=siva && plava>=crvena)
		{
			max=plava;
		}
		
	
		if(Ukupno==0)
		{
			Postotak=0.0;
		}
		else
		{
			Postotak=(max*100)/Ukupno;
		}
	
		if (max==crna)
		{
			printf("Najpopularnija boja je crna (%.2f%%).\n",Postotak);
		}
		
		else if (max==bijela)
		{
			printf("Najpopularnija boja je bijela (%.2f%%).\n",Postotak);
		}
		else if (max==siva)
		{
			printf("Najpopularnija boja je siva (%.2f%%).\n",Postotak);
		}
		else if (max==crvena)
		{
			printf("Najpopularnija boja je crvena (%.2f%%).\n",Postotak);
		}
		else if (max==plava)
		{
			printf("Najpopularnija boja je plava (%.2f%%).\n",Postotak);
		}
		
	
	return 0;
	






}

