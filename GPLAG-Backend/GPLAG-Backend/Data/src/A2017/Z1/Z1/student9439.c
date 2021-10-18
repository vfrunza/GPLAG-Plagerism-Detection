#include <stdio.h>
#define bp 5.3
#define bc 6.0
#define bh 5.0
#define fp 8.0
#define fc 3.9
#define fh 3.0
#define rp 6.8
#define rc 5.0
#define rh 3.3
int main() {
	char tarik,mirza,bojan,novi_red;
	float suma,sumar;
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &tarik);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &bojan);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &mirza);
	scanf("%c", &novi_red);

if((tarik=='P')&&(bojan=='P')&&(mirza=='P')){
	suma=bp+bp+bp;
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", suma );
		sumar=(rp+rp+rp)-(rp+rp+rp)*0.1;
		if(sumar<suma){
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", sumar);}}

	if((tarik=='H')&&(bojan=='H')&&(mirza=='H')){
	suma=fh+fh+fh;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", suma );
		sumar=rh+rh+rh-(rh+rh+rh)*0.1;
		if(sumar<suma){
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", sumar);}}
		
		if((tarik=='C')&&(bojan=='C')&&(mirza=='C')){
	suma=fc+fc+fc;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", suma );
		sumar=rc+rc+rc-(rc+rc+rc)*0.1;
		if(sumar<suma){
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", sumar);}}
	
		if(((tarik=='P')&&(bojan=='P')&&(mirza=='C'))||((tarik=='C')&&(bojan=='P')&&(mirza=='P'))||((tarik=='P')&&(bojan=='C')&&(mirza=='P'))){
	suma=bp+bp+bc;
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", suma );
			sumar=rp+rp+rc-(rp+rp)*0.1;
			if(sumar<suma){
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", sumar);}}
		
		if(((tarik=='P')&&(bojan=='P')&&(mirza=='H'))||((tarik=='H')&&(bojan=='P')&&(mirza=='P'))||((tarik=='P')&&(bojan=='H')&&(mirza=='P'))){
	suma=bp+bp+bh;
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", suma );
			sumar=rp+rp+rh-(rp+rp)*0.1;
			if(sumar<suma){
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", sumar);}}
		
		if(((tarik=='C')&&(bojan=='C')&&(mirza=='P'))||((tarik=='C')&&(bojan=='P')&&(mirza=='C'))||((tarik=='P')&&(bojan=='C')&&(mirza=='C'))){
	suma=fc+fc+fp;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", suma );
			sumar=rc+rc+rp-(rc+rc)*0.1;
			if(sumar<suma){
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", sumar);}}
		
		if(((tarik=='C')&&(bojan=='C')&&(mirza=='H'))||((tarik=='C')&&(bojan=='H')&&(mirza=='C'))||((tarik=='H')&&(bojan=='C')&&(mirza=='C'))){
	suma=fc+fc+fh;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", suma );
		sumar=rc+rc+rh-(rc+rc)*0.1;
		if(sumar<suma){
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", sumar);}}
		
		if(((tarik=='H')&&(bojan=='H')&&(mirza=='P'))||((tarik=='P')&&(bojan=='H')&&(mirza=='H'))||((tarik=='H')&&(bojan=='P')&&(mirza=='H'))){
	suma=rp+rh+rh;
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", suma );}

		if(((tarik=='H')&&(bojan=='H')&&(mirza=='C'))||((tarik=='H')&&(bojan=='C')&&(mirza=='H'))||((tarik=='C')&&(bojan=='H')&&(mirza=='H'))){
	suma=fc+fh+fh;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", suma );
	sumar=rh+rh+rc-(rh+rh)*0.1;
	if(sumar<=suma){
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", sumar);}}
		
		if((tarik=='P')&&(bojan=='H')&&(mirza=='C')){
	suma=rc+rh+rp;
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", suma );
	sumar=rp+rc+rh-(rp)*0.1;
	if(sumar<=suma){
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", sumar);}}
		
		if((tarik=='P')&&(bojan=='C')&&(mirza=='H')){
	suma=rc+rh+rp;
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", suma );
	sumar=rp+rc+rh-(rp)*0.1;
	if(sumar<=suma){
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", sumar);}}
		
		if((tarik=='H')&&(bojan=='P')&&(mirza=='C')){
	suma=rc+rh+rp;
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", suma );
	sumar=rp+rc+rh-(rp)*0.1;
	if(sumar<=suma){
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", sumar);}}
		
		if((tarik=='H')&&(bojan=='C')&&(mirza=='P')){
	suma=rc+rh+rp;
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", suma );
	sumar=rp+rc+rh-(rp)*0.1;
	if(sumar<=suma){
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", sumar);}}
	
		if((tarik=='C')&&(bojan=='P')&&(mirza=='H')){
	suma=rc+rh+rp;
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", suma );
	sumar=rp+rc+rh-(rp)*0.1;
	if(sumar<=suma){
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", sumar);}}

if((tarik=='C')&&(bojan=='H')&&(mirza=='P')){
	suma=fc+fh+fp;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", suma );
	sumar=rp+rc+rh-(rp)*0.1;
	if(sumar<=suma){
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", sumar);}}

	return 0;
}
