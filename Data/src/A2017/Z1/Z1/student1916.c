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

int main() {
	char t, b, m, nr;
	/* Unijeti jela */
	do{
		printf("Unesite jelo za Tarika: ");
		scanf("%c", &t);
		scanf("%c", &nr);
	} while (t!='P' && t!='H' && t!='C');
	do{
		printf("Unesite jelo za Bojana: ");
		scanf("%c", &b);
		scanf("%c", &nr);
	} while (b!='H' && b!='P' && b!='C');
	do{
		printf("Unesite jelo za Mirzu: ");
		scanf("%c", &m);
		scanf("%c", &nr);
	} while (m!='P' && m!='H' && m!='C');
	
	/* Racunanje zasebnih racuna za sva 3 mjesta */
	float s1=0.0, s2=0.0, s3=0.0; /* s1-racun u restoranu, s2- racun u fast-food-u i s3-racun u bistro */
	if(b=='P'){
		s1+=KP;
		s2+=TP;
		s3+=LP;
	}
	if(b=='H'){
		s1+=KH;
		s2+=TH;
		s3+=LH;
	}
	if(b=='C'){
		s1+=KC;
		s2+=TC;
		s3+=LC;
	}
	if(t=='P'){
		s1+=KP;
		s2+=TP;
		s3+=LP;
	}
	if(t=='H'){
		s1+=KH;
		s2+=TH;
		s3+=LH;
	}
	if(t=='C'){
		s1+=KC;
		s2+=TC;
		s3+=LC;
	}
	if(m=='P'){
		s1+=KP;
		s2+=TP;
		s3+=LP;
	}
	if(m=='H'){
		s1+=KH;
		s2+=TH;
		s3+=LH;
	}
	if(m=='C'){
		s1+=KC;
		s2+=TC;
		s3+=LC;
	}
	/* Ispis najjeftinijeg racuna */
	if(s1<=s2 && s1<=s3) printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", s1);
	else if(s2<=s1 && s2<=s3) printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", s2);
	else printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", s3);
	/* Ako s3 nije najjeftinije onda oduzima 10% */
	float s4=0.0;
	if(s1>s2 || s1>s3){
		/* Ako su svi pizu */
		if((t=='P' && b=='P' && m=='P')||(t=='H' && b=='H' && m=='H')||(t=='C' && b=='C' && m=='C')) s4=s1-0.1*s1;
		if((t=='P' && b=='P' && m!='P')||(t=='P' && b!='P' && m=='P')||(t!='P' && b=='P' && m=='P')) s4=s1-0.1*2*KP;
		if((t=='P' && b!='P' && m!='P')||(t!='P' && b!='P' && m=='P')||(t!='P' && b=='P' && m!='P')) s4=s1-0.1*KP;
		if((t=='C' && b=='C' && m=='H')||(t=='C' && b=='H' && m=='C')||(t=='H' && b=='C' && m=='C')) s4=s1-0.1*2*KH;
		if((t=='C' && b=='H' && m=='H')||(t=='H' && b=='H' && m=='C')||(t=='H' && b=='C' && m=='H')) s4=s1-0.1*KH;
		/* Ako je racun sa popustom manji od ostalih onda ispisuje taj racun */
		if(s4<s2 && s4<s3) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", s4);
	}
	return 0;
}
