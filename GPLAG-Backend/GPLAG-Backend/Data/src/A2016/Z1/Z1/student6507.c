#include <stdio.h>
#include <math.h>
#define PPI 20
#define DPI 20
#define P 10
#define Z 10
#define ZI 40


int main() {
	double x1, x2, x3, x4, x5, y1, y2, y3, y4, y5, z1, z2, z3, z4, z5, S1, S2, S3;
	int O1, O2, O3;
	printf("Unesite bodove za Tarika: \n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &x1);
	
	if(x1<0 || x1>20){
		printf("Neispravan broj bodova");
		return 0; 
	}
	
	printf("II parcijalni ispit: ");
	scanf("%lf", &x2);
	if(x2<0 || x2>DPI){
		printf("Neispravan broj bodova");
		return 0;
	}
	
	printf("Prisustvo: ");
	scanf("%lf", &x3);
	if(x3<0 || x3>P){
		printf("Neispravan broj bodova");
		return 0;
	}
	
	printf("Zadace: ");
	scanf("%lf", &x4);
	if(x4<0 || x4>Z){
		printf("Neispravan broj bodova");
		return 0;
	}
	
	printf("Zavrsni ispit: ");
	scanf("%lf", &x5);
	if(x5<0 || x5>ZI){
		printf("Neispravan broj bodova");
		return 0;
	}
	
	
	
	
	printf("Unesite bodove za Bojana: \n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &y1);
	if(y1<0 || y1>PPI){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &y2);
	if(y2<0 || y2>DPI){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &y3);
	if(y3<0 || y3>P){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &y4);
	if(y4<0 || y4>Z){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &y5);
	if(y5<0 || y5>ZI){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Unesite bodove za Mirzu: \n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &z1);
	if(z1<0 || z1>PPI){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &z2);
	if(z2<0 || z2>DPI){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &z3);
	if(z3<0 || z3>P){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &z4);
	if(z4<0 || z4>Z){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &z5);
	if(z5<0 || z5>ZI) {
		printf("Neispravan broj bodova");
		return 0;
	}
	S1=x1+x2+x3+x4+x5;
	S2=y1+y2+y3+y4+y5;
	S3=z1+z2+z3+z4+z5;
	
	if(S1>=55  && S1<65){
		O1=6;
		
	}
	else if(S1>=65 && S1<75){
		O1=7;
	}
	else if(S1>=75 && S1<85){
		O1=8;
	}
	else if(S1>=85 && S1<92){
		O1=9;
	}
	else if(S1>=92 && S1<=100){
		O1=10;
	}
	
	if(S2>=55 && S2<65){
		O2=6;
	}
	else if(S2>=65 && S2<75){
		O2=7;
	}
	else if(S2>=75 && S2<85){
		O2=8;
	}
	else if(S2>=85 && S2<92){
		O2=9;
	}
	else if(S2>=92 && S2<=100){
		O2=10;
	}
	
	if(S3>=55 && S3<65){
		O3=6;
	}
	else if(S3>=65 && S3<75){
		O3=7;
	}
	else if(S3>=75 && S3<85){
		O3=8;
	}
	else if(S3>=85 && S3<92){
		O3=9;
	}
	else if(S3>=92 && S3<=100){
		O3=10;
	}
	
	if(S1<55 && S2<55 && S3<55){
		printf("Nijedan student nije polozio.\n");
	}
	else if((S1>=55 && S2<55 && S3<55) || (S1<55 && S2>=55 && S3<55) ||(S1<55 && S2<55 && S3>=55)){
		printf("Jedan student je polozio.\n");
	}
	
	else if((S1>=55 && S2>=55 && S3<55) || (S1>=55 && S2<55 && S3>=55) || (S1<55 && S2>=55 && S3>=55)){
		printf("Dva studenta su polozila.\n");
	}
	else if(S1>=55 && S2>=55 && S3>=55){
		printf("Sva tri studenta su polozila.\n");
		
		if((O1==O2 && O2!=O3) || (O1==O3 && O3!=O2) || (O2==O3 && O3!=O1)){
			printf("Dva od tri studenta imaju istu ocjenu.\n");
		}
		else if(O1==O2 && O2==O3){
			printf("Sva tri studenta imaju istu ocjenu.\n");
		}
		else if(O1!=O2 && O2!=O3 ){
			printf("Svaki student ima razlicitu ocjenu.\n");
		}
	}
	
		
	return 0;
}
