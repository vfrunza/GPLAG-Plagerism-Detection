#include <stdio.h>

int dva_od_tri(int *niz1, int vel1, int *niz2, int vel2, int *niz3, int vel3) {
	int i, j, ret = 0, control = 0, temp;
	for(i = 0; i < vel1 - 1; ++i)
		if(niz[i] > niz[i + 1]) {
			temp = niz[i];
			niz[i] = niz[i + 1];
			niz[i + 1] = temp;
		}
		
	for(i = 0; i < vel1; ++i) {
		for(j = 0; j < vel2; ++j) 
			if(niz1[i] == niz2[j]) {
				control = 1;
				break;
			}
		for(j = 0; j < vel3; ++j)
			if(niz1[i] == niz3[j]) {
				control = 0;
				break;
			}
		if(control) {
			ret++;
			control = 0;
		}
	}
	for(i = 0; i < vel1; ++i) {
		for(j = 0; j < vel3; ++j) 
			if(niz1[i] == niz3[j]) {
				control = 1;
				break;
			}
		for(j = 0; j < vel2; ++j)
			if(niz1[i] == niz2[j]) {
				control = 0;
				break;
			}
		if(control) {
			ret++;
			control = 0;
		}
	}
	for(i = 0; i < vel2; ++i) {
		for(j = 0; j < vel3; ++j) 
			if(niz2[i] == niz3[j]) {
				control = 1;
				break;
			}
		for(j = 0; j < vel1; ++j)
			if(niz2[i] == niz1[j]) {
				control = 0;
				break;
			}
		if(control) {
			ret++;
			control = 0;
		}
	}
	return ret;
}

int main() {
	int niz1[4] = {1, 3, 5};
	int niz2[5] = {1, 2, 4, 6, 7};
	int niz3[6] = {1, 3, 4, 8, 9, 10};
	printf("%d", dva_od_tri(niz1, 4, niz2, 5, niz3, 6));
	return 0;
}
