#include <stdio.h>

int main() {
	int H=0, P=0, C=0;
	float restoran=0, fastfood=0, bistro=0;
	char jelo, beze;
	printf("Unesite jelo za Tarika: ");
	scanf("%c",&jelo);
	scanf("%c", &beze);
	if (jelo=='H')
		H++;
	else if (jelo=='P')
		P++;
	else
		C++;
	printf("Unesite jelo za Bojana: ");
	scanf("%c",&jelo);
	scanf("%c", &beze);
	if(jelo=='H')
		H++;
	else if(jelo=='P')
		P++;
	else
		C++;
	printf("Unesite jelo za Mirzu: ");
	scanf("%c",&jelo);
	
	if(jelo=='H')
		H++;
	else if(jelo=='P')
		P++;
	else
		C++;
	restoran=3.30*H+6.80*P+5.00*C;
	fastfood=3.00*H+8.00*P+3.90*C;
	bistro=5.00*H+5.30*P+6.00*C;
	if (restoran < fastfood && restoran < bistro)
	{
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", restoran);
		return 0;
	}
	else if (fastfood < restoran && fastfood < bistro)
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", fastfood);
	else 
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",bistro);
	if (restoran>fastfood || restoran>bistro){
		if (P>=1) 
			restoran-=P*0.68;
		else if (C>=1)
			restoran-=C*0.5;
		else
			restoran-=H*0.33;
	}
	if (restoran < fastfood && restoran < bistro)
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", restoran);
		
	return 0;
}
