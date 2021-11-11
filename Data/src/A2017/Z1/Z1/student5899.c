#include <stdio.h>
#define P1 6.80
#define P2 8.00
#define P3 5.30
#define H1 3.30
#define H2 3.00
#define H3 5.00
#define C1 5.00
#define C2 3.90
#define C3 6.00

int main() {
	char Bojan,Tarik,Mirza,novired,navodnik1='"',navodnik2='"';
	double Tarik1=0,Bojan1=0,Mirza1=0,Tarik2=0,Bojan2=0,Mirza2=0,Tarik3=0,Mirza3=0,Bojan3=0,Tarik1p=0,Bojan1p=0,Mirza1p=0, NP=0;
	double SumaKK=0,SumaT=0,SumaL=0,SumaKKp=0;
	printf("Unesite jelo za Tarika: ");
	scanf("%c",&Tarik);
	scanf("%c",&novired);
	printf("Unesite jelo za Bojana: ");
	scanf("%c",&Bojan);
	scanf("%c",&novired);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c",&Mirza);
	scanf("%c",&novired);
	if(Tarik=='P' ){
		Tarik1=P1;
	}else if(Tarik=='H') {
		Tarik1=H1;
		
	}else if(Tarik=='C') {
		Tarik1=C1;
		
	}
	if(Bojan=='P') {
		Bojan1=P1;
	}else if(Bojan=='H') {
		Bojan1=H1;
		
	} else if(Bojan=='C') {
		Bojan1=C1;
		
	}
	if(Mirza=='P')
	{
		Mirza1=P1;
		
	} else if(Mirza=='H') {
		Mirza1=H1;
		
	}else if(Mirza=='C') {
		Mirza1=C1; 
		
	}
	SumaKK=(SumaKK+Tarik1+Bojan1+Mirza1);
	
	if(P2!=P1 && H2!=H1 && C2!=C1){
		if(Tarik=='P'){
		Tarik2=P2;
		
	}else if(Tarik=='H'){
		Tarik2=H2;
		
	}else if(Tarik=='C') {
		Tarik2=C2;
		
	}
	if(Bojan=='P') {
		Bojan2=P2;
	} else if(Bojan=='H') {
		Bojan2=H2;
	} else if(Bojan=='C') {
		Bojan2=C2;
	}
	if(Mirza=='P') {
		Mirza2=P2;
	} else if(Mirza=='H') {
		Mirza2=H2;
	} else if(Mirza=='C') {
		Mirza2=C2;
		
	}
	SumaT=(SumaT+Tarik2+Bojan2+Mirza2);
	
	if(Tarik=='P'){
		Tarik3=P3;
		
	} else if(Tarik=='H'){
		Tarik3=H3;
	} else if(Tarik=='C') {
		Tarik3=C3;
	}
	if (Bojan=='P'){
		Bojan3=P3;
		
	} else if(Bojan=='H') {
		Bojan3=H3;
	} else if(Bojan=='C') {
		Bojan3=C3;
		
	}
	if(Mirza=='P'){
		Mirza3=P3;
	} else if(Mirza=='H') {
		Mirza3=H3;
	} else if(Mirza=='C') {
		Mirza3=C3; 
		
	}
	SumaL=(SumaL+Tarik3+Bojan3+Mirza3);
	}
	if(SumaL<SumaKK && SumaL<SumaT) {
	printf("Najjeftiniji je Bistro %cLorelei%c (%.2f KM).\n", navodnik1,navodnik2,SumaL);
	if(Tarik1>Bojan1 && Tarik1>Mirza1){
		Tarik1p=(Tarik1-Tarik1*(10./100));
		SumaKKp=(Tarik1p+Bojan1+Mirza1);
		if(SumaKKp<SumaL) 
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",SumaKKp);
		
	} else if(Bojan1>Tarik1 && Bojan1>Mirza1) {
		Bojan1p=(Bojan1-Bojan1*(10./100));
		SumaKKp=(Tarik1+Bojan1p+Mirza);
		if(SumaKKp<SumaL) 
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",SumaKKp);
		
	} else if(Mirza1>Tarik1 && Mirza1>Bojan1) {
		Mirza1p=(Mirza1-Mirza1*(10./100));
		SumaKKp=(Tarik1+Bojan1+Mirza1p);
		if(SumaKKp<SumaL) 
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",SumaKKp);
	} else if(Tarik1< Bojan1 && Bojan1==Mirza1) {
		Bojan1p=(Bojan1- Bojan1*(10./100));
		SumaKKp=2*Bojan1p+Tarik1;
		if(SumaKKp<SumaL)
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",SumaKKp);
	}
	} else if(SumaKK<SumaL && SumaKK<SumaT) {
	printf("Najjeftiniji je Restoran %cKod konja i konjusara%c (%.2f KM).\n",navodnik1,navodnik2,SumaKK); 
	} else if(SumaT<SumaKK && SumaT<SumaL) {
	printf("Najjeftiniji je Fast-food %cTrovac%c (%.2f KM).\n",navodnik1,navodnik2, SumaT);
	if(Mirza1>Tarik1 && Mirza1>Bojan1) {
		Mirza1p=(Mirza1-Mirza1*(10./100));
		SumaKKp=Mirza1p+Tarik1+Bojan1;
		if(SumaKKp<SumaT)
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",SumaKKp);
	}else if(Tarik1==Bojan1 && Bojan1==Mirza1) {
		Tarik1p=(Tarik1-Tarik1*(10./100));
		SumaKKp=3*Tarik1p;
		if(SumaKKp<SumaT) {
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",SumaKKp);
		}
	}
	}
	
	return 0;
}
