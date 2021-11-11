#include <stdio.h>
#define KP 6.8
#define KH 3.3
#define KC 5.0
#define TP 8.0
#define TH 3.0
#define TC 3.9
#define LP 5.3
#define LH 5.0
#define LC 6.0
#define PK 0.1

int main() {
//	printf("Zadaća 1, Zadatak 1");
	char t, b, m, nr;
	printf ("\nUnesite jelo za Tarika: ");
	scanf ("%c", &t);
	scanf ("%c", &nr);
	printf ("Unesite jelo za Bojana: ");
	scanf ("%c", &b);
	scanf ("%c", &nr);
	printf ("Unesite jelo za Mirzu: ");
	scanf ("%c", &m);
	scanf ("%c", &nr);
	
	float t1, t2, t3;
	float b1, b2, b3;
	float m1, m2, m3;
	
	if (t=='P') {
		t1=KP;
		t2=TP;
		t3=LP;
	}
	else if (t=='H') {
		t1=KH;
		t2=TH;
		t3=LH;
	}
	else if (t=='C') {
		t1=KC;
		t2=TC;
		t3=LC;
	}
	
	if (b=='P') {
		b1=KP;
		b2=TP;
		b3=LP;
	}
	else if (b=='H') {
		b1=KH;
		b2=TH;
		b3=LH;
	}
	else if (b=='C') {
		b1=KC;
		b2=TC;
		b3=LC;
	}
	
	if (m=='P') {
		m1=KP;
		m2=TP;
		m3=LP;
	}
	else if (m=='H') {
		m1=KH;
		m2=TH;
		m3=LH;
	}
	else if (m=='C') {
		m1=KC;
		m2=TC;
		m3=LC;
	}
	
	float c1, c2, c3;
	c1=0; c2=0; c3=0;
	c1=t1+b1+m1;
	c2=t2+b2+m2;
	c3=t3+b3+m3;
	
	float p1, p2, p3;
	p1=t1-t1*PK+b1+m1;
	p2=t1+b1-b1*PK+m1;
	p3=t1+b1+m1-m1*PK;
	if (t1==b1 && t1==m1) p1=t1*3-t1*PK*3;
	else if (t1==b1 && t1!=m1) p1=t1*2-t1*PK*2+m1;
	else if (t1==m1 && t1!=b1) p1=t1*2-t1*PK*2+b1;
	else if (b1==m1 && t1!=b1) p2=t1+b1*2-b1*PK*2;

//	printf ("%f %f %f", p1, p2, p3);

	if (c1<c2 && c1<c3) printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", c1 );

	else if (c2<c3 && c2<c1) {
		printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", c2 );
		if (p1<p2 && p1<p3 && p1<c2) printf ("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", p1);
		else if (p2<p3 && p2<p1 && p2<c2) printf ("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", p2);
		else if (p3<p1 && p3<p1 && p3<c2) printf ("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", p3);
	}
	else if (c3<c1 && c3<c2) {
		printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", c3 );
		if (p1<p2 && p1<p3 && p1<c3) printf ("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", p1);
		else if (p2<p3 && p2<p1 && p2<c3) printf ("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", p2);
		else if (p3<p1 && p3<p1 && p3<c3) printf ("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", p3);
	}
	return 0;
}
