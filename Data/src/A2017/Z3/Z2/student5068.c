#include <stdio.h>
#include <math.h>

int saberi_cifre(float x) {
	int pomoc_var, broj_cifri=0, suma_cifri=0, i;
	
	pomoc_var=floor(fabs(x));
	while(pomoc_var!=0) {
		broj_cifri++;
		pomoc_var=pomoc_var/10;
	}
	
	//pokusaj sabiranja cifri za svaki clan niza
	
	pomoc_var=floor(fabs(x));
	for(i=0; i<broj_cifri; i++) {
			suma_cifri=suma_cifri + (pomoc_var%10);
			pomoc_var/=10;
		}
		suma_cifri+=round( (fabs(x)-floor(fabs(x)))*10);
		
	return suma_cifri;
}

void zaokruzi1(float *niz, int velicina) {
	int i;
	for(i=0; i<velicina; i++) {
		*(niz+i)=(round(*(niz+i)*10))/10;
	}
}

void preslozi(float *niz, int velicina, int k) {
	int i, brojac_cifri[100]={0}, j, suma_cifri, pomoc_var=1, broj_izvrsavanja=0;
	float temp;
	
	zaokruzi1(niz, velicina);
	
	
	//jos preslaganje -.-
	
	for(i=0; i<velicina; i++) {
		suma_cifri=saberi_cifre(*(niz+i));
		if(suma_cifri<k) {
			temp=*(niz+i);
			for(j=i; j<velicina-1; j++) {
				*(niz+j)=*(niz+j+1);
				broj_izvrsavanja++;
			}
			*(niz+velicina-1)=temp;
		if(saberi_cifre(*(niz+i)<k) && broj_izvrsavanja<=velicina) i--;
		} 
	}
	

	
}

int main() {
	float niz[100];
	int velicina, i, k;
	
	printf("Unesite velicinu niza: \n");
	scanf("%d", &velicina);
	
	printf("Unesite niz: \n");
	for(i=0; i<velicina; i++) {
		scanf("%f", &niz[i]);
	}
	
	printf("Unesite vrijednost k: \n");
	scanf("%d", &k);
	
	preslozi(niz, velicina, k);
	printf("Niz glasi: \n");
	for(i=0; i<velicina; i++) {
		printf("%g ", niz[i]);
	}
	return 0;
}
