#include <stdio.h>

int main() {
	
	char tarik,mirza,bojan,nr;
	double ResP=6.8,ResH=3.3,ResC=5,FastP=8,FastH=3,FastC=3.9,BisP=5.3,BisH=5,BisC=6;
	double CijenaR=0,CijenaFast=0,CijenaBis=0;
	double BrojP=0,BrojH=0,BrojC=0;
	
	printf("Unesite jelo za Tarika: ");
	scanf("%c",&tarik);
	scanf("%c",&nr);
	printf("Unesite jelo za Bojana: ");
	scanf("%c",&bojan);
	scanf("%c",&nr);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c",&mirza);
	scanf("%c",&nr);
	
	if(tarik=='P')BrojP++;
	else if(tarik=='H')BrojH++;
	else if(tarik=='C')BrojC++;
	if(bojan=='P')BrojP++;
	else if(bojan=='H')BrojH++;
	else if(bojan=='C')BrojC++;
	if(mirza=='P')BrojP++;
	else if(mirza=='H')BrojH++;
	else if(mirza=='C')BrojC++;
	CijenaR=BrojC*ResC+BrojP*ResP+BrojH*ResH;
	CijenaFast=BrojH*FastH+BrojP*FastP+BrojC*FastC;
	CijenaBis=BrojC*BisC+BrojH*BisH+BrojP*BisP;
	
	if(CijenaR<CijenaBis && CijenaR<CijenaFast)printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",CijenaR);

	else
	{
		if(CijenaFast<CijenaR && CijenaFast<CijenaBis)printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",CijenaFast);
		else printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",CijenaBis);
		if(BrojH>BrojP && BrojH>BrojC) ResH*=0.9;
		else if(BrojC>BrojP && BrojC>BrojH) ResC*=0.9;
		else ResP*=0.9;
		CijenaR=BrojH*ResH + BrojP*ResP + BrojC*ResC;
		if(CijenaR<CijenaBis && CijenaR<CijenaFast) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",CijenaR);
	}
	
	return 0;
}
