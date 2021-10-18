#include <stdio.h>

int main() {
	char t,b,m,novi_red;
	int p=0,h=0,c=0;
		printf("Unesite jelo za Tarika: ");
		scanf("%c", &t);
		scanf("%c", &novi_red);
		printf("Unesite jelo za Bojana: ");
		scanf("%c", &b);
		scanf("%c", &novi_red);
		printf("Unesite jelo za Mirzu: ");
		scanf("%c", &m);
		
		if(t=='P') p++;
		if(t=='H') h++;
		if(t=='C') c++;
		if(b=='P') p++;
		if(b=='H') h++;
		if(b=='C') c++;
		if(m=='P') p++;
		if(m=='H') h++;
		if(m=='C') c++;
		
		
		float rest,fast,bistro;
		rest=p*6.8 + h*3.3 + c*5.0;
		fast=p*8.0 + h*3.0 + c*3.9;
		bistro=p*5.3 +h*5.0 + c*6.0;
		
		float min=10000;
		if(rest<=fast && rest<=bistro) min=rest;
		else if(bistro<=fast && bistro<=rest) min=bistro;
		else min=fast;
		float rest2=rest;
		if(rest>min) {
			
			if(p!=0)rest2=p*6.8*0.9 + h*3.3 +c*5.0;
							else if( c!=0) rest2=p*6.8 + h*3.3 + c*5.0*0.9;
							
							else rest2=p*6.8 + h*3.3*0.9 + c*5.0;
			}
			
			if(min==rest) printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",rest);
			else if(min==fast) printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",fast);
			else if(min==bistro) printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",bistro);
			if(min!=rest && rest2<min) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",rest2);
			
		
	return 0;
}
