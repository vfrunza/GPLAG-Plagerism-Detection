#include <stdio.h>
#include <math.h>
#define epsilon 0.0001

int main() {
    char a;
    int i, br;
    double max,c, p , s, v, b;
    br=0;
    c=0;
    p=0;
    s=0;
    b=0;
    v=0;
    printf("Unesite vozila: ");
    for(i=0;i<1; )
    {
        scanf("%c", &a);
        if((a!='c')&&(a!='C')&&(a!='b')&&(a!='B')&&(a!='s')&&(a!='S')&&(a!='v')&&(a!='V')&&(a!='p')&&(a!='P')&&(a!='k')&&(a!='K'))
        printf("Neispravan unos\n");
        
    
        if((a=='c')||(a=='C'))
        {
             br=br+1;
             c++;
        }
        else if((a=='B')||(a=='b'))
        {
            br=br+1;
            b++;
            
        }
        else if((a=='S')||(a=='s'))
        {
             br=br+1;
             s++;
        }
        else if((a=='P')||(a=='p'))
        {
             br=br+1;
             p++;
        }
        else if((a=='v')||(a=='V'))
        {
             br=br+1;
             v++;
        }
       
        else if((a=='k')||(a=='K'))
        i++;
        
    }
    printf("Ukupno evidentirano %d vozila.\n", br);
    if(br==0)
    printf("Najpopularnija boja je crna (%.2f%%).", c);
    else
    {
    c=(c*100)/br;
    b=(b*100)/br;
    s=(s*100)/br;
    p=(p*100)/br;
    v=(v*100)/br;
    
    
    max=c;
    if(b>max)
        max=b;
    if(s>max)
        max=s;
    if(p>max)
        max=p;
    if(v>max)
        max=v;
        
    printf("Najpopularnija boja je ");
    if(fabs(max-c)<epsilon)
       printf("crna (%.2f%%).", c);
    else  if(fabs(max-b)<epsilon)
     printf("bijela (%.2f%%).", b);
    else if(fabs(max-s)<epsilon)
     printf("siva (%.2f%%).", s);
    else  if(fabs(max-v)<epsilon)
     printf("crvena (%.2f%%).", v);
    else  if(fabs(max-p)<epsilon)
     printf("plava (%.2f%%).", p);
     
    
     
    }
       

	return 0;
}
