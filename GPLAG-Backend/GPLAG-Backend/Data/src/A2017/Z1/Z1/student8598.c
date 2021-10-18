#include <stdio.h>
#include <math.h>
#define H1 3.30
#define H2 3.00
#define H3 5.00
#define P1 6.80
#define P2 8.00
#define P3 5.30
#define Cv1 5.00
#define Cv2 3.90
#define Cv3 6.00

int main() {
	float C1=0,C2=0,C3=0;
	char tarik, mirza, bojan,novi_red;
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &tarik);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &bojan);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &mirza);
	scanf("%c", &novi_red);
	if(tarik=='H' && bojan=='H' && mirza=='H')
	{
	C1=H1+H1+H1;
	C2=H2+H2+H2;
	C3=H3+H3+H3;
	if(C1<C2 && C1<C3)
	printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", C1);
	if(C2<C1 && C2<C3)
	printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", C2);
	if(C3<C1 && C3<C2)
	printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", C3);
	if(C2<C1 || C3<C1)
	{
	C1=fabs(10*H1/100-H1)*3;
	if(C1<C2 && C1<C3)
	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", C1);
	}
	}
	if(tarik=='P' && bojan=='P' && mirza=='P')
	{
	C1=3*P1;
	C2=3*P2;
	C3=3*P3;
	if(C1<C2 && C1<C3)
	printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", C1);
	if(C2<C1 && C2<C3)
	printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", C2);
	if(C3<C1 && C3<C2)
	printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", C3);
	if(C2<C1 || C3<C1)
	{
	C1=fabs(10*P1/100-P1)*3;
	if(C1<C2 && C1<C3)
	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", C1);
	}
	}
	if(tarik=='C' && bojan=='C' && mirza=='C')
	{
	C1=3*Cv1;
	C2=3*Cv2;
	C3=3*Cv3;
	if(C1<C2 && C1<C3)
	printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", C1);
	if(C2<C1 && C2<C3)
	printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", C2);
	if(C3<C1 && C3<C2)
	printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", C3);
	if(C2<C1 || C3<C1)
	{
	C1=fabs(10*Cv1/100-Cv1)*3;
	if(C1<C2 && C1<C3)
	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", C1);
	}
	}
	if(tarik=='H' && bojan=='H' && mirza=='P' || tarik=='H' && bojan=='P' && mirza=='H' || tarik=='P' && bojan=='H' && mirza=='H')
	{
	C1=2*H1+P1;
	C2=2*H2+P2;
	C3=2*H3+P3;
	if(C1<C2 && C1<C3)
	printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", C1);
	if(C2<C1 && C2<C3)
	printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", C2);
	if(C3<C1 && C3<C2)
	printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", C3);
	if(C2<C1 || C3<C1)
	{
	if(2*H1>P1)
	{
	C1=(fabs(10*H1/100-H1)*2+P1);
	if(C1<C2 && C1<C3)
	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", C1);
	}
	if(P1>2*H1)
	{
	C1=(fabs(10*P1/100-P1)+2*H1);
	if(C1<C2 && C1<C3)
	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", C1);
	}
	}
	}
	if(tarik=='H' && bojan=='P' && mirza=='C' || tarik=='H' && bojan=='C' && mirza=='P' || tarik=='C' && bojan=='H' && mirza=='P' || tarik=='C' && bojan=='P' && mirza=='H' || tarik=='P' && bojan=='H' && mirza=='C' || tarik=='P' && bojan=='C' && mirza=='H')
	{
	C1=Cv1+H1+P1;
	C2=Cv2+H2+P2;
	C3=Cv3+H3+P3;
	if(C1<C2 && C1<C3)
	printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", C1);
	if(C2<C1 && C2<C3)
	printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", C2);
	if(C3<C1 && C3<C2)
	printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", C3);
	if(C2<C1 || C3<C1)
	{
	if(H1>Cv1 && H1>P1)
	{
	C1=(fabs(10*H1/100-H1)+Cv1+P1);
	if(C1<C2 && C1<C3)
	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", C1);
	}
	if(P1>Cv1 && P1>H1)
	{
	C1=(fabs(10*P1/100-P1)+Cv1+H1);
	if(C1<C2 && C1<C3)
	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", C1);
	}
	if(Cv1>H1 && Cv1>P1)
	{
	C1=(fabs(10*Cv1/100-Cv1)+H1+P1);
	if(C1<C2 && C1<C3)
	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", C1);
	}
	}
	}
	if(tarik=='H' && bojan=='H' && mirza=='C' || tarik=='H' && bojan=='C' && mirza=='H' || tarik=='C' && bojan=='H' && mirza=='H')
	{
	C1=2*H1+Cv1;
	C2=2*H2+Cv2;
	C3=2*H3+Cv3;
	if(C1<C2 && C1<C3)
	printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", C1);
	if(C2<C1 && C2<C3)
	printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", C2);
	if(C3<C1 && C3<C2)
	printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", C3);
	if(C2<C1 || C3<C1)
	{
	if(2*H1>Cv1)
	C1=(fabs(10*H1/100-H1)*2+Cv1);
	if(Cv1>2*H1)
	C1=(fabs(10*Cv1/100-Cv1)+2*H1);
	if(C1<C2 && C1<C3)
	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", C1);
	}
	}
	if(tarik=='H' && bojan=='C' && mirza=='C' || tarik=='C' && bojan=='C' && mirza=='H' || tarik=='C' && bojan=='H' && mirza=='C')
	{
	C1=2*Cv1+H1;
	C2=2*Cv2+H2;
	C3=2*Cv3+H3;
	if(C1<C2 && C1<C3)
	printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", C1);
	if(C2<C1 && C2<C3)
	printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", C2);
	if(C3<C1 && C3<C2)
	printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", C3);
	if(C2<C1 || C3<C1)
	{
	if(2*Cv1>H1)
	C1=(fabs(10*Cv1/100-Cv1)*2+H1);
	if(H1>2*Cv1)
	C1=(fabs(10*H1/100-H1)+2*Cv1);
	if(C1<C2 && C1<C3)
	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", C1);
	}
	}
	if(tarik=='H' && bojan=='P' && mirza=='P' || tarik=='P' && bojan=='H' && mirza=='P' || tarik=='P' && bojan=='P' && mirza=='H')
	{
	C1=2*P1+H1;
	C2=2*P2+H2;
	C3=2*P3+H3;
	if(C1<C2 && C1<C3)
	printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", C1);
	if(C2<C1 && C2<C3)
	printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", C2);
	if(C3<C1 && C3<C2)
	printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", C3);
	if(C2<C1 || C3<C1)
	{
	if(2*P1>H1)
	C1=(fabs(10*P1/100-P1)*2+H1);
	if(H1>2*P1)
	C1=(fabs(10*H1/100-H1)+2*P1);
	if(C1<C2 && C1<C3)
	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", C1);
	}
	}
	if(tarik=='P' && bojan=='P' && mirza=='C' || tarik=='P' && bojan=='C' && mirza=='P' || tarik=='C' && bojan=='P' && mirza=='P')
	{
	C1=2*P1+Cv1;
	C2=2*P2+Cv2;
	C3=2*P3+Cv3;
	if(C1<C2 && C1<C3)
	printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", C1);
	if(C2<C1 && C2<C3)
	printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", C2);
	if(C3<C1 && C3<C2)
	printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", C3);
	if(C2<C1 || C3<C1)
	{
	if(2*P1>Cv1)
	C1=(fabs(10*P1/100-P1)*2+Cv1);
	if(Cv1>2*P1)
	C1=(fabs(10*Cv1/100-Cv1)+2*P1);
	if(C1<C2 && C1<C3)
	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", C1);
	}
	}
	if(tarik=='C' && bojan=='C' && mirza=='P' || tarik=='P' && bojan=='C' && mirza=='C' || tarik=='C' && bojan=='P' && mirza=='C')
	{
	C1=2*Cv1+P1;
	C2=2*Cv2+P2;
	C3=2*Cv3+P3;
	if(C1<C2 && C1<C3)
	printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", C1);
	if(C2<C1 && C2<C3)
	printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", C2);
	if(C3<C1 && C3<C2)
	printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", C3);
	if(C2<C1 || C3<C1)
	{
	C1=(fabs(10*Cv1/100-Cv1)*2+P1);
	if(C1<C2 && C1<C3)
	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", C1);
	}
	}
		return 0;
}

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	