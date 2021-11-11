#include <stdio.h>
#define PR 6.80
#define PF 8.00
#define PB 5.30
#define HR 3.30
#define HF 3.00
#define HB 5.00
#define CR 5.00
#define CF 3.90
#define CB 6.00


int main() {
	
	float R1,F1,B1,CSP1,CSP2,CSP3,CSP4,CSP5,CSP6;
	char Tarik,Bojan,Mirza,nr;
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &Tarik);
	scanf("%c", &nr);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &Bojan);
	scanf("%c", &nr);
    printf("Unesite jelo za Mirzu: ");
	scanf("%c", &Mirza);
	scanf("%c", &nr);
	
	if((Tarik=='H' && Bojan=='P' && Mirza=='C') || (Tarik=='C' && Bojan=='H' && Mirza=='P') || (Tarik=='P' && Bojan=='C' && Mirza=='H') || (Tarik=='C' && Bojan=='P' && Mirza=='H') || (Tarik=='P' && Bojan=='H' && Mirza=='C') || (Tarik=='H' && Bojan=='C' && Mirza=='P')) {
		if((PR+HR+CR)<(PF+HF+CF) && (PR+HR+CR)<(PB+HB+CB)) {
			R1=PR+HR+CR;
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", R1 );
		}
		else if((PF+HF+CF)<(PR+HR+CR) && (PF+HF+CF)<(PB+HB+CB)) {
			F1=PF+HF+CF;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", F1 );
		      if(PR>HR && PR>CR) {
			     CSP1=HR+CR+(PR*0.9);
			     if(CSP1<F1) {
			     	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", CSP1);
			     }
		}
		      if(HR>PR && HR>CR) {
		      	CSP2=PR+CR+(HR*0.9);
		      	if(CSP2<F1) {
		      		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", CSP2);
		      	}
		      }
		 if(CR>PR && CR>HR) {
		      	CSP3=PR+HR+(CR*0.9);
		      	if(CSP3<F1) {
		      		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", CSP3);
		      	}
		      }
		
		}
		else if((PB+HB+CB)<(PR+HR+CR) && (PB+HB+CB)<(PF+HF+CF)) {
			B1=PB+HB+CB;
				printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", B1);
		      if(PR>HR && PR>CR) {
			     CSP4=HR+CR+(PR*0.9);
			     if(CSP4<B1) {
			     	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", CSP4);
			     }
		}
		      if(HR>PR && HR>CR) {
		      	CSP5=PR+CR+(HR*0.9);
		      	if(CSP5<B1) {
		      		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", CSP5);
		      	}
		      }
		 if(CR>PR && CR>HR) {
		      	CSP6=PR+HR+(CR*0.9);
		      	if(CSP6<B1) {
		      		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", CSP6);
		    }
          }
		}
	}
	/*2.*/
else if((Tarik=='H' && Bojan=='H' && Mirza=='C') || (Tarik=='H' && Bojan=='C' && Mirza=='H') || (Tarik=='C' && Bojan=='H' && Mirza=='H')) {
	if((2*HR)+CR<(2*HF)+CF && ((2*HR)+CR)<((2*HB)+CB)) {
			R1=(2*HR)+CR;
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", R1);
      }
      	else if((2*HF)+CF<(2*HR)+CR && ((2*HF)+CF)<((2*HB)+CB)) {
			F1=(2*HF)+CF;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", F1);
		      if((2*HR)>CR) {
			     CSP1=CR+(2*HR*0.9);
			     if(CSP1<F1) {
			     	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", CSP1);
			     }
		}
		      else if(CR>(2*HR)) {
		      	CSP2=2*HR+(CR*0.9);
		      	if(CSP2<F1) {
		      		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", CSP2);
		      	}
		      }
		 
		      }
			else if((2*HB)+CB<(2*HR)+CR && ((2*HB)+CB)<((2*HF)+CF)) {
			B1=(2*HB)+CB;
				printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", B1);
		      if(2*HR>CR) {
			     CSP3=CR+(2*HR*0.9);
			     if(CSP4<B1) {
			     	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", CSP3);
			     }
		}
		      else if(CR>(2*HR)) {
		      	CSP5=(2*HR)+(CR*0.9);
		      	if(CSP4<B1) {
		      		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", CSP4);
		      	}
		      }
			}
}
/*3.*/
else if((Tarik=='H' && Bojan=='P' && Mirza=='P') || (Tarik=='P' && Bojan=='H' && Mirza=='P') || (Tarik=='P' && Bojan=='P' && Mirza=='H')) {
	if((2*PR)+HR<(2*PF)+HF && ((2*PR)+HR)<((2*PB)+HB)) {
			R1=(2*PR)+HR;
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", R1);
      }
      	else if((2*PF)+HF<(2*PR)+HR && ((2*PF)+HF)<((2*PB)+HB)) {
			F1=(2*PF)+HF;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM) .\n", F1);
		      if((2*PR)>HR) {
			     CSP1=HR+(2*PR*0.9);
			     if(CSP1<F1) {
			     	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", CSP1);
			     }
		}
		      else if(HR>(2*PR)) {
		      	CSP2=2*PR+(HR*0.9);
		      	if(CSP2<F1) {
		      		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", CSP2);
		      	}
		      }
		 
		      }
			else if((2*PB)+HB<(2*PR)+HR && ((2*PB)+HB)<((2*PF)+HF)) {
			B1=(2*PB)+HB;
				printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", B1);
		      if(2*PR>HR) {
			     CSP3=HR+(2*PR*0.9);
			     if(CSP3<B1) {
			     	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", CSP3);
			     }
		}
		      else if(HR>(2*PR)) {
		      	CSP5=(2*PR)+(HR*0.9);
		      	if(CSP4<B1) {
		      		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", CSP4);
		      	}
		      }
			}
}
/*4.*/
else if((Tarik=='H' && Bojan=='H' && Mirza=='P') || (Tarik=='H' && Bojan=='P' && Mirza=='H') || (Tarik=='P' && Bojan=='H' && Mirza=='H')) {
	if((2*HR)+PR<(2*HF)+PF && ((2*HR)+PR)<((2*HB)+PB)) {
			R1=(2*HR)+PR;
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", R1);
      }
      	else if((2*HF)+PF<(2*HR)+PR && ((2*HF)+PF)<((2*HB)+PB)) {
			F1=(2*HF)+PF;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", F1);
		      if((2*HR)>PR) {
			     CSP1=PR+(2*HR*0.9);
			     if(CSP1<F1) {
			     	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", CSP1);
			     }
		}
		      else if(PR>(2*HR)) {
		      	CSP2=(2*HR)+(PR*0.9);
		      	if(CSP2<F1) {
		      		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", CSP2);
		      	}
		      }
		 
		      }
			else if((2*HB)+PB<(2*HR)+PR && ((2*HB)+PB)<((2*HF)+PF)) {
			B1=(2*HB)+PB;
				printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", B1);
		      if(2*HR>PR) {
			     CSP3=PR+(2*HR*0.9);
			     if(CSP3<B1) {
			     	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", CSP3);
			     }
		}
		      else if(PR>(2*HR)) {
		      	CSP4=(2*HR)+(PR*0.9);
		      	if(CSP4<B1) {
		      		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", CSP4);
		      	}
		      }
			}
}
/*5.*/
else if((Tarik=='P' && Bojan=='P' && Mirza=='C') || (Tarik=='P' && Bojan=='C' && Mirza=='P') || (Tarik=='C' && Bojan=='P' && Mirza=='P')) {
	if((2*PR)+CR<(2*PF)+CF && ((2*PR)+CR)<((2*PB)+CB)) {
			R1=(2*PR)+CR;
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", R1);
      }
      	else if((2*PF)+CF<(2*PR)+CR && ((2*PF)+CF)<((2*PB)+CB)) {
			F1=(2*PF)+CF;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", F1);
		      if((2*PR)>CR) {
			     CSP1=CR+(2*PR*0.9);
			     if(CSP1<F1) {
			     	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", CSP1);
			     }
		}
		      else if(CR>(2*PR)) {
		      	CSP2=(2*PR)+(CR*0.9);
		      	if(CSP2<F1) {
		      		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", CSP2);
		      	}
		      }
		 
		      }
			else if((2*PB)+CB<(2*PR)+CR && ((2*PB)+CB)<((2*PF)+CF)) {
			B1=(2*PB)+CB;
				printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", B1);
		      if((2*PR)>CR) {
			     CSP3=CR+(2*PR*0.9);
			     if(CSP3<B1) {
			     	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", CSP3);
			     }
		}
		      else if(CR>(2*PR)) {
		      	CSP4=(2*PR)+(CR*0.9);
		      	if(CSP4<B1) {
		      		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", CSP4);
		      	}
		      }
			}
}
/*6.*/
else if((Tarik=='C' && Bojan=='C' && Mirza=='H') || (Tarik=='C' && Bojan=='H' && Mirza=='C') || (Tarik=='H' && Bojan=='C' && Mirza=='C')) {
	if((2*CR)+HR<(2*CF)+HF && ((2*CR)+HR)<((2*CB)+HB)) {
			R1=(2*CR)+HR;
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", R1);
      }
      	else if((2*CF)+HF<(2*CR)+HR && ((2*CF)+HF)<((2*CB)+HB)) {
			F1=(2*CF)+HF;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", F1);
		      if((2*CR)>HR) {
			     CSP1=HR+(2*CR*0.9);
			     if(CSP1<F1) {
			     	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", CSP1);
			     }
		}
		      else if(HR>(2*CR)) {
		      	CSP2=(2*CR)+(HR*0.9);
		      	if(CSP2<F1) {
		      		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", CSP2);
		      	}
		      }
		 
		      }
			else if((2*CB)+HB<(2*CR)+HR && ((2*CB)+HB)<((2*CF)+HF)) {
			B1=(2*CB)+HB;
				printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", B1);
		      if((2*CR)>HR) {
			     CSP3=HR+(2*CR*0.9);
			     if(CSP3<B1) {
			     	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", CSP3);
			     }
		}
		      else if(HR>(2*CR)) {
		      	CSP4=(2*CR)+(HR*0.9);
		      	if(CSP4<B1) {
		      		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", CSP4);
		      	}
		      }
			}
}
/*7.*/
else if((Tarik=='C' && Bojan=='C' && Mirza=='P') || (Tarik=='C' && Bojan=='P' && Mirza=='C') || (Tarik=='P' && Bojan=='C' && Mirza=='C')) {
	if((2*CR)+PR<(2*CF)+PF && ((2*CR)+PR)<((2*CB)+PB)) {
			R1=(2*CR)+PR;
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", R1);
      }
      	else if((2*CF)+PF<(2*CR)+PR && ((2*CF)+PF)<((2*CB)+PB)) {
			F1=(2*CF)+PF;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", F1);
		      if((2*CR)>PR) {
			     CSP1=PR+(2*CR*0.9);
			     if(CSP1<F1) {
			     	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", CSP1);
			     }
		}
		      else if(PR>(2*CR)) {
		      	CSP2=(2*CR)+(PR*0.9);
		      	if(CSP2<F1) {
		      		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", CSP2);
		      	}
		      }
		 
		      }
			else if((2*CB)+PB<(2*CR)+PR && ((2*CB)+PB)<((2*CF)+PF)) {
			B1=(2*CB)+PB;
				printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", B1);
		      if((2*CR)>PR) {
			     CSP3=PR+(2*CR*0.9);
			     if(CSP3<B1) {
			     	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", CSP3);
			     }
		}
		      else if(PR>(2*CR)) {
		      	CSP4=(2*CR)+(PR*0.9);
		      	if(CSP4<B1) {
		      		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", CSP4);
		      	}
		      }
			}
}
/*8.*/
else if(Tarik=='P' && Bojan=='P' && Mirza=='P') {
	if((3*PR)<(3*PF) && (3*PR)<(3*PB)) {
			R1=3*PR;
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", R1);
      }
      	else if((3*PF)<(3*PR) && (3*PF)<(3*PB)) {
			F1=3*PF;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", F1);
			     CSP1=3*PR*0.9;
			     if(CSP1<F1) {
			     	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", CSP1);
			     }
		      }
			else if((3*PB)<(3*PR) && (3*PB)<(3*PF)) {
			B1=3*PB;
				printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", B1);
	
			     CSP2=3*PR*0.9;
			     if(CSP2<B1) {
			     	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", CSP2);
			     }
		}
		    
			}
/*9.*/
else if(Tarik=='C' && Bojan=='C' && Mirza=='C') {
	if((3*CR)<(3*CF) && (3*CR)<(3*CB)) {
			R1=3*CR;
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", R1);
      }
      	else if((3*CF)<(3*CR) && (3*CF)<(3*CB)) {
			F1=3*CF;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", F1);
			     CSP1=3*CR*0.9;
			     if(CSP1<F1) {
			     	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", CSP1);
			     }
		      }
			else if((3*CB)<(3*CR) && (3*CB)<(3*CF)) {
			B1=3*CB;
				printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", B1);
	
			     CSP2=3*CR*0.9;
			     if(CSP2<B1) {
			     	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", CSP2);
			     }
		}
		    
			}

/*10.*/
else if(Tarik=='H' && Bojan=='H' && Mirza=='H') {
	if((3*HR)<(3*HF) && (3*HR)<(3*HB)) {
			R1=3*HR;
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", R1);
      }
      	else if((3*HF)<(3*HR) && (3*HF)<(3*HB)) {
			F1=3*HF;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", F1);
			     CSP1=3*HR*0.9;
			     if(CSP1<F1) {
			     	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", CSP1);
			     }
		      }
			else if((3*HB)<(3*HR) && (3*HB)<(3*HF)) {
			B1=3*HB;
				printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", B1);
	
			     CSP2=3*HR*0.9;
			     if(CSP2<B1) {
			     	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", CSP2);
			     }
		}
		    
			}

	return 0;
}