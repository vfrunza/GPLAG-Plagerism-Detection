#include <stdio.h>

int main() {
char TARIK,MIRZA,BOJAN,novi_red;
double H1=3.30,H2=3.00,H3=5.00,P1=6.80,P2=8.00,P3=5.30,C1=5.00,C2=3.90,C3=6.00,ukupno1=0,ukupno2=0,ukupno3=0,najmanje=0;
double popust1=0,popust2=0,popust3=0;
int br_h=0,br_p=0,br_c=0;
printf("Unesite jelo za Tarika: ");
scanf("%c",&TARIK);
scanf("%c",&novi_red);
printf("Unesite jelo za Bojana: ");
scanf("%c",&BOJAN);
scanf("%c",&novi_red);
printf("Unesite jelo za Mirzu: ");
scanf("%c",&MIRZA);
scanf("%c",&novi_red);
if(TARIK=='H'){
    ukupno1+=H1;
    ukupno2+=H2;
    ukupno3+=H3;
    br_h++;
}else if(TARIK=='P'){
    ukupno1+=P1;
    ukupno2+=P2;
    ukupno3+=P3;
    br_p++;
}else if(TARIK=='C'){
    ukupno1+=C1;
    ukupno2+=C2;
    ukupno3+=C3;
    br_c++;
}if(BOJAN=='H'){
    ukupno1+=H1;
    ukupno2+=H2;
    ukupno3+=H3;
    br_h++;
}else if(BOJAN=='P'){
    ukupno1+=P1;
    ukupno2+=P2;
    ukupno3+=P3;
    br_p++;
}else if(BOJAN=='C'){
    ukupno1+=C1;
    ukupno2+=C2;
    ukupno3+=C3;
    br_c++;
}if(MIRZA=='H'){
    ukupno1+=H1;
    ukupno2+=H2;
    ukupno3+=H3;
    br_h++;
}else if(MIRZA=='P'){
    ukupno1+=P1;
    ukupno2+=P2;
    ukupno3+=P3;
    br_p++;
}else if(MIRZA=='C'){
    ukupno1+=C1;
    ukupno2+=C2;
    ukupno3+=C3;
    br_c++;
}printf("Najjeftiniji je ");
if(ukupno1<ukupno2 && ukupno1<ukupno3){
    najmanje=ukupno1;
    printf("Restoran \"Kod konja i konjusara\" (%.2f KM).",najmanje);
    return 0;
}else if(ukupno2<ukupno1 && ukupno2<ukupno3){
    najmanje=ukupno2;
    printf("Fast-food \"Trovac\" (%.2f KM).",najmanje);
}else if(ukupno3<ukupno1 && ukupno3<ukupno2){
    najmanje=ukupno3;
    printf("Bistro \"Lorelei\" (%.2f KM).",najmanje);
}popust1=H1*0.1*(double)(br_h);
popust2=P1*0.1*(double)(br_p);
popust3=C1*0.1*(double)(br_c);
if(popust1>popust2 && popust1>popust3 && popust1>0){
    ukupno1-=popust1;
    if(ukupno1<najmanje) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",ukupno1);
}else if(popust2>popust1 && popust2>popust3 && popust2>0){
    ukupno1-=popust2;
    if (ukupno1<najmanje) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",ukupno1);
}else if(popust3>popust1 && popust3>popust2 && popust3>0){
    ukupno1-=popust3;
    if(ukupno1<najmanje) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",ukupno1);
}
	return 0;
}
