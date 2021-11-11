#include <stdio.h>

int main() {


	char c='m';
	int ukupno=0,crna=0,bijela=0,siva=0,crvena=0,plava=0,najvise=0;
	float procenat_plave,procenat_bijele,procenat_crvene,procenat_crne,procenat_sive;

	printf("Unesite vozila: ");
	while (c!='k' && c!='K') 
	{
		
		scanf("%c",&c);
		
		if (c!='c' && c!='C' && c!='B' && c!='b' && c!='v'&& c!='V' && c!='p' && c!='P' && c!='s' && c!='S' && c!='k' && c!='K')
		
			printf("Neispravan unos\n");
		
		 else if (c=='C' || c=='c')
		{
			crna++;
			ukupno++;
		}
		else if (c=='B' || c=='b')
		{
			bijela++;
			ukupno++;
		}
		else if (c=='S' || c=='s')
		{
			siva++;
			ukupno++;
		}
		else if (c=='V' || c=='v')
		{
			crvena++;
			ukupno++;
		}
		else if (c=='P' || c=='p')
		{
			plava++;
			ukupno++;
		}
		

	}
	if (crna>najvise)
	{
		najvise=crna;
	}
	else if (bijela>najvise)
	{
		najvise=bijela;
	}
	else if (siva>najvise)
	{
		najvise=siva;
	}
	else if(crvena>najvise)
	{
		najvise=crvena;
	}
	else if(plava>najvise)
	{
		najvise=plava;
	}
	if (ukupno==0)
	{
		printf("Ukupno evidentirano 0 vozila.\n");
		printf("Najpopularnija boja je crna (0.00%%).");
		return 0;
	}
	procenat_sive=((float)(siva*100))/ukupno;
	procenat_crne=((float)(crna*100))/ukupno;
	procenat_crvene=((float)(crvena*100))/ukupno;
	procenat_bijele=((float)(bijela*100))/ukupno;
	procenat_plave=((float)(plava*100))/ukupno;
	printf("Ukupno evidentirano %d vozila.\n",ukupno);
	printf("Najpopularnija boja je ");
	if (crna>=bijela && crna>=siva && crna>=crvena && crna>=plava)
	printf("crna (%.2f%%).",procenat_crne);
	else if (siva>crna && siva>=crvena && siva>=plava && siva>bijela)
	printf("siva (%.2f%%).",procenat_sive);
	else if (crvena>crna && crvena>bijela && crvena>siva && crvena>=plava)
	printf("crvena (%.2f%%).",procenat_crvene);
	else if (plava>crvena && plava>crna && plava>siva && plava>bijela)
	printf("plava (%.2f%%).",procenat_plave);
	else if (bijela>crna && bijela>=crvena && bijela>=plava && bijela>=siva)
	printf("bijela (%.2f%%).",procenat_bijele);
	
	return 0;
}
