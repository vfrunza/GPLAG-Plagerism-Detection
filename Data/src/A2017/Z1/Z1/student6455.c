/*#include <stdio.h>
#define P1 6.80
#define P2 8.00
#define P3 5.30
#define H1 3.30
#define H2 3.00
#define H3 5.00
#define C1 5.00
#define C2 3.90
#define C3 6.00
int main()
{
	/*char tarik,bojan,mirza,novi_red;
	float sum1,sum2,sum3,sum11,sum4,sum5,sum6,sum44,sum7,sum8,sum9,sum77,sum10,sum12,sum13,sum1010,sum14,sum15,sum16,sum1414,sum17,sum18,sum19,sum1717,sum20,sum21,sum22,sum2020,sum23,sum24,sum25,sum2323,sum26,sum27,sum28,sum2626,sum29,sum30,sum31,sum2929,sum32,sum33,sum34,sum3232,sum35,sum36,sum37,sum38,sum39,sum40,sum41,sum42,sum43;
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &tarik);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &bojan);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &mirza);
	scanf("%c", &novi_red);

	if(tarik=='P' && bojan=='P' && mirza=='P') {
		sum1=3*P1;
		sum2=3*P2;
		sum3=3*P3;
		if(sum1<sum2 && sum1<sum3) {
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\"(%.2f KM).", sum1);
		}


		else if(sum2<sum1 && sum2<sum3) {
			sum11=(P1-(P1*10)/100)*3;
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", sum2);
			if (sum11<sum2) {
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", sum11);
			}
		}

		else if (sum3<sum1 && sum3<sum2) {
			sum11=(P1-(P1*10)/100)*3;
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", sum3);
			if(sum11<sum3) {
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", sum11);
			}

		}
	}

	else if(tarik=='P' && bojan=='P' && mirza=='H') {
		sum4=P1*2+H1;
		sum5=P2*2+H2;
		sum6=P3*3+H3;
		if(sum4<sum5 && sum4<sum6) {
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", sum4);
		}

		else if(sum5<sum4 && sum5<sum6) {
			sum35= (H1-(H1*10)/100)+2*P1;
			sum44=(P1-(P1*10)/100)*2+H1;
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", sum5);
			if(sum44<sum5 && sum44<sum35) {
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", sum44);
			} else if(sum35<sum44 && sum35<sum5) {
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", sum35);
			}

		}

		else if(sum6<sum5 && sum6<sum4) {
			sum44=(P1-(P1*10)/100)*2+H1;
			sum35= (H1-(H1*10)/100)+2*P1;
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",  sum6);
			if(sum44<sum6 && sum44<sum35) {
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", sum44);
			} else if(sum35<sum44 && sum35<sum6) {
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", sum35);
			}
		}
	}

	else if((tarik=='P' && bojan=='P' && mirza=='C') || (tarik=='P' && bojan=='C' && mirza=='P') || (tarik=='C' && bojan=='P' && mirza=='P')) {
		sum7=2*P1+C1;
		sum8=2*P2+C2;
		sum9=2*P3+C3;
		if(sum7<sum8 && sum7<sum9) {
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%2.f KM).", sum7);
		} else if(sum8<sum7 && sum8<sum9) {
			printf("Najjeftiniji je Fast-food\"Trovac\" (%.2f KM).\n", sum8);
			sum77=(P1-(P1*10)/100)*2+C1;
			sum36=(C1-(C1*10)/100)+2*P1;
			if(sum77<sum8 && sum77<sum36) {
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", sum77);
			} else if(sum36<sum77 && sum36<sum8) {
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", sum36);
			}

		}

		else if (sum9<sum7 && sum9<sum8) {
			sum77=(P1-(P1*10)/100)*2+C1;
			sum36=(C1-(C1*10)/100)+2*P1;
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", sum9);
			if(sum77<sum9 && sum77<sum36) {
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", sum77);
			} else if(sum36<sum77 && sum36<sum9) {
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", sum36);
			}
		}
	}

	else if((tarik=='P' && bojan=='H' && mirza=='P') || (tarik=='H' && bojan=='P' && mirza=='P')) {
		sum10=P1*2+H1;
		sum12=P2*2+H2;
		sum13=P3*2+H3;
		if(sum10<sum12 && sum10<sum13) {
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", sum10);
		} else if(sum12<sum10 && sum12<sum13) {
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", sum12);
			sum1010=(P1-(P1*10)/100)*2+H1;
			sum37=(H1-(H1*10)/100)+2*P1;
			if(sum1010<sum12 && sum1010<sum37) {
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", sum1010);
			} else if(sum37<sum1010 && sum37<sum12) {
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", sum37);
			}

		} else if (sum13<sum10 && sum13<sum12) {
			sum1010=(P1-(P1*10)/100)*2+H1;
			sum37=(H1-(H1*10)/100)+2*P1;
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", sum13);
			if(sum1010<sum13 && sum1010<sum37) {
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", sum1010);
			} else if(sum37<sum1010 && sum37<sum13) {
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", sum37);
			}
		}
	}

	else if((tarik=='P' && bojan=='H' && mirza=='H') || (tarik=='H' && bojan=='H' && mirza=='P') || (tarik=='H' && bojan=='P' && mirza=='H'))

	{
		sum14=P1+2*H1;
		sum15=P2+2*H2;
		sum16=P3+2*H3;
		if(sum14<sum15 && sum14<sum16) {
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", sum14);
		} else if(sum15<sum14 && sum15<sum16) {
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", sum15);
			sum1414=(P1-(P1*10)/100)+2*H1;
			sum38=(H1-(H1*10)/100)*2+P1;
			if(sum1414<sum15 && sum1414<sum38) {
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", sum1414);
			} else if(sum38<sum1414 && sum38<15) {
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", sum38);
			}

		}

		else if (sum16<sum14 && sum16<sum15) {
			sum1414=(P1-(P1*10)/100)+2*H1;
			sum38=(H1-(H1*10)/100)*2+P1;
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", sum16);
			if(sum1414<sum16 && sum1414<sum38) {
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", sum1414);
			} else if(sum38<sum1414 && sum38<sum16) {
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", sum38);
			}

		}
	}

	else if((tarik=='P' && bojan=='H' && mirza=='C')||(tarik=='P' && bojan=='C' && mirza=='H') || (tarik=='H' && bojan=='P' && mirza=='C') || (tarik=='H' && bojan=='C' && mirza=='P') || (tarik=='C' && bojan=='H' && mirza=='P') || (tarik=='C' && bojan=='P' && mirza=='H')) {
		sum17=P1+H1+C1;
		sum18=P2+H2+C2;
		sum19=P3+H3+C3;
		if(sum17<sum18 && sum17<sum19) {
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", sum17);
		} else if(sum18<sum17 && sum18<sum19) {
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", sum18);
			sum1717=(P1-(P1*10)/100)+H1+C1;
			sum39=(H1-(H1*10)/100)+P1+C1;
			sum40=(C1-(C1*10)/100)+P1+H1;
			if(sum1717<sum18 && sum1717<sum39 && sum1717<sum40) {
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", sum1717);
			} else if(sum39<sum18 && sum39<sum1717 && sum39<sum40) {
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", sum39);
			} else if(sum40<sum18 && sum40<sum1717 && sum40<sum39) {
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", sum40);
			}

		}

		else if (sum19<sum17 && sum19<sum18) {
			sum1717=(P1-(P1*10)/100)+H1+C1;
			sum39=(H1-(H1*10)/100)+P1+C1;
			sum40=(C1-(C1*10)/100)+P1+H1;
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", sum19);
			if(sum1717<sum19 && sum1717<sum39 && sum1717<sum40) {
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", sum1717);
			} else if(sum39<sum1717 && sum39<sum40 && sum39<sum19) {
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", sum39);
			} else if(sum40<sum19 && sum40<sum1717 && sum40<sum39) {
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", sum40);
			}

		}
	} else if((tarik=='P' && bojan=='C' && mirza=='C')||(tarik=='C' && bojan=='C' && mirza=='P')||(tarik=='C' && bojan=='P' && mirza=='C')) {
		sum20=P1+2*C1;
		sum21=P2+2*C2;
		sum22=P3+2*C3;
		if(sum20<sum21 && sum20<sum22) {
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", sum20);
		}

		else if(sum21<sum20 && sum21<sum22) {
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", sum21);
			sum2020=(P1-(P1*10)/100)+2*C1;
			sum41=(C1-(C1*10)/100)*2 +P1;
			if(sum2020<sum21 && sum2020<sum41) {
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", sum2020);
			} else if(sum41<sum2020 && sum41<sum21) {
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", sum41);
			}

		} else if (sum22<sum20 && sum22<sum21) {
			sum2020=(P1-(P1*10)/100)+2*C1;
			sum41=(C1-(C1*10)/100)*2 +P1;
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", sum22);
			if(sum2020<sum22 && sum2020<sum41) {
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", sum2020);
			} else if(sum41<sum22 && sum41<sum2020) {
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",sum41);
			}

		}
	} else if((tarik=='H' && bojan=='C' && mirza=='C')||(tarik=='C' && bojan=='C' && mirza=='H')|| (tarik=='C' && bojan=='H' && mirza=='C')) {
		sum23=H1+C1*2;
		sum24=H2+C2*2;
		sum25=H3+C3*3;
		if(sum23<sum24 && sum23<sum25) {
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", sum23);
		} else if(sum24<sum23 && sum24<sum25) {
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",sum24);
			sum2323=(H1-(H1*10)/100)+2*C1;
			sum42=(C1-(C1*10)/100)*2+H1;
			if(sum2323<sum24 && sum2323<sum42) {
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", sum2323);
			} else if(sum42<sum2323 && sum42<sum24) {
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", sum42);
			}
		}

		else if (sum25<sum23 && sum25<sum24) {
			sum2323=(H1-(H1*10)/100)+2*C1;
			sum42=(C1-(C1*10)/100)*2+H1;
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", sum24);
			if(sum2323<sum25 && sum2323<sum42) {
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", sum2323);
			} else if(sum42<sum25 && sum42<sum2323) {
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", sum42);
			}
		}
	} else if(tarik=='H' && bojan=='H' && mirza=='H') {
		sum26=3*H1;
		sum27=3*H2;
		sum28=3*H3;
		if(sum26<sum27 && sum26<sum28) {
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", sum26);
		} else if(sum27<sum26 && sum27<sum28) {
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", sum27);
			sum2626=(H1-(H1*10)/100)*3;
			if(sum2626<sum27) {
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", sum2626);
			}

		} else if (sum28<sum26 && sum28<sum27) {
			sum2626=(H1-(H1*10)/100)*3;
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", sum28);
			if(sum2626<sum28) {
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", sum2626);
			}

		}

	} else if(tarik=='C' && bojan=='C' && mirza=='C') {
		sum29=3*C1;
		sum30=3*C2;
		sum31=3*C3;
		if(sum29<sum30 && sum29<sum31) {
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", sum29);
		} else if(sum30<sum29 && sum30<sum31) {
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", sum30);
			sum2929=(C1-(C1*10)/100)*3;
			if(sum2929<sum30) {
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", sum2929);
			}

		} else if (sum31<sum29 && sum31<sum30) {
			sum2929=(C1-(C1*10)/100)*3;
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", sum31);
			if(sum2929<sum31) {
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", sum2929);
			}

		}
	} else if ((tarik=='H' && bojan=='H' && mirza=='C')||(tarik=='H' && bojan=='C' && mirza=='H')||(tarik=='C' && bojan=='H' && mirza=='H')) {
		sum32=2*H1+C1;
		sum33=2*H2+C2;
		sum34=2*H3+C3;
		if(sum32<sum33 && sum32<sum34) {
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", sum32);
		}

		else if(sum33<sum32 && sum33<sum34) {
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", sum33);
			sum3232=(H1-(H1*10)/100)*2+C1;
			sum43=(C1-(C1*10)/100)+2*H1;
			if(sum3232<sum33 && sum3232<sum43) {
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", sum3232);
			} else if(sum43<sum3232 && sum43<sum33) {
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", sum43);
			}

		} else if (sum34<sum32 && sum34<sum33) {
			sum3232=(H1-(H1*10)/100)*2+C1;
			sum43=(C1-(C1*10)/100)+2*H1;
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", sum34);
			if(sum3232<sum34) {
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", sum3232);
			} else if(sum43<sum3232 && sum43<sum34) {
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", sum43);
			}

		}

	}
 

	return 0;
}
*/
#include <stdio.h>
#define PKKK 6.8
#define PFFT 8
#define PBL 5.3
#define HKKK 3.3
#define HFFT 3
#define HBL 5
#define CKKK 5
#define CFFT 3.9
#define CBL 6
int main(){
	char Tarik, Bojan,Mirza,novi_red;
	double sumaKKK=0, sumaBL=0,sumaFFT=0,sumaPP,sumaHP,sumaCP;
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &Tarik);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &Bojan);
	scanf("%c", &novi_red);

	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &Mirza);
	scanf("%c", &novi_red);
	switch(Tarik) {
		case 'P':
		sumaKKK+=PKKK;
		sumaFFT+=PFFT;
		sumaBL+=PBL;
		break;
		case 'H':
		sumaKKK+=HKKK;
		sumaBL+=HBL;
		sumaFFT+=HFFT;
		break;
		case 'C':
		sumaKKK+=CKKK;
		sumaBL+=CBL;
		sumaFFT+=CFFT;
		break;
		default: 
		printf("Pogresan unos!");
		return 1;
	}
	switch(Bojan) {
		case 'P':
		sumaKKK+=PKKK;
		sumaFFT+=PFFT;
		sumaBL+=PBL;
		break;
		case 'H':
		sumaKKK+=HKKK;
		sumaBL+=HBL;
		sumaFFT+=HFFT;
		break;
		case 'C':
		sumaFFT+=CFFT;
		sumaBL+=CBL;
		sumaKKK+=CKKK;
		break;
		default: 
		printf("Pogresan unos!");
		return 1;
	}
	switch(Mirza) {
		case 'P':
		sumaKKK+=PKKK;
		sumaFFT+=PFFT;
		sumaBL+=PBL;
		break;
		case 'H':
		sumaKKK+=HKKK;
		sumaBL+=HBL;
		sumaFFT+=HFFT;
		break;
		case 'C':
		sumaFFT+=CFFT;
		sumaBL+=CBL;
		sumaKKK+=CKKK;
		break;
		default: 
		printf("Pogresan unos!");
		return 1;
	}
	printf("%g %g %g", sumaKKK, sumaFFT,sumaBL);
	sumaPP=sumaKKK;sumaHP=sumaKKK;sumaCP=sumaKKK;
	if(sumaKKK>sumaFFT || sumaKKK>sumaBL) {
		if(Bojan=='P') 
		sumaPP=sumaPP-PKKK*10/100;
		if(Mirza=='P')
		sumaPP=sumaPP-PKKK*10/100.;
		if(Tarik=='P')
		sumaPP=sumaPP-PKKK*10/100.;
		if(Bojan=='C') 
		sumaCP=sumaCP-CKKK*10/100;
		if(Mirza=='C')
		sumaCP-=CKKK*10/100.;
		if(Tarik=='C')
		sumaCP-=CKKK*10/100.;
		if(Bojan=='H') 
		sumaHP-=HKKK*10/100;
		if(Mirza=='H')
		sumaHP-=HKKK*10/100.;
		if(Tarik=='H')
		sumaHP-=HKKK*10/100.;
		
	}
  if(sumaKKK<sumaFFT && sumaKKK<sumaBL) printf("Restoran kod konja i konjusara je najeftiji (%f)", sumaKKK);

  else if(sumaFFT<sumaKKK && sumaFFT<sumaBL) printf("Najjeftiniji je Fast-food Trovac (%f)", sumaFFT);
  else printf("Najjeftiniji je Bistro Lorelei (%f)", sumaBL);
  	 if(!(sumaKKK<sumaFFT && sumaKKK<sumaBL) && (sumaHP<sumaCP) && sumaHP<sumaPP && sumaHP<sumaFFT && sumaHP<sumaBL )
  	 printf("Sa popustom bi Restoran bio jeftiniji (%f)",sumaHP);
  	else if(!(sumaKKK<sumaFFT && sumaKKK<sumaBL) && (sumaPP<sumaCP) && sumaPP<sumaHP && sumaPP<sumaFFT && sumaPP<sumaBL )

  	 printf("Sa popustom bi Restoran bio jeftiniji (%f)",sumaPP);
  	   	else if(!(sumaKKK<sumaFFT && sumaKKK<sumaBL) && (sumaCP<sumaHP) && sumaCP<sumaPP && sumaCP<sumaFFT && sumaCP<sumaBL )
  	 printf("Sa popustom bi Restoran bio jeftiniji (%f)",sumaCP);



	
	return 0;
}






















