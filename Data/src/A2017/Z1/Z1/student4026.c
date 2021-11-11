#include <stdio.h>
int main()
{
	double Rcijena=0,Fcijena=0,Bcijena=0,RP=6.8,RH=3.3,RC=5,FP=8,FH=3,FC=3.9,BP=5.3,BH=5,BC=6,BrHa=0,BrPi=0,BrCe=0;
	char Tarik,Bojan,Mirza;
	printf("Unesite jelo za Tarika: ");
	scanf("%c ",&Tarik);
	printf("Unesite jelo za Bojana: ");
	scanf("%c ",&Bojan);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c ",&Mirza);
	if(Tarik=='H') BrHa = BrHa + 1;
	else if (Tarik=='P') BrPi = BrPi + 1;
	else if (Tarik=='C') BrCe = BrCe + 1;
	if(Bojan=='H') BrHa = BrHa + 1;
	else if (Bojan=='P') BrPi = BrPi + 1;
	else if (Bojan=='C') BrCe = BrCe + 1;
	if(Mirza=='H') BrHa = BrHa + 1;
	else if (Mirza=='P') BrPi = BrPi + 1;
	else if (Mirza=='C') BrCe = BrCe + 1;
	Rcijena=RH*BrHa+RC*BrCe+RP*BrPi;
	Fcijena=FH*BrHa+FC*BrCe+FP*BrPi;
	Bcijena=BH*BrHa+BC*BrCe+BP*BrPi;
	if(Rcijena<Bcijena && Rcijena<Fcijena) printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",Rcijena);
	else 
	{
		if(Fcijena<Bcijena && Fcijena<Rcijena) printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",Fcijena);
		else printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",Bcijena);
		if(BrHa>BrPi && BrHa>BrCe) RH=RH*0.9;
		else if(BrCe>BrHa && BrCe>BrPi) RC=RC*0.9;
		else RP=RP*0.9;
		Rcijena=RH*BrHa+RC*BrCe+RP*BrPi;
	    if(Rcijena<Bcijena && Rcijena<Fcijena) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",Rcijena);
	}
	return 0;
}