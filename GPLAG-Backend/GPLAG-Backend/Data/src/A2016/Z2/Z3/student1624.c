#include <stdio.h>
int main ()
{
    int number, i, j, m, n;
    int mat[20][20]={{0},{0}};
        printf ("Unesite broj tacaka: ");
        scanf ("%d", &number);
        while(number>10 || number<1){
            printf ("Pogresan unos\n");
            printf ("Unesite broj tacaka: ");
            scanf ("%i", &number);
        }

        for (i=1;i<=number;i++)
        {   printf ("Unesite %d. tacku: ", i);
            scanf ("%i %i", &m, &n);
         while(m<0 || n<0 || m>19 || n>19) {printf ("Pogresan unos\n");
            printf ("Unesite %d. tacku: ", i);
            scanf ("%i %i", &m, &n);
          }
            mat[m][n]=1;
            }
        
            
            for (i=0; i<20; i++) {
                for (j=0; j<20; j++) {
                    if (mat[j][i]==1) printf ("*");
                    else printf (" ");
                        }
                printf ("\n");
            }
            
            return 0;
            }