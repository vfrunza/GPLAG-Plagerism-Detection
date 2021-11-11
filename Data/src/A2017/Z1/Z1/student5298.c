#include <stdio.h>
#define p1 6.80
#define p2 8.00
#define p3 5.30
#define h1 3.30
#define h2 3.00
#define h3 5.00
#define c1 5.00
#define c2 3.90
#define c3 6.00

int main() {
	
	char t,b,m,novi_red;
	float s1,s2,s3,pomP,pomH,pomC;
	int b1,b2,b3;
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &t);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &b);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &m);
	scanf("%c", &novi_red);
	
	s1=0;
	s2=0;
	s3=0;
	b1=0;
	b2=0;
	b3=0;
	
	if(t=='P') {
		s1+=p1;
		s2+=p2;
		s3+=p3;
		b1++;
	}
	
	if(t=='H') {
		s1+=h1;
		s2+=h2;
		s3+=h3;
		b2++;
	}
	
	if(t=='C') {
		s1+=c1;
		s2+=c2;
		s3+=c3;
		b3++;
	}
	
	if(b=='P') {
		s1+=p1;
		s2+=p2;
		s3+=p3;
		b1++;
	}
	
	if(b=='H') {
		s1+=h1;
		s2+=h2;
		s3+=h3;
		b2++;
	}
	
	if(b=='C') {
		s1+=c1;
		s2+=c2;
		s3+=c3;
		b3++;
	}
	
	if(m=='P') {
		s1+=p1;
		s2+=p2;
		s3+=p3;
		b1++;
	}
	
	if(m=='H') {
		s1+=h1;
		s2+=h2;
		s3+=h3;
		b2++;
	}
	
	if(m=='C') {
		s1+=c1;
		s2+=c2;
		s3+=c3;
		b3++;
	}
	
	if(s1<s2 && s1<s3) {
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", s1);
	} else if(s2<s1 && s2<s3) {
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", s2);
		
		
		pomP=p1*b1;
		pomH=h1*b2;
		pomC=c1*b3;
		
		if(pomP>pomH && pomP>pomC) pomP=pomP*0.9;
		else if(pomH>pomP && pomH>pomC) pomH=pomH*0.9;
		else if(pomC>pomP && pomC<pomH) pomC=pomC*0.9;
		
		s1=pomP+pomH+pomC;
		
		if(s1<s2) {
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", s1);
		}
	} else if(s3<s1 && s3<s2) {
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",s3);
		
		pomP=p1*b1;
		pomH=h1*b2;
		pomC=c1*b3;
		
		if(pomP>pomH && pomP>pomC) pomP=pomP*0.9;
		else if(pomH>pomP && pomH>pomC) pomH=pomH*0.9;
		else if(pomC>pomP && pomC>pomH) pomC=pomC*0.9;
		
		s1=pomP+pomH+pomC;
		
		if(s1<s3) {
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", s1);
		}
	}
	return 0;
}
