#include <stdio.h>

int main() {
	float t1,t2,t3,t4,t5,s1;
	float b1,b2,b3,b4,b5,s2;
	float m1,m2,m3,m4,m5,s3;
	int a=0,b=0,c=0;
	
	printf("Unesite bodove za Tarika:\n");
	printf("I parcijalni ispit: ");
	scanf("%f",&t1);
	if(t1<0||t1>20){
		printf("Neispravan broj bodova.");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f",&t2);
	if(t2<0 || t2>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%f",&t3);
    if(t3<0 || t3>10){
    	printf("Neispravan broj bodova");
    	return 0;
    }
	printf("Zadace: ");
	scanf("%f",&t4);
	if(t4<0 || t4>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f",&t5);
	if(t5<0 || t5>40){
		printf("Neispravan broj bodova");
		return 0;
	}
	
	printf("Unesite bodove za Bojana: \n");
	printf("I parcijalni ispit: ");
	scanf("%f",&b1);
	if(b1<0 || b1>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f",&b2);
	if(b2<0 || b2>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%f",&b3);
	if(b3<0 || b3>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%f",&b4);
	if(b4<0 || b4>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f",&b5);
	if(b5<0 || b5>40){
		printf("Neispravan broj bodova");
		return 0;
	}
	
	printf("Unesite bodove za Mirzu: \n");
	printf("I parcijalni ispit: ");
	scanf("%f",&m1);
	if(m1<0 || m1>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f",&m2);
	if(m2<0 || m2>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%f",&m3);
	if(m3<0 || m3>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%f",&m4);
	if(m4<0 || m4>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f",&m5);
	if(m5<0 || m5>40){
		printf("Neispravan broj bodova");
		return 0;
	}
	
	s1=t1+t2+t3+t4+t5;
	s2=b1+b2+b3+b4+b5;
	s3=m1+m2+m3+m4+m5;
	
	s1= (s1*100 + 0.05)/100;
	
	s2= (s2*100 + 0.05)/100;
	
	s3= (s3*100 + 0.05)/100;
	
 if(s1>=55 && s1<65) a=6;
	else if(s1>=65 && s1<75)a=7;
	else if(s1>=75 && s1<85)a=8;
	else if(s1>=85 && s1<92)a=9;
	else if(s1>=92 && s1<=100) a=10;
   if(s2>=55 && s2<64) b=6;
	 else if(s2>=65 && s2<75)b=7;
	 else if(s2>=75 && s2<85)b=8;
	 else if(s2>=85 && s2<92)b=9;
	 else if(s2>=92 && s2<=100)b=10;
   if(s3>=55 && s3<65) c=6;
	else if(s3>=65 && s3<75)c=7;
     else if(s3>=75 && s3<85)c=8;
	else if(s3>=85 && s3<92)c=9;
	else if(s3>=92 && s3<=100)c=10;
 	
   if(s1<55 && s2<55 && s3<55)
		printf("Nijedan student nije polozio.\n");
	
     else  if(s1>=55 && s2<55 && s3<55)
		printf("Jedan student je polozio.\n");
		else if((s2>=55)&&(s1<55 && s3<55))
		printf("Jedan student je polozio.\n");
		else if((s3>=55)&& (s1<55 && s2<55))
		printf("Jedan student je polozio.\n");
		
	else  if((s1>=55 && s2>=55)&&(s3<55))
		printf("Dva studenta su polozila.\n");
		else if((s1>=55 && s3>=55)&& (s2<55))
		printf("Dva studenta su polozila.\n");
		else if((s2>=55 && s3>=55)&& (s1<55))
		printf("Dva studenta su polozila.\n");
	
	else if(s1>=55 && s2>=55 && s3>=55)
		printf("Sva tri studenta su polozila.\n");

if(s1>=55 && s2>=55 && s3>=55){	
 
     if(a==b && a==c )
	printf("Sva tri studenta imaju istu ocjenu.");
	
	else if(a==b || a==c || b==c)
	printf("Dva od tri studenta imaju istu ocjenu.");
	
	else if(a!=b && a!=c && b!=c)
	printf("Svaki student ima razlicitu ocjenu.");
}


	 return 0;
}
