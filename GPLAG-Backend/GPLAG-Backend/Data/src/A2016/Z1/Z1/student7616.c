#include <stdio.h>
int main() 
{
	double prvi_par1,drugi_par1,prisustvo1,zadace1,zavrsni_ispit1;
	double prvi_par2,drugi_par2,prisustvo2,zadace2,zavrsni_ispit2;
    double prvi_par3,drugi_par3,prisustvo3,zadace3,zavrsni_ispit3;
	double S1,S2,S3,ocj,ocj1,ocj2,s1,s2,s3;
	/*TARIK*/
	printf("Unesite bodove za Tarika:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf",&prvi_par1);
	if(prvi_par1<0 || prvi_par1>20)  { printf("Neispravan broj bodova"); return 0; }
	printf("II parcijalni ispit: ");
	scanf("%lf",&drugi_par1);
	if(drugi_par1<0 || drugi_par1>20)  {  printf("Neispravan broj bodova");  return 0; }
	printf("Prisustvo: ");
	scanf("%lf",&prisustvo1);
	if(prisustvo1<0 || prisustvo1>10)  {  printf("Neispravan broj bodova"); return 0; }
	printf("Zadace: ");
	scanf("%lf",&zadace1);
	if(zadace1<0 || zadace1>10)   {  printf("Neispravan broj bodova");  return 0; }  
	printf("Zavrsni ispit: ");
	scanf("%lf",&zavrsni_ispit1);
	if(zavrsni_ispit1<0 || zavrsni_ispit1>40)  {  printf("Neispravan broj bodova");  return 0; }
	/*BOJAN*/
	printf("Unesite bodove za Bojana:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf",&prvi_par2);
	if(prvi_par2<0 || prvi_par2>20)   { printf("Neispravan broj bodova"); return 0; }
	printf("II parcijalni ispit: ");
	scanf("%lf",&drugi_par2);
	if(drugi_par2<0 || drugi_par2>20)   {  printf("Neispravan broj bodova");  return 0; }
	printf("Prisustvo: ");
	scanf("%lf",&prisustvo2);
	if(prisustvo2<0 || prisustvo2>10)    {  printf("Neispravan broj bodova");  return 0; }
	printf("Zadace: ");
	scanf("%lf",&zadace2);
	if(zadace2<0 || zadace2>10)  { printf("Neispravan broj bodova");  return 0;  } 
	printf("Zavrsni ispit: ");
	scanf("%lf",&zavrsni_ispit2);
	if(zavrsni_ispit2<0 || zavrsni_ispit2>40)   { printf("Neispravan broj bodova"); return 0;  }
	//MIRZA//
	printf("Unesite bodove za Mirzu:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf",&prvi_par3);
	if(prvi_par3<0 || prvi_par3>20)   {  printf("Neispravan broj bodova");  return 0;  }
	printf("II parcijalni ispit: ");
	scanf("%lf",&drugi_par3);
	if(drugi_par3<0 || drugi_par3>20)  {  printf("Neispravan broj bodova");  return 0; }
	printf("Prisustvo: ");
	scanf("%lf",&prisustvo3);
	if(prisustvo3<0 || prisustvo3>10)   {  printf("Neispravan broj bodova");  return 0;  }
	printf("Zadace: ");
	scanf("%lf",&zadace3);
	if(zadace3<0 || zadace3>10)  { printf("Neispravan broj bodova");  return 0; }
	printf("Zavrsni ispit: ");
	scanf("%lf",&zavrsni_ispit3);
	if(zavrsni_ispit3<0 || zavrsni_ispit3>40)  { printf("Neispravan broj bodova"); return 0; }
	
		S1=prvi_par1+drugi_par1+prisustvo1+zadace1+zavrsni_ispit1;
		S2=prvi_par2+drugi_par2+prisustvo2+zadace2+zavrsni_ispit2;
		S3=prvi_par3+drugi_par3+prisustvo3+zadace3+zavrsni_ispit3;
		// Za Tarika//
		if(S1<55)
		ocj=5;
		else if(S1>=55 && S1<65)
		ocj=6;
		else if(S1>=65 && S1<75)
		ocj=7;
		else if(S1>=75 && S1<85)
		ocj=8;
		else if(S1>=85 && S1<92)
		ocj=9;
		else if(S1>=92 && S1<=100)
		ocj=10;
		// Za Bojana//
		if(S2<55)
		ocj1=5;
		else if(S2>=55 && S2<65)
		ocj1=6;
		else if(S2>=65 && S2<75)
		ocj1=7;
		else if(S2>=75 && S2<85)
		ocj1=8;
		else if(S2>=85 && S2<92)
		ocj1=9;
		else if(S2>=92 && S2<=100)
		ocj1=10;
		// Za Mirzu//
		if(S3<55)
		ocj2=5;
		else if(S3>=55 && S3<65)
		ocj2=6;
		else if(S3>=65 && S3<75)
		ocj2=7;
		else if(S3>=75 && S3<85)
		ocj2=8;
		else if(S3>=85 && S3<92)
		ocj2=9;
		else if(S3>=92 && S3<=100)
		ocj2=10;
		
	s1=ocj;
	s2=ocj1;
	s3=ocj2;
	if(s1==5 && s2==5 && s3==5) {
		printf("Nijedan student nije polozio.\n");
	}
	else if(s1==5 && s2==5 && s3>5 || s1==5 && s2>5 && s3==5 || s1>5 && s2==5 && s3==5) {
		printf("Jedan student je polozio.\n");
	}
	else if(s1>5 && s2>5 && s3==5 || s1>5 && s2==5 && s3>5 || s1==5 && s2>5 && s3>5) {
		printf("Dva studenta su polozila. \n");
	}
	else if(s1>5 && s2>5 && s3>5) {
		printf("Sva tri studenta su polozila.\n");
		if(s1==s2 && s1==s3) {
			printf("Sva tri studenta imaju istu ocjenu.\n");
		}
		else if(s1==s2 || s1==s3 || s2==s3) {
			printf("Dva od tri studenta imaju istu ocjenu.\n");
		}
		else if(s1!=s2 && s2!=s3 && s3!=s1) {
			printf("Svaki student ima razlicitu ocjenu.\n");
		}
	}
	return 0;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	