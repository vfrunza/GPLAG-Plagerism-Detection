#include <stdio.h>
#define EPS 0.01
#include<math.h>
int main() {
	//printf("Zadaća 1, Zadatak 1");
	float TPARC1,TPARC2,TZ,TP,TK;
	float BPARC1,BPARC2,BZ,BP,BK;
	float MPARC1,MPARC2,MZ,MP,MK;
	printf("Unesite bodove za Tarika: \n");
	printf("I parcijalni ispit: ");
	scanf("%f",&TPARC1);
	if(TPARC1>20||TPARC1<0){
		printf("Neispravan broj bodova"); return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f",&TPARC2);
	if(TPARC2>20||TPARC2<0){
		printf("Neispravan broj bodova"); return 0;
	}
	printf("Prisustvo: ");
	scanf("%f",&TP);
	if(TP>10||TP<0){
		printf("Neispravan broj bodova"); return 0;
	}
	printf("Zadace: ");
	scanf("%f",&TZ);
	if(TZ>10||TZ<0){
		printf("Neispravan broj bodova"); return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f",&TK);
	if(TK>40||TK<0){
		printf("Neispravan broj bodova"); return 0;
	}





	printf("Unesite bodove za Bojana: \n");
	printf("I parcijalni ispit: ");
	scanf("%f",&BPARC1);
	if(BPARC1>20||BPARC1<0){
		printf("Neispravan broj bodova"); return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f",&BPARC2);
	if(BPARC2>20||BPARC2<0){
		printf("Neispravan broj bodova"); return 0;
	}
	printf("Prisustvo: ");
	scanf("%f",&BP);
	if(BP>10||BP<0){
		printf("Neispravan broj bodova"); return 0;
	}
	printf("Zadace: ");
	scanf("%f",&BZ);
	if(BZ>10||BZ<0){
		printf("Neispravan broj bodova"); return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f",&BK);
	if(BK>40||BK<0){
		printf("Neispravan broj bodova"); return 0;
	}




	printf("Unesite bodove za Mirzu: \n");
	printf("I parcijalni ispit: ");
	scanf("%f",&MPARC1);
	if(MPARC1>20||MPARC1<0){
		printf("Neispravan broj bodova"); return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f",&MPARC2);
	if(MPARC2>20||MPARC2<0){
		printf("Neispravan broj bodova"); return 0;
	}
	printf("Prisustvo: ");
	scanf("%f",&MP);
	if(MP>10||MP<0){
		printf("Neispravan broj bodova"); return 0;
	}
	printf("Zadace: ");
	scanf("%f",&MZ);
	if(MZ>10||MZ<0){
		printf("Neispravan broj bodova"); return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f",&MK);
	if(MK>40||MK<0){
		printf("Neispravan broj bodova"); return 0;
	}

	float Tsuma,Bsuma,Msuma;
	Tsuma=TPARC1+TPARC2+TZ+TP+TK;
	Bsuma=BPARC1+BPARC2+BZ+BP+BK;
	Msuma=MPARC1+MPARC2+MZ+MP+MK;
						//printf("\n Sume su redom T= %f, B= %f, M= %f",Tsuma,Bsuma,Msuma);
	int brojacPadova=0, brojac6=0,brojac7=0,brojac8=0,brojac9=0,brojac10=0,brojacIsto=0;
	//Za Tarika racun
	
	//pONOVNI PRORACUN UZ EPS KAO PROIZVOLJNO MALI INTERVAL POREDENJA
	if(Tsuma<=(55-EPS)){
		brojacPadova++;	//printf ("\n Tarik pao\n");
	} else if (Tsuma>=55&&Tsuma<65){
		brojac6++;		//printf ("\n Tarik dobio 6\n");
	} else if (Tsuma>=65&&Tsuma<75){
		brojac7++;		//printf ("\n Tarik dobio 7\n");
	} else if (Tsuma>=75&&Tsuma<85){
		brojac8++;	//	printf ("\n Tarik dobio 8\n");
	} else if (Tsuma>=85&&Tsuma<92){
		brojac9++;	//	printf ("\n Tarik dobio 9\n");
	} else if (Tsuma>=92&&Tsuma<100){
		brojac10++;	//	printf ("\n Tarik dobio 10\n");
	}
	//Za Bojana racun
	if(Bsuma<=(55-EPS)){
		brojacPadova++;//printf ("\n Bojan pao\n");
	} else if (Bsuma>=55&&Bsuma<65){
		brojac6++;		//printf ("\n Bojan dobio 6\n");
	} else if (Bsuma>=65&&Bsuma<75){
		brojac7++;		//printf ("\n Bojan dobio 7\n");
	} else if (Bsuma>=75&&Bsuma<85){
		brojac8++;		//printf ("\n Bojan dobio 8\n");
	} else if (Bsuma>=85&&Bsuma<92){
		brojac9++;		//printf ("\n Bojan dobio 9\n");
	} else if (Bsuma>=92&&Bsuma<100){
		brojac10++;		//printf ("\n Bojan dobio 10\n");
	}
	//Za Mirzu racun
	if(Msuma<=(55-EPS)){
		brojacPadova++; 	//printf ("\n Mirza pao\n");
	} else if (Msuma>=55&&Msuma<65){
		brojac6++;		//printf ("\n Mirza dobio 6\n");
	} else if (Msuma>=65&&Msuma<75){
		brojac7++;	//	printf ("\n Mirza dobio 7\n");
	} else if (Msuma>=75&&Msuma<85){
		brojac8++;	//	printf ("\n Mirza dobio 8\n");
	} else if (Msuma>=85&&Msuma<92){
		brojac9++;	//	printf ("\n Mirza dobio 9\n");
	} else if (Msuma>=92&&Msuma<100){
		brojac10++;	//	printf ("\n Mirza dobio 10\n");
	}
	
	//Dalji ispis
	if(brojacPadova==3){
		printf("Nijedan student nije polozio.");
	} else if (brojacPadova==1){
		printf("Dva studenta su polozila.");
	} else if (brojacPadova==2){
		printf("Jedan student je polozio.");
	} else if (brojacPadova==0){
		printf("Sva tri studenta su polozila.\n");
	
	
		if(brojac6==3||brojac7==3||brojac8==3||brojac9==3||brojac10==3){
			printf("Sva tri studenta imaju istu ocjenu.");
		} else if (brojac6==2||brojac7==2||brojac8==2||brojac9==2||brojac10==2){
			printf("Dva od tri studenta imaju istu ocjenu.");
		} else if (brojac6==1||brojac7==1||brojac8==1||brojac9==1||brojac10==1){
			printf("Svaki student ima razlicitu ocjenu.");
		}
		
	
	
	
		//if(brojac6==1||brojac7==1||brojac8==1||brojac9==1||brojac10==1){
		//	printf("Svaki student ima razlicitu ocjenu.");
		//} else if (brojac6==2||brojac7==2||brojac8==2||brojac9==2||brojac10==2){
		//	printf("Dva od tri studenta imaju istu ocjenu.");
		//} else if (brojac6==3||brojac7==3||brojac8==3||brojac9==3||brojac10==3){
		//	printf("Sva tri studenta imaju istu ocjenu.");
		//}
	}
	
	
	
	
	
	

	return 0;
}
