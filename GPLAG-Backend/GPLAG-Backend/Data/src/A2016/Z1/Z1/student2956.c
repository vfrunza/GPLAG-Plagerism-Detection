#include <stdio.h>
#include <stdlib.h>

int main()
{
   float prviT,drugiT,prisustvoT,zadaceT,zavrsniT;
   float prviB,drugiB,prisustvoB,zadaceB,zavrsniB;
   float prviM,drugiM,prisustvoM,zadaceM,zavrsniM;
   float tarik,bojan,mirza;
   float sestT,sestB,sestM,sedamT,sedamB,sedamM,osamT,osamB,osamM,devetT,devetB,devetM,desetT,desetB,desetM;

   printf("Unesite bodove za Tarika:\n");
   printf("I parcijalni ispit:");
   scanf("%f",&prviT);
   printf("Drugi parcijalni ispit:");
   scanf("%f",&drugiT);
   printf("Prisustvo:");
   scanf("%f",&prisustvoT);
   printf("Zadace:");
   scanf("%f",&zadaceT);
   printf("Zavrsni ispit:");
   scanf("%f",&zavrsniT);
    printf("Unesite bodove za Bojana:\n");
   printf("I parcijalni ispit:");
   scanf("%f",&prviB);
   printf("Drugi parcijalni ispit:");
   scanf("%f",&drugiB);
   printf("Prisustvo:");
   scanf("%f",&prisustvoB);
   printf("Zadace:");
   scanf("%f",&zadaceB);
   printf("Zavrsni ispit:");
   scanf("%f",&zavrsniB);
    printf("Unesite bodove za Mirzu:\n");
   printf("I parcijalni ispit:");
   scanf("%f",&prviM);
   printf("Drugi parcijalni ispit:");
   scanf("%f",&drugiM);
   printf("Prisustvo:");
   scanf("%f",&prisustvoM);
   printf("Zadace:");
   scanf("%f",&zadaceM);
   printf("Zavrsni ispit:");
   scanf("%f",&zavrsniM);

   if(prviB<0 || prviB>20 || prviM<0 || prviM>20 || prviT<0 || prviT>20 || drugiB<0 || drugiB>20 || drugiM<0 || drugiM>20 || drugiT<0 || drugiT>20 || prisustvoB<0 || prisustvoB>10 || prisustvoM<0 || prisustvoM>10 || prisustvoT<0 || prisustvoT>10 || zadaceB<0 || zadaceB>10 || zadaceM<0 || zadaceM>10 || zadaceT<0 || zadaceT>10 || zavrsniB<0 || zavrsniB>40 || zavrsniM<0 || zavrsniM>40 || zavrsniT<0 || zavrsniT>40) {
    printf("Neispravan broj bodova"); return 0;
   }
   tarik=prviT+drugiT+prisustvoT+zadaceT+zavrsniT;
   bojan=prviB+drugiB+prisustvoB+zadaceB+zavrsniB;
   mirza=prviM+drugiM+prisustvoM+zadaceM+zavrsniM;


   if(tarik<55 && bojan<55 && mirza<55) { printf("Nijedan student nije polozio"); return 0;}
   if((tarik>55 && bojan<55 && mirza<55)||(bojan>55 && tarik<55 && mirza<55)||(mirza>55 && tarik<55 && bojan<55)) { printf("Jedan student je polozio"); return 0;}
   if((tarik>55 && bojan>55 && mirza<55)||(tarik>55 && mirza>55 && bojan<55)||(bojan>55 && mirza>55 && tarik<55)) { printf("Dva studenta su polozila"); return 0;}
   if((tarik>=55 || tarik<65 && bojan>=55 || bojan<65 && mirza>=55 || mirza<65)||(tarik>=65 || tarik<75 && bojan>=65 || bojan<75 && mirza>=65 || mirza<75)||(tarik>=75 || tarik<85 && bojan>=75 || bojan<85 && mirza>=75 || mirza<85)||(tarik>=85 || tarik<92 && bojan>=85 || bojan<92 && mirza>=85 || mirza<92)||(tarik>=92 || tarik<=100 && bojan>=92 || bojan<=100 && mirza>=92 || mirza<=100)) {
    printf("Sva tri studenta su polozila\nSva tri imaju istu ocjenu");}
    else { printf("Sva tri studenta su polozila\nSvi studenti imaju razlicitu ocjenu ocjenu");
    return 0;
    }

}
