#include <stdio.h>
#define n_rkkk 'Restoran "Kod konja i konjusara"'
#define n_fft 'Fast food "Trovac"'
#define n_bl 'Bistro "Lorelei"'
#define P_RKKK 6.8 /*cijena pizze u restoranu kod konJa i konjusara*/
#define P_FFT 8.0/*cijena pizze u fast food trovacu*/
#define P_BL 5.3/*cijena pizze u bistro lorelei*/ 
#define H_RKKK 3.3/*cijena hamburgera u restoranu kod konja i konjusara*/
#define H_FFT 3.0/*cijena hamburgera u fast food trovacu*/
#define H_BL 5.0/*cijena hamburgera u bistro lorelei*/
#define C_RKKK 5.0/*cijena cevapa u restoranu kod konja i konjusara*/
#define C_FFT 3.9/*cijena cevapa u fast food trovacu*/
#define C_BL 6.0/*cijena cevapa u bistro lorelei*/

int main() {
	char tarik,bojan,mirza,novi_red;
	float s_rkkk,s_fft,s_bl;
	printf("Unesite jelo za Tarika: ");
	scanf ("%c",&tarik);
	scanf ("%c",&novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf ("%c",&bojan);
	scanf ("%c",&novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c",&mirza);
	scanf("%c",&novi_red);
	
	if (tarik=='P' && bojan=='P' && mirza=='P') {
		if (P_RKKK<P_FFT && P_RKKK<P_BL){
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", 3*P_RKKK);
		}
		else if (P_FFT<P_RKKK && P_FFT<P_BL){
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n" , 3*P_FFT);
		}
		else {
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",3*P_BL);
		}
		if(P_RKKK>P_FFT || P_RKKK>P_BL) {
			if ((3*P_RKKK*0.9)<3*P_FFT && (3*P_RKKK*0.9)<3*P_BL) {
				printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", 3*P_RKKK*0.9);
			}
		}
	}
	
	else if ((tarik=='P' && bojan=='P' && mirza=='C') || (tarik=='P' && bojan=='C' && mirza=='P') || (tarik=='C' && bojan=='P' && mirza=='P') ) { 
		
		s_rkkk=2*P_RKKK+C_RKKK;
		s_fft=2*P_FFT+C_FFT;
		s_bl=2*P_BL+C_BL; 
		
		if (s_rkkk<s_fft && s_rkkk<s_bl){
			printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", s_rkkk );
		}
		else if (s_fft<s_rkkk && s_fft<s_bl) {
			printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", s_fft);
		}
		else  {
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", s_bl);
		}
		if (s_rkkk>s_fft || s_rkkk>s_bl){
			if ((0.9*P_RKKK+P_RKKK+C_RKKK)<s_fft && (0.9*P_RKKK+P_RKKK+C_RKKK)<s_bl){
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",0.9*P_RKKK+P_RKKK+C_RKKK);
			}
		}
	}
	
else if ((tarik=='P' && bojan=='P' && mirza=='H') || (tarik=='P' && bojan=='H' && mirza=='P') || (tarik=='H' && bojan=='P' && mirza=='P') ) {
	
		s_rkkk=2*P_RKKK+H_RKKK;
		s_fft=2*P_FFT+H_FFT;
		s_bl=2*P_BL+H_BL; 
		
		if (s_rkkk<s_fft && s_rkkk<s_bl){
			printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", s_rkkk );
		}
		else if (s_fft<s_rkkk && s_fft<s_bl) {
			printf ("Najjeftiniji je \"Fast-food Trovac\" (%.2f KM.)\n", s_fft);
		}
		else  {
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", s_bl);
		}
		
		if (s_rkkk>s_fft || s_rkkk>s_bl){
			if ((0.9*P_RKKK+ 0.9*P_RKKK+H_RKKK)<s_fft && (0.9*P_RKKK+0.9*P_RKKK+H_RKKK)<s_bl){
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",0.9*P_RKKK+0.9*P_RKKK+H_RKKK);
			}
		}
    } 
    
    else if ((tarik=='P' && bojan=='C' && mirza=='H') || (tarik=='H' && bojan=='P' && mirza=='C') || (tarik=='C' && bojan=='H' && mirza=='P') ) {
    	
    	s_rkkk=P_RKKK+H_RKKK+C_RKKK;
    	s_fft=P_FFT+H_FFT+C_FFT;
    	s_bl=P_BL+H_BL+C_BL;
    	
    	if (s_rkkk<s_fft && s_rkkk<s_bl){
			printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", s_rkkk );
		}
		else if (s_fft<s_rkkk && s_fft<s_bl) {
			printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", s_fft);
		}
		else  {
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", s_bl);
		}
		if (s_rkkk>s_fft || s_rkkk>s_bl){
			if ((0.9*P_RKKK+H_RKKK+C_RKKK)<s_fft && (0.9*P_RKKK+H_RKKK+C_RKKK)<s_bl){
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",0.9*P_RKKK+H_RKKK+C_RKKK);
			}
		}
    } 
    
    else if (tarik=='H' && bojan=='H' && mirza=='H') {
		if (H_RKKK<H_FFT && H_RKKK<H_BL){
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n ", 3*H_RKKK);
		}
		else if (H_FFT<H_RKKK && H_FFT<H_BL){
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n" , 3*H_FFT);
		}
		else {
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n ",3*H_BL);
		}
		if(H_RKKK>H_FFT || H_RKKK>H_BL) {
			if ((3*H_RKKK*0.9)<3*H_FFT && (3*H_RKKK*0.9)<3*H_BL) {
				printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", 3*H_RKKK*0.9);
			}
		}
	}
	
	else if ((tarik=='H' && bojan=='H' && mirza=='P') || (tarik=='P' && bojan=='H' && mirza=='H') || (tarik=='H' && bojan=='P' && mirza=='H') ) {
		
		s_rkkk=2*H_RKKK+P_RKKK;
		s_fft=2*H_FFT+P_FFT;
		s_bl=2*H_BL+P_BL;
		
		if (s_rkkk<s_fft && s_rkkk<s_bl){
			printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", s_rkkk );
		}
		else if (s_fft<s_rkkk && s_fft<s_bl) {
			printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", s_fft);
		}
		else  {
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", s_bl);
		}
		if (s_rkkk>s_fft || s_rkkk>s_bl){
			if ((0.9*P_RKKK+ 2*H_RKKK)<s_fft && (0.9*P_RKKK+ 2*H_RKKK)<s_bl){
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",0.9*P_RKKK+ 2*H_RKKK);
			}
		}
	}
	
	else if  ((tarik=='H' && bojan=='H' && mirza=='C') || (tarik=='C' && bojan=='H' && mirza=='H') || (tarik=='H' && bojan=='P' && mirza=='H') ) {
		
		s_rkkk=2*H_RKKK+C_RKKK;
		s_fft=2*H_FFT+C_FFT;
		s_bl=2+H_BL+C_BL; 
		
		if (s_rkkk<s_fft && s_rkkk<s_bl){
			printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", s_rkkk );
		}
		else if (s_fft<s_rkkk && s_fft<s_bl) {
			printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", s_fft);
		}
		else  {
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", s_bl);
		}
		if (s_rkkk>s_fft || s_rkkk>s_bl){
			if ((0.9*C_RKKK + 2*H_RKKK)<s_fft && (0.9*C_RKKK+ 2*H_RKKK)<s_bl){
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",0.9*C_RKKK+ 2*H_RKKK);
			}
		}
	} 
	
	else if (tarik=='C' && bojan=='C' && mirza=='C') {
		
		if (C_RKKK<C_FFT && C_RKKK<C_BL){
			printf("Najjeftiniji je restoran \"Kod konja i konjusara\" (%.2f KM).\n", 3*C_RKKK);
		}
		else if (C_FFT<C_RKKK && C_FFT<C_BL){
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n" , 3*C_FFT);
		}
		else {
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",3*C_BL);
		}
		if(C_RKKK>C_FFT || C_RKKK>C_BL) {
			if ((3*C_RKKK*0.9)<3*C_FFT && (3*C_RKKK*0.9)<3*C_BL) {
				printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM). ", 3*C_RKKK*0.9);
			}
		}
	}	
	
	else if ((tarik=='C' && bojan=='C' && mirza=='H') || (tarik=='H' && bojan=='C' && mirza=='C') || (tarik=='C' && bojan=='H' &&  mirza=='C') ) {
		
		s_rkkk=2*C_RKKK+H_RKKK;
		s_fft=2*C_FFT+H_FFT;
		s_bl=2*C_BL+H_BL; 
		
		if (s_rkkk<s_fft && s_rkkk<s_bl){
			printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", s_rkkk );
		}
		else if (s_fft<s_rkkk && s_fft<s_bl) {
			printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", s_fft);
		}
		else  {
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", s_bl);
		}

		if (s_rkkk>s_fft || s_rkkk>s_bl){
			if ((0.9*C_RKKK+C_RKKK+H_RKKK)<s_fft && (0.9*C_RKKK+C_RKKK+H_RKKK)<s_bl){
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",0.9*C_RKKK+C_RKKK+H_RKKK);
			}
		}
	}
	
	else if ((tarik=='C' && bojan=='C' && mirza=='P') || (tarik=='P' && bojan=='C' && mirza=='C') || (tarik=='C' && bojan=='P' &&  mirza=='C') ) {
	
		s_rkkk=2*C_RKKK+P_RKKK;
		s_fft=2*C_FFT+P_FFT;
		s_bl=2*C_BL+P_BL;
		
		if (s_rkkk<s_fft && s_rkkk<s_bl){
			printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", s_rkkk );
		}
		else if (s_fft<s_rkkk && s_fft<s_bl) {
			printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", s_fft);
		}
		else  {
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", s_bl);
		}
		if (s_rkkk>s_fft || s_rkkk>s_bl){
			if ((0.9*P_RKKK+2*C_RKKK)<s_fft && (0.9*P_RKKK+2*C_RKKK)<s_bl){
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",0.9*P_RKKK+ 2*C_RKKK);
			}
		}
	}
//}

	return 0;
}