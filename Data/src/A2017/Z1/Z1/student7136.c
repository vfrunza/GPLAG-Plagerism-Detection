#include <stdio.h>
#define P1 6.80
#define H1 3.30
#define C1 5.00
#define P2 8.00
#define H2 3.00
#define C2 3.90
#define P3 5.30
#define H3 5.00
#define C3 6.00

int main() {
	char t,b,m,novi_red;
	float x,x1,x2,x3,y,y1,y2;
	printf("Unesite jelo za Tarika: ");
	scanf("%c",&t);
	scanf("%c",&novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c",&b);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c",&m);
	scanf("%c",&novi_red);
	if(t=='P' && b=='P' && m=='P'){
		x1=3*P1; x2=3*P2; x3=3*P3;
		y=3*P1-3*P1/10;
		if(x1<x2 && x1<x3){
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",x1);
		}
		else if(x2<x1 && x2<x3){
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",x2);
			if(y<x2){
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",y);
		}
			else 
			return 0;
		}
		else if(x3<x1 && x3<x2){
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",x3);
			if(y<x3){
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",y);
		}
			else 
			return 0;
		}
	}
	else if(t=='H' && b=='H'&& m=='H'){
		x1=3*H1; x2=3*H2; x3=3*H3;
		y=3*H1-3*H1/10;
		if(x1<x2 && x1<x3){
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",x1);
		}
		else if(x2<x1 && x2<x3){
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",x2);
			if(y<x2){
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",y);
		}
			else 
			return 0;
		}
		else if(x3<x1 && x3<x2){
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",x3);
			if(y<x3){
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",y);
		}
			else 
			return 0;
		}
	}
	else if(t=='C' && b=='C' && m=='C'){
		x1=3*C1; x2=3*C2; x3=3*C3;
		y=3*C1-3*C1/10;
		if(x1<x2 && x1<x3){
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",x1);
		}
		else if(x2<x1 && x2<x3){
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",x2);
			if(y<x2){
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",y);
		}
			else 
			return 0;
		}
		else if(x3<x1 && x3<x2){
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",x3);
			if(y<x3){
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",y);
		}
			else 
			return 0;
		}
	}
	else if((t=='P' && b=='H' && m=='H')||(t=='H' && b=='P' && m=='H')||(t=='H' && b=='H' && m=='P')){
		x1=P1+2*H1; x2=P2+2*H2; x3=P3+2*H3;
		y1=P1+2*H1-2*H1/10; y2=P1-P1/10+2*H1;
		if(x1<x2 && x1<x3){
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",x1);
		}
		else if(x2<x1 && x2<x3){
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",x2);
			if(y1<y2 && y1<x2){
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",y1);
		}
			else if(y2<y1 && y2<x2){
					printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",y2);
		}
			else 
			return 0;
			}
		else if(x3<x1 && x3<x2){
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",x3);
			if(y1<y2 && y1<x3){
					printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",y1);
		}
			else if(y2<y1 && y2<x3){
					printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",y2);
		}
			else 
			return 0;
		}
	}
	else if((t=='H' && b=='P' && m=='P')||(t=='P' && b=='H' && m=='P')||(t=='P' && b=='P' && m=='H')){
		x1=H1+2*P1; x2=H2+2*P2; x3=H3+2*P3;
		y1=H1+2*P1-2*P1/10; y2=H1-H1/10+2*P1;
		if(x1<x2 && x1<x3){
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",x1);
		}
		else if(x2<x1 && x2<x3){
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",x2);
			if(y1<y2 && y1<x2){
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",y1);
		}
			else if(y2<y1 && y2<x2){
					printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",y2);
		}
			else 
			return 0;
			}
		else if(x3<x1 && x3<x2){
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",x3);
			if(y1<y2 && y1<x3){
					printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",y1);
		}
			else if(y2<y1 && y2<x3){
					printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",y2);
		}
			else 
			return 0;
		}
	}
	else if((t=='H' && b=='C' && m=='C')||(t=='C' && b=='H' && m=='C')||(t=='C' && b=='C' && m=='H')){
		x1=H1+2*C1; x2=H2+2*C2; x3=H3+2*C3;
		y1=H1+2*C1-2*C1/10; y2=H1-H1/10+2*C1;
		if(x1<x2 && x1<x3){
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",x1);
		}
		else if(x2<x1 && x2<x3){
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",x2);
			if(y1<y2 && y1<x2){
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",y1);
		}
			else if(y2<y1 && y2<x2){
					printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",y2);
		}
			else 
			return 0;
			}
		else if(x3<x1 && x3<x2){
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",x3);
			if(y1<y2 && y1<x3){
					printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",y1);
		}
			else if(y2<y1 && y2<x3){
					printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",y2);
		}
			else 
			return 0;
		}
	}
	else if((t=='C' && b=='P' && m=='P')||(t=='P' && b=='C' && m=='P')||(t=='P' && b=='P' && m=='C')){
		x1=C1+2*P1; x2=C2+2*P2; x3=C3+2*P3;
		y1=C1+2*P1-2*P1/10; y2=C1-C1/10+2*P1;
			if(x1<x2 && x1<x3){
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",x1);
		}
		else if(x2<x1 && x2<x3){
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",x2);
			if(y1<y2 && y1<x2){
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",y1);
		}
			else if(y2<y1 && y2<x2){
					printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",y2);
		}
			else 
			return 0;
			}
		else if(x3<x1 && x3<x2){
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",x3);
			if(y1<y2 && y1<x3){
					printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",y1);
		}
			else if(y2<y1 && y2<x3){
					printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",y2);
		}
			else 
			return 0;
		}
	}
	else if((t=='C' && b=='H' && m=='H')||(t=='H' && b=='C' && m=='H')||(t=='H' && b=='H' && m=='C')){
		x1=C1+2*H1; x2=C2+2*H2; x3=C3+2*H3;
		y1=C1+2*H1-2*H1/10; y2=C1-C1/10+2*H1;
		if(x1<x2 && x1<x3){
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",x1);
		}
		else if(x2<x1 && x2<x3){
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",x2);
			if(y1<y2 && y1<x2){
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",y1);
		}
			else if(y2<y1 && y2<x2){
					printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",y2);
		}
			else 
			return 0;
			}
		else if(x3<x1 && x3<x2){
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",x3);
			if(y1<y2 && y1<x3){
					printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",y1);
		}
			else if(y2<y1 && y2<x3){
					printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",y2);
		}
			else 
			return 0;
		}
	}
	else if((t=='P' && b=='C' && m=='C')||(t=='C'&&b=='P'&&m=='C')||(t=='C'&&b=='C'&&m=='P')){
		x1=P1+2*C1; x2=P2+2*C2; x3=P3+2*C3;
		y1=P1+2*C1-2*C1/10; y2=P1-P1/10+2*C1;
			if(x1<x2 && x1<x3){
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",x1);
		}
		else if(x2<x1 && x2<x3){
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",x2);
			if(y1<y2 && y1<x2){
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",y1);
		}
			else if(y2<y1 && y2<x2){
					printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",y2);
		}
			else 
			return 0;
			}
		else if(x3<x1 && x3<x2){
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",x3);
			if(y1<y2 && y1<x3){
					printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",y1);
		}
			else if(y2<y1 && y2<x3){
					printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",y2);
		}
			else 
			return 0;
		}
	}
	else if((t=='P'&&b=='H'&&m=='C')||(t=='P'&&b=='C'&&m=='H')||(t=='H'&&b=='P'&&m=='C')||(t=='H'&&b=='C'&&m=='P')||(t=='C'&&b=='P'&&m=='H')||(t=='C'&&b=='H'&&m=='P')){
		x1=P1+H1+C1; x2=P2+H2+C2; x3=P3+H3+C3;
		y=P1-P1/10+H1+C1; y1=P1+H1-H1/10+C1; y2=P1+H1+C1-C1/10;
		if(x1<x2 && x1<x3){
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",x1);
		}
		else if(x2<x1 && x2<x3){
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",x2);
			if(y<y1 &&y<y2 && y<x2){
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",y);
		}
			else if(y1<y && y1<y2 && y1<x2){
					printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",y1);
		}
			else if(y2<y && y2<y1 && y2<x2){
					printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",y2);
		}
			else 
			return 0;
			}
		else if(x3<x1 && x3<x2){
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",x3);
			if(y<y1 && y<y2 && y<x3){
					printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",y);
		}
			else if(y1<y && y1<y2 && y1<x3){
					printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",y1);
		}
			else if(y2<y && y2<y1 && y2<x3){
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",y2);
			}
			else 
			return 0;
		}
	}
	
		else 
		return 0;
	}
	
