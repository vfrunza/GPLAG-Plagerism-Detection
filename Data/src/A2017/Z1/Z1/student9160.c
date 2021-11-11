#include <stdio.h>


int main() {
	
	char T,B,M,nr;
	float suma1=0,suma2=0,suma3=0;
	int br1=0,br2=0,br3=0;
	float  P1=6.80,P2=8.00,P3=5.30,H1=3.30,H2=3.00,H3=5.00,C1=5.00,C2=3.90,C3=6.00;

	
	printf("Unesite jelo za Tarika: ");
	scanf("%c%c",&T,&nr);
	printf("Unesite jelo za Bojana: ");
	scanf("%c%c",&B,&nr);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c%c",&M,&nr);
	
	
	//TARIK
	if(T=='H'){
		suma1+=H1;
		suma2+=H2;
		suma3+=H3;
		br2++;
		
	}

	if(T=='P'){
		suma1+=P1;
		suma2+=P2;
		suma3+=P3;
		br1++;
	}

	if(T=='C'){
		suma1+=C1;
		suma2+=C2;
		suma3+=C3;
		br3++;
	}
	
	//BOJAN
	
	if(B=='C'){
		suma1+=C1;
		suma2+=C2;
		suma3+=C3;
		br3++;
	}
	
	
	if(B=='H'){
		suma1+=H1;
		suma2+=H2;
		suma3+=H3;
		br2++;
	}
	
	
	if(B=='P'){
		suma1+=P1;
		suma2+=P2;
		suma3+=P3;
		br1++;
	}
	
	//MIRZA
	if(M=='C'){
		suma1+=C1;
		suma2+=C2;
		suma3+=C3;
		br3++;
	}
	
	if(M=='H'){
		suma1+=H1;
		suma2+=H2;
		suma3+=H3;
		br2++;
	}
	
	if(M=='P'){
		suma1+=P1;
		suma2+=P2;
		suma3+=P3;
		br1++;
	}
	
	if(suma1<suma2 && suma1<suma3)printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",suma1);
	else if(suma1>suma2 && suma3>suma2) {
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",suma2);
		P1*=br1;
		H1*=br2;
		C1*=br3;
		
		if(P1>H1 && P1>C1) P1*=0.9;
		else if(H1>P1 && H1>C1) H1*=0.9;
		else if(C1>P1 && C1>H1) C1*=0.9;
		suma1=P1+H1+C1;
		
		if(suma1<suma2) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",suma1);
		
	}
	
	else if(suma3<suma1 && suma3<suma2) {
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",suma3);
		
		P1*=br1;
		H1*=br2;
		C1*=br3;
		
		if(P1>H1 && P1>C1) P1*=0.9;
		else if(H1>P1 && H1>C1) H1*=0.9;
		else if(C1>P1 && C1>H1) C1*=0.9;
		suma1=P1+H1+C1;
		
		if(suma1<suma3) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",suma1);
	}
	
	return 0;
}
