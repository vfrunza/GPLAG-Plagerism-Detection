#include <stdio.h>
int main() {
	char tarik, bojan, mirza, novi_red;
	float maxVrijednost;
	float restoran = 0;
	float fastfud = 0;
	float bistro = 0;
	int ham = 0;
	int pic = 0;
	int cev = 0;
	int ham1,pic1,cev1;
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &tarik);
	scanf("%c", &novi_red);
	if(tarik == 'H'){
		ham++;
	}else if(tarik  == 'P'){
		pic++;
	}else if(tarik == 'C'){
		cev++;
	}
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &bojan);
	scanf("%c", &novi_red);
	if(bojan == 'H'){
		ham++;
	}else if(bojan  == 'P'){
		pic++;
	}else if(bojan == 'C'){
		cev++;
	}
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &mirza);
	scanf("%c", &novi_red);
	if(mirza == 'H'){
		ham++;
	}else if(mirza  == 'P'){
		pic++;
	}else if(mirza == 'C'){
		cev++;
	}
	/*----------------KOLIKO IMA CEGA----------------*/
	restoran =pic*6.80 + ham*3.30 + cev*5.00;
	fastfud = pic*8.00 + ham*3.00 + cev*3.90;
	bistro =  pic*5.30 + ham*5.00 + cev*6.00;
	if(mirza == 'H' ||tarik == 'H' ||bojan == 'H'){
		maxVrijednost = 3.30;
		ham1 = ham;
		pic1 = 1;
		cev1 = 1;
	}
	if(mirza == 'C' ||tarik == 'C' ||bojan == 'C'){
		maxVrijednost = 5.00;
		ham1 = 1;
		cev1 = cev;
		pic1 = 1;
	}
	if(mirza == 'P' ||tarik == 'P' ||bojan == 'P' ){
		maxVrijednost = 6.80;
		ham1 = 1;
		cev1 = 1;
		pic1 = pic;
	}
	
	if(restoran < fastfud && restoran < bistro){
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", restoran);
	}else if(fastfud < restoran && fastfud < bistro){
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", fastfud);
		if((restoran - ham1*pic1*cev1*(maxVrijednost*0.1) < fastfud)){
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",restoran - ham1*pic1*cev1*(maxVrijednost*0.1));
		}
	}else if (bistro < fastfud && bistro < restoran){
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", bistro);
		if((restoran - ham1*pic1*cev1*(maxVrijednost*0.1) < bistro)){
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",restoran - ham1*pic1*cev1*(maxVrijednost*0.1));
		}
	}
	return 0;
}
