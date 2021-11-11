#include <stdio.h>
#define Pizza1 6.80
#define Pizza2 8.00
#define Pizza3 5.30
#define Hamburger1 3.30
#define Hamburger2 3.00
#define Hamburger3 5.00
#define Cevapi1 5.00
#define Cevapi2 3.90
#define Cevapi3 6.00
#define z 0.1

int main()
{

	float a1,a2,a3,b1,b2,b3,c1,c2,c3,d1,d2,d3,e1,e2,e3,f1,f2,f3,g1,g2,g3,h1,h2,h3,i1,i2,i3,j1,j2,j3,k;
	char tarik, mirza, bojan,novi_red;

	printf("Unesite jelo za Tarika: ");
	scanf("%c", &tarik);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &bojan);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &mirza);
	scanf("%c", &novi_red);

	if(tarik=='P' && bojan=='P' && mirza=='P') {
		a1=Pizza1+Pizza1+Pizza1;
		a2=Pizza2+Pizza2+Pizza2;
		a3=Pizza3+Pizza3+Pizza3;
		if(a1<a2 && a1<a3) {
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", a1);
		}
		if(a2<a1 && a2<a3) {
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", a2);
			k=-(a1*z)+a1;
			if(k<a2) {
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",k);
			}
		}
		if(a3<a1 && a3<a2) {
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", a3);
			k=-(a1*z)+a1;
			if(k<a3) {
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",k);
			}
		}

	}

	if((tarik=='H' && bojan=='P' && mirza=='P') || (tarik=='P' && bojan=='H' && mirza=='P') || (tarik=='P' && bojan=='P' && mirza=='H')) {
		b1=Hamburger1+Pizza1+Pizza1;
		b2=Hamburger2+Pizza2+Pizza2;
		b3=Hamburger3+Pizza3+Pizza3;
		if(b1<b2 && b1<b3) {
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", b1);
		}
		if(b2<b1 && b2<b3) {
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", b2);
			if((Hamburger1*z)>(z*2*Pizza1)) {
				k=(2*Pizza1)+Hamburger1-(Hamburger1*z);
				if(k<b2) {
					printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",k);
				}
			}
			if((z*2*Pizza1)>(Hamburger1*z)) {
				k=(2*Pizza1)+Hamburger1-(2*Pizza1*z);
				if(k<b2) {
					printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",k);
				}
			}
		}
		if(b3<b1 && b3<b2) {
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", b3);
			if((z*2*Pizza1)>(Hamburger1*z)) {
				k=(2*Pizza1)+Hamburger1-(2*Pizza1*z);
				if(k<b3) {
					printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",k);
				}
			}
			if((Hamburger1*z)>(z*2*Pizza1)) {
				k=(2*Pizza1)+Hamburger1-(Hamburger1*z);
				if(k<b3) {
					printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",k);
				}
			}
		}
	}

	if((tarik=='H' && bojan=='H' && mirza=='P') || (tarik=='P' && bojan=='H' && mirza=='H') || (tarik=='H' && bojan=='P' && mirza=='H')) {
		c1=Hamburger1+Hamburger1+Pizza1;
		c2=Hamburger2+Hamburger2+Pizza2;
		c3=Hamburger3+Hamburger3+Pizza3;
		if(c1<c2 && c1<c3) {
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", c1);
		}
		if(c2<c1 && c2<c3) {
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", c2);
			if((z*2*Hamburger1)>(z*Pizza1)) {
				k=Pizza1+(2*Hamburger1)-(2*Hamburger1*z);
				if(k<c2) {
					printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",k);
				}
			}
			if((z*Pizza1)>(2*z*Hamburger1)) {
				k=Pizza1+(2*Hamburger1)-(Pizza1*z);
				if(k<c2) {
					printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",k);
				}
			}

		}
		if(c3<c1 && c3<c2) {
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", c3);
			if((z*2*Hamburger1)>(z*Pizza1)) {
				k=Pizza1+(2*Hamburger1)-(2*Hamburger1*z);
				if(k<c3) {
					printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",k);
				}
			}
			if((z*Pizza1)>(2*z*Hamburger1)) {
				k=Pizza1+(2*Hamburger1)-(Pizza1*z);
				if(k<c3) {
					printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",k);
				}
			}
		}
	}

	if((tarik=='H' && bojan=='H' && mirza=='H') || (tarik=='H' && bojan=='H' && mirza=='H') || (tarik=='H' && bojan=='H' && mirza=='H')) {
		d1=Hamburger1+Hamburger1+Hamburger1;
		d2=Hamburger2+Hamburger2+Hamburger2;
		d3=Hamburger3+Hamburger3+Hamburger3;
		if(d1<d2 && d1<d3) {
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", d1);
		}
		if(d2<d1 && d2<d3) {
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", d2);
			k=-(d1*z)+d1;
			if(k<d2) {
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",k);
			}
		}
		if(d3<d1 && d3<d2) {
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", d3);
			k=-(d1*z)+d1;
			if(k<d3) {
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",k);
			}
		}
	}


	if((tarik=='C' && bojan=='P' && mirza=='P') || (tarik=='P' && bojan=='C' && mirza=='P') || (tarik=='P' && bojan=='P' && mirza=='C')) {
		e1=Cevapi1+Pizza1+Pizza1;
		e2=Cevapi2+Pizza2+Pizza2;
		e3=Cevapi3+Pizza3+Pizza3;
		if(e1<e2 && e1<e3) {
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", e1);
		}
		if(e2<e1 && e2<e3) {
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", e2);
			if((z*Cevapi1)>(2*z*Pizza1)) {
				k=(2*Pizza1)+Cevapi1-(Cevapi1*z);
				if(k<e2) {
					printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",k);
				}
			}
			if((z*2*Pizza1)>(z*Cevapi1)) {
				k=Cevapi1+(2*Pizza1)-(2*Pizza1*z);
				if(k<e2) {
					printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",k);
				}
			}
		}
		if(e3<e1 && e3<e2) {
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", e3);
			if((z*Cevapi1)>(2*z*Pizza1)) {
				k=(2*Pizza1)+Cevapi1-(Cevapi1*z);
				if(k<e3) {
					printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",k);
				}
			}
			if((z*2*Pizza1)>(z*Cevapi1)) {
				k=Cevapi1+(2*Pizza1)-(2*Pizza1*z);
				if(k<e3) {
					printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",k);
				}
			}
		}
	}

	if((tarik=='C' && bojan=='C' && mirza=='P') || (tarik=='P' && bojan=='C' && mirza=='C') || (tarik=='C' && bojan=='P' && mirza=='C')) {
		f1=Cevapi1+Cevapi1+Pizza1;
		f2=Cevapi2+Cevapi2+Pizza2;
		f3=Cevapi3+Cevapi3+Pizza3;

		if(f1<f2 && f1<f3) {
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", f1);
		}
		if(f2<f1 && f2<f3) {
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", f2);
			if((2*z*Cevapi1)>(z*Pizza1)) {
				k=(2*Cevapi1)+Pizza1-(2*Cevapi1*z);
				if(k<f2) {
					printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",k);
				}
			}
			if((z*Pizza1)>(z*2*Cevapi1)) {
				k=Pizza1+(2*Cevapi1)-(Pizza1*z);
				if(k<f2) {
					printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",k);
				}
			}
		}
		if(f3<f1 && f3<f2) {
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", f3);
			if((2*z*Cevapi1)>(z*Pizza1)) {
				k=(2*Cevapi1)+Pizza1-(2*Cevapi1*z);
				if(k<f3) {
					printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",k);
				}
			}
			if((z*Pizza1)>(z*2*Cevapi1)) {
				k=Pizza1+(2*Cevapi1)-(Pizza1*z);
				if(k<f3) {
					printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",k);
				}
			}
		}
	}

	if(tarik=='C' && bojan=='C' && mirza=='C') {
		g1=Cevapi1+Cevapi1+Cevapi1;
		g2=Cevapi2+Cevapi2+Cevapi2;
		g3=Cevapi3+Cevapi3+Cevapi3;
		if(g1<g2 && g1<g3) {
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", g1);
		}
		if(g2<g1 && g2<g3) {
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", g2);
			k=-(g1*z)+g1;
			if(k<g2) {
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",k);
			}
		}
		if(g3<g1 && g3<g2) {
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", g3);
			k=-(g1*z)+g1;
			if(k<g3) {
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",k);
			}
		}
	}


	if((tarik=='C' && bojan=='C' && mirza=='H') || (tarik=='H' && bojan=='C' && mirza=='C') || (tarik=='C' && bojan=='H' && mirza=='C')) {
		h1=Cevapi1+Cevapi1+Hamburger1;
		h2=Cevapi2+Cevapi2+Hamburger2;
		h3=Cevapi3+Cevapi3+Hamburger3;

		if(h1<h2 && h1<h3) {
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", h1);
		}
		if(h2<h1 && h2<h3) {
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", h2);
			if((2*z*Cevapi1)>(z*Hamburger1)) {
				k=(2*Cevapi1)+Hamburger1-(2*Cevapi1*z);
				if(k<h2) {
					printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",k);
				}
			}
			if((z*Hamburger1)>(z*2*Cevapi1)) {
				k=Pizza1+(2*Cevapi1)-(Hamburger1*z);
				if(k<h2) {
					printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",k);
				}
			}
		}
		if(h3<h1 && h3<h2) {
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", h3);
			if((2*z*Cevapi1)>(z*Hamburger1)) {
				k=(2*Cevapi1)+Hamburger1-(2*Cevapi1*z);
				if(k<h3) {
					printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",k);
				}
			}
			if((z*Hamburger1)>(z*2*Cevapi1)) {
				k=Hamburger1+(2*Cevapi1)-(Hamburger1*z);
				if(k<h3) {
					printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",k);
				}
			}
		}
	}

	if((tarik=='H' && bojan=='H' && mirza=='C') || (tarik=='C' && bojan=='H' && mirza=='H') || (tarik=='H' && bojan=='C' && mirza=='H')) {
		i1=Hamburger1+Hamburger1+Cevapi1;
		i2=Hamburger2+Hamburger2+Cevapi2;
		i3=Hamburger3+Hamburger3+Cevapi3;
		if(i1<i2 && i1<i3) {
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", i1);
		}
		if(i2<i1 && i2<i3) {
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", i2);
			if((z*2*Hamburger1)>(z*Cevapi1)) {
				k=Cevapi1+(2*Hamburger1)-(2*Hamburger1*z);
				if(k<i2) {
					printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",k);
				}
			}
			if((z*Cevapi1)>(2*z*Hamburger1)) {
				k=Pizza1+(2*Hamburger1)-(Cevapi1*z);
				if(k<i2) {
					printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",k);
				}
			}
		}
		if(i3<i1 && i3<i2) {
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", i3);
			if((z*2*Hamburger1)>(z*Cevapi1)) {
				k=Cevapi1+(2*Hamburger1)-(2*Hamburger1*z);
				if(k<i3) {
					printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",k);
				}
			}
			if((z*Cevapi1)>(2*z*Hamburger1)) {
				k=Pizza1+(2*Hamburger1)-(Cevapi1*z);
				if(k<i3) {
					printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",k);
				}
			}
		}
	}

	if((tarik=='H' && bojan=='P' && mirza=='C') || (tarik=='C' && bojan=='P' && mirza=='H') || (tarik=='P' && bojan=='C' && mirza=='H') || (tarik=='H' && bojan=='C' && mirza=='P') || (tarik=='P' && bojan=='H' && mirza=='C') || (tarik=='C' && bojan=='H' && mirza=='P')) {
		j1=Pizza1+Hamburger1+Cevapi1;
		j2=Pizza2+Hamburger2+Cevapi2;
		j3=Pizza3+Hamburger3+Cevapi3;
		if(j1<j2 && j1<j3) {
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", j1);
		}
		if(j2<j1 && j2<j3) {
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", j2);
			if((z*Pizza1>z*Cevapi1) && (z*Pizza1>z*Hamburger1)) {
				k=Pizza1+Hamburger1+Cevapi1-(z*Pizza1);
				if(k<j2) {
					printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",k);
				}
			}
			if((z*Cevapi1>z*Pizza1) && (z*Cevapi1>z*Hamburger1)) {
				k=Pizza1+Hamburger1+Cevapi1-(z*Cevapi1);
				if(k<j2) {
					printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",k);
				}
			}
			if((z*Hamburger1>z*Cevapi1) && (z*Hamburger1>z*Pizza1)) {
				k=Pizza1+Hamburger1+Cevapi1-(z*Hamburger1);
				if(k<j2) {
					printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",k);
				}
			}

		}
		if(j3<j1 && j3<j2) {
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", j3);
			if((z*Pizza1>z*Cevapi1) && (z*Pizza1>z*Hamburger1)) {
				k=Pizza1+Hamburger1+Cevapi1-(z*Pizza1);
				if(k<j3) {
					printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",k);
				}
			}
			if((z*Cevapi1>z*Pizza1) && (z*Cevapi1>z*Hamburger1)) {
				k=Pizza1+Hamburger1+Cevapi1-(z*Cevapi1);
				if(k<j3) {
					printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",k);
				}
			}
			if((z*Hamburger1>z*Cevapi1) && (z*Hamburger1>z*Pizza1)) {
				k=Pizza1+Hamburger1+Cevapi1-(z*Hamburger1);
				if(k<j3) {
					printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",k);
				}
			}
		}
	}








	return 0;  
	
}