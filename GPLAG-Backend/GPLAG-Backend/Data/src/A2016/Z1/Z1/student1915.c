#include <stdio.h>

int main() {
	double pi1,pi2,pi3,pii1,pii2,pii3,p1,p2,p3,z1,z2,z3,u1,u2,u,s1,s2,s3;
	int o1,o2,o3;
printf("Unesite bodove za Tarika: \n");
	printf("I parcijalni ispit: ");
	scanf("%lf",&pi1);
	if((pi1<0)||(pi1>20)) {printf("Neispravan broj bodova");
	return 0;}
printf("II parcijalni ispit: ");
	scanf("%lf",&pii1);
	if((pii1<0)||(pii1>20)) {printf("Neispravan broj bodova");
	return 0;}
	
	printf("Prisustvo: ");
	scanf("%lf",&p1);
	if((p1<0)||(p1>10)) {printf("Neispravan broj bodova");
	return 0;}
	printf("Zadace: ");
	scanf("%lf",&z1);
	if((z1<0)||(z1>10)) {printf("Neispravan broj bodova");
	return 0;}
 printf("Zavrsni ispit: ");
	scanf("%lf",&u1);
	if((u1<0)||(u1>40)) {printf("Neispravan broj bodova");
	return 0;}
  	printf("Unesite bodove za Bojana: \n");
	printf("I parcijalni ispit: ");
	scanf("%lf",&pi2);
	if((pi2<0)||(pi2>20)) {printf("Neispravan broj bodova");
	return 0;}
	
	printf("II parcijalni ispit: ");
	scanf("%lf",&pii2);
	if((pii2<0)||(pii2>20)) {printf("Neispravan broj bodova");
	return 0;}
	printf("Prisustvo: ");
	scanf("%lf",&p2);
	if((p2<0)||(p2>10)) {printf("Neispravan broj bodova");
	return 0;}
	printf("Zadace: ");
	scanf("%lf",&z2);
	if((z2<0)||(z2>10)) {printf("Neispravan broj bodova");
	return 0;}
	printf("Zavrsni ispit: ");
	scanf("%lf",&u2);
	if((u2<0)||(u2>40)) {printf("Neispravan broj bodova");
	return 0;}
	printf("Unesite bodove za Mirzu: \n");
	printf("I parcijalni ispit: ");
	scanf("%lf",&pi3);	
	if((pi3<0)||(pi3>20)) {printf("Neispravan broj bodova");
	return 0;}
	printf("II parcijalni ispit: ");
	scanf("%lf",&pii3);
	if((pii3<0)||(pii3>20)) {printf("Neispravan broj bodova");
	return 0;}
	printf("Prisustvo: ");
	scanf("%lf",&p3);
	if((p3<0)||(p3>10)) {printf("Neispravan broj bodova");
	return 0;}
	
	printf("Zadace: ");
	scanf("%lf",&z3);
	if((z3<0)||(z3>10)) {printf("Neispravan broj bodova");
	return 0;}
	printf("Zavrsni ispit: ");
	scanf("%lf",&u);
    if((u<0) || (u>40)) {printf("Nesipravan broj bodova");
    	return 0;
    }
	
    s1=pi1+pii1+p1+z1+u1;
	s2=pi2+pii2+p2+z2+u2;
	s3=pi3+pii3+p3+z3+u;
	if ((s1>=0) && (s1<55)) o1=5;
	else if ((s1>=55) && (s1<65)) o1=6;
	else if ((s1>=65) && (s1<75)) o1=7;
	else if ((s1>=75) && (s1<85)) o1=8;
	else if ((s1>=85) && (s1<95)) o1=9;
	else if ((s1>=95) && (s1<=100)) o1=10;
	if ((s2>=0) && (s2<55.00)) o2=5;
	else if ((s2>=55) && (s2<65)) o2=6;
	else if ((s2>=65) && (s2<75)) o2=7;
	else if ((s2>=75) && (s2<85)) o2=8;
	else if ((s2>=85) && (s2<95)) o2=9;
	else if ((s2>=95) && (s2<=100)) o2=10;
	if ((s3>=0) && (s3<55.00)) o3=5;
	else if ((s3>=55) && (s3<65)) o3=6;
	else if ((s3>=65) && (s3<75)) o3=7;
	else if ((s3>=75) && (s3<85)) o3=8;
	else if ((s3>=85) && (s3<95)) o3=9;
	else if ((s3>=95) && (s3<=100)) o3=10;
	if ((o1==5)&&(o2==5)&&(o3==5)) printf("Nijedan student nije polozio.\n");
	if (((o1==5)&&(o2==5)&&(o3!=5))||((o1==5)&&(o3==5)&&(o2!=5))||((o3==5)&&(o2==5)&&(o1!=5))) printf("Jedan student je polozio.\n");
	if(((o1!=5)&&(o2==5)&&(o3!=5))||((o1==5)&&(o3!=5)&&(o2!=5))||((o3==5)&&(o2!=5)&&(o1!=5))) printf("Dva studenta su polozila.\n");
    if ((o1!=5)&&(o2!=5)&&(o3!=5)){ printf("Sva tri studenta su polozila.\n");
	if((o2==o3)&&(o1==o3)&&(o1==o2)) printf("Sva tri studenta imaju istu ocjenu.\n");
	else if(((o1==o2)&&(o1!=o3)&&(o2!=o3))||((o1==o3)&&(o1!=o2)&&(o2!=o3))||((o3==o2)&&(o1!=o3)&&(o2!=o1))) printf("Dva od tri studenta imaju istu ocjenu.\n");
	else if((o1!=o2)&&(o2!=o3)&&(o1!=o3)) printf("Svaki student ima razlicitu ocjenu.\n");
}	return 0;
}
