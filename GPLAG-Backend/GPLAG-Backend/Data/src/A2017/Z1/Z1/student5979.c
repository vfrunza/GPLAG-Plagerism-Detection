#include <stdio.h>
#define PizzaRestoran 6.80
#define PizzaTrovac 8.00
#define PizzaBistro 5.30
#define HamburgerRestoran 3.30
#define HamburgerTrovac 3.00
#define HamburgerBistro 5.00
#define CevapiRestoran 5.00
#define CevapiTrovac 3.90
#define CevapiBistro 6.00


int main() {
	char j1,j2,j3,novi_red;
	int p=0,h=0,c=0;
	double iR,iT,iB,iRP,iRH,iRC;
	
	printf("Unesite jelo za Tarika: ");
	scanf("%c",&j1);
	scanf("%c",&novi_red);
		if(j1=='H') h=h+1; else if (j1=='P') p=p+1; else if(j1=='C') c=c+1;
		
	printf("Unesite jelo za Bojana: ");
	scanf("%c",&j2);
	scanf("%c",&novi_red);
	if(j2=='H') h++; else if (j2=='P') p++; else if(j2=='C') c++; 
	printf("Unesite jelo za Mirzu: ");
	scanf("%c",&j3);
	if(j3=='H') h++; else if (j3=='P') p++; else if (j3=='C') c++;
	iR=p*PizzaRestoran + h*HamburgerRestoran + c*CevapiRestoran;
	iT=p*PizzaTrovac + h*HamburgerTrovac +c*CevapiTrovac;
	iB=p*PizzaBistro + h*HamburgerBistro + c*CevapiBistro;
	iRH=p*PizzaRestoran*9.00/10 + h*HamburgerRestoran + c*CevapiRestoran;
	iRP=p*PizzaRestoran + h*HamburgerRestoran*9.00/10 +c*CevapiRestoran;
	iRC=p*PizzaRestoran +h*HamburgerRestoran + c*CevapiRestoran*9.00/10;
	if (iR<=iT && iR<=iB) printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",iR);
		else if (iT<=iR && iT<=iB)
		{
				printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",iT);
			 		if(iRH<iT || iRC<iT || iRP <iT){
						if(iRH<=iRP && iRH<=iRC)
							printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",iRH);
						else if (iRP<=iRH && iRP<=iRC)
								printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",iRP);
								else printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",iRC);
		}
			
		} else {printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",iB);
		if(iRH<iB ||iRP<iB || iRC<iB){
			if(iRH<=iRP && iRH<=iRC) 
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",iRH);
			else if(iRP<=iRH && iRP<=iRC) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",iRP);
			else printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",iRC);
			
		}
	} 
	return 0;
}
