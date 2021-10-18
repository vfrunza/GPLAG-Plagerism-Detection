#include <stdio.h>
int dva_od_tri (int niz_1[], int vel_1, int niz_2[], int vel_2, int niz_3[], int vel_3) {
	int i, j, k, t, rezultat, hocu_li_continue, ima_ga_u_prvom, ima_ga_u_drugom, ima_ga_u_trecem;
	rezultat=0;
	for(i = 0; i < vel_1; i++) {
		hocu_li_continue=0;
		for (t = 0; t < i; t++) {
			if (niz_1[i] == niz_1[t]) hocu_li_continue=1;
		}
		if(hocu_li_continue) continue;
		ima_ga_u_drugom = 0;
		ima_ga_u_trecem = 0;
		for (j = 0; j < vel_2; j++) {
			if(niz_1[i] == niz_2[j]) ima_ga_u_drugom = 1;
		}
		for (k = 0; k < vel_3; k++) {
			if (niz_1[i] == niz_3[k]) ima_ga_u_trecem = 1;
		}
		if ((ima_ga_u_drugom && !ima_ga_u_trecem) || (!ima_ga_u_drugom && ima_ga_u_trecem)) rezultat++;
	}
	for (j = 0; j < vel_2; j++) {
		hocu_li_continue = 0;
		for (t = 0; t < j; t++) {
			if (niz_2[j] == niz_2[t]) hocu_li_continue = 1;
		}
		if (hocu_li_continue) continue;
		ima_ga_u_prvom = 0;
		ima_ga_u_trecem = 0;
		for (k = 0; k < vel_3; k++) {
			if (niz_2[j] == niz_3[k]) ima_ga_u_trecem = 1;
		}
		for (i = 0; i < vel_1; i++) {
			if (niz_2[j] == niz_1[i]) ima_ga_u_prvom = 1;
		}
		if (ima_ga_u_trecem && !ima_ga_u_prvom) rezultat++;
	}
	return rezultat;
}

int main() {
	
	return 0;
	
}
