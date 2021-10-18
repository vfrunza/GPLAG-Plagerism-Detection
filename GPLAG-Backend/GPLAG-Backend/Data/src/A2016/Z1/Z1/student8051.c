#include <stdio.h>
#include<math.h>
#define epsilon 0.0001
int main() {
	double a,b,c,d,e,s1=0,s2=0,s3=0;
	int o1,o2,o3;
	printf("Unesite bodove za Tarika:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf",&a);
	if(a>20||a<0)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &b);
	if(b>20||b<0)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	
	printf("Prisustvo: ");
	scanf("%lf",&c);
	if(c>10||c<0)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	
	printf("Zadace: ");
	scanf("%lf",&d);
	if(d>10||d<0)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	
	printf("Zavrsni ispit: ");
	scanf("%lf",&e);
	if(e>40||e<0)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	
	
	s1+=a;
	s1+=b;
	s1+=c;
	s1+=d;
	s1+=e;
	
	printf("Unesite bodove za Bojana:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf",&a);
	if(a>20||a<0)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &b);
	if(b>20||b<0)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	
	printf("Prisustvo: ");
	scanf("%lf",&c);
	if(c>10||c<0)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	
	printf("Zadace: ");
	scanf("%lf",&d);
	if(d>10||d<0)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	
	printf("Zavrsni ispit: ");
	scanf("%lf",&e);
	if(e>40||e<0)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	
	
	
	s2=a+b+c+d+e;
	
	printf("Unesite bodove za Mirzu:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf",&a);
	if(a>20||a<0)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &b);
	if(b>20||b<0)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	
	printf("Prisustvo: ");
	scanf("%lf",&c);
	if(c>10||c<0)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	
	printf("Zadace: ");
	scanf("%lf",&d);
	if(d>10||d<0)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	
	printf("Zavrsni ispit: ");
	scanf("%lf",&e);
	if(e>40||e<0)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	
	
	
	
	
	
	
	s3=a+b+c+d+e;
	
	if(55-s1>epsilon)
		o1=0;
	else if(s1>=55&&s1<65)
		o1=6;
	else if(s1>=65&&s1<75)
		o1=7;
	else if(s1>=75&&s1<85)
		o1=8;
	else if(s1>=85&&s1<92)
		o1=9;
	else if(s1>=92&&s1<=100)
		o1=10;
		
		if(55-s2>epsilon)
		o2=0;
	else if(s2>=55&&s2<65)
		o2=6;
	else if(s2>=65&&s2<75)
		o2=7;
	else if(s2>=75&&s2<85)
		o2=8;
	else if(s2>=85&&s2<92)
		o2=9;
	else if(s2>=92&&s2<=100)
		o2=10;
	
	if(55-s3>epsilon)
		o3=0;
	else if(s3>=55&&s3<65)
		o3=6;
	else if(s3>=65&&s3<75)
		o3=7;
	else if(s3>=75&&s3<85)
		o3=8;
	else if(s3>=85&&s3<92)
		o3=9;
	else if(s3>=92&&s3<=100)
		o3=10;
	int p=0;
	if(o1==0)
		p++;
	if(o2==0)
		p++;
	if(o3==0)
		p++;
	if(p==0)
		printf("Sva tri studenta su polozila.\n");
	else if(p==1)
		printf("Dva studenta su polozila.\n");
	else if(p==2)
		printf("Jedan student je polozio.\n");
	else 
		printf("Nijedan student nije polozio.\n");
		
	if(p==0)
	{
	if(o1==o2&&o1==o3)
		printf("Sva tri studenta imaju istu ocjenu.");
	else if(o1==o2||o2==o3)
		printf("Dva od tri studenta imaju istu ocjenu.");
	else
		printf("Svaki student ima razlicitu ocjenu.");
	}
	
	
	
	return 0;
}