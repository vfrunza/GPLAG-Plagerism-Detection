#include <stdio.h>

int main() {
	
	int kolone;
	int sirinaKolone;
	int redovi;
	int brojRedova,brojKolona,sirinaKolona;
	
	do{
	printf("Unesite broj redova: ");
	scanf("%d",&brojRedova);
	}while(brojRedova > 10 || brojRedova <= 0);
	
	do{
	printf("Unesite broj kolona: ");
	scanf("%d",&brojKolona);
	}while(brojKolona > 10 ||brojKolona <= 0);
	
	do{
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d",&sirinaKolona);
	}while(sirinaKolona > 10 || sirinaKolona <= 0);
	
	for(redovi = 0; redovi <= brojRedova-1; redovi++)
	{
		printf("+");
		for(kolone = 0; kolone <= brojKolona-1; kolone++)
		{
				for(sirinaKolone = 0; sirinaKolone <= sirinaKolona-1;sirinaKolone++)
				{
					printf("-");
				}
				printf("+");
				
		}
		printf("\n");
		printf("|");
		for(kolone = 0; kolone <= brojKolona-1; kolone++)
		{
				for(sirinaKolone = 0; sirinaKolone <= sirinaKolona-1;sirinaKolone++)
				{
					printf(" ");
				}
				printf("|");
				
		}
		printf("\n");
	}
	printf("+");
	for(kolone = 0; kolone <= brojKolona-1; kolone++)
	{
			for(sirinaKolone = 0; sirinaKolone <= sirinaKolona-1;sirinaKolone++)
			{
				printf("-");
			}
			printf("+");
			
	}
	
	return 0;
}
