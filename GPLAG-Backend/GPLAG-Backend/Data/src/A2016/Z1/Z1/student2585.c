#include <stdio.h>

int main() {

double ppt=0, dpt=0, prist=0, zadt=0, zavt=0, ukt=0;
int ot=0;
double ppb=0, dpb=0, prisb=0, zadb=0, zavb=0, ukb=0;
int ob=0;
double ppm=0, dpm=0, prism=0, zadm=0, zavm=0, ukm=0;
int om=0;
printf("Unesite bodove za Tarika: \n");
printf("I parcijalni ispit: ");
scanf("%lf", &ppt);
if(ppt<0 || ppt>20) {printf("Neispravan broj bodova"); return 0;}
printf("II parcijalni ispit: ");
scanf("%lf", &dpt);
if(dpt<0 || dpt>20) {printf("Neispravan broj bodova"); return 0;}
printf("Prisustvo: ");
scanf("%lf", &prist);
if(prist<0 || prist>10) {printf("Neispravan broj bodova"); return 0;}
printf("Zadace: ");
scanf("%lf", &zadt);
if(zadt<0 || zadt>10) {printf("Neispravan broj bodova"); return 0;}
printf("Zavrsni ispit: ");
scanf("%lf", &zavt);
if(zavt<0 || zavt>40) {printf("Neispravan broj bodova"); return 0;}

ukt=ppt+dpt+zadt+prist+zavt;
if(ukt<55) {ot=0;}
else {if(ukt>=55 && ukt<65) {ot=6;}
if(ukt>=65 && ukt<75) {ot=7;}
if(ukt>=75 && ukt<85) {ot=8;}
if(ukt>=85 && ukt<92) {ot=9;}
if(ukt>=92 && ukt<100) {ot=10;}}


printf("Unesite bodove za Bojana: \n");
printf("I parcijalni ispit: ");
scanf("%lf", &ppb);
if(ppb<0 || ppb>20) {printf("Neispravan broj bodova"); return 0;}
printf("II parcijalni ispit: ");
scanf("%lf", &dpb);
if(dpb<0 || dpb>20) {printf("Neispravan broj bodova"); return 0;}
printf("Prisustvo: ");
scanf("%lf", &prisb);
if(prisb<0 || prisb>10) {printf("Neispravan broj bodova"); return 0;}
printf("Zadace: ");
scanf("%lf", &zadb);
if(zadb<0 || zadb>10) {printf("Neispravan broj bodova"); return 0;}
printf("Zavrsni ispit: ");
scanf("%lf", &zavb);
if(zavb<0 || zavb>40) {printf("Neispravan broj bodova"); return 0;}

ukb=ppb+dpb+zadb+prisb+zavb;
if(ukb<55) {ob=0;}
else {if(ukb>=55 && ukb<65) {ob=6;}
if(ukb>=65 && ukb<75) {ob=7;}
if(ukb>=75 && ukb<85) {ob=8;}
if(ukb>=85 && ukb<92) {ob=9;}
if(ukb>=92 && ukb<100) {ob=10;}}


printf("Unesite bodove za Mirzu: \n");
printf("I parcijalni ispit: ");
scanf("%lf", &ppm);
if(ppm<0 || ppm>20) {printf("Neispravan broj bodova"); return 0;}
printf("II parcijalni ispit: ");
scanf("%lf", &dpm);
if(dpm<0 || dpm>20) {printf("Neispravan broj bodova"); return 0;}
printf("Prisustvo: ");
scanf("%lf", &prism);
if(prism<0 || prism>10) {printf("Neispravan broj bodova"); return 0;}
printf("Zadace: ");
scanf("%lf", &zadm);
if(zadm<0 || zadm>10) {printf("Neispravan broj bodova"); return 0;}
printf("Zavrsni ispit: ");
scanf("%lf", &zavm);
if(zavm<0 || zavm>40) {printf("Neispravan broj bodova"); return 0;}

ukm=ppm+dpm+zadm+prism+zavm;
if(ukm<55) {om=0;}
else {if(ukm>=55 && ukm<65) {om=6;}
if(ukm>=65 && ukm<75) {om=7;}
if(ukm>=75 && ukm<85) {om=8;}
if(ukm>=85 && ukm<92) {om=9;}
if(ukm>=92 && ukm<100) {om=10;}}

if(om==0 && ob==0 && ot==0) {printf("Nijedan student nije polozio."); return 0;}
if((ot!=0 && ob==0 && om==0) || (ot==0 && ob!=0 && om==0) || (ot==0 && ob==0 && om!=0)) {printf("Jedan student je polozio."); return 0;}
if((ot!=0 && ob!=0 && om==0) || (ot!=0 && ob==0 && om!=0) || (ot==0 && ob!=0 && om!=0)) {printf("Dva studenta su polozila."); return 0;}
if(ot!=0 && ob!=0 && om!=0) {printf("Sva tri studenta su polozila.\n");
    if(ot==ob && ot==om) {printf("Sva tri studenta imaju istu ocjenu."); return 0;}
    if((ot==ob && ob!=om) || (ob==om && ob!=ot) || (ot==om && ot!=ob)) {printf("Dva od tri studenta imaju istu ocjenu."); return 0;}
    if(ot!=ob && ot!=om && ob!=om) {printf("Svaki student ima razlicitu ocjenu."); return 0;}
}
return 0;
}
