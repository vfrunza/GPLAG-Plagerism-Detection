#include <stdio.h>

int main()
{
  float PP, DP, P, Z, Zavrsni, Tarik, Bojan, Mirza;
    int TO, BO, MO;
        printf("Unesite bodove za Tarika:");
        printf("\nI parcijalni ispit: ");
        scanf("%f", &PP);
    if(PP<0||PP>20)
    {
        printf("Neispravan broj bodova");
    return 0;
}
        printf("II parcijalni ispit: ");
        scanf("%f", &DP);
    if(DP<0||DP>20)
   {
        printf("Neispravan broj bodova");
    return 0;
}
        printf("Prisustvo: ");
        scanf("%f", &P);
    if(P<0||P>10)
    {
        printf("Neispravan broj bodova");
    return 0;
}
        printf("Zadace: ");
        scanf("%f", &Z);
    if(Z<0||Z>10)
    {
        printf("Neispravan broj bodova");
    return 0;
}
        printf("Zavrsni ispit: ");
        scanf("%f", &Zavrsni);
   if(Zavrsni<0||Zavrsni>40)
   {
       printf("Neispravan broj bodova");
    return 0;
}
Tarik=PP+DP+P+Z+Zavrsni;
    if(Tarik<55)
    TO=5;
    else if(Tarik>=55&&Tarik<65)
    TO=6;
    else if(Tarik>=65&&Tarik<75)
    TO=7;
    else if(Tarik>=75&&Tarik<85)
    TO=8;
    else if(Tarik>=85&&Tarik<92)
    TO=9;
    else if(Tarik>=92&&Tarik<=100)
    TO=10;
    
        printf("Unesite bodove za Bojana:");
        printf("\nI parcijalni ispit: ");
        scanf("%f", &PP);
    if(PP<0||PP>20)
    {
        printf("Neispravan broj bodova");
    return 0;
}
        printf("II parcijalni ispit: ");
        scanf("%f", &DP);
    if(DP<0||DP>20)
   {
        printf("Neispravan broj bodova");
    return 0;
}
        printf("Prisustvo: ");
        scanf("%f", &P);
    if(P<0||P>10)
    {
        printf("Neispravan broj bodova");
    return 0;
}
        printf("Zadace: ");
        scanf("%f", &Z);
    if(Z<0||Z>10)
    {
        printf("Neispravan broj bodova");
    return 0;
}
        printf("Zavrsni ispit: ");
        scanf("%f", &Zavrsni);
   if(Zavrsni<0||Zavrsni>40)
   {
       printf("Neispravan broj bodova");
    return 0;
}
Bojan=PP+DP+P+Z+Zavrsni;
    if(Tarik<55)
    BO=5;
    else if(Bojan>=55&&Bojan<65)
    BO=6;
    else if(Bojan>=65&&Bojan<75)
    BO=7;
    else if(Bojan>=75&&Bojan<85)
    BO=8;
    else if(Bojan>=85&&Bojan<92)
    BO=9;
    else if(Bojan>=92&&Bojan<=100)
    BO=10;
    
    printf("Unesite bodove za Mirzu:");
        printf("\nI parcijalni ispit: ");
        scanf("%f", &PP);
    if(PP<0||PP>20)
    {
        printf("Neispravan broj bodova");
    return 0;
}
        printf("II parcijalni ispit: ");
        scanf("%f", &DP);
    if(DP<0||DP>20)
   {
        printf("Neispravan broj bodova");
    return 0;
}
        printf("Prisustvo: ");
        scanf("%f", &P);
    if(P<0||P>10)
    {
        printf("Neispravan broj bodova");
    return 0;
}
        printf("Zadace: ");
        scanf("%f", &Z);
    if(Z<0||Z>10)
    {
        printf("Neispravan broj bodova");
    return 0;
}
        printf("Zavrsni ispit: ");
        scanf("%f", &Zavrsni);
   if(Zavrsni<0||Zavrsni>40)
   {
       printf("Neispravan broj bodova");
    return 0;
}
Mirza=PP+DP+P+Z+Zavrsni;
    if(Mirza<55)
    MO=5;
    else if(Mirza>=55&&Mirza<65)
    MO=6;
    else if(Mirza>=65&&Mirza<75)
    MO=7;
    else if(Mirza>=75&&Mirza<85)
    MO=8;
    else if(Mirza>=85&&Mirza<92)
    MO=9;
    else if(Mirza>=92&&Mirza<=100)
    MO=10;
    
    if(TO==5 && BO==5 && MO==5)
        printf("Nijedan student nije polozio.");
    else if((TO>5 && BO==5 && MO==5) || (TO==5 && BO>5 && MO==5) || (TO==5 && BO==5 && MO>5))
        printf("Jedan student je polozio.");
    else if((TO>5 && BO>5 && MO==5) || (TO>5 && BO==5 && MO>5) || (TO==5 && BO>5 && MO>5))
        printf("Dva studenta su polozila.");
    else if(TO>5 && BO>5 && MO>5)
    {
        printf("Sva tri studenta su polozila.");
    if(TO==BO && BO==MO)
       printf("\nSva tri studenta imaju istu ocjenu.");
    else if((TO==BO && BO!=MO) || (TO==MO && BO!=MO) || (MO==BO && TO!=MO))
       printf("\nDva od tri studenta imaju istu ocjenu.");
    else if(TO!=BO && BO!=MO && TO!=MO)
       printf("\nSvaki student ima razlicitu ocjenu.");
}
    return 0;

}
        
        

   
