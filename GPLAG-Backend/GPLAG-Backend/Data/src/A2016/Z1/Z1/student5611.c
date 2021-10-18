#include <stdio.h>

int main() {
	float a1,a2,a3,b1,b2,b3,c1,c2,c3,d1,d2,d3,e1,e2,e3,x1,x2,x3,z1,z2,z3;
	
	printf("Unesite bodove za Tarika: ");
	printf("\nI parcijalni ispit: ");
	scanf("%f", &a1);
	if(a1<0 || a1>20){
		printf("Neispravan broj bodova");
		return 1;
	}
	printf("II parcijalni ispit: ");
	scanf("%f", &b1);
	if(b1<0 || b1>20){
		printf("Neispravan broj bodova");
		return 1;
	}
	printf("Prisustvo: ");
	scanf("%f", &c1);
	if(c1<0 || c1>10){
		printf("Neispravan broj bodova");
		return 1;
	}
	printf("Zadace: ");
	scanf("%f", &d1);
	if(d1<0 || d1>10){
		printf("Neispravan broj bodova");
		return 1;
	}
	printf("Zavrsni ispit: ");
	scanf("%f", &e1);
	if(e1<0 || e1>40){
		printf("Neispravan broj bodova");
		return 1;
	}
	printf("Unesite bodove za Bojana: ");
	printf("\nI parcijalni ispit: ");
	scanf("%f", &a2);
	if(a2<0 || a2>20){
		printf("Neispravan broj bodova");
		return 1;
	}
	printf("II parcijalni ispit: ");
	scanf("%f", &b2);
	if(b2<0 || b2>20){
		printf("Neispravan broj bodova");
		return 1;
	}
	printf("Prisustvo: ");
	scanf("%f", &c2);
	if(c2<0 || c2>10){
		printf("Neispravan broj bodova");
		return 1;
	}
	printf("Zadace: ");
	scanf("%f", &d2);
	if(d2<0 || d2>10){
		printf("Neispravan broj bodova");
		return 1;
	}
	printf("Zavrsni ispit: ");
	scanf("%f", &e2);
	if(e2<0 || e2>40){
		printf("Neispravan broj bodova");
		return 1;
	}
	printf("Unesite bodove za Mirzu: ");
	printf("\nI parcijalni ispit: ");
	scanf("%f", &a3);
	if(a3<0 || a3>20){
		printf("Neispravan broj bodova");
		return 1;
	}
	printf("II parcijalni ispit: ");
	scanf("%f", &b3);
	if(b3<0 || b3>20){
		printf("Neispravan broj bodova");
		return 1;
	}
	printf("Prisustvo: ");
	scanf("%f", &c3);
	if(c3<0 || c3>10){
		printf("Neispravan broj bodova");
		return 1;
	}
	printf("Zadace: ");
	scanf("%f", &d3);
	if(d3<0 || d3>10){
		printf("Neispravan broj bodova");
		return 1;
	}
	printf("Zavrsni ispit: ");
	scanf("%f", &e3);
	if(e3<0 || e3>40){
		printf("Neispravan broj bodova");
		return 1;
	}
x1=a1+b1+c1+d1+e1;
x2=a2+b2+c2+d2+e2;
x3=a3+b3+c3+d3+e3;

if(x1<=54){
	z1=5;
}
else if((x1==55 || x1>55) && x1<=64){
	z1=6;
}
else if((x1==65 || x1>65) && x1<=74){
	z1=7;
}
else if((x1==75 || x1>75) && x1<=84){
	z1=8;
}
else if((x1==85 || x1>85) && x1<=94){
	z1=9;
}
else{
	z1=10;
}
if(x2<=54){
	z2=5;
}
else if((x2==55 || x2>55) && x2<=64){
	z2=6;
}
else if((x2==65 || x2>65) && x2<=74){
	z2=7;
}
else if((x2==75 || x2>75) && x2<=84){
	z2=8;
}
else if((x2==85 || x2>85) && x2<=94){
	z2=9;
}
else{
	z2=10;
}
if(x3<=54){
	z3=5;
}
else if((x3==55 || x3>55) && x3<=64){
	z3=6;
}
else if((x3==65 || x3>65) && x3<=74){
	z3=7;
}
else if((x3==75 || x3>75) && x3<=84){
	z3=8;
}
else if((x3==85 || x3>85) && x3<=94){
	z3=9;
}
else{
	z3=10;
}
if(z1==5 && z2==5 && z3==5){
	printf("Nijedan student nije polozio.");
}
else if(z1==5 && z2!=5 && z3==5 || z1==5 && z2==5 && z3!=5 || z1!=5 && z2==5 && z3==5){
	printf("Jedan student je polozio.");
}
else if(z1!=5 && z2==5 && z3!=5 || z1==5 && z2!=5 && z3!=5 || z1!=5 && z2!=5 && z3==5){
	printf("Dva studenta su polozila.");
}
else if(z1>5 && z2>5 && z3>5){
	printf("Sva tri studenta su polozila.");
	
	if(z1==z2 && z1==z3 &&z2==z3){
		printf("\nSva tri studenta imaju istu ocjenu.");
	}
	else if(z1==z2 && z1!=z3 || z1==z3 && z1!=z2 || z2==z3 && z2!=z1 || z2==z1 && z2!=z3){
		printf("\nDva od tri studenta imaju istu ocjenu.");
	}
	else{
		printf("\nSvaki student ima razlicitu ocjenu.");
	}
}
	return 0;
}
