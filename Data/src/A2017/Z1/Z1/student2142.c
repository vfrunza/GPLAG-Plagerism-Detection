#include <stdio.h>

int main() {
	
	char tarik,bojan,mirza, novi_red;
	float p1=6.8,p2=8.0,p3=5.3,h1=3.3,h2=3.0,h3=5.0,c1=5.0,c2=3.9,c3=6.0,racun,racunp;
	/*Unos jela*/
	printf("Unesite jelo za Tarika: ");
	scanf("%c",&tarik);
	scanf("%c",&novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c",&bojan);
	scanf("%c",&novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c",&mirza);
	scanf("%c",&novi_red);
	
	if(tarik=='H' && bojan=='H' && mirza=='H')
	{
		racun=3*h2;
		racunp=3*h1-3*h1*0.1;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",racun);
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",racunp);
	}
	if(tarik=='P' && bojan=='P' && mirza=='P')
	{	
		racun=3*p3;
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",racun);
	}
	if(tarik=='C' && bojan=='C' && mirza=='C')
	{	
		racun=3*c2;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",racun);
	}
	if(tarik=='C' && bojan=='H' && mirza=='H')
	{ 
		racun=2*h2+c2;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",racun);
	}
	if(tarik=='H' && bojan=='C' && mirza=='H')
	{
		racun=2*h2+c2;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",racun);
	}
	if(tarik=='H' && bojan=='H' && mirza=='C')
	{
		racun=2*h2+c2;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",racun);
	}
	if(tarik=='P' && bojan=='H' && mirza=='H')
	{
		racun=2*h1+p1;
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",racun);
	}
	if(tarik=='H' && bojan=='P' && mirza=='H')
	{
		racun=2*h1+p1;
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",racun);
	}
	if(tarik=='H' && bojan=='H' && mirza=='P')
	{
		racun=2*h1+p1;
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",racun);
	}
	if(tarik=='H' && bojan=='C' && mirza=='C')
	{
		racun=2*c2+h2;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",racun);
	}
	if(tarik=='C' && bojan=='H' && mirza=='C')
	{
		racun=2*c2+h2;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",racun);
	}
	if(tarik=='C' && bojan=='C' && mirza=='H')
	{
		racun=2*c2+h2;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",racun);
	}
	if(tarik=='P' && bojan=='C' && mirza=='C')
	{
		racun=2*c2+p2;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",racun);
	}
	if(tarik=='C' && bojan=='P' && mirza=='C')
	{
		racun=2*c2+p2;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",racun);
	}
	if(tarik=='C' && bojan=='C' && mirza=='P')
	{
		racun=2*c2+p2;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",racun);
	}
	if(tarik=='H' && bojan=='P' && mirza=='P')
	{
		racun=2*p3+h3;
		racunp=2*p1+h1-(2*p1*0.1);
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",racun);
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",racunp);
	}
	if(tarik=='P' && bojan=='H' && mirza=='P')
	{
		racun=2*p3+h3;
		racunp=2*p1+h1-(2*p1*0.1);
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",racun);
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",racunp);	
	}
	if(tarik=='P' && bojan=='P' && mirza=='H')
	{
		racun=2*p3+h3;
		racunp=2*p1+h1-(2*p1*0.1);
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",racun);
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",racunp);
	}
	if(tarik=='C' && bojan=='P' && mirza=='P')
	{
		racun=2*p3+c3;
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",racun);
	}
	if(tarik=='P' && bojan=='C' && mirza=='P')
	{
		racun=2*p3+c3;
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",racun);
	}
	if(tarik=='P' && bojan=='P' && mirza=='C')
	{
		racun=2*p3+c3;
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",racun);
	}
	if(tarik=='H' && bojan=='C' && mirza=='P')
	{
		racun=p2+h2+c2;
		racunp=p1+h1+c1-(p1*0.1);
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",racun);
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",racunp);
	}
	if(tarik=='C' && bojan=='H' && mirza=='P')
	{
		racun=p2+h2+c2;
		racunp=p1+h1+c1-(p1*0.1);
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",racun);
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",racunp);
	}
	if(tarik=='P' && bojan=='C' && mirza=='H')
	{
		racun=p2+h2+c2;
		racunp=p1+h1+c1-(p1*0.1);
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",racun);
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",racunp);
	}
	if(tarik=='H' && bojan=='P' && mirza=='C')
	{
		racun=p2+h2+c2;
		racunp=p1+h1+c1-(p1*0.1);
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",racun);
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",racunp);
	}
	if(tarik=='P' && bojan=='H' && mirza=='C')
	{
		racun=p2+h2+c2;
		racunp=p1+h1+c1-(p1*0.1);
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",racun);
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",racunp);
	}
	if(tarik=='C' && bojan=='P' && mirza=='H')
	{
		racun=p2+h2+c2;
		racunp=p1+h1+c1-(p1*0.1);
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",racun);
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",racunp);
	}
	return 0;
}
