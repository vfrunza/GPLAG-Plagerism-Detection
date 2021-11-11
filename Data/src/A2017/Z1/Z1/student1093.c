#include <stdio.h>
#define p1 6.80
#define h1 3.30
#define c1 5.00
#define p2 8.00
#define h2 3.00
#define c2 3.90
#define p3 5.30
#define h3 5.00
#define c3 6.00
int main() {
	char t,b,m,novi_red;
	double popust;
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &t);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &b);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &m);
	scanf("%c", &novi_red);
 	if (t=='P' && b=='P' && m=='P' && p1<p2 && p1<p3){
	printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", p1+p1+p1);
	return 0;}
	else if (t=='P' && b=='P' && m=='P' && p2<p1 && p2<p3)
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", p2+p2+p2);
	else if (t=='P' && b=='P' && m=='P' && p3<p1 && p3<p2)
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", p3+p3+p3);
	else if (t=='C' && b=='C' && m=='C' && c1<c2 && c1<c3){
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", c1+c2+c3);
		return 0;}
	else if (t=='C' && b=='C' && m=='C' && c2<c1 && c2<c3)
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", c2+c2+c2);
	else if (t=='C' && b=='C' && m=='C' && c3<c1 && c3<c2)
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", c3+c3+c3);
	else if (t=='H' && b=='H' && m=='H' && h1<h2 && h1<h3){
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", h1+h1+h1);
		return 0;}
	else if (t=='H' && b=='H' && m=='H' && h2<h1 && h2<h3)
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", h2+h2+h2);
	else if (t=='H' && b=='H' && m=='H' && h3<h1 && h3<h2)
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", h3+h3+h3);
	else if (((t=='P' && b=='P' && m=='C') || (t=='P' && b=='C' && m=='P') || (t=='C' && b=='P' && m=='P')) && (2*p1+c1<2*p2+c2 && 2*p1+c1<2*p3+c3)){
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", p1+p1+c1);
		return 0;}
	else if (((t=='P' && b=='P' && m=='C') || (t=='P' && b=='C' && m=='P') || (t=='C' && b=='P' && m=='P')) && (2*p2+c2<2*p1+c1 && 2*p2+c2<2*p3+c3))
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", p2+p2+c2);
	else if (((t=='P' && b=='P' && m=='C') || (t=='P' && b=='C' && m=='P') || (t=='C' && b=='P' && m=='P')) && (2*p3+c3<2*p2+c2 && 2*p3+c3<2*p1+c1))
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", p3+p3+c3);
	else if (((t=='C' && b=='C' && m=='P') || (t=='C' && b=='P' && m=='C') || (t=='P' && b=='C' && m=='C')) && (2*c1+p1<2*c2+p2 && 2*c1+p1<2*c3+p3)){
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", c1+c1+p1);
		return 0;}
	else if (((t=='C' && b=='C' && m=='P') || (t=='C' && b=='P' && m=='C') || (t=='P' && b=='C' && m=='C')) && (2*c2+p2<2*c1+p1 && 2*c2+p2<2*c3+p3))
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", c2+c2+p2);
	else if (((t=='C' && b=='C' && m=='P') || (t=='C' && b=='P' && m=='C') || (t=='P' && b=='C' && m=='C')) && (2*c3+p3<2*c2+p2 && 2*c3+p3<2*c1+p1))
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", c3+c3+p3);
	else if (((t=='P' && b=='P' && m=='H') || (t=='P' && b=='H' && m=='P') || (t=='H' && b=='P' && m=='P')) && (2*p1+h1<2*p2+h2 && 2*p1+h1<2*p3+h3)){
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", p1+p1+h1);
		return 0;}
	else if (((t=='P' && b=='P' && m=='H') || (t=='P' && b=='H' && m=='P') || (t=='H' && b=='P' && m=='P')) && (2*p2+h2<2*p1+h1 && 2*p2+h2<2*p3+h3))
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", p2+p2+h2);
	else if (((t=='P' && b=='P' && m=='H') || (t=='P' && b=='H' && m=='P') || (t=='H' && b=='P' && m=='P')) && (2*p3+h3<2*p2+h2 && 2*p3+h3<2*p1+h1))
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", p3+p3+h3);
	else if (((t=='P' && b=='H' && m=='H') || (t=='H' && b=='P' && m=='H') || (t=='H' && b=='H' && m=='P')) && (2*h1+p1<2*h2+p2 && 2*h1+p1<2*h3+p3)){
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", p1+h1+h1);
		return 0;}
	else if (((t=='P' && b=='H' && m=='H') || (t=='H' && b=='P' && m=='H') || (t=='H' && b=='H' && m=='P')) && (2*h2+p2<2*h1+p1 && 2*h2+p2<2*h3+p3))
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", p2+h2+h2);
	else if (((t=='P' && b=='H' && m=='H') || (t=='H' && b=='P' && m=='H') || (t=='H' && b=='H' && m=='P')) && (2*h3+p3<2*h2+p2 && 2*h3+p3<2*h1+p1))
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", p3+h3+h3);
	else if (((t=='H' && b=='H' && m=='C') || (t=='H' && b=='C' && m=='H') || (t=='C' && b=='H' && m=='H')) && (2*h1+c1<2*h2+c2 && 2*h1+c1<2*h3+c3)){
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", h1+h1+c1);
		return 0;}
	else if (((t=='H' && b=='H' && m=='C') || (t=='H' && b=='C' && m=='H') || (t=='C' && b=='H' && m=='H')) && (2*h2+c2<2*h1+c1 && 2*h2+c2<2*h3+c3))
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", h2+h2+c2);
	else if (((t=='H' && b=='H' && m=='C') || (t=='H' && b=='C' && m=='H') || (t=='C' && b=='H' && m=='H')) && (2*h3+c3<2*h2+c2 && 2*h3+c3<2*h1+c1))
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", h3+h3+c3);
	else if (((t=='H' && b=='C' && m=='C') || (t=='C' && b=='H' && m=='C') || (t=='C' && b=='C' && m=='H')) && (2*c1+h1<2*c2+h2 && 2*c1+h1<2*c3+h3)){
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", c1+c1+h1);
		return 0;}
	else if (((t=='H' && b=='C' && m=='C') || (t=='C' && b=='H' && m=='C') || (t=='C' && b=='C' && m=='H')) && (2*c2+h2<2*c1+h1 && 2*c2+h2<2*c3+h3))
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", c2+c2+h2);
	else if (((t=='H' && b=='C' && m=='C') || (t=='C' && b=='H' && m=='C') || (t=='C' && b=='C' && m=='H')) && (2*c3+h3<2*c2+h2 && 2*c3+h3<2*c1+h1))
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", c3+c3+h3);
	else if (((t=='C' && b=='P' && m=='H') || (t=='C' && b=='H' && m=='P') || (t=='P' && b=='H' && m=='C') || (t=='P' && b=='C' && m=='H') || (t=='H' && b=='C' && m=='P') || (t=='H' && b=='P' && m=='C')) && (p1+h1+c1<p2+h2+c2 && p1+h1+c1<p3+c3+h3)){
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", p1+h1+c1);
		return 0;}
	else if (((t=='C' && b=='P' && m=='H') || (t=='C' && b=='H' && m=='P') || (t=='P' && b=='H' && m=='C') || (t=='P' && b=='C' && m=='H') || (t=='H' && b=='C' && m=='P') || (t=='H' && b=='P' && m=='C')) && (p2+h2+c2<p1+h1+c1 && p2+h2+c2<p3+c3+h3))
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", p2+c2+h2);
	else if (((t=='C' && b=='P' && m=='H') || (t=='C' && b=='H' && m=='P') || (t=='P' && b=='H' && m=='C') || (t=='P' && b=='C' && m=='H') || (t=='H' && b=='C' && m=='P') || (t=='H' && b=='P' && m=='C')) && (p3+h3+c3<p1+h1+c1 && p3+h3+c3<p2+c2+h2))
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", p3+c3+h3);
		
	if (t=='C' && b=='C' && m=='C' && 3*c1*0.9<3*c2 && 3*c1*0.9<3*c3){
	popust=3*c1*0.9;
	printf("Sa popustom bi Restoran bio jeftiniji (%.2lf KM).", popust);}
	else if (t=='P' && b=='P' && m=='P' && 3*p1*0.9<3*p2 && 3*p1*0.9<3*p3){
	popust=3*p1*0.9;
	printf("Sa popustom bi Restoran bio jeftiniji (%.2lf KM).", popust);}
	else if (t=='H' && b=='H' && m=='H' && 3*h1*0.9<3*h2 && 3*h1*0.9<3*h3){
	popust=3*h1*0.9;
	printf("Sa popustom bi Restoran bio jeftiniji (%.2lf KM).",popust);}
	else if (((t=='P' && b=='P' && m=='C') || (t=='P' && b=='C' && m=='P') || (t=='C' && b=='P' && m=='P')) && ((2*(p1*0.9))+c1<2*p2+c2) && ((2*(p1*0.9))+c1<2*p3+c3)){
	popust=2*(p1*0.9)+c1;
	printf("Sa popustom bi Restoran bio jeftiniji (%.2lf KM).", popust);}
	else if (((t=='C' && b=='C' && m=='P') || (t=='C' && b=='P' && m=='C') || (t=='P' && b=='C' && m=='C')) && ((2*(c1*0.9))+p1<2*c2+p2) && ((2*(c1*0.9))+p1<2*c3+p3)){
	popust=2*(c1*0.9)+p1;
	printf("Sa popustom bi Restoran bio jeftiniji (%.2lf KM).", popust);}
	else if (((t=='P' && b=='P' && m=='H') || (t=='P' && b=='H' && m=='P') || (t=='H' && b=='P' && m=='P')) && ((2*(p1*0.9))+h1<2*p2+h2) && ((2*(p1*0.9))+h1<2*p3+h3)){
	popust=2*(p1*0.9)+h1;
	printf("Sa popustom bi Restoran bio jeftiniji (%.2lf KM).", popust);}
	else if (((t=='P' && b=='H' && m=='H') || (t=='H' && b=='P' && m=='H') || (t=='H' && b=='H' && m=='P')) && ((2*(h1*0.9))+p1<2*h2+p2) && ((2*(h1*0.9))+p1<2*h3+p3)){
	popust=2*(h1*0.9)+p1;
	printf("Sa popustom bi Restoran bio jeftiniji (%.2lf KM).", popust);}
	else if (((t=='H' && b=='H' && m=='C') || (t=='H' && b=='C' && m=='H') || (t=='C' && b=='H' && m=='H')) && ((2*(h1*0.9))+c1<2*h2+c2) && ((2*(h1*0.9))+c1<2*h3+c3)){
	popust=2*(h1*0.9)+c1;
	printf("Sa popustom bi Restoran bio jeftiniji (%.2lf KM).",popust);}
	else if (((t=='H' && b=='C' && m=='C') || (t=='C' && b=='H' && m=='C') || (t=='C' && b=='C' && m=='H')) && ((2*(c1*0.9))+h1<2*c2+h2) && ((2*(c1*0.9))+h1<2*c3+h3)){
	popust=2*(c1*0.9)+h1;
	printf("Sa popustom bi Restoran bio jeftiniji (%.2lf KM).", popust);}
	else if (((t=='C' && b=='P' && m=='H') || (t=='C' && b=='H' && m=='P') || (t=='P' && b=='H' && m=='C') || (t=='P' && b=='C' && m=='H') || (t=='H' && b=='C' && m=='P') || (t=='H' && b=='P' && m=='C')) && ((p1*0.9)+c1+h1<p2+c2+h2) && ((p1*0.9)+c1+h1<p3+c3+h3)){
	popust=(p1*0.9)+c1+h1;
	printf("Sa popustom bi Restoran bio jeftiniji (%.2lf KM).", popust);}
	else if (((t=='C' && b=='P' && m=='H') || (t=='C' && b=='H' && m=='P') || (t=='P' && b=='H' && m=='C') || (t=='P' && b=='C' && m=='H') || (t=='H' && b=='C' && m=='P') || (t=='H' && b=='P' && m=='C')) && ((c1*0.9)+p1+h1<p2+c2+h2) && ((c1*0.9)+p1+h1<p3+c3+h3)){
	popust=(c1*0.9)+p1+h1;
	printf("Sa popustom bi Restoran bio jeftiniji (%.2lf KM).", popust);}
	else if (((t=='C' && b=='P' && m=='H') || (t=='C' && b=='H' && m=='P') || (t=='P' && b=='H' && m=='C') || (t=='P' && b=='C' && m=='H') || (t=='H' && b=='C' && m=='P') || (t=='H' && b=='P' && m=='C')) && ((h1*0.9)+p1+c1<p2+c2+h2) && ((h1*0.9)+p1+c1<p3+c3+h3)){
	popust=(h1*0.9)+c1+h1;
	printf("Sa popustom bi Restoran bio jeftiniji (%.2lf KM).", popust);}

	
	
	return 0;
}
