#include <stdio.h>

#define pizza_konjusar 6.8
#define pizza_trovac 8
#define pizza_lorelei 5.3

#define hamburger_konjusar 3.3
#define hamburger_trovac 3
#define hamburger_lorelei 5

#define cevapi_konjusar 5
#define cevapi_trovac 3.9
#define cevapi_lorelei 6

int main() {
	
	char tarik_nar;
	char bojan_nar;
	char mirza_nar;
	char novi_red;
	float hamburgerkodKiK=0, hamburgerfastfoodT=0, hamburgerbistroL=0,pizzakodKiK=0,pizzafastfoodT=0,pizzabistroL=0,cevapikodKiK=0,cevapifastfoodT=0,cevapibistoL=0;
	float kodKiK =0,fastfoodT=0,bistroL=0;
	//u zadatku nije definisano sta da radimo sa drugim slovima osim H, P i C, tako da cu ja to uraditi na svoj nacin.//
	
	do{
		printf("Unesite jelo za Tarika: ");
		scanf("%c", &tarik_nar);
		scanf("%c", &novi_red);
	}while(tarik_nar != 'H' && tarik_nar != 'P' && tarik_nar != 'C');
	
	do{
		printf("Unesite jelo za Bojana: ");
		scanf("%c", &bojan_nar);
		scanf("%c", &novi_red);
	}while(bojan_nar != 'H' && bojan_nar != 'P' && bojan_nar != 'C');
	
	do{
		printf("Unesite jelo za Mirzu: ");
		scanf("%c", &mirza_nar);
		scanf("%c", &novi_red);
	}while(mirza_nar != 'H' && mirza_nar != 'P' && mirza_nar != 'C');
	
	if(tarik_nar == 'H')
			{
			hamburgerkodKiK=hamburgerkodKiK + hamburger_konjusar;
			hamburgerfastfoodT=hamburgerfastfoodT + hamburger_trovac;
			hamburgerbistroL=hamburgerbistroL + hamburger_lorelei;
			}
			else if (tarik_nar =='P' )
			{
				pizzakodKiK=pizzakodKiK + pizza_konjusar;
				pizzafastfoodT=pizzafastfoodT + pizza_trovac;
				pizzabistroL=pizzabistroL + pizza_lorelei;
			}
				else
				
				{
					cevapikodKiK=cevapikodKiK + cevapi_konjusar;
					cevapifastfoodT=cevapifastfoodT + cevapi_trovac;
					cevapibistoL=cevapibistoL + cevapi_lorelei;
				}  
	if(bojan_nar == 'H')
			{
			hamburgerkodKiK=hamburgerkodKiK + hamburger_konjusar;
			hamburgerfastfoodT=hamburgerfastfoodT + hamburger_trovac;
			hamburgerbistroL=hamburgerbistroL + hamburger_lorelei;
			}
			else if (bojan_nar =='P' )
			{
				pizzakodKiK=pizzakodKiK + pizza_konjusar;
				pizzafastfoodT=pizzafastfoodT + pizza_trovac;
				pizzabistroL=pizzabistroL + pizza_lorelei;
			}
				else
				
				{
					cevapikodKiK=cevapikodKiK + cevapi_konjusar;
					cevapifastfoodT=cevapifastfoodT + cevapi_trovac;
					cevapibistoL=cevapibistoL + cevapi_lorelei;
				}
	if(mirza_nar == 'H')
			{
			hamburgerkodKiK=hamburgerkodKiK + hamburger_konjusar;
			hamburgerfastfoodT=hamburgerfastfoodT + hamburger_trovac;
			hamburgerbistroL=hamburgerbistroL + hamburger_lorelei;
			}
			else if (mirza_nar =='P' )
			{
				pizzakodKiK=pizzakodKiK + pizza_konjusar;
				pizzafastfoodT=pizzafastfoodT + pizza_trovac;
				pizzabistroL=pizzabistroL + pizza_lorelei;
			}
				else
				
				{
					cevapikodKiK=cevapikodKiK + cevapi_konjusar;
					cevapifastfoodT=cevapifastfoodT + cevapi_trovac;
					cevapibistoL=cevapibistoL + cevapi_lorelei;
				}
				
	kodKiK=hamburgerkodKiK + pizzakodKiK + cevapikodKiK;
	fastfoodT=hamburgerfastfoodT + pizzafastfoodT + cevapifastfoodT;
	bistroL=hamburgerbistroL + pizzabistroL + cevapibistoL;
			
	if((kodKiK<fastfoodT)&&(kodKiK<bistroL))
		{
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",kodKiK);
			return 0; 
		}
		else if ((fastfoodT<kodKiK)&&(fastfoodT<bistroL))
		{
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",fastfoodT);
		}
		else {
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",bistroL);
		}
		
		
	float popustkodKiK=0;
	
	if (tarik_nar =='H' && bojan_nar =='H' && mirza_nar =='H')
		{     
			popustkodKiK=hamburgerkodKiK*0.9;
			if((popustkodKiK<fastfoodT)&&(popustkodKiK<bistroL))
			{
				printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).\n",popustkodKiK);
			}
		}
	 if (tarik_nar== 'P' && bojan_nar== 'P' && mirza_nar == 'P')
				{
					popustkodKiK=pizzakodKiK*0.9;
					if((popustkodKiK<fastfoodT)&&(popustkodKiK<bistroL))
					{
						printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).\n",popustkodKiK);	
					}
				}
	 if (tarik_nar =='C' && bojan_nar =='C' && mirza_nar =='C')
				{
					popustkodKiK=cevapikodKiK*0.9;
					if((popustkodKiK<fastfoodT)&&(popustkodKiK<bistroL))
					{
						printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).\n",popustkodKiK);
					}
				}
	if ((tarik_nar=='P' || bojan_nar=='P' || mirza_nar=='P'))
	{
		popustkodKiK=pizzakodKiK*0.9 + hamburgerkodKiK + cevapikodKiK;
		if((popustkodKiK<fastfoodT)&&(popustkodKiK<bistroL))
		{
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).\n",popustkodKiK);	
		}
	}
	return 0;
}
