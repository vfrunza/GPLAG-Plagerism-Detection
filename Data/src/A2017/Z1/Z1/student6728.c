#include <stdio.h>
#define epsilon 0.0001
int main() {
	char tarik,mirza,bojan,novi_red;
	double pizza_r, pizza_f, pizza_b, ham_r, ham_f, ham_b, cevapi_r, cevapi_f, cevapi_b, sum_r, sum_f, sum_b;
	int brojac_h = 0, brojac_p = 0, brojac_c = 0;
	pizza_r = 6.8;
	pizza_f = 8;
	pizza_b = 5.3;
	ham_r = 3.3;
	ham_f = 3;
	ham_b = 5;
	cevapi_r = 5;
	cevapi_f = 3.9;
	cevapi_b = 6;
	sum_b = 0;
	sum_f = 0;
	sum_r = 0;
	printf("Unesite jelo za Tarika: ");
	scanf("%c",&tarik);
	scanf("%c",&novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c",&bojan);
	scanf("%c",&novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c",&mirza);
	scanf("%c",&novi_red);
	if (tarik == 'H') {
		sum_r += ham_r;
		sum_f += ham_f;
		sum_b += ham_b;
		++brojac_h;
	}
	if (tarik == 'P') {
		sum_r += pizza_r;
		sum_f += pizza_f;
		sum_b += pizza_b;
		++brojac_p;
	}
	if (tarik == 'C') {
		sum_r += cevapi_r;
		sum_f += cevapi_f;
		sum_b += cevapi_b;
		++brojac_c;
	}
	if (bojan == 'H') {
		sum_r += ham_r;
		sum_f += ham_f;
		sum_b += ham_b;
		++brojac_h;
	}
	if (bojan == 'P') {
		sum_r += pizza_r;
		sum_f += pizza_f;
		sum_b += pizza_b;
		++brojac_p;
	}
	if (bojan == 'C') {
		sum_r += cevapi_r;
		sum_f += cevapi_f;
		sum_b += cevapi_b;
		++brojac_c;
	}
	if (mirza == 'P') {
		sum_r += pizza_r;
		sum_f += pizza_f;
		sum_b += pizza_b;
		++brojac_p;
	}
	if (mirza == 'H') {
		sum_r += ham_r;
		sum_f += ham_f;
		sum_b += ham_b;
		++brojac_h;
	}
	if (mirza == 'C') {
		sum_r += cevapi_r;
		sum_f += cevapi_f;
		sum_b += cevapi_b;
		++brojac_c;
	}
	if (sum_b<sum_f && sum_b<sum_r){ 
		printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", sum_b);
		if (brojac_c >= 2) {
			sum_r -= (cevapi_r * 0.1) * brojac_c;
		} else if (brojac_p >= 1) {
			sum_r -= (pizza_r * 0.1) * brojac_p;
		} else {
			sum_r -= (ham_r * 0.1) * brojac_h;
		} 
		
		if (sum_r < sum_b) 
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", sum_r);
	}
	else if (sum_f < sum_b && sum_f < sum_r) {
		printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", sum_f);
		if (brojac_c >= 2) {
			sum_r -= (cevapi_r * 0.1) * brojac_c;
		} else if (brojac_p >= 1) {
			sum_r -= (pizza_r * 0.1) * brojac_p;
		} else {
			sum_r -= (ham_r * 0.1) * brojac_h;
			} 
		
		if (sum_r < sum_f) 
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", sum_r);
	}
	else if (sum_r < sum_f && sum_r < sum_b) 
	printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", sum_r);
	
	
/*	printf("suma rest %f \n", sum_r);
	printf("suma fast %f\n", sum_f);
	printf("suma bistro %f\n", sum_b); */
	
	return 0;
}
