#include <stdio.h>


int dva_od_tri(int prvi_niz[], int velicina_prvog_niza, int drugi_niz[], int velicina_drugog_niza, int treci_niz [] , int velicina_treceg_niza)
{
	int i, j, k, br_ponovljenih=0, temp;
	int niz_bez_ponovljenih_1[100], niz_bez_ponovljenih_2[100], niz_bez_ponovljenih_3[100];
	int velicina_bp_1 = velicina_prvog_niza, velicina_bp_2 = velicina_drugog_niza, velicina_bp_3 = velicina_treceg_niza;

	for(i = 0; i < velicina_prvog_niza; i++) {
		niz_bez_ponovljenih_1[i] = prvi_niz[i];
	}

	for(i = 0; i < velicina_drugog_niza; i++) {
		niz_bez_ponovljenih_2[i] = drugi_niz[i];
	}

	for(i = 0; i < velicina_treceg_niza; i++) {
		niz_bez_ponovljenih_3[i] = treci_niz[i];
	}

	for(i=0; i < velicina_bp_1; i++) {
		for(j = i + 1; j < velicina_bp_1;) {
			if(niz_bez_ponovljenih_1[j] == niz_bez_ponovljenih_1[i]) {
				for(k = j; k < velicina_bp_1; k++) {
					niz_bez_ponovljenih_1[k] = niz_bez_ponovljenih_1[k+1];
				}
				velicina_bp_1--;
			} else 	j++;
		}
	}

	for(i = 0; i < velicina_bp_2; i++) {
		for(j = i + 1; j < velicina_bp_2;) {
			if(niz_bez_ponovljenih_2[j] == niz_bez_ponovljenih_2[i]) {
				for(k = j; k < velicina_bp_2; k++) {
					niz_bez_ponovljenih_2[k] = niz_bez_ponovljenih_2[k+1];
				}
				velicina_bp_2--;
			} else 	j++;
		}
	}

	for(i = 0; i < velicina_bp_3; i++) {
		for(j = i + 1; j < velicina_bp_3;) {
			if(niz_bez_ponovljenih_3[j] == niz_bez_ponovljenih_3[i]) {
				for(k = j; k < velicina_bp_3; k++) {
					niz_bez_ponovljenih_3[k] = niz_bez_ponovljenih_3[k+1];
				}
				velicina_bp_3--;
			} else 	j++;
		}
	}

	for(i = 0; i < velicina_bp_1 - 1; i++) {
		for(j = 0; j < velicina_bp_1 - 1; j++) {
			if(niz_bez_ponovljenih_1[j+1] < niz_bez_ponovljenih_1[j]) {
				temp = niz_bez_ponovljenih_1[j];
				niz_bez_ponovljenih_1[j] = niz_bez_ponovljenih_1[j+1];
				niz_bez_ponovljenih_1[j+1] = temp;
			}
		}
	}

	for(i = 0; i < velicina_bp_2 - 1; i++) {
		for(j=0; j < velicina_bp_2 - 1; j++) {
			if(niz_bez_ponovljenih_2[j+1]<niz_bez_ponovljenih_2[j]) {
				temp = niz_bez_ponovljenih_2[j];
				niz_bez_ponovljenih_2[j] = niz_bez_ponovljenih_2[j+1];
				niz_bez_ponovljenih_2[j+1] = temp;
			}
		}
	}

	for(i = 0; i < velicina_bp_3-1; i++) {
		for(j = 0; j < velicina_bp_3-1; j++) {
			if(niz_bez_ponovljenih_3[j+1] < niz_bez_ponovljenih_3[j]) {
				temp = niz_bez_ponovljenih_3[j];
				niz_bez_ponovljenih_3[j] = niz_bez_ponovljenih_3[j+1];
				niz_bez_ponovljenih_3[j+1] = temp;
			}
		}
	}

	for(i = 0; i < velicina_bp_1; i++) {
		for(j = 0; j < velicina_bp_2; j++) {
			if(niz_bez_ponovljenih_1[i] == niz_bez_ponovljenih_2[j]) {
				br_ponovljenih++;
				break;
			}
		}
	}

	for(i = 0; i < velicina_bp_2; i++) {
		for(j = 0; j < velicina_bp_3; j++) {
			if(niz_bez_ponovljenih_2[i] == niz_bez_ponovljenih_3[j]) {
				br_ponovljenih++;
				break;
			}

		}
	}

	for(i = 0; i < velicina_bp_1; i++) {
		for(j = 0; j < velicina_bp_3; j++) {
			if(niz_bez_ponovljenih_1[i] == niz_bez_ponovljenih_3[j]) {
				br_ponovljenih++;
				break;
			}
		}
	}

	for(i = 0; i < velicina_bp_1; i++) {
		for(j = 0; j < velicina_bp_2; j++) {
			for(k = 0; k < velicina_bp_3; k++) {
				if(niz_bez_ponovljenih_1[i] == niz_bez_ponovljenih_2[j] && niz_bez_ponovljenih_2[j] == niz_bez_ponovljenih_3[k]) {
					br_ponovljenih -= 3;
					break;
				}
			}
		}
	}
	return br_ponovljenih;
}

int main()
{
	int prvi_niz[100], drugi_niz[100], treci_niz[100], i;
	int velicina_prvog_niza = 0, velicina_drugog_niza = 0, velicina_treceg_niza = 0, ponovljeni;
	printf("Unesite clanove prvog niza: ");
	for(i = 0; i < 100; i++) {
		scanf("%d", &prvi_niz[i]);
		if(prvi_niz[i] == -1) break;
		velicina_prvog_niza++;
	}
	printf("Unesite clanove drugog niza: ");
	for(i = 0; i < 100; i++) {
		scanf("%d", &drugi_niz[i]);
		if(prvi_niz[i] == -1) break;
		velicina_drugog_niza++;
	}
	printf("Unesite clanove treceg niza: ");
	for(i = 0; i < 100; i++) {
		scanf("%d", &treci_niz[i]);
		if(prvi_niz[i] == -1) break;
		velicina_treceg_niza++;
	}

	ponovljeni = dva_od_tri(prvi_niz,velicina_prvog_niza,drugi_niz,velicina_drugog_niza,treci_niz, velicina_treceg_niza);
	printf("Broj ponovljenih u dva od tri niza: %d", ponovljeni);

	return 0;
}
