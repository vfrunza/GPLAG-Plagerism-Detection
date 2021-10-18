#include <stdio.h>

int main() {
	float I1, II1, DZ1, P1, Z1, S1, O1, I2, II2, P2, DZ2, Z2, S2, O2, I3, II3, P3, DZ3, Z3, S3, O3;

	
	
	printf("Unesite bodove za Tarika:\n");
	
	printf("I parcijalni ispit: ");
	scanf("%f", &I1);
	
	if(I1<0 || I1>20)
	{
		printf("Nesipravan broj bodova\n");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f", &II1);
	
	if(II1<0 || II1>20)
	{
		printf("Neispravan broj bodova\n");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%f", &P1);
	
	if(P1<0 || P1>10)
	{
		printf("Nesipravan broj bodova\n");
		return 0;
	}	
	
	printf("Zadace: ");
	scanf("%f", &DZ1);
	
	if(DZ1<0 || DZ1>10)
	{
		printf("Nesipravan broj bodova");
		return 0;
	}
	
	printf("Zavrsni ispit: ");
	scanf("%f", &Z1);
	
	if(Z1<0 || Z1>40)
	{
		printf("Nesipravan broj bodova");
		return 0;
	}
	
	S1=I1+II1+P1+DZ1+Z1;
	
	if(S1==0 && S1<=55)
		O1=5;
	else if(S1>55 && S1<=65)
		O1=6;
	else if(S1>65 && S1<=75)
		O1=7;
	else if(S1>75 && S1<=85)
		O1=8;
	else if(S1>85 && S1<=92)
		O1=9;
	else
		O1=10;
	
	
	
	printf("Unesite bodove za Bojana:\n");
	
	printf("I parcijalni ispit: ");
	scanf("%f", &I2);
	
	if(I2<0 || I2>20)
	{
		printf("Nesipravan broj bodova\n");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f", &II2);
	
	if(II2<0 || II2>20)
	{
		printf("Neispravan broj bodova\n");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%f", &P2);
	
	if(P2<0 || P2>10)
	{
		printf("Nesipravan broj bodova\n");
		return 0;
	}	
	
	printf("Zadace: ");
	scanf("%f", &DZ2);
	
	if(DZ2<0 || DZ2>10)
	{
		printf("Nesipravan broj bodova");
		return 0;
	}
	
	printf("Zavrsni ispit: ");
	scanf("%f", &Z2);
	
	if(Z2<0 || Z2>40)
	{
		printf("Nesipravan broj bodova");
		return 0;
	}
	
	S2=I2+II2+P2+DZ2+Z2;
	
	if(S2==0 && S2<=55)
		O2=5;
	else if(S2>55 && S2<=65)
		O2=6;
	else if(S2>65 && S2<=75)
		O2=7;
	else if(S2>75 && S2<=85)
		O2=8;
	else if(S2>85 && S2<=92)
		O2=9;
	else
		O2=10;
		
	
	
	printf("Unesite bodove za Mirzu:\n");
	
	printf("I parcijalni ispit: ");
	scanf("%f", &I3);
	
	if(I3<0 || I3>20)
	{
		printf("Nesipravan broj bodova\n");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f", &II3);
	
	if(II3<0 || II3>20)
	{
		printf("Neispravan broj bodova\n");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%f", &P3);
	
	if(P3<0 || P3>10)
	{
		printf("Nesipravan broj bodova\n");
		return 0;
	}	
	
	printf("Zadace: ");
	scanf("%f", &DZ3);
	
	if(DZ3<0 || DZ3>10)
	{
		printf("Nesipravan broj bodova");
		return 0;
	}
	
	printf("Zavrsni ispit: ");
	scanf("%f", &Z3);
	
	if(Z3<0 || Z3>40)
	{
		printf("Nesipravan broj bodova");
		return 0;
	}
	
	S3=I3+II3+P3+DZ3+Z3;
	
	if(S3==0 && S3<=55)
		O3=5;
	else if(S3>55 && S3<=65)
		O3=6;
	else if(S3>65 && S3<=75)
		O3=7;
	else if(S3>75 && S3<=85)
		O3=8;
	else if(S3>85 && S3<=92)
		O3=9;
	else
		O3=10;
		
	
	
	if(O1<6 && O2<6 && O3<6)
		printf("Nijedan student nije polozio.\n");
		
	
	if((O1>5 && O2<6 && O3) || (O1<6 && O2>5 && O3<6) || (O1<6 && O2<6 && O3>5))
		printf("Jedan student je polozio.\n");
		
	
	if((O1>5 && O2>5 && O3<6) || (O1>5 && O2<6 && O3>5) || (O1<6 && O2>5 && O3>5))
		printf("Dva studenta su polozila.\n");
		
	
	if(O1>5 && O2>5 && O3>5)
		printf("Sva tri studenta su polozila.\n");
		
	
	if(O1==O2 && O1==O3)
		printf("Sva tri studenta imaju istu ocjenu.");
		
	
	if((O1==O2 && O1!=O3) || (O1==O3 && O1!=O2) || (O2==O3 && O2!=O1))
		printf("Dva od tri studenta imaju istu ocjenu.");
	
	
	if(O1!=O2 && O1!=O3 && O2!=O3)
		printf("Svaki student ima razlicitu ocjenu.");
		
	return 0;
}
