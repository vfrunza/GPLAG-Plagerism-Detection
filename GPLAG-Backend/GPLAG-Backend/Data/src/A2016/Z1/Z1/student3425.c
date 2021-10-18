#include <stdio.h>

int main() {
	float b1T,b2T,bpT,bzT,bzavT,b1B,b2B,bpB,bzB,bzavB,b1M,b2M,bpM,bzM,bzavM,ST,SB,SM,xT,xB,xM;
//	printf("Unesi bodove za Tarika \n");
//	printf("Prvi parcijalni ispit:");
	scanf("%f", &b1T);

	scanf("%f", &b2T);

	scanf("%f", &bpT);

	scanf("%f", &bzT);

	scanf("%f", &bzavT);

	scanf("%f", &b1B);

	scanf("%f", &b2B);

	scanf("%f", &bpB);

	scanf("%f", &bzB);

	scanf("%f", &bzavB);

	scanf("%f", &b1M);

	scanf("%f", &b2M);

	scanf("%f", &bpM);

	scanf("%f", &bzM);

	scanf("%f", &bzavM);
	
		if (b1T<=20 && b2T<=20 && bpT<=10 && bzT<=10 && bzavT<=40) { //Ocjene za Tarika
			ST=b1T+b2T+bpT+bzT+bzavT;
			if(ST<55) xT=5;
			if(ST>=55 && ST<65) xT=6;
			if(ST>=65 && ST<75) xT=7;
			if(ST>=75 && ST<85) xT=8;
			if(ST>=85 && ST<92) xT=9;
			if(ST>=92 && ST<100) xT=10;
			
		}
		else printf("Neispravan broj bodova.");
		if (b1B<=20 && b2B<=20 && bpB<=10 && bzB<=10 && bzavB<=40) { //Ocjene za Bojana
			SB=b1B+b2B+bpB+bzB+bzavB;
			if(SB<55) xB=5;
			if(SB>=55 && SB<65) xB=6;
			if(SB>=65 && SB<75) xB=7;
			if(SB>=75 && SB<85) xB=8;
			if(SB>=85 && SB<92) xB=9;
			if(SB>=92 && SB<100) xB=10;
			
		}
		else printf("Neispravan broj bodova.");
		if (b1M<=20 && b2M<=20 && bpM<=10 && bzM<=10 && bzavM<=40) { //Ocjene za Mirzu
			SM=b1M+b2M+bpM+bzM+bzavM;
			if(SM<55) xM=5;
			if(SM>=55 && SM<65) xM=6;
			if(SM>=65 && SM<75) xM=7;
			if(SM>=75 && SM<85) xM=8;
			if(SM>=85 && SM<92) xM=9;
			if(SM>=92 && SM<100) xM=10;
			
		}
		else printf("Neispravan broj bodova.");
	
		if (xT==5 && xB==5 && xM==5 ) printf ("Nijedan student nije polozio.");
		else {
			if ((xT>5 && xB==5 && xM==5) || (xT==55 && xB==5 && xM>5) || (xT==5 && xB>5 && xM==5)) printf ("Jedan student je polozio.");
			if ((xT>5 && xB>5 && xM==5) || (xT==5 && xB>5 && xM>5) || (xT>5 && xB==5 && xM>5)) printf ("Dva studenta su polozila.");
			if (xT>5 && xB>5 && xM>5){
				printf ("Sva tri studenta su polozila. \n");	
				if (xT==xB && xB==xM) printf ("Sva tri studenta imaju istu ocjenu.");
					else {
						if ((xT==xB)||(xB==xM)||(xT==xM)) printf ("Dva od tri studenta imaju istu ocjenu.");
					}
				if (xT!=xB && xB!=xM) printf ("Svaki student ima razlicitu ocjenu.");
			} 
		}
	
		return 0;
}