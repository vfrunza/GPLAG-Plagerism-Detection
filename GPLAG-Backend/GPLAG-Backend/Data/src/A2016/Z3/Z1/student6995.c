#include <stdio.h>
int daj_prost (){
	int k, a, e=1;
	static int r=1;
	k=r;
	k++;
	for( ;e>0;k++) {
		e=0;
		for(a=2;a<k;a++){
			if(k%a ==0) e++;
		}
	}
	k--;
	r=k;
	return k;
}
int main() {
	//printf("zadaca broj 3, zadatak 1");//
	int e,f,g=0,suma=0;
	unos: {
		printf("\nUnesite brojeve A i B: ");
		scanf("%d",&e);
		scanf("%d",&f);
		if ((int) e!=e || e<=0) {
			printf("A nije prirodan broj. ");
			goto unos;
		}
		if (e>=f) {
			printf("A nije manje od B. ");
			goto unos;
		}
		if ((int) f!=f || f<=0) {
			printf("B nije prirodan broj. ");
			goto unos;
		}
	}
	do {
		suma+=g;
	do {
		g=daj_prost();
	} while (g<=e);
		
	} while(g<f);
	printf("Suma prostih brojeva izmedju %d i %d je %d.",e,f,suma);
	return 0;
}
