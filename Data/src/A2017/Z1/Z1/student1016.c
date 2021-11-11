#include <stdio.h>
#define RKKKP 6.80
#define RKKKH 3.30
#define RKKKC 5.00
#define FFTP  8.00
#define FFTH 3.00
#define FFTC 3.90
#define BLP 5.30
#define BLH 5.00
#define BLC 6.00
int main() {
	char T,B,M,nered;
	float CR,CRP,CF,CB,MIN=0;
	printf("Unesite jelo za Tarika: ");
	scanf ("%c",&T);
	scanf ("%c",&nered);
	printf ("Unesite jelo za Bojana: ");
	scanf ("%c",&B);
	scanf ("%c",&nered);
	printf ("Unesite jelo za Mirzu: ");
	scanf("%c",&M);
	scanf ("%c",&nered);
	  if (T=='C' && B=='C' && M=='C'){CRP=RKKKC*3-(RKKKC*0.10);CR=RKKKC*3;CF=FFTC*3;CB=BLC*3;}
	  if (T=='H' && B=='H' && M=='H'){CR=RKKKH*3;CF=FFTH*3;CB=BLH*3;CRP=RKKKH*3-(RKKKH*0.10);}
	  if (T=='P' && B=='P' && M=='P'){CR=RKKKP*3;CF=FFTP*3;CB=BLP*3;CRP=RKKKP*3-(RKKKP*0.10);}	
	  if (T=='P' && B=='C' && M=='P'){CR=RKKKC+(RKKKP*2);CF=FFTC+(FFTP*2);CB=(BLP*2)+BLC;CRP=RKKKC+(RKKKP*2)-(RKKKP*0.10);}
	  if (T=='P' && B=='H' && M=='P'){CR=RKKKH+(RKKKP*2);CF=FFTH+(FFTP*2);CB=(BLP*2)+BLH;CRP=RKKKH+(RKKKP*2)-(RKKKP*0.10);}
	  if (T=='C' && B=='P' && M=='P'){CR=RKKKC+(RKKKP*2);CF=FFTC+(FFTP*2);CB=(BLP*2)+BLC;CRP=RKKKC+(RKKKP*2)-(RKKKP*0.10);}
	  if (T=='C' && B=='H' && M=='H'){CR=RKKKC+(RKKKH*2);CF=FFTC+(FFTH*2);CB=(BLH*2)+BLC;CRP=RKKKC+(RKKKH*2)-(RKKKC*0.10);}
	  if (T=='C' && B=='H' && M=='P'){CR=RKKKC+RKKKH+RKKKP;CF=FFTC+FFTH+FFTP;CB=BLH+BLC+BLP;CRP=RKKKC+RKKKH+RKKKP-(RKKKP*0.10);}
	  if (T=='C' && B=='P' && M=='H'){CR=RKKKC+RKKKH+RKKKP;CF=FFTC+FFTH+FFTP;CB=BLH+BLC+BLP;CRP=RKKKC+RKKKH+RKKKP-(RKKKP*0.10);}
	  if (T=='P' && B=='C' && M=='C'){CR=RKKKP+(RKKKC*2);CF=FFTP+(FFTC*2);CB=BLP+(BLC*2);CRP=(RKKKC*2)+RKKKP-(RKKKP*0.10);}
	  if (T=='P' && B=='H' && M=='H'){CR=RKKKP+(RKKKH*2);CF=FFTP+(FFTH*2);CB=BLP+(BLH*2);CRP=(RKKKH*2)+RKKKP-(RKKKP*0.10);}
	  if (T=='P' && B=='C' && M=='H'){CR=RKKKC+RKKKH+RKKKP;CF=FFTC+FFTH+FFTP;CB=BLH+BLC+BLP;CRP=RKKKC+RKKKH+RKKKP-(RKKKP*0.10);}
	  if (T=='P' && B=='H' && M=='C'){CR=RKKKC+RKKKH+RKKKP;CF=FFTC+FFTH+FFTP;CB=BLH+BLC+BLP;CRP=RKKKC+RKKKH+RKKKP-(RKKKP*0.10);}
	  if (T=='H' && B=='P' && M=='P'){CR=RKKKH+(RKKKP*2);CF=FFTH+(FFTP*2);CB=BLH+(BLP*2);CRP=(RKKKP*2)+RKKKH-(RKKKP*2*0.10);}
	  if (T=='H' && B=='C' && M=='C'){CR=RKKKH+(RKKKC*2);CF=FFTH+(FFTC*2);CB=BLH+(BLC*2);CRP=(RKKKC*2)+RKKKH-(RKKKC*0.10);}
	  if (T=='H' && B=='P' && M=='C'){CR=RKKKC+RKKKH+RKKKP;CF=FFTC+FFTH+FFTP;CB=BLH+BLC+BLP;CRP=RKKKC+RKKKH+RKKKP-(RKKKP*0.10);}
	  if (T=='H' && B=='C' && M=='P'){CR=RKKKC+RKKKH+RKKKP;CF=FFTC+FFTH+FFTP;CB=BLH+BLC+BLP;CRP=RKKKC+RKKKH+RKKKP-(RKKKP*0.10);}
	  if (T=='C' && B=='P' && M=='C'){CR=RKKKP+(RKKKC*2);CF=FFTP+(FFTC*2);CB=(BLC*2)+BLP;CRP=RKKKP+(RKKKC*2)-(RKKKP*0.10);}
	  if (T=='C' && B=='H' && M=='C'){CR=RKKKH+(RKKKC*2);CF=FFTH+(FFTC*2);CB=(BLC*2)+BLH;CRP=RKKKH+(RKKKC*2)-(RKKKC*0.10);}
	  if (T=='H' && B=='C' && M=='H'){CR=RKKKC+(RKKKH*2);CF=FFTC+(FFTH*2);CB=(BLP*2)+BLC;CRP=RKKKC+(RKKKH*2)-(RKKKC*0.10);}
	  if (T=='H' && B=='P' && M=='H'){CR=RKKKP+(RKKKH*2);CF=FFTP+(FFTH*2);CB=(BLH*2)+BLP;CRP=RKKKP+(RKKKH*2)-(RKKKP*0.10);}
	  if (T=='C' && B=='C' && M=='P'){CR=RKKKP+(RKKKC*2);CF=FFTP+(FFTC*2);CB=BLP+(BLC*2);CRP=(RKKKC*2)+RKKKP-(RKKKP*0.10);}
	  if (T=='C' && B=='C' && M=='H'){CR=RKKKH+(RKKKC*2);CF=FFTH+(FFTC*2);CB=BLH+(BLC*2);CRP=(RKKKC*2)+RKKKH-(RKKKC*0.10);}
	  if (T=='P' && B=='P' && M=='C'){CR=RKKKC+(RKKKP*2);CF=FFTC+(FFTP*2);CB=BLC+(BLP*2);CRP=(RKKKP*2)+RKKKC-(RKKKP*0.10);}
	  if (T=='P' && B=='P' && M=='H'){CR=RKKKP+(RKKKC*2);CF=FFTH+(FFTP*2);CB=BLH+(BLP*2);CRP=(RKKKP*2)+RKKKH-(RKKKP*0.10);}
	  if (T=='H' && B=='H' && M=='C'){CR=RKKKC+(RKKKH*2);CF=FFTC+(FFTH*2);CB=BLC+(BLH*2);CRP=(RKKKH*2)+RKKKC-(RKKKC*0.10);}
	  if (T=='H' && B=='H' && M=='P'){CR=RKKKP+(RKKKH*2);CF=FFTP+(FFTH*2);CB=BLP+(BLH*2);CRP=(RKKKH*2)+RKKKP-(RKKKP*0.10);}
	   if (T==B && B==M){CRP=CR-CR*0.10;}
	   if (CR<CF && CR<CB){printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",CR);}
	   if (CF<CB && CF<CR){printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",CF),MIN=CF;}
	   if (CB<CF && CB<CR){printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",CB),MIN=CB;}
	   if (CRP<MIN){printf ("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",CRP);}
	  // if (CRP<CF && CR>CF){printf ("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",CRP);}
	  // if (CRP<CB && CR>CB){printf ("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",CRP);}
	 

	return 0;
}
