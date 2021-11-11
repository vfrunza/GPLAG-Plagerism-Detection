#include <stdio.h>

int main() {
	char t,b,m,novi_red;
	int broj;
	double p_k_k=6.80,p_t=8,p_l=5.30; // CJENE PIZZA ODGOVARAJUCIH RESTORANA 
	double h_k_k=3.30,h_t=3,h_l=5; //CJENE HAMBURGERA ODGOVARAJUCIH RESTORANA
	double c_k_k=5,c_t=3.90,c_l=6; //CJENE CEVAPA ODGOVARAJUCIH RESTORANA
	double cjena,cjenak,cjena_sa_popustom;
	int jeste=0;
	    //UNOS ODGOVARAJUCIH JELA
	printf("Unesite jelo za Tarika: ");    
	scanf("%c",&t);
	scanf("%c",&novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c",&b);
	scanf("%c",&novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c",&m);
	scanf("%c",&novi_red);
	broj=t+b+m; //UZIMANJE ASCII VREDNOSTI ODGOVARAJUCIH CHAROVA
	if(broj==('H'+'H'+'H') || broj==('H'+'C'+'C') || broj==('P'+'C'+'C') || broj==('C'+'C'+'C') || broj==('C'+'H'+'P') || broj==('C'+'H'+'H')){
		printf("Najjeftiniji je Fast-food \"Trovac\" ");
	
	//U svakom uslovu pronalazimo cjenu i provjeravamo da li bi bila jeftinija sa popustom u restoranu.
	if (broj==('H'+'H'+'H')){
		cjena=3*h_t;
		cjenak=3*h_k_k;
		cjenak=cjenak-(0.1*h_k_k)*3;
		if(cjenak<cjena){cjena_sa_popustom=cjenak; jeste=1;}
		
	}
	else if(broj==('H'+'C'+'C')){
		cjena=h_t+2*c_t;
		cjenak=h_k_k+2*c_k_k;
		cjenak=cjenak-(0.1*c_k_k)*2;
		if(cjenak<cjena){cjena_sa_popustom=cjenak; jeste=1;}
		
	}
		else if(broj==('P'+'C'+'C')){
			cjena=p_t+2*c_t;
			cjenak=p_k_k+2*c_k_k;
			cjenak=cjenak-(0.1)*p_k_k;
			if(cjenak<cjena){cjena_sa_popustom=cjenak; jeste=1;}
		}
		else if(broj==('C'+'C'+'C')){
			cjena=3*c_t;
			cjenak=3*c_k_k;
		}
		else if(broj==('C'+'H'+'P')){
			cjena=c_t+h_t+p_t;
		cjenak=h_k_k+c_k_k+p_k_k;
		cjenak=cjenak-(0.1)*p_k_k;
		if(cjenak<cjena){cjena_sa_popustom=cjenak; jeste=1;
		
	}
		}
		else if(broj==('C'+'H'+'H')){
			cjena=c_t+2*h_t;
			cjenak=2*h_k_k+c_k_k;
			cjenak=cjenak-(0.1*c_k_k)*2;
			if(cjenak<cjena){cjena_sa_popustom=cjenak; jeste=1;}
		}
	printf("(%.2lf KM).\n",cjena);
	
	if(jeste){
		printf("Sa popustom bi Restoran bio jeftiniji (%.2lf KM).",cjena_sa_popustom);
	}
	
		}
		//U OVIM USLOVIMA TAKODZE 
		else if(broj==('H'+'P'+'P') || broj==('P'+'P'+'P') || broj==('P'+'P'+'C')){
			printf("Najjeftiniji je Bistro \"Lorelei\" ");
		
	if(broj==('H'+'P'+'P')){
		cjena=h_l+p_l*2;
		cjenak=h_k_k+2*p_k_k;
		cjenak=cjenak-(0.1*p_k_k)*2;
		if(cjenak<cjena){cjena_sa_popustom=cjenak; jeste=1;}
	
	}
	else if (broj==('P'+'P'+'P')){
		cjena=3*p_l;
		cjenak=3*p_k_k;
		cjenak=cjenak-(0.1*p_k_k)*3;
		if(cjenak<cjena){jeste=1; cjena_sa_popustom=cjenak;}
	}
	else if(broj==('P'+'P'+'C')){
		cjena=2*p_l+c_l;
		cjenak=2*p_k_k+c_k_k;
		cjenak=cjenak-(0.1*p_k_k)*2;
		if(cjenak<cjena){cjena_sa_popustom=cjenak; jeste=1;}
		
	}
	printf("(%.2lf KM).\n",cjena);
	if(jeste){
		printf("Sa popustom bi Restoran bio jeftiniji (%.2lf KM).",cjena_sa_popustom);
	}}

else {
	printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" ");
	if(broj==('H'+'H'+'P'))cjena=h_k_k*2 + p_k_k;
	printf("(%.2lf KM).\n",cjena);
}
	return 0;
}












