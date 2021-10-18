#include <stdio.h>

int dva_od_tri (int niz1[], int vel1, int niz2[], int vel2, int niz3[], int vel3)
{
	int i,j,k,brojac=0,br=0,ponavljanje=0;
	for(i=0; i<vel1; i++) {
		for(j=0; j<i; j++) {
			if(niz1[i]==niz1[j]) ponavljanje++;
		}
		if(ponavljanje>0) {
			ponavljanje=0;
			continue;
		}
		for(j=0; j<vel2; j++) {
			brojac=0;
			if(niz1[i]==niz2[j]) {
				for(k=0; k<vel3; k++) {
					if(niz3[k]!=niz1[i] || niz3[k]!=niz2[j]) brojac++;
				}
				if(brojac==vel3) {
					br++;
					break;
				}
			}
		}
	}
	for(i=0; i<vel1; i++) {
		for(j=0; j<i; j++) {
			if(niz1[i]==niz1[j]) ponavljanje++;
		}
		if(ponavljanje>0) {
			ponavljanje=0;
			continue;
		}
		for(j=0; j<vel3; j++) {
			brojac=0;
			if(niz1[i]==niz3[j]) {
				for(k=0; k<vel2; k++) {
					if(niz2[k]!=niz1[i] || niz2[k]!=niz3[j]) brojac++;
				}
				if(brojac==vel2) {
					br++;
					break;
				}
			}
		}
	}
	for(i=0; i<vel2; i++) {
		for(j=0; j<i; j++) {
			if(niz2[i]==niz2[j]) ponavljanje++;
		}
		if (ponavljanje>0) {
			ponavljanje=0;
			continue;
		}
		for(j=0; j<vel3; j++) {
			brojac=0;
			if(niz2[i]==niz3[j]) {
				for(k=0; k<vel1; k++) {
					if(niz1[k]!=niz2[i] || niz1[k]!=niz3[j]) brojac++;
				}
				if(brojac==vel1) {
					br++;
					break;
				}
			}
		}
	}
	return br;
}
int main()
{
	return 0;
}
