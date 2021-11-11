#include <stdio.h>

int main() {
	
	char Tarik, Bojan, Mirza;
	double pizza_rest=6.8, hamb_rest=3.3, cev_rest=5;
	double pizza_fast=8, hamb_fast=3, cev_fast=3.9;
	double pizza_bist=5.3, hamb_bist=5, cev_bist=6;
	double R, min, Rn;
	double C1,C2,C3;
	
	printf("Unesite jelo za Tarika: ");
	scanf("\n%c", &Tarik);
	printf("Unesite jelo za Bojana: ");
	scanf("\n%c", &Bojan);
	printf("Unesite jelo za Mirzu: ");
	scanf("\n%c", &Mirza);
	
	
	if(Tarik=='P' && Bojan=='P' && Mirza=='P'){
		min=pizza_rest;
		if(pizza_fast<min && pizza_fast<pizza_bist){
			min=pizza_fast;
		} else if(pizza_bist<min){
			min=pizza_bist;
		}
	 R=3*min;
     printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", R); }
     
	
	
	
	if(Tarik=='H' && Bojan=='H' && Mirza=='H'){
		min=hamb_fast;
		if(hamb_rest<min && hamb_rest<hamb_bist){
			min=hamb_rest;
		} else if(hamb_bist<min){
			min=hamb_bist;
		}
		R=3*min;
		Rn=min*3*0.99;
	   printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", R);
	   printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", Rn);}
	
	
	
	
	if(Tarik=='C' && Bojan=='C' && Mirza=='C'){
		min=cev_fast;
		if(cev_rest<min && cev_rest<cev_bist){
			min=cev_rest;
		} else if(cev_bist<min){
			min=cev_bist;
		}
		R=3*min;
	 printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", R);}
	 
	 
	 
	if(Tarik!=Bojan && Tarik!=Mirza && Bojan!=Mirza) {
		C1=pizza_rest+hamb_rest+cev_rest;
		C2=pizza_fast+hamb_fast+cev_fast;
		C3=pizza_bist+hamb_bist+cev_bist;
		Rn=0.9*pizza_rest+hamb_rest+cev_rest;
	    min=C2;
	    if(C1<min && C1<C3){
	    	min=C1;
	    } else if(C2<min){
	    	min=C2;
	    }
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", min);
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", Rn);}
		
		
	if((Tarik=='P' && Bojan=='P' && Mirza=='H') || (Tarik=='P' && Mirza=='P' && Bojan=='H') || (Tarik=='H' && Bojan=='P' && Mirza=='P')){
		C1=2*pizza_rest+hamb_rest;
		C2=2*pizza_fast+hamb_fast;
		C3=2*pizza_bist+hamb_bist;
		Rn=2*pizza_rest*0.9+hamb_rest;
		 min=C3;
		 if(C1<min && C1<C2){
		 	min=C1;
		 } else if(C2<min){
		 	min=C2;
		 }
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", min);
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", Rn); }
	 
	 
	 if((Tarik=='P' && Bojan=='P' &&  Mirza=='C') || (Tarik=='P' && Bojan=='C'  && Mirza=='P') || (Tarik=='C' && Bojan=='P' && Mirza=='P')){
	 	C1=2*pizza_rest+cev_rest;
	 	C2=2*pizza_fast+cev_fast;
	 	C3=2*pizza_bist+cev_bist;
	 	min=C3;
	 	if(C1<min && C1<C2){
	 		min=C1;
	 	} else if(C2<min){
	 		min=C2;
	 	}
	 	printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", min); }
	 	
	 
	 if((Tarik=='H' && Bojan=='H' && Mirza=='P') || (Tarik=='H' && Bojan=='P' && Mirza=='H') || (Tarik=='P' && Bojan=='H' && Mirza=='H')){
	 	C1=2*hamb_rest+pizza_rest;
	 	C2=2*hamb_fast+pizza_fast;
	 	C3=2*hamb_bist+pizza_bist;
	 	Rn=2*hamb_rest+0.9*pizza_rest;
	 	min=C1;
	 	if(C2<min && C2<C3){
	 		min=C2;
	 	} else if(C3<min){
	 		min=C3;
	 	}
	 	printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", min);}
	 
	if((Tarik=='H' && Bojan=='H' && Mirza=='C') || (Tarik=='H' && Bojan=='C' && Mirza=='H') || (Tarik=='C' && Bojan=='H' && Mirza=='H')){
		C1=2*hamb_rest+cev_rest;
		C2=2*hamb_fast+cev_fast;
		C3=2*hamb_bist+cev_bist;
		min=C2;
		if(C1<min && C1<C3){
			min=C1;
		} else if(C3<min){
			min=C3;
		}
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", min); }
		
	if((Tarik=='H' && Bojan=='C' && Mirza=='C') || (Tarik=='C' && Bojan=='H' && Mirza=='C') || (Tarik=='C' && Bojan=='C' && Mirza=='H')){
		C1=2*cev_rest+hamb_rest;
		C2=2*cev_fast+hamb_fast;
		C3=2*cev_bist+hamb_bist;
		min=C2;
		if(C1<min && C1<C3){
			min=C1;
		} else if(C3<min){
			min=C3;
		}
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", min); }
	
	if((Tarik=='C' && Bojan=='C' && Mirza=='P') || (Tarik=='C' && Bojan=='P' && Mirza=='C') || (Tarik=='P' && Bojan=='C' && Mirza=='C')){
		C1=2*cev_rest+pizza_rest;
		C2=2*cev_fast+pizza_fast;
		C3=2*cev_bist+pizza_bist;
		min=C2;
		if(C1<min && C1<C3){
			min=C1;
		} else if(C3<min){
			min=C3;
		}
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", min); }
		
		
	return 0; }
		   
	
	
	
	
