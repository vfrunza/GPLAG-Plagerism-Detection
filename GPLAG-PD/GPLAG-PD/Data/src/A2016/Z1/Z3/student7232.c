#include <stdio.h>

int main()
{
    int C,B,S,V,P,br;
    float maksimal, postotak;
    char x;
    br=0;
    C=B=S=V=P=0;
    
    printf("Unesite vozila: ");
    do{
        scanf("%c", &x);
        if(x=='C'||x=='c')
        {
            C+=1;
        }
        else if(x=='B'||x=='b')
        {
            B+=1;
        }
        else if(x=='S'||x=='s')
        {
            S+=1;
        }
        else if(x=='V'||x=='v')
        {
            V+=1;
        }
        else if(x=='P'||x=='p')
        {
            P+=1;
        }
        else if(x=='\n'||x=='K'||x=='k')
        {
        }
        else
        {
            printf("Neispravan unos\n");
        }
    }while(x!='K'&&x!='k');
    
    br=C+B+S+V+P;
    printf("Ukupno evidentirano %d vozila.\n", br);
    if(br==0)
    {
        printf("Najpopularnija boja je crna (0.00%%).");
        return 0;
    }
    maksimal=C;
    if(B>maksimal)
    {
        maksimal=B;
    }
    if(S>maksimal)
    {
        maksimal=S;
    }
     if(V>maksimal)
    {
        maksimal=V;
    }
    if(P>maksimal)
    {
        maksimal=P;
    }
    
    postotak=maksimal/br*100;
    
    if(C==maksimal)
    {
        printf("Najpopularnija boja je crna (%.2f%%).",postotak);
        return 0;
    }
    else if (B==maksimal)
    {
        printf("Najpopularnija boja je bijela (%.2f%%).",postotak);
    }
    else if (S==maksimal)
    {
        printf("Najpopularnija boja je siva (%.2f%%).",postotak);
    }
    else if (V==maksimal)
    {
        printf("Najpopularnija boja je crvena (%.2f%%).",postotak);
    }
    else
    {
        printf("Najpopularnija boja je plava (%.2f%%).",postotak);
    }
    return 0;
}