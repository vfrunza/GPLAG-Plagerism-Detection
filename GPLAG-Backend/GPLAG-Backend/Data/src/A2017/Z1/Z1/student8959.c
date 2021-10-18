#include <stdio.h>
#define P1 6.8
#define P2 8.0
#define P3 5.3
#define H1 3.3
#define H2 3.0
#define H3 5.0
#define C1 5.0
#define C2 3.9
#define C3 6.0
int main() {
	char T,B,M;
	double min,max,cijena1,cijena2,cijena3;
	printf("Unesite jelo za Tarika: ");
	scanf(" %c",&T);
	printf("Unesite jelo za Bojana: ");
	scanf(" %c",&B);
	printf("Unesite jelo za Mirzu: ");
	scanf(" %c",&M);
	if((T%'H'==0 )&&(B%'H'==0)&&(M%'H'==0))
	{
		if(H1<H2 && H1<H3)
		{
			min=H1;
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",(3*min));
			return 1;
		}
		else if(H2<H1 &&H2<H3)
		{
			min=H2;
				printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",(3*min));
		}
		else 
		{
			min=H3;
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",(3*min));
		}
	
		if((3*H1-3*H1*0.1)<(3*min)) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",(3*H1-3*H1*0.1));
		return 1;
	}
	else if((T%'P'==0 )&&(B%'P'==0)&&(M%'P'==0)) 
	{
		if(P1<P2 && P1<P3)
		{
			min=P1;
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",(3*min));
			return 1;
		}
		else if(P2<P1 &&P2<P3)
		{
			min=P2;
				printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",(3*min));
		}
		else 
		{
			min=P3;
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",(3*min));
		}
	
		if((3*P1-3*P1*0.1)<(3*min)) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",(3*P1-3*P1*0.1));
		return 1;
	}
	
		else if((T%'C'==0 )&&(B%'C'==0)&&(M%'C'==0)) 
	{
		if(C1<C2 && C1<C3)
		{
			min=C1;
				printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",(3*min));
				return 1;
		}
		else if(C2<C1 &&C2<C3)
		{
			min=C2;
				printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",(3*min));
		}
		else 
		{
			min=C3;
				printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",(3*min));
		}
	
		if((3*C1-3*C1*0.1)<(3*min)) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",(3*C1-3*C1*0.1));
		return 1;
	}
	//Moguce kombinacije kada svi unesu drugo jelo
	else if( (T%'P'==0 && B%'H'==0 && M%'C'==0 )||(T%'P'==0 && B%'C'==0 && M%'H'==0)||(T%'H'==0 && B%'P'==0 && M%'C'==0)
	||(T%'H'==0 && B%'C'==0 && M%'P'==0)||(T%'C'==0 && B%'H'==0 && M%'P'==0) ||(T%'C'==0 && B%'P'==0 && M%'H'==0))
	{
		cijena1=H1+C1+P1;
		cijena2=H2+C2+P2;
		cijena3=H3+C3+P3;
		
		if((cijena1<cijena2) && (cijena1<cijena3))
		{
			min=cijena1;
				printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",min);
				return 1;
		}
		else if((cijena2<cijena1) && (cijena2<cijena3))
		{
			min=cijena2;
				printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",min);
		}
		else
		{
			min=cijena3;
				printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",min);
		}
		if(H1>P1 && H1>C1) max=H1;
		else if(P1>H1 && P1>C1) max=P1;
		else max=C1;
		if((cijena1-max*0.1)<min) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",(cijena1-max*0.1));
		return 1;
	}
	//Moguce kombinacije kada 2 osobe unesu HAMBURGER
	else if((T%'H'==0 && B%'H'==0 &&(M%'P'==0 ||M%'C'==0)) || (T%'H'==0 && M%'H'==0 &&(B%'P'==0 ||B%'C'==0))
	|| (M%'H'==0 && B%'H'==0 &&(T%'P'==0 ||T%'C'==0)))
	{ 
		if(T%'P'==0 || M%'P'==0 || B%'P'==0)
		{
			
			cijena1=P1+2*H1;
			cijena2=P2+2*H2;
			cijena3=P3+2*H3;
			
			if((cijena1<cijena2) && (cijena1<cijena3))
		{
			min=cijena1;
				printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",min);
				return 1;
		}
		else if((cijena2<cijena1) && (cijena2<cijena3))
		{
			min=cijena2;
				printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",min);
		}
		else
		{
			min=cijena3;
				printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",min);
		}
		if(P1>2*H1) max=P1;
		else max=2*H1;
			if((cijena1-max*0.1)<min) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",(cijena1-max*0.1));
			
		}
		else
		{
			cijena1=C1+2*H1;
			cijena2=C2+2*H2;
			cijena3=C3+2*H3;
			
			if((cijena1<cijena2) && (cijena1<cijena3))
		{
			min=cijena1;
				printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",min);
				return 1;
		}
		else if((cijena2<cijena1) && (cijena2<cijena3))
		{
			min=cijena2;
				printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",min);
		}
		else
		{
			min=cijena3;
				printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",min);
		}
		if(C1>2*H1) max=C1;
		else max=2*H1;
			if((cijena1-max*0.1)<min) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",(cijena1-max*0.1));
		}
	}
		//Moguce kombinacije kada 2 osobe unesu PICU
	else if((T%'P'==0 && B%'P'==0 &&(M%'H'==0 ||M%'C'==0)) || (T%'P'==0 && M%'P'==0 &&(B%'H'==0 ||B%'C'==0))
	|| (M%'P'==0 && B%'P'==0 &&(T%'H'==0 ||T%'C'==0)))
	{
		if(T%'H'==0 || M%'H'==0 || B%'H'==0)
		{
			cijena1=H1+2*P1;
			cijena2=H2+2*P2;
			cijena3=H3+2*P3;
			
			if((cijena1<cijena2) && (cijena1<cijena3))
		{
			min=cijena1;
				printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",min);
				return 1;
		}
		else if((cijena2<cijena1) && (cijena2<cijena3))
		{
			min=cijena2;
				printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",min);
		}
		else
		{
			min=cijena3;
				printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",min);
		}
		if(H1>2*P1) max=H1;
		else max=2*P1;
			if((cijena1-max*0.1)<min) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",(cijena1-max*0.1));
			
		}
		else
		{
			cijena1=C1+2*P1;
			cijena2=C2+2*P2;
			cijena3=C3+2*P3;
			if((cijena1<cijena2) && (cijena1<cijena3))
		{
			min=cijena1;
				printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",min);
				return 1;
		}
		else if((cijena2<cijena1) && (cijena2<cijena3))
		{
			min=cijena2;
				printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",min);
		}
		else
		{
			min=cijena3;
				printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",min);
		}
		if(C1>2*P1) max=C1;
		else max=2*P1;
			if((cijena1-max*0.1)<min) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",(cijena1-max*0.1));
		}
	}
	//Moguce kombinacije kada 2 osobe unesu Cevape
	else
	{
		if(T%'H'==0 || M%'H'==0 || B%'H'==0)
		{
			cijena1=H1+2*C1;
			cijena2=H2+2*C2;
			cijena3=H3+2*C3;
			
			if((cijena1<cijena2) && (cijena1<cijena3))
		{
			min=cijena1;
				printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",min);
				return 1;
		}
		else if((cijena2<cijena1) && (cijena2<cijena3))
		{
			min=cijena2;
				printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",min);
		}
		else
		{
			min=cijena3;
				printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",min);
		}
		if(H1>2*C1) max=H1;
		else max=2*C1;
			if((cijena1-max*0.1)<min) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",(cijena1-max*0.1));
			
		}
		else
		{
			cijena1=P1+2*C1;
			cijena2=P2+2*C2;
			cijena3=P3+2*C3;
			if((cijena1<cijena2) && (cijena1<cijena3))
		{
			min=cijena1;
				printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",min);
				return 1;
		}
		else if((cijena2<cijena1) && (cijena2<cijena3))
		{
			min=cijena2;
				printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",min);
		}
		else
		{
			min=cijena3;
				printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",min);
		}
		if(P1>2*C1) max=P1;
		else max=2*C1;
			if((cijena1-max*0.1)<min) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",(cijena1-max*0.1));
		}
	}
	
	return 0;
}
