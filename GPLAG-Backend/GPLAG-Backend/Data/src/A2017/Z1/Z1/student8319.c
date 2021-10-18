#include <stdio.h>

int main() {
	char t,b,m,nr;
	double restoran=0,fastfood=0,bistro=0;
	double p1=6.80,h1=3.30,c1=5.00,p2=8.00,h2=3.00,c2=3.90,p3=5.30,h3=5.00,c3=6.00;
	int br1=1,br2=1,br3=1;
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &t);
	scanf("%c", &nr);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &b);
	scanf("%c", &nr);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &m);
	scanf("%c", &nr);
	
	if(t=='P' || b=='P' || m=='P') {
		if(t=='P' && m=='P' && b!='P'|| t=='P' && b=='P' && m!='P'|| b=='P' && m=='P' && t!='P') br1=2;
		else if(t=='P' && b=='P' && m=='P') br1=3;
		else br1=1;
		restoran+=p1*br1;
		fastfood+=p2*br1;
		bistro+=p3*br1;
	}
	
	if(t=='H' || b=='H' || m=='H') {
		if(t=='H' && m=='H' && b!='H' || t=='H' && b=='H' && m!='H' || b=='H' && m=='H' && t!='H') br2=2;
		else if(t=='H' && b=='H' && m=='H') br2=3;
		else br2=1;
		restoran+=h1*br2;
		fastfood+=h2*br2;
		bistro+=h3*br2;
	}
	
	if(t=='C' || b=='C' || m=='C') {
		if(t=='C' && m=='C' && b!='C' || t=='C' && b=='C' && m!='C'|| b=='C' && m=='C' && t!='C') br3=2;
		else if(t=='C' && b=='C' && m=='C') br3=3;
		else br3=1;
		restoran+=c1*br3;
		fastfood+=c2*br3;
		bistro+=c3*br3;
	}
	
	if(fastfood<restoran && fastfood<bistro)
	printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", fastfood);
	
	else if(restoran<fastfood && restoran<bistro)
	printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", restoran);
	
	else if(bistro<restoran && bistro<fastfood)
	printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", bistro);
	
	if(restoran>fastfood || restoran>bistro) {
		restoran-=(p1*0.1)*br1;
		if(restoran<fastfood && restoran<bistro)
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", restoran);
		else if(restoran>fastfood || restoran>bistro) {
			restoran+=(p1*0.1)*br1;
			restoran-=(h1*0.1)*br2;
			if(restoran<fastfood && restoran<bistro)
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", restoran);
			else if(restoran>fastfood || restoran>bistro) {
				restoran+=(h1*0.1)*br2;
				restoran-=(c1*0.1)*br3;
				if(restoran<fastfood && restoran<bistro){
					printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", restoran);
				}
			}
		}
	}
	
	return 0;
}
