#include <stdio.h>

int main() {
	double t1parc, t2parc, tzavrsni, b1parc, b2parc, bzavrsni, m1parc, m2parc, mzavrsni, tsuma, bsuma, msuma;
	double tzadace, tprisustvo, bzadace, bprisustvo, mzadace, mprisustvo;
	int brojac_pao=0, b6=0, b7=0, b8=0, b9=0, b10=0;
	printf("Unesite bodove za Tarika:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf\n", &t1parc);
	if(t1parc<0 || t1parc>20)
		printf("Neispravan broj bodova");
	else{
	printf("II parcijalni ispit: ");
	scanf("%lf\n", &t2parc);
	if(t2parc<0 || t2parc>20)
		printf("Neispravan broj bodova");
	else{
	printf("Prisustvo: ");
	scanf("%lf\n", &tprisustvo);
	if(tprisustvo<0 || tprisustvo>10)
		printf("Neispravan broj bodova");
	else{
	printf("Zadace: ");
	scanf("%lf\n", &tzadace);
	if(tzadace<0 || tzadace>10)
		printf("Neispravan broj bodova");
	else{
	printf("Zavrsni ispit: ");
	scanf("%lf\n", &tzavrsni);
	if(tzavrsni<0 || tzavrsni>100)
		printf("Neispravan broj bodova");
	else{
	printf("Unesite bodove za Bojana:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf\n", &b1parc);
	if(b1parc<0 || b1parc>20)
		printf("Neispravan broj bodova");
	else{
	printf("II parcijalni ispit: ");
	scanf("%lf\n", &b2parc);
	if(b2parc<0 || b2parc>20)
		printf("Neispravan broj bodova");
	else{
	printf("Prisustvo: ");
	scanf("%lf\n", &bprisustvo);
	if(bprisustvo<0 || bprisustvo>10)
		printf("Neispravan broj bodova"); 
	else{
	printf("Zadace: ");
	scanf("%lf\n", &bzadace);
	if(bzadace<0 || bzadace>10)
		printf("Neispravan broj bodova"); 
	else{
	printf("Zavrsni ispit: ");
	scanf("%lf\n", &bzavrsni);
	if(bzavrsni<0 || bzavrsni>100)
		printf("Neispravan broj bodova"); 
	else{
	printf("Unesite bodove za Mirzu:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf\n", &m1parc);
	if(m1parc<0 || m1parc>20)
		printf("Neispravan broj bodova"); 
	else{
	printf("II parcijalni ispit: ");
	scanf("%lf\n", &m2parc);
	if(m2parc<0 || m2parc>20)
		printf("Neispravan broj bodova"); 
	else{
	printf("Prisustvo: ");
	scanf("%lf\n", &mprisustvo);
	if(mprisustvo<0 || mprisustvo>10)
		printf("Neispravan broj bodova"); 
	else{
	printf("Zadace: ");
	scanf("%lf\n", &mzadace);
	if(mzadace<0 || mzadace>10)
		printf("Neispravan broj bodova"); 
	else{
	printf("Zavrsni ispit: ");
	scanf("%lf\n", &mzavrsni);
	if(mzavrsni<0 || mzavrsni>100)
		printf("Neispravan broj bodova"); 
	else{
	
	tsuma=t1parc+t2parc+tprisustvo+tzadace+tzavrsni;
	bsuma=b1parc+b2parc+bprisustvo+bzadace+bzavrsni;
	msuma=m1parc+m2parc+mprisustvo+mzadace+mzavrsni;
	if(tsuma>=0 && tsuma<55) brojac_pao++;
	if(bsuma>=0 && bsuma<55) brojac_pao++;
	if(msuma>=0 && msuma<55) brojac_pao++;
	if(brojac_pao==1){
		printf("Dva studenta su polozila.");
	}
	else if(brojac_pao==2){
		printf("Jedan student je polozio.");
	}
	else if(brojac_pao==3){
		printf("Nijedan student nije polozio.");
	}
	else printf("Sva tri studenta su polozila.\n");
	
	if(tsuma>=55 && tsuma<65) b6++;
	if(bsuma>=55 && bsuma<65) b6++;
	if(msuma>=55 && msuma<=65) b6++;
	if(tsuma>=65 && tsuma<75) b7++;
	if(bsuma>=65 && bsuma<75) b7++;
	if(msuma>=65 && msuma<75) b7++;
	if(tsuma>=75 && tsuma<85) b8++;
	if(bsuma>=75 && bsuma<85) b8++;
	if(msuma>=75 && msuma<85) b8++;
	if(tsuma>=85 && tsuma<92) b9++;
	if(bsuma>=85 && bsuma<92) b9++;
	if(msuma>=85 && msuma<92) b9++;
	if(tsuma>=92 && tsuma<100) b10++;
	if(bsuma>=92 && bsuma<100) b10++;
	if(msuma>=92 && msuma<100) b10++;
	
	
	if((b6==1 && b7==1 && b8==1) || (b6==1 && b8==1 && b9==1) || (b6==1 && b7==1 && b9==1) || (b6==1 && b7==1 && b10==1)
	|| (b6==1 && b8==1 && b10==1) || (b7==1 && b8==1 && b9==1) || (b7==1 && b8==1 && b10==1) || (b6==1 && b9==1 && b10==1)
	|| (b7==1 && b9==1 && b10==1)){
		printf("Svaki student ima razlicitu ocjenu.");
		
	}
	
	else if((b6==2 && (b7==1 || b8==1 || b9==1 || b10==1))|| (b7==2 &&(b6==1 || b8==1 || b9==1 || b10==1)) ||
	(b8==2 && (b6==1 || b7==1 || b8==1 || b9==1 || b10==1)) || (b9==2 && (b6==1 || b7==1 || b8==1 || b10==1)) ||
	(b10==2 && (b6==1 || b7==1 || b8==1 || b9==1 ))) {
		printf("Dva od tri studenta imaju istu ocjenu.\n");
	}
	else if(b6==3 || b7==3 || b8==3 || b9==3 || b10==3){
		printf("Sva tri studenta imaju istu ocjenu.");
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	return 0;
}
