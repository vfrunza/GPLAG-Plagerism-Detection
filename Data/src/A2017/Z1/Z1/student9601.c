#include <stdio.h>
#define RP 6.80
#define RH 3.30
#define RC 5.00
#define FFP 8.00
#define FFH 3.00
#define FFC 3.90
#define BP 5.30
#define BH 5.00
#define BC 6.00
int main() {
	char tarik,bojan,mirza,novi_red;
	int brP=0,brH=0,brC=0;
	double CR,CFF,CB,SRH=RH,SRP=RP,SRC=RC;
	printf("Unesite jelo za Tarika: ");
	scanf("%c",&tarik);
	scanf("%c",&novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c",&bojan);
	scanf("%c",&novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c",&mirza);
	scanf("%c",&novi_red);
	if(tarik=='P') brP++;
	else if(tarik=='H') brH++;
	else if(tarik=='C') brC++;
	if(bojan=='P') brP++;
	else if(bojan=='H') brH++;
	else if(bojan=='C') brC++;
	if(mirza=='P') brP++;
	else if(mirza=='H') brH++;
	else if(mirza=='C') brC++;
	CR=brP*RP+brC*RC+brH*RH;
	CFF=brP*FFP+brH*FFH+brC*FFC;
	CB=brC*BC+brH*BH+brP*BP;
	if(CR<CFF && CR<CB) printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",CR);
	else 
	{
	 if(CFF<CB) printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",CFF);
	 else printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",CB);
	 if(brH>brC && brH>brP) SRH*=(1-0.1);
	 else if(brC>brP && brC>brH) SRC*=(1-0.1);
	 else SRP*=(1-0.1);
	 CR=brP*SRP+brC*SRC+brH*SRH;
	 if(CR<CFF && CR<CB) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",CR);
	}
	return 0;
}
