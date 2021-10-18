#include <stdio.h>

int main()
{
       int RED,KOLONA,SIRINA;

       do {
              printf ("Unesite broj redova: ");
              scanf ("%d", &RED);
       } while (RED<=0 || RED>10);
       do {
              printf ("Unesite broj kolona: ");
              scanf ("%d", &KOLONA);
       } while (KOLONA<=0 || KOLONA>10);
       do {
              printf ("Unesite sirinu jedne kolone: ");
              scanf ("%d", &SIRINA);
       } while (SIRINA<=0 || SIRINA>10);

       int i,j,k;

       for (k=0; k<RED; k++) {
              for (i=0 ; i<KOLONA; i++) {
                     printf ("+");
                     
                     for (j=0; j<SIRINA; j++) {
                            printf ("-");
                     }
              }

              printf ("+");
              printf ("\n");

              for (i=0; i<KOLONA; i++) {
                     printf ("|");
                     for (j=0; j<SIRINA; j++) {
                            printf (" ");
                     }
              }
              printf ("|");
              printf ("\n");
       }

       for (i=0; i<KOLONA; i++) {
              printf ("+");
              for (j=0; j<SIRINA; j++) {
                     printf ("-");
              }
       }
       printf ("+");

       return 0;
}
