#include <stdio.h>
#define HAM_R 3.30
#define HAM_F 3.00
#define HAM_B 5.00
#define CEV_R 5.00
#define CEV_F 3.90
#define CEV_B 6.00
#define PIZ_R 6.80
#define PIZ_F 8.00
#define PIZ_B 5.30
int main() {
	char tarik,bojan,mirza,novi_red,pizza,hamburger,cevapi;
	float Restoran,Fast,Bistro,Popust;
	printf("Unesite jelo za Tarika: ");
	scanf ("%c",&tarik);
	scanf ("%c",&novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf ("%c",&bojan);
	scanf ("%c",&novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf ("%c",&mirza);
	scanf ("%c",&novi_red);
	pizza=0; hamburger=0; cevapi=0;
		if (tarik=='P') pizza++;
		if (bojan=='P') pizza++;
		if (mirza=='P') pizza++;
		if (bojan=='H') hamburger++;
		if (tarik=='H') hamburger++;
		if (mirza=='H') hamburger++;
		if (mirza=='C') cevapi++;
		if (tarik=='C') cevapi++;
		if (bojan=='C') cevapi++;
	Restoran=pizza*PIZ_R+hamburger*HAM_R+cevapi*CEV_R; 
	
	Fast=pizza*PIZ_F+hamburger*HAM_F+cevapi*CEV_F; 
	
	Bistro=pizza*PIZ_B+hamburger*HAM_B+cevapi*CEV_B;
	
	if (pizza==3) Popust=(PIZ_R*3)-((PIZ_R*3)/10);
	else if (hamburger==3) Popust=(HAM_R*3)-((HAM_R*3)/10);
	else if (cevapi==3) Popust=(CEV_R*3)-((CEV_R*3)/10);
	else if (pizza==1 && hamburger==1 && cevapi==1) Popust=(PIZ_R-(PIZ_R/10))+HAM_R+CEV_R;
	else if (pizza==2 && hamburger==1) Popust=(PIZ_R*2-((PIZ_R*2)/10))+HAM_R;
	else if (pizza==2 && cevapi==1) Popust=(PIZ_R*2-((PIZ_R*2)/10))+CEV_R;
	else if (hamburger==2 && cevapi==1) Popust=(HAM_R*2-((HAM_R*2)/10))+CEV_R;
	else if (hamburger==2 && pizza==1) Popust=(HAM_R*2-((HAM_R*2)/10))+PIZ_R;
	else if (cevapi==2 && pizza==1) Popust=(CEV_R*2-((CEV_R*2)/10))+PIZ_R;
	else if (cevapi==2 && hamburger==1) Popust=(CEV_R*2-((CEV_R*2)/10))+HAM_R;
	if (Fast<Restoran && Fast<Bistro){
		printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",Fast);
		if (Popust<Fast) printf ("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",Popust);
	}
	else if (Bistro<Fast && Bistro<Restoran){
		printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",Bistro);
		if (Popust<Bistro) printf ("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",Popust);
	}
	else if (Restoran<Fast && Restoran<Bistro){
		
		printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",Restoran);
	}
	
	return 0;
}
