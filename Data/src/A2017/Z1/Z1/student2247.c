#include <stdio.h>
#define KKIKP 6.80 
#define KKIKH 3.30
#define KKIKC 5.00
#define TP 8.00
#define TH 3.00
#define TC 3.90
#define LP 5.30
#define LH 5.00
#define LC 6.00
int main() {
    char jelot, jelob, jelom;
    float cijenar1, popustr1, cijenar2, popustr2, cijenar3, popustr3, restoran, fastfood, bistro;
	printf ("Unesite jelo za Tarika: ");
	scanf ("%c", &jelot);
	printf ("Unesite jelo za Bojana: ");
	scanf (" %c", &jelob);
	printf ("Unesite jelo za Mirzu: ");
	scanf (" %c", &jelom);
	
	popustr1=KKIKH*0.1;
	cijenar1=KKIKH-popustr1;
	popustr2=KKIKP*0.1;
	cijenar2=KKIKP-popustr2;
	popustr3=KKIKC*0.1;
	cijenar3=KKIKC-popustr3;
    
	
	if (jelot=='H' && jelob=='H' && jelom=='H'){
		restoran=(KKIKH+KKIKH+KKIKH);
		fastfood=(TH+TH+TH);
		bistro=(LH+LH+LH);
	if (restoran<fastfood && restoran<bistro) printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", restoran);
	else if (bistro<fastfood && bistro<restoran) printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", bistro);
	else if (fastfood<restoran && fastfood<bistro) printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", TH+TH+TH);
	if ((cijenar1*3)<(TH+TH+TH)) printf ("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijenar1*3); }
	
	
	    
	else if (jelot=='P' && jelob=='P' && jelom=='P'){
		restoran=(KKIKP+KKIKP+KKIKP);
		fastfood=(TP+TP+TP);
		bistro=(LP+LP+LP);
	if (restoran<fastfood && restoran<bistro) printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", restoran);
	else if (fastfood<restoran && fastfood<bistro) printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", fastfood);
	else if(bistro<fastfood && bistro<restoran)
		printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", LP+LP+LP);
	if ((cijenar2*3)<(LP+LP+LP)) printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", cijenar2*3); }
	
	
	else if (jelot=='C' && jelob=='C' && jelom=='C'){
		restoran=(KKIKC+KKIKC+KKIKC);
		fastfood=(TC+TC+TC);
		bistro=(LC+LC+LC);
	if (restoran<fastfood && restoran<bistro) printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", restoran);
	else if (bistro<fastfood && bistro<restoran) printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", bistro);
	else if (fastfood<restoran && fastfood<bistro)
		printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", TC+TC+TC);
	if ((cijenar3*3)<(TC+TC+TC)) printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", cijenar3*3);}
	
	
	else if (jelot=='H'&& jelob=='P' && jelom=='P'){
	restoran=(KKIKH+KKIKP+KKIKP);
	bistro=(LH+LP+LP);
	fastfood=(TH+TP+TP);
	if (restoran<bistro && restoran<fastfood) printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", restoran);
	else if (fastfood<restoran && fastfood<bistro) printf ("Najjeftiniji je Fast-food \"Trovac\"(%.2f KM).", fastfood);
	else if (bistro<fastfood && bistro<restoran)
		printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", LH+LP+LP);
	if ((cijenar2*2+KKIKH)<(LH+LP+LP)) printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", cijenar2*2+KKIKH);}
	
	else if (jelot=='H'&& jelob=='P' && jelom=='C') {
	restoran=(KKIKH+KKIKP+KKIKC);
	bistro=(LH+LP+LC);
	fastfood=(TH+TP+TC);
	if (restoran<fastfood && restoran<bistro) printf ("Najjeftiniji je restoran \"Kod konja i konjusara\" (%.2f KM).", restoran);
	else if (bistro<fastfood && bistro<restoran)printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", bistro);
	else if (fastfood<restoran && fastfood<bistro)
		printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", TH+TP+TC);
	if ((cijenar2+KKIKH+KKIKC)<(TH+TP+TC)) printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", cijenar2+KKIKH+KKIKC); }
	
	
	else if (jelot=='H' && jelob=='C' && jelom=='C'){
	restoran=(KKIKH+KKIKC+KKIKC);
	bistro=(LH+LC+LC);
	fastfood=(TH+TC+TC);
	if (restoran<fastfood && restoran<bistro)printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", restoran);
	else if (bistro<restoran && bistro<fastfood)printf ("Najjeftiniji je Bistro \"Lorelei\"(%.2f KM).", bistro);
	else if (fastfood<restoran && fastfood<bistro)
	 printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", TH+TC+TC);}
	 
	 
	else if (jelot=='P' && jelob=='H' && jelom=='H'){
	restoran=(KKIKP+KKIKH+KKIKH);
	bistro=(LP+LH+LH);
	fastfood=(TP+TH+TH);
	if (bistro<restoran && bistro<fastfood)printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", bistro);
	else if (fastfood<restoran && fastfood<bistro)printf ("Najjeftiniji je Fast-food \"Trovac\"(%.2f KM).", fastfood);
	else if (restoran<fastfood && restoran<bistro)
		printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",KKIKP+KKIKH+KKIKH );}
		
		
	else if (jelot=='P' && jelob=='C' && jelom=='C'){
	restoran=(KKIKP+KKIKC+KKIKC);
	bistro=(LP+LC+LC);
	fastfood=(TC+TP+TC);
	if (restoran<fastfood && restoran<bistro) printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\"(%.2f KM).", restoran);
	else if (bistro<fastfood && bistro<restoran)printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", bistro);
	else if (fastfood<restoran && fastfood<bistro)
	 printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", TP+TC+TC);}
	 
	 
	else if (jelot=='C' && jelob=='H' && jelom=='H'){
	restoran=(KKIKH+KKIKC+KKIKH);
	bistro=(LH+LH+LC);
	fastfood=(TH+TH+TC);
	if (restoran<fastfood && restoran<bistro) printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",restoran);
	else if (bistro<fastfood && bistro<restoran)printf ("Najjeftiniji je Bistro \"Lorelei\"(%.2f KM).", bistro);
	else if (fastfood<restoran && fastfood<bistro)
	 printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", TC+TH+TH);}
	 
	else if (jelot=='C' && jelob=='P' && jelom=='P'){
	restoran=(KKIKC+KKIKP+KKIKP);
	bistro=(LC+LP+LP);
	fastfood=(TC+TP+TP);
	if (restoran<bistro && restoran<fastfood) printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",restoran);
	else if (fastfood<restoran && fastfood<bistro) printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", fastfood);
	else if (bistro<restoran && bistro<fastfood)
	 printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", LC+LP+LP);}
	 
	 
	else if (jelot=='H' && jelob=='H' && jelom=='P'){
	restoran=(KKIKH+KKIKH+KKIKP);
	bistro=(LP+LH+LH);
	fastfood=(TH+TH+TP);
	if (bistro<restoran && bistro<fastfood) printf("Najjeftiniji je BIstro \"Lorelei\" (%.2f KM).", bistro);
	else if (fastfood<restoran && fastfood<bistro) printf ("Najjeftiniji je Fast-food \"Trovac\"(%.2f KM).", fastfood);
	else if (restoran<fastfood&& restoran<bistro)
	 printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",KKIKP+KKIKH+KKIKH );}
	 
	 
	else if (jelot=='C'&& jelob=='H' && jelom=='P'){
	restoran=(KKIKC+KKIKH+KKIKP);
	bistro=(LC+LP+LH);
	fastfood=(TC+TH+TP);
	if (restoran<bistro && restoran<fastfood) printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",restoran);
	else if (bistro<restoran && bistro<fastfood)printf ("Najjeftiniji je Bistro \"Lorelei\"(%.2f KM).", bistro);
	else if (fastfood<bistro && fastfood<restoran)
		printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", TH+TP+TC);
		 if((cijenar2+KKIKH+KKIKC)<(TH+TP+TC)) printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", cijenar2+KKIKH+KKIKC);}
		 
		 
	else if (jelot=='C' && jelob=='P' && jelom=='C'){
	restoran=(KKIKC+KKIKP+KKIKC);
	bistro=(LC+LP+LC);
	fastfood=(TC+TP+TC);
	if (restoran<fastfood && restoran<bistro) printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",restoran);
	else if (bistro<fastfood && bistro<restoran) printf ("Najjeftiniji je Bistro \"Loreleiˇ\" (%.2f KM).", bistro);
	else if (fastfood<bistro && fastfood <restoran)
	printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", TP+TC+TC);}
	
	else if (jelot=='P' && jelob=='P' && jelom=='C'){
	restoran=(KKIKP+KKIKP+KKIKC);
	bistro=(LP+LP+LC);
	fastfood=(TP+TP+TC);
	if (restoran<bistro && restoran<fastfood)printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", restoran);
	else if (fastfood<restoran && fastfood<bistro) printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", fastfood);
	else if (bistro<fastfood && bistro<restoran)
	 printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", LC+LP+LP);}
	 
	 
	else if (jelot=='P' && jelob=='C' && jelom=='H'){
	restoran=(KKIKP+KKIKC+KKIKH);
	bistro=(LP+LC+LH);
	fastfood=(TP+TC+TH);
	if (restoran<bistro && restoran<fastfood)printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",restoran);
	else if (bistro<restoran && bistro<fastfood) printf ("Najjeftiniji je Bistro \"Lorelei\"(%.2f KM).", bistro);
	else if (fastfood<restoran && fastfood<bistro)
	printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", TP+TC+TH);
	if ((cijenar2+KKIKH+KKIKC)<(TP+TC+TH)) printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", cijenar2+KKIKH+KKIKC);}
	return 0;
}




