#include <stdio.h>
#include <math.h>

int main() {
	float ip1, dp1, p1, zd1, ui1, sum1, ip2, dp2, p2, zd2, ui2, sum2, ip3, dp3, p3, zd3, ui3, sum3;
	int oc1, oc2, oc3;
	
	printf("Unesite bodove za Tarika: \n");
	
		printf("I parcijalni ispit: ");
		scanf("%f", &ip1);
			if((ip1<0) || (ip1>20))
				{
					printf("Neispravan broj bodova");
					return 0;
				}
		printf("II parcijalni ispit: ");
		scanf("%f", &dp1);
			if((dp1<0) || (dp1>20))
				{
					printf("Neispravan broj bodova");
					return 0;
				}
		printf("Prisustvo: ");
		scanf("%f", &p1);
			if((p1<0) || (p1>10))
				{
					printf("Neispravan broj bodova");
					return 0;
				}
		printf("Zadace: ");
		scanf("%f", &zd1);
			if((zd1<0) || (zd1>10))
				{
					printf("Neispravan broj bodova");
					return 0;
				}
		printf("Zavrsni ispit: ");
		scanf("%f", &ui1);
			if((ui1<0) || (ui1>40))
				{
					printf("Neispravan broj bodova");
					return 0;
				}
		
	printf("Unesite bodove za Bojana: \n");
	
		printf("I parcijalni ispit: ");
		scanf("%f", &ip2);
			if((ip2<0) || (ip2>20))
				{
					printf("Neispravan broj bodova");
					return 0;
				}
		printf("II parcijalni ispit: ");
		scanf("%f", &dp2);
			if((dp2<0) || (dp2>20))
				{
					printf("Neispravan broj bodova");
					return 0;
				}
		printf("Prisustvo: ");
		scanf("%f", &p2);
			if((p2<0) || (p2>10))
				{
					printf("Neispravan broj bodova");
					return 0;
				}
		printf("Zadace: ");
		scanf("%f", &zd2);
			if((zd2<0) || (zd2>10))
				{
					printf("Neispravan broj bodova");
					return 0;
				}
		printf("Zavrsni ispit: ");
		scanf("%f", &ui2);
			if((ui2<0) || (ui2>40))
				{
					printf("Neispravan broj bodova");
					return 0;
				}
	
	printf("Unesite bodove za Mirzu: \n");
	
		printf("I parcijalni ispit: ");
		scanf("%f", &ip3);
			if((ip3<0) || (ip3>20))
				{
					printf("Neispravan broj bodova");
					return 0;
				}
		printf("II parcijalni ispit: ");
		scanf("%f", &dp3);
			if((dp3<0) || (dp3>20))
				{
					printf("Neispravan broj bodova");
					return 0;
				}
		printf("Prisustvo: ");
		scanf("%f", &p3);
			if((p3<0) || (p3>10))
				{
					printf("Neispravan broj bodova");
					return 0;
				}
		printf("Zadace: ");
		scanf("%f", &zd3);
			if((zd3<0) || (zd3>10))
				{
					printf("Neispravan broj bodova");
					return 0;
				}
		printf("Zavrsni ispit: ");
		scanf("%f", &ui3);
			if((ui3<0) || (ui3>40))
				{
					printf("Neispravan broj bodova");
					return 0;
				}
	
		sum1=roundf((ip1+dp1+p1+zd1+ui1)*100)/100;
		sum2=roundf((ip2+dp2+p2+zd2+ui2)*100)/100;
		sum3=roundf((ip3+dp3+p3+zd3+ui3)*100)/100;

		if(sum1>=55 && sum1<65)
			oc1=6;
		else if(sum1>=65 && sum1<75)
			oc1=7;
		else if(sum1>=75 && sum1<85)
		    oc1=8;
		else if(sum1>=85 && sum1<92)
			oc1=9;
		else if(sum1>=92)
			oc1=10;
		else oc1=5;
		
		if(sum2>=55 && sum2<65)
			oc2=6;
		else if(sum2>=65 && sum2<75)
			oc2=7;
		else if(sum2>=75 && sum2<85)
		    oc2=8;
		else if(sum2>=85 && sum2<92)
			oc2=9;
		else if(sum2>=92)
			oc2=10;
		else oc2=5;
		
		if(sum3>=55 && sum3<65)
			oc3=6;
		else if(sum3>=65 && sum3<75)
			oc3=7;
		else if(sum3>=75 && sum3<85)
		    oc3=8;
		else if(sum3>=85 && sum3<92)
			oc3=9;
		else if(sum3>=92)
			oc3=10;
		else oc3=5;

	
	if(oc1==5 && oc2==5 && oc3==5)
		printf("Nijedan student nije polozio.");
	else{

				if((oc1>5 && oc2==5 && oc3==5) || (oc1==5 && oc2>5 && oc3==5) || (oc1==5 && oc2==5 && oc3>5))
					printf("Jedan student je polozio.\n");
				else if((oc1>5 && oc2>5 && oc3==5) || (oc1>5 && oc2==5 && oc3>5) || (oc1==5 && oc2>5 && oc3>5))
					printf("Dva studenta su polozila.\n");
				else if(oc1>5 && oc2>5 && oc3>5)
					{
						printf("Sva tri studenta su polozila.\n");
					if((oc1==oc2) && (oc1==oc3) && (oc2==oc3))
					printf("Sva tri studenta imaju istu ocjenu.");
					else if((oc1!=oc2) && (oc1!=oc3) && (oc2!=oc3))
					printf("Svaki student ima razlicitu ocjenu.");
					else if(((oc1==oc2) && (oc1!=oc3)) || ((oc1==oc3) && (oc1!=oc2)) || ((oc2==oc3) && (oc2!=oc1)))
					printf("Dva od tri studenta imaju istu ocjenu.");
				}
	}
	
	return 0;
}
