#include <stdio.h>

int main()
{
    char x;
    int c=0, b=0, s=0, v=0, p=0, suma=0;
    double y=0;
    
    printf ("Unesite vozila: ");
     while (1)
     {
         scanf("%c", &x);
         
         if (x=='c' || x=='C')
         {
             c++;
             
         }
         else if (x=='b' || x=='B')
         {
             b++;
             
         }
         else if (x=='s' || x=='S')
         {
             s++;
             
         }
         else if (x=='v' || x=='V')
         {
             v++;
             
         }
         else if (x=='p' || x=='P')
         {
             p++;
        }
        else if (x=='k' || x=='K')
        {
            break;
        }
        else
        {
        printf ("Neispravan unos\n");
        }
     }
     
     suma=c+b+s+v+p;
     printf ("Ukupno evidentirano %d vozila.", suma);
     
   
   double C,B,P,V,S,SUMA;
   P=p; V=v; S=s; C=c; B=b;
   
   if (suma==0)
     {
       
         printf ("\nNajpopularnija boja je crna (%.2f%%).", y);
     }
   
     else if (p>v && p>s && p>s && p>b && p>c)
     {
         y=(P/suma)*100;
         printf ("\nNajpopularnija boja je plava (%.2f%%).", y);
     }
     else if (v>=p && v>s && v>b && v>c)
     {
         y=(V/suma)*100;
         printf ("\nNajpopularnija boja je crvena (%.2f%%).", y);
     }
     else if (s>=p && s>=v && s>b && s>c)
     {
         y=(S/suma)*100;
         printf ("\nNajpopularnija boja je siva (%.2f%%).", y);
     }
     else if (b>=p && b>=v && b>=s && b>c)
     {
         y=(B/suma)*100;
         printf ("\nNajpopularnija boja je bijela (%.2f%%).", y);
     }
     else if (c>=b && c>=s && c>=v && c>=p)
     {
         y=(C/suma)*100;
         printf("\nNajpopularnija boja je crna (%.2f%%).", y);
     }
     
   
     
     return 0;
}