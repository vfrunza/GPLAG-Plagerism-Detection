#include <stdio.h>
#include <math.h>
int main() {
	double TR,BR,MR,RC,TF,BF,MF,FC,TB,BB,MB,BC,a;
	char T,B,M,novi;
	printf("Unesite jelo za Tarika: ");
	scanf("%c",&T);
	scanf("%c",&novi);
	printf("Unesite jelo za Bojana: ");
	scanf("%c",&B);
	scanf("%c",&novi);	
	printf("Unesite jelo za Mirzu: ");
	scanf("%c",&M);
	scanf("%c",&novi);
	
	a = 0;
	if (T == 'P') {
		TF = 8.0;
	} else if (T == 'H') {
		TF = 3.0;
	} else if (T == 'C') {
		TF = 3.9;
	}
	if (B == 'P') {
		BF = 8.0;
	} else if (B == 'H') {
		BF = 3.0;
	} else if (B == 'C') {
		BF = 3.9;
	}
	if (M == 'P') {
		MF = 8.0;
	} else if (M == 'H') {
		MF = 3.0;
	} else if ( M == 'C') {
		MF = 3.9;
	}
	FC = TF + MF + BF;
	
	if (T == 'P') {
		TB = 5.3;
	} else if (T == 'H') {
		TB = 5.0;
	} else if (T == 'C') {
		TB = 6.0;
	}
	if (B == 'P') {
		BB = 5.3;
	} else if (B == 'H') {
		BB = 5.0;
	} else if (B == 'C') {
		BB = 6.0;
	}
	if (M == 'P') {
		MB = 5.3;
	} else if (M == 'H') {
		MB = 5.0;
	} else if ( M == 'C') {
		MB = 6.0;
	}
	BC = TB + MB + BB;
	
	if (T == 'P') {
		TR = 6.8;
	} else if (T == 'H') {
		TR = 3.3;
	} else if (T == 'C') {
		TR = 5.0;
	}
	if (B == 'P') {
		BR = 6.8;
	} else if (B == 'H') {
		BR = 3.3;
	} else if (B == 'C') {
		BR = 5.0;
	}
	if (M == 'P') {
		MR = 6.8;
	} else if (M == 'H') {
		MR = 3.3;
	} else if ( M == 'C') {
		MR = 5.0;
	}
	RC = TR + BR + MR;
	
	if (RC < FC && RC < BC) {
		printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",RC);
		a = 1 ;
	} else {
			if ((M == 'P' && B == 'P' && T == 'P') || (M == 'C' && B == 'C' && T == 'C') || (M == 'H' && B == 'H' && T == 'H')) {
				RC = RC * 0.9;
			} else if (M == 'P' && B == 'P' && T != 'P') {
				RC = (MR * 0.9) + (BR * 0.9) + TR;
			} else if (T == 'P' && B == 'P' && M != 'P') {
				RC = TR * 0.9 + BR * 0.9 + MR;
			} else if (M == 'P' && T == 'P' && B != 'P') {
				RC = TR + BR * 0.9 + MR * 0.9;
			} else if (M == 'P' && B != 'P' && T != 'P') {
				RC = MR * 0.9 + BR + TR;
			} else if (T == 'P' && B != 'P' && M != 'P') {
				RC = TR * 0.9 + BR  + MR;
			} else if (B == 'P' && M != 'P' && T != 'P') {
				RC = TR + BR * 0.9 + MR;
			} else if (M =='C' && B == 'C' && T != 'C') {
				RC = MR * 0.9 + BR * 0.9 + TR;
			} else if (T == 'C' && B == 'C' && M != 'C') {
				RC = TR * 0.9 + BR * 0.9 + MR;
			} else if (M == 'C' && T == 'C' && B != 'C') {
				RC = TR + BR * 0.9 + MR * 0.9;
			} else if (M == 'C' && B != 'C' && T != 'C') {
				RC = MR * 0.9 + BR + TR;
			} else if (T == 'C' && B != 'C' && M != 'C') {
				RC = TR * 0.9 + BR  + MR;
			} else if (B == 'C' && M != 'C' && T != 'C') {
				RC = TR + BR * 0.9 + MR;
			}
	}
	
	if (RC < FC && FC < BC && a == 0) {
				printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",FC);
				printf ("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",RC);
				
			} else if (FC < BC && a == 0) {
				printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",FC);
				
			} else if (RC < BC && BC < FC && a == 0) {
				printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",BC);
				printf ("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",RC);
			} else if(a == 0) {
				printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",BC);
			}
	
	return 0;
}
