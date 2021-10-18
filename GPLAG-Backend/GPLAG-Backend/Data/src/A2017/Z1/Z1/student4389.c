
#include <stdio.h>
/*KOD KONJUSARA*/
#define a3H 9.9
#define a3P 20.4
#define a3C 15.00
#define a2H1P 13.4
#define a1H2P 16.9
#define a2H1C 11.6
#define a1H2C 13.3
#define a2P1C 18.6
#define a1P2C 16.8

/*TROVAC*/
#define b3H 9
#define b3P 24
#define b3C 11.7
#define b2H1P 14
#define b1H2P 19
#define b2H1C 9.9
#define b1H2C 10.8
#define b2P1C 19.9
#define b1P2C 15.8

/*BISTRO*/
#define c3H 15
#define c3P 15.9
#define c3C 18
#define c2H1P 15.3
#define c1H2P 15.6
#define c2H1C 16
#define c1H2C 21
#define c2P1C 16.6
#define c1P2C 17.3

#define wk 15.1
#define wt 14.9
#define wb 16.3



int main() {
	
	char tarik,mirza,bojan,H,P,C,enter;
	float k1,k2,k3,k4,k5,k6,k7,k8,k9;
	float t1,t2,t3,t4,t5,t6,t7,t8,t9;
	float b1,b2,b3,b4,b5,b6,b7,b8,b9;
	float p1,p2,p3,p4,p5,p6;
	float q1,q2,q3,q4,q5,q6;
	float n1,l1,l2;
	
	/*------------------------------------*/
	/*             ULAZNI DIO             */
	/*------------------------------------*/
	
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &tarik);
	scanf("%c", &enter);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &bojan);
	scanf("%c", &enter);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &mirza);
	
	
	
	/*------------------------------------*/
	/*        VRIJEDNOSTI PROIZVODA       */
	/*------------------------------------*/
	
	k1=a3H*1;
	t1=b3H*1;
	b1=c3H*1;
	
	k2=a3P*1;
	t2=b3P*1;
	b2=c3P*1;
	
	k3=a3C*1;
	t3=b3C*1;
	b3=c3C*1;
	
	p1=a3H-0.99;
	p2=a3P-2.04;
	p3=a3C-1.5;
	
	/*--------------------------------------*/
	/*         3 ISTE NAMIRNICE             */
	/*              KONJUSAR                */
	/*--------------------------------------*/
	
	   /*KONJUSAR*/
	if((tarik=='H' && bojan=='H' && mirza=='H') && (k1<t1 && k1<b1)) {
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\"(%.2f KM).", k1);
	}
	else if((tarik=='H' && bojan=='H' && mirza=='H') && (k1<t1 && k1<b1) && (p1<k1)) {
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\"(%.2f KM).\n", k1);
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", p1);
	}
	
	else if((tarik=='P' && bojan=='P' && mirza=='P') && (k2<t2 && k2<b2)) {
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", k2);
	}
	else if((tarik=='P' && bojan=='P' && mirza=='P') && (k2<t2 && k2<b2) && (p2<k2)) {
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", k2);
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", p2);
	}
	
	else if((tarik=='C' && bojan=='C' && mirza=='C') && (k3<t3 && k3<b3)) {
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", k3);
	}
	else if((tarik=='C' && bojan=='C' && mirza=='C') && (k3<t3 && k3<b3) && (p3<k3)) {
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", k3);
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", p3);
	}
	
	/*-----------------------------------------*/
	/*                TROVAC                   */
	/*-----------------------------------------*/
	
	if((tarik=='H' && bojan=='H' && mirza=='H') && (t1<k1 && t1<b1) && (p1>t1)) {
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", t1);
	}
	else if((tarik=='H' && bojan=='H' && mirza=='H') && (t1<k1 && t1<b1) && (p1<t1)) {
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", t1);
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", p1);
	}
	
	
	else if((tarik=='P' && bojan=='P' && mirza=='P') && (t2<k2 && t2<b2) && (p2>t2)) {
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", t2);
	}
	else if((tarik=='P' && bojan=='P' && mirza=='P') && (t2<k2 && t2<b2) && (p2<t2)) {
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", t2);
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", p2);
	}
	
	
	else if((tarik=='C' && bojan=='C' && mirza=='C') && (t3<k3 && t3<b3) && (p3>t3)) {
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", t3);
	}
	else if((tarik=='C' && bojan=='C' && mirza=='C') && (t3<k3 && t3<b3) && (p3<t3)) {
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", t3);
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", p3);
	}
	
	
	
/*---Zalutala lajna---*/
l1=l2*1;
/*------------------------*/	
	
	/*------------------------------------------*/
	/*                 BISTRO*                  */
	/*------------------------------------------*/
	
	if((tarik=='H' && bojan=='H' && mirza=='H') && (b1<k1 && b1<t1) && (p1>b1)) {
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", b1);
	}
	else if((tarik=='H' && bojan=='H' && mirza=='H') && (b1<k1 && b1<t1) && (p1<b1)) {
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", b1);
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", p1);
	}
	
	
	else if((tarik=='P' && bojan=='P' && mirza=='P') && (b2<t2 && b2<k2) && (p2>b2)) {
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", b2);
	}
	else if((tarik=='P' && bojan=='P' && mirza=='P') && (b2<t2 && b2<k2) && (p2<b2)) {
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", b2);
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", p2);
	}
	
	else if((tarik=='C' && bojan=='C' && mirza=='C') && (b3<t3 && b3<k3) && (p3>b3)) {
		printf("Najjeftiniji je Bistro \"Lorelei\" (%2.f KM).\n", b3);
		 
	}
	else if((tarik=='C' && bojan=='C' && mirza=='C') && (b3<t3 && b3<k3) && (p3<b3)) {
		printf("Najjeftiniji je Bistro \"Lorelei\" (%2.f KM).\n", b3);
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", p3);
		 
	}
	
	/*-------------------------------------------*/
	/*         2 hamburgera, 1 pizza             */
	/*         neovisno o redoslijedu            */
	/*-------------------------------------------*/
	
	/*-------------------------------------------*/
	/*              CIJENE PROIZVODA             */
	/*-------------------------------------------*/
	
	k4=a2H1P*1;
	t4=b2H1P*1;
	b4=c2H1P*1;
	
	/*---Cijena sa 10% popusta---*/
	q1=a2H1P-1.34;
	/*---------------------------*/
	
	if((tarik=='H' && bojan=='H' && mirza=='P' || tarik=='H' && bojan=='P' && mirza=='H' || tarik=='P' && bojan=='H' && mirza=='H') && (k4<t4 && k4<b4)) {
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", k4);
	}
	
	else if((tarik=='H' && bojan=='H' && mirza=='P' || tarik=='H' && bojan=='P' && mirza=='H' || tarik=='P' && bojan=='H' && mirza=='H') && t4<k4 && b4<k4 && q1<k4) {
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", q1);
	}
	
	
	else if((tarik=='H' && bojan=='H' && mirza=='P' || tarik=='H' && bojan=='P' && mirza=='H' || tarik=='P' && bojan=='H' && mirza=='H') && (t4<k4 && t4<b4)) {
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", t4); 
	}
	
	else if((tarik=='H' && bojan=='H' && mirza=='P' || tarik=='H' && bojan=='P' && mirza=='H' || tarik=='P' && bojan=='H' && mirza=='H') && q1<t4) {
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", q1);
	}
	
	
	else if((tarik=='H' && bojan=='H' && mirza=='P' || tarik=='H' && bojan=='P' && mirza=='H' || tarik=='P' && bojan=='H' && mirza=='H') && (b4<k4 && b4<t4)) {
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", b4);
	}
	
	else if((tarik=='H' && bojan=='H' && mirza=='P' || tarik=='H' && bojan=='P' && mirza=='H' || tarik=='P' && bojan=='H' && mirza=='H')&& q1<b4) {
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", q1);
	}
	
	/*--------------------------------------------*/
	/*          1 hamburger, 2 pice               */
	/*          neovisno o redoslijedu            */
	/*--------------------------------------------*/
	
	/*-------------------------------------------*/
	/*              CIJENE PROIZVODA             */
	/*-------------------------------------------*/
	
	k5=a1H2P*1;
	t5=b1H2P*1;
	b5=c1H2P*1;
	
	/*---Cijena sa 10% popusta*/
	q2=a1H2P-1.36;
	/*------------------------*/
	
	if((tarik=='H' && bojan=='P' && mirza=='P' || tarik=='P' && bojan=='P' && mirza=='H' || tarik=='P' && bojan=='H' && mirza=='P') && (k5<t5 && k5<b5) &&(q2>k5)) {
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", k5);
	}
	else if((tarik=='H' && bojan=='P' && mirza=='P' || tarik=='P' && bojan=='P' && mirza=='H' || tarik=='P' && bojan=='H' && mirza=='P') && (k5<t5 && k5<b5) && (q2<k5)) {
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", k5);
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", q2);
	}
	
	
	else if((tarik=='H' && bojan=='P' && mirza=='P' || tarik=='P' && bojan=='P' && mirza=='H' || tarik=='P' && bojan=='H' && mirza=='P') && (t5<k5 && t5<b5) && (q2>t5)) {
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", t5);
	}
	else if((tarik=='H' && bojan=='P' && mirza=='P' || tarik=='P' && bojan=='P' && mirza=='H' || tarik=='P' && bojan=='H' && mirza=='P') && (t5<k5 && t5<b5) && (q2<t5)) {
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", t5);
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", q2);
	}
	
	
	else if((tarik=='H' && bojan=='P' && mirza=='P' || tarik=='P' && bojan=='P' && mirza=='H' || tarik=='P' && bojan=='H' && mirza=='P') && (b5<k5 && b5<t5) && (q2>b5)) {
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", b5);
	}
	else if((tarik=='H' && bojan=='P' && mirza=='P' || tarik=='P' && bojan=='P' && mirza=='H' || tarik=='P' && bojan=='H' && mirza=='P') && (b5<k5 && b5<t5) && (q2<b5)) {
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", b5);
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", q2);
		return 0;
	}
	
	
	
	/*------------------------------------------*/
	/*       1 Cevap i 1 Hamburger i 1 Pica     */
	/*------------------------------------------*/
	
	/*Zalutala lajna #2*/
	n1=wk-0.68;
	/*-------------------- */


	if((tarik=='H' && bojan=='C' && mirza=='P' || tarik=='P' && bojan=='C' && mirza=='H' || tarik=='H' && bojan=='P' && mirza=='C') || tarik=='C' && bojan=='H' && mirza=='P' || tarik=='C' && bojan=='P' && mirza=='H' || tarik=='P' && bojan=='H' && mirza=='C' && (wt<wk && wt<wb) && (n1<wt)) {
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", wt);
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", n1);
	}
	else if((tarik=='H' && bojan=='C' && mirza=='P' || tarik=='P' && bojan=='C' && mirza=='H' || tarik=='H' && bojan=='P' && mirza=='C') || tarik=='C' && bojan=='H' && mirza=='P' || tarik=='C' && bojan=='P' && mirza=='H' || tarik=='P' && bojan=='H' && mirza=='C' && (wt<wk && wt<wb) && (n1>wt)){ 
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n");
	}
	
	
	else if((tarik=='H' && bojan=='C' && mirza=='P' || tarik=='P' && bojan=='C' && mirza=='H' || tarik=='H' && bojan=='P' && mirza=='C') || tarik=='C' && bojan=='H' && mirza=='P' || tarik=='C' && bojan=='P' && mirza=='H' || tarik=='P' && bojan=='H' && mirza=='C' && (wb<wk && wb<wt) && (n1>wb)) {
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", wb);
	}
	else if((tarik=='H' && bojan=='C' && mirza=='P' || tarik=='P' && bojan=='C' && mirza=='H' || tarik=='H' && bojan=='P' && mirza=='C') || tarik=='C' && bojan=='H' && mirza=='P' || tarik=='C' && bojan=='P' && mirza=='H' || tarik=='P' && bojan=='H' && mirza=='C' && (wb<wk && wb<wt) && (n1<wb)) {
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", wb);
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", n1);
	}
	else {}
	

	/*-------------------------------------------*/
	/*              CIJENE PROIZVODA             */
	/*-------------------------------------------*/
	
	k6=a2H1C*1;
	t6=b2H1C*1;
	b6=c2H1C*1;
	
	
	
	if((tarik=='H' && bojan=='P' && mirza=='P' || tarik=='P' && bojan=='P' && mirza=='H' || tarik=='P' && bojan=='H' && mirza=='P') && q2<b5) {
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", q2);
	}
	
	else if((tarik=='H' && bojan=='P' && mirza=='P' || tarik=='P' && bojan=='P' && mirza=='H' || tarik=='P' && bojan=='H' && mirza=='P')&& q2<t5) {
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", q2);
	}
	
	else if((tarik=='H' && bojan=='P' && mirza=='P' || tarik=='P' && bojan=='P' && mirza=='H' || tarik=='P' && bojan=='H' && mirza=='P')&& q2<k5 && t5<k5 && b5<k5) {
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", q2); 
	}
	
	/*-----------------------------------------*/
	/*        2 hamburgera i 1 Cevap           */
	/*-----------------------------------------*/
	
	/*--Cijena sa 10% popusta---*/
	q3=a2H1C-1.16;
	/*--------------------------*/
	
	if((tarik=='H' && bojan=='H' && mirza=='C' || tarik=='C' && bojan=='H' && mirza=='H' || tarik=='H' && bojan=='C' && mirza=='H') && (k6<t6 && k6<b6)) {
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", k6);
	}
	
	else if((tarik=='H' && bojan=='H' && mirza=='C' || tarik=='C' && bojan=='H' && mirza=='H' || tarik=='H' && bojan=='C' && mirza=='H') && q3<k6 && t6<k6 && b6<k6) {
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", q3);
	}
	
	else if((tarik=='H' && bojan=='H' && mirza=='C' || tarik=='C' && bojan=='H' && mirza=='H' || tarik=='H' && bojan=='C' && mirza=='H') && (t6<k6 && t6<b6)) {
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", t6);
	}
	
	else if((tarik=='H' && bojan=='H' && mirza=='C' || tarik=='C' && bojan=='H' && mirza=='H' || tarik=='H' && bojan=='C' && mirza=='H') && q3<t6) {
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", q3);
	}
	
	else if((tarik=='H' && bojan=='H' && mirza=='C' || tarik=='C' && bojan=='H' && mirza=='H' || tarik=='H' && bojan=='C' && mirza=='H') && (b6<k6 && b6<t6)) {
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", b6);
	}
	
	else if((tarik=='H' && bojan=='H' && mirza=='C' || tarik=='C' && bojan=='H' && mirza=='H' || tarik=='H' && bojan=='C' && mirza=='H') && q3<b6) {
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", q3);
	}
	
	/*-------------------------------------------*/
	/*          1 Hamburger i 2 cevapa           */
	/*-------------------------------------------*/
	
	/*-------------------------------------------*/
	/*              CIJENE PROIZVODA             */
	/*-------------------------------------------*/
	
	k7=a1H2C*1;
	t7=b1H2C*1;
	b7=c1H2C*1;
	
	/*---Cijena sa 10% popusta---*/
	q4=a1H2C-1.33;
	/*---------------------------*/
	
	if((tarik=='H' && bojan=='C' && mirza=='C' || tarik=='C' && bojan=='C' && mirza=='H' || tarik=='C' && bojan=='H' && mirza=='C') && (k7<t7 && k7<b7)) {
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", k7);
	}
	
	else if((tarik=='H' && bojan=='C' && mirza=='C' || tarik=='C' && bojan=='C' && mirza=='H' || tarik=='C' && bojan=='H' && mirza=='C') && q4<k7 && t7<k7 && b7<k7) {
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", q4);
	}
	
	else if((tarik=='H' && bojan=='C' && mirza=='C' || tarik=='C' && bojan=='C' && mirza=='H' || tarik=='C' && bojan=='H' && mirza=='C') && (t7<k7 && t7<b7)) {
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", t7);
	}
	
	else if((tarik=='H' && bojan=='C' && mirza=='C' || tarik=='C' && bojan=='C' && mirza=='H' || tarik=='C' && bojan=='H' && mirza=='C') && q4<t7) {
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", q4);
	}
	
	else if((tarik=='H' && bojan=='C' && mirza=='C' || tarik=='C' && bojan=='C' && mirza=='H' || tarik=='C' && bojan=='H' && mirza=='C') && (b7<k7 && b7<t7)) {
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", b7);
	}
	
	else if((tarik=='H' && bojan=='C' && mirza=='C' || tarik=='C' && bojan=='C' && mirza=='H' || tarik=='C' && bojan=='H' && mirza=='C') && q4<b7) {
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", q4);
	}
	
	/*-------------------------------------------------*/
	/*              2 Pizzee i 1 Cevap                 */
	/*-------------------------------------------------*/
	
	/*-------------------------------------------*/
	/*              CIJENE PROIZVODA             */
	/*-------------------------------------------*/
	
	k8=a2P1C*1;
	t8=b2P1C*1;
	b8=c2P1C*1;
	
	/*---Cijena sa 10% popusta---*/
	q5=a2P1C-1.86;
	/*--------------------------*/
	
	if((tarik=='P' && bojan=='P' && mirza=='C' || tarik=='C' && bojan=='C' && mirza=='P' || tarik=='P' && bojan=='C' && mirza=='P') && (k8<t8 && k8<b8)) {
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", k8);
	}
	
	
    else if((tarik=='P' && bojan=='P' && mirza=='C' || tarik=='C' && bojan=='C' && mirza=='P' || tarik=='P' && bojan=='C' && mirza=='P') && (t8<k8 && t8<b8)) {
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", t8);
	}
	
	
	else if((tarik=='P' && bojan=='P' && mirza=='C' || tarik=='C' && bojan=='C' && mirza=='P' || tarik=='P' && bojan=='C' && mirza=='P') && (b8<k8 && b8<t8)) {
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", b8);
	}
	
	l1=l2*1;
	
	if((tarik=='P' && bojan=='P' && mirza=='C' || tarik=='C' && bojan=='C' && mirza=='P' || tarik=='P' && bojan=='C' && mirza=='P') && q5<k8 && t8<k8 && b8<k8) {
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", q5);
	}
	
	else if((tarik=='P' && bojan=='P' && mirza=='C' || tarik=='C' && bojan=='C' && mirza=='P' || tarik=='P' && bojan=='C' && mirza=='P') && !(t8>q5) && q5<t8) {
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", q5);
	}
	
	/*--------------------------------------------*/
	/*            1 Pizza i 2 Cevapa              */
	/*--------------------------------------------*/
	
	/*-------------------------------------------*/
	/*              CIJENE PROIZVODA             */
	/*-------------------------------------------*/
	
	k9=a1P2C*1;
	t9=b1P2C*1;
	b9=c1P2C*1;
	
	/*---Cijena sa 10% popusta---*/
	q6=c1P2C-1.68;
	/*---------------------------*/
	
	if((tarik=='C' && bojan=='C' && mirza=='P' || tarik=='P' && bojan=='C' && mirza=='C' || tarik=='C' && bojan=='P' && mirza=='C') && (k9<t9 && k9<b9)) {
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", k9);
	}
	
	else if((tarik=='C' && bojan=='C' && mirza=='P' || tarik=='P' && bojan=='C' && mirza=='C' || tarik=='C' && bojan=='P' && mirza=='C') && q6<k9 && t9<k9 &&b9<k9) {
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", q6);
	}
	
	else if((tarik=='C' && bojan=='C' && mirza=='P' || tarik=='P' && bojan=='C' && mirza=='C' || tarik=='C' && bojan=='P' && mirza=='C') && (t9<k9 && t9<b9)) {
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", t9);
	}
	
	else if((tarik=='C' && bojan=='C' && mirza=='P' || tarik=='P' && bojan=='C' && mirza=='C' || tarik=='C' && bojan=='P' && mirza=='C') && q6<t9) {
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", q6);
	}
	
	else if((tarik=='C' && bojan=='C' && mirza=='P' || tarik=='P' && bojan=='C' && mirza=='C' || tarik=='C' && bojan=='P' && mirza=='C') && (b9<k9 && b9<t9)) {
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", b9);
	}
	
	else if((tarik=='C' && bojan=='C' && mirza=='P' || tarik=='P' && bojan=='C' && mirza=='C' || tarik=='C' && bojan=='P' && mirza=='C') && q6<b9) {
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", q6);
	}
	
	
	return 0;
}