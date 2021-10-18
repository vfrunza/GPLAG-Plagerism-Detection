#include <stdio.h>
#define rp 6.80
#define rh 3.30
#define rc 5.00
#define fp 8.00
#define fh 3.00
#define fc 3.90
#define bp 5.30
#define bh 5.00
#define bc 6.00

int main() {
	char tarik, bojan, mirza;
	double popust, jeftinijeh, jeftinijep, jeftinijec, restoran, ukupno;
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &tarik);
	printf("Unesite jelo za Bojana: ");
	scanf(" %c", &bojan);
	printf("Unesite jelo za Mirzu: ");
	scanf(" %c", &mirza);
	
	jeftinijeh = rh;
	if(jeftinijeh>fh) jeftinijeh=fh;
	if(jeftinijeh>bh) jeftinijeh=bh;
	jeftinijec = rc;
	if(jeftinijec>fc) jeftinijec=fc;
	if(jeftinijec>bc) jeftinijec=bc;
	jeftinijep = rp;
	if(jeftinijep>fp) jeftinijep=fp;
	if(jeftinijep>bp) jeftinijep=bp;
	
	if(tarik == bojan && bojan == mirza && tarik == 'H') {
		restoran = 3*rh;
		jeftinijeh=3*jeftinijeh;
		if(jeftinijeh==3*rh) {
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", jeftinijeh);
		} else if(jeftinijeh==3*fh) {
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", jeftinijeh);
			popust = restoran-restoran/10;
			if(jeftinijeh>popust) {
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", popust);
			}
		} else if(jeftinijeh==3*bh) {
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", jeftinijeh);
			popust = restoran - restoran/10;
			if(jeftinijeh>popust) {
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", popust);
			}
		}
	} else if(tarik == bojan && bojan == mirza && tarik == 'P') {
		restoran = 3*rp;
		jeftinijep = 3*jeftinijep;
		if(jeftinijep==3*rp) {
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",jeftinijep);
		} else if(jeftinijep==3*fp) {
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",jeftinijep);
			popust = restoran - restoran/10;
			if(jeftinijep>popust){
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", popust);
			}
		} else if(jeftinijep==3*bp) {
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",jeftinijep);
			popust = restoran - restoran/10;
			if(jeftinijep>popust){
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", popust);
			}
		}
	} else if(tarik == bojan && bojan == mirza && tarik == 'C') {
		restoran = 3*rc;
		jeftinijec = 3* jeftinijec;
		if(jeftinijec==3*rc) {
			printf("Najjeftiniji je Restoran \"Kod konja i knjusara\" (%.2f KM).",jeftinijec);
		} else if (jeftinijec==3*fc) {
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",jeftinijec);
			popust = restoran-restoran/10;
			if(jeftinijec>popust) {
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", popust);
			}
		} else if(jeftinijec==3*bc) {
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",jeftinijec);
			popust = restoran - restoran/10;
			if(jeftinijec>popust) {
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", popust);
			}
		}
	} else if (tarik != bojan && bojan != mirza) {
	ukupno = jeftinijep + jeftinijec + jeftinijeh;
	if((jeftinijeh == rh && jeftinijec == rc && jeftinijep == rp) || (jeftinijeh == rh && jeftinijec == rc) || (jeftinijeh == rh && jeftinijep == rp) || (jeftinijec == rc && jeftinijep == rp)) {
	printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (.2f KM).", ukupno);	
	} else if((jeftinijeh == fh && jeftinijep == fp && jeftinijec == fc) || (jeftinijeh == fh && jeftinijec == fc) || (jeftinijeh == fh && jeftinijep == fp) || (jeftinijec == fc && jeftinijep == fp)) {
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", ukupno);
	} else if ((jeftinijeh == bh && jeftinijep == bp && jeftinijec == bc) || (jeftinijeh == bc && jeftinijec == bc) || (jeftinijeh == bh && jeftinijep == bp) || (jeftinijec == bc && jeftinijep == bp)) {
		printf("Najjeftiniji je Bistro\"Lorelei\" (%.2f KM).", ukupno);
	} 
	} else if (tarik == bojan && bojan != mirza && tarik == 'H') {
		if(jeftinijeh==rh) {
				if(mirza == 'P') {
			ukupno = 2*jeftinijeh + rp;
			restoran = 2*rh+rp;
		} else if(mirza == 'C') {
			ukupno = 2*jeftinijeh + rc;
			restoran = 2*rh + rc;
		}
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", ukupno);
		} else if(jeftinijeh==fh) {
				if(mirza == 'P') {
			ukupno = 2*jeftinijeh + rp;
			restoran = 2*rh + rp;
		} else if(mirza == 'C') {
			ukupno = 2*jeftinijeh + rc;
			restoran = 2*rh + rc;
		}
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", ukupno);
			popust = restoran - 2*rh/10;
			if(ukupno>popust) {
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", popust);
			}
		} else if(jeftinijeh==bh) {
				if(mirza == 'P') {
			ukupno = 2*jeftinijeh + bp;
			restoran = 2*rh + rp;
		} else if(mirza == 'C') {
			ukupno = 2*jeftinijeh + bc;
			restoran = 2*rh + rc;
		}
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", ukupno);
			popust = restoran - 2*rh/10;
			if(ukupno>popust) {
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", popust);
			}
		}
	} else if(bojan == mirza && mirza != tarik && mirza == 'H') {
	
		if(jeftinijeh==rh) {
			if(tarik == 'P') {
			ukupno = 2*jeftinijeh + rp;
			restoran = 2*rh + rp;
		} else if(tarik == 'C') {
			ukupno = 2*jeftinijeh + rc;
			restoran = 2*rh + rc;
		}
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", ukupno);
		} else if(jeftinijeh==fh) {
		if(tarik == 'P') {
			ukupno = 2*jeftinijeh + fp;
			restoran = 2*rh + rp;
		} else if(tarik == 'C') {
			ukupno = 2*jeftinijeh + fc;
			restoran = 2*rh + rc;
		}
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", ukupno);
			popust = restoran - 2*rh/10;
			if(ukupno>popust) {
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", popust);
			}
		} else if(jeftinijeh==bh) {
			if(tarik == 'P') {
			ukupno = 2*jeftinijeh + bp;
			restoran = 2*rh + rp;
		} else if(tarik == 'C') {
			ukupno = 2*jeftinijeh + bc;
			restoran = 2*rh + rc;
		}
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", ukupno);
			popust = restoran - 2*rh/10;
			if(ukupno>popust) {
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", popust);
			}
		}
	} else if(tarik == mirza && tarik != bojan && tarik == 'H') {
			
		if(jeftinijeh==rh) {
			if(bojan == 'P') {
			ukupno = 2*jeftinijeh + rp;
			restoran = 2*rh + rp;
		} else if(bojan == 'C') {
			ukupno = 2*jeftinijeh + rc;
			restoran = 2*rh + rc;
		}
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", ukupno);
		} else if(jeftinijeh==fh) {
			if(bojan == 'P') {
			ukupno = 2*jeftinijeh + fp;
			restoran = 2*rh + rp;
		} else if(bojan == 'C') {
			ukupno = 2*jeftinijeh + fc;
			restoran = 2*rh + rc;
		}
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", ukupno);
			popust = restoran - 2*rh/10;
			if(ukupno>popust) {
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", popust);
			}
		} else if(jeftinijeh==bh) {
			if(bojan == 'P') {
			ukupno = 2*jeftinijeh + bp;
			restoran = 2*rh + rp;
		} else if(bojan == 'C') {
			ukupno = 2*jeftinijeh + bc;
			restoran = 2*rh + rc;
		}
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", ukupno);
			popust = restoran - 2*rh/10;
			if(ukupno>popust) {
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", popust);
			}
		}
	} else if(tarik == bojan && bojan != mirza && tarik == 'P') {
		if(jeftinijep==rp) {
			if(mirza == 'H') {
				ukupno = 2*jeftinijep + rh;
				restoran = 2*rp + rh;
			} else if(mirza == 'C') {
				ukupno = 2*jeftinijep + rc;
			restoran = 2*rp + rc;
			}
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",ukupno);
		} else if(jeftinijep==fp) {
			if(mirza == 'H') {
				ukupno = 2*jeftinijep + fh;
				restoran = 2*rp + rh;
			} else if(mirza == 'C') {
				ukupno = 2*jeftinijep + fc;
				restoran = 2*rp + rc;
			}
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",ukupno);
			popust = restoran - 2*rp/10;
			if(ukupno>popust){
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", popust);
			}
		} else if(jeftinijep==bp) {
				if(mirza == 'H') {
				ukupno = 2*jeftinijep + bh;
				restoran = 2*rp + rh;
			} else if(mirza == 'C') {
				ukupno = 2*jeftinijep + bc;
				restoran = 2*rp + rc;
			}
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",ukupno);
			popust = restoran - 2*rp/10;
			if(ukupno>popust){
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", popust);
			}
		}
	} else if(bojan == mirza && mirza != tarik && mirza == 'P') {
		
		if(jeftinijep==rp) {
			if(tarik == 'H') {
				ukupno = 2*jeftinijep + rh;
				restoran = 2*rp + rh;
			} else if(tarik == 'C') {
				ukupno = 2*jeftinijep + rc;
				restoran = 2*rp + rc;
			}
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",ukupno);
		} else if(jeftinijep==fp) {
			if(tarik == 'H') {
				ukupno = 2*jeftinijep + fh;
				restoran = 2*rp + rh;
			} else if(tarik == 'C') {
				ukupno = 2*jeftinijep + fc;
				restoran = 2*rp + rc;
			}
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",ukupno);
			popust = restoran - 2*rp/10;
			if(ukupno>popust){
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", popust);
			}
		} else if(jeftinijep==bp) {
			if(tarik == 'H') {
				ukupno = 2*jeftinijep + bh;
				restoran = 2*rp + rh;
			} else if(tarik == 'C') {
				ukupno = 2*jeftinijep + bc;
				restoran = 2*rp + rc;
			}
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",ukupno);
			popust = restoran - 2*rp/10;
			if(ukupno>popust){
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", popust);
			}
		}
	} else if(tarik == mirza && tarik != bojan && tarik == 'P') {
		
		if(jeftinijep==rp) {
			if(bojan == 'H') {
				restoran = 2*rp + rh;
				ukupno = 2*jeftinijep + rh;
			} else if(bojan == 'C') {
				ukupno = 2*jeftinijep + rc;
				restoran = 2*rp + rc;
			}
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",ukupno);
		} else if(jeftinijep==fp) {
			if(bojan == 'H') {
				ukupno = 2*jeftinijep + fh;
				restoran = 2*rp + rh;
			} else if(bojan == 'C') {
				ukupno = 2*jeftinijep + fc;
				restoran = 2*rp + rc;
			}
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",ukupno);
			popust = restoran - 2*rp/10;
			if(ukupno>popust){
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", popust);
			}
		} else if(jeftinijep==bp) {
			if(bojan == 'H') {
				ukupno = 2*jeftinijep + bh;
				restoran = 2*rp + rh;
			} else if(bojan == 'C') {
				ukupno = 2*jeftinijep + bc;
				restoran = 2*rp + rc;
			}
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",ukupno);
			popust = restoran - 2*rp/10;
			if(ukupno>popust){
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", popust);
			}
		}
	} else if(tarik == bojan && bojan != mirza && tarik == 'C') {
		
		if(jeftinijec==rc) {
			if(mirza == 'H') {
			ukupno = 2*jeftinijec+rh;
			restoran = 2*rc + rh;
		} else if (mirza == 'P') {
			ukupno = 2*jeftinijec+rp;
			restoran = 2*rc + rp;
		}
			printf("Najjeftiniji je Restoran \"Kod konja i knjusara\" (%.2f KM).",ukupno);
		} else if (jeftinijec==fc) {
			if(mirza == 'H') {
			ukupno = 2*jeftinijec+fh;
			restoran = 2*rc + rh;
		} else if (mirza == 'P') {
			ukupno = 2*jeftinijec+fp;
			restoran = 2*rc + rp;
		}
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",ukupno);
			popust = restoran - 2*rc/10;
			if(ukupno>popust) {
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", popust);
			}
		} else if(jeftinijec==bc) {
			if(mirza == 'H') {
			ukupno = 2*jeftinijec+bh;
			restoran = 2*rc + rh;
		} else if (mirza == 'P') {
			ukupno = 2*jeftinijec+bp;
			restoran = 2*rc + rp;
		}
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",ukupno);
			popust = restoran - 2*rc/10;
			if(ukupno>popust) {
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", popust);
			}
		}
	} else if (bojan == mirza && mirza != tarik && mirza == 'C') {
			
		if(jeftinijec==rc) {
			if(tarik == 'H') {
			ukupno = 2*jeftinijec+rh;
			restoran = 2*rc + rh;
		} else if (tarik == 'P') {
			ukupno = 2*jeftinijec+rp;
			restoran = 2*rc + rp;
		}
			printf("Najjeftiniji je Restoran \"Kod konja i knjusara\" (%.2f KM).",ukupno);
		} else if (jeftinijec==fc) {
			if(tarik == 'H') {
			ukupno = 2*jeftinijec+fh;
			restoran = 2*rc + rh;
		} else if (tarik == 'P') {
			ukupno = 2*jeftinijec+fp;
			restoran = 2*rc + rp;
		}
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",ukupno);
			popust = restoran - 2*rc/10;
			if(ukupno>popust) {
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", popust);
			}
		} else if(jeftinijec==bc) {
			if(tarik == 'H') {
			ukupno = 2*jeftinijec+bh;
			restoran = 2*rc + rh;
		} else if (tarik == 'P') {
			ukupno = 2*jeftinijec+bp;
			restoran = 2*rc + rp;
		}
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",ukupno);
			popust = restoran - 2*rc/10;
			if(ukupno>popust) {
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", popust);
			}
		}
	} else if(tarik == mirza && tarik != bojan && tarik == 'C') {
			
		if(jeftinijec==rc) {
			if(bojan == 'H') {
			ukupno = 2*jeftinijec+rh;
			restoran = 2*rc + rh;
		} else if (bojan == 'P') {
			ukupno = 2*jeftinijec+rp;
			restoran = 2*rc + rp;
		}
			printf("Najjeftiniji je Restoran \"Kod konja i knjusara\" (%.2f KM).",ukupno);
		} else if (jeftinijec==fc) {
			if(bojan == 'H') {
			ukupno = 2*jeftinijec+fh;
			restoran = 2*rc + rh;
		} else if (bojan == 'P') {
			ukupno = 2*jeftinijec+fp;
			restoran = 2*rc + rp;
		}
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",ukupno);
			popust = restoran - 2*rc/10;
			if(ukupno>popust) {
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", popust);
			}
		} else if(jeftinijec==bc) {
			if(bojan == 'H') {
			ukupno = 2*jeftinijec+bh;
			restoran = 2*rc + rh;
		} else if (bojan == 'P') {
			ukupno = 2*jeftinijec+bp;
			restoran = 2*rc + rp;
		}
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",ukupno);
			popust = restoran - 2*rc/10;
			if(ukupno>popust) {
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", popust);
			}
		}
	}
	return 0;
}
