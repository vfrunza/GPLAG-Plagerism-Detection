#include <stdio.h>

/*Provjera: da li je broj prost*/
int daj_prost() {
	static int i=1, slozen=0, j;
	i++;
	
	while(slozen==0) {
		for(j=2; j<i; j++) {
		if(i%j==0) { /*Ako je broj djeljiv s vise brojeva, a ne samo s samim sobom onda je slozen*/
			slozen=1;
			break; 
		}	
		}
		if(slozen==0) { /*Ako je prost broj, f-ja nam ga treba vratiti*/
			return i;
		} else { /*Ako nije prost, trazimo sljedeci prost*/
			i++;
			slozen=0;
	}
	}
	return 0;
}

int main() {
	int a, b, i, pb, s=0;
	
	
	do {
		printf("Unesite brojeve A i B: "); /*Unos prirodnih brojeva*/
		scanf("%d %d", &a, &b);
		if(b<=a) { /*Provjera uslova*/
			printf("A nije manje od B.\n");
		} else if(a<1) {
			printf("A nije prirodan broj.\n");
		} else if(b<1) {
			printf("B nije prirodan broj.\n");
		}
	} while(b<=a || a<1 || b<1);
	
	/*Racunanje sume svih prostih brojeva ako je uslov ispunjen*/
	if(a<b) {
		for(i=0; i<b; i++) {
			pb=daj_prost(); /*poziv f-je daj_prost()*/
			if(pb>a && pb<b) { /*Ako je broj izmedju a i b dodaje se na sumu*/
				s+=pb;
			}
		}
	}
	
	/*Ispis sume prostih brojeva*/
	printf("Suma prostih brojeva izmedju %d i %d je %d.", a,b,s);
	
	return 0;
} 