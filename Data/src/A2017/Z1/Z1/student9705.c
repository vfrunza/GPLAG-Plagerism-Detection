#include <stdio.h>
int main()
{
    double CijenaRestoran=0,CijenaFast=0,CijenaBistro=0;
    double RestHam=3.3,RestPiz=6.8,RestCev=5,FastHam=3,FastPiz=8,FastCev=3.9,BistHam=5,BistPiz=5.3,BistCev=6;
    int BrojHam=0,BrojPiz=0,BrojCev=0;
    char Tarik,Bojan,Mirza,nr;
    printf("Unesite jelo za Tarika: ");
    scanf("%c",&Tarik);
    scanf("%c",&nr);
    printf("Unesite jelo za Bojana: ");
    scanf("%c",&Bojan);
    scanf("%c",&nr);
    printf("Unesite jelo za Mirzu: ");
    scanf("%c",&Mirza);
    scanf("%c",&nr);
    if(Tarik=='H') BrojHam++;
    else if(Tarik=='P') BrojPiz++;
    else if(Tarik=='C') BrojCev++;
    if(Mirza=='H') BrojHam++;
    else if(Mirza=='P') BrojPiz++;
    else if(Mirza=='C') BrojCev++;
    if(Bojan=='H') BrojHam++;
    else if(Bojan=='P') BrojPiz++;
    else if(Bojan=='C') BrojCev++;
    CijenaRestoran=BrojHam*RestHam + BrojPiz*RestPiz + BrojCev*RestCev;
    CijenaFast=BrojHam*FastHam + BrojPiz*FastPiz + BrojCev*FastCev;
    CijenaBistro=BrojHam*BistHam + BrojPiz*BistPiz + BrojCev*BistCev;
    if(CijenaRestoran<CijenaFast && CijenaRestoran<CijenaBistro) printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",CijenaRestoran);
    else
    {
        if(CijenaFast<CijenaRestoran && CijenaFast<CijenaBistro) printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",CijenaFast);
        else printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",CijenaBistro);
        if(BrojHam>BrojPiz && BrojHam>BrojCev) RestHam*=0.9;
        else if(BrojCev>BrojPiz && BrojCev>BrojHam) RestCev*=0.9;
        else RestPiz*=0.9;
        CijenaRestoran=BrojHam*RestHam + BrojPiz*RestPiz + BrojCev*RestCev;
        if(CijenaRestoran<CijenaFast && CijenaRestoran<CijenaBistro) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",CijenaRestoran);
    }
    return 0;
}