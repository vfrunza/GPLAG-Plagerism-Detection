#include <stdio.h>
#define PKKK 6.80
#define PT 8.00
#define PL 5.30
#define HKKK 3.30
#define HT 3.00
#define HL 5.00
#define CKKK 5.00
#define CT 3.90
#define CL 6.00

int main() {
	char tarik,bojan,mirza,novi_red,nav='"';
	double cijenaKKK=0,cijenaT=0,cijenaL=0,tarikKKK=0,tarikT=0,tarikL=0,mirzaKKK=0,mirzaT=0,mirzaL=0,bojanKKK=0,bojanT=0,bojanL;
	printf("Unesite jelo za Tarika: ");
	scanf ("%c", &tarik);
	scanf ("%c", &novi_red);
	printf ("Unesite jelo za Bojana: ");
	scanf ("%c", &bojan);
	scanf ("%c",&novi_red);
	printf ("Unesite jelo za Mirzu: ");
	scanf ("%c",&mirza);
	scanf ("%c", &novi_red);
			if (tarik=='P') {
				tarikKKK=PKKK;
				tarikT=PT;
			 	tarikL=PL;
			} 
			else if (tarik=='H') {
				tarikKKK=HKKK;
				tarikT=HT;
				tarikL=HL;
			}
			else if (tarik=='C') {
				tarikKKK=CKKK;
				tarikT=CT;
				tarikL=CL;
			}
			if (bojan=='P') {
				bojanKKK=PKKK;
				bojanT=PT;
				bojanL=PL;
			}
			else if (bojan=='H') {
				bojanKKK=HKKK;
				bojanT=HT;
				bojanL=HL;
			}
			else if (bojan=='C') {
				bojanKKK=CKKK;
				bojanT=CT;
				bojanL=CL;
			}
			if (mirza=='P') {
				mirzaKKK=PKKK;
				mirzaT=PT;
				mirzaL=PL; 
			}
			else if (mirza=='H') {
				mirzaKKK=HKKK;
				mirzaT=HT;
				mirzaL=HL; 
			}
			else if (mirza=='C') {
				mirzaKKK=CKKK;
				mirzaT=CT;
				mirzaL=CL;
			}
	}
	cijenaKKK=tarikKKK+mirzaKKK+bojanKKK;
	cijenaT=tarikT+mirzaT+bojanT;
	cijenaL=tarikL+mirzaL+bojanL;
	if (cijenaKKK<cijenaT && cijenaKKK<cijenaL) {
		printf ("Najjeftiniji je Restoran %cKod konja i konjusara%c (%.2f KM).",nav, cijenaKKK,nav);
	}
	else if (cijenaT<cijenaL && cijenaT<cijenaKKK) {
		printf ("Najjeftiniji je Fast-food %cTrovac%c (%.2f KM).",nav,cijenaT,nav);
		if(tarikKKK>mirzaKKK && tarikKKK>bojanKKK) {
			tarikKKK=(10./100)*tarikKKK;
		}
		else if (mirzaKKK>tarikKKK && mirzaKKK>bojanKKK) {
			mirzaKKK=(10./100)*mirzaKKK;
		}
		else if (bojanKKK>mirzaKKK && bojanKKK>tarikKKK) {
			bojanKKK=(10./100)*bojanKKK;
		}
	}
	else if (cijenaL<cijenaKKK && cijenaL<cijenaT) {
		printf ("Najjeftiniji je Bistro %cLorelei%c (%.2f KM).",nav,cijenaL,nav);
		if (tarikKKK>mirzaKKK && tarikKKK>bojanKKK) {
			tarikKKK=(10./100)*tarikKKK;
		}
		else if (mirzaKKK>tarikKKK && mirzaKKK>bojanKKK) {
			mirzaKKK=(10./100)*mirzaKKK;
		}
		else if (bojanKKK>mirzaKKK && bojanKKK>tarikKKK) {
			bojanKKK=(10./100)*bojanKKK;
		}
	}
		return 0;
}








