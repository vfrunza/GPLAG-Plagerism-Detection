#include <stdio.h>

int main() {
	double Tp1, Tp2, Tp, Tz, Tzi, Bp1, Bp2, Bp, Bz, Bzi, Mp1, Mp2, Mp, Mz, Mzi, S1, S2, S3, Ot, Ob, Om;
	printf("Unesite bodove za Tarika: \n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &Tp1);
		if(Tp1<0||Tp1>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &Tp2);
		if(Tp2<0||Tp2>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &Tp);
		if(Tp<0||Tp>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &Tz);
		if(Tz<0||Tz>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &Tzi);
		if(Tzi<0||Tzi>40){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Unesite bodove za Bojana: \n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &Bp1);
	if(Bp1<0||Bp1>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &Bp2);
		if(Bp2<0||Bp2>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &Bp);
		if(Bp<0||Bp>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &Bz);
		if(Bz<0||Bz>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &Bzi);
		if(Bzi<0||Bzi>40){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Unesite bodove za Mirzu: \n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &Mp1);
	if(Mp1<0||Mp1>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &Mp2);
		if(Mp2<0||Mp2>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &Mp);
		if(Mp<0||Mp>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &Mz);
		if(Mz<0||Mz>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &Mzi);
		if(Mzi<0||Mzi>40){
		printf("Neispravan broj bodova");
		return 0;
	}
	
	S1=Tp1+Tp2+Tp+Tz+Tzi;
	S2=Bp1+Bp2+Bp+Bz+Bzi;
	S3=Mp1+Mp2+Mp+Mz+Mzi;
	if(S1<55) Ot=5;
	if(S1>=55. && S1<65.) Ot=6;
		if(S1>=65. && S1<75.) Ot=7;
		if(S1>=75. && S1<85.) Ot=8;
		if(S1>=85. && S1<92.) Ot=9;
		if(S1>=92. && S1<=100.) Ot=10;
		if(S2<55) Ob=5;
		if(S2>=55. && S2<65.) Ob=6;
		if(S2>=65. && S2<75.) Ob=7;
		if(S2>=75. && S2<85.) Ob=8;
		if(S2>=85. && S2<92.) Ob=9;
		if(S2>=92. && S2<=100.) Ob=10;
		if(S3<55) Om=5;
		if(S3>=55. && S3<65.) Om=6;
		if(S3>=65. && S3<75.) Om=7;
		if(S3>=75. && S3<85.) Om=8;
		if(S3>=85. && S3<92.) Om=9;
		if(S3>=92. && S3<=100.) Om=10;
	if(Ot>=6 && Ob>=6 && Om>=6){
		printf("Sva tri studenta su polozila.\n");
		if(Ot==Ob&&Ob==Om) printf("Sva tri studenta imaju istu ocjenu.");
		if((Ot==Ob&&Ob!=Om)||(Ot==Om&&Om!=Ob)||(Om==Ob&&Ob!=Ot)) printf("Dva od tri studenta imaju istu ocjenu.\n");
		if(Ot!=Ob&&Ob!=Om) printf("Svaki student ima razlicitu ocjenu.\n");
	}
	if(Ot==5&&Ob==5&&Om==5){
		printf("Nijedan student nije polozio.\n");
	}
	if((Ot>=6&&Ob==5&&Om==5)||(Ot==5&&Ob>=6&&Om==5)||(Ot==5&&Ob==5&&Om>=6)){
		printf("Jedan student je polozio.\n");
	}
	if((Ot==5&&Ob>=6&&Om>=6)||(Ot>=6&&Ob==5&&Om>=6)||(Ot>=6&&Ob>=6&&Om==5)){
		printf("Dva studenta su polozila.\n");
	}
	return 0;
}
