#include <stdio.h>
#include <math.h>

int izmijeni_broj(int x, int cifra) {
	int novi_broj = 0, stepen_10=1,pomocna;
	pomocna=fabs(x);
	while(pomocna!=0) {
		if(pomocna%10!=cifra) {
			novi_broj=novi_broj+(pomocna%10)*stepen_10;
			stepen_10*=10;
		}
		pomocna/=10;
	}
	if(x>0){
		return novi_broj;
	}
	else {
		return (-novi_broj);
	}
}


int izbaci_cifre(int niz1[], int n1, int niz2[], int n2) {
	int i, j;
	for(i=0; i<n2; i++) {
		for(j=i+1; j<n2; j++) {
			if(niz2[i] == niz2[j] || niz2[i]<0 || niz2[i]>9 || niz2[j]<0 || niz2[j]>9) {
			return 0;
			}
		}
	}
	
	for(i=0; i<n1; i++) {
		for(j=0; j<n2; j++) {
			niz1[i] = izmijeni_broj(niz1[i], niz2[j]);
		}
	}
	return 1;
	
} 

int main() {
	int niz1[1000], niz2[1000], i, n1, n2;
	printf("Unesite velicinu prvog niza: "); scanf("%d", &n1);
	printf("Unesite elemente prvog niza: ");
	for(i=0; i<n1; i++) {
		printf("Unesite %d. element: ", i+1);
		scanf("%d", &niz1[i]);
	}
	printf("Unesite velicinu drugog niza: "); scanf("%d", &n2);
	printf("Unesite elemente drugog niza: ");
	for(i=0; i<n2; i++) {
		printf("Unesite %d. element: ", i+1);
		scanf("%d", &niz2[i]);
	}
	
	printf("%d\n", izbaci_cifre(niz1, n1, niz2, n2));
	
	for(i=0; i<n1; i++) {
		printf("%d ", niz1[i]);
	}
	return 0;
}
