#include <stdio.h>

int main() {
	
	char tarik, bojan, mirza, nred;
	
	/*Unos*/
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &tarik);
	scanf("%c", &nred);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &bojan);
	scanf("%c", &nred);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &mirza);
	
	/*Cjenovnik*/
	float pizza_rest = 6.80, pizza_ffood = 8.00, pizza_bistro = 5.30;
	float hamb_rest = 3.30, hamb_ffood = 3.00, hamb_bistro = 5.00;
	float cev_rest = 5.00, cev_ffood = 3.90, cev_bistro = 6.00;
	
	/*Ukupne cijene za svaki lokal posebno*/
	float c_rest = 0, c_ffood = 0, c_bistro = 0;
	
	//Sracunati cijene za svakog od drugova u svakom lokalu
	switch(tarik){
		case 'P': 
			c_rest += pizza_rest;
			c_ffood += pizza_ffood;
			c_bistro += pizza_bistro;
			break;
		case 'H': 
			c_rest += hamb_rest;
			c_ffood += hamb_ffood;
			c_bistro += hamb_bistro;
			break;
		case 'C': 
			c_rest += cev_rest;
			c_ffood += cev_ffood;
			c_bistro += cev_bistro;
			break;
	}
	switch(bojan){
		case 'P': 
			c_rest += pizza_rest;
			c_ffood += pizza_ffood;
			c_bistro += pizza_bistro;
			break;
		case 'H': 
			c_rest += hamb_rest;
			c_ffood += hamb_ffood;
			c_bistro += hamb_bistro;
			break;
		case 'C': 
			c_rest += cev_rest;
			c_ffood += cev_ffood;
			c_bistro += cev_bistro;
			break;
	}
	switch(mirza){
		case 'P': 
			c_rest += pizza_rest;
			c_ffood += pizza_ffood;
			c_bistro += pizza_bistro;
			break;
		case 'H': 
			c_rest += hamb_rest;
			c_ffood += hamb_ffood;
			c_bistro += hamb_bistro;
			break;
		case 'C': 
			c_rest += cev_rest;
			c_ffood += cev_ffood;
			c_bistro += cev_bistro;
			break;
	}
	
	
	/*Nadji najjeftini lokal*/
	float c_min;
	
	if(c_ffood < c_rest && c_ffood < c_bistro) c_min = c_ffood;
	else if(c_bistro < c_rest && c_bistro < c_ffood) c_min = c_bistro;
	else if(c_rest < c_bistro && c_rest < c_ffood) c_min = c_rest;
	
	
	/*Popust time*/
	if(c_min == c_rest){
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", c_rest);	
	}else{
		/*Ispisi najjeftiniji*/
		if(c_min == c_ffood) printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", c_ffood);
		else if(c_min == c_bistro) printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", c_bistro);
		
		/*Najmanja cijena s popustom*/
		if(tarik == 'P' || bojan == 'P' || mirza == 'P'){
			if(tarik == 'P') c_rest -= pizza_rest * 0.1;
			if(bojan == 'P') c_rest -= pizza_rest * 0.1;
			if(mirza == 'P') c_rest -= pizza_rest * 0.1;
		} else if(tarik == 'C' || bojan == 'C' || mirza == 'C'){
			if(tarik == 'C') c_rest -= cev_rest * 0.1;
			if(bojan == 'C') c_rest -= cev_rest * 0.1;
			if(mirza == 'C') c_rest -= cev_rest * 0.1;
		} else if(tarik == 'H' || bojan == 'H' || mirza == 'H'){
			if(tarik == 'H') c_rest -= hamb_rest * 0.1;
			if(bojan == 'H') c_rest -= hamb_rest * 0.1;
			if(mirza == 'H') c_rest -= hamb_rest * 0.1;
		}
		
		/*Ponovo traziti najjeftiniji lokal, nakon uracunatog popusta*/
		if(c_rest < c_min) {
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", c_rest);
		}
	}
	
	
	
	return 0;
}
