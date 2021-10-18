#include <stdio.h>
#include <stdlib.h>
int main() {
	float x,y,z,x1,x2,x3,x4,x5,y1,y2,y3,y4,y5,z1,z2,z3,z4,z5;
	printf("Unesite bodove za Tarika:\n");
	printf("I parcijalni ispit: ");
	scanf("%f", &x1);
	if (x1<0 || x1>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f", &x2);
	if (x2<0 || x2>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%f", &x3);
	if (x3<0 || x3>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%f", &x4);
	if (x4<0 || x4>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f", &x5);
	if (x5<0 || x5>40) {
		printf("Neispravan broj bodova");
		return 0;
	} /* za prvog studenta*/
	printf("Unesite bodove za Bojana:\n");
	printf("I parcijalni ispit: ");
	scanf("%f", &y1);
	if (y1<0 || y1>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f", &y2);
	if (y2<0 || y2>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%f", &y3);
	if (y3<0 || y3>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%f", &y4);
	if (y4<0 || y4>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f", &y5);
	if (y5<0 || y5>40) {
		printf("Neispravan broj bodova");
		return 0;
	} /* za drugog studenta*/
	printf("Unesite bodove za Mirzu:\n");
	printf("I parcijalni ispit: ");
	scanf("%f", &z1);
	if (z1<0 || z1>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f", &z2);
	if (z2<0 || z2>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%f", &z3);
	if (z3<0 || z3>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%f", &z4);
	if (z4<0 || z4>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f", &z5);
	if (z5<0 || z5>40) {
		printf("Neispravan broj bodova");
		return 0;
	} /* za treceg studenta*/
	system("clear");
x=x1 + x2 + x3 + x4 + x5;
y=y1 + y2 + y3 + y4 + y5;
z=z1 + z2 + z3 + z4 + z5;
if(x<=54) {
	x=5;
}
if(x>54 && x<65) {
	x=6;
}
if(x>=65 && x<75) {
	x=7;
}
if(x>=75 && x<85) {
	x=8;
}
if(x>=85 && x<92) {
	x=9;
}
if(x>=92 && x<=100) {
	x=10;
}
if(y<55) {
	y=5;
}
if(y>=55 && y<65) {
	y=6;
}
if(y>=65 && y<75) {
	y=7;
}
if(y>=75 && y<85) {
	y=8;
}
if(y>=85 && y<92) {
	y=9;
}
if(y>=92 && y<=100) {
	y=10;
}
if(z<55) {
	z=5;
}
if(z>=55 && z<65) {
	z=6;
}
if(z>=65 && z<75) {
	z=7;
}
if(z>=75 && z<85) {
	z=8;
}
if(z>=85 && z<92) {
	z=9;
}
if(z>=92 && z<=100) {
	z=10;
}
if(x>5 && y>5 && z>5){
		printf("Sva tri studenta su polozila. \n");
}
if(x<=5 && y<=5 && z<=5){
		printf("Nijedan student nije polozio.\n");
		return 0;
}
	if((x>5 && y<=5 && z<=5) || (x<=5 && y>5 && z<=5) || (x<=5 && y<=5 && z>5)){
		printf("Jedan student je polozio.\n");
		return 0;
}
if((x>5 && y>5 && z<= 5) || (x<=5 && y>5 && z>5)|| (x>5 && y<=5 && z>5))
	{
	printf("Dva studenta su polozila.\n");
	return 0;
}
if(x == y && y == z ){
		printf("Sva tri studenta imaju istu ocjenu.\n");
}
if(x != y && y != z ){
		printf("Svaki student ima razlicitu ocjenu.\n");
}
	if((x == y && y != z ) || (x != y && y == z ) || (x == z && y != z ))
	{
		printf("Dva od tri studenta imaju istu ocjenu.\n");
	}
return 0;
}
