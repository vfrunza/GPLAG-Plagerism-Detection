#include <stdio.h>
#include <stdlib.h>

int dva_od_tri(int niz1[], int a, int niz2[], int b, int niz3[], int c) {
	int rez=0;
	int brojac;
	int i, j;
	int prvi, drugi;

	if(a>=b && a>=c) prvi=a;
	if(b>=a && b>=c) prvi=b;
	if(c>=a && c>=b) prvi=c;
	
	if(prvi==a) {
		for(i=0; i<prvi; i++) {
			brojac=1;
			for(j=0; j<b; j++) {
				if(niz1[i]==niz2[j]) brojac++;
			}
			for(j=0; j<c; j++) {
				if(niz1[i]==niz3[j]) brojac++;
			}
			if(brojac==2) rez++;
		}
		if(b>=c) {
			drugi=b;
			for(i=0; i<drugi; i++) {
				brojac=1;
				for(j=0; j<a; j++) {
					if(niz2[i]==niz1[j]) brojac++;
				}
				for(j=0; j<c; j++) {
					if(niz2[i]==niz3[j]) brojac++;
				}
				if(brojac==2) rez++;
			}
		} else {
			drugi=c;
			for(i=0; i<drugi; i++) {
				brojac=1;
				for(j=0; j<a; j++) {
					if(niz3[i]==niz1[j]) brojac++;
				}
				for(j=0; j<b; j++) {
					if(niz3[i]==niz2[j]) brojac++;
				}
				if(brojac==2) rez++;
			}
		}
	} else {
		if(prvi==b) {
			for(i=0; i<prvi; i++) {
				brojac=1;
				for(j=0; j<a; j++) {
					if(niz2[i]==niz1[j]) brojac++;
				}
				for(j=0; j<c; j++) {
					if(niz2[i]==niz3[j]) brojac++;
				}
				if(brojac==2) rez++;
			}
			if(a>=c) {
				drugi=a;
				for(i=0; i<drugi; i++) {
					brojac=1;
					for(j=0; j<b; j++) {
						if(niz1[i]==niz2[j]) brojac++;
					}
					for(j=0; j<c; j++) {
						if(niz1[i]==niz3[j]) brojac++;
					}
					if(brojac==2) rez++;
				}
			} else {
				drugi=c;
				for(i=0; i<drugi; i++) {
					brojac=1;
					for(j=0; j<a; j++) {
						if(niz3[i]==niz1[j]) brojac++;
					}
					for(j=0; j<b; j++) {
						if(niz3[i]==niz2[j]) brojac++;
					}
					if(brojac==2) rez++;
				}
			}
		} else {
			if(prvi==c) {
				for(i=0; i<prvi; i++) {
					brojac=1;
					for(j=0; j<a; j++) {
						if(niz3[i]==niz1[j]) brojac++;
					}
					for(j=0; j<b; j++) {
						if(niz3[i]==niz2[j]) brojac++;
					}
					if(brojac==2) rez++;
					}
				if(a>=b) {
					drugi=a;
					for(i=0; i<drugi; i++) {
					brojac=1;
					for(j=0; j<b; j++) {
						if(niz1[i]==niz2[j]) brojac++;
					}
					for(j=0; j<c; j++) {
						if(niz1[i]==niz3[j]) brojac++;
					}
					if(brojac==2) rez++;
					}
				} else {
					drugi=b;
					for(i=0; i<drugi; i++) {
						brojac=1;
						for(j=0; j<a; j++) {
							if(niz2[i]==niz1[j]) brojac++;
						}
						for(j=0; j<c; j++) {
							if(niz2[i]==niz3[j]) brojac++;
						}
						if(brojac==2) rez++;
					}
				}
			}
		}
	}
	return rez;
}

int main() {
	int niz1[] = {1, 2, 3, 5};
	int niz2[] = {1, 2, 4, 6, 7};
	int niz3[] = {1, 3, 4, 8, 9, 10};
	int rez=dva_od_tri(niz1, 4, niz2, 5, niz3, 6);
	printf("%d", rez);
	return 0;
}
