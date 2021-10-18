#include <stdio.h>
#define p_r 6.80
#define p_f 8.00
#define p_b 5.30
#define h_r 3.30
#define h_f 3.00
#define h_b 5.00
#define c_r 5.00
#define c_f 3.90
#define c_b 6.00

int main() {
	char tarik, bojan, mirza, n_red;
	int brojac_p = 0, brojac_h = 0, brojac_c=0;
	float r1, r2,r3, r_popust=0;
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &tarik);
	scanf("%c", &n_red);
	switch (tarik) {
		case 'P':
			brojac_p++;
		break;
		case 'H':
			brojac_h++;
		break;
		case 'C':
			brojac_c++;
		break;
	}
	
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &bojan);
	scanf("%c", &n_red);
	switch (bojan) {
		case 'P':
			brojac_p++;
		break;
		case 'H':
			brojac_h++;
		break;
		case 'C':
			brojac_c++;
		break;
	}
	
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &mirza);
	scanf("%c", &n_red);
	switch (mirza) {
		case 'P':
			brojac_p++;
		break;
		case 'H':
			brojac_h++;
		break;
		case 'C':
			brojac_c++;
		break;
	}
	
	r1 = brojac_h*h_r + brojac_p*p_r + brojac_c*c_r;
	r2 = brojac_c*c_f + brojac_p*p_f + brojac_h*h_f;
	r3 = brojac_h*h_b + brojac_p*p_b + brojac_c*c_b;
	

	if (brojac_h == 2 ) {
		r_popust = (brojac_h*h_r + brojac_p*p_r + brojac_c*c_r) - (2*(h_r*10)/100);
	}
	else if (brojac_p == 2) {
		r_popust = (brojac_h*h_r + brojac_p*p_r + brojac_c*c_r) - (2*(p_r*10)/100);
	}
	else if (brojac_c == 2) {
		r_popust = (brojac_h*h_r + brojac_p*p_r + brojac_c*c_r) - (2*(c_r*10)/100);
	}
	else if(brojac_h == 3) {
		r_popust = (brojac_h*h_r + brojac_p*p_r + brojac_c*c_r) - (3*(h_r*10)/100);
	}
	else if(brojac_p == 3) {
		r_popust = (brojac_h*h_r + brojac_p*p_r + brojac_c*c_r) - (3*(p_r*10)/100);
	}
	else if(brojac_c == 3) {
			r_popust = (brojac_h*h_r + brojac_p*p_r + brojac_c*c_r) - (3*(c_r*10)/100);
	}
	else {
			r_popust = (brojac_h*h_r + brojac_p*p_r + brojac_c*c_r) - (p_r*10)/100;
	}
	
	if(r1 < r2 && r1 < r3) {
		
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", r1);
		
	}
	else if ( r2 < r1 && r2 < r3) {
		
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", r2);
		
			if (r_popust < r2) {
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", r_popust);
		}
		
	}
	else if (r3 < r1 && r3 < r2) {
	
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", r3);
		
			if (r_popust < r3) {
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", r_popust);
		}
		
		
	}
	
	
	
	

	
	return 0;
}
