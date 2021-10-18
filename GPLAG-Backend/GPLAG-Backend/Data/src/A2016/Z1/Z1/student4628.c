#include <stdio.h>

int main() {
double a1, b1, c1, d1, e1, a2, b2, c2, d2, e2, a3, b3, c3, d3, e3, s1, s2, s3, oc1, oc2, oc3;

printf("Unesite bodove za Tarika:\n");
printf("I parcijalni ispit: ");
scanf("%lf", &a1);
if(a1<0||a1>20){
	printf("Neispravan broj bodova");
	return 0;
}
printf("II parcijalni ispit: ");
scanf("%lf", &b1);
if(b1<0||b1>20){
	printf("Neispravan broj bodova");
	return 0;
}
printf("Prisustvo: ");
scanf("%lf", &c1);
if(c1<0||c1>10){
	printf("Neispravan broj bodova");
	return 0;
}
printf("Zadace: ");
scanf("%lf", &d1);
if(d1<0||d1>10){
	printf("Neispravan broj bodova");
	return 0;
}
printf("Zavrsni ispit: ");
scanf("%lf", &e1);
if(e1<0||e1>40){
	printf("Neispravan broj bodova");
	return 0;
}

printf("Unesite bodove za Bojana:\n");
printf("I parcijalni ispit: ");
scanf("%lf", &a2);
if(a2<0||a2>20){
	printf("Neispravan broj bodova");
	return 0;
}
printf("II parcijalni ispit: ");
scanf("%lf", &b2);
if(b2<0||b2>20){
	printf("Neispravan broj bodova");
	return 0;
}
printf("Prisustvo: ");
scanf("%lf", &c2);
if(c2<0||c2>10){
	printf("Neispravan broj brodova");
	return 0;
}
printf("Zadace: ");
scanf("%lf", &d2);
if(d2<0||d2>10){
	printf("Neispravan broj bodova");
	return 0;
}
printf("Zavrsni ispit: ");
scanf("%lf", &e2);
if(e2<0||e2>40){
	printf("Neispravan broj bodova");
	return 0;
}

printf("Unesite bodove za Mirzu:\n");
printf("I parcijalni ispit: ");
scanf("%lf", &a3);
if(a3<0||a3>20){
	printf("Neispravan broj bodova");
	return 0;
}
printf("II parcijalni ispit: ");
scanf("%lf", &b3);
if(b3<0||b3>20){
	printf("Neispravan broj bodova");
	return 0;
}
printf("Prisustvo: ");
scanf("%lf", &c3);
if(c3<0||c3>10){
	printf("Neispravan broj bodova");
	return 0;
}
printf("Zadace: ");
scanf("%lf", &d3);
if(d3<0||d3>10){
	printf("Neispravan broj bodova");
	return 0;
}
printf("Zavrsni ispit: ");
scanf("%lf", &e3);
if(e3<0||e3>40){
	printf("Neispravan broj bodova");
	return 0;
}

s1=a1+b1+c1+d1+e1;
s2=a2+b2+c2+d2+e2;
s3=a3+b3+c3+d3+e3;

if(s1<55)
oc1=5;
else if(s1>=55 && s1<65)
oc1=6;
else if(s1>=65 && s1<75)
oc1=7;
else if(s1>=75 && s1<85)
oc1=8;
else if(s1>=85 && s1<92)
oc1=9;
else if(s1>=92 && s1<=100)
oc1=10;

if(s2<55)
oc2=5;
if(s2>=55 && s2<65)
oc2=6;
else if(s2>=65 && s2<75)
oc2=7;
else if(s2>=75 && s2<85)
oc2=8;
else if(s2>=85 && s2<92)
oc2=9;
else if(s2>=92 && s2>=100)
oc2=10;

if(s3<55)
oc3=5;
else if(s3>=55 && s3<65)
oc3=6;
else if(s3>=65 && s3<75)
oc3=7;
else if(s3>=75 && s3<85)
oc3=8;
else if(s3>=85 && s3<92)
oc3=9;
else if(s3>=92 && s3<=100)
oc3=10;


if(s1>=55 && s2>=55 && s3>=55){
	printf("Sva tri studenta su polozila.");
	if((oc1==oc2) && (oc2==oc3))
	{
		printf("\nSva tri studenta imaju istu ocjenu.");
	}else if((oc1==oc2) || (oc2==oc3) && (oc1==oc3)){
		printf("\nDva od tri studenta imaju istu ocjenu.");
	}else {
		printf("\nSvaki student ima razlicitu ocjenu.");
	}

} else if((s1>=55 && s2<55 && s3<55) || (s1<55 && s2>=55 && s3<55) || (s1<55 && s2<55 && s3>=55)){
	printf("Jedan student je polozio.");
} else if ((s1>=55 && s2>=55 && s3<55) || (s1<55 && s2>=55 && s3>=55) || (s1>=55 && s2<55 && s3>=55)){
	printf("Dva studenta su polozila.");
}else{
	printf("Nijedan student nije polozio.");

}

return 0;

}