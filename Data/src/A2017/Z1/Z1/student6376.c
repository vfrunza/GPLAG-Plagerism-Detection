#include <stdio.h>
#include <math.h>
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
	char T,B,M,novi_red;
	float R1,R2,R3,R4;
	printf("Unesite jelo za Tarika: ");
	scanf("%c",&T);
	scanf("%c",&novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c",&B);
	scanf("%c",&novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c",&M);
	scanf("%c",&novi_red);
	if (T=='P' && B=='P' && M=='P') {
		R1=3*P1;
		R2=3*P2;
		R3=3*P3;
		if (R1<R2 && R1<R3) {
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",R1);
		}
		if (R2<R1 && R2<R3) {
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",R2);
		}
		if (R3<R2 && R3<R1) {
			printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",R3);
		}
		R4=round((P1-(P1*0.1))*3*100) / 100;
		if (((R2<R1 && R2<R3) || (R3<R2 && R3<R1)) && R4<R3 && R4<R2) {
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",R4);
		}
	}
		if (T=='C' && B=='C' && M=='C') {
		R1=3*C1;
		R2=3*C2;
		R3=3*C3;
		if (R1<R2 && R1<R3) {
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",R1);
		}
		if (R2<R1 && R2<R3) {
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",R2);
		}
		if (R3<R2 && R3<R1) {
			printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",R3);
		}
		R4=round((C1-(C1*0.1))*3*100) / 100;
		if (((R2<R1 && R2<R3) || (R3<R2 && R3<R1)) && R4<R3 && R4<R2) {
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",R4);
		}
	}
		if (T=='H' && B=='H' && M=='H') {
		R1=3*H1;
		R2=3*H2;
		R3=3*H3;
		if (R1<R2 && R1<R3) {
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",R1);
		}
		if (R2<R1 && R2<R3) {
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",R2);
		}
		if (R3<R2 && R3<R1) {
			printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",R3);
		}
		R4=round ((H1-(H1*0.1))*3*100) / 100;
		if (((R2<R1 && R2<R3) || (R3<R2 && R3<R1)) && R4<R3 && R4<R2) {
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",R4);
		}
		}
		if (T=='P' && B=='H' && M=='C') {
		R1=P1+H1+C1;
		R2=P2+H2+C2;
		R3=P3+H3+C3;
		if (R1<R2 && R1<R3) {
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",R1);
		}
		if (R2<R1 && R2<R3) {
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",R2);
		}
		if (R3<R2 && R3<R1) {
			printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",R3);
		}
		R4=round((R1-(P1*0.1))*100)/100;
			if (((R2<R1 && R2<R3) || (R3<R2 && R3<R1)) && R4<R3 && R4<R2) {
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",R4);
		}
	}
	if (T=='P' && B=='C' && M=='H') {
		R1=P1+H1+C1;
		R2=P2+H2+C2;
		R3=P3+H3+C3;
		if (R1<R2 && R1<R3) {
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",R1);
		}
		if (R2<R1 && R2<R3) {
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",R2);
		}
		if (R3<R2 && R3<R1) {
			printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",R3);
		}
			R4=round((R1-(P1*0.1))*100)/100;
			if (((R2<R1 && R2<R3) || (R3<R2 && R3<R1)) && R4<R3 && R4<R2) {
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",R4);
		}
	}
	if (T=='P' && B=='P' && M=='H') {
		R1=P1+P1+H1;
		R2=P2+P2+H2;
		R3=P3+P3+H3;
		if (R1<R2 && R1<R3) {
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",R1);
		}
		if (R2<R1 && R2<R3) {
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",R2);
		}
		if (R3<R2 && R3<R1) {
			printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",R3);
		}
			R4=round((R1-(2*(P1*0.1)))*100)/100;
			if (((R2<R1 && R2<R3) || (R3<R2 && R3<R1)) && R4<R3 && R4<R2) {
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",R4);
		}
	}
	if (T=='P' && B=='H' && M=='P') {
		R1=P1+P1+H1;
		R2=P2+P2+H2;
		R3=P3+P3+H3;
		if (R1<R2 && R1<R3) {
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",R1);
		}
		if (R2<R1 && R2<R3) {
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",R2);
		}
		if (R3<R2 && R3<R1) {
			printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",R3);
		}
			R4=round((R1-(2*(P1*0.1)))*100)/100;
			if (((R2<R1 && R2<R3) || (R3<R2 && R3<R1)) && R4<R3 && R4<R2) {
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",R4);
		}
	}
		if (T=='P' && B=='H' && M=='H') {
		R1=P1+H1+H1;
		R2=P2+H2+H2;
		R3=P3+H3+H3;
		if (R1<R2 && R1<R3) {
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",R1);
		}
		if (R2<R1 && R2<R3) {
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",R2);
		}
		if (R3<R2 && R3<R1) {
			printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",R3);
		}
			R4=round((R1-(2*(H1*0.1)))*100)/100;
			if (((R2<R1 && R2<R3) || (R3<R2 && R3<R1)) && R4<R3 && R4<R2) {
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",R4);
		}
	}
	if (T=='P' && B=='P' && M=='C') {
		R1=P1+P1+C1;
		R2=P2+P2+C2;
		R3=P3+P3+C3;
		if (R1<R2 && R1<R3) {
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",R1);
		}
		if (R2<R1 && R2<R3) {
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",R2);
		}
		if (R3<R2 && R3<R1) {
			printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",R3);
		}
			R4=round((R1-(2*(P1*0.1)))*100)/100;
			if (((R2<R1 && R2<R3) || (R3<R2 && R3<R1)) && R4<R3 && R4<R2) {
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",R4);
		}
	}
	if (T=='P' && B=='C' && M=='P') {
		R1=P1+P1+C1;
		R2=P2+P2+C2;
		R3=P3+P3+C3;
		if (R1<R2 && R1<R3) {
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",R1);
		}
		if (R2<R1 && R2<R3) {
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",R2);
		}
		if (R3<R2 && R3<R1) {
			printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",R3);
		}
			R4=round((R1-(2*(P1*0.1)))*100)/100;
			if (((R2<R1 && R2<R3) || (R3<R2 && R3<R1)) && R4<R3 && R4<R2) {
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",R4);
		}
	}
	if (T=='P' && B=='C' && M=='C') {
		R1=P1+C1+C1;
		R2=P2+C2+C2;
		R3=P3+C3+C3;
		if (R1<R2 && R1<R3) {
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",R1);
		}
		if (R2<R1 && R2<R3) {
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",R2);
		}
		if (R3<R2 && R3<R1) {
			printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",R3);
		}
			R4=round((R1-(P1*0.1))*100)/100;
			if (((R2<R1 && R2<R3) || (R3<R2 && R3<R1)) && R4<R3 && R4<R2) {
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",R4);
		}
	}
	if (T=='H' && B=='H' && M=='P') {
		R1=H1+H1+P1;
		R2=H2+H2+P2;
		R3=H3+H3+P3;
		if (R1<R2 && R1<R3) {
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",R1);
		}
		if (R2<R1 && R2<R3) {
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",R2);
		}
		if (R3<R2 && R3<R1) {
			printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",R3);
		}
			R4=round((R1-(2*(H1*0.1)))*100)/100;
			if (((R2<R1 && R2<R3) || (R3<R2 && R3<R1)) && R4<R3 && R4<R2) {
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",R4);
		}
	}
		if (T=='H' && B=='P' && M=='P') {
		R1=H1+P1+P1;
		R2=H2+P2+P2;
		R3=H3+P3+P3;
		if (R1<R2 && R1<R3) {
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",R1);
		}
		if (R2<R1 && R2<R3) {
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",R2);
		}
		if (R3<R2 && R3<R1) {
			printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",R3);
		}
			R4=round((R1-(2*(P1*0.1)))*100)/100;
			if (((R2<R1 && R2<R3) || (R3<R2 && R3<R1)) && R4<R3 && R4<R2) {
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",R4);
		}
	}
	if (T=='H' && B=='P' && M=='H') {
		R1=H1+H1+P1;
		R2=H2+H2+P2;
		R3=H3+H3+P3;
		if (R1<R2 && R1<R3) {
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",R1);
		}
		if (R2<R1 && R2<R3) {
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",R2);
		}
		if (R3<R2 && R3<R1) {
			printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",R3);
		}
			R4=round((R1-(2*(H1*0.1)))*100)/100;
			if (((R2<R1 && R2<R3) || (R3<R2 && R3<R1)) && R4<R3 && R4<R2) {
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",R4);
		}
	}
	if (T=='H' && B=='H' && M=='C') {
		R1=H1+H1+C1;
		R2=H2+H2+C2;
		R3=H3+H3+C3;
		if (R1<R2 && R1<R3) {
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",R1);
		}
		if (R2<R1 && R2<R3) {
			printf("Najjeftiniji je Fast-food\"Trovac\" (%.2f KM).",R2);
		}
		if (R3<R2 && R3<R1) {
			printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",R3);
		}
			R4=round((R1-(2*(H1*0.1)))*100)/100;
			if (((R2<R1 && R2<R3) || (R3<R2 && R3<R1)) && R4<R3 && R4<R2) {
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",R4);
		}
	}
	if (T=='H' && B=='C' && M=='C') {
		R1=H1+C1+C1;
		R2=H2+C2+C2;
		R3=H3+C3+C3;
		if (R1<R2 && R1<R3) {
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",R1);
		}
		if (R2<R1 && R2<R3) {
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",R2);
		}
		if (R3<R2 && R3<R1) {
			printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",R3);
		}
			R4=round((R1-(2*(C1*0.1)))*100)/100;
			if (((R2<R1 && R2<R3) || (R3<R2 && R3<R1)) && R4<R3 && R4<R2) {
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",R4);
		}
	}
		if (T=='H' && B=='C' && M=='H') {
		R1=H1+H1+C1;
		R2=H2+H2+C2;
		R3=H3+H3+C3;
		if (R1<R2 && R1<R3) {
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",R1);
		}
		if (R2<R1 && R2<R3) {
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",R2);
		}
		if (R3<R2 && R3<R1) {
			printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",R3);
		}
			R4=round((R1-(2*(H1*0.1)))*100)/100;
			if (((R2<R1 && R2<R3) || (R3<R2 && R3<R1)) && R4<R3 && R4<R2) {
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",R4);
		}
	}
		if (T=='H' && B=='P' && M=='C') {
		R1=H1+P1+C1;
		R2=H2+P2+C2;
		R3=H3+P3+C3;
		if (R1<R2 && R1<R3) {
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",R1);
		}
		if (R2<R1 && R2<R3) {
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",R2);
		}
		if (R3<R2 && R3<R1) {
			printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",R3);
		}
			R4=round((R1-(P1*0.1))*100)/100;
			if (((R2<R1 && R2<R3) || (R3<R2 && R3<R1)) && R4<R3 && R4<R2) {
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",R4);
		}
	}
	if (T=='H' && B=='C' && M=='P') {
		R1=H1+C1+P1;
		R2=H2+C2+P2;
		R3=H3+C3+P3;
		if (R1<R2 && R1<R3) {
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",R1);
		}
		if (R2<R1 && R2<R3) {
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",R2);
		}
		if (R3<R2 && R3<R1) {
			printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",R3);
		}
			R4=round((R1-(P1*0.1))*100)/100;
			if (((R2<R1 && R2<R3) || (R3<R2 && R3<R1)) && R4<R3 && R4<R2) {
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",R4);
		}
	}
	if (T=='C' && B=='C' && M=='P') {
		R1=C1+C1+P1;
		R2=C2+C2+P2;
		R3=C3+C3+P3;
		if (R1<R2 && R1<R3) {
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",R1);
		}
		if (R2<R1 && R2<R3) {
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",R2);
		}
		if (R3<R2 && R3<R1) {
			printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",R3);
		}
			R4=round((R1-(2*(C1*0.1)))*100)/100;
			if (((R2<R1 && R2<R3) || (R3<R2 && R3<R1)) && R4<R3 && R4<R2) {
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",R4);
		}
	}
		if (T=='C' && B=='P' && M=='C') {
		R1=C1+C1+P1;
		R2=C2+C2+P2;
		R3=C3+C3+P3;
		if (R1<R2 && R1<R3) {
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",R1);
		}
		if (R2<R1 && R2<R3) {
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",R2);
		}
		if (R3<R2 && R3<R1) {
			printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",R3);
		}
			R4=round((R1-(2*(C1*0.1)))*100)/100;
			if (((R2<R1 && R2<R3) || (R3<R2 && R3<R1)) && R4<R3 && R4<R2) {
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",R4);
		}
	}
		if (T=='C' && B=='P' && M=='P') {
		R1=C1+P1+P1;
		R2=C2+P2+P2;
		R3=C3+P3+P3;
		if (R1<R2 && R1<R3) {
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",R1);
		}
		if (R2<R1 && R2<R3) {
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",R2);
		}
		if (R3<R2 && R3<R1) {
			printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",R3);
		}
		R4=round((R1-(2*(P1*0.1)))*100)/100;
			if (((R2<R1 && R2<R3) || (R3<R2 && R3<R1)) && R4<R3 && R4<R2) {
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",R4);
		}
	}
		if (T=='C' && B=='C' && M=='H') {
		R1=C1+C1+H1;
		R2=C2+C2+H2;
		R3=C3+C3+H3;
		if (R1<R2 && R1<R3) {
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",R1);
		}
		if (R2<R1 && R2<R3) {
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",R2);
		}
		if (R3<R2 && R3<R1) {
			printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",R3);
		}
		R4=round((R1-(2*(C1*0.1)))*100)/100;
			if (((R2<R1 && R2<R3) || (R3<R2 && R3<R1)) && R4<R3 && R4<R2) {
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",R4);
		}
	}
	if (T=='C' && B=='H' && M=='C') {
		R1=C1+C1+H1;
		R2=C2+C2+H2;
		R3=C3+C3+H3;
		if (R1<R2 && R1<R3) {
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",R1);
		}
		if (R2<R1 && R2<R3) {
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",R2);
		}
		if (R3<R2 && R3<R1) {
			printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",R3);
		}
		R4=round((R1-(2*(C1*0.1)))*100)/100;
			if (((R2<R1 && R2<R3) || (R3<R2 && R3<R1)) && R4<R3 && R4<R2) {
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",R4);
		}
	}
	if (T=='C' && B=='H' && M=='H') {
		R1=C1+H1+H1;
		R2=C2+H2+H2;
		R3=C3+H3+H3;
		if (R1<R2 && R1<R3) {
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",R1);
		}
		if (R2<R1 && R2<R3) {
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",R2);
		}
		if (R3<R2 && R3<R1) {
			printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",R3);
		}
		R4=round((R1-(2*(H1*0.1)))*100)/100;
			if (((R2<R1 && R2<R3) || (R3<R2 && R3<R1)) && R4<R3 && R4<R2) {
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",R4);
		}
	}
	if (T=='C' && B=='P' && M=='H') {
		R1=C1+P1+H1;
		R2=C2+P2+H2;
		R3=C3+P3+H3;
		if (R1<R2 && R1<R3) {
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",R1);
		}
		if (R2<R1 && R2<R3) {
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",R2);
		}
		if (R3<R2 && R3<R1) {
			printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",R3);
		}
		R4=round((R1-(P1*0.1))*100)/100;
			if (((R2<R1 && R2<R3) || (R3<R2 && R3<R1)) && R4<R3 && R4<R2) {
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",R4);
		}
	}
		if (T=='C' && B=='H' && M=='P') {
		R1=C1+P1+H1;
		R2=C2+P2+H2;
		R3=C3+P3+H3;
		if (R1<R2 && R1<R3) {
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",R1);
		}
		if (R2<R1 && R2<R3) {
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",R2);
		}
		if (R3<R2 && R3<R1) {
			printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",R3);
		}
		R4=round((R1-(P1*0.1))*100)/100;
			if (((R2<R1 && R2<R3) || (R3<R2 && R3<R1)) && R4<R3 && R4<R2) {
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",R4);
		}
	}
	return 0;
}
