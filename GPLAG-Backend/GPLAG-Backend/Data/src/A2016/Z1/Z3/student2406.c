#include <stdio.h>
 
int main() 
{
    char a;
    int br=0, c=0, b=0, s=0, v=0, p=0;
    double m;
    printf("Unesite vozila: ");
    do
    {
        scanf("%c", &a); 
        if(a =='k'|| a =='K') 
        break;
        
        if(a=='c'|| a=='C')
        {br++; c++;}
        
        else if(a=='b'||a=='B')
        {br++; b++;}

        else if(a=='v'||a=='V')
        {br++;v++;}

        else if(a=='p'||a=='P')
        {br++;p++;}

        else if(a=='s'||a=='S')
        {br++;s++;}
        
            else if(a!='k'&& a!='K'&& a!='c'&& a!='C'&& a!='s'&& a!='S'&& a!='v'&&a!='V'&& a!='p'&& a!='P')
            printf("Neispravan unos\n");
    }
        while(a!='k'&& a!='K');
        printf("Ukupno evidentirano %d vozila.\n", br);
        if(br!=0)
        {   if(c>=b && c>=s && c>=p && c>=v)
                {m=(double) c*100/br;
                printf("Najpopularnija boja je crna (%.2lf%).", m);
                }
                
                else if(b>=c && b>=s && b>=p && b>=v)
                {m=(double) b*100/br;
                printf("Najpopularnija boja je bijela (%.2lf%).", m);
                }
                
                else if(s>=c && s>=b && s>=p && s>=v)
                {m=(double) s*100/br;
                printf("Najpopularnija boja je siva (%.2lf%).", m);
                }
                
                else if(v>=c && v>=b && v>=s && v>=p)
                {m=(double) v*100/br;
                printf("Najpopularnija boja je crvena (%.2lf%).", m);
                }
                
                else if(p>=b && p>=c && p>=s && p>=v)
                {m=(double) p*100/br;
                printf("Najpopularnija boja je plava (%.2lf%).", m);
                }
                
                
        }
        
                    else if(br==0)
                    {printf("Najpopularnija boja je crna (0.00%%).");}
                    
    
        
    return 0;
}