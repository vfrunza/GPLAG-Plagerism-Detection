#include <stdio.h>
#define PK 6.80
#define HK 3.30		/*"Kod konja i konjusara"*/
#define CK 5.00
#define PT 8.00
#define HT 3.00		/*"Trovac"*/
#define CT 3.90
#define PL 5.30
#define HL 5.00		/*Lorelei*/
#define CL 6.00


int main() {
	float R,P,K;
	char a,b,c;
	printf("Unesite jelo za Tarika: ");
	scanf(" %c",&a);
	printf("Unesite jelo za Bojana: ");
	scanf(" %c",&b);
	printf("Unesite jelo za Mirzu: ");
	scanf(" %c", &c);
	
	printf("Najjeftiniji je ");
	
	if(a=='H'&&b=='H'&&c=='H'){
		printf("Fast-food \"Trovac\" (9.00 KM).");
		R=HT+HT+HT;
		K=HK+HK+HK;
		P=3*HK-(0.1*3*HK);
	}
	
	else if (a=='P'&&b=='P'&&c=='P'){
		printf("Bistro \"Lorelei\" (15.90 KM).");
		R=PL+PL+PL;
		K=PK+PK+PK;
		P=3*PK-(3*PK*0.1);
	}
	else if(a=='C'&& b=='C' && c=='C'){
		printf("Fast-food \"Trovac\" (11.70 KM).");
		R=CT+CT+CT;
		K=CK+CK+CK;
		P=3*CK-(3*CK*0.1);
	}
	
	else if(a!=b && b!=c && a!=c){
		printf("Fast-food \"Trovac\" (14.90 KM).");
		R=PT+CT+HT;
		K=PK+CK+HK;
		P=PK-0.1*PK+CK+HK;
	}
	
	else if((a=='P'&& c=='H' && b=='H') || (a=='H'&& b==a && c=='P') || (b=='P' && a==c && c=='H')) {
		printf("Restoran \"Kod konja i konjusara\" (13.40 KM).");
		R=PK+HK+HK;
		K=PK+HK+HK;
		P=PK-0.1*PK+HK+HK;
	}
	
	else if ((a=='P'&& b==c &&b=='C') || (b=='P'&& a==c && a=='C')||(c=='P' && a==b && a=='C')){
		printf("Fast-food \"Trovac\" (15.80 KM).");
		R=PT+CT+CT;
		K=PK+CK+CK;
		P=PK+2*CK-(2*CK*0.1);
	}
	else if((a=='H' &&b==c &&b=='P')||(b=='H' && a==c && a=='P') || (c=='H' && a==b && b=='P')){
		printf("Bistro \"Lorelei\" (15.60 KM).");
		R=HL+PL+PL;
		K=HK+PK+PK;
		P=2*PK-(2*0.1*PK)+HK;
	}
	else if((a=='H' && b==c && b=='C')||(b=='H' && a==c && a=='C') || (c=='H' && a==b && b=='C')){
		printf("Fast-food \"Trovac\" (10.80 KM).");
		R= HT+CT+CT;
		K=HK+CK+CK;
		P=CK-0.1*CK+CK+HK;
	}
	else if ((a=='C'&& b==c && b=='H')||(b=='C'&& a==c && c=='H')||(c=='C' && a==b && a=='H' )){
		printf("Fast-food \"Trovac\" (9.90 KM).");
		R=CT+HT+HT;
		K=CK+HK+HK;
		P=2*HK-(2*0.1*HK)+CK;
	}
	else if ((a=='C'&& b==c && b=='P')||(b=='C'&& a==c && c=='P') || (c=='C' && a==b && b=='P')){
		printf("Bistro \"Lorelei\" (16.60 KM).");
		R=CL+PL+PL;
		K=CK+PK+PK;
		P=2*PK-(2*0.1*PK)+CK;
	}
	
	if(P<R && R<K){
		printf("\nSa popustom bi Restoran bio jeftiniji (%g KM).",P);
		}
	return 0;
}
