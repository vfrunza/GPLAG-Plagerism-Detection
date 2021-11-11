#include <stdio.h>
#include <math.h>

void ubaci (int niz[], int vel) {
	int i=0, suma, temp, br=0;
	
	/* Razdvajanje clanova (mjesto za sumu cifara prethodnog clana) */
	for (i=vel-1; i>0; i--) {
		niz[2*vel-br-2] = niz[i];
		niz[2*vel-br-3] = 0;
		br+=2;
	}
	/* Dodavanje sume prijasnjeg clana na sljedeci clan niza */
	for (i=0; i<2*vel; i+=2) {
		suma = 0;
		temp = niz[i];
		
		while (temp!=0) {
		suma += temp%10;
		temp = temp/10;
		}
		niz[i+1] = fabs(suma);
	} 
}
	/* Funkcije koja vraca posljedni Fibonacijev broj manji ili jednak parametru */
int fibonacci (int broj) {
	int prvi=0, drugi=1, fnacci = 1;
	
	while (fnacci<broj) {
		fnacci = prvi + drugi;
		prvi = drugi;
		drugi = fnacci;
	}
	
	return fnacci;
}

int izbaci (int niz[], int vel) {
	int i, j, broj;
	
	for (i=0; i<vel; i++) {
		broj = fibonacci(niz[i]);
		
		if (broj == niz[i]) {
			for (j=i; j<vel-1; j++) {
				niz[j] = niz[j+1];
			}
			vel--;
			i--;
		}
	}
	
	return vel;
}

int main() {
	int i, niz[20] = {0}, brojac=0, velicina;
	
	printf("Unesite niz od 10 brojeva: ");
	for (i=0; i<10; i++) {
	scanf ("%d", &niz[i]);
	brojac ++ ;
	}
	
	ubaci (niz, brojac);
	velicina = izbaci(niz, 2*brojac);
	
	printf ("Modificirani niz glasi: ");
	for(i=0; i<velicina; i++) {
		if (i==(velicina-1))
		printf ("%d.", niz[i]);
		else
		printf ("%d, ", niz[i]);
	}
	
	return 0;
}