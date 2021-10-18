#include <stdio.h>
#include <math.h>

int izbaci_cifre(int brojevi[], int velBrojevi, int cifre[], int velCifre) {
	int i, j, k, size = 0, brojevinizovi[4][100] = {{0}}, *firstBrojevi, number = 0, pownum = 0;
	firstBrojevi = brojevi;
	for(i=0; i<velBrojevi; i++) {
		brojevinizovi[0][i] = *brojevi++;
	}

	for(i=0; i<velCifre; i++) {
		brojevinizovi[1][i] = *cifre++;
	}
	brojevi = firstBrojevi;
	for(i=velBrojevi-1; i>=0; i--) { //for za size
		number = *brojevi++;
		if(number < 0) number *= -1;
		while (number>0) {
			brojevinizovi[2][size] = number%10;
			number/=10;
			size++;
		}
		brojevinizovi[2][size] = 999;
		size++;
	}
	for(i=0; i<size; i++) {
		if(brojevinizovi[2][i] == 999) {
			continue;
		}
		for(j=0; j<velCifre; j++) {
			if(brojevinizovi[2][i] == brojevinizovi[1][j]) {
				for(k=i; k<size-1; k++) {
					brojevinizovi[2][k] = brojevinizovi[2][k+1];
				}
				size--;
				i--;
			}
		}
	}
	number = 0;
	brojevi = firstBrojevi;
	for(i=0; i<size; i++) {
		if(brojevinizovi[2][i] == 999) {
			if(*brojevi < 0) number *= -1;
			*brojevi = number;
			brojevi++;
			number = 0;
			pownum = 0;
			continue;
		} else {
			number += brojevinizovi[2][i]*pow(10,pownum);
			pownum++;
		}
	}


	for(i=0; i<velCifre; i++) {
		if(brojevinizovi[1][i] < 0 || brojevinizovi[1][i] > 9) {
			return 0;
		}

		for(j=i; j<velCifre-1; j++) {
			if(brojevinizovi[1][i] == brojevinizovi[1][j+1]) return 0;
		}
	}
	return 1;
}

int main() {

	return 0;
}
