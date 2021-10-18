#include <stdio.h>
#define kkp 6.80
#define kkh 3.30
#define kkc 5.00
#define ffp 8.00
#define ffh 3.00
#define ffc 3.90
#define bp 5.30
#define bh 5.00
#define bc 6.00

int main() {
	char H, P, C, t, b, m, novi_red, navodnici,crta;
	navodnici='"';
	crta='-';
    double	N1=0, N2=0, N3=0, N4=0;
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &t);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &b); 
	scanf("%c", &novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &m);
	scanf("%c", &novi_red);
	
	if(t=='P' && m=='P' && b=='P') {
		N1=3.*kkp;
		N2=3.*ffp;
		N3=3.*bp;
		N4=N1*0.9;
		
		if ((N1<N2) && (N1<N3)) {
			printf("Najjeftiniji je \"Restoran %cKod konja i konjusara%c (%.2f KM).", navodnici, navodnici, N1);
		} else if ((N2<N1) && (N2<N3)) {
			printf("Najjeftiniji je Fast-food %cTrovac%c (%.2f KM).", navodnici, navodnici, N2);
		} else if ((N3<N2) && (N3<N1)) {
			printf("Najjeftiniji je Bistro %cLorelei%c (%.2f KM).", navodnici, navodnici, N3);
		} 
		if(N1>=N3 && N1>=N2) {
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", N4);
	}	return 1;
	}
	
	if(t=='C' && m=='C' && b=='C') {
     	N1=3.*kkc;
		N2=3.*ffc;
		N3=3.*bc;
		N4=N1*0.9;
		
			
		if ((N1<N2) && (N1<N3)) {
			printf("Najjeftiniji je Restoran %cKod konja i konjusara%c (%.2f KM).", navodnici, navodnici, N1);
		} else if ((N2<N1) && (N2<N3)) {
			printf("Najjeftiniji je Fast-food %cTrovac%c (%.2f KM).", navodnici, navodnici, N2);
		} else if ((N3<N2) && (N3<N1)) {
			printf("Najjeftiniji je Bistro %cLorelei%c (%.2f KM).", navodnici, navodnici, N3);
		} 
		
		if (N1>=N2 && N1>=N3) {
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", N4);
		} return 1;
	}
	
	if(t=='H' && m=='H' && b=='H') {
     	N1=3.*kkh;
		N2=3.*ffh;
		N3=3.*bh;
		N4=N1*0.9;
		
			
		if ((N1<N2) && (N1<N3)) {
			printf("Najjeftiniji je Restoran %cKod konja i konjusara%c (%.2f KM).", navodnici, navodnici, N1);
		} else if ((N2<N1) && (N2<N3)) {
			printf("Najjeftiniji je Fast%cfood %cTrovac%c (%.2f KM).", crta, navodnici, navodnici, N2);
		} else if ((N3<N2) && (N3<N1)) {
			printf("Najjeftiniji je Bistro %cLorelei%c (%.2f KM).", navodnici, navodnici, N3);
		} 
		
		if (N4<N2 && N4<N3) {
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", N4);
		} return 1;
	} 
	
	if((t=='H' && m=='H' && b=='P') || (t=='H' && m=='P' && b=='H') || (t=='P' && m=='H' && b=='H')) {
		N1=2.*kkh + kkp;
		N2=2.*ffh + ffp;
		N3=2.*bh + bp;
		N4=kkp*0.9 + 2.*kkh;
		
			if ((N1<N2) && (N1<N3)) {
			printf("Najjeftiniji je Restoran %cKod konja i konjusara%c (%.2f KM).", navodnici, navodnici, N1);
		} else if ((N2<N1) && (N2<N3)) {
			printf("Najjeftiniji je Fast-food %cTrovac%c (%.2f KM).", navodnici, navodnici, N2);
		} else if ((N3<N2) && (N3<N1)) {
			printf("Najjeftiniji je Bistro %cLorelei%c (%.2f KM).", navodnici, navodnici, N3);
		} 

		if(N1>=N2 && N1>=N3){	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", N4);
		}
		return 1;
	}
	if((t=='H' && m=='H' && b=='C') || (t=='C' && m=='H' && b=='H') || (t=='H' && m=='C' && b=='H')) {
		N1=2.*kkh + kkc;
		N2=2.*ffh + ffc;
		N3=2.*bh + bc;
		N4=2.*kkh*0.9 + kkc;
		
			if ((N1<N2) && (N1<N3)) {
			printf("Najjeftiniji je Restoran %cKod konja i konjusara%c (%.2f KM).", navodnici, navodnici, N1);
		} else if ((N2<N1) && (N2<N3)) {
			printf("Najjeftiniji je Fast-food %cTrovac%c (%.2f KM).", navodnici, navodnici, N2);
		} else if ((N3<N2) && (N3<N1)) {
			printf("Najjeftiniji je Bistro %cLorelei%c (%.2f KM).", navodnici, navodnici, N3);
		} 
		if(N1>=N2 && N1>=N3){	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", N4);
		}
		return 1;
	}
	if((t=='C' && m=='C' && b=='P') || (t=='C' && m=='P' && b=='C') || (t=='P' && m=='C' && b=='C')) {
		N1=2.*kkc + kkp;
		N2=2.*ffc + ffp;
		N3=2.*bc + bp;
		N4=2.*kkc*0.9 + kkp;
		
			if ((N1<N2) && (N1<N3)) {
			printf("Najjeftiniji je Restoran %cKod konja i konjusara%c (%.2f KM).", navodnici, navodnici, N1);
		} else if ((N2<N1) && (N2<N3)) {
			printf("Najjeftiniji je Fast-food %cTrovac%c (%.2f KM).", navodnici, navodnici, N2);
		} else if ((N3<N2) && (N3<N1)) {
			printf("Najjeftiniji je Bistro %cLorelei%c (%.2f KM).", navodnici, navodnici, N3);
		}
		if(N1>=N2 && N1>=N3){	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", N4);
		}
		return 1;
	}
	if((t=='C' && m=='C' && b=='H')  || (t=='C' && m=='H' && b=='C') || (t=='H' && m=='C' && b=='C')) {
		N1=2.*kkc + kkh;
		N2=2.*ffc + ffh;
		N3=2.*bc + bh;
		N4=2.*kkc*0.9 + kkh;
		
			if ((N1<N2) && (N1<N3)) {
			printf("Najjeftiniji je Restoran %cKod konja i konjusara%c (%.2f KM).", navodnici, navodnici, N1);
		} else if ((N2<N1) && (N2<N3)) {
			printf("Najjeftiniji je Fast-food %cTrovac%c (%.2f KM).", navodnici, navodnici, N2);
		} else if ((N3<N2) && (N3<N1)) {
			printf("Najjeftiniji je Bistro %cLorelei%c (%.2f KM).", navodnici, navodnici, N3);
		} 
		if(N1>=N2 && N1>=N3){	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", N4);
		}
		return 1;
	}
	
	if ((t=='P' && m=='P' && b=='H') || (t=='P' && m=='H' && b=='P') || (t=='H' && m=='P' && b=='P')) {
		N1=2.*kkp+kkh;
		N2=2.*ffp + ffh;
		N3=2.*bp + bh;
		N4=2.*0.9*kkp + kkh;
		
			if ((N1<N2) && (N1<N3)) {
			printf("Najjeftiniji je Restoran %cKod konja i konjusara%c (%.2f KM).", navodnici, navodnici, N1);
		} else if ((N2<N1) && (N2<N3)) {
			printf("Najjeftiniji je Fast-food %cTrovac%c (%.2f KM).", navodnici, navodnici, N2);
		} else if ((N3<N2) && (N3<N1)) {
			printf("Najjeftiniji je Bistro %cLorelei%c (%.2f KM).", navodnici, navodnici, N3);
		}
		if(N4<N2 && N4<N3){	printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", N4);
		}
		return 1;
	}
	
	if  ((t=='P' && m=='P' && b=='C') || (t=='C' && m=='P' && b=='P') || (t=='P' && m=='C' && b=='P')) {
		N1=2.*kkp + kkc;
		N2=2.*ffp + ffc;
		N3=2.*bp + bc;
		N4=2.*kkp + kkc;
		
			if ((N1<N2) && (N1<N3)) {
			printf("Najjeftiniji je Restoran %cKod konja i konjusara%c (%.2f KM).", navodnici, navodnici, N1);
		} else if ((N2<N1) && (N2<N3)) {
			printf("Najjeftiniji je Fast-food %cTrovac%c (%.2f KM).", navodnici, navodnici, N2);
		} else if ((N3<N2) && (N3<N1)) {
			printf("Najjeftiniji je Bistro %cLorelei%c (%.2f KM).", navodnici, navodnici, N3);
		}
		if(N1>=N2 && N1>=N3){	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", N4);
		}
		return 1;
	}
	if((t=='P' && m=='H' && b=='C') || (t=='C' && m=='H' && b=='P') || (t=='C' && m=='P' && b=='H') || (t=='P' && m=='C' && b=='H') || (t=='H' && m=='P' && b=='C') || (t=='H' && m=='C' && b=='P')) {
		N1=kkp+kkh+kkc;
		N2=ffp+ffh+ffc;
		N3=bh+bc+bp;
		N4=kkp*0.9+kkh+kkc;
		
		         	if ((N1<N2) && (N1<N3)) {
			printf("Najjeftiniji je Restoran %cKod konja i konjusara%c (%.2f KM).", navodnici, navodnici, N1);
		} else if ((N2<N1) && (N2<N3)) {
			printf("Najjeftiniji je Fast-food %cTrovac%c (%.2f KM).", navodnici, navodnici, N2);
		} else if ((N3<N2) && (N3<N1)) {
			printf("Najjeftiniji je Bistro %cLorelei%c (%.2f KM).", navodnici, navodnici, N3);
		}
		if(N4<N2 && N4<N3){	printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", N4);
		}
		return 1;
	}               
		return 0;
}
