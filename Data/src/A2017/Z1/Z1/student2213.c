#include <stdio.h>



int main() {
	char mirza,bojan,tarik;
	char novi_red;
	double p_kik, h_kik, c_kik, p_trovac, h_trovac, c_trovac, p_lorelei, h_lorelei, c_lorelei, p_kik_popust, h_kik_popust,c_kik_popust;
	double ukupna_kik,ukupna_trovac,ukupna_lorelei,min_cijena;
	int pizza,hamburger,cevap;
	ukupna_kik=0;
	ukupna_lorelei=0;
	ukupna_trovac=0;

	pizza=0;
	hamburger=0;
	cevap=0;
	
	p_kik=6.80;
	h_kik=3.30;
	c_kik=5.00;
	p_trovac=8.00;
	h_trovac=3.00;
	c_trovac=3.90;
	p_lorelei=5.30;
	h_lorelei=5.00;
	c_lorelei=6.00;
	p_kik_popust=6.12;
	h_kik_popust=2.97;
	c_kik_popust=4.50;
	
	
	printf("Unesite jelo za Tarika: ");
	scanf("%c",&tarik);
	scanf("%c",&novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c",&bojan);
	scanf("%c",&novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c",&mirza);
	scanf("%c",&novi_red);
	
	if(tarik=='P'){
		
		ukupna_kik+=p_kik;
		ukupna_trovac+=p_trovac;
		ukupna_lorelei+=p_lorelei;
		pizza++;
	}
	else if(tarik=='H'){
		ukupna_kik+=h_kik;
		ukupna_trovac+=h_trovac;
		ukupna_lorelei+=h_lorelei;
		hamburger++;
	}
	else {
		ukupna_kik+=c_kik;
		ukupna_trovac+=c_trovac;
		ukupna_lorelei+=c_lorelei;
		cevap++;
		
	}
	
	if(bojan=='P'){
		ukupna_kik+=p_kik;
		ukupna_trovac+=p_trovac;
		ukupna_lorelei+=p_lorelei;
		pizza++;
	}
	else if (bojan=='H'){
		ukupna_kik+=h_kik;
		ukupna_lorelei+=h_lorelei;
		ukupna_trovac+=h_trovac;
		hamburger++;
	}
	else{ 
	ukupna_kik+=c_kik;
	ukupna_trovac+=c_trovac;
	ukupna_lorelei+=c_lorelei;
		cevap++;
	}
	
	if(mirza=='P'){
		ukupna_kik+=p_kik;
		ukupna_trovac+=p_trovac;
		ukupna_lorelei+=p_lorelei;
		pizza++;
	}
	else if(mirza=='H'){
		ukupna_kik+=h_kik;
		ukupna_lorelei+=h_lorelei;
		ukupna_trovac+=h_trovac;
		hamburger++;
	}
	else {
		ukupna_trovac+=c_trovac;
		ukupna_lorelei+=c_lorelei;
		ukupna_kik+=c_kik;
		cevap++;
	}
	
	min_cijena=ukupna_kik;
	if(ukupna_trovac<min_cijena) min_cijena=ukupna_trovac;
	if(ukupna_lorelei<min_cijena) min_cijena=ukupna_lorelei;
	
	if(min_cijena==ukupna_lorelei){
		
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2lf KM).\n",ukupna_lorelei);
		
	}
	else if(min_cijena==ukupna_trovac){
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2lf KM).\n",ukupna_trovac);
		
	}
	else if(min_cijena==ukupna_kik){ 
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2lf KM).\n",ukupna_kik);
		
	}
	
	if(min_cijena!=ukupna_kik){
		
		
		double popust_na_pizzu, popust_na_hamburger, popust_na_cevape;
		popust_na_cevape=0;
		popust_na_hamburger=0;
		popust_na_pizzu=0;
		
		popust_na_pizzu=pizza*p_kik_popust+hamburger*h_kik+cevap*c_kik;
		popust_na_hamburger=pizza*p_kik+hamburger*h_kik_popust+cevap*c_kik;
		popust_na_cevape=pizza*p_kik+hamburger*h_kik+cevap*c_kik_popust;
		
		
		 double minimalna_s_popustom;
		 minimalna_s_popustom=0;
		 minimalna_s_popustom=popust_na_pizzu;
		 if(popust_na_cevape<minimalna_s_popustom) minimalna_s_popustom=popust_na_cevape;
		 if(popust_na_hamburger<minimalna_s_popustom) minimalna_s_popustom=popust_na_hamburger;
		 
		 ukupna_kik=minimalna_s_popustom;
		 if(ukupna_kik<min_cijena)
		 	printf("Sa popustom bi Restoran bio jeftiniji (%.2lf KM).",ukupna_kik);
		 	
		
		 
		 
	}
	

	return 0;
}
