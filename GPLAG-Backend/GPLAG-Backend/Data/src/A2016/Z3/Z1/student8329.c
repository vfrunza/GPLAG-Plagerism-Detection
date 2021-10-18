#include <stdio.h>
int daj_prost();
int main()
{
	int A,B,i=1,suma=0;
	int broj;
	broj=daj_prost();

	/*Unos brojeva A i B*/
	do {
		printf("Unesite brojeve A i B: ");
		scanf("%d %d",&A,&B);
		if(A>=B) {
			printf("A nije manje od B.\n");
		}

		else if(A<1) {
			printf("A nije prirodan broj.\n");
		}

	} while((A>=B)||(A<1));


	while(broj<B) {
		broj=daj_prost();
		if((broj>A)&&(broj<B)) { /*Ovaj uslov provjerava da li je vraceni prosti broj u opsegu izmedju A i B*/
			suma=suma+broj;
			i++;
		}
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B,suma);
	return 0;
}
/*Funkcija daj_prost vraca proste brojeve*/
int daj_prost()
{
	int i;
	int provjera=1;
	static int prost=1;
	do {
		prost++;
		if(prost==2)return prost;
		for(i=2; i<prost; i++) {
			if(prost%i==0) {
				provjera=0;
				break;
			}
		}
		if(provjera==1)
			return prost;
		provjera=1;

	} while(1);
}
