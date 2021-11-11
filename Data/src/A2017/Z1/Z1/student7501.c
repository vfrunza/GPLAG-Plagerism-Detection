#include <stdio.h>

int main() {
	float pizzarestoran = 6.80;
	float pizzafastfood = 8;
	float pizzabistro = 5.30;
    float hamburgerrestoran = 3.30;
    float hamburgerfastfood = 3;
    float hamburgerbistro = 5;
    float cevapirestoran = 5;
    float cevapifastfood = 3.90;
    float cevapibistro = 6;
    char tarik,bojan,mirza,novi_red;
    float restoranukupno=0, fastfoodukupno=0, bistroukupno=0;
    float brojpizza=0, brojhamburgera=0, brojcevapa=0;
   
    printf("Unesite jelo za Tarika: ");
	scanf("%c", &tarik);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &bojan);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf(" %c", &mirza);
	
	switch(tarik)
	{
	    case'P':
	    restoranukupno=restoranukupno+pizzarestoran;
	    fastfoodukupno=fastfoodukupno+pizzafastfood;
	    bistroukupno=bistroukupno+pizzabistro;
	    brojpizza++;
	    break;
	    
	    case'H':
	    restoranukupno=restoranukupno+hamburgerrestoran;
	    fastfoodukupno=fastfoodukupno+hamburgerfastfood;
	    bistroukupno=bistroukupno+hamburgerbistro;
	    brojhamburgera++;
	    break;
	    
	    case'C':
	    restoranukupno=restoranukupno+cevapirestoran;
	    fastfoodukupno=fastfoodukupno+cevapifastfood;
	    bistroukupno=bistroukupno+cevapibistro;
	    brojcevapa++;
	    break;
	    
	    default:
	    printf("\nPogrešan unos!");
	    
	}

	switch(bojan)
	{
	    case'P':
	    restoranukupno=restoranukupno+pizzarestoran;
	    fastfoodukupno=fastfoodukupno+pizzafastfood;
	    bistroukupno=bistroukupno+pizzabistro;
	    brojpizza++;
	    break;
	    
	    case'H':
	    restoranukupno=restoranukupno+hamburgerrestoran;
	    fastfoodukupno=fastfoodukupno+hamburgerfastfood;
	    bistroukupno=bistroukupno+hamburgerbistro;
	    brojhamburgera++;
	    break;
	    
	    case'C':
	    restoranukupno=restoranukupno+cevapirestoran;
	    fastfoodukupno=fastfoodukupno+cevapifastfood;
	    bistroukupno=bistroukupno+cevapibistro;
	    brojcevapa++;
	    break;
	    
	    default:
	    printf("Pogrešan unos!");
	    
	}
	
	switch(mirza)
	{
	    case'P':
	    restoranukupno=restoranukupno+pizzarestoran;
	    fastfoodukupno=fastfoodukupno+pizzafastfood;
	    bistroukupno=bistroukupno+pizzabistro;
	    brojpizza++;
	    break;
	    
	    case'H':
	    restoranukupno=restoranukupno+hamburgerrestoran;
	    fastfoodukupno=fastfoodukupno+hamburgerfastfood;
	    bistroukupno=bistroukupno+hamburgerbistro;
	    brojhamburgera++;
	    break;
	    
	    case'C':
	    restoranukupno=restoranukupno+cevapirestoran;
	    fastfoodukupno=fastfoodukupno+cevapifastfood;
	    bistroukupno=bistroukupno+cevapibistro;
	    brojcevapa++;
	    break;
	    
	    default:
	    printf("Pogrešan unos!");
}

	if (restoranukupno<fastfoodukupno && restoranukupno<bistroukupno) 
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",restoranukupno);

	else if (fastfoodukupno<restoranukupno && fastfoodukupno<bistroukupno ) 
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",fastfoodukupno);

	else if (bistroukupno<fastfoodukupno && bistroukupno<restoranukupno) 
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",bistroukupno);
	
	
	if (bistroukupno<restoranukupno || fastfoodukupno<restoranukupno)

	{
		if (brojpizza>brojcevapa && brojpizza>brojhamburgera) 
			restoranukupno-=pizzarestoran*(brojpizza*0.1);
	
		else if (brojcevapa>brojpizza && brojcevapa>brojhamburgera) 
			restoranukupno-=cevapirestoran*(brojcevapa*0.1);
	
		else if (brojhamburgera>brojpizza && brojhamburgera>brojcevapa) 
			restoranukupno-=hamburgerrestoran*(brojhamburgera*0.1);
	
		else if (brojhamburgera==1 && brojcevapa==1 && brojpizza==1) 
			restoranukupno-=pizzarestoran*(brojpizza*0.1);
		
		if (restoranukupno<fastfoodukupno && restoranukupno<bistroukupno) 
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",restoranukupno);
	
	}
	
	return 0;
}
