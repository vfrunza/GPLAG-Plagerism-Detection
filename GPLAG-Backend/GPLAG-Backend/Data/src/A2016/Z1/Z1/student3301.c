#include <stdio.h>
#include <math.h>
#define EPS 0.01
int main() {
	float TBod1,TBod2,TPris,TZad,TZI,BBod1,BBod2,BPris,BZad,BZI,MBod1,MBod2,MPris,MZad,MZI;
	float Stud1=0,Stud2=0,Stud3=0;
	int brojac=0,o6=0,o7=0,o8=0,o9=0,o10=0;
	printf("Unesite bodove za Tarika:\nI parcijalni ispit: ");
	scanf("%f",&TBod1);
	if(TBod1<0 || TBod1>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f",&TBod2);
	if(TBod2<0 || TBod2>20){ 
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%f",&TPris);
	if(TPris<0 || TPris>10){ 
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%f",&TZad);
	if(TZad<0 || TZad>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f",&TZI);
	if(TZI<0 || TZI>40){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Unesite bodove za Bojana:\nI parcijalni ispit: ");
	scanf("%f",&BBod1);
	if(BBod1<0 || BBod1>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f",&BBod2);
	if(BBod2<0 || BBod2>20){ 
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%f",&BPris);
	if(BPris<0 || BPris>10){ 
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%f",&BZad);
	if(BZad<0 || BZad>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f",&BZI);
	if(BZI<0 || BZI>40){
		printf("Neispravan broj bodova");
		return 0;
	}
		printf("Unesite bodove za Mirzu:\nI parcijalni ispit: ");
	scanf("%f",&MBod1);
	if(MBod1<0 || MBod1>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f",&MBod2);
	if(MBod2<0 || MBod2>20){ 
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%f",&MPris);
	if(MPris<0 || MPris>10){ 
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%f",&MZad);
	if(MZad<0 || MZad>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f",&MZI);
	if(MZI<0 || MZI>40){
		printf("Neispravan broj bodova");
		return 0;
	}
	Stud1=TBod1+TBod2+TPris+TZad+TZI;
	Stud2=BBod1+BBod2+BPris+BZad+BZI;
	Stud3=MBod1+MBod2+MPris+MZad+MZI;
	if(fabs(55-Stud1)<=EPS) Stud1=55;
	if(fabs(55-Stud2)<=EPS) Stud2=55;
	if(fabs(55-Stud3)<=EPS) Stud3=55;
	if(Stud1>=55) brojac++;
	if(Stud2>=55) brojac++;
	if(Stud3>=55) brojac++;
	if(Stud1>=55 && Stud1<65) o6++;
	if(Stud1>=65 && Stud1<75) o7++;
	if(Stud1>=75 && Stud1<85) o8++;
	if(Stud1>=85 && Stud1<92) o9++;
	if(Stud1>=92 && Stud1<100) o10++;
	if(Stud2>=55 && Stud2<65) o6++;
	if(Stud2>=65 && Stud2<75) o7++;
	if(Stud2>=75 && Stud2<85) o8++;
	if(Stud2>=85 && Stud2<92) o9++;
	if(Stud2>=92 && Stud2<100) o10++;
	if(Stud3>=55 && Stud3<65) o6++;
	if(Stud3>=65 && Stud3<75) o7++;
	if(Stud3>=75 && Stud3<85) o8++;
	if(Stud3>=85 && Stud3<92) o9++;
	if(Stud3>=92 && Stud3<100) o10++;
	if(brojac==0){
		printf("Nijedan student nije polozio.\n");
	}
	if(brojac==1){
		printf("Jedan student je polozio.\n");
	}
	if(brojac==2){
		printf("Dva studenta su polozila.\n");
	}
	if(brojac==3){
		printf("Sva tri studenta su polozila.\n");
		if(o6==3 || o7==3 || o8==3 || o9==3 || o10==3){
			printf("Sva tri studenta imaju istu ocjenu.\n");
		}
		if(o6==2 || o7==2 || o8==2 || o9==2 || o10==2){
			printf("Dva od tri studenta imaju istu ocjenu.\n");
		}
		if((o6==1|| o6==0) && (o7==1 || o7==0) && (o8==1 || o8==0) && (o9==1 || o9==0) && (o10==1 || o10==0)){
			printf("Svaki student ima razlicitu ocjenu.\n");
		}
	}
	return 0;
}
