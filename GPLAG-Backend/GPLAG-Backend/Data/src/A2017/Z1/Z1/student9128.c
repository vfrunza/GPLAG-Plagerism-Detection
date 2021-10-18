#include <stdio.h>

int main() {
	char t,b,m,n='\n';
	float pr=6.8, pf=8, pb=5.3, hr=3.3, hf=3, hb=5, cr=5, cf=3.9, cb=6, sumapppR,sumapppF, sumapppB, sumapphR, sumapphF, sumapphB, sumappcR, sumappcF, sumappcB, sumaphhR, sumaphhF, sumaphhB, sumapccR, sumapccF, sumapccB, sumapchR, sumapchF, sumapchB, sumahhcR, sumahhcF, sumahhcB, sumahccR, sumahccF, sumahccB, sumacccR, sumacccF, sumacccB, sumahhhR, sumahhhF, sumahhhB; 

	printf("Unesite jelo za Tarika: ");
	scanf("%c", &t);
	scanf("%c", &n);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &b);
	scanf("%c", &n);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &m);
	scanf("%c", &n);
	
	sumapppR=pr*3;
	sumapppF=pf*3;
	sumapppB=pb*3;
	
	sumapphR=pr+pr+hr;
	sumapphF=pf+pf+hf;
	sumapphB=pb+pb+hb;
	
	sumappcR=pr+pr+cr;
	sumappcF=pf+pf+cf;
	sumappcB=pb+pb+cb;
	
	sumaphhR=pr+hr+hr;
	sumaphhF=pf+hf+hf;
	sumaphhB=pb+hb+hb;
	
	sumapccR=pr+cr+cr;
	sumapccF=pf+cf+cf;
	sumapccB=pb+cb+cb;
	
	sumapchR=pr+cr+hr;
	sumapchF=pf+cf+hf;
	sumapchB=pb+cb+hb;
	
	sumahhcR=hr+hr+cr;
	sumahhcF=hf+hf+cf;
	sumahhcB=hb+hb+cb;
	
	sumahccR=hr+cr+cr;
	sumahccF=hf+cf+cf;
	sumahccB=hb+cb+cb;
	
	sumacccR=cr*3;
	sumacccF=cf*3;
	sumacccB=cb*3;
	
	sumahhhR=hr*3;
	sumahhhF=hf*3;
	sumahhhB=hb*3;
	
	if(t=='P' && b=='P' && m=='P') {
		if(sumapppR<=sumapppF && sumapppR<=sumapppB) {
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", sumapppR);
		}
		if(sumapppF<=sumapppR && sumapppF<=sumapppB) {
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", sumapppF);
		}
		if(pr+pr+(9/10)*pr<sumapppF) {
				printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", pr+pr+(9/10));
			}
		
		if(sumapppB<=sumapppF && sumapppB<=sumapppR) {
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", sumapppB);
			if((9*sumapppR)/10<sumapppB) {
				printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 9*sumapppR/10);
			}
		}
	}
	if((t=='P' && b=='P' && m=='H') || (t=='P' && b=='H' && m=='P') || (t=='H' && b=='P' && m=='P')) {
		if(sumapphR<=sumapphF && sumapphR<=sumapphB) {
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", sumapphR);
		}
		if(sumapphF<=sumapphR && sumapphF<=sumapphB) {
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", sumapphF);
			if(pr+(9./10)*pr+hr<sumapphF) {
				printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", pr+(9./10)*pr+hr);
			}
		}
		if(sumapphB<=sumapphF && sumapphB<=sumapphR) {
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", sumapphB);
		}	if((9./10)*pr+(9./10)*pr+hr<sumapphB) {
				printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", (9./10)*pr+(9./10)*pr+hr);
			}
		
	}
	if((t=='P' && b=='P' && m=='C') || (t=='P' && b=='C' && m=='P') || (t=='C' && b=='P' && m=='P')) {
		if(sumappcR<=sumappcF && sumappcR<=sumappcB) {
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", sumappcR);
		}
		if(sumappcF<=sumappcR && sumappcF<=sumappcB) {
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", sumappcF);
			if((9*sumappcR)/10<sumapphF) {
				printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 9*sumappcR/10);
			}
		}
		if(sumappcB<=sumappcR && sumappcB<=sumappcF) {
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", sumappcB);
			if((9*sumappcR)/10<sumappcB) {
				printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 9*sumappcR/10);
			}
		}
	}
	if((t=='P' && b=='H' && m=='H') || (t=='H' && b=='H' && m=='P') || (t=='H' && b=='P' && m=='H')) {
		if(sumaphhR<=sumaphhF && sumaphhR<=sumaphhB) {
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", sumaphhR);
		}
		if(sumaphhF<=sumaphhR && sumaphhF<=sumaphhB) {
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", sumaphhF);
			if((9*sumaphhR)/10<sumaphhF) {
				printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 9*sumaphhR/10);
			}
		}
		if(sumaphhB<=sumaphhF && sumaphhB<=sumaphhR) {
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", sumaphhB);
			if((9*sumaphhR)/10<sumaphhB) {
				printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 9*sumaphhR/10);
			}
		}
	}
	if((t=='P' && b=='C' && m=='C') || (t=='C' && b=='C' && m=='P') || (t=='C' && b=='P' && m=='C')) {
		if(sumapccR<=sumapccF && sumapccR<=sumapccB) {
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", sumapccR);
		}
		if(sumapccF<=sumapccB && sumapccF<=sumapccR) {
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", sumapccF);
			if((9*sumapccR)/10<sumapccF) {
				printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", (9*sumapccR)/10);
			}
		}
		if(sumapccB<=sumapccF && sumapccB<=sumapccR) {
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", sumapccB);
			if((9*sumapccR)/10<sumapccB) {
				printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 9*sumapccR/10);
			}
		}
	}
	if((t=='P' && b=='C' && m=='H') || (t=='H' && b=='P' && m=='C') || (t=='C' && b=='H' && m=='P') || (t=='P' && b=='H' && m=='C') || (t=='h' && b=='c' && m=='p') || (t=='c' && b=='p' && m=='c')) {
		if(sumapchR<=sumapchF && sumapchR<=sumapchB) {
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", sumapchR);
		}
		if(sumapchF<=sumapchR && sumapchF<=sumapchB) {
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", sumapchF);
			if((9*sumapchR)/10<sumapchF) {
				printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 9*sumapchR/10);
			}
		}
		if(sumapchB<=sumapchF && sumapchB<=sumapchR) {
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", sumapchB);
			if((9*sumapchR)/10<sumapchB) {
				printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 9*sumapchR/10);
			}
		}
	}
	if((t=='H' && b=='H' && m=='C') || (t=='H' && b=='C' && m=='H') || (t=='C' && b=='H' && m=='H')) {
		if(sumahhcR<=sumahhcF && sumahhcR<=sumahhcB) {
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", sumahhcR);
		}
		if(sumahhcF<=sumahhcR && sumahhcF<=sumahhcB) {
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", sumahhcF);
			if((9*sumahhcR)/10<sumahhcF) {
				printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 9*sumahhcR/10);
			}
		}
		if(sumahhcB<=sumahhcF && sumahhcB<=sumahhcR) {
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", sumahhcB);
			if((9*sumahhcR)/10<sumahhcB) {
				printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 9*sumahhcR/10);
			}
		}
	}
	if((t=='H' && b=='C' && m=='C') || (t=='C' && b=='C' && m=='H') || (t=='C' && b=='H' && m=='C')) {
		if(sumahccR<=sumahccF && sumahccR<=sumahccB) {
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", sumahccR);
		}
		if(sumahccF<=sumahccR && sumahccF<=sumahccB) {
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", sumahccF);
			if((9*sumahccR)/10<sumahccF) {
				printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 9*sumahccR/10);
			}
		}
		if(sumahccB<=sumahccF && sumahccB<=sumahccR) {
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", sumahccB);
			if((9*sumahccR)/10<sumahccB) {
				printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 9*sumahccR/10);
			}
		}
	}
	if((t=='C' && b=='C' && m=='C')) {
		if(sumacccR<=sumacccF && sumacccR<=sumacccB) {
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", sumacccR);
		}
		if(sumacccF<=sumacccR && sumacccF<=sumacccB) {
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", sumacccF);
			if((9*sumacccR)/10<sumacccF) {
				printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 9*sumacccR/10);
			}
		}
		if(sumacccB<=sumacccF && sumacccB<=sumacccR) {
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", sumacccB);
			if((9*sumacccR)/10<sumacccB) {
				printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 9*sumacccR/10);
			}
		}
	}
	if((t=='H' && b=='H' && m=='H')) {
		if(sumahhhR<=sumahhhF && sumahhhR<=sumahhhB) {
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", sumahhhR);
		}
		if(sumahhhF<=sumahhhR && sumahhhF<=sumahhhB) {
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", sumahhhF);
			if((9*sumahhhR)/10<sumahhhF) {
				printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 9*sumahhhR/10);
			}
		}
		if(sumahhhB<=sumahhhF && sumahhhB<=sumahhhR) {
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", sumahhhB);
			if((9*sumahhhR)/10<sumahhhB) {
				printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 9*sumahhhR/10);
			}
		}
	}
	return 0;
}
