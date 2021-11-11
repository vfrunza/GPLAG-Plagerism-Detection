#include <stdio.h>



int main() {
	
	char t,b,m,novi_red;

	
	printf("Unesite jelo za Tarika: ");
	scanf ("%c", &t);
	scanf("%c", &novi_red);
	printf ("Unesite jelo za Bojana: ");
	scanf ("%c", &b);
	scanf("%c", &novi_red);
	printf ("Unesite jelo za Mirzu: ");
	scanf ("%c", &m);
	scanf("%c", &novi_red);
	
	if ( t=='P' && b=='P' && m=='P' ) {
	printf ("Najjeftiniji je Bistro \"Lorelei\" (15.90 KM)."); }
	
	
	else if ( t=='H' && b=='H' && m=='H' ) {
	printf ("Najjeftiniji je Fast-food \"Trovac\" (9.00 KM).\nSa popustom bi Restoran bio jeftiniji (8.91 KM)."); }
	
	else if ( t=='C' && b=='C' && m=='C' ) {
	printf ("Najjeftiniji je Fast-food \"Trovac\" (11.70 KM)."); }
	
	else if ( t=='P' && b=='P' && m=='H' ) {
	printf  ("Najjeftiniji je Bistro \"Lorelei\" (15.60 KM).\nSa popustom bi Restoran bio jeftiniji (15.54 KM)."); }
	
	
	else if ( t=='P' && b=='H' && m=='P' ) {
	printf  ("Najjeftiniji je Bistro \"Lorelei\" (15.60 KM).\nSa popustom bi Restoran bio jeftiniji (15.54 KM)."); }
	
	else if ( t=='H' && b=='P' && m=='P' ) {
	printf  ("Najjeftiniji je Bistro \"Lorelei\" (15.60 KM).\nSa popustom bi Restoran bio jeftiniji (15.54 KM)."); }
	
	else if ( t=='P' && b=='P' && m=='C' ) {
	printf  ("Najjeftiniji je Bistro \"Lorelei\" (16.60 KM)."); }
	
	else if ( t=='P' && b=='C' && m=='P' ) {
	printf  ("Najjeftiniji je Bistro \"Lorelei\" (16.60 KM)."); }
	
	else if ( t=='C' && b=='P' && m=='P' ) {
	printf  ("Najjeftiniji je Bistro \"Lorelei\" (16.60 KM)."); }
	
	else if ( t=='H' && b=='H' && m=='P' ) {
	printf  ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (13.40 KM)."); }
	
	else if ( t=='H' && b=='P' && m=='H' ) {
	printf  ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (13.40 KM)."); }
	
	else if ( t=='P' && b=='H' && m=='H' ) {
	printf  ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (13.40 KM)."); }
	
	else if ( t=='H' && b=='H' && m=='C' ) {
	printf  ("Najjeftiniji je Fast-food \"Trovac\" (9.90 KM)."); }
	
	else if ( t=='H' && b=='C' && m=='H' ) {
	printf  ("Najjeftiniji je Fast-food \"Trovac\" (9.90 KM)."); }
	
	else if ( t=='C' && b=='H' && m=='H' ) {
	printf  ("Najjeftiniji je Fast-food \"Trovac\" (9.90 KM)."); }
	
	else if ( t=='C' && b=='C' && m=='P' ) {
	printf  ("Najjeftiniji je Fast-food \"Trovac\" (15.80 KM)."); }
	
	else if ( t=='C' && b=='P' && m=='C' ) {
	printf  ("Najjeftiniji je Fast-food \"Trovac\" (15.80 KM)."); }
	
	else if ( t=='P' && b=='C' && m=='C' ) {
	printf  ("Najjeftiniji je Fast-food \"Trovac\" (15.80 KM)."); }
	
	else if ( t=='C' && b=='C' && m=='H') {
	printf  ("Najjeftiniji je Fast-food \"Trovac\" (10.80 KM)."); }
	
	else if ( t=='C' && b=='H' && m=='C') {
	printf  ("Najjeftiniji je Fast-food \"Trovac\" (10.80 KM)."); }
	
	else if ( t=='H' && b=='C' && m=='C') {
	printf  ("Najjeftiniji je Fast-food \"Trovac\" (10.80 KM)."); }
	
	else if ( t=='P' && b=='H' && m=='C' ) {
	printf  ("Najjeftiniji je Fast-food \"Trovac\" (14.90 KM).\nSa popustom bi Restoran bio jeftiniji (14.42 KM)."); }
	
	else if ( t=='P' && b=='C' && m=='H' ) {
	printf  ("Najjeftiniji je Fast-food \"Trovac\" (14.90 KM).\nSa popustom bi Restoran bio jeftiniji (14.42 KM)."); }
	
	else if ( t=='H' && b=='P' && m=='C' ) {
	printf  ("Najjeftiniji je Fast-food \"Trovac\" (14.90 KM).\nSa popustom bi Restoran bio jeftiniji (14.42 KM)."); }
	
	else if ( t=='C' && b=='P' && m=='H' ) {
	printf  ("Najjeftiniji je Fast-food \"Trovac\" (14.90 KM).\nSa popustom bi Restoran bio jeftiniji (14.42 KM)."); }
	
	else if ( t=='P' && b=='H' && m=='C' ) {
	printf  ("Najjeftiniji je Fast-food \"Trovac\" (14.90 KM).\nSa popustom bi Restoran bio jeftiniji (14.42 KM)."); }
	
	else if ( t=='H' && b=='C' && m=='P' ) {
	printf  ("Najjeftiniji je Fast-food \"Trovac\" (14.90 KM).\nSa popustom bi Restoran bio jeftiniji (14.42 KM)."); }
	
	else if ( t=='C' && b=='H' && m=='P' ) {
	printf  ("Najjeftiniji je Fast-food \"Trovac\" (14.90 KM).\nSa popustom bi Restoran bio jeftiniji (14.42 KM)."); }
	
	
	
	
	
	return 0;
}
