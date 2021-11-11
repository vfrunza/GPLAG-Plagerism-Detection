#include <stdio.h>


int dva_od_tri(int niz1[], int vel1, int niz2[], int vel2, int niz3[], int vel3) {
	int i, j, k, br_pojav=0, pomocna, presjek_sva_tri=0, razlika_skupova=0, u_samo_dva=0, ukupan_broj=0, svi_razliciti;
	
	/*Trazenje ukupnog broja clanova u sva tri niza*/
	for (i=0; i<vel1; i++) {
		pomocna=0;
		for (j=0; j<i; j++) {
			if (niz1[i]==niz1[j]) {
				pomocna=1;
				break;
			}
		}
		if (pomocna==1) {
			continue;
		}
		ukupan_broj++;
	}
	for (i=0; i<vel2; i++) {
		pomocna=0;
		for (j=0; j<i; j++) {
			if (niz2[i]==niz2[j]) {
				pomocna=1;
				break;
			}
		}
		if (pomocna==1) {
			continue;
		}
		ukupan_broj++;
	}
	for (i=0; i<vel3; i++) {
		pomocna=0;
		for (j=0; j<i; j++) {
			if (niz3[i]==niz3[j]) {
				pomocna=1;
				break;
			}
		}
		if (pomocna==1) {
			continue;
		}
		ukupan_broj++;
	}
	
	/*Trazenje broja clanova koji se nalaze u sva tri niza*/
	for (i=0; i<vel1; i++) {
		br_pojav=1;
		pomocna=0;
		for (j=0; j<i; j++) {
			if (niz1[i]==niz1[j]) {
				pomocna=1;
				break;
			}
		}
		if (pomocna==1) {
			continue;
		}
		for (j=0; j<vel2; j++) {
			pomocna=0;
			for (k=0; k<j; k++) {
				if (niz2[j]==niz2[k]) {
					pomocna=1;
					break;
				}
			}
			if (pomocna==1) {
				continue;
			}
			if (niz1[i]==niz2[j]) {
				br_pojav++;
				break;
			}
		}
		for (j=0; j<vel3; j++) {
			pomocna=0;
			for (k=0; k<j; k++) {
				if (niz3[j]==niz3[k]) {
					pomocna=1;
					break;
				}
			}
			if (pomocna==1) {
				continue;
			}
			if (niz1[i]==niz3[j]) {
				br_pojav++;
			}
		}
		if (br_pojav==3) {
			presjek_sva_tri++;
		}
	}
	
	/*Trazenje broja elemenata koji se nalaze u samo jednom nizu*/
	for (i=0; i<vel1; i++) {
		pomocna=0;
		for (j=0; j<i; j++) {
			if (niz1[i]==niz1[j]) {
				pomocna=1;
				break;
			}
		}
		if (pomocna==1) {
			continue;
		}
		svi_razliciti=1;
		for (j=0; j<vel2; j++) {
			pomocna=0;
			for (k=0; k<j; k++) {
				if (niz2[j]==niz2[k]) {
					pomocna=1;
					break;
				}
			}
			if (pomocna==1) {
				continue;
			}
			if (niz1[i]==niz2[j]) {
				svi_razliciti=0;
				break;
			}
		}
		if (svi_razliciti) {
			for (j=0; j<vel3; j++) {
				pomocna=0;
				for (k=0; k<j; k++) {
					if (niz3[j]==niz3[k]) {
						pomocna=1;
						break;
					}
				}
				if (pomocna==1) {
					continue;
				}
				if (niz1[i]==niz3[j]) {
					svi_razliciti=0;
					break;
				}
			}
		}
		if (svi_razliciti) {
			razlika_skupova++;
		}
	}
	for (i=0; i<vel2; i++) {
		pomocna=0;
		for (j=0; j<i; j++) {
			if (niz2[i]==niz2[j]) {
				pomocna=1;
				break;
			}
		}
		if (pomocna==1) {
			continue;
		}
		svi_razliciti=1;
		for (j=0; j<vel3; j++) {
			pomocna=0;
			for (k=0; k<j; k++) {
				if (niz3[j]==niz3[k]) {
					pomocna=1;
					break;
				}
			}
			if (pomocna==1) {
				continue;
			}
			if (niz2[i]==niz3[j]) {
				svi_razliciti=0;
				break;
			}
		}
		if (svi_razliciti) {
			for (j=0; j<vel1; j++) {
				pomocna=0;
				for (k=0; k<j; k++) {
					if (niz1[j]==niz1[k]) {
						pomocna=1;
						break;
					}
				}
				if (pomocna==1) {
					continue;
				}
				if (niz2[i]==niz1[j]) {
					svi_razliciti=0;
					break;
				}
			}
		}
		if (svi_razliciti) {
			razlika_skupova++;
		}
	}
	for (i=0; i<vel3; i++) {
		pomocna=0;
		for (j=0; j<i; j++) {
			if (niz3[i]==niz3[j]) {
				pomocna=1;
				break;
			}
		}
		if (pomocna==1) {
			continue;
		}
		svi_razliciti=1;
		for (j=0; j<vel1; j++) {
			pomocna=0;
			for (k=0; k<j; k++) {
				if (niz1[j]==niz1[k]) {
					pomocna=1;
					break;
				}
			}
			if (pomocna==1) {
				continue;
			}
			if (niz3[i]==niz1[j]) {
				svi_razliciti=0;
				break;
			}
		}
		if (svi_razliciti) {
			for (j=0; j<vel2; j++) {
				pomocna=0;
				for (k=0; k<j; k++) {
					if (niz2[j]==niz2[k]) {
						pomocna=1;
						break;
					}
				}
				if (pomocna==1) {
					continue;
				}
				if (niz3[i]==niz2[j]) {
					svi_razliciti=0;
					break;
				}
			}
		}
		if (svi_razliciti) {
			razlika_skupova++;
		}
	}
	
	u_samo_dva=(ukupan_broj-razlika_skupova-(3*presjek_sva_tri))/2;
	
	return u_samo_dva;
}


int main() {
	int niz1[]={-2, -2, -2, -3, -6};
	int niz2[]={-2, -2, -2, -6};
	int niz3[]={-3, -3, -3, -3, -3, -3};
	
	printf("%d", dva_od_tri(niz1, 5, niz2, 4, niz3, 6));
	
	return 0;
}
