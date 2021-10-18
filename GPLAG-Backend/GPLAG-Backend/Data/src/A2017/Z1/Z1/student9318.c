#include <stdio.h>
#include <math.h>
#define PR 6.80
#define HR 3.30
#define CR 5.00
#define PF 8.00
#define HF 3.00
#define CF 3.90
#define PB 5.30
#define HB 5.00
#define CB 6.00
#define P 10    /*popust u postotcima*/
#define E 0.001

int main ()
{
    char t, b, m, q; 
    int i=0, j=0, k=0;
    double l1=0, l2=0, l3=0, l4=0, l5=0, l6=0, l7=0, l8=0, l9=0, min1=0, min2=0, r1=0, r2=0, r3=0, pp=0, R1=0, R2=0, R3=0; /*pp-za postotak*/
    printf ("Unesite jelo za Tarika: ");
    scanf ("%c", &t);
    scanf ("%c", &q); /*da pokupi enter iz bafera, za ubacivanje u memoriju novog znaka, jer je i enter znak, pa samo preskoci unos iduci*/
    printf ("Unesite jelo za Bojana: ");
    scanf ("%c", &b);
    scanf ("%c", &q);
    printf ("Unesite jelo za Mirzu: ");
    scanf ("%c", &m);
    scanf ("%c", &q);
    if (t=='H' || b=='H' || m=='H')
    {
        i++;
        if ((t=='H' && b=='H') || (t=='H' && m=='H') || (b=='H' && m=='H'))
            i++; 
        if (t=='H' && b=='H' && m=='H')
            i++;
    }
    if (t=='P' || b=='P' || m=='P')
    {
        j++;
        if ((t=='P' && b=='P') || (t=='P' && m=='P') || (b=='P' && m=='P'))
            j++;
        if (t=='P' && b=='P' && m=='P')
            j++;
    }
    if (t=='C' || b=='C' || m=='C')
    {
        k++;
        if ((t=='C' && b=='C') || (t=='C' && m=='C') || (b=='C' && m=='C'))
            k++;
        if (t=='C' && b=='C' && m=='C')
            k++;
    }
    if (t=='H' && b=='H' && m=='H')
    {
        l1 = HR;
        l2 = HF;
        l3 = HB;
        goto bit;
    }
    else if (t=='P' && b=='P' && m=='P')
    {
        l1 = PR;
        l2 = PF;
        l3 = PB;
        goto bit;
    }
    else if (t=='C' && b=='C' && m=='C')
    {
        l1 = CR;
        l2 = CF;
        l3 = CB;
        goto bit;
    }
    else if ((t=='H' && b=='H' && m=='P') || (t=='H' && b=='P' && m=='H') || (t=='P' && b=='H' && m=='H') || (t=='H' && b=='H' && m=='C') || (t=='H' && b=='C' && m=='H') || (t=='C' && b=='H' && m=='H') || (t=='P' && b=='P' && m=='H') || (t=='P' && b=='H' && m=='P') || (t=='H' && b=='P' && m=='P') || (t=='P' && b=='P' && m=='C') || (t=='P' && b=='C' && m=='P') || (t=='C' && b=='P' && m=='P') || (t=='C' && b=='C' && m=='H') || (t=='C' && b=='H' && m=='C') || (t=='H' && b=='C' && m=='C') || (t=='C' && b=='C' && m=='P') || (t=='C' && b=='P' && m=='C') || (t=='P' && b=='C' && m=='C'))
    {
        if ((t=='H' && b=='H' && m=='P') || (t=='H' && b=='P' && m=='H') || (t=='P' && b=='H' && m=='H') || (t=='H' && b=='H' && m=='C') || (t=='H' && b=='C' && m=='H') || (t=='C' && b=='H' && m=='H'))
        {
            if ((t=='H' && b=='H' && m=='P') || (t=='H' && b=='P' && m=='H') || (t=='P' && b=='H' && m=='H'))
            {
                l1 = HR; l4 = PR; 
                l2 = HF; l5 = PF;
                l3 = HB; l6 = PB;
                goto bit; 
            }
            else
            {
                l1 = HR; l4 = CR; 
                l2 = HF; l5 = CF;
                l3 = HB; l6 = CB;
                goto bit;
            }
        }
        else if ((t=='P' && b=='P' && m=='H') || (t=='P' && b=='H' && m=='P') || (t=='H' && b=='P' && m=='P') || (t=='P' && b=='P' && m=='C') || (t=='P' && b=='C' && m=='P') || (t=='C' && b=='P' && m=='P'))
            {
                if ((t=='P' && b=='P' && m=='H') || (t=='P' && b=='H' && m=='P') || (t=='H' && b=='P' && m=='P'))
                {
                    l1 = PR; l4 = HR; 
                    l2 = PF; l5 = HF;
                    l3 = PB; l6 = HB;
                    goto bit;
                }
                else
                {
                    l1 = PR; l4 = CR; 
                    l2 = PF; l5 = CF;
                    l3 = PB; l6 = CB;
                    goto bit;
                }
            }
        else if ((t=='C' && b=='C' && m=='H') || (t=='C' && b=='H' && m=='C') || (t=='H' && b=='C' && m=='C') || (t=='C' && b=='C' && m=='P') || (t=='C' && b=='P' && m=='C') || (t=='P' && b=='C' && m=='C'))
        {
            if ((t=='C' && b=='C' && m=='H') || (t=='C' && b=='H' && m=='C') || (t=='H' && b=='C' && m=='C'))
            {
                l1 = CR; l4 = HR; 
                l2 = CF; l5 = HF;
                l3 = CB; l6 = HB;
                goto bit;
            }
            else 
            {
                l1 = CR; l4 = PR; 
                l2 = CF; l5 = PF;
                l3 = CB; l6 = PB;
                goto bit;
            }
        }
    }
    else if ((t=='H' && b=='P' && m=='C') || (t=='H' && b=='C' && m=='P') || (t=='C' && b=='P' && m=='H') || (t=='C' && b=='H' && m=='P') || (t=='P' && b=='H' && m=='C') || (t=='P' && b=='C' && m=='H'))
        {
            l1 = PR; l4 = CR; l7 = HR;
            l2 = PF; l5 = CF; l7 = HF;
            l3 = PB; l6 = CB; l7 = HB;
            R1 = l1+l4+l7;
            R2 = l2+l5+l8;
            R3 = l3+l6+l9;
            goto bit;
           
        }
        
   bit: {
            if (i==3 || j==3 || k==3) /*sva jela ista*/
            {
                    if (t=='H' && l1<l2 && l1<l3)
                        printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", 3*l1);
                    else if (t=='H' && l2<l1 && l2<l3)
                    {
                            printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", 3*l2);
                            pp = (l1*P)/100.;
                            pp = l1-pp;
                            if ((3*l2)>(3*pp))
                                printf ("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 3*pp);
                    }
                    else if (t=='H' && l3<l1 && l3<l2)
                    {
                        printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", 3*l3);
                        pp = (l1*P)/100.;
                        pp = l1-pp;
                        if ((3*l3)>(3*pp))
                            printf ("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 3*pp);
                    }
                    else if (t=='P' && l1<l2 && l1<l3)
                        printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", 3*l1);
                    else if (t=='P' && l2<l1 && l2<l3)
                    {
                            printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", 3*l2);
                            pp = (l1*P)/100.;
                            pp = l1-pp;
                            if ((3*l2)>(3*pp))
                                printf ("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 3*pp);
                    }
                    else if (t=='P' && l3<l1 && l3<l2)
                    {
                        printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", 3*l3);
                        pp = (l1*P)/100.;
                        pp = l1-pp;
                        if ((3*l3)>(3*pp))
                            printf ("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 3*pp);
                    }
                    else if (t=='C' && l1<l2 && l1<l3)
                        printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", 3*l1);
                    else if (t=='C' && l2<l1 && l2<l3)
                    {
                            printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", 3*l2);
                            pp = (l1*P)/100.;
                            pp = l1-pp;
                            if ((3*l2)>(3*pp))
                                printf ("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 3*pp);
                    }
                    else if (t=='C' && l3<l1 && l3<l2)
                    {
                        printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", 3*l3);
                        pp = (l1*P)/100.;
                        pp = l1-pp;
                        if ((3*l3)>(3*pp))
                            printf ("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 3*pp);
                    }
            }
            else if (i==2 || j==2 || k==2) /*dva jela kombinacije*/
            {
                if (i==2) /*2H*/
                {
                    min1 = l1;                        
                    if (min1>l2)
                    {
                        min1 = l2;
                        if (min1>l3)  
                            min1 = l3;
                    }
                    min2 = l4;                        
                    if (min2>l5)
                    {
                        min2 = l5;
                        if (min2>l6)  
                            min2 =l6;
                    }
                    r1=2*l1+l4;
                        r2=2*l2+l5;
                        r3=2*l3+l6;
                    if ((fabs(min1-l1)<=E) && (fabs(min2-l4)<=E))
                        printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", 2*min1+min2);
                    else if ((fabs(min1-l2)<=E) && (fabs(min2-l5)<=E))
                        {
                            printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", 2*min1+min2);
                            if (l1<l4) /*provjera POPUSTAAAA*/
                            {
                                pp = (l4*P)/100.;
                                pp = l4-pp;
                                if ((2*min1+min2)>(2*pp+l1))
                                    printf ("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 2*pp+l1);
                            }
                            else
                            {
                                pp = (l1*P)/100.;
                                pp = l1-pp;
                                if ((2*min1+min2)>(2*pp+l4))
                                    printf ("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 2*pp+l4); 
                            }
                        }
                    else if ((fabs(min1-l3)<=E) && (fabs(min2-l6)<=E))
                    {
                        printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", 2*min1+min2);
                            if (l1<l4) /*provjera POPUSTAAAA*/
                            {
                                pp = (l4*P)/100.;
                                pp = l4-pp;
                                if ((2*min1+min2)>(2*pp+l1))
                                    printf ("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 2*pp+l1);
                            }
                            else
                            {
                                pp = (l1*P)/100.;
                                pp = l1-pp;
                                if ((2*min1+min2)>(2*pp+l4))
                                    printf ("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 2*pp+l4); 
                            }
                    }    
                    else if ((fabs(r1-r2)>E) && (fabs(r1-r3)>E) && (fabs(r2-r3)>E))
                    {
                        
                        if (r1<r2 && r1<r3)
                            printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", r1);
                        else if (r2<r1 && r2<r3)
                        {
                            printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", r2);
                            if (l1<l4)    /*provjera POPUSTAAAA*/
                            {
                                pp = (l4*P)/100.;
                                pp = l4-pp;
                                if ((2*min1+min2)>(2*pp+l1))
                                    printf ("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 2*pp+l1);
                            }
                            else
                            {
                                pp = (l1*P)/100.;
                                pp = l1-pp;
                                if ((2*min1+min2)>(2*pp+l4))
                                    printf ("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 2*pp+l4); 
                            }
                        }
                        else
                        {
                            printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", r3); 
                            if (l1<l4) /*provjera POPUSTAAAA*/
                            {
                                pp = (l4*P)/100.;
                                pp = l4-pp;
                                if (r3>(2*pp+l1))
                                    printf ("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 2*pp+l1);
                            }
                            else
                            {
                                pp = (l1*P)/100.;
                                pp = l1-pp;
                                if (r3>(2*pp+l4))
                                    printf ("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 2*pp+l4); 
                            }
                        }
                    }
                }
                else if (j==2) /*2P*/
                {
                    min1 = l1;                        
                    if (min1>l2)
                    {
                        min1 = l2;
                        if (min1>l3)  
                            min1 = l3;
                    }
                    min2 = l4;                        
                    if (min2>l5)
                    {
                        min2 = l5;
                        if (min2>l6)  
                            min2 = l6;
                    }
                    if ((fabs(min1-l1)<=E) && (fabs(min2-l4)<=E))
                        printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", 2*min1+min2);
                    else if ((fabs(min1-l2)<=E) && (fabs(min2-l5)<=E))
                        {
                            printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", 2*min1+min2);
                            pp = (l1*P)/100.;
                            pp = l1-pp;
                            if (R2>(2*pp+l5))
                                printf ("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 2*pp+l5);
                        }
                    else if ((fabs(min1-l3)<=E) && (fabs(min2-l6)<=E))
                        {
                            printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", 2*min1+min2);
                                pp = (l1*P)/100.;
                                pp = l1-pp;
                                if (R2>(2*pp+l6))
                                    printf ("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 2*pp+l6);
                        }
                    else 
                    {
                        r1=2*l1+l4;
                        r2=2*l2+l5;
                        r3=2*l3+l6;
                        if (r1<r2 && r1<r3)
                            printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", r1);
                        else if (r2<r1 && r2<r3)
                        {
                            printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", r2);
                                pp = (l1*P)/100.;
                                pp = l1-pp;
                                if (r2>(2*pp+l4))
                                    printf ("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 2*pp+l4);
                        }
                        else
                        {
                            printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", r3);
                                pp = (l1*P)/100.;
                                pp = l1-pp;
                                if (r3>(2*pp+l4))
                                    printf ("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 2*pp+l4);
                        }
                    }
                }
                else if (k==2) /*2C*/
                {
                    min1 = l1;                        
                    if (min1>l2)
                    {
                        min1 = l2;
                        if (min1>l3)  
                            min1 = l3;
                    }
                    min2 = l4;                        
                    if (min2>l5)
                    {
                        min2 = l5;
                        if (min2>l6)  
                            min2 =l6;
                    }
                    if ((fabs(min1-l1)<=E) && (fabs(min2-l4)<=E))
                        printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", 2*min1+min2);
                    else if ((fabs(min1-l2)<=E) && (fabs(min2-l5)<=E))
                        {
                            printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", 2*min1+min2);
                            pp = (l1*P)/100.;
                            pp = l1-pp;
                            if ((2*min1+min2)>(2*pp+l5))
                                printf ("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 2*pp+l5);
                        }
                    else if ((fabs(min1-l3)<=E) && (fabs(min2-l6)<=E))
                        {
                            printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", 2*min1+min2);
                            pp = (l1*P)/100.;
                            pp = l1-pp;
                            if ((2*min1+min2)>(2*pp+l6))
                                printf ("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 2*pp+l6);
                        }
                    else 
                    {
                        r1=2*l1+l4;
                        r2=2*l2+l5;
                        r3=2*l3+l6;
                        if (r1<r2 && r1<r3)
                            printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", r1);
                        else if (r2<r1 && r2<r3)
                        {
                            printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", r2);
                                pp = (l1*P)/100.;
                                pp = l1-pp;
                                if (r2>(2*pp+l4))
                                    printf ("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 2*pp+l4);
                            
                        }
                        else
                        {
                            printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", r3);
                                pp = (l1*P)/100.;
                                pp = l1-pp;
                                if (r3>(2*pp+l4))
                                    printf ("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 2*pp+l4);
                        }
                    }
                }
            }
            else if ((t=='H' && b=='P' && m=='C') || (t=='H' && b=='C' && m=='P') || (t=='C' && b=='P' && m=='H') || (t=='C' && b=='H' && m=='P') || (t=='P' && b=='H' && m=='C') || (t=='P' && b=='C' && m=='H'))
            {
                if (R1<R2 && R1<R3)
                {
                    printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", R1);
                }
                else if (R2<R1 && R2<R3)
                {
                    printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", R2);
                    if (l1>l4 && l1>l7)
                    {
                        pp = (l1*P)/100.;
                        pp = l1-pp;
                        if (R2>(pp+l4+l7))
                            printf ("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", pp+l4+l7);
                    }
                    else if (l4>l1 && l4>l7)
                    {
                        pp = (l4*P)/100.;
                        pp = l4-pp;
                        if (R2>(pp+l1+l7))
                            printf ("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", pp+l1+l7);
                    }
                    else if (l7>l1 && l7>l4)
                    {
                        pp = (l7*P)/100.;
                        pp = l7-pp;
                        if (R2>(pp+l1+l4))
                            printf ("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", pp+l1+l4);
                    }
                }
                else 
                {
                    printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", R3);
                    if (l1>l4 && l1>l7)
                    {
                        pp = (l1*P)/100.;
                        pp = l1-pp;
                        if (R3>(pp+l4+l7))
                            printf ("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", pp+l4+l7);
                    }
                    else if (l4>l1 && l4>l7)
                    {
                        pp = (l4*P)/100.;
                        pp = l4-pp;
                        if (R3>(pp+l1+l7))
                            printf ("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", pp+l1+l7);
                    }
                    else if (l7>l1 && l7>l4)
                    {
                        pp = (l7*P)/100.;
                        pp = l7-pp;
                        if (R3>(pp+l1+l4))
                            printf ("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", pp+l1+l4);
                    }
                }
            }
   }
    return 0;
}
