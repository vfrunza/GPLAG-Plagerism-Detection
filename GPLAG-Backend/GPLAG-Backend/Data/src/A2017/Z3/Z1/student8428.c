#include <stdio.h>

/* To moramo raditi bez ponavljanja, dakle dupli clanovi ce nam stvarati problem jer cemo ih dva puta brojati */
/* Potrebno je napraviti nove nizove u kojima nema duplih, kako ne bismo mijenjali one koje korisnik unosi */

void izbaci_duple (int *niz, int *vel) { /* Mijenja redoslijed clanova u nizu bez ocuvanja poretka, modifikuje se izvoni niz */ 
	int *p, *q;
	p = niz;
	
	/* Vanjska while petlja uzima jednog clana, a unutrasnja se krece od tog clana do kraja niza */
	/* Ova funkcija ce promijeniti i niz i njegovu velicinu */
	
	while (p < niz + *vel) {
		q = p+1;
		while (q < niz + *vel) {
			if (*p == *q) {
				/* Imamo dupli clan, pa cemo ga izbaciti */
				*q = *(niz + *vel - 1); /* ovo je zadnji clan */
				q--;
				(*vel)--;
			}
			q++;
		}
		p++;
	}
	return;
}

/* U novi niz se upisuju svi koji nisu dupli */	
void izbaci_duple_bez_promjene (int *niz, int *novi_niz, int vel, int *nova_vel) {  
	int *p, *q, *r;
	int nije_dupli;
	
	p = niz;
	r = novi_niz;
	*nova_vel = 0;
	while (p < niz + vel) {
		/* Provjeriti da li postoji *p u novom nizu, ako ne onda je potrebno ubaciti ga */
		nije_dupli = 1;
		q = novi_niz;
		/* *p pisemo u novi niz ako ga vec nismo upisali */
		while (q < novi_niz + *nova_vel) {
			if (*p == *q) {
				nije_dupli = 0;
				break;
			}
			q++;
		}
		if (nije_dupli) {
			/* Ako nije dupli, upisi ga u niz */
			/*ova linija je graska prema testovima*/
			*r = *p; /* r se uvijek nalazi na kraju tako da pomocu njega upisujemo */
			(*nova_vel)++;
			r++;
		}
		p++;
	}
	return;
}

int dva_od_tri (int *niz1, int vel1, int *niz2, int vel2, int *niz3, int vel3) {
	int novi_niz1[100], novi_niz2[100], novi_niz3[100];
	int nova_vel1, nova_vel2, nova_vel3;
	int *p, *q, *r;
	int postoji1, postoji2, postoji3;
	int brojac = 0;
	
	izbaci_duple_bez_promjene (niz1, novi_niz1, vel1, &nova_vel1);
	izbaci_duple_bez_promjene (niz2, novi_niz2, vel2, &nova_vel2);
	izbaci_duple_bez_promjene (niz3, novi_niz3, vel3, &nova_vel3);
	
	/* Ovo broji niz1 sa niz2, niz1 sa niz3, fali niz2 sa niz3 */
	p = novi_niz1;
	while (p < novi_niz1 + nova_vel1) {
		postoji2 = postoji3 = 0;
		q = novi_niz2;
		r = novi_niz3;
		while (q < novi_niz2 + nova_vel2) {
			if (*p == *q) {
				postoji2 = 1;
				break;
			}
			q++;
		}
		while (r < novi_niz3 + nova_vel3) {
			if (*p == *r) {
				postoji3 = 1;
				break;
			}
			r++;
		}
		
		if ((postoji2 && !postoji3) || (!postoji2 && postoji3)) /* Prolazimo kroz prvi i gledamo da postoji u jednom, a ne postoji u drugom od preostalih (1 sa 2, i 1 sa 3)*/ 
			brojac++;
			
		p++;
	}
	
	q = novi_niz2;
	while (q < novi_niz2 + nova_vel2) {
		p = novi_niz1;
		r = novi_niz3;
		postoji1 = postoji3 = 0;
		while (p < novi_niz1 + nova_vel1) {
			if (*q == *p) {
				postoji1 = 1;
				break;
			}
			p++;
		}
		while (r < novi_niz3 + nova_vel3) {
			if (*q == *r) {
				postoji3 = 1;
				break;
			}
			r++;
		}
		
		if (!postoji1 && postoji3)	/*preostalo nam je da provjerimo 2 sa 3, dakle element ne postoji u prvom a postoji u trecem nizu*/
			brojac++;
			
		q++;
	}
	
	return brojac;
}

int main() {
	int niz1[] = {1, 2, 3, 5 };
	int niz2[] = {1, 2, 4, 6, 7 };
	int niz3[] = {1, 3, 4, 8, 9, 10 };
	
	printf("%d", dva_od_tri(niz1, 4, niz2, 5, niz3, 6));
	return 0;
}
