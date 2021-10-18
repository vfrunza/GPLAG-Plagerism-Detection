#include <stdio.h>

int main() {
	double T1, T2, B1, B2, M1, M2;
	double Pt, Pb, Pm, Zt, Zb, Zm, Ut, Ub, Um;
	int brojac=0;
	double bodT, bodB, bodM;
	int ocjena1, ocjena2, ocjena3;
	/*TARIK*/
	printf("Unesite bodove za Tarika:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &T1);
	if(T1<0 || T1>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &T2);
	if(T2<0 || T2>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &Pt);
	if(Pt<0 || Pt>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &Zt);
	if(Zt<0 || Zt>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &Ut);
	if(Ut<0 || Ut>40){
		printf("Neispravan broj bodova");
		return 0;
	}
	/*Bojan*/
	printf("Unesite bodove za Bojana:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &B1);
	if(B1<0 || B1>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &B2);
	if(B2<0 || B2>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &Pb);
	if(Pb<0 || Pb>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &Zb);
	if(Zb<0 || Zb>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &Ub);
	if(Ub<0 || Ub>40){
		printf("Neispravan broj bodova");
		return 0;
	}
	/*Mirza*/
	printf("Unesite bodove za Mirzu:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &M1);
	if(M1<0 || M1>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &M2);
	if(M2<0 || M2>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &Pm);
	if(Pm<0 || Pm>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &Zm);
	if(Zm<0 || Zm>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &Um);
	if(Um<0 || Um>40){
		printf("Neispravan broj bodova");
		return 0;
	}
	bodT=T1+T2+Pt+Zt+Ut;
	bodB=B1+B2+Pb+Zb+Ub;
	bodM=M1+M2+Pm+Zm+Um;
	if(bodT>=55)brojac++;
	if(bodB>=55)brojac++;
	if(bodM>=55)brojac++;
	switch(brojac){
		case 0:
		printf("Nijedan student nije polozio.\n");
		break;
		case 1:
		printf("Jedan student je polozio.\n");
		break;
		case 2:
		printf("Dva studenta su polozila.\n");
		break;
		default :
		printf("Sva tri studenta su polozila.\n");
	}
	if (brojac==3){
		if (bodT>=55 && bodT<=64){
			ocjena1=6;
		}
		else if(bodT>=65 && bodT<=74){
			ocjena1=7;
		}
		else if(bodT>=75 && bodT<=84){
			ocjena1=8;
		}
		else if(bodT>=85 && bodT<=91){
			ocjena1=9;
		}
		else{
			ocjena1=10;
		}
		if (bodB>=55 && bodB<=64){
			ocjena2=6;
		}
		else if(bodB>=65 && bodB<=74){
			ocjena2=7;
		}
		else if(bodB>=75 && bodB<=84){
			ocjena2=8;
		}
		else if(bodB>=85 && bodB<=91){
			ocjena2=9;
		}
		else{
			ocjena2=10;
		}
		if (bodM>=55 && bodM<=64){
			ocjena3=6;
		}
		else if(bodM>=65 && bodM<=74){
			ocjena3=7;
		}
		else if(bodM>=75 && bodM<=84){
			ocjena3=8;
		}
		else if(bodM>=85 && bodM<=91){
			ocjena3=9;
		}
		else{
			ocjena3=10;
		}
	if(ocjena1==ocjena2 && ocjena1==ocjena3) printf("Sva tri studenta imaju istu ocjenu.");
	else if(ocjena1==ocjena2 || ocjena1==ocjena3 || ocjena2==ocjena3)printf("Dva od tri studenta imaju istu ocjenu.");
	else printf("Svaki student ima razlicitu ocjenu.");
	}
	return 0;
}