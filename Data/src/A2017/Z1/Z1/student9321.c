#include <stdio.h>
#include<string.h>

int main() {
char tarik,bojan,mirza,novi_red;
float cijena_1,cijena_2,cijena_3,cijena_11,cijena_12,cijena_13;
float ch_1,ch_2,ch_3,cp_1,cp_2,cp_3,cc_1,cc_2,cc_3,p;
float min,min_1;
ch_1=3.30;
ch_2=3.00;
ch_3=5.00;
cp_1=6.80;
cp_2=8.00;
cp_3=5.30;
cc_1=5.00;
cc_2=3.90;
cc_3=6.00;
p=0.9;
printf("Unesite jelo za Tarika: ");
scanf("%c",&tarik);
scanf("%c", &novi_red);
printf("Unesite jelo za Bojana: ");
scanf("%c",&bojan);
scanf("%c", &novi_red);
printf("Unesite jelo za Mirzu: ");
scanf("%c",&mirza);

if((tarik=='H') && (bojan=='H') && (mirza=='H')) {
	
	cijena_1=3*ch_1; 		/*Restoran "Kod konja i konjusara"*/
	cijena_2=3*ch_2; 		/*Fast food "Trovac"*/
	cijena_3=3*ch_3; 		/*Bistro "Lorelei"*/
	cijena_11= 3*p*ch_1;
	
if(cijena_1<cijena_2 && cijena_1<cijena_3) {
	printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",cijena_1);
	return 0;
}

	 if(cijena_2<cijena_3){
	 	min_1=cijena_2;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",min_1); 
	}
	
	else {
		min_1=cijena_3;
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",min_1);
	}
	
if(cijena_11<min_1){

	printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",cijena_11);
}
else{
	return 0;
}

}
	else if((tarik=='P') && (bojan=='P') && (mirza=='P')) {
		
		cijena_1=3*cp_1;		/*Restoran "Kod konja i konjusara"*/
		cijena_2=3*cp_2;		/*Fast food "Trovac"*/
		cijena_3=3*cp_3;		/*Bistro "Lorelei"*/
		cijena_11= 3*p*cp_1;
		
	if(cijena_1<cijena_2 && cijena_1<cijena_3) {
	printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",cijena_1);
	return 0;
}

	 if(cijena_2<cijena_3){
	 	min_1=cijena_2;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",min_1); 
	}
	
	else {
		min_1=cijena_3;
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",min_1);
	}
	
if(cijena_11<min_1){

	printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",cijena_11);
}
else{
	return 0;
}
	}
	else if((tarik=='C') && (bojan=='C') && (mirza=='C')){
			
			cijena_1=3*cc_1;		/*Restoran "Kod konja i konjusara"*/
			cijena_2=3*cc_2;		/*Fast food "Trovac"*/
			cijena_3=3*cc_3;        /*Bistro "Lorelei"*/
			cijena_11= p*3*cc_1;
			if(cijena_1<cijena_2 && cijena_1<cijena_3) {
	printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",cijena_1);
	return 0;
}

	 if(cijena_2<cijena_3){
	 	min_1=cijena_2;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",min_1); 
	}
	
	else {
		min_1=cijena_3;
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",min_1);
	}
	
if(cijena_11<min_1){

	printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",cijena_11);
}
else{
	return 0;
}
		}
	else if((tarik=='H' && bojan=='H' && mirza=='P') || (tarik=='H' && bojan=='P' && mirza=='H') || (tarik=='P' && bojan=='H' && mirza=='H')) {
		
		cijena_1=2*ch_1+cp_1;     /*Restoran "Kod konja i konjusara"*/
		cijena_2=2*ch_2+cp_2;		/*Fast food "Trovac"*/
		cijena_3=2*ch_3+cp_3;		/*Bistro "Lorelei"*/
		cijena_11=2*p*ch_1 + cp_1;
		cijena_12=2*ch_1 + p*cp_1;
		
		if(cijena_1<cijena_2 && cijena_1<cijena_3) {
	printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",cijena_1);
	return 0;
}

	 if(cijena_2<cijena_3){
	 	min_1=cijena_2;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",min_1); 
	}
	
	else {
		min_1=cijena_3;
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",min_1);
	}
	

if(cijena_11<cijena_12){
	min=cijena_11;
}
else {
	min=cijena_12;
}
if(min_1<min){
	return 0;
}
else{
	printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",min);
}

	}
else if((tarik=='H' && bojan=='H' && mirza=='C') || (tarik=='H' && bojan=='C' && mirza=='H') || (tarik=='C' && bojan=='H' && mirza=='H') ) {

	cijena_1=2*ch_1+cc_1;     /*Restoran "Kod konja i konjusara"*/
	cijena_2=2*ch_2+cc_2;		/*Fast food "Trovac"*/
	cijena_3=2*ch_3+cc_3;		/*Bistro "Lorelei"*/
	cijena_11=2*p*ch_1 + cc_1;
	cijena_12=2*ch_1+ cc_1*p;

if(cijena_1<cijena_2 && cijena_1<cijena_3) {
	printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",cijena_1);
	return 0;
}

	 if(cijena_2<cijena_3){
	 	min_1=cijena_2;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",min_1); 
	}
	
	else {
		min_1=cijena_3;
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",min_1);
	}
	

if(cijena_11<cijena_12){
	min=cijena_11;
}
else {
	min=cijena_12;
}
if(min_1<min){
	return 0;
}
else{
	printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",min);
}

	}

	else if((tarik=='P' && bojan=='P' && mirza=='H') || (tarik=='P' && bojan=='H' && mirza=='P') || (tarik=='H' && bojan=='P' && mirza=='P')) {

	cijena_1=2*cp_1+ch_1;     /*Restoran "Kod konja i konjusara"*/
	cijena_2=2*cp_2+ch_2;		/*Fast food "Trovac"*/
	cijena_3=2*cp_3+ch_3;		/*Bistro "Lorelei"*/
	cijena_11=2*p*cp_1 + ch_1;
	cijena_12=2*cp_1 + p*ch_1;
	
	if(cijena_1<cijena_2 && cijena_1<cijena_3) {
	printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",cijena_1);
	return 0;
}

	 if(cijena_2<cijena_3){
	 	min_1=cijena_2;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",min_1); 
	}
	
	else {
		min_1=cijena_3;
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",min_1);
	}
	

if(cijena_11<cijena_12){
	min=cijena_11;
}
else {
	min=cijena_12;
}
if(min_1<min){
	return 0;
}
else{
	printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",min);
}


	}

	else if((tarik=='P' && bojan=='P' && mirza=='C') || (tarik=='P' && bojan=='C' && mirza=='P') || (tarik=='C' && bojan=='P' && mirza=='P')) {

	cijena_1=2*cp_1+cc_1;     /*Restoran "Kod konja i konjusara"*/
	cijena_2=2*cp_2+cc_2;		/*Fast food "Trovac"*/
	cijena_3=2*cp_3+cc_3;		/*Bistro "Lorelei"*/
	cijena_11=2*p*cp_1+ cc_1;
	cijena_12=2*cp_1+ p*cc_1;
	
	if(cijena_1<cijena_2 && cijena_1<cijena_3) {
	printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",cijena_1);
	return 0;
}

	 if(cijena_2<cijena_3){
	 	min_1=cijena_2;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",min_1); 
	}
	
	else {
		min_1=cijena_3;
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",min_1);
	}
	

if(cijena_11<cijena_12){
	min=cijena_11;
}
else {
	min=cijena_12;
}
if(min_1<min){
	return 0;
}
else{
	printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",min);
}


	}

else if((tarik=='C' && bojan=='C' && mirza=='H') || (tarik=='C' && bojan=='H' && mirza=='C') || (tarik=='H' && bojan=='C' && mirza=='C') )  {

	cijena_1=2*cc_1+ch_1;     /*Restoran "Kod konja i konjusara"*/
	cijena_2=2*cc_2+ch_2;		/*Fast food "Trovac"*/
	cijena_3=2*cc_3+ch_3;		/*Bistro "Lorelei"*/
	cijena_11=2*p*cc_1+ ch_1;
	cijena_12=2*cc_1 + p*ch_1;
	
	if(cijena_1<cijena_2 && cijena_1<cijena_3) {
	printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",cijena_1);
	return 0;
}

	 if(cijena_2<cijena_3){
	 	min_1=cijena_2;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",min_1); 
	}
	
	else {
		min_1=cijena_3;
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",min_1);
	}
	

if(cijena_11<cijena_12){
	min=cijena_11;
}
else {
	min=cijena_12;
}
if(min_1<min){
	return 0;
}
else{
	printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",min);
}

	}

	else if((tarik=='C' && bojan=='C' && mirza=='P') || (tarik=='C' && bojan=='P' && mirza=='C') || (tarik=='P' && bojan=='C' && mirza=='C')) { 

	cijena_1=2*cc_1+cp_1;     /*Restoran "Kod konja i konjusara"*/
	cijena_2=2*cc_2+cp_2;		/*Fast food "Trovac"*/
	cijena_3=2*cc_3+cp_3;		/*Bistro "Lorelei"*/ 
    cijena_11=2*p*cc_1 +cp_1;
    cijena_12=2*cc_1 + p*cp_1;
 
 if(cijena_1<cijena_2 && cijena_1<cijena_3) {
	printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",cijena_1);
	return 0;
}

	 if(cijena_2<cijena_3){
	 	min_1=cijena_2;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",min_1); 
	}
	
	else {
		min_1=cijena_3;
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",min_1);
	}
	

if(cijena_11<cijena_12){
	min=cijena_11;
}
else {
	min=cijena_12;
}
if(min<min_1){
	printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",min);
}
else{
	return 0;
}

	}
	
	else {

	cijena_1=ch_1+cp_1+cc_1;     /*Restoran "Kod konja i konjusara"*/
	cijena_2=ch_2+cp_2+cc_2;		/*Fast food "Trovac"*/
	cijena_3=ch_3+cp_3+cc_3;		/*Bistro "Lorelei"*/
	cijena_11= p*ch_1 + cp_1 + cc_1;
	cijena_12= ch_1 + p*cp_1 + cc_1;
	cijena_13= ch_1 + cp_1 + p*cc_1;
	
	if(cijena_1<cijena_2 && cijena_1<cijena_3) {
	printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",cijena_1);
	return 0;
}

	 if(cijena_2<cijena_3){
	 	min_1=cijena_2;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",min_1); 
	}
	
	else {
		min_1=cijena_3;
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",min_1);
	}
	

if(cijena_11<cijena_12 && cijena_11<cijena_13){
	min=cijena_11;
}
else if(cijena_12<cijena_11 && cijena_12<cijena_13) {
	min=cijena_12;
}
else {
	min=cijena_13;
}
if(min_1<min){
	return 0;
}
else{
	printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",min);
}

}


return 0;
}

