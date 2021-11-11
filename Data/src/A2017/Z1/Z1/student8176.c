#include <stdio.h>

int main() 
{
	char mirza,bojan,tarik,novired;
	float restoran,fastfood,bistro,Ppopust,Hpopust,Cpopust,x;
	
	
	
	
	restoran=0.00;
	bistro=0.00;
	fastfood=0.00;
	Ppopust=0.00;
	Hpopust=0.00;
	Cpopust=0.00;
	x=0.00;
	
	
	
	printf("Unesite jelo za Tarika: ");
	scanf("%c",&tarik);
	scanf("%c",&novired);
	printf("Unesite jelo za Bojana: ");
	scanf("%c",&bojan);
	scanf("%c",&novired);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c",&mirza);
	
	switch (tarik)
	{
		
		
		case 'H' :
		
			restoran=restoran+3.30;
			fastfood=fastfood+3.00;
			bistro=bistro+5.00;
			break;
		case 'P' :
		restoran=restoran+6.80;
		fastfood=fastfood+8.00;
		bistro=bistro+5.30;
		break;
		case 'C' :
		restoran=restoran+5.00;
		fastfood=fastfood+3.90;
		bistro=bistro+6.00;
		break;
	}
	
	switch (mirza)
	{
		case 'H' :
		
			restoran=restoran+3.30;
			fastfood=fastfood+3.00;
			bistro=bistro+5.00;
			break;
		case 'P' :
		restoran=restoran+6.80;
		fastfood=fastfood+8.00;
		bistro=bistro+5.30;
		break;
		case 'C' :
		restoran=restoran+5.00;
		fastfood=fastfood+3.90;
		bistro=bistro+6.00;
		break;
	}
	
	switch (bojan)
	{
		case 'H' :
		
			restoran=restoran+3.30;
			fastfood=fastfood+3.00;
			bistro=bistro+5.00;
			break;
		case 'P' :
		restoran=restoran+6.80;
		fastfood=fastfood+8.00;
		bistro=bistro+5.30;
		break;
		case 'C' :
		restoran=restoran+5.00;
		fastfood=fastfood+3.90;
		bistro=bistro+6.00;
		break;
	}
	
	if(restoran<fastfood && restoran<bistro)
	printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM). ",restoran);
	else if (fastfood<restoran && fastfood<bistro)
	printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM). ",fastfood);
	else
	printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM). ",bistro);
	if (restoran>fastfood || restoran>bistro)
	{  
		if(mirza=='P' || tarik=='P' || bojan=='P')
		Ppopust=0.68; 
		if(tarik==bojan && tarik==mirza)
		Ppopust=2.04;
		else if( (tarik=='P' && mirza=='P') || ( tarik=='P' && bojan=='P') || (mirza=='P' && bojan=='P'))
		Ppopust=2.04;
	}
	if(mirza=='C' || tarik=='C' || bojan=='C')
	{
		Cpopust=0.50;
		if(tarik==bojan && tarik==mirza)
		Cpopust=1.50;
		else if( (tarik=='C' && mirza=='C') || ( tarik=='C' && bojan=='C') || (mirza=='C' && bojan=='C'))
		Cpopust=1;
	}
	
	if(mirza=='H' || tarik=='H' || bojan=='H')
	{
		Hpopust=0.33;
		if(tarik==bojan && tarik==mirza)
		Hpopust=0.99;
		else if( (tarik=='C' && mirza=='C') || ( tarik=='C' && bojan=='C') || (mirza=='C' && bojan=='C'))
		Hpopust=0;
		
	}
	
	if( Hpopust>Cpopust && Hpopust>Ppopust)
	x=restoran-Hpopust;
	else if (Ppopust>Hpopust && Ppopust>Cpopust)
	x=restoran-Ppopust;
	else
	x=restoran-Cpopust;
	
	if (fastfood<restoran || bistro<restoran)
	{
		if(x<bistro && x<fastfood)
		{
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM. ",x);
		}
	}
	
	

	return 0;
}
