#include <stdio.h>


int main() {
	char T, B, M, H, P, C, navodnici;
	navodnici='"';
	int BRP=0, BRH=0, BRC=0;
	double kk, kk1, trovac, bistro, pp; 
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &T);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &B);
	scanf("%c", &B);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &M);
	scanf("%c", &M);
	
 if  (T=='H')  BRH++;  
 else if(T=='P') BRP++;
 else if(T=='C') BRC++;
 if(B=='H') BRH++;
  else if(B=='P') BRP++;
   else if(B=='C') BRC++;
   if(M=='H') BRH++;
   else if(M=='P') BRP++;
   else if(M=='C') BRC++;
 kk=BRP*6.8+BRH*3.3+BRC*5;
 trovac=BRP*8+BRH*3+BRC*3.9;
 bistro=BRP*5.30+BRH*5.00+BRC*6;
  if(BRP*6.8>BRH*3.3 && BRP*6.8>BRC*5)
 pp=BRP*6.8;
 if(BRH*3.3>BRP*6.8 && BRH*3.3>BRC*5)
 pp=BRH*3.3;
 if(BRC*5>BRP*6.8 && BRC*5>BRH*3.3)
 pp=BRC*5;
 kk1=kk-0.1*pp;
{
 if (trovac<bistro && trovac<kk) 
 {
   printf("Najjeftiniji je Fast-food %cTrovac%c (%.2lf KM).", navodnici, navodnici,trovac);
   if(kk1<bistro && kk1<trovac)printf("\nSa popustom bi Restoran bio jeftiniji (%.2lf KM).", kk1);
 }
 
 if(bistro<trovac && bistro<kk) 
 {
   printf("Najjeftiniji je Bistro %cLorelei%c (%.2lf KM).",navodnici,navodnici, bistro);
   if(kk1<bistro && kk1<trovac)printf("\nSa popustom bi Restoran bio jeftiniji (%.2lf KM).", kk1);
  
 }
 if(kk<trovac && kk<bistro) printf("Najjeftiniji je Restoran %cKod konja i konjusara%c (%.2lf KM).",navodnici,navodnici, kk);
 

  
}
	
	return 0;
}
