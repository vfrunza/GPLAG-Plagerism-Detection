#include <stdio.h>

int main() {
	float t1,t2,t3,t4,t5,b1,b2,b3,b4,b5,m1,m2,m3,m4,m5,Uk1,Uk2,Uk3;
	printf("Unesite bodove za Tarika:\n");
	printf("I parcijalni ispit: ");
	scanf("%f", &t1);
	if (t1<0 || t1>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f", &t2);
	if (t2<0 || t2>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%f", &t3);
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
	scanf("%f", &t5);
		if(t5<0 || t5>40){
		printf("Neispravan broj bodova");
		return 0;
		}
	
	
	printf("Unesite bodove za Bojana:\n");
	printf("I parcijalni ispit: ");
	scanf("%f", &b1);
		if(b1<0 || b1>20){
			printf("Neispravan broj bodova");
			return 0;
		}
	printf("II parcijalni ispit: ");
	scanf("%f", &b2);
		if(b2<0 || b2>20){
			printf("Neispravan broj bodova");
			return 0;
		}
	printf("Prisustvo: ");
	scanf("%f", &b3);
		if(b3<0 || b3>10){
			printf("Neispravan broj bodova");
			return 0;
		}
	printf("Zadace: ");
	scanf("%f", &b4);
		if(b4<0 || b4>10){
			printf("Neispravan broj bodova");
			return 0;
		}
	printf("Zavrsni ispit: ");
	scanf("%f", &b5);
		if(b5<0 || b5>40){
			printf("Neispravan broj bodova");
		}
	
	
	printf("Unesite bodove za Mirzu:\n");
	printf("I parcijalni ispit: ");
	scanf("%f", &m1);
		if(m1<0 || m1>20){
			printf("Neispravan broj bodova");
			return 0;
		}
	printf("II parcijalni ispit: ");
	scanf("%f", &m2);
		if(m2<0 || m2>20){
			printf("Neispravan broj bodova");
			return 0;
		}
	printf("Prisustvo: ");
	scanf("%f", &m3);
		if(m3<0 || m3>10){
			printf("Neispravan broj bodova");
			return 0;
			}
	printf("Zadace: ");
	scanf("%f", &m4);
		if(m4<0 || m4>10){
			printf("Neispravan broj bodova");
			return 0;
			}
	printf("Zavrsni ispit: ");
	scanf("%f", &m5);
		if(m5<0 || m5>40){
			printf("Neispravan broj bodova");
			return 0;
		}

	Uk1=(double)t1+t2+t3+t4+t5;
	Uk2=(double)b1+b2+b3+b4+b5;
	Uk3=(double)m1+m2+m3+m4+m5;
	
	
	if (Uk1<55 && Uk2<55 && Uk3<55)
		printf("Nijedan student nije polozio.\n");
	else if (Uk1>54 && Uk2<55 && Uk3<55 )
		printf ("Jedan student je polozio.\n");
	else if (Uk1<55 && Uk2>54 && Uk3<55)
		printf("Jedan student je polozio.\n");
	else if (Uk1<55 && Uk2<55 && Uk3>54)
		printf("Jedan student je polozio.\n");
	else if (Uk1>54 && Uk2>54 && Uk3<55)
		printf("Dva studenta su polozila.\n");
	else if (Uk1>54 && Uk2<55 && Uk3>54)
		printf("Dva studenta su polozila.\n");
	else if (Uk1<55 && Uk2>54 && Uk3>54)
		printf("Dva studenta su polozila.\n");
	else if (Uk1>54 && Uk2>54 && Uk3>54)
		printf("Sva tri studenta su polozila.\n");
		
	
	if(Uk1>54 && Uk2>54 && Uk3>54){
		if(((Uk1>54 && Uk1<65) && (Uk2>54 && Uk2<65) && (Uk3>54 && Uk3<65)) || ((Uk1>64 && Uk1<75) && (Uk2>64 && Uk2<75) && (Uk3>64 && Uk3<75)) || ((Uk1>74 && Uk1<85) && (Uk2>74 && Uk2<85) && (Uk3>74 && Uk3<85)) || ((Uk1>84 && Uk1<92) && (Uk2>84 && Uk2<92) && (Uk3>84 && Uk3<92)) || ((Uk1>91 && Uk1<101) && (Uk2>91 && Uk2<101) && (Uk3>91 && Uk3<101))) 
			printf("Sva tri studenta imaju istu ocjenu.\n");
		else if(((Uk1>54 && Uk1<65) && (Uk2>54 && Uk2<65)) || ((Uk1>54 && Uk1<65) && (Uk3>54 && Uk3<65)) || ((Uk2>54 && Uk2<65) && (Uk3>54 && Uk3<65))  || ((Uk1>64 && Uk1<75) && (Uk2>64 && Uk2<75)) ||((Uk1>64 && Uk1<75) && (Uk3>64 && Uk3<75)) || ((Uk2>64 && Uk2<75) && (Uk3>64 && Uk3<75)) || ((Uk1>74 && Uk1<85) && (Uk2>74 && Uk2<85)) || ((Uk1>74 && Uk1<85) && (Uk3>74 && Uk3<85)) || ((Uk2>74 && Uk2<85) && (Uk3>74 && Uk3<85)) || ((Uk1>84 && Uk1<92) && (Uk2>84 && Uk2<92)) || ((Uk3>74 && Uk3<85) && (Uk3>84 && Uk3<92)) || ((Uk2>84 && Uk2<92) && (Uk3>84 && Uk3<92)) || ((Uk1>91 && Uk1<101) && (Uk2>91 && Uk2<101)) || ((Uk1>91 && Uk1<101) && (Uk3>91 && Uk3<101)) || ((Uk3>91 && Uk3<101) && (Uk3>91 && Uk3<101)))
			printf("Dva od tri studenta imaju istu ocjenu.\n");
		else 
			printf("Svaki student ima razlicitu ocjenu.\n");
	}
	


	
		
	
	
		
	
	return 0;
}
