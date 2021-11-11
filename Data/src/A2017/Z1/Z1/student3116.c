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

printf("Unesite jelo za Tarika: ");
scanf ("%c", &t);
scanf ("%c", &novi_red);
printf ("Unesite jelo za Bojana: ");
scanf ("%c", &b);
scanf ("%c",&novi_red);
printf ("Unesite jelo za Mirzu: ");
scanf ("%c", &m);
scanf ("%c",&novi_red);


	if (t=='H' && b=='H' && m=='H') {
		if (H1*3<H2*3 && H1*3<H3*3)
			printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",H1*3);
		else if (H2*3<H1*3 && H2*3<H3*3) 
			printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",H2*3);
		else if (H3*3<H1*3 && H3*3<H2*3)  
			printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",H3*3);
		if ((H1*0.9*3<H2*3) && (H1*0.9*3<H3*3))
			printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",H1*0.9*3); }
			
	if (t=='P' && b=='P' && m=='P') {
		if (P1*3<P2*3 && P1*3<P3*3)
			printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",P1*3);
		else if (P2*3<P1*3 && P2*3<P3*3) 
			printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",P2*3);
		else if (P3*3<P1*3 && P3*3<P1*3) 
			printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",P3*3); 
		if ((P1*0.9*3<P2*3) && (P1*0.9*3<P3*3))
			printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",P1*0.9*3); } 	
			
	if (t=='C' && b=='C' && m=='C') {
		if (C1*3<C2*3 && C1*3<C3*3)
			printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",C1*3);
		else if (C2*3<C1*3 && C2*3<C3*3) 
			printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",C2*3);
		else if (C3*3<C1*3 && C3*3<C2*3)
			printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",C3*3);
		if ((C1*0.9*3<C2*3) && (C1*0.9*3<C3*3))
			printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",C1*0.9*3); }
			
	
			
	if ((t=='P' && b=='H' && m=='C')||(t=='P' && b=='C' && m=='H')||(t=='H' && b=='P' && m=='C')||(t=='H' && b=='C' && m=='P')||(t=='C' && b=='P' && m=='H')||(t=='C' && b=='H' && m=='P')) {
		if (((P1+H1+C1)<(P2+H2+C2))&&((P1+H1+C1)<(P3+H3+C3))) {
			printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",P1+H1+C1);
			return 0; }
		else if (((P2+H2+C2)<(P1+H1+C1))&&((P2+H2+C2)<(P3+H3+C3)))
			printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",P2+H2+C2);
		else if (((P3+H3+C3)<(P1+H1+C1))&&((P3+H3+C3)<(P2+H2+C2)))
			printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",P3+H3+C3); 
			
	if (P1+H1+C1*0.9<P2+H2+C2 && P1+H1+C1*0.9<P3+H3+C3 && P1+H1+C1*0.9<P1+C1+H1*0.9 && P1+H1*0.9+C1<P1*0.9+C1+H1)
		printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",P1+C1*0.9+H1);
	else if (P1*0.9+H1+C1<P2+C2+H2 && P1*0.9+H1+C1<P3+H3+C3 && P1*0.9+H1+C1<P1+C1*0.9+H1 && P1*0.9+H1+C1<P1+C1+H1*0.9)
		printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",P1*0.9+C1+H1);
	else if (P1+H1*0.9+C1<P2+H2+C2 && P1+H1*0.9+C1<P3+H3+C3 && P1+H1*0.9+C1<P1+C1*0.9+H1 && P1+H1*0.9+C1<P1*0.9+C1+H1)
		printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",P1+C1+H1*0.9); }
			
			
			
	if ((t=='P' && b=='P' && m=='C')||(t=='P' && b=='C' && m=='P')||(t=='C' && b=='P' && m=='P')) {
		if (((P1*2+C1)<(P2*2+C2))&&((P1*2+C1)<(P3*2+C3))) {
			printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",P1*2+C1);
			return 0; }
		else if (((P2*2+C2)<(P1*2+C1))&&((P2*2+C2)<(P3*2+C3)))
			printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",P2*2+C2);
		else if (((P3*2+C3)<(P1*2+C1))&&((P3*2+C3)<(P2*2+C2)))
			printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",P3*2+C3);
			
		if (P1*0.9*2+C1<P2*2+C2 && P1*0.9*2+C1<P3*2+C3 && P1*0.9*2+C1<P1*2+C1*0.9)
			printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",P1*0.9*2+C1);
		else if (P1*2+C1*0.9<P2*2+C2 && P1*2+C1*0.9<P3*2+C3 && P1*2+C1*0.9<P1*2*0.9+C1)
			printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",P1*2+C1*0.9); }
			
		
		
	if ((t=='C' && b=='C' && m=='P')||(t=='P' && b=='C' && m=='C')||(t=='C' && b=='P' && m=='C')){
		if (((C1*2+P1)<(C2*2+P2))&&((C1*2+P1)<(C3*2+P3))) {
			printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",C1*2+P1);
			return 0; }
		else if (((C2*2+P2)<(C1*2+P1))&&((C2*2+P2)<(C3*2+P3)))
			printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",C2*2+P2);
		else if (((C3*2+P3)<(C1*2+P1))&&((C3*2+P3)<(C2*2+P2)))
			printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",C3*2+P3);
		
		if (C1*0.9*2+P1<C2*2+P2 && C1*0.9*2+P1<C3*2+P3 && C1*0.9*2+P1<C1*2+P1*0.9)
			printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",C1*0.9*2+P1);
		else if (C1*2+P1*0.9<C2*2+P2 && C1*2+P1*0.9<C3*2+P3 && C1*2+P1*0.9<C1*2*0.9+P1)
			printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",C1*2+P1*0.9); }	
		
		
			
	if ((t=='P' && b=='P' && m=='H')||(t=='P' && b=='H' && m=='P')||(t=='H' && b=='P' && m=='P')){
		if (((P1*2+H1)<(P2*2+H2))&&((P1*2+H1)<(P3*2+H3))) {
			printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",P1*2+H1);
			return 0; }
		else if (((P2*2+H2)<(P1*2+H1))&&((P2*2+H2)<(P3*2+H3)))
			printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",P2*2+H2);
		else if (((P3*2+H3)<(P1*2+H1))&&((P3*2+H3)<(P2*2+H2)))
			printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",P3*2+H3);
			
		if (P1*0.9*2+H1<P2*2+H2 && P1*0.9*2+H1<P3*2+H3 && P1*0.9*2+H1<P1*2+H1*0.9)
			printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",P1*0.9*2+H1);
		else if (P1*2+H1*0.9<P2*2+H2 && P1*2+H1*0.9<P3*2+H3 && P1*2+H1*0.9<P1*2*0.9+H1)
			printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",P1*2+H1*0.9); }
		
	
			
	if ((t=='H' && b=='H' && m=='P')||(t=='P' && b=='H' && m=='H')||(t=='H' && b=='P' && m=='H')){
		if (((H1*2+P1)<(H2*2+P2))&&((H1*2+P1)<(H3*2+P3))) {
			printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",H1*2+P1);
			return 0; }
		else if (((H2*2+P2)<(H1*2+P1))&&((H2*2+P2)<(H3*2+P3)))
			printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",H2*2+P2);
		else if (((H3*2+P3)<(H1*2+P1))&&((H3*2+P3)<(H2*2+P2)))
			printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",H3*2+P3); 
			
		if (H1*0.9*2+P1<H2*2+P2 && H1*0.9*2+P1<H3*2+P3 && H1*0.9*2+P1<H1*2+P1*0.9) 
			printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",H1*0.9*2+P1);
		else if (H1*2+P1*0.9<H2*2+P2 && H1*2+P1*0.9<H3*2+P3 && H1*2+P1*0.9<H1*2*0.9+P1)
			printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",H1*2+P1*0.9); }
			
	
			
	if ((t=='C' && b=='C' && m=='H')||(t=='C' && b=='H' && m=='C')||(t=='H' && b=='C' && m=='C')){
		if (((C1*2+H1)<(C2*2+H2))&&((C1*2+H1)<(C3*2+H3))) {
			printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",C1*2+H1);
			return 0; }
		else if (((C2*2+H2)<(C1*2+H1))&&((C2*2+H2)<(C3*2+H3)))
			printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",C2*2+H2);
		else if (((C3*2+H3)<(C1*2+H1))&&((C3*2+H3)<(C2*2+H2)))
			printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",C3*2+H3); 
			
		if (C1*0.9*2+H1<C2*2+H2 && C1*0.9*2+H1<C3*2+H3 && C1*0.9*2+H1<C1*2+H1*0.9) 
			printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",C1*0.9*2+H1);
		else if (C1*2+H1*0.9<C2*2+H2 && C1*2+H1*0.9<C3*2+H3 && C1*2+H1*0.9<C1*2*0.9+H1)
			printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",C1*2+H1*0.9); }
			
			
			
	if ((t=='H' && b=='H' && m=='C')||(t=='C' && b=='H' && m=='H')||(t=='H' && b=='C' && m=='H')){
		if (((H1*2+C1)<(H2*2+C2))&&((H1*2+C1)<(H3*2+C3))) {
			printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",H1*2+C1);
			return 0; }
		else if (((H2*2+C2)<(H1*2+C1))&&((H2*2+C2)<(H3*2+C3)))
			printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",H2*2+C2);
		else if (((H3*2+C3)<(H1*2+C1))&&((H3*2+C3)<(H2*2+C2)))
			printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",H3*2+C3); 
			
		if (H1*0.9*2+C1<H2*2+C2 && H1*0.9*2+C1<H3*2+C3 && H1*0.9*2+C1<H1*2+C1*0.9) 
			printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",H1*0.9*2+C1);
		else if (H1*2+C1*0.9<H2*2+C2 && H1*2+C1*0.9<H3*2+C3 && H1*2+C1*0.9<H1*2*0.9+C1)
			printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",H1*2+C1*0.9); }
			
	return 0;
}
