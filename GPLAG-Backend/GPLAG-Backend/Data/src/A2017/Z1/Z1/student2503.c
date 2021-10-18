#include <stdio.h>

#define CP1 6.80
#define CP2 8.00
#define CP3 5.30

#define CH1 3.30
#define CH2 3.00
#define CH3 5.00

#define CC1 5.00
#define CC2 3.90
#define CC3 6.00

#define popust 0.9
int main()
{
    float PPP,HHH,CCC,PPP1,PPP2,PPP3,PPH01,PPH02,PPH1,PPH2,PPH3,PPC01,PPC02,PPC1,PPC2,PPC3,PHH01,PHH02,PHH1,PHH2,PHH3,PHC01,PHC02,PHC03,PHC1,PHC2,PHC3,PCC01,PCC02,PCC1,PCC2,PCC3,HHH1,HHH2,HHH3,HHC01,HHC02,HHC1,HHC2,HHC3,HCC01,HCC02,HCC1,HCC2,HCC3,CCC1,CCC2,CCC3;
    char tarik,bojan,mirza;
    char novi_red;

    printf("Unesite jelo za Tarika: ");
    scanf("%c", &tarik);
    scanf("%c", &novi_red);
    printf("Unesite jelo za Bojana: ");
    scanf("%c", &bojan);
    scanf("%c", &novi_red);
    printf("Unesite jelo za Mirzu: ");
    scanf("%c", &mirza);
    scanf("%c", &novi_red);

    PPP1=CP1+CP1+CP1;
    PPP2=CP2+CP2+CP2;
    PPP3=CP3+CP3+CP3;

    PPH1=CP1+CP1+CH1;
    PPH2=CP2+CP2+CH2;
    PPH3=CP3+CP3+CH3;

    PPC1=CP1+CP1+CC1;
    PPC2=CP2+CP2+CC2;
    PPC3=CP3+CP3+CC3;

    PHH1=CP1+CH1+CH1;
    PHH2=CP2+CH2+CH2;
    PHH3=CP3+CH3+CH3;

    PHC1=CP1+CH1+CC1;
    PHC2=CP2+CH2+CC2;
    PHC3=CP3+CH3+CC3;

    PCC1=CP1+CC1+CC1;
    PCC2=CP2+CC2+CC2;
    PCC3=CP3+CC3+CC3;

    HHH1=CH1+CH1+CH1;
    HHH2=CH2+CH2+CH2;
    HHH3=CH3+CH3+CH3;

    HHC1=CH1+CH1+CC1;
    HHC2=CH2+CH2+CC2;
    HHC3=CH3+CH3+CC3;

    HCC1=CH1+CC1+CC1;
    HCC2=CH2+CC2+CC2;
    HCC3=CH3+CC3+CC3;

    CCC1=CC1+CC1+CC1;
    CCC2=CC2+CC2+CC2;
    CCC3=CC3+CC3+CC3;

    if (tarik=='P' && bojan=='P' && mirza=='P') {
        if((PPP1<PPP2) && (PPP1<PPP3)) {
            printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",PPP1);
        } else if ((PPP2<PPP1) && (PPP2<PPP3)) {
            printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",PPP2);
            PPP=3.*popust*CP1;
            if (PPP<PPP2) {
                printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",PPP);
            }
        } else {
            printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",PPP3);
            PPP=3.*popust*CP1;
            if (PPP<PPP3) {
                printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",PPP);
            }
        }

    } else if ((tarik=='P' && bojan=='P' && mirza=='H') || (tarik=='P' && mirza=='P' && bojan=='H') || (bojan=='P' && mirza=='P' && tarik=='H')) {
        if((PPH1<PPH2) && (PPH1<PPH3)) {
            printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",PPH1);
        } else if ((PPH2<PPH1) && (PPH2<PPH3)) {
            printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",PPH2);
            PPH01=2.*CP1*popust+CH1;
            PPH02=2.*CP1+CH1*popust;
            if ((PPH01<PPH02) && (PPH01<PPH2)) {
                printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",PPH01);
            } else if ((PPH02<PPH01) & (PPH02<PPH2)) {
                printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",PPH02);
            }
        } else {
            printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",PPH3);
            PPH01=2.*CP1*popust+CH1;
            PPH02=2.*CP1+CH1*popust;
            if ((PPH01<PPH02) && (PPH01<PPH3)) {
                printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",PPH01);
            } else if ((PPH02<PPH01) & (PPH02<PPH3)) {
                printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",PPH02);
            }
        }
    } else if ((tarik=='P' && bojan=='P' && mirza=='C') || (tarik=='P' && mirza=='P' && bojan=='C') || (bojan=='P' && mirza=='P' && tarik=='C')) {
        if((PPC1<PPC2) && (PPC1<PPC3)) {
            printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",PPC1);
        } else if ((PPC2<PPC1) && (PPC2<PPC3)) {
            printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",PPC2);
            PPC01=2.*CP1*popust+CC1;
            PPC02=2.*CP1+CC1*popust;
            if ((PPC01<PPC02) && (PPC01<PPC2)) {
                printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",PPC01);
            } else if ((PPC02<PPC01) & (PPC02<PPC2)) {
                printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",PPC02);
            }
        } else {
            printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",PPC3);
            PPC01=2.*CP1*popust+CC1;
            PPC02=2.*CP1+CC1*popust;
            if ((PPC01<PPC02) && (PPC01<PPC3)) {
                printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",PPC01);
            } else if ((PPC02<PPC01) & (PPC02<PPC3)) {
                printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",PPC02);
            }
        }
    } else if ((tarik=='P' && bojan=='H' && mirza=='H') || (tarik=='H' && mirza=='P' && bojan=='H') || (bojan=='P' && mirza=='H' && tarik=='H')) {
        if((PHH1<PHH2) && (PHH1<PHH3)) {
            printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",PHH1);
        } else if ((PHH2<PHH1) && (PHH2<PHH3)) {
            printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",PHH2);
            PHH01=2.*CH1*popust+CP1;
            PHH02=2.*CH1+CP1*popust;
            if ((PHH01<PHH02) && (PHH01<PHH2)) {
                printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",PHH01);
            } else if ((PHH02<PPC01) & (PHH02<PHH2)) {
                printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",PHH02);
            }
        } else {
            printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",PHH3);
            PHH01=2.*CH1*popust+CP1;
            PHH02=2.*CH1+CP1*popust;
            if ((PHH01<PHH02) && (PHH01<PHH3)) {
                printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",PHH01);
            } else if ((PHH02<PPC01) & (PHH02<PHH3)) {
                printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",PHH02);
            }
        }
    } else if ((tarik=='P' && mirza=='H' && bojan=='C') || (tarik=='P' && mirza=='C' && bojan=='H') || (tarik=='C' && mirza=='P' && bojan=='H') || (tarik=='C' && mirza=='H' && bojan=='P') || (tarik=='H' && mirza=='P' && bojan=='C') || (tarik=='H' && mirza=='C' && bojan=='P')) {
        if((PHC1<PHC2) && (PHC1<PHC3)) {
            printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",PHC1);
        } else if ((PHC2<PHC1) && (PHC2<PHC3)) {
            printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",PHC2);
            PHC01=popust*CP1+CH1+CC1;
            PHC02=CP1+popust*CH1+CC1;
            PHC03=CP1+CH1+popust*CC1;
            if ((PHC01<PHC02) && (PHC01<PHC03) && (PHC01<PHC2)) {
                printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",PHC01);
            } else if ((PHC02<PHC01) & (PHC02<PHC03) && (PHC02<PHC2)) {
                printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",PHC02);
            } else if ((PHC03<PHC01) & (PHC03<PHC02) && (PHC03<PHC2)) {
                printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",PHC03);
            }
        } else {
            printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",PHC3);
            if ((PHC01<PHC02) && (PHC01<PHC03) && (PHC01<PHC3)) {
                printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",PHC01);
            } else if ((PHC02<PHC01) & (PHC02<PHC03) && (PHC02<PHC3)) {
                printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",PHC02);
            } else if ((PHC03<PHC01) & (PHC03<PHC02) && (PHC03<PHC3)) {
                printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",PHC03);
            }
        }
    } else if ((tarik=='C' && bojan=='C' && mirza=='P') || (tarik=='P' && mirza=='C' && bojan=='C') || (bojan=='P' && mirza=='C' && tarik=='C')) {
        if((PCC1<PCC2) && (PCC1<PCC3)) {
            printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",PCC1);
        } else if ((PCC2<PCC1) && (PCC2<PCC3)) {
            printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",PCC2);
            PCC01=2.*CC1*popust+CP1;
            PCC02=2.*CC1+CP1*popust;
            if ((PCC01<PCC02) && (PCC01<PCC2)) {
                printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",PCC01);
            } else if ((PCC02<PCC01) & (PCC02<PCC2)) {
                printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",PCC02);
            }
        } else {
            printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",PCC3);
            PCC01=2.*CC1*popust+CP1;
            PCC02=2.*CC1+CP1*popust;
            if ((PCC01<PCC02) && (PCC01<PCC3)) {
                printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",PCC01);
            } else if ((PCC02<PCC01) & (PCC02<PCC3)) {
                printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",PCC02);
            }
        }
    } else if (tarik=='H' && bojan=='H' && mirza=='H') {
        if((HHH1<HHH2) && (HHH1<HHH3)) {
            printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",HHH1);
        } else if ((HHH2<HHH1) && (HHH2<HHH3)) {
            printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",HHH2);
            HHH=3.*popust*CH1;
            if (HHH<HHH2) {
                printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",HHH);
            }
        } else {
            printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",HHH3);
            HHH=3.*popust*CH1;
            if (HHH<HHH3) {
                printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",HHH);
            }
        }
    } else if ((tarik=='H' && bojan=='H' && mirza=='C') || (tarik=='C' && mirza=='H' && bojan=='H') || (bojan=='C' && mirza=='H' && tarik=='H')) {
        if((HHC1<HHC2) && (HHC1<HHC3)) {
            printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",HHC1);
        } else if ((HHC2<HHC1) && (HHC2<HHC3)) {
            printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",HHC2);
            HHC01=2.*CH1*popust+CC1;
            HHC02=2.*CH1+CC1*popust;
            if ((HHC01<HHC02) && (HHC01<HHC2)) {
                printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",HHC01);
            } else if ((HHC02<HHC01) & (HHC02<HHC2)) {
                printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",HHC02);
            }
        } else {
            printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f).\n",HHC3);
            HHC01=2.*CH1*popust+CC1;
            HHC02=2.*CH1+CC1*popust;
            if ((HHC01<HHC02) && (HHC01<HHC3)) {
                printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",HHC01);
            } else if ((HHC02<HHC01) & (HHC02<HHC3)) {
                printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",HHC02);
            }
        }
    } else if ((tarik=='C' && bojan=='C' && mirza=='H') || (tarik=='H' && mirza=='C' && bojan=='C') || (bojan=='H' && mirza=='C' && tarik=='C')) {
        if((HCC1<HCC2) && (HCC1<HCC3)) {
            printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",HCC1);

        } else if ((HCC2<HCC1) && (HCC2<HCC3)) {
            printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",HCC2);
            HCC01=2.*CC1*popust+CH1;
            HCC02=2.*CC1+CH1*popust;
            if ((HCC01<HCC02) && (HCC01<HCC2)) {
                printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",HCC01);
            } else if ((HCC02<HCC01) & (HCC02<HCC2)) {
                printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",HCC02);
            }
        } else {
            printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",HCC3);
            HCC01=2.*CC1*popust+CH1;
            HCC02=2.*CC1+CH1*popust;
            if ((HCC01<HCC02) && (HCC01<HCC3)) {
                printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",HCC01);
            } else if ((HCC02<HCC01) & (HCC02<HCC3)) {
                printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",HCC02);
            }
        }
    } else if (tarik=='C' && bojan=='C' && mirza=='C') {
        if((CCC1<CCC2) && (CCC1<CCC3)) {
            printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",CCC1);
        } else if ((CCC2<CCC1) && (CCC2<CCC3)) {
            printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",CCC2);
            CCC=3.*popust*CC1;
            if (CCC<CCC2) {
                printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",CCC);
            }
        } else {
            printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",CCC3);
            CCC=3.*popust*CC1;
            if (CCC<CCC3) {
                printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",CCC);
            }
        }
    }
    return 0;
}
