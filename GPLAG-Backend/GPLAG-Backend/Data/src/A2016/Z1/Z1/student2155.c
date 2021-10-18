#include <stdio.h>
int main() {
	double T1,T2,Tp,Tz,T3,B1,B2,Bp,Bz,B3,M1,M2,Mp,Mz,M3,T,B,M,OT,OM,OB;
	/* Tarik */
	printf("Unesite bodove za Tarika: ");
	printf("\nI parcijalni ispit: ");
	scanf("%lf", &T1);
	if(T1 <0 || T1 > 20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &T2);
	if(T2 < 0 || T2 > 20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &Tp);
	if(Tp < 0 || Tp > 10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &Tz);
	if(Tz < 0 || Tz > 10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &T3);
	if(T3 < 0 || T3 > 40){
		printf("Neispravan broj bodova");
		return 0;
	}
	/* Bojan */
	printf("Unesite bodove za Bojana: ");
	printf("\nI parcijalni ispit: ");
	scanf("%lf", &B1);
	if(B1 <0 || B1 > 20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &B2);
	if(B2 < 0 || B2 > 20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &Bp);
	if(Bp < 0 || Bp > 10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &Bz);
	if(Bz < 0 || Bz > 10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &B3);
	if(B3 < 0 || B3 > 40){
		printf("Neispravan broj bodova");
		return 0;
	}
	/* Mirza */
	printf("Unesite bodove za Mirzu: ");
	printf("\nI parcijalni ispit: ");
	scanf("%lf", &M1);
	if(M1 <0 || M1 > 20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &M2);
	if(M2 < 0 || M2 > 20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &Mp);
	if(Mp < 0 || Mp > 10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &Mz);
	if(Mz < 0 || Mz > 10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &M3);
	if(M3 < 0 || M3 > 40){
		printf("Neispravan broj bodova");
		return 0;
	}
	T=T1+T2+Tz+Tp+T3;
	B=B1+B2+B3+Bz+Bp;
	M=M1+M2+M3+Mz+Mp;
	if(T >= 55 && B >= 55 && M >= 55){
		printf("Sva tri studenta su polozila.");
				if(T >= 55 && T < 65){
		OT = 6;
	} else if( T >= 65 && T < 75){
		OT = 7;
	} else if(T >= 75 && T < 85){
		OT = 8;
	} else if(T >= 85 && T < 92){
		OT = 9;
	} else if(T >= 92 && T <= 100){
		OT=10;
	}
	if(B >= 55 && B < 65){
		OB = 6;
	} else if( B >= 65 && B < 75){
		OB = 7;
	} else if(B >= 75 && B < 85){
		OB = 8;
	} else if(B >= 85 && B < 92){
		OB = 9;
	} else if(B >= 92 && B <= 100){
		OB=10;
	}
	if(M >= 55 && M < 65){
		OM = 6;
	} else if( M >= 65 && M < 75){
		OM = 7;
	} else if(M >= 75 && M < 85){
		OM = 8;
	} else if(M >= 85 && M < 92){
		OM = 9;
	} else if(M >= 92 && M <= 100){
		OM=10;
	}
	if(OT == OB && OB == OM){
		printf("\nSva tri studenta imaju istu ocjenu.");
	} else if(OT == OB || OB == OM || OT == OM){
		printf("\nDva od tri studenta imaju istu ocjenu.");
		} else{
		printf("\nSvaki student ima razlicitu ocjenu.");
		}}
		else if(T >= 55 && B >= 55 || T >= 55 && M >= 55 || B >= 55 && M >= 55){
		printf("Dva studenta su polozila.");
	} else if (T >= 55.0 || B >= 55 || M >=55){
		printf("Jedan student je polozio.");
	} else {
		printf("Nijedan student nije polozio.");
	}
	return 0;
}
