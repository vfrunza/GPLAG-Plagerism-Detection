#include <stdio.h>

int main()
{
	char T,B,M,novi_red;
	float P1,C1,H1,P2,C2,H2,P3,C3,H3,R1,R2,R3,R4;
	P1=6.80;
	P2=8.00;
	P3=5.30;
	H1=3.30;
	H2=3.00;
	H3=5.00;
	C1=5.00;
	C2=3.90;
	C3=6.00;
	printf("Unesite jelo za Tarika: ");
	scanf("%c",&T);
	scanf("%c",&novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c",&B);
	scanf("%c",&novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c",&M);
	
	scanf("%c",&novi_red);
	
	if(T=='P' && B=='P' && M=='P') {
		R1=P1+P1+P1;
		R2=P2+P2+P2;
		R3=P3+P3+P3;
		R4 = R1 - R1/10;
	}
			else if (T=='H' && B=='H' && M=='H') {
				R1=3*H1;
				R2=3*H2;
				R3=3*H3;
				R4 = R1 - R1/10;
			}
					else if (T=='C' && B=='C' && M=='C') {
						R1=C1+C1+C1;
						R2=C2+C2+C2;
						R3=C3+C3+C3;
						R4 = R1 - R1/10;
					}
					else if (T=='P' && B=='P' && M=='H') {
						R1=P1+P1+H1;
						R2=P2+P2+H2;
						R3=P3+P3+H3;
						R4 = 2*P1 - 2*P1/10 + H1;
					}
					else if (T=='P' && B=='P' &&  M=='C') {
						R1=P1+P1+C1;
						R2=P2+P2+C2;
						R3=P3+P3+C3;
						R4 = 2*P1 - 2*P1/10 + C1;
					}
					else if (T=='P' && B=='H' && M=='C') {
						R1=P1+H1+C1;
						R2=P2+H2+C2;
						R3=P3+H3+C3;
						R4 = P1 - P1/10 + H1 + C1;
					}
					else if (T=='C' && B=='C' && M=='P') {
					R1=C1+C1+P1;
					R2=C2+C2+P2;
					R3=C3+C3+P3;
					R4= 2*C1 - 2*C1/10 + P1;
					}
					else if (T=='C' && B=='C' && M=='H') {
						R1=C1+C1+H1;
						R2=C2+C2+H2;
						R3=C3+C3+H3;
						R4= 2*C1 - 2*C2/10 + H1;
					}
					else if(T=='H' && B=='H' && M=='P') {
						R1=H1+H1+P1;
						R2=H2+H2+P2;
						R3=H3+H3+P3;
						R4= 2*H1 + P1 - P1/10;
					}
					else if(T=='H' && B=='H' && M=='C') {
					R1=H1+H1+C1;
					R2=H2+H2+C2;
					R3=H3+H3+C3;
					R4= 2*H1 - 2*H1/10 + C1;
					}
					else if(T=='H' && B=='P' && M=='P') {
						R1=H1+P1+P1;
						R2=H2+P2+P2;
						R3=H3+P3+P3;
						R4= 2*P1 - 2*P1/10 + H1;
					}
					else if(T=='P' && B=='H' && M=='P') {
						R1=P1+H1+P1;
						R2=P2+H2+P2;
						R3=P3+H3+P3;
						R4= 2*P1 - 2*P1/10 + H1;
					}
					else if (T=='P' && B=='C' && M=='P') {
					R1=P1+C1+P1;
					R2=P2+C2+P2;
					R3=P3+C3+P3;
					R4= 2*P1 - 2*P1/10 + C1;
					}
					else if (T=='C' && B=='P' && M=='P') {
						R1=C1+P1+P1;
						R2=C2+P2+P2;
						R3=C3+P3+P3;
						R4= 2*P1 - 2+P1/10 + C1;
					}
					else if (T=='H' && B=='P' && M=='C'){
						R1=H1+P1+C1;
						R2=H2+P2+C2;
						R3=H3+P3+C3;
						R4 = P1 - P1/10 + H1 + C1;
					}
					else if (T=='C' && B=='P' && M=='H') {
						R1=C1+P1+H1;
						R2=C2+P2+H2;
						R3=C3+P3+H3;
						R4 = P1 - P1/10 + H1 + C1;
					}
					else if (T=='C' && B=='H' && M=='P') {
						R1=C1+H1+P1;
						R2=C2+H2+P2;
						R3=C3+H3+P3;
						R4 = P1 - P1/10 + H1 + C1;
					}
					else if(T=='H' && B=='C' && M=='P') {
						R1=H1+C1+P1;
						R2=H2+C2+P2;
						R3=H3+C3+P3;
						R4 = P1 - P1/10 + H1 + C1;
					}
					else if (T=='P' && B=='C' && M=='H') {
						R1=P1+C1+H1;
						R2=P2+C2+H2;
						R3=P3+C3+H3;
						R4 = P1 - P1/10 + H1 + C1;
					}
					else if(T=='P' && B=='C' && M=='C') {
						R1=P1+C1+C1;
						R2=P2+C2+C2;
						R3=P3+C3+C3;
						R4 = 2*C1 - 2*C1/10 + P1;
					}
					else if (T=='C' && B=='P' && M=='C') {
					R1=C1+P1+C1;
					R2=C2+P2+C2;
					R3=C3+P3+C3;
					R4 = 2*C1 - 2*C1/10 + P1;
					}
					else if (T=='H' && B=='C' && M=='C') {
						R1=H1+C1+C1;
						R2=H2+C2+C2;
						R3=H3+C3+C3;
						R4 = 2*C1 - 2*C1/10 + H1;
					}
					else if (T=='C' && B=='H' && M=='C') {
					R1=C1+H1+C1;
					R2=C2+H2+C2;
					R3=C3+H3+C3;
					R4 = 2*C1 - 2*C1/10 + H1;
					}
					else if(T=='H' && B=='P' && M=='H') {
						R1=H1+P1+H1;
						R2=H2+P2+H2;
						R3=H3+P3+H3;
						R4 = 2*H1 + P1 - P1/10;
					}
					else if (T=='P' && B=='H' && M=='H') {
						R1=P1+H1+H1;
						R2=P2+H2+H2;
						R3=P3+H3+H3;
						R4 = 2*H1 + P1 - P1/10;
					}
					else if (T=='C' && B=='H' && M=='H') {
					R1=C1+H1+H1;
					R2=C2+H2+H2;
					R3=C3+H3+H3;
					R4 = 2*H1 + C1 - 2*H1/10;
					} 
					else {
						R1=H1+C1+H1;
						R2=H2+C2+H2;
						R3=H3+C3+H3;
						R4 = 2*H1 + C1 - 2*H1/10;
					}
					
					if(R1<R2 && R1<R3)
					{ 
					printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",R1);
					}
					else if(R2<R1 && R2<R3)
					{
					printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",R2);
					if(R4<R2) {
						printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",R4);
					}
					}
					else 
					{
						printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",R3);
						if(R4<R3)
						{
							printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",R4);
						}
					}
					
				
					return 0;
}
				