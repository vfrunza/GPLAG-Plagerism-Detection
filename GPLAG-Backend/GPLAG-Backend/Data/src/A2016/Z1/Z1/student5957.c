#include <stdio.h>

int main() {
	float T1,T2,Tp,Tz,Tzi,B1,B2,Bp,Bz,Bzi,M1,M2,Mp,Mz,Mzi;
	float Ut,Ub,Um;
	float A=5,B=6,C=7,D=8,E=9,F=10;
	printf("Unesite bodove za Tarika: \n");
	printf("I parcijalni ispit: ");
	scanf("%g", &T1);
	if(T1<0 || T1>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%g", &T2);
	if(T2<0 || T2>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%g", &Tp);
	if(Tp<0 || Tp>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%g", &Tz);
	if(Tz<0 || Tz>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%g", &Tzi);
	if(Tzi<0 || Tzi>40){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Unesite bodove za Bojana: \n");
	printf("I parcijalni ispit: ");
	scanf("%g", &B1);
	if(B1<0 || B1>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%g", &B2);
	if(B2<0 || B2>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%g", &Bp);
	if(Bp<0 || Bp>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%g", &Bz);
	if(Bz<0 || Bz>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%g", &Bzi);
	if(Bzi<0 || Bzi>40){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Unesite bodove za Mirzu:\n");
	printf("I parcijalni ispit: ");
	scanf("%g", &M1);
	if(M1<0 || M1>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%g", &M2);
	if(M2<0 || M2>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%g", &Mp);
	if(Mp<0 || Mp>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%g", &Mz);
	if(Mz<0 || Mz>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f", &Mzi);
	if(Mzi<0 || Mzi>40){
		printf("Neispravan broj bodova");
		return 0;
	}
		Ut=T1+T2+Tp+Tz+Tzi;
		Ub=B1+B2+Bp+Bz+Bzi;
		Um=M1+M2+Mp+Mz+Mzi;
	
	
		
		if((Ut>54.99 && Ub<55.00 && Um<55.00) || (Ut<55.00 && Ub>54.99 && Um<55.00) || (Ut<55.00 && Ub<55.00 && Um>54.99))
		printf("Jedan student je polozio.\n");
		else if((Ut>=55.00 && Ub>=55.00 && Um<55.00) || (Ut>=55.00 && Ub<55.00 && Um>=55.00) || (Ut<55.00 && Ub>=55.00 && Um>=55.00))
		printf("Dva studenta su polozila.\n");
	
		
		else if(Ut>=55 && Ub>=55 && Um>=55){
		printf("Sva tri studenta su polozila.\n");
	    if((Ut>=55 && Ut<65) && (Ub>=55 && Ub<65) && (Um>=55 && Um<65)){
		Ut==B;
		Ub==B;
		Um==B;
	    	
	    }
		else if((Ut>=65 && Ut<75) && (Ub>=65 && Ub<75) && (Um>=65 && Um<75)){
		Ut==C; Ub==C; Um==C;}
		else if((Ut>=75 && Ut<85) && (Ub>=75 && Ub<85) && (Um>=75 && Um<85)){
		Ut==D; Ub==D; Um==D;}
		else if((Ut>=85 && Ut<92) && (Ub>=85 && Ub<92) && (Um>=85 && Um<92)){
		Ut==E; Ub==E; Um==E;}
		else{
		Ut==F; Ub==F; Um==F;}
		//Ut=round(Ut);
		//Um=round(Um);
		//Ub=round(Ub);
	    if(Ut==B && Ub==B && Um==B)
		printf("Sva tri studenta imaju istu ocjenu.\n");
		else if(Ut==C && Ub==C && Um==C)
		printf("Sva tri studenta imaju istu ocjenu.\n");
		else if(Ut==Ub && Ut==Um && Ub==Um)
		printf("Sva tri studenta imaju istu ocjenu.\n");
		else if(Ut==D && Ub==D && Um==D)
		printf("Sva tri studenta imaju istu ocjenu.\n");
		else if(Ut==E && Ub==E && Um==E)
		printf("Sva tri studenta imaju istu ocjenu.\n");
		else if(Ut==F && Ub==F && Um==F)
		printf("Sva tri studenta imaju istu ocjenu.\n");
		
		else if((Ut>=55 && Ut<65 && Ub>=55 && Ub<65 && Um>=65) || (Ut>=55 && Ut<65 && Um>=55 && Um<65 && Ub>=65) || (Um>=55 && Um<65 && Ub>=55 && Ub<65 && Ut>=65))
		printf("Dva od tri studenta imaju istu ocjenu.");
	    else if((Ut>=65 && Ut<75 && Ub>=65 && Ub<75 && Um>=75 && Um<65) || (Ut>=65 && Ut<75 && Um>=65 && Um<75 && Ub>=75 && Ub<65) || (Um>=65 && Um<75 && Ub>=65 && Ub<75 && Ut<65 && Ut>=75))
		printf("Dva od tri studenta imaju istu ocjenu.");
		else if((Ut>=75 && Ut<85 && Ub>=75 && Ub<85 && Um>=85 && Um<75) || (Ut>=75 && Ut<85 && Um>=75 && Um<85 && Ub>=85 && Ub<75) || (Um>=75 && Um<85 && Ub>=75 && Ub<85 && Ut>=85 && Ut<75))
		printf("Dva od tri studenta imaju istu ocjenu.");
		else if((Ut>=85 && Ut<92 && Ub>=85 && Ub<92 && Um>=92 && Um<85) || (Ut>=85 && Ut<92 && Um>=85 && Um<92 && Ub>=92 && Ub<85) || (Um>=85 && Um<92 && Ub>=85 && Ub<92 && Ut>=92 && Ut<85))
		printf("Dva od tri studenta imaju istu ocjenu.");
		else if((Ut>=92 && Ub>=92 && Um<92) || (Ut>=92 && Um>=92 && Ub<92) || (Um>=92 && Ub>=92 && Ut<92))
		printf("Dva od tri studenta imaju istu ocjenu.");
		else 
		printf("Svaki student ima razlicitu ocjenu.\n");
		
		
		}
		else if(Ut<55.00 && Ub<55.00 && Um<55.00)
		printf("Nijedan student nije polozio.\n");
		
		
		
		
		
		
		
	return 0;
}
