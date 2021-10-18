#include <stdio.h>

int main() {
	
	float pt1,pt2,pt,zt,zit,pb1,pb2,pb,zb,zib,pm1,pm2,pm,zm,zim,bt,bb,bm;
	int T=0,B=0,M=0;
	
	printf("Unesite bodove za Tarika:");
	
	printf("\nI parcijalni ispit: ");
	scanf("%f", &pt1);
	if (pt1 < 0 || pt1 > 20){
		printf("Neispravan broj bodova");
		return 0;
	} 
	
	printf("II parcijalni ispit: ");
	scanf("%f", &pt2);
	if (pt2 < 0 || pt2 > 20){
		printf("Neispravan broj bodova");
		return 0;
	} 
	
	printf("Prisustvo: ");
	scanf("%f", &pt);
	if (pt < 0 || pt > 10){
		printf("Neispravan broj bodova");
		return 0;
	} 
	
	printf("Zadace: ");
	scanf("%f", &zt);
	if (zt < 0 || zt > 10){
		printf("Neispravan broj bodova");
		return 0;
	} 
	
	printf("Zavrsni ispit: ");
	scanf("%f", &zit);
	if (zit < 0 || zit > 40){
		printf("Neispravan broj bodova");
		return 0;
	} 
	
	bt = (pt1*100 + pt2*100 + zt*100 + pt*100 + zit*100)/100;
	
	printf("Unesite bodove za Bojana: ");
	printf("\nI parcijalni ispit: ");
	scanf("%f", &pb1);
	if (pb1 < 0 || pb1 > 20){
		printf("Neispravan broj bodova");
		return 0;
	} 
	
	printf("II parcijalni ispit: ");
	scanf("%f", &pb2);
	if (pb2 < 0 || pb2 > 20){
		printf("Neispravan broj bodova");
		return 0;
	} 
	
	printf("Prisustvo: ");
	scanf("%f", &pb);
	if (pb < 0 || pb > 10){
		printf("Neispravan broj bodova");
		return 0;
	} 
	
	printf("Zadace: ");
	scanf("%f", &zb);
	if (zb < 0 || zb > 10){
		printf("Neispravan broj bodova");
		return 0;
	} 
	
	printf("Zavrsni ispit: ");
	scanf("%f", &zib);
	if (zib < 0 || zib > 40){
		printf("Neispravan broj bodova");
		return 0;
	} 
	
	bb = (pb1*100 + pb2*100 + pb*100 + zb*100 + zib*100)/100;
	
	printf("Unesite bodove za Mirzu: ");
	printf("\nI parcijalni ispit: ");
	scanf("%f", &pm1);
	if (pm1 < 0 || pm1 > 20){
		printf("Neispravan broj bodova");
		return 0;
	} 
	
	printf("II parcijalni ispit: ");
	scanf("%f", &pm2);
	if (pm2 < 0 || pm2 > 20){
		printf("Neispravan broj bodova");
		return 0;
	} 
	
	printf("Prisustvo: ");
	scanf("%f", &pm);
	if (pm < 0 || pm > 10){
		printf("Neispravan broj bodova");
		return 0;
	}
	
	printf("Zadace: ");
	scanf("%f", &zm);
	if (zm < 0 || zm > 10){
		printf("Neispravan broj bodova");
		return 0;
	} 
	
	printf("Zavrsni ispit: ");
	scanf("%f", &zim);
	if (zim < 0 || zim > 40){
		printf("Neispravan broj bodova");
		return 0;
	} 
	
	bm = (pm1*100 + pm2*100 + pm*100 + zm*100 + zim*100)/100;
	
	if (bt < 55 && bb < 55 && bm < 55){
		printf("Nijedan student nije polozio.");
		return 0;
	} else if (bt >= 55 && bb < 55 && bm < 55){
		printf("Jedan student je polozio.");
		return 0;
	} else if (bb >= 55 && bt < 55 && bm < 55){
		printf("Jedan student je polozio.");
		return 0;
	} else if (bm >= 55 && bb < 55 && bt < 55){
		printf("Jedan student je polozio.");
		return 0;
	} else if (bt >= 55 && bb >= 55 && bm < 55){
		printf("Dva studenta su polozila.");
		return 0;
	} else if (bt >= 55 && bm >= 55 && bb < 55){
		printf("Dva studenta su polozila.");
		return 0;
	} else if (bm >= 55 && bb >= 55 && bt < 55){
		printf("Dva studenta su polozila.");
		return 0;
	} else if (bt >= 55 && bb >= 55 && bm > 55){
		printf("Sva tri studenta su polozila.");
	}
	
	if (bt >= 55 && bt < 65){
		T = 6;
	} else if (bt >= 65 && bt < 75){
		T = 7;
	} else if (bt >= 75 && bt < 85){
		T = 8;
	} else if (bt >= 85 && bt < 92){
		T = 9;
	} else if (bt >= 92 && bt <= 100){
		T = 10;
	}
	
	if (bb >= 55 && bb < 65){
		B = 6;
	} else if (bb >= 65 && bb < 75){
		B = 7;
	} else if (bb >= 75 && bb < 85){
		B = 8;
	} else if (bb >= 85 && bb < 92){
		B = 9;
	} else if (bb >= 92 && bb <= 100){
		B = 10;
	}
	
	if (bm >= 55 && bm < 65){
		M = 6;
	} else if (bm >= 65 && bm < 75){
		M = 7;
	} else if (bm >= 75 && bm < 85){
		M = 8;
	} else if (bm >= 85 && bm < 92){
		M = 9;
	} else if (bm >= 92 && bm <= 100){
		M = 10;
	}
	
	if (T == B && B == M){
		printf("\nSva tri studenta imaju istu ocjenu.");
	} else if (T == B && B != M){
		printf("\nDva od tri studenta imaju istu ocjenu.");
	} else if (T == M && M != B ){
		printf("\nDva od tri studenta imaju istu ocjenu.");
	} else if (B == M && M != T ){
		printf("\nDva od tri studenta imaju istu ocjenu.");
	} else if (T != B && B != M && T != M){
		printf("\nSvaki student ima razlicitu ocjenu.");
	}
	
	return 0;
}
