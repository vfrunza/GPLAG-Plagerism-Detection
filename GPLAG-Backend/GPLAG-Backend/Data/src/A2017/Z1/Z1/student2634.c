#include <stdio.h>

int main () {
    
    char tarik,bojan,mirza;
    char novi_red;
    double cp1=6.80, cp2=8.00, cp3=5.30, ch1=3.30, ch2=3.00, ch3=5.00, cc1=5.00, cc2=3.90, cc3=6.00;
    double cijena1, cijena2, cijena3;
    
    
    printf  ("Unesite jelo za Tarika: ");
    scanf ("%c", &tarik);
    scanf ("%c", &novi_red);
    printf ("Unesite jelo za Bojana: ");
    scanf ("%c", &bojan);
    scanf ("%c", &novi_red);
    printf ("Unesite jelo za Mirzu: ");
    scanf ("%c", &mirza);
    scanf ("%c", &novi_red);
    
    if (tarik=='P' && bojan=='P' && mirza=='P')  {
        cijena1=cp1*3;
        cijena2=cp2*3;
        cijena3=cp3*3;
        if (cijena2<cijena1 && cijena2<cijena3) printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2fKM).\n", cijena2);
        else if (cijena3<cijena1 && cijena3<cijena2) printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", cijena3);
        else if (cijena1<cijena2 && cijena1<cijena3) printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", cijena1);
        if (cijena1<cijena2 && cijena1<cijena3) {
           cp1=cp1-(cp1/10);
           cijena1=cp1*3;
           if (cijena1>cijena2 && cijena1>cijena3) printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena1);
       }
        
    }
    
    else if (tarik=='H' && bojan=='H' && mirza=='H') {
        cijena1=ch1*3;
        cijena2=ch2*3;
        cijena3=ch3*3;
        if (cijena2<cijena1 && cijena2<cijena3) printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", cijena2);
        else if (cijena3<cijena2 && cijena3<cijena1) printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", cijena3);
        else if (cijena1<cijena2 && cijena1<cijena3) printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", cijena1);
        if (cijena1>cijena2 || cijena1>cijena3) {
            cijena1=cijena1 - ch1*0.3;
            if (cijena1<cijena2 && cijena1<cijena3) printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena1);
        }
    }
    
    else if (tarik=='C' && bojan=='C' && mirza=='C') {
        cijena1=cc1*3;
        cijena2=cc2*3;
        cijena3=cc3*3;
        if (cijena2<cijena1 && cijena2<cijena3) printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", cijena2);
        else if (cijena3<cijena2 && cijena3<cijena1) printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", cijena3);
        else if (cijena1<cijena2 && cijena1<cijena3) printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", cijena1);
        if (cijena1>cijena2 && cijena1>cijena3) {
            cc1=cc1-(cc1*10);
            cijena1=cc1*3;
            if (cijena1<cijena2 && cijena1<cijena3) printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena1);
        }
    }
    
    else if ((tarik=='P' && bojan=='P' && mirza=='C') || (tarik=='P' && bojan=='C' && mirza=='P') || (tarik=='C' && bojan=='P' && mirza=='P')) {
        cijena1=cp1*2 + cc1;
        cijena2=cp2*2 + cc2;
        cijena3=cp3*2 + cc3;
        if (cijena2<cijena1 && cijena2<cijena3) printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", cijena2);
        else if (cijena3<cijena2 && cijena3<cijena1) printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", cijena3);
        else if (cijena1<cijena2 && cijena1<cijena3) printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", cijena1);
        if (cijena1>cijena2 && cijena1>cijena3) {
            if (cp1>cc1) {
                cp1= cp1 - (cp1/10);
                cijena1=cp1*2 + cc1;
                printf ("Sa popustom bi Restoran bio jeftiniji (%g KM).", cijena1); }
                else {
                    cc1= cc1 - (cc1/10);
                    cijena1=cp1*2 + cc1;
                    printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena1);
                }
            }
                
        }
        
    else if ((tarik=='P' && mirza=='P' && bojan=='H') || (tarik=='P' && bojan=='P' && mirza=='H') || (tarik=='H' && mirza=='P' && bojan=='P')) {
        cijena1=cp1*2 + ch1;
        cijena2=cp2*2 + ch2;
        cijena3=cp3*2 + ch3;
        if (cijena2<cijena1 && cijena2<cijena3) printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", cijena2);
        else if (cijena3<cijena2 && cijena3<cijena1) printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", cijena3);
        else if (cijena1<cijena2 && cijena1<cijena3) printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", cijena1);
        if (cijena1>cijena2 || cijena1>cijena3) {
            if (cp1>ch1) {
                cijena1=cijena1 - 2*0.1*cp1;
                printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena1); }
                else {
                    cijena1=cijena1 - 0.2*ch1;
                    printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena1); 
                    
                }
            }
                
        }
        
    else if ((tarik=='H' && mirza=='H' && bojan=='P') || (tarik=='P' && mirza=='H' && bojan=='H') || (mirza=='P' && tarik=='H' && bojan=='H')) {
        cijena1=ch1*2 + cp1;
        cijena2=ch2*2 + cp2;
        cijena3=ch3*2 + cp3;
        if (cijena2<cijena1 && cijena2<cijena3) printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", cijena2);
        else if (cijena3<cijena2 && cijena3<cijena1) printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", cijena3);
        else if (cijena1<cijena2 && cijena1<cijena3) printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", cijena1);
        if (cijena1>cijena2 && cijena1>cijena3) {
            if (ch1>cp1) {
                ch1=ch1 - (ch1/10);
                cijena1=ch1*2 + cp1;
                printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena1); }
                else {
                    cp1=cp1 - (cp1/10);
                    cijena1=ch1*2 + cp1;
                    printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena1);
                }
            }
        }
    
      else if ((tarik=='H' && mirza=='H' && bojan=='C') || (tarik=='C' && mirza=='H' && bojan=='H') || (mirza=='C' && tarik=='H' && bojan=='H')) {
        cijena1=ch1*2 + cc1;
        cijena2=ch2*2 + cc2;
        cijena3=ch3*2 + cc3;
        if (cijena2<cijena1 && cijena2<cijena3) printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", cijena2);
        else if (cijena3<cijena2 && cijena3<cijena1) printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", cijena3);
        else if (cijena1<cijena2 && cijena1<cijena3) printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", cijena1);
        if (cijena1>cijena2 && cijena1>cijena3) {
            if (ch1>cc1) {
                ch1=ch1 - (ch1/10);
                cijena1=ch1*2 + cc1;
                printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena1); }
                else {
                    cc1=cc1 - (cc1/10);
                    cijena1=ch1*2 + cc1;
                    printf ("Sa popustom bi Restoran bio jeftiniji (%,2f KM).", cijena1);
                }
            }
        }
        
    else if ((tarik=='C' && mirza=='C' && bojan=='P') || (mirza=='C' && bojan=='C' && tarik=='P') || (mirza=='P' && tarik=='C' && mirza=='C')) {
        cijena1=cc1*2 + cp1;
        cijena2=cc2*2 + cp2;
        cijena3=cc3*2 + cp3;
        if (cijena2<cijena1 && cijena2<cijena3) printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", cijena2);
        else if (cijena3<cijena2 && cijena3<cijena1) printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", cijena3);
        else if (cijena1<cijena2 && cijena1<cijena3) printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", cijena1);
        if (cijena1>cijena2 && cijena1>cijena3) {
            if (cc1>cp1) {
                cc1=cc1 - (cc1/10);
                cijena1=cc1*2 + cp1;
                printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena1); }
                else {
                    cp1=cp1 - (cp1/10);
                    cijena1=cc1*2 + cp1;
                    printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena1);
                }
            }
        }
        
     else if ((tarik=='C' && mirza=='C' && bojan=='H') || (mirza=='C' && bojan=='C' && tarik=='H') || (mirza=='H' && tarik=='C' && mirza=='C')) {
        cijena1=cc1*2 + ch1;
        cijena2=cc2*2 + ch2;
        cijena3=cc3*2 + ch3;
        if (cijena2<cijena1 && cijena2<cijena3) printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", cijena2);
        else if (cijena3<cijena2 && cijena3<cijena1) printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", cijena3);
        else if (cijena1<cijena3 && cijena1<cijena2) printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", cijena1);
        if (cijena1>cijena2 && cijena1>cijena3) {
            if (cc1>ch1) {
                cc1=cc1 - (cc1/10);
                cijena1=cc1*2 + cp1;
                printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena1); }
                else {
                    ch1=ch1 - (ch1/10);
                    cijena1=cc1*2 + ch1;
                    printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena1);
                }
            }
        }
        
    else if ((tarik=='C' || tarik=='P' || tarik=='H') && (mirza=='C' || mirza=='P' || mirza=='H') && (bojan=='C' || bojan=='P' || bojan=='H')) {
        cijena1=cc1+cp1+ch1;
        cijena2=cc2+cp2+ch2;
        cijena3=cc3+cp3+ch3;
        if (cijena2<cijena1 && cijena2<cijena3) printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", cijena2);
        else if (cijena3<cijena2 && cijena3<cijena1) printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", cijena3);
        else if (cijena1<cijena3 && cijena1<cijena2) printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", cijena1);
        if (cijena1>cijena2 || cijena1>cijena3) {
            if (cc1>cp1 && cc1>ch1) {
                cijena1=cijena1-0.1*cc1;
                printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena1); }
            else if (ch1>cc1 && ch1>cp1) {
                cijena1=cijena1-0.1*ch1;
                printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena1); }
            else if (cp1>cc1 && cp1>ch1) {
                cijena1=cijena1-0.1*cp1;
                printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena1); }
            }
            
    }
    
    return 0;
}
        