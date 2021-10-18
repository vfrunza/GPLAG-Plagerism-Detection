#include <stdio.h>

int main() {
int i,j,brk=0,brr=0,sk=0,k;

do

{
    printf ("Unesite broj redova: ");
    scanf ("%d", &brr);
   
}

while (brr<1 || brr>10);

do

{
    printf ("Unesite broj kolona: ");
    scanf ("%d", &brk);
}

while (brk<1 || brk>10);

do

{
    printf ("Unesite sirinu jedne kolone: ");
    scanf ("%d", &sk);
}

while (sk<1 || sk>10);




for (i=0; i<brr; i++)
{
    for (j=0; j<brk; j++)
    {
         printf ("+");
       
        for (k=0; k<sk; k++)
        {
            printf ("-");
        }
        
    }
    printf ("+");
       printf ("\n");
       
       for (j=0; j<brk; j++)
       
       {
           printf ("|");
           
           for (k=0; k<sk; k++)
           {
           printf  (" ");
           }
       }
       printf ("|");
       printf ("\n");
      
      
    
}
    
 
    for (j=0; j<brk; j++)
    {
         printf ("+");
       
        for (k=0; k<sk; k++)
        {
            printf ("-");
        }
        
    }
    printf ("+");





	return 0;
}
