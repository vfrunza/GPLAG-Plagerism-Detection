#include <stdio.h>
int main ()
{
    int crna=0, bijela=0, siva=0, crvena=0, plava=0;
    char slovo;
    float udio;
    int brojac=0;
    printf("Unesite vozila: ");
    while(scanf("%c", &slovo))
    {
        
        if(slovo=='k' || slovo=='K') break;
        else if(slovo=='c' || slovo=='C') { crna++; brojac++; }
        else if(slovo=='b' || slovo=='B') { bijela++; brojac++; }
        else if(slovo=='s' || slovo=='S') { siva++; brojac++; }
        else if(slovo=='v' || slovo=='V') { crvena++; brojac++; }
        else if(slovo=='p' || slovo=='P') { plava++; brojac++; }
        else printf("Neispravan unos\n");
    }
    
    
    printf("Ukupno evidentirano %d vozila.\n", brojac);
    if(crna>=bijela && crna>=siva && crna>=crvena && crna>=plava)
    {
        if(brojac!=0) { 
        udio=((crna*100.00)/brojac);
        printf("Najpopularnija boja je crna (%.2f%%).\n", udio);
        return 0;
        }
        else /*dijeljenje sa nulom nan */
        {
            printf("Najpopularnija boja je crna (0.00%%).\n");
            return 0;
        }
    }
    if(bijela>crna && bijela>=siva && bijela>=crvena && bijela>=plava)
    {
        udio=((bijela*100.00)/brojac);
        printf("Najpopularnija boja je bijela (%.2f%%).\n", udio);
        return 0;
    }
    if(siva>crna && siva>bijela && siva>=crvena && siva>=plava)
    {
        udio=((siva*100.00)/brojac);
        printf("Najpopularnija boja je siva (%.2f%%).\n", udio);
        return 0;
    }
    if(crvena>crna && crvena>bijela && crvena>siva && crvena>=plava)
    {
        udio=((crvena*100.00)/brojac);
        printf("Najpopularnija boja je crvena (%.2f%%).\n", udio);
        return 0;
    }
    if(plava>crna && plava>bijela && plava>siva && plava>crvena)
    {
        udio=((plava*100.00)/brojac);
        printf("Najpopularnija boja je plava (%.2f%%).\n", udio);
        return 0;
    }
   
    return 0;
}