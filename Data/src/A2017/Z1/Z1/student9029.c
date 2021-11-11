#include <stdio.h>
#define p1 6.80
#define p2 8.00
#define p3 5.30
#define h1 3.30
#define h2 3.00
#define h3 5.00
#define c1 5.00
#define c2 3.90
#define c3 6.00

int main() {
	char novi_red;
	float zbir1,zbir2,popust1,popust2,zbir4,zbir3,zbir5,zbir6,zbir7,zbir8,zbir9,rezultat1,rezultat2,zbir10,rezultat3,popust3,rezultatH,cijena,rezultatP,rezultatC,rezultatH1,rezultatC1,rezultatC2,rezultatP2,rezultatH3,rezultat3h,rezultat3c,rezultatC3,rezultatH2,rezultatc;
	char tarik,bojan,mirza;
	printf("Unesite jelo za Tarika: ");
	scanf("%c",&tarik);
	scanf("%c",&novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c",&bojan);
	scanf("%c",&novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c",&mirza);
	scanf("%c",&novi_red);
		
	 if(tarik=='P' && bojan=='P' && mirza=='P' ){
	 zbir1=p3+p3+p3;
	 printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",zbir1);}
	 else if(tarik=='H' && bojan=='H' && mirza=='H'){
	 	zbir2=h2*3;
	 		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",zbir2);
	 	popust1=(h1*3)*10/100;
	 	
	 	rezultat1=h1*3-popust1;
	 	if(rezultat1<zbir2)
	 		printf("\nSa popustom bi Restoran bio jeftiniji (%g KM).",rezultat1);
	 	
	 }else if(tarik=='C' && mirza=='C' && bojan=='C'){
	 	zbir3=c2*3;
	 	printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",zbir3);
	 	cijena=c1*3-((c1*3*10)/100);
	 	if(cijena<zbir3)
	 	printf("\nSa popustom bi Restoran bio jeftiniji (%g KM).",cijena);
	 	
	 }else if(tarik=='P' && bojan=='P' && mirza=='H' || tarik=='P' && mirza=='P' && bojan=='H' || mirza=='P'&& bojan=='P' && tarik=='H'){
	 	zbir4=p3+p3+h3;
	 
	 		 printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",zbir4);
	 		 rezultatH=(p1+p1+h1)-(h1*10/100);
	 		 	popust2=p1*2*10/100;
	 	rezultat2=(p1+p1+h1)-popust2;
	 	if(rezultat2<rezultatH)
	 		 printf("\nSa popustom bi Restoran bio jeftiniji (%g KM).",rezultat2);
	 }
		else if(tarik=='P' && bojan=='P' && mirza=='C' || tarik=='P' && mirza=='P' && bojan=='C' || mirza=='P'&& bojan=='P' && tarik=='C'){
			zbir5=p3+p3+c3;
			printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",zbir5);
			rezultatP=(p1+p1+c1)-(p1*2*10/100);
			rezultatC=(p1+p1+c1)-(c1*10/100);
			if(rezultatP<zbir5)
			 printf("\nSa popustom bi Restoran bio jeftiniji (%g KM).",rezultatP);
			 if(rezultatC<zbir5)
			 printf("\nSa popustom bi Restoran bio jeftiniji (%g KM).",rezultatC);
		}
		 else if(tarik=='H' && bojan=='H' && mirza=='P' || tarik=='H' && mirza=='H' && bojan=='P' || mirza=='H'&& bojan=='H' && tarik=='P'){
		 	zbir6=h1+h1+p1;
		 	printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",zbir6);
		 }
		 else if(tarik=='H' && bojan=='H' && mirza=='C' || tarik=='H' && mirza=='H' && bojan=='C' || mirza=='H'&& bojan=='H' && tarik=='C'){
		 	zbir7=h2+h2+c2;
		 		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",zbir7);
		 		rezultatH1=(h1*2+c1)-(h1*2*10/100);
		 		rezultatC1=(h1*2+c1)-(c1*10/100);
		 		if(rezultatH1<zbir7)
		 		 printf("\nSa popustom bi Restoran bio jeftiniji (%g KM).",rezultatH1);
		 		 if(rezultatC1<zbir7)
		 		 printf("\nSa popustom bi Restoran bio jeftiniji (%g KM).",rezultatC1);
		 }
		 
		else if(tarik=='C' && bojan=='C' && mirza=='P' || tarik=='C' && mirza=='C' && bojan=='P' || mirza=='C'&& bojan=='C' && tarik=='P'){
			zbir8=c2+c2+p2;
				printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",zbir8);
				rezultatC2=(c1*2+p1)-(c1*2*10/100);
				rezultatP2=(c1*2+p1)-(p1*10/100);
				if(rezultatC2<zbir8 && rezultatC2<rezultatP2)
				printf("\nSa popustom bi Restoran bio jeftiniji (%g KM).",rezultatC2);
				if(rezultatP2<zbir8 && rezultatP2<rezultatC2)
			printf("\nSa popustom bi Restoran bio jeftiniji (%g KM).",rezultatP2);
		}
		
			else if(tarik=='C' && bojan=='C' && mirza=='H' || tarik=='C' && mirza=='C' && bojan=='H' || mirza=='C'&& bojan=='C' && tarik=='H'){
		zbir9=c2+c2+h2;
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",zbir9);
			rezultatC3=(c1*2+h1)-(c1*2*10/100);
			rezultatH2=(c1*2+h1)-(h1*10/100);
			if(rezultatC3<rezultatH2 && rezultatC3<zbir9)
			printf("\nSa popustom bi Restoran bio jeftiniji (%g KM).",rezultatC3);
			if(rezultatH2<zbir9 && rezultatH2<rezultatC3)
			printf("\nSa popustom bi Restoran bio jeftiniji (%g KM).",rezultatH2);
			}
			else if(tarik=='C' && bojan=='H' && mirza=='P' || tarik=='H' && mirza=='C' && bojan=='P' || mirza=='H'&& bojan=='C' && tarik=='P'){
				zbir10=c2+p2+h2;
				popust3=p1*10/100;
				rezultat3=(p1+h1+c1)-popust3;
				rezultat3c=(p1+h1+c1)-(c1*10/100);
				rezultat3h=(p1+h1+c1)-(h1*10/100);
					printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",zbir10);
					if(rezultat3<zbir10 && rezultat3<rezultat3c && rezultat3<rezultat3h)
					printf("\nSa popustom bi Restoran bio jeftiniji (%g KM).",rezultat3);
		
			}
	return 0;
}
