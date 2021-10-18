#include <stdio.h>
#include <math.h>
#define EPS 0.0001

int main() {
	double mprvap,tprvap,bprvap,mdrugap,tdrugap,bdrugap,mprisustvo,tprisustvo,bprisustvo,mzadace,bzadace,tzadace,mzavrsni,bzavrsni,tzavrsni,sumam,sumab,sumat;
	int mocjena,bocjena,tocjena;
	printf("Unesite bodove za Tarika:\nI parcijalni ispit: ");
	scanf("%lf",&tprvap);
	if(tprvap<0 || tprvap>20){ printf("Neispravan broj bodova"); return 0;}
	printf("II parcijalni ispit: ");
	scanf("%lf",&tdrugap);
	if(tdrugap<0 || tdrugap>20){ printf("Neispravan broj bodova"); return 0;}
	printf("Prisustvo: ");
	scanf("%lf",&tprisustvo);
	if(tprisustvo<0 || tprisustvo>10){ printf("Neispravan broj bodova"); return 0;}
	printf("Zadace: ");
	scanf("%lf",&tzadace);
	if(tzadace<0 || tzadace>10){ printf("Neispravan broj bodova"); return 0;}
	printf("Zavrsni ispit: ");
	scanf("%lf",&tzavrsni);
	if(tzavrsni<0 || tzavrsni>40){ printf("Neispravan broj bodova"); return 0;}
	printf("Unesite bodove za Bojana:\nI parcijalni ispit: ");
	scanf("%lf",&bprvap);
	if(bprvap<0 || bprvap>20){ printf("Neispravan broj bodova"); return 0;}
	printf("II parcijalni ispit: ");
	scanf("%lf",&bdrugap);
	if(bdrugap<0 || bdrugap>20){ printf("Neispravan broj bodova"); return 0;}
	printf("Prisustvo: ");
	scanf("%lf",&bprisustvo);
	if(bprisustvo<0 || bprisustvo>10){ printf("Neispravan broj bodova"); return 0;}
	printf("Zadace: ");
	scanf("%lf",&bzadace);
	if(bzadace<0 || bzadace>10){ printf("Neispravan broj bodova"); return 0;}
	printf("Zavrsni ispit: ");
	scanf("%lf",&bzavrsni);
	if(bzavrsni<0 || bzavrsni>40){ printf("Neispravan broj bodova"); return 0;}
	printf("Unesite bodove za Mirzu:\nI parcijalni ispit: ");
	scanf("%lf",&mprvap);
	if(mprvap<0 || mprvap>20){ printf("Neispravan broj bodova"); return 0;}
	printf("II parcijalni ispit: ");
	scanf("%lf",&mdrugap);
	if(mdrugap<0 || mdrugap>20){ printf("Neispravan broj bodova"); return 0;}
	printf("Prisustvo: ");
	scanf("%lf",&mprisustvo);
	if(mprisustvo<0 || mprisustvo>10){ printf("Neispravan broj bodova"); return 0;}
	printf("Zadace: ");
	scanf("%lf",&mzadace);
	if(mzadace<0 || mzadace>10){ printf("Neispravan broj bodova"); return 0;}
	printf("Zavrsni ispit: ");
	scanf("%lf",&mzavrsni);
	if(mzavrsni<0 || mzavrsni>40){ printf("Neispravan broj bodova"); return 0;}
	sumat=0;
	sumab=0;
	sumam=0;
	sumat=tprvap+tdrugap+tzadace+tzavrsni+tprisustvo;
	sumab=bprvap+bdrugap+bzadace+bprisustvo+bzavrsni;
	sumam=mprvap+mdrugap+mprisustvo+mzavrsni+mzadace;
	if(sumat>=92)tocjena=10;
	else if(sumat<92 && sumat>=85)tocjena=9;
	else if(sumat<85 && sumat>=75)tocjena=8;
	else if(sumat<75 && sumat>=65)tocjena=7;
	else if(sumat<65 && sumat>=55)tocjena=6;
	else tocjena=5;
	if(sumab>=92)bocjena=10;
	else if(sumab<92 && sumab>=85)bocjena=9;
	else if(sumab<85 && sumab>=75)bocjena=8;
	else if(sumab<75 && sumab>=65)bocjena=7;
	else if(sumab<65 && sumab>=55)bocjena=6;
	else bocjena=5;
	if(sumam>=92)mocjena=10;
	else if(sumam<92 && sumam>=85)mocjena=9;
	else if(sumam<85 && sumam>=75)mocjena=8;
	else if(sumam<75 && sumam>=65)mocjena=7;
	else if(sumam<65 && sumam>=55)mocjena=6;
	else mocjena=5;
	if(mocjena==5 && bocjena==5 && tocjena==5) printf("Nijedan student nije polozio.\n");
	else if((mocjena!=5 && bocjena==5 && tocjena==5) || (mocjena==5 && bocjena!=5 && tocjena==5) || (mocjena==5 && bocjena==5 && tocjena!=5)) printf("Jedan student je polozio.\n");
	else if(bocjena!=5 && mocjena!=5 && tocjena!=5) printf("Sva tri studenta su polozila.\n");
	else printf("Dva studenta su polozila.\n");
	if(bocjena==mocjena && mocjena==tocjena && bocjena!=5 && mocjena!=5 && tocjena!=5) printf("Sva tri studenta imaju istu ocjenu.\n");
	else if(bocjena!=mocjena && mocjena!=tocjena && tocjena!=bocjena && bocjena!=5 && mocjena!=5 && tocjena!=5)printf("Svaki student ima razlicitu ocjenu.\n");
	else if(bocjena!=5 && mocjena!=5 && tocjena!=5 && (bocjena==mocjena || mocjena==tocjena || tocjena==bocjena)) printf("Dva od tri studenta imaju istu ocjenu.");
	return 0;
}
