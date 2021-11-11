#include <stdio.h>
#include <math.h>
#define PK 6.80
#define PT 8.00
#define PL 5.30
#define HK 3.30
#define HT 3.00
#define HL 5.00
#define CK 5.00
#define CT 3.90
#define CL 6.00
#define procenat 10
#define tolerancija 0.00001
int main() {
	float racun;
	float x,y;
	char a,b,c,novi_red;
	char i[] = "Bistro \"Lorelei\"";
	char j[] = "Restoran \"Kod konja i konjusara\"";
	char k[] = "Fast-food \"Trovac\"";
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &a);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &b);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &c);
	scanf("%c", &novi_red);
	
	
	if(a=='P' && b=='P' && c=='P'){
		racun=3*PL;
		printf("Najjeftiniji je %s (%.2f KM).",i,racun);
		x=PK+PK+PK;
		y=(x-((procenat*PK)/100));
		
		if(y<racun && fabs(y-racun)>tolerancija && fabs(x-racun)>tolerancija){
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM)",y);
		}
	}
	else if(a=='H' && b=='H' && c=='H'){
		racun=3*HT;
		printf("Najjeftiniji je %s (%.2f KM).\n",k, racun);
		x=3*HK;
		y=(x-((procenat*3*HK)/100));
		if(y<racun && fabs(y-racun)>tolerancija && fabs(x-racun)>tolerancija){
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",y);
		}
	}
	else if(a=='C' && b=='C' && c=='C'){
		racun=3*CT;
		printf("Najjeftiniji je %s (%.2f KM).\n", k, racun);
		x=3*CK;
		y=(x-((procenat*3*CK)/100));
		if(y<racun && fabs(y-racun)>tolerancija && fabs(x-racun)>tolerancija){
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",y);
		}
		
	}
	else if(a=='P' && b=='P' && c=='H'){
		racun=2*PL+HL;
		printf("Najjeftiniji je %s (%.2f KM).\n",i, racun);
		x=2*PK+HK;
		y=(x-((procenat*2*PK)/100));
		if(y<racun && fabs(y-racun)>tolerancija && fabs(x-racun)>tolerancija){
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", y);
		}
	}
	else if(a=='P' && b=='H' && c=='P'){
		racun=2*PL+HL;
		printf("Najjeftiniji je %s (%.2f KM).\n",i, racun);
		x=2*PK+HK;
		y=(x-((procenat*2*PK)/100));
		if(y<racun && fabs(y-racun)>tolerancija && fabs(x-racun)>tolerancija){
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",y);
		}
	}
	else if(a=='H' && b=='P' && c=='P'){
		racun=2*PL+HL;
		printf("Najjeftiniji je %s (%.2f KM).\n",i, racun);
		x=2*PK+HK;
		y=(x-((procenat*2*PK)/100));
		if(y<racun && fabs(y-racun)>tolerancija && fabs(x-racun)>tolerancija){
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",y);
		}
	}
	else if(a=='H' && b=='H' && c=='P'){
		racun=2*HK+PK;
		printf("Najjeftiniji je %s (%.2f KM).\n",j, racun);
		x=2*HK+PK;
		y=(x-((procenat*PK)/100));
		if(y<racun && fabs(y-racun)>tolerancija && fabs(x-racun)>tolerancija){
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",y);
		}
	}
	else if(a=='H' && b=='P' && c=='H'){
		racun=2*HK+PK;
		printf("Najjeftiniji je %s (%.2f KM).\n",j,racun);
		x=2*HK+PK;
		y=(x-((procenat*PK)/100));
		if(y<racun && fabs(y-racun)>tolerancija && fabs(x-racun)>tolerancija){
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",y);
		}
	}
	else if(a=='P' && b=='H' && c=='H'){
		racun=2*HK+PK;
		printf("Najjeftiniji je %s (%.2f KM).\n",j,racun);
		x=2*HK+PK;
		y=(x-((procenat*PK)/100));
		if(y<racun && fabs(y-racun)>tolerancija && fabs(x-racun)>tolerancija){
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",y);
		}
	}
	else if(a=='C' && b=='C' && c=='H'){
		racun=2*CT+HT;
		printf("Najjeftiniji je %s (%.2f KM).\n",k, racun);
		x=2*CK+HK;
		y=(x-((procenat*2*CK)/100));
		if(y<racun && fabs(y-racun)>tolerancija && fabs(x-racun)>tolerancija){
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",y);
		}
	}
	else if(a=='C' && b=='H' && c=='C'){
		racun=2*CT+HT;
		printf("Najjeftiniji je %s (%.2f KM).\n",k,racun);
		x=2*CK+HK;
		y=(x-((procenat*2*CK)/100));
		if(y<racun && fabs(y-racun)>tolerancija && fabs(x-racun)>tolerancija){
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM)",y);
		}
	}
	else if(a=='H' && b=='C' && c=='C'){
		racun=2*CT+HT;
		printf("Najjeftiniji je %s (%.2f KM).\n",k, racun);
		x=2*CK+HK;
		y=(x-((procenat*2*CK)/100));
		if(y<racun && fabs(y-racun)>tolerancija && fabs(x-racun)>tolerancija){
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",y);
		}
	}
	else if(a=='C' && b=='C' && c=='P'){
		racun=2*CT+PT;
		printf("Najjeftiniji je %s (%.2f KM).\n",k, racun);
		x=2*CK+PK;
		y=(x-((procenat*2*CK)/100));
		if(y<racun && fabs(y-racun)>tolerancija && fabs(x-racun)>tolerancija){
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",y);
		}
	}
	else if(a=='C' && b=='P' && c=='C'){
		racun=2*CT+PT;
		printf("Najjeftiniji je %s (%.2f KM).\n",k, racun);
		x=2*CK+PK;
		y=(x-((procenat*2*CK)/100));
		if(y<racun && fabs(y-racun)>tolerancija && fabs(x-racun)>tolerancija){
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",y);
		}
		
	}
	else if(a=='P' && b=='C' && c=='C'){
		racun=2*CT+PT;
		printf("Najjeftiniji je %s (%.2f KM).\n", k, racun);
		x=2*CK+PK;
		y=(x-((procenat*2*CK)/100));
		if(y<racun && fabs(y-racun)>tolerancija && fabs(x-racun)>tolerancija){
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",y);
		}
	}
	else if(a=='H' && b=='H' && c=='C'){
		racun=2*HT+CT;
		printf("Najjeftiniji je %s (%.2f KM).\n", k, racun);
		x=2*HK+CK;
		y=(x-((procenat*2*HK)/100));
		if(y<racun && fabs(y-racun)>tolerancija && fabs(x-racun)>tolerancija){
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",y);
		}
	}
	else if(a=='H' && b=='C' && c=='H'){
		racun=2*HT+CT;
		printf("Najjeftiniji je %s (%.2f KM).\n", k, racun);
		x=2*HK+CK;
		y=(x-((procenat*2*HK)/100));
		if(y<racun && fabs(y-racun)>tolerancija && fabs(x-racun)>tolerancija){
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",y);
		}
	}
	else if(a=='C' && b=='H' && c=='H'){
		racun=2*HT+CT;
		printf("Najjeftiniji je %s (%.2f KM).\n",k, racun);
		x=2*HK+CK;
		y=(x-((procenat*2*HK)/100));
		if(y<racun && fabs(y-racun)>tolerancija && fabs(x-racun)>tolerancija){
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",y);
		}
	}
	else if(a=='P' && b=='P' && c=='C'){
		racun=2*PL+CL;
		printf("Najjeftiniji je %s (%.2f KM).\n", i,racun);
		x=2*PK+CK;
		y=(x-((procenat*2*PK)/100));
		if(y<racun && fabs(y-racun)>tolerancija && fabs(x-racun)>tolerancija){
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",y);
		}
	}
	else if(a=='P' && b=='C' && c=='P'){
		racun=2*PL+CL;
		printf("Najjeftiniji je %s (%.2f KM).\n", i, racun);
		x=2*PK+CK;
		y=(x-((procenat*2*PK)/100));
		if(y<racun && fabs(y-racun)>tolerancija && fabs(x-racun)>tolerancija){
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",y);
		}
	}
	else if(a=='C' && b=='P' && c=='P'){
		racun=2*PL+CL;
		printf("Najjeftiniji je %s (%.2f KM).\n", i, racun);
		x=2*PK+CK;
		y=(x-((procenat*2*PK)/100));
		if(y<racun && fabs(y-racun)>tolerancija && fabs(x-racun)>tolerancija){
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM.)",y);
		}
	}
	else if(a=='C' && b=='H'&& c=='P'){
		racun=PT+HT+CT;
		printf("Najjeftiniji je %s (%.2f KM).\n", k, racun);
		x=PK+HK+CK;
		y=(x-((procenat*PK)/100));
		if(y<racun && fabs(y-racun)>tolerancija && fabs(x-racun)>tolerancija){
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", y);
		}
		
	}
	else if(a=='P' && b=='H' && c=='C'){
		racun=PT+HT+CT;
		printf("Najjeftiniji je %s (%.2f KM).\n",k, racun);
		x=PK+HK+CK;
		y=(x-((procenat*PK)/100));
		if(y<racun && fabs(y-racun)>tolerancija && fabs(x-racun)>tolerancija){
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", y);
		}
	}
	else if(a=='P' && b=='C' && c=='H'){
		racun=PT+HT+CT;
		printf("Najjeftiniji je %s (%.2f KM).\n", k, racun);
		x=PK+HK+CK;
		y=(x-((procenat*PK)/100));
		if(y<racun && fabs(y-racun)>tolerancija && fabs(x-racun)>tolerancija){
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", y);
		}
	}
	else if(a=='H' && b=='P' && c=='C'){
		racun=PT+HT+CT;
		printf("Najjeftiniji je %s (%.2f KM).\n", k, racun);
		x=PK+HK+CK;
		y=(x-((procenat*PK)/100));
		if(y<racun && fabs(y-racun)>tolerancija && fabs(x-racun)>tolerancija){
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",y);
		}
	}
	else if(a=='C' && b=='P' && c=='H'){
		racun=PT+HT+CT;
		printf("Najjeftiniji je %s (%.2f KM).\n", k,racun);
		x=CK+HK+PK;
		y=(x-((procenat*PK)/100));
		if(y<racun && fabs(y-racun)>tolerancija && fabs(x-racun)>tolerancija){
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",y);
		}
	}
	else if(a=='H' && b=='C' && c=='P'){
		racun=PT+CT+HT;
		printf("Najjeftiniji je %s (%.2f KM).\n",k,racun);
		x=CK+PK+HK;
		y=(x-(procenat*PK)/100);
		if(y<racun && fabs(y-racun)>tolerancija && fabs(x-racun)>tolerancija){
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",y);
		}
	}
	return 0;
}