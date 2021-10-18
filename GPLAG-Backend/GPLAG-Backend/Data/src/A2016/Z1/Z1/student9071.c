#include <stdio.h>

int main() {
	/*Varijable redoslijed: prvi parcijalni, drugi parcijalni, prisustvo, zadaca, ispit; poredano po imenima Tarik, Bojan i Mirza*/
	int zx=2;
	double t1=0,t2=0,tp=0,tz=0,ti=0;
	double b1=0,b2=0,bp=0,bz=0,bi=0;
	double m1=0,m2=0,mp=0,mz=0,mi=0;
	
	double OT=0,OB=0,OM=0; /*ocjene*/
	double BT=0,BB=0,BM=0; /*bodovi*/
	
	
	
	do{
	/*Unos varijabli*/
		printf("Unesite bodove za Tarika: \n");
printf("I parcijalni ispit: ");
	scanf("%lf",&t1);
	if ((t1<0)||(t1>20)){
	printf("Neispravan broj bodova");
		break;}
		
printf("II parcijalni ispit: ");	
	scanf("%lf",&t2);
	if ((t2<0)||(t2>20)){
		printf("Neispravan broj bodova");
		break;}
		
printf("Prisustvo: ");
	scanf("%lf",&tp);
	if ((tp<0)||(tp>10)){
	printf("Neispravan broj bodova");
		break;}
		
printf("Zadace: ");
	scanf("%lf",&tz);
	if ((tz<0)||(tz>10)){
	printf("Neispravan broj bodova");
		break;}
	
printf("Zavrsni ispit: ");
	scanf("%lf",&ti);
	if ((ti<0)||(ti>40)){
	printf("Neispravan broj bodova");
		break;}
	
		printf("Unesite bodove za Bojana: \n");
		printf("I parcijalni ispit: ");
	scanf("%lf",&b1);
	if ((b1<0)||(b1>20)){
	printf("Neispravan broj bodova");
		break;	}
		printf("II parcijalni ispit: ");	
	scanf("%lf",&b2);
	if ((b2<0)||(b2>20)){
	printf("Neispravan broj bodova");
		break;	}
		printf("Prisustvo: ");
	scanf("%lf",&bp);
	if ((bp<0)||(bp>10)){
	printf("Neispravan broj bodova");
		break;	}
		printf("Zadace: ");
	scanf("%lf",&bz);
	if ((bz<0)||(bz>10)){
	printf("Neispravan broj bodova");
		break;	}
		printf("Zavrsni ispit: ");
	scanf("%lf",&bi);
	if ((bi<0)||(bi>40)){
	printf("Neispravan broj bodova");
		break;	}
	
			printf("Unesite bodove za Mirzu: \n");
		printf("I parcijalni ispit: ");
	scanf("%lf",&m1);
	if ((m2<0)||(m2>20)){
	printf("Neispravan broj bodova");
		break;		}
		printf("II parcijalni ispit: ");	
	scanf("%lf",&m2);
	if ((m2<0)||(m2>20)){
	printf("Neispravan broj bodova");
		break;		}
		printf("Prisustvo: ");
	scanf("%lf",&mp);
	if ((mp<0)||(mp>10)){
	printf("Neispravan broj bodova");
		break;}
		printf("Zadace: ");
	scanf("%lf",&mz);
	if ((mz<0)||(mz>10)){
	printf("Neispravan broj bodova");
		break;	}
		printf("Zavrsni ispit: ");
	scanf("%lf",&mi);      
	if ((mi<0)||(mi>40)){
	printf("Neispravan broj bodova");
		break;		}
	
	/*Testiranje validnosti unosa*/
	


	
	
	/*Glavni dio koda*/
	
	BT=t1+t2+tp+tz+ti;
	BB=b1+b2+bp+bz+bi;
	BM=m1+m2+mp+mz+mi;
	
	
	/*Tarikove ocjene*/
	
	if (BT<55){
		OT=0;
	}
	else if ((BT>=55)&&(BT<65)){
		OT=6;
	}
	else if ((BT>=65)&&(BT<75)){
		OT=7;
	}	
	else if ((BT>=75)&&(BT<85)){
		OT=8;
	}	
	else if ((BT>=85)&&(BT<92)){
		OT=9;
	}	
	else if ((BT>=92)&&(BT<=100)){
		OT=10;
	}	
/*---------Boki ocjene-------------*/	
	if (BB<55){
		OB=0;
	}
	else if ((BB>=55)&&(BB<65)){
		OB=6;
	}
	else if ((BB>=65)&&(BB<75)){
		OB=7;
	}	
	else if ((BB>=75)&&(BB<85)){
		OB=8;
	}	
	else if ((BB>=85)&&(BB<92)){
		OB=9;
	}	
	else if ((BB>=92)&&(BB<=100)){
		OB=10;
	}	
/*------------Mirza ocjene----------*/	
		if (BM<55){
		OM=0;
	}
	else if ((BM>=55)&&(BM<65)){
		OM=6;
	}
	else if ((BM>=65)&&(BM<75)){
		OM=7;
	}	
	else if ((BM>=75)&&(BM<85)){
		OM=8;
	}	
	else if ((BM>=85)&&(BM<92)){
		OM=9;
	}	
	else if ((BM>=92)&&(BM<=100)){
		OM=10;
	}
	
	/*Testiranje koliko su polozili*/
	
    if ((OT==0)&&(OB==0)&&(OM==0)){
    	printf("Nijedan student nije polozio."); 
    	
    }
	
	else if (((OT!=0)&&(OB==0)&&(OM==0))||((OT==0)&&(OB!=0)&&(OM==0))||((OT==0)&&(OB==0)&&(OM!=0))){
		printf("Jedan student je polozio.");
		
	}
	
	else if (((OT!=0)&&(OB!=0)&&(OM==0)) || ((OT!=0)&&(OB==0)&&(OM!=0)) || ((OT==0)&&(OB!=0)&&(OM!=0))){
		printf("Dva studenta su polozila.");
		
	}
	
	else if ((OT!=0)&&(OB!=0)&&(OM!=0)){
		printf("Sva tri studenta su polozila.");
			
		
	
	if ((OT==OB)&&(OT==OM)){
	printf("\nSva tri studenta imaju istu ocjenu.");	
		
	} else if ((OT!=OB)&&(OT!=OM)){
	printf("\nSvaki student ima razlicitu ocjenu.");
		}  	else  {
			printf("\nDva od tri studenta imaju istu ocjenu.");
		}
	}
	
	
	
	
	
	}while(zx!=2);
	return 0;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
