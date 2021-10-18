#include <stdio.h>

int main() {
	char tarik, bojan, mirza, novi_red, qm=34;
	double suma1=0,suma2=0,suma3=0,popust_p=0.68,popust_h=0.33,popust_c=0.5,glavna_suma;
	int brojac_p=0,brojac_h=0,brojac_c=0;
	printf("Unesite jelo za Tarika: ");
	scanf("%c",&tarik);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c",&bojan);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c",&mirza);
	if(tarik=='P') {
		suma1+=6.8;
		suma2+=8.0;
		suma3+=5.3;
		brojac_p++;
	}
	else if(tarik=='H') {
		suma1+=3.3;
		suma2+=3;
		suma3+=5;
		brojac_h++;
	}
	else if(tarik=='C') {
		suma1+=5;
		suma2+=3.9;
		suma3+=6;
		brojac_c++;
	}
	if(bojan=='P') {
		suma1+=6.8;
		suma2+=8.0;
		suma3+=5.3;
		brojac_p++;
	}
	else if(bojan=='H') {
		suma1+=3.3;
		suma2+=3;
		suma3+=5;
		brojac_h++;
	}
	else if(bojan=='C') {
		suma1+=5;
		suma2+=3.9;
		suma3+=6;
		brojac_c++;
	}	
	if(mirza=='P') {
		suma1+=6.8;
		suma2+=8.0;
		suma3+=5.3;
		brojac_p++;
	}
	else if(mirza=='H') {
		suma1+=3.3;
		suma2+=3;
		suma3+=5;
		brojac_h++;
	}
	else if(mirza=='C') {
		suma1+=5;
		suma2+=3.9;
		suma3+=6;
		brojac_c++;
	}
	if(suma2<suma3) glavna_suma=suma2;
	else glavna_suma=suma3;
	if(suma1<glavna_suma) printf("Najjeftiniji je Restoran %cKod konja i konjusara%c (%.2f KM).",qm,qm,suma1);
	else {
		if(brojac_p>1) suma1-=brojac_p*popust_p;
		else if(brojac_h>1 && brojac_p==0) suma1-=brojac_h*popust_h;
		else if(brojac_c==3) suma1-=brojac_c*popust_c;
		else if(brojac_c==2) suma1-=brojac_c*popust_c;
		else suma1-=brojac_p*popust_p;
		if(suma1<glavna_suma) {
			if(glavna_suma==suma2){
				printf("Najjeftiniji je Fast-food %cTrovac%c (%.2f KM).\n",qm,qm,glavna_suma);
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",suma1);
			}
			else if(glavna_suma==suma3){
				printf("Najjeftiniji je Bistro %cLorelei%c (%.2f KM).\n",qm,qm,glavna_suma);
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",suma1);
			}
		}
		else {
			if(glavna_suma==suma2) printf("Najjeftiniji je Fast-food %cTrovac%c (%.2f KM).\n",qm,qm,glavna_suma);
			else if(glavna_suma==suma3) printf("Najjeftiniji je Bistro %cLorelei%c (%.2f KM).\n",qm,qm,glavna_suma);
		}
	}
	return 0;
}