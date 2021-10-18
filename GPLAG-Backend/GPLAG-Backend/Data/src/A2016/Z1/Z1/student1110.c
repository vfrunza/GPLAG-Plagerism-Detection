#include <stdio.h>

#define par1 20.00
#define par2 20.00
#define p 10.00
#define z 10.00
#define u 40.00
#define PROLAZ 54.00

int main() 
{
	float I1, I2, I3, II1, II2, II3, Za1, Za2, Za3, P1, P2, P3, Z1, Z2, Z3, S1, S2, S3, O1, O2, O3;	
	
	printf("Unesite bodove za Tarika: ");
	printf("\nI parcijalni ispit: ");
	scanf("%f", &I1);
	
	if(I1>par1 || I1<0)
	{
	    printf("Neispravan broj bodova");
	    return 0;
	}
	
	printf("II parcijalni ispit: ");
	scanf("%f", &II1);
	
	if(II1>par2 || II1<0)
	{
	    printf("Neispravan broj bodova");
	    return 0;
	}
	
	printf("Prisustvo: ");
	scanf("%f", &P1);
	
	if(P1>p || P1<0)
	{
	    printf("Neispravan broj bodova");
	    return 0;
	}
	
	printf("Zadace: ");
	scanf("%f", &Za1);
	
	if(Za1>z || Za1<0)
	{
	    printf("Neispravan broj bodova");
	    return 0;
	}
	
	printf("Zavrsni ispit: ");
	scanf("%f", &Z1);
	
	if(Z1>u || Z1<0)
	{
	    printf("Neispravan broj bodova");
	    return 0;
	}
	
	
	printf("Unesite bodove za Bojana: ");
	printf("\nI parcijalni ispit: ");
	scanf("%f", &I2);
	
	if(I2>par1 || I2<0)
	{
	    printf("Neispravan broj bodova");
	    return 0;
	}
	
	printf("II parcijalni ispit: ");
	scanf("%f", &II2);
	
	if(II2>par2 || II2<0)
	{
	    printf("Neispravan broj bodova");
	    return 0;
	}
	
	printf("Prisustvo: ");
	scanf("%f", &P2);
	
	if(P2>p || P2<0)
	{
	    printf("Neispravan broj bodova");
	    return 0;
	}
	
	printf("Zadace: ");
	scanf("%f", &Za2);
	
	if(Za2>z || Za2<0)
	{
	    printf("Neispravan broj bodova");
	    return 0;
	}
	
	printf("Zavrsni ispit: ");
	scanf("%f", &Z2);
	
	if(Z2>u || Z2<0)
	{
	    printf("Neispravan broj bodova");
	    return 0;
	}
	
	
	printf("Unesite bodove za Mirzu: ");
	printf("\nI parcijalni ispit: ");
	scanf("%f", &I3);
	
	if(I3>par1 || I3<0)
	{
	    printf("Neispravan broj bodova");
	    return 0;
	}
	
	printf("II parcijalni ispit: ");
	scanf("%f", &II3);
	
	if(II3>par2 || II3<0)
	{
	    printf("Neispravan broj bodova");
	    return 0;
	}
	
	printf("Prisustvo: ");
	scanf("%f", &P3);
	
	if(P3>p || P3<0)
	{
	    printf("Neispravan broj bodova");
	    return 0;
	}
	
	printf("Zadace: ");
	scanf("%f", &Za3);
	
	if(Za3>z || Za3<0)
	{
	    printf("Neispravan broj bodova");
	    return 0;
	}
	
	printf("Zavrsni ispit: ");
	scanf("%f", &Z3);
	
	if(Z3>u || Z3<0)
	{
	    printf("Neispravan broj bodova");
	    return 0;
	}
	
	
	S1 = I1 + II1 + P1 + Za1 + Z1;
	S2 = I2 + II2 + P2 + Za2 + Z2;
	S3 = I3 + II3 + P3 + Za3 + Z3;
	
	if(S1<55) O1=0;
	else if(S1>=55 && S1<65) O1=6;
	else if(S1>=65 && S1<75) O1=7;
	else if(S1>=75 && S1<85) O1=8;
	else if(S1>=85 && S1<92) O1=9;
	else if(S1>=92 && S1<101) O1=10;
	
		if(S2<55) O2=0;
	else if(S2>=55 && S2<65) O2=6;
	else if(S2>=65 && S2<75) O2=7;
	else if(S2>=75 && S2<85) O2=8;
	else if(S2>=85 && S2<92) O2=9;
	else if(S2>=92 && S2<101) O2=10;
	
		if(S3<55) O3=0;
	else if(S3>=55 && S3<65) O3=6;
	else if(S3>=65 && S3<75) O3=7;
	else if(S3>=75 && S3<85) O3=8;
	else if(S3>=85 && S3<92) O3=9;
	else if(S3>=92 && S3<101) O3=10;
	
	if(S1>PROLAZ && S2>PROLAZ && S3>PROLAZ) printf("Sva tri studenta su polozila.");
	else if((S1>PROLAZ && S2>PROLAZ) || (S2>PROLAZ && S3>PROLAZ) || (S3>PROLAZ && S1>PROLAZ)) printf("Dva studenta su polozila.");
	else if(S1>PROLAZ || S2>PROLAZ || S3>PROLAZ) printf("Jedan student je polozio.");
	else printf("Nijedan student nije polozio.");
	
	printf("\n");
	
	if(S1>PROLAZ && S2>PROLAZ && S3>PROLAZ)
	{
	    if(O1==O2 && O2==O3) printf("Sva tri studenta imaju istu ocjenu.");
	    else if(O1==O2 || O2==O3 || O3==O1) printf("Dva od tri studenta imaju istu ocjenu.");
	    else printf("Svaki student ima razlicitu ocjenu.");
	}
	
	return 0;
}