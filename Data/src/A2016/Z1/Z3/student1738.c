#include <stdio.h>
int main ()
{
    float pr;
    char slovo;
    int c=0,b=0,s=0,v=0,p=0,u;
    
    printf ("Unesite vozila: ");
    
        do
        {
            scanf ("%c",&slovo);
        
            
            if (slovo=='c'||slovo=='C')
            {
                c++;
                continue;
            }
            else if (slovo=='b'||slovo=='B')
            {
                b++;
                continue;
            }
            else if (slovo=='s'||slovo=='S')
            {
                s++;
                continue;
            }
            else if (slovo=='v'||slovo=='V')
            {
                v++;
                continue;
            }
            else if (slovo=='p'||slovo=='P')
            {
                p++;
                continue;
            }
            else if (slovo=='k'|| slovo=='K')
            {
                break;
            }
            else if (slovo=='\n')
            {
                continue;
            }
            else
            {
                printf ("Neispravan unos\n");
            }
            
        }while (slovo!='k'||slovo!='K');
        
    u=c+b+s+v+p;
    printf ("Ukupno evidentirano %i vozila.",u);
    if (u==0)
    {
        printf ("\nNajpopularnija boja je crna (0.00%%).");
    }
    
    
    /*poredjenje*/
    else if (c>=b&&c>=s&&c>=v&&c>=p)
    {
        
        pr=(100*c)/(1.0*u);
        printf ("\nNajpopularnija boja je crna (%2.2f%%).",pr);
    }
    else if (b>=c&&b>=s&&b>=v&&b>=p)
    {
        if (b>c)
        {
            pr=(100*b)/(1.0*u);
            printf ("\nNajpopularnija boja je bijela (%2.2f%%).",pr);
        }
        else if (b>=c)
        {
            pr=(100*c)/(1.0*u);
            printf ("\nNajpopularnija boja je crna (%2.2f%%).",pr);
        }
        
    }
    else if (s>=b&&s>=c&&s>=v&&s>=p)
    {
        if (s==c)
        {
            pr=(100*c)/(1.0*u);
            printf ("\nNajpopularnija boja je crna (%2.2f%%).",pr);
        }
        else if (s==b)
        {
            pr=(100*b)/(1.0*u);
            printf ("\nNajpopularnija boja je bijela (%2.2f%%).",pr);
        }
        else
        {
            pr=(100*s)/(1.0*u);
            printf ("\nNajpopularnija boja je siva (%2.2f%%).",pr);
        }
    }
    else if (v>=b&&v>=s&&v>=c&&v>=p)
    {
        if (v==c)
        {
            pr=(100*c)/(1.0*u);
            printf ("\nNajpopularnija boja je crna (%2.2f%%).",pr);
        }
        else if (v==b)
        {
            pr=(100*b)/(1.0*u);
            printf ("\nNajpopularnija boja je bijela (%2.2f%%).",pr);
        }
        else if (v==s)
        {
            pr=(100*s)/(1.0*u);
            printf ("\nNajpopularnija boja je siva (%2.2f%%).",pr);
        }
        else
        {
            pr=(100*v)/(1.0*u);
            printf ("\nNajpopularnija boja je crvena (%2.2f%%).",pr);
        }
    }
    else if (p>=b&&p>=s&&p>=v&&p>=c)
    {
        if (p==c)
        {
            pr=(100*c)/(1.0*u);
            printf ("\nNajpopularnija boja je crna (%2.2f%%).",pr);
        }
        else if (p==b)
        {
            pr=(100*b)/(1.0*u);
            printf ("\nNajpopularnija boja je bijela (%2.2f%%).",pr);
        }
        else if (p==s)
        {
            pr=(100*s)/(1.0*u);
            printf ("\nNajpopularnija boja je siva (%2.2f%%).",pr);
        }
        else if (p==v)
        {
            pr=(100*v)/(1.0*u);
            printf ("\nNajpopularnija boja je crvena (%2.2f%%).",pr);
        }
        else 
        {
            pr=(100*p)/(1.0*u);
            printf ("\nNajpopularnija boja je plava (%2.2f%%).",pr);
        }
    }
    
    return 0;
}