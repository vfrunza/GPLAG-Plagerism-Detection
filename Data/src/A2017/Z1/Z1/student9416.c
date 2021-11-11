#include <stdio.h>
#include <math.h>
#define Pr 6.80
#define Hr 3.30
#define Cr 5.00
#define Pf 8.00
#define Hf 3.00
#define Cf 3.90
#define Pb 5.30
#define Hb 5.00
#define Cb 6.00
#define e 0.00001

int main() {
	char T, B, M, n;
	int brojac_P=0, brojac_H=0, brojac_C=0;
	double cijena_restorana=0, cijena_f_f=0, cijena_bistro=0, najjeftiniji=0, restoran_sa_popustom=0, t=0;
	
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &T);
	scanf("%c",&n);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &B);
	scanf("%c",&n);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c",&M);
	scanf("%c",&n);
	
	if(T=='P'){
		cijena_restorana+=Pr;
		cijena_f_f+=Pf;
		cijena_bistro+=Pb;
		brojac_P++;
	}
	
	if(T=='H'){
		cijena_restorana+=Hr;
		cijena_f_f+=Hf;
		cijena_bistro+=Hb;
		brojac_H++;
	}
	
	if(T=='C'){
		cijena_restorana+=Cr;
		cijena_f_f+=Cf;
		cijena_bistro+=Cb;
		brojac_C++;
	}
	
	if(B=='P'){
		cijena_restorana+=Pr;
		cijena_f_f+=Pf;
		cijena_bistro+=Pb;
		brojac_P++;
	}
	
	if(B=='H'){
		cijena_restorana+=Hr;
		cijena_f_f+=Hf;
		cijena_bistro+=Hb;
		brojac_H++;
	}
	
	if(B=='C'){
		cijena_restorana+=Cr;
		cijena_f_f+=Cf;
		cijena_bistro+=Cb;
		brojac_C++;
	}
	
	if(M=='P'){
		cijena_restorana+=Pr;
		cijena_f_f+=Pf;
		cijena_bistro+=Pb;
		brojac_P++;
	}
	
	if(M=='H'){
		cijena_restorana+=Hr;
		cijena_f_f+=Hf;
		cijena_bistro+=Hb;
		brojac_H++;
	}
	if(M=='C'){
		cijena_restorana+=Cr;
		cijena_f_f+=Cf;
		cijena_bistro+=Cb;
		brojac_C++;
	}
	
	najjeftiniji=cijena_restorana;
	if(cijena_bistro<najjeftiniji){najjeftiniji=cijena_bistro;}
	if(cijena_f_f<najjeftiniji){najjeftiniji=cijena_f_f;}
	
	if(fabs(najjeftiniji-cijena_restorana)>e){
		t=brojac_P*Pr;
		if(brojac_H*Hr>t){t=brojac_H*Hr;}
		if(brojac_C*Cr>t){t=brojac_C*Cr;}
		
		restoran_sa_popustom=cijena_restorana-0.1*t;
	}
	
	if(fabs(najjeftiniji-cijena_restorana)<e)
	{
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", cijena_restorana);
	}
	
	if(fabs(najjeftiniji-cijena_bistro)<e){
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", cijena_bistro);
		if(restoran_sa_popustom<cijena_bistro){
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", restoran_sa_popustom);
		}
	}
	
	if(fabs(najjeftiniji-cijena_f_f)<e){
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", cijena_f_f);
		if(restoran_sa_popustom<cijena_f_f){
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", restoran_sa_popustom);
		}
	}
	return 0;
}
