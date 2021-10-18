#include<stdio.h>
#include<math.h>
#define E 0.00001
int main()
{
	float a1,a2,a3,b1,b2,b3,p1,p2,p3,z1,z2,z3,u1,u2,u3,s1,s2,s3;
	int br=0;
	printf("Unesite bodove za Tarika:\n");
	printf("I parcijalni ispit: ");
	scanf("%f",&a1);
	if(a1<0 || a1>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f",&b1);
	if(b1<0 || b1>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%f",&p1);
	if(p1<0 || p1>10){
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
	scanf("%f",&u1);
	if(u1<0 || u1>40){
		printf("Neispravan broj bodova");
		return 0;
	}
	
	printf("Unesite bodove za Bojana:\n");
	printf("I parcijalni ispit: ");
	scanf("%f",&a2);
	if(a2<0 || a2>20){
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
	scanf("%f",&p2);
	if(p2<0 || p2>10){
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
	scanf("%f",&u2);
	if(u2<0 || u2>40){
		printf("Neispravan broj bodova");
		return 0;
	}
	
	
	printf("Unesite bodove za Mirzu:\n");
	printf("I parcijalni ispit: ");
	scanf("%f",&a3);
	if(a3<0 || a3>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f",&b3);
	if(b3<0 || b3>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%f",&p3);
	if(p3<0 || p3>10){
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
	scanf("%f",&u3);
	if(u3<0 || u3>40){
		printf("Neispravan broj bodova");
		return 0;
	}
	
	
	
	s1=(a1+b1+p1+z1+u1);
	s2=(a2+b2+p2+z2+u2);
	s3=(a3+b3+p3+z3+u3);
	
	
	
	if(fabs(s1-55)<E || s1>55) br++;
	if(fabs(s2-55)<E || s2>55) br++;
	if(fabs(s3-55)<E || s3>55) br++;
	
	if(br==0) printf("Nijedan student nije polozio.");
	if(br==1) printf("Jedan student je polozio.");
	if(br==2) printf("Dva studenta su polozila.");
	if(br==3) 
	  {
	  	printf("Sva tri studenta su polozila.\n");
	      if((((s1>55 || fabs(s1-55)<E) && s2<65) && ((s2>55 || fabs(s2-55)<E) && s2<65) && ((s3>55 || fabs(s3-55)<E) && s3<65))||(((s1>65 || fabs(s1-65)<E) && s1<75)&&((s2>65 || fabs(s2-65)<E) && s2<75)&&((s3>65 || fabs(s3-65)<E) && s3<75))||(((s1>75 || fabs(s1-75)<E) && s1<85)&&(s2>=75 && s2<85) && ((s3>75 || fabs(s3-75)<E) && s3<85))||(((s1>85 || fabs(s1-85)<E) && s1<92)&&((s2>85 || fabs(s2-85)<E ) && s2<92)&& ((s3>85 ||fabs(s3-85)<E) && s3<92))||(((s1>92 || fabs(s3-92)<E) && s1<=100)&&((s2>92 || fabs(s2-92)<E) && s2<=100)&&((s3>92 || fabs(s3-92)<E) && s3<=100)))
	      printf("Sva tri studenta imaju istu ocjenu.");
	      
	      else if(((s1>55 || fabs(s1-55)<E) && s2<65 && (s2>55 || fabs(s2-55)<E) && s2<65 && (s3>65 || fabs(s3-65)<E) && (s3<100 || fabs(s3-100)<E))||((s1>65 || fabs(s1-65)<E) && s1<75 && (s2>65 || fabs(s1-65)<E) && s2<75 && (s3>75 || fabs(s3-75)<E) && (s3<100 || fabs(s3-100)<E))||((s1>75 || fabs(s1-75)<E) && s1<85 && (s2>75 || fabs(s2-75)<E) && s2<85 && (s3>85 || fabs(s3-85)<E) && (s3<100 || fabs(s3-100)<E))||((s1>85 || fabs(s1-85)<E) && s1<92 && (s2>85 || fabs(s2-85)<E) && s2<92 && (s3>92 || fabs(s3-92)<E) && (s3<100 || fabs(s3-100)<E))||
	      ((s1>55 ||fabs(s1-55)<E) && s1<65 && (s3>55 || fabs(s3-55)<E) && s3<65 && (s2>65 || fabs(s2-65)<E) && (s2<100 || fabs(s2-100)<E))||((s1>65 || fabs(s1-65)<E) && s1<75 && (s3>65 || fabs(s3-65)<E) && s3<75 && (s2>75 || fabs(s2-75)<E) && (s2<100 || fabs(s2-100)<E))||((s1>75 || fabs(s1-75)<E) && s1<85 && (s3>75 || fabs(s3-75)<E) && s3<85 && (s2>85 || fabs(s2-85)<E) && (s2<100 || fabs(s2-100)<E))||((s1>85 || fabs(s1-85)<E) && s1<92 && (s3>85 || fabs(s3-85)<E) && s3<92 && (s2>92 || fabs(s2-92)<E) && (s2<100 || fabs(s2-100)<E))||((s2>55 || fabs(s2-55)<E) && s2<65 && (s3>55 || fabs(s3-55)<E) && s3<65 && (s1>65 || fabs(s1-65)<E) && (s1<100 || fabs(s1-100)<E ))||
	      ((s2>55 && s2<65 && (s3>55 || fabs(s3-55)<E) && s3<65 && (s1>65 || fabs(s1-65)<E) && (s1<100 || fabs(s1-100)<E))||((s2>55 || fabs(s2-55)<E) && s2<65 && (s3>55 || fabs(s3-55)<E) && s3<65 && (s1>65 || fabs(s1-65)<E) && (s1<100 || fabs(s1-100)<E))||((s2>55 || fabs(s2-55)<E) && s2<65 && (s3>55 || fabs(s3-55)<E) && s3<65 && (s1>65 || fabs(s1-65)<E) && (s1<100 || fabs(s1-100)<E))||((s2>55 || fabs(s2-55)<E) && s2<65 && (s3>55 || fabs(s3-55)<E) && s3<65 && (s1>65 || fabs(s1-65)<E) && (s1<100 || fabs(s1-100)<E))||((s2>55 || fabs(s2-55)<E) && s2<65 && (s3>55 || fabs(s3-55)<E) && s3<65 && (s1>65 || fabs(s1-65)<E) && (s1<100 || fabs(s1-100)<E))||((s2>55 || fabs(s2-55)<E) && s2<65 && (s3>55 || fabs(s3-55)<E) && s3<65 && (s1>65 || fabs(s1-65)<E) && (s1<100 || fabs(s1-100)<E))||
          ((s2>65 || fabs(s2-65)<E) && s2<75 && (s3>65 || fabs(s3-65)<E) && s3<75 && (s1>75 || fabs(s1-75)<E) && (s1<100 || fabs(s1-100)<E))||((s2>75 || fabs(s2-75)<E) && s2<85 && (s3>75 || fabs(s3-75)<E) && s3<85 && (s1>85 || fabs(s1-85)<E) && (s1<100 || fabs(s1-100)<E))||((s2>85 || fabs(s2-85)<E) && s2<92 && (s3>85 || fabs(s3-85)<E) && s3<92 && (s1>92 || fabs(s1-92)<E) && (s1<100 || fabs(s1-100)<E))))
	      printf("Dva od tri studenta imaju istu ocjenu.");
	      
	      else printf("Svaki student ima razlicitu ocjenu.");
	  }
	
	

	return 0;
}

