#include <stdio.h>
#include <math.h>
#define P1 20
#define P2 20
#define P 10
#define Z 10
#define G 40
#define EPS 0.0001
int main() {
	double pjt,pjb,pjm, pdt,pdb,pdm, pt,pb,pm, zt,zb,zm, gt,gb,gm,ut,ub,um;
	int ot=0,ob=0,om=0;
	printf("Unesite bodove za Tarika: ");
	printf("\nI parcijalni ispit: ");
	scanf ("%lf", &pjt);
	if(pjt <0 || pjt>P1){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf ("%lf", &pdt);
		if(pdt <0 || pdt>P2){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &pt);
		if(pt <0 || pt>P){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &zt);
		if(zt <0 || zt>Z){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &gt);
		if(gt <0 || gt>G){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Unesite bodove za Bojana: ");
	printf("\nI parcijalni ispit: ");
	scanf("%lf", &pjb);
		if(pjb <0 || pjb>P1){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf ("%lf", &pdb);
		if(pdb <0 || pdb>P2){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &pb);
		if(pb <0 || pb>P){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &zb);
		if(zb <0 || zb>Z){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &gb);
		if(gb <0 || gb>G){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Unesite bodove za Mirzu: ");
	printf("\nI parcijalni ispit: ");
	scanf ("%lf", &pjm);
		if(pjm<0 || pjm>P1){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf ("%lf", &pdm);
		if(pdm <0 || pdm>P2){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &pm);
		if(pm <0 || pm>P){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &zm);
		if(zm <0 || zm>Z){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &gm);
		if(gm <0 || gm>G){
		printf("Neispravan broj bodova");
		return 0;
	}else{
		ut = pjt + pdt + pt + zt +gt;
		ub = pjb + pdb + pb + zb +gb;
		um = pjm + pdm + pm + zm +gm;
			if (ut<55){
				ot=5;
			}else if((fabs(ut-55)<EPS || ut>55) && ut<65){
				ot=6;	
			}else if((fabs(ut-65)<EPS || ut>65) && ut<75){
				ot=7;
			}else if((fabs(ut-75)<EPS || ut>75) && ut<85){
				ot=8;	
			}else if((fabs(ut-85)<EPS || ut>85) && ut<92){
				ot=9;
			}else if((fabs(ut-92)<EPS || ut>92) && (fabs(ut-100)<EPS && ut<100)){
				ot=10;
			}
			if (ub<55){
				ob=5;
			}else if((fabs(ub-55)<EPS || ub>55) && ub<65){
				ob=6;	
			}else if((fabs(ub-65)<EPS || ub>65) && ub<75){
				ob=7;
			}else if((fabs(ub-75)<EPS || ub>75) && ub<85){
				ob=8;	
			}else if((fabs(ub-85)<EPS || ub>85) && ub<92){
				ob=9;
			}else if((fabs(ub-92)<EPS || ub>92) && (fabs(ub-100)<EPS && ub<100)){
				ob=10;
			}
			if (um<55){
				om=5;
			}else if((fabs(um-55)<EPS || um>55) && um<65){
				om=6;	
			}else if((fabs(um-65)<EPS || um>65) && um<75){
				om=7;
			}else if((fabs(um-75)<EPS || um>75) && um<85){
				om=8;	
			}else if((fabs(um-85)<EPS || um>85) && um<92){
				om=9;
			}else if((fabs(um-92)<EPS || um>92) && (fabs(um-100)<EPS && um<100)){
				om=10;
			}
			if ((ot>5 && ot <=10)&&(ob>5 && ob<=10)&&(om>5 && om <=10)){
				printf("Sva tri studenta su polozila.");
		if((ot==ob)&&(ot==om)&&(ob==om)){
			printf("\nSva tri studenta imaju istu ocjenu.");
		}else if (ot==ob){
			printf("\nDva od tri studenta imaju istu ocjenu.");
		}else if (om==ob){
			printf("\nDva od tri studenta imaju istu ocjenu.");
		}else if (ot==om){
			printf("\nDva od tri studenta imaju istu ocjenu.");
		}else{
			printf("\nSvaki student ima razlicitu ocjenu.");
		}
			}else if (((fabs(ut-55)<EPS || ut>55) && (fabs(ut-100)<EPS || ut<100) && (ub<55)&&(um<55)) || ((ut<55) && ((fabs(ub-55)<EPS || ub>55) && (fabs(ub-100)<EPS || ub<100)) && (um<55)) || ((fabs(um-55)<EPS || um>55) && (fabs(um-100)||um<100) && (ut<55) && (ub<55))){
				printf("Jedan student je polozio.");
			}else if ((((fabs(ut-55)<EPS || ut>55) && ((fabs(ut-100)<EPS || ut <100))) && ((fabs(ub-55)<EPS || ub>55) && (fabs(ub-100)<EPS || ub<100))&&(um<55))||(((fabs(ut-55)<EPS || ut>55) && (fabs(ut-100)<EPS || ut <100)) && ((fabs(um-55)<EPS || um>55) && (fabs(um-100)<EPS || um<100))&&(ub<55))||(((fabs(um-55)<EPS || um>55) && (fabs(um-100)<EPS || um <100)) && ((fabs(ub-55)<EPS || ub>55) && (fabs(ub-100)<EPS || ub<100))&&(ut<55))){
				printf("Dva studenta su polozila.");
			}else if((ut<55)&&(ub<55)&&(um<55)){
				printf("Nijedan student nije polozio.");
			}
		}
	return 0;
}
