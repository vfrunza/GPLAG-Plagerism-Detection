#include <stdio.h>
#include <math.h>
#define epsilon 0.0001

int main ()
{
    float postotakcrna, postotakbijela, postotaksiva, postotakcrvena, postotakplava, max=0;
    int UKUPNO, crna=0, bijela=0, siva=0, crvena=0, plava=0;
    char slovo;
    
    printf("Unesite vozila: ");
    
    while ((slovo=getchar())!='K' && slovo!='k')
    {
        if (slovo=='C' || slovo=='c')
        crna++;
        if (slovo=='B' || slovo=='b')
        bijela++;
        if (slovo=='S' || slovo=='s')
        siva++;
        if (slovo=='V' || slovo=='v')
        crvena++;
        if (slovo=='P' || slovo=='p')
        plava++;
        else if(slovo!='C' && slovo!='c' && slovo!='B' && slovo!='b' && slovo!='S' && slovo!='s' && slovo!='V' && slovo!='v' && slovo!='P' && slovo!='p')
        {
            printf("Neispravan unos\n");
        }
    }
    
    UKUPNO=crna+bijela+siva+crvena+plava;
    
    printf("Ukupno evidentirano %d vozila.\n", UKUPNO);
    
    postotakcrna=(crna/(float)UKUPNO)*100;
    postotakbijela=(bijela/(float)UKUPNO)*100;
    postotaksiva=(siva/(float)UKUPNO)*100;
    postotakcrvena=(crvena/(float)UKUPNO)*100;
    postotakplava=(plava/(float)UKUPNO)*100;
    
    if (UKUPNO==0)
    printf("Najpopularnija boja je crna (0.00%%).");
    
    else
    {
        if (postotakcrna>max)
        max=postotakcrna;
        if (postotakbijela>max)
        max=postotakbijela;
        if (postotaksiva>max)
        max=postotaksiva;
        if (postotakcrvena>max)
        max=postotakcrvena;
        if (postotakplava>max)
        max=postotakplava;
    }
    
    if (fabs(max-postotakcrna)<epsilon)
    printf("Najpopularnija boja je crna (%.2f%%).", postotakcrna);
    else if (fabs(max-postotakbijela)<epsilon)
    printf("Najpopularnija boja je bijela (%.2f%%).", postotakbijela);
    else if (fabs(max-postotaksiva)<epsilon)
    printf("Najpopularnija boja je siva (%.2f%%).", postotaksiva);
    else if (fabs(max-postotakcrvena)<epsilon)
    printf("Najpopularnija boja je crvena (%.2f%%).", postotakcrvena);
    else if (fabs(max-postotakplava)<epsilon)
    printf("Najpopularnija boja je plava (%.2f%%).", postotakplava);
    
    return 0;
}