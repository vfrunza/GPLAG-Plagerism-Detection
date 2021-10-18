#include <stdio.h>

int main()
{
	char tarik, bojan, mirza, novi_red;
	double pizza1 = 6.80, hamburger1 = 3.30, cevapi1 = 5.00;
	double pizza2 = 8.00, hamburger2 = 3.00, cevapi2 = 3.90;
	double pizza3 = 5.30, hamburger3 = 5.00, cevapi3 = 6.00;
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &tarik);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &bojan);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &mirza);
	scanf("%c", &novi_red);
	double r1 = 0, r2 = 0, r3 = 0;
	if(tarik == 'P') {
		r1 += pizza1;
		r2 += pizza2;
		r3 += pizza3;
	}
	if(tarik == 'H') {
		r1 += hamburger1;
		r2 += hamburger2;
		r3 += hamburger3;
	}
	if(tarik == 'C') {
		r1 += cevapi1;
		r2 += cevapi2;
		r3 += cevapi3;
	}
	if(bojan == 'P') {
		r1 += pizza1;
		r2 += pizza2;
		r3 += pizza3;
	}
	if(bojan == 'H') {
		r1 += hamburger1;
		r2 += hamburger2;
		r3 += hamburger3;
	}
	if(bojan == 'C') {
		r1 += cevapi1;
		r2 += cevapi2;
		r3 += cevapi3;
	}
	if(mirza == 'P') {
		r1 += pizza1;
		r2 += pizza2;
		r3 += pizza3;
	}
	if(mirza == 'H') {
		r1 += hamburger1;
		r2 += hamburger2;
		r3 += hamburger3;
	}
	if(mirza == 'C') {
		r1 += cevapi1;
		r2 += cevapi2;
		r3 += cevapi3;
	}
	double minR = r1;
	if(r2 < minR) minR = r2;
	if(r3 < minR) minR = r3;
	if(minR == r1) printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", r1);
	if(minR == r2) printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", r2);
	if(minR == r3) printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", r3);
	if(minR != r1) {
		double r1pizza = 0, r1ham = 0, r1cev = 0;
		double pizza = pizza1 - pizza1/10;
		double hamburger = hamburger1 - hamburger1/10;
		double cevapi = cevapi1 - cevapi1/10;
		double minRP = 0;
		if(tarik == 'P') {
			r1pizza += pizza;
			r1ham += pizza1;
			r1cev += pizza1;
		}
		if(tarik == 'H') {
			r1pizza += hamburger1;
			r1ham += hamburger;
			r1cev += hamburger1;
		}
		if(tarik == 'C') {
			r1pizza += cevapi1;
			r1ham += cevapi1;
			r1cev += cevapi;
		}
		if(bojan == 'P') {
			r1pizza += pizza;
			r1ham += pizza1;
			r1cev += pizza1;
		}
		if(bojan == 'H') {
			r1pizza += hamburger1;
			r1ham += hamburger;
			r1cev += hamburger1;
		}
		if(bojan == 'C') {
			r1pizza += cevapi1;
			r1ham += cevapi1;
			r1cev += cevapi;
		}
		if(mirza == 'P') {
			r1pizza += pizza;
			r1ham += pizza1;
			r1cev += pizza1;
		}
		if(mirza == 'H') {
			r1pizza += hamburger1;
			r1ham += hamburger;
			r1cev += hamburger1;
		}
		if(mirza == 'C') {
			r1pizza += cevapi1;
			r1ham += cevapi1;
			r1cev += cevapi;
		}
		minRP = r1pizza;
		if(r1ham < minRP) minRP = r1ham;
		if(r1cev < minRP) minRP = r1cev;
		if(minRP < minR) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", minRP);
	}
	return 0;
}
