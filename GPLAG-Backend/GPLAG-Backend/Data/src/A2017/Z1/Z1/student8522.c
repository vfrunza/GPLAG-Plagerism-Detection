#include <stdio.h>

int main() {
	char jzt, jzm, jzb, nr;
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &jzt);
	scanf("%c", &nr);
	
	
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &jzb);
	scanf("%c", &nr);
	
	
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &jzm);
	scanf("%c", &nr);
	
	float pr = 6.8 , pt = 8.0 , pl = 5.3; 
	float hr = 3.3 , ht = 3.0 , hl = 5.0;
	float cr = 5.0 , ct = 3.9 , cl = 6.0;
	float ukupnoR = 0 , ukupnoT = 0 , ukupnoL = 0;
	float ukupnoH = 0 , ukupnoP = 0 , ukupnoC = 0;
	switch(jzt)
	{
		
		
		case 'H':
		ukupnoR += hr;
		ukupnoT += ht;
		ukupnoL += hl;
		ukupnoH += hr;
		break;
		
		case 'P':
		
		ukupnoR += pr;
		ukupnoT += pt;
		ukupnoL += pl;
		ukupnoP += pr;
		break;
		case 'C':
		
		
		ukupnoR += cr;
		ukupnoT += ct;
		ukupnoL += cl;
		ukupnoC += cr;
		break;
		
		default:
		break;
		
	}
	switch(jzb)
	{
		case 'H':
		ukupnoR += hr;
		ukupnoT += ht;
		ukupnoL += hl;
		ukupnoH += hr;
		break;
		case 'P':
		
		ukupnoR += pr;
		ukupnoT += pt;
		ukupnoL += pl;
		ukupnoP += pr;
		break;
		case 'C':
		
		ukupnoR += cr;
		ukupnoT += ct;
		ukupnoL += cl;
		ukupnoC += cr;
		break;
		
		default:
		break;
	}
	switch(jzm) {
		case 'H':
		ukupnoR += hr;
		ukupnoT += ht;
		ukupnoL += hl;
		ukupnoH += hr;
		break;
		
		case 'P':
		ukupnoR += pr;
		ukupnoT += pt;
		ukupnoL += pl;
		ukupnoP += pr;
		break;
		case 'C':
		ukupnoR += cr;
		ukupnoT += ct;
		ukupnoL += cl;
		ukupnoC += cr;
		break;
		
		default:
		break;
	}
	float min=1000;
	if(ukupnoR < min)
	
	{
		min = ukupnoR;
		
	}
	if(ukupnoT < min)
	
	{
		min = ukupnoT;
	}
	if(ukupnoL < min)
	
	{
		min = ukupnoL;
	}
	float max = 0;
	if(ukupnoH > max){
		max = ukupnoH;
	}
	if(ukupnoP > max){
		max = ukupnoP;
	}
	if(ukupnoC > max)
	
	{
		max = ukupnoC;
	}
	float popust = max * 10/100;
	float restoranpopust = 0;
	
	if(ukupnoR != min){
		restoranpopust = ukupnoR - popust;
	}
	if(min == ukupnoR)
	
	{
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",ukupnoR);
	}
	else if(min == ukupnoT)
	{
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",ukupnoT);
	}
	else if(min == ukupnoL)
	{
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",ukupnoL);
	}
	if(restoranpopust > 0 && restoranpopust < min){
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",restoranpopust);
	}

	return 0;
}
