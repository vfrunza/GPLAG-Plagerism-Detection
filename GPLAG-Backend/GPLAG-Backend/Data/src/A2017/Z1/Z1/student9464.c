#include <stdio.h>

int main() {

	char Tarik, Bojan, Mirza, novi_red;
	
	float s1, s2, s3, p1, p2, p3, h1, h2, h3, c1, c2, c3, popust, s;

	printf("Unesite jelo za Tarika: ");
	scanf("%c", &Tarik);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &Bojan);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &Mirza);
	scanf("%c", &novi_red);
	
	
	p1=6.80;
	p2=8.00;
	p3=5.30;
	
	h1=3.30;
	h2=3.00;
	h3=5.00;
	
	c1=5.00;
	c2=3.90;
	c3=6.00;

	if (Tarik=='P' && Bojan=='P' && Mirza=='P') {
		
		/*sume*/
		s1=3*p1;
		s2=3*p2;
		s3=3*p3;
		
		/*restoran najjeftiniji*/
		if (s1<s2 && s1<s3) {
		s=s1;
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", s1);
		}
		
		/*fast food najjeftiniji*/
		else if (s2<s3 && s2<s1){
		s=s2;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", s2);	
		} 

	    /*bistro najjeftiniji*/
		else {
		s=s3;
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", s3);
		}
		
		/*popust restoran*/
		popust=3*(p1-(p1*0.1));
		if (s1==s) {
			return 0;
		}
		else if(popust<s) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", popust);
	}
	

	if ((Tarik=='P' && Bojan=='P' && Mirza=='H') || (Tarik=='P' && Bojan=='H' && Mirza=='P') || (Tarik=='H' && Bojan=='P' && Mirza=='P')) {
		
		/*sume*/
		s1=2*p1+h1;
		s2=2*p2+h2;
		s3=2*p3+h3;
		
		/*restoran najjeftiniji*/
		if (s1<s2 && s1<s3) {
		s=s1;
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", s1);
		}
		
		/*fast food najjeftiniji*/
		else if (s2<s3 && s2<s1){
		s=s2;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", s2);	
		} 
		
		/*bistro najjeftiniji*/
		else {
		s=s3;
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", s3);
		}
		
		/*popust restoran*/
		popust=2*(p1-(p1*0.1))+h1;
		if (s1==s) {
			return 0;
		}
		else if(popust<s) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", popust);
	}
	
	
	if ((Tarik=='P' && Bojan=='P' && Mirza=='C') || (Tarik=='P' && Bojan=='C' && Mirza=='P') || (Tarik=='C' && Bojan=='P' && Mirza=='P')) {
		
		/*sume*/
		s1=2*p1+c1;
		s2=2*p2+c2;
		s3=2*p3+c3;
		
		/*restoran najjeftiniji*/
		if (s1<s2 && s1<s3) {
		s=s1;
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", s1);
		}
		
		/*fast food najjeftiniji*/
		else if (s2<s3 && s2<s1){
		s=s2;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", s2);	
		} 
		
		/*bistro najjeftiniji*/
		else {
		s=s3;
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", s3);
		}
		
		/*popust restoran*/
		popust=2*(p1-(p1*0.1))+c1;
		if (s1==s) {
			return 0;
		}
		else if(popust<s) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", popust);
		
		
	}
	
	if ((Tarik=='P' && Bojan=='H' && Mirza=='H') || (Tarik=='H' && Bojan=='H' && Mirza=='P') || (Tarik=='H' && Bojan=='P' && Mirza=='H')) {
		
		/*sume*/
		s1=2*h1+p1;
		s2=2*h2+p2;
		s3=2*h3+p3;
		
		/*restoran najjeftiniji*/
		if (s1<s2 && s1<s3) {
		s=s1;
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", s1);
		}
		
		/*fast food najjeftiniji*/
		else if (s2<s3 && s2<s1){
		s=s2;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", s2);	
		} 
		
		/*bistro najjeftiniji*/
		else {
		s=s3;
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", s3);
		}
		
		/*popust restoran*/
		popust=2*(h1-(h1*0.1))+p1;
		if (s1==s) {
			return 0;
		}
		else if(popust<s) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", popust);
	
	}	
	
	if ((Tarik=='P' && Bojan=='C' && Mirza=='C') || (Tarik=='C' && Bojan=='C' && Mirza=='P') || (Tarik=='C' && Bojan=='P' && Mirza=='C')) {
			
		/*sume*/
		s1=2*c1+p1;
		s2=2*c2+p2;
		s3=2*c3+p3;
		
		/*restoran najjeftiniji*/
		if (s1<s2 && s1<s3) {
		s=s1;
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", s1);
		}
		
		/*fast food najjeftiniji*/
		else if (s2<s3 && s2<s1){
		s=s2;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", s2);	
		} 
		
		/*bistro najjeftiniji*/
		else {
		s=s3;
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", s3);
		}
		
		/*popust restoran*/
		popust=2*(c1-(c1*0.1))+p1;
		if (s1==s) {
			return 0;
		}
		else if(popust<s) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", popust);
		
	}
	

	
	if (Tarik=='H' && Bojan=='H' && Mirza=='H') {
			
		/*sume*/
		s1=3*h1;
		s2=3*h2;
		s3=3*h3;
		
		/*restoran najjeftiniji*/
		if (s1<s2 && s1<s3) {
		s=s1;
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", s1);
		}
		
		/*fast food najjeftiniji*/
		else if (s2<s3 && s2<s1){
		s=s2;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", s2);	
		} 
		
		/*bistro najjeftiniji*/
		else {
		s=s3;
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", s3);
		}
		
		/*popust restoran*/
		popust=3*(h1-(h1*0.1));
		if (s1==s) {
			return 0;
		}
		else if(popust<s) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", popust);
		
	}
		
	if ((Tarik=='H' && Bojan=='H' && Mirza=='C') || (Tarik=='H' && Bojan=='C' && Mirza=='H') || (Tarik=='C' && Bojan=='H' && Mirza=='H')) {
			
		/*sume*/
		s1=2*h1+c1;
		s2=2*h2+c2;
		s3=2*h3+c3;
		
		/*restoran najjeftiniji*/
		if (s1<s2 && s1<s3) {
		s=s1;
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", s1);
		}
		
		/*fast food najjeftiniji*/
		else if (s2<s3 && s2<s1){
		s=s2;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", s2);	
		} 
		
		/*bistro najjeftiniji*/
		else {
		s=s3;
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", s3);
		}
		
		/*popust restoran*/
		popust=2*(h1-(h1*0.1))+c1;
		if (s1==s) {
			return 0;
		}
		else if(popust<s) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", popust);
		
	}
	
	if ((Tarik=='H' && Bojan=='C' && Mirza=='C') || (Tarik=='C' && Bojan=='H' && Mirza=='C') || (Tarik=='C' && Bojan=='C' && Mirza=='H')) {
			
		/*sume*/
		s1=2*c1+h1;
		s2=2*c2+h2;
		s3=2*c3+h3;
		
		/*restoran najjeftiniji*/
		if (s1<s2 && s1<s3) {
		s=s1;
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", s1);
		}
		
		/*fast food najjeftiniji*/
		else if (s2<s3 && s2<s1){
		s=s2;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", s2);	
		} 
		
		/*bistro najjeftiniji*/
		else {
		s=s3;
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", s3);
		}
		
		/*popust restoran*/
		popust=2*(c1-(c1*0.1))+h1;
		if (s1==s) {
			return 0;
		}
		else if(popust<s) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", popust);
		
	}
	
	/*cevapi*/
	if (Tarik=='C' && Bojan=='C' && Mirza=='C') {
			
		/*sume*/
		s1=3*c1;
		s2=3*c2;
		s3=3*c3;
		
		/*restoran najjeftiniji*/
		if (s1<s2 && s1<s3) {
		s=s1;
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", s1);
		}
		
		/*fast food najjeftiniji*/
		else if (s2<s3 && s2<s1){
		s=s2;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", s2);	
		} 
		
		/*bistro najjeftiniji*/
		else {
		s=s3;
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", s3);
		}
		
		/*popust restoran*/
		popust=3*(c1-(c1*0.1));
		if (s1==s) {
			return 0;
		}
		else if(popust<s) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", popust);
		
	}
	
	/*pizza hambas cevapi*/
	
	if ((Tarik=='P' && Bojan=='H' && Mirza=='C') || (Tarik=='P' && Bojan=='C' && Mirza=='H') || (Tarik=='H' && Bojan=='P' && Mirza=='C') || (Tarik=='H' && Bojan=='C' && Mirza=='P') || (Tarik=='C' && Bojan=='P' && Mirza=='H') || (Tarik=='C' && Bojan=='H' && Mirza=='P')) {
		
		/*sume*/
		s1=p1+h1+c1;
		s2=p2+h2+c2;
		s3=p3+h3+c3;
		
		/*restoran najjeftiniji*/
		if (s1<s2 && s1<s3) {
		s=s1;
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", s1);
		}
		
		/*fast food najjeftiniji*/
		else if (s2<s3 && s2<s1){
		s=s2;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", s2);	
		} 
		
		/*bistro najjeftiniji*/
		else {
		s=s3;
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", s3);
		}
		
		/*popust restoran*/
		popust=p1-(p1*0.1)+h1+c1;
		if (s1==s) {
			return 0;
		}
		else if(popust<s) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", popust);
		
	}
	
	return 0;
}

