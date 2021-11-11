#include <stdio.h>
#define cpr 6.80
#define chr 3.30
#define ccr 5.00
#define cpf 8.00
#define chf 3.00
#define ccf 3.90
#define cpb 5.30
#define chb 5.00
#define ccb 6.00


int main()
{
	char jt, jb, jm, a,b;
	float pcpr,pccr, pchr;
	pcpr=0.9*cpr;
	pchr=0.9*chr;
	pccr=0.9*ccr;
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &jt);
	scanf("%c", &a);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &jb);
	scanf("%c", &b);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &jm);
	if((jt=='H' || jt=='P' || jt=='C') && (jb=='H' || jb=='P' || jb=='C') && (jm=='H' || jm=='P' || jm=='C')) {


		if(jt==jb && jb==jm) {
			if(jt=='C') {
				if(3*ccr<3*ccf && 3*ccr<3*ccb) {
					printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", 3*ccr);
				} else if(3*ccf<3*ccr && 3*ccf<3*ccb) {
					printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", 3*ccf);
					if(3*pccr<3*ccf) {
						printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 3*pccr);
					}
				} else if(3*ccb<3*ccr && 3*ccb<3*ccf) {
					printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", 3*ccb);
					if(3*pccr<3*ccb) {
						printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 3*pccr);
					}
				}
			}
			if(jt=='P') {
				if(3*cpr<3*cpf && 3*cpr<3*cpb) {
					printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", 3*cpr);
				} else if(3*cpf<3*cpr && 3*cpf<3*cpb) {
					printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", 3*cpf);
					if(3*(pcpr)<3*cpf) {
						printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 3*(pcpr));
					}
				} else if(3*cpb<3*cpr && 3*cpb<3*cpf) {
					printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", 3*cpb);
					if(3*(pcpr)<3*cpb) {
						printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 3*(pcpr));
					}
				}
			}
			if(jt=='H') {
				if(3*chr<3*chf && 3*chr<3*chb) {
					printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", 3*chr);
				} else if(3*chf<3*chr && 3*chf<3*chb) {
					printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", 3*chf);
					if(3*pchr<3*chf) {
						printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 3*pchr);
					}
				} else if(3*chb<3*chr && 3*chb<3*chf) {
					printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", 3*chb);
					if(3*pchr<3*chb) {
						printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 3*(pchr));
					}
				}
			}
		}


		if(jt==jb && jb!=jm) {
			if(jt=='P') {
				if(jm=='C') {
					if(2*cpr+ccr<2*cpf+ccf && 2*cpr+ccr<2*cpb+ccb) {
						printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", 2*cpr+ccr);
					} else if(2*cpf+ccf<2*cpr+ccr && 2*cpf+ccf<2*cpb+ccb) {
						printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", 2*cpf+ccf);
						if(2*pcpr+ccr<2*cpf+ccf) {
							printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 2*pcpr+ccr);
						}
					} else if(2*cpb+ccb<2*cpr+ccr && 2*cpb+ccb<2*cpf+ccf) {
						printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", 2*cpb+ccb);
						if(2*pcpr+ccr<2*cpb+ccb) {
							printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 2*pcpr+ccr);
						}
					}
				}
				if(jm=='H') {
					if(2*cpr+chr<2*cpf+chf && 2*cpr+chr<2*cpb+chb) {
						printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", 2*cpr+chr);
					} else if(2*cpf+chf<2*cpr+chr && 2*cpf+chf<2*cpb+chb) {
						printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", 2*cpf+chf);
						if(2*pcpr+chr<2*cpf+chf) {
							printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 2*pcpr+chr);
						}
					} else if(2*cpb+chb<2*cpr+chr && 2*cpb+chb<2*cpf+chf) {
						printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", 2*cpb+chb);
						if(2*pcpr+chr<2*cpb+chb) {
							printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 2*pcpr+chr);
						}
					}
				}
			}
		}
		
		
		if(jt==jm && jm!=jb) {
			if(jt=='P') {
				if(jb=='C') {
					if(2*cpr+ccr<2*cpf+ccf && 2*cpr+ccr<2*cpb+ccb) {
						printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", 2*cpr+ccr);
					} else if(2*cpf+ccf<2*cpr+ccr && 2*cpf+ccf<2*cpb+ccb) {
						printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", 2*cpf+ccf);
						if(2*pcpr+ccr<2*cpf+ccf) {
							printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 2*pcpr+ccr);
						}
					} else if(2*cpb+ccb<2*cpr+ccr && 2*cpb+ccb<2*cpf+ccf) {
						printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", 2*cpb+ccb);
						if(2*pcpr+ccr<2*cpb+ccb) {
							printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 2*pcpr+ccr);
						}
					}
				}
				if(jb=='H') {
					if(2*cpr+chr<2*cpf+chf && 2*cpr+chr<2*cpb+chb) {
						printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", 2*cpr+chr);
					} else if(2*cpf+chf<2*cpr+chr && 2*cpf+chf<2*cpb+chb) {
						printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", 2*cpf+chf);
						if(2*pcpr+chr<2*cpf+chf) {
							printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 2*pcpr+chr);
						}
					} else if(2*cpb+chb<2*cpr+chr && 2*cpb+chb<2*cpf+chf) {
						printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", 2*cpb+chb);
						if(2*pcpr+chr<2*cpb+chb) {
							printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 2*pcpr+chr);
						}
					}
				}
			}
		}
		
		
		if(jm==jb && jb!=jt) {
			if(jm=='P') {
				if(jt=='C') {
					if(2*cpr+ccr<2*cpf+ccf && 2*cpr+ccr<2*cpb+ccb) {
						printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", 2*cpr+ccr);
					} else if(2*cpf+ccf<2*cpr+ccr && 2*cpf+ccf<2*cpb+ccb) {
						printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", 2*cpf+ccf);
						if(2*pcpr+ccr<2*cpf+ccf) {
							printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 2*pcpr+ccr);
						}
					} else if(2*cpb+ccb<2*cpr+ccr && 2*cpb+ccb<2*cpf+ccf) {
						printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", 2*cpb+ccb);
						if(2*pcpr+ccr<2*cpb+ccb) {
							printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 2*pcpr+ccr);
						}
					}
				}
				if(jt=='H') {
					if(2*cpr+chr<2*cpf+chf && 2*cpr+chr<2*cpb+chb) {
						printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", 2*cpr+chr);
					} else if(2*cpf+chf<2*cpr+chr && 2*cpf+chf<2*cpb+chb) {
						printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", 2*cpf+chf);
						if(2*pcpr+chr<2*cpf+chf) {
							printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 2*pcpr+chr);
						}
					} else if(2*cpb+chb<2*cpr+chr && 2*cpb+chb<2*cpf+chf) {
						printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", 2*cpb+chb);
						if(2*pcpr+chr<2*cpb+chb) {
							printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 2*pcpr+chr);
						}
					}
				}
			}
		}
		
		
		if(jt==jb && jb!=jm) {
			if(jt=='H') {
				if(jm=='C') {
					if(2*chr+ccr<2*chf+ccf && 2*chr+ccr<2*chb+ccb) {
						printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", 2*chr+ccr);
					} else if(2*chf+ccf<2*chr+ccr && 2*chf+ccf<2*chb+ccb) {
						printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", 2*chf+ccf);
						if(2*pchr+ccr<2*chf+ccf) {
							printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 2*pchr+ccr);
						}
					} else if(2*chb+ccb<2*chr+ccr && 2*chb+ccb<2*chf+ccf) {
						printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", 2*chb+ccb);
						if(2*pchr+ccr<2*chb+ccb) {
							printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 2*pchr+ccr);
						}
					}
				}
				if(jm=='P') {
					if(2*chr+cpr<2*chf+cpf && 2*chr+cpr<2*chb+cpb) {
						printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", 2*chr+cpr);
					} else if(2*chf+cpf<2*chr+cpr && 2*chf+cpf<2*chb+cpb) {
						printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", 2*chf+cpf);
						if(2*pchr+cpr<2*chf+cpf) {
							printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 2*pchr+cpr);
						}
					} else if(2*chb+cpb<2*chr+cpr && 2*chb+cpb<2*chf+cpf) {
						printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", 2*chb+cpb);
						if(2*pchr+cpr<2*chb+cpb) {
							printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 2*pchr+cpr);
						}
					}
				}
			}
		}
		
		
		if(jt==jm && jm!=jb) {
			if(jt=='H') {
				if(jb=='C') {
					if(2*chr+ccr<2*chf+ccf && 2*chr+ccr<2*chb+ccb) {
						printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", 2*chr+ccr);
					} else if(2*chf+ccf<2*chr+ccr && 2*chf+ccf<2*chb+ccb) {
						printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", 2*chf+ccf);
						if(2*pchr+ccr<2*chf+ccf) {
							printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 2*pchr+ccr);
						}
					} else if(2*chb+ccb<2*chr+ccr && 2*chb+ccb<2*chf+ccf) {
						printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", 2*chb+ccb);
						if(2*pchr+ccr<2*chb+ccb) {
							printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 2*pchr+ccr);
						}
					}
				}
				if(jb=='P') {
					if(2*chr+cpr<2*chf+cpf && 2*chr+cpr<2*chb+cpb) {
						printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", 2*chr+cpr);
					} else if(2*chf+cpf<2*chr+cpr && 2*chf+cpf<2*chb+cpb) {
						printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", 2*chf+cpf);
						if(2*pchr+cpr<2*chf+cpf) {
							printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 2*pchr+cpr);
						}
					} else if(2*chb+cpb<2*chr+cpr && 2*chb+cpb<2*chf+cpf) {
						printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", 2*chb+cpb);
						if(2*pchr+cpr<2*chb+cpb) {
							printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 2*pchr+cpr);
						}
					}
				}
			}
		}
		
		
		if(jm==jb && jb!=jt) {
			if(jm=='H') {
				if(jt=='C') {
					if(2*chr+ccr<2*chf+ccf && 2*chr+ccr<2*chb+ccb) {
						printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", 2*chr+ccr);
					} else if(2*chf+ccf<2*chr+ccr && 2*chf+ccf<2*chb+ccb) {
						printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", 2*chf+ccf);
						if(2*pchr+ccr<2*chf+ccf) {
							printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 2*pchr+ccr);
						}
					} else if(2*chb+ccb<2*chr+ccr && 2*chb+ccb<2*chf+ccf) {
						printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", 2*chb+ccb);
						if(2*pchr+ccr<2*chb+ccb) {
							printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 2*pchr+ccr);
						}
					}
				}
				if(jt=='P') {
					if(2*chr+cpr<2*chf+cpf && 2*chr+cpr<2*chb+cpb) {
						printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", 2*chr+cpr);
					} else if(2*chf+cpf<2*chr+cpr && 2*chf+cpf<2*chb+cpb) {
						printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", 2*chf+cpf);
						if(2*pchr+cpr<2*chf+cpf) {
							printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 2*pchr+cpr);
						}
					} else if(2*chb+cpb<2*chr+cpr && 2*chb+cpb<2*chf+cpf) {
						printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", 2*chb+cpb);
						if(2*pchr+cpr<2*chb+cpb) {
							printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 2*pchr+cpr);
						}
					}
				}
			}
		}
		
		
		if(jt==jb && jb!=jm) {
			if(jt=='C') {
				if(jm=='P') {
					if(2*ccr+cpr<2*ccf+cpf && 2*ccr+cpr<2*ccb+cpb) {
						printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", 2*ccr+cpr);
					} else if(2*ccf+cpf<2*ccr+cpr && 2*ccf+cpf<2*ccb+cpb) {
						printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", 2*ccf+cpf);
						if(2*pccr+cpr<2*ccf+cpf) {
							printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 2*pccr+cpr);
						}
					} else if(2*ccb+cpb<2*ccr+cpr && 2*ccb+cpb<2*ccf+cpf) {
						printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", 2*ccb+cpb);
						if(2*pccr+cpr<2*ccb+cpb) {
							printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 2*pccr+cpr);
						}
					}
				}
				if(jm=='H') {
					if(2*ccr+chr<2*ccf+chf && 2*ccr+chr<2*ccb+chb) {
						printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", 2*ccr+chr);
					} else if(2*ccf+chf<2*ccr+chr && 2*ccf+chf<2*ccb+chb) {
						printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", 2*ccf+chf);
						if(2*pccr+chr<2*ccf+chf) {
							printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 2*pccr+chr);
						}
					} else if(2*ccb+chb<2*ccr+chr && 2*ccb+chb<2*ccf+chf) {
						printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", 2*ccb+chb);
						if(2*pccr+chr<2*ccb+chb) {
							printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 2*pccr+chr);
						}
					}
				}
			}
		}
		
		
		if(jt==jm && jm!=jb) {
			if(jt=='C') {
				if(jb=='P') {
					if(2*ccr+cpr<2*ccf+cpf && 2*ccr+cpr<2*ccb+cpb) {
						printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", 2*ccr+cpr);
					} else if(2*ccf+cpf<2*ccr+cpr && 2*ccf+cpf<2*ccb+cpb) {
						printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", 2*ccf+cpf);
						if(2*pccr+cpr<2*ccf+cpf) {
							printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 2*pccr+cpr);
						}
					} else if(2*ccb+cpb<2*ccr+cpr && 2*ccb+cpb<2*ccf+cpf) {
						printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", 2*ccb+cpb);
						if(2*pccr+cpr<2*ccb+cpb) {
							printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 2*pccr+cpr);
						}
					}
				}
				if(jb=='H') {
					if(2*ccr+chr<2*ccf+chf && 2*ccr+chr<2*ccb+chb) {
						printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", 2*ccr+chr);
					} else if(2*ccf+chf<2*ccr+chr && 2*ccf+chf<2*ccb+chb) {
						printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", 2*ccf+chf);
						if(2*pccr+chr<2*ccf+chf) {
							printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 2*pccr+chr);
						}
					} else if(2*ccb+chb<2*ccr+chr && 2*ccb+chb<2*ccf+chf) {
						printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", 2*ccb+chb);
						if(2*pccr+chr<2*ccb+chb) {
							printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 2*pccr+chr);
						}
					}
				}
			}
		}
		
		
		if(jm==jb && jb!=jt) {
			if(jm=='C') {
				if(jt=='P') {
					if(2*ccr+cpr<2*ccf+cpf && 2*ccr+cpr<2*ccb+cpb) {
						printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", 2*ccr+cpr);
					} else if(2*ccf+cpf<2*ccr+cpr && 2*ccf+cpf<2*ccb+cpb) {
						printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", 2*ccf+cpf);
						if(2*pccr+cpr<2*ccf+cpf) {
							printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 2*pccr+cpr);
						}
					} else if(2*ccb+cpb<2*ccr+cpr && 2*ccb+cpb<2*ccf+cpf) {
						printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", 2*ccb+cpb);
						if(2*pccr+cpr<2*ccb+cpb) {
							printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 2*pccr+cpr);
						}
					}
				}
				if(jt=='H') {
					if(2*ccr+chr<2*ccf+chf && 2*ccr+chr<2*ccb+chb) {
						printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", 2*ccr+chr);
					} else if(2*ccf+chf<2*ccr+chr && 2*ccf+chf<2*ccb+chb) {
						printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", 2*ccf+chf);
						if(2*pccr+chr<2*ccf+chf) {
							printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 2*pccr+chr);
						}
					} else if(2*ccb+chb<2*ccr+chr && 2*ccb+chb<2*ccf+chf) {
						printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", 2*ccb+chb);
						if(2*pccr+chr<2*ccb+chb) {
							printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 2*pccr+chr);
						}
					}
				}
			}
		}
		
		
		if(jt!=jb && jt!=jm && jm!=jb) {
			if(ccr+cpr+chr<cpf+chf+ccf && ccr+cpr+chr<cpb+chb+ccb) {
				printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", ccr+cpr+chr);
			} else if(cpf+chf+ccf<ccr+cpr+chr && cpf+chf+ccf<ccb+cpb+chb) {
				printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", cpf+chf+ccf);
				if(ccr>=chr && ccr>=cpr) {
					printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", pccr+cpr+chr);
				} else if(cpr>=chr && cpr>=ccr) {
					printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", ccr+pcpr+chr);
				} else if(chr>=cpr && chr>=ccr) {
					printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", ccr+cpr+pchr);
				}
			} else if(ccb+cpb+chb<ccf+cpf+chf && ccb+cpb+chb<ccr+cpr+chr) {
				printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", 3*ccb);
				if(ccr>=chr && ccr>=cpr) {
					printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", pccr+cpr+chr);
				} else if(cpr>=chr && cpr>=ccr) {
					printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", ccr+pcpr+chr);
				} else if(chr>=cpr && chr>=ccr) {
					printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", ccr+cpr+pchr);
				}
			}
		}
	}
	else
	{
		printf("Neispravno unesena slova!");
	}
	return 0;
}
