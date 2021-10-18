#include <stdio.h>
#include <stdint.h>
#include <math.h>
#define eps 0.00001
int main() {
	float pp1,pp2,z,p,zt,zbir1,zbir2,zbir3,zbir4;
	int polozio1=0;
	int polozio2=0;
	int polozio3=0;
	int ocjena1,ocjena2,ocjena3;
	printf("Unesite bodove za Tarika:\n");
	printf("I parcijalni ispit: ");
	scanf("%f" ,&pp1);
	if(pp1<0|| pp1>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f",&pp2);
		if(pp2<0|| pp2>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%f",&p);
		if(p<0|| p>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%f",&z);
		if(z<0|| z>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f",&zt);
	if(zt<0|| zt>40){
		printf("Neispravan broj bodova");
		return 0;
		
	}
	
	zbir1=pp1+pp2+z+p+zt;
	//zbir4=pp1+pp2+z+p;
    zbir4=55.00-zbir1;
	if(zbir1+eps>=55&&zbir1<65)ocjena1=6;
	if(zbir1>=65&&zbir1<75)ocjena1=7;
	if(zbir1>=75&&zbir1<85)ocjena1=8;
	if(zbir1>=85&&zbir1<92)ocjena1=9;
	if(zbir1>=92)ocjena1=10;
	if(zbir1+eps>=55&&ocjena1>=6)polozio1=1;
	//zbir4=zbir1-55;
	
	//printf("%f", zbir4);
	//drugi ucenik
		printf("Unesite bodove za Bojana:\n");
	printf("I parcijalni ispit: ");
	scanf("%f" ,&pp1);
	if(pp1<0|| pp1>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f",&pp2);
		if(pp2<0|| pp2>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%f",&p);
		if(p<0|| p>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%f",&z);
		if(z<0|| z>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f",&zt);
	if(zt<0|| zt>40){
		printf("Neispravan broj bodova");
		return 0;
		
	}
	
	zbir2=pp1+pp2+z+p+zt;
	//zbir4=pp1+pp2+z+p;
	if(zbir2>=55&&zbir2<65)ocjena2=6;
	if(zbir2>=65&&zbir2<75)ocjena2=7;
	if(zbir2>=75&&zbir2<85)ocjena2=8;
	if(zbir2>=85&&zbir2<92)ocjena2=9;
	if(zbir2>=92)ocjena1=10;
	if(zbir2>=55&&ocjena2>=6)polozio2=1;
	// 3. ucenik
		printf("Unesite bodove za Mirzu:\n");
	printf("I parcijalni ispit: ");
	scanf("%f" ,&pp1);
	if(pp1<0|| pp1>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f",&pp2);
		if(pp2<0|| pp2>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%f",&p);
		if(p<0|| p>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%f",&z);
		if(z<0|| z>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f",&zt);
	if(zt<0|| zt>40){
		printf("Neispravan broj bodova");
		return 0;
		
	}
	
	zbir3=pp1+pp2+z+p+zt;
	//zbir4=pp1+pp2+z+p;
	if(zbir3>=55&&zbir3<65)ocjena3=6;
	if(zbir3>=65&&zbir3<75)ocjena3=7;
	if(zbir3>=75&&zbir3<85)ocjena3=8;
	if(zbir3>=852&&zbir3<92)ocjena3=9;
	if(zbir3>=92)ocjena3=10;
	if(zbir3>=55&&ocjena3>=6)polozio3=1;
	
	
	if(polozio3==0&&polozio2==0&&polozio1==0)
	printf("Nijedan student nije polozio.\n");
	if(polozio1==1&&polozio2==1&&polozio3==1){
	printf("Sva tri studenta su polozila.\n");
		if(ocjena1!=ocjena2&&ocjena3!=ocjena1&&ocjena2!=ocjena3)
		printf("Svaki student ima razlicitu ocjenu.");
		if(ocjena3==ocjena2&&ocjena2==ocjena1)
		printf("Sva tri studenta imaju istu ocjenu.");
		if((ocjena1!=ocjena2&&ocjena1!=ocjena3&&ocjena2==ocjena3)||(ocjena2!=ocjena1&&ocjena2!=ocjena3&&ocjena1==ocjena3)||(ocjena3!=ocjena1&&ocjena3!=ocjena2&&ocjena1==ocjena2))
		printf("Dva od tri studenta imaju istu ocjenu.");
	}
	if((polozio1==1&&polozio2==0&&polozio3==0)||(polozio1==0&&polozio2==1&&polozio3==0)||(polozio1==0&&polozio2==0&&polozio3==1))
	printf("Jedan student je polozio.\n");
	if((polozio1==1&&polozio2==1&&polozio3==0)||(polozio1==0&&polozio2==1&&polozio3==1)||(polozio1==1&&polozio2==0&&polozio3==1))
	printf("Dva studenta su polozila.");

	return 0;
}