#include <stdio.h>

int main() {
	float Ip1,IIp1,pri1,z1,zi1,Ip2,IIp2,pri2,z2,zi2,Ip3,IIp3,pri3,z3,zi3,s1,s2,s3;
	int ocjena1,ocjena2,ocjena3;
	
	printf("Unesite bodove za Tarika:\n");
	printf("I parcijalni ispit: ");
	scanf("%f",&Ip1);
	if(Ip1<0 || Ip1>20){
	printf("Neispravan broj bodova");
	return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f",&IIp1);
	if(IIp1<0 || IIp1>20){
	printf("Neispravan broj bodova");
	return 0;
	}
	printf("Prisustvo: ");
	scanf("%f",&pri1);
	if(pri1<0 || pri1>10){
	printf("Neispravan broj bodova");
	return 0;
	}
	printf("Zadace: ");
	scanf("%f",&z1);
	if(z1<0 || z1>10){
	printf("Neispravan broj bodova");
	return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f",&zi1);
	if(zi1<0 || zi1>40){
	printf("Neispravan broj bodova");
	return 0;
	}
		printf("Unesite bodove za Bojana:\n");
	printf("I parcijalni ispit: ");
	scanf("%f",&Ip2);
	if(Ip2<0 || Ip2>20){
	printf("Neispravan broj bodova");
	return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f",&IIp2);
	if(IIp2<0 || IIp2>20){
	printf("Neispravan broj bodova");
	return 0;
	}
	printf("Prisustvo: ");
	scanf("%f",&pri2);
	if(pri2<0 || pri2>10){
	printf("Neispravan broj bodova");
	return 0;
	}
	printf("Zadace: ");
	scanf("%f",&z2);
	if(z2<0 || z2>10){
	printf("Neispravan broj bodova");
	return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f",&zi2);
	if(zi2<0 || zi2>40){
	printf("Neispravan broj bodova");
	return 0;
	}
		printf("Unesite bodove za Mirzu:\n");
	printf("I parcijalni ispit: ");
	scanf("%f",&Ip3);
	if(Ip3<0 || Ip3>20){
	printf("Neispravan broj bodova");
	return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f",&IIp3);
	if(IIp3<0 || IIp3>20){
	printf("Neispravan broj bodova");
	return 0;
	}
	printf("Prisustvo: ");
	scanf("%f",&pri3);
	if(pri3<0 || pri3>10){
	printf("Neispravan broj bodova");
	return 0;
	}
	printf("Zadace: ");
	scanf("%f",&z3);
	if(z3<0 || z3>10){
	printf("Neispravan broj bodova");
	return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f",&zi3);
	if(zi3<0 || zi3>40){
	printf("Neispravan broj bodova");
	return 0;
	}
	
	s1=((Ip1+IIp1+pri1+z1+zi1)*100+0.05)/100;
	s2=((Ip2+IIp2+pri2+z2+zi2)*100+0.05)/100;
	s3=((Ip3+IIp3+pri3+z3+zi3)*100+0.05)/100;
	
	if(s1>=55 && s1<65)
	ocjena1=6;
	if(s1>=65 && s1<75)
	ocjena1=7;
	if(s1>=75 && s1<85)
	ocjena1=8;
	if(s1>=85 && s1<92)
	ocjena1=9;
	if(s1>=92 && s1<=100)
	ocjena1=10;
	
	if(s2>=55 && s2<65)
	ocjena2=6;
	if(s2>=65 && s2<75)
	ocjena2=7;
	if(s2>=75 && s2<85)
	ocjena2=8;
	if(s2>=85 && s2<92)
	ocjena2=9;
	if(s2>=92 && s2<=100)
	ocjena2=10;
	
	if(s3>=55 && s3<65)
	ocjena1=6;
	if(s3>=65 && s3<75)
	ocjena1=7;
	if(s3>=75 && s3<85)
	ocjena1=8;
	if(s3>=85 && s3<92)
	ocjena1=9;
	if(s3>=92 && s3<=100)
	ocjena1=10;
	
	if(s1<55 && s2<55 && s3<55)
	printf("Nijedan student nije polozio.\n");
	else if((s1>=55 && s2<55 && s3<55)||(s1<55 && s2>=55 && s3<55)||(s1<55 && s2<55 && s3>=55))
	printf("Jedan student je polozio.\n");
	else if((s1>=55 && s2>=55 && s3<55)||(s1>=55 && s2<55 && s3>=55)||(s1<55 && s2>=55 && s3>=55))
	printf("Dva studenta su polozila.\n");
	else if(s1>=55 && s2>=55 && s3>=55)
	printf("Sva tri studenta su polozila.\n");
	
	if (s1>=55 && s2>=55 && s3>=55)
		 {
		 	if (((ocjena1==ocjena2) || (ocjena2==ocjena3)) || ((ocjena1==ocjena3) || (ocjena2==ocjena3)))
		 	printf("Sva tri studenta imaju istu ocjenu.");
		 	else 	if (((ocjena1==ocjena2) && (ocjena2==ocjena3)) && ((ocjena1==ocjena3) || (ocjena2==ocjena3)))
		    printf("Dva od tri studenta imaju istu ocjenu.");
		    else if((ocjena1!=ocjena2)||(ocjena1!=ocjena3)||(ocjena2!=ocjena3))
		    printf("Svaki student ima razlicitu ocjenu.");
		 	}
	
			return 0;
}
