#include <stdio.h>

int fibonacci(int broj) {
	int i = 0, niz[20000], jeste =0;
	do {
		if (i == 0 || i == 1){
			niz[i] = 1;
		}
		else niz[i] = niz [i-1] + niz[i-2];
		if (broj == niz[i]){
			jeste = 1;
			break;
		}
	}while (niz[i++] < broj);
	return jeste;
}

void ubaci(int* p, int vel) {
    int var, djeljitelj, *q, *d, i = 0;
    q = p;
    while (q < p + 2*vel-1){
    	djeljitelj = 1;
    	d = q + vel-i-1;
    	while (d >= q){
    		*(d+1) = *d;
    		d--;
    	}
    	if (*q < 0) var = -*q;
    	else var = *q;
    	while (var >= 10){
    		var /= 10;
    		djeljitelj *= 10;
    	}
    	if (*q < 0) var = -*q;
    	else var = *q;
    	*(q+1) = 0;
    	while (djeljitelj >= 1){
    		*(q+1) += var/djeljitelj;
    		var = var-(var/djeljitelj)*djeljitelj;
    		djeljitelj /= 10;
    	}
        i++;
    	q += 2;
    }
}

int izbaci(int* p, int vel) {
	int *q, *d;
	q = p;
	while (q < p + vel){
		if (fibonacci(*q)){
			d = q;
			while (d < (p + vel - 1)){
				*d = *(d+1);
				d++;
			}
			q--;
			vel--;
		}
		q++;
	}
	return vel;
}

int main() {
	int niz[20000], i, j;
	printf ("Unesite niz od 10 brojeva: ");
	for (i=0; i<10; i++){
	    scanf ("%d", &niz[i]);
	}
	ubaci(niz, i);
	i = i*2;
	i = izbaci(niz, i);
	printf ("Modificirani niz glasi: ");
	for (j=0; j<i; j++){
		printf ("%d", niz[j]);
		if (j != i-1) {
			printf (", ");
		}
		if (j == i-1) printf (".");
	}
	return 0;
}