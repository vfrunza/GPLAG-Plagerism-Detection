#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void ubaci(int* A, int vel) {
	
	int i, j, c, temp_c, duzina_cifre, B[5555] = {0}, C[5555] = {0};
	
	for(i=0; i<vel; i++) {
		c = A[i];
		temp_c = c;
		
		duzina_cifre = 0;
		
		while(temp_c) {
			temp_c/=10;
			duzina_cifre++;
		}
		
		for(j=0; j<duzina_cifre; j++) {
			B[i]+=c%10;
			c/=10;
		}
	}
	
	for(i=0; i<vel; i++) {
		if(B[i]<0){
			B[i] = fabs(B[i]);
		}
	}
	
	for(i=0; i<vel*2; i++) {
		C[i*2] = A[i];
		C[i*2+1] = B[i];
	}
	
	for(i=0; i<vel*2; i++) {
		A[i] = C[i];
	}
}

void izbaci_element(int* niz, int broj, int *vel) {
	
	int i, j=0, temp_niz[5555] = {0};
	
	for(i=0; i<*vel; i++) {
		if(niz[i] == broj) {
			continue;
		} 
		else {
			temp_niz[j] = niz[i];
			j++;
		}
	}
	*vel = j;
	
	for(i=0; i<*vel; i++) {
		niz[i] = temp_niz[i];
	}
}

int da_li_je_fibonacci(int x) {

	long broj_int1, broj_int2;
	double broj_double1, broj_double2;
	
	if(x<=0) return 0;
	
	broj_double1 = sqrt(5*pow(x,2)+4);
	broj_int1 = broj_double1;
	broj_double2 = sqrt(5*pow(x,2)-4);
	broj_int2 = broj_double2;
	
	if((broj_int1<=broj_double1 && broj_int1>=broj_double1) || (broj_int2<=broj_double2 && broj_int2>=broj_double2)) {
		return 1;
	}
	else return 0;
}

int izbaci(int* A, int vel) {
	
	int i=0;
	
	for(i=0; i<vel; i++) {
		if(da_li_je_fibonacci(A[i])) {
			izbaci_element(A,A[i],&vel);
			i--;
		}
	}
	return vel;
}

int main() {
	
	int i, niz[100] = {0}, vel;
	
	printf("Unesite niz od 10 brojeva: ");
	for(i=0; i<10; i++) {
		scanf("%d", &niz[i]);
	}
	
	ubaci(niz,10);
	vel = izbaci(niz,20);
	
	printf("Modificirani niz glasi: ");
	for(i=0; i<vel-1; i++) {
		printf("%d, ", niz[i]);
	}
	if(vel>0) {
		printf("%d.", niz[vel-1]);
	} 
	else if(vel==0) {
		printf("Modificirani niz glasi: %d.", 0);
	}

	return 0;
}