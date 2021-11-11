#include <stdio.h>
#include <math.h>
#define P1 6.80
#define P2 8.00
#define P3 5.30
#define H1 3.30
#define H2 3.00
#define H3 5.00
#define C1 5.00
#define C2 3.90
#define C3 6.00
int main() {float R,F,BI,F1,R1,L,R2,F2,F3,F4,F5,R3,L1;
char novi_red,T,B,M;
printf("Unesite jelo za Tarika: ");
scanf("%c",&T);
scanf("\n",&novi_red);
printf("Unesite jelo za Bojana: ");
scanf("%c",&B);
scanf("\n",&novi_red);
printf("Unesite jelo za Mirzu: ");
scanf("%c",&M);
scanf("\n",&novi_red);
if(T=='P' && B=='P' && M=='P'){
    BI=3*P3;
    printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",BI);}
if(T=='H' && B=='H' && M=='H'){
    F=3*H2;
    R=(3*H1)-(3*H1*10/100);  
    printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",F);
    printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",R);}
if(T=='C' && B=='C' && M=='C'){
    F1=3*C2;
    printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",F1);}
else if((T=='P' && B=='P' && M=='H') || (T=='P' && B=='H' && M=='P') || (T=='H' && B=='P' && M=='P')){
    L=2*P3+H3;
    R1=(2*P1+H1)-2*P1*10/100;
    printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",L);
    printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",R1);}
else if((T=='P' && B=='P' && M=='C') || (T=='P' && B=='C' && M=='P') || (T=='C' && B=='P' && M=='P')){
    L1=2*P3+C3;
    printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",L1);
}
else if((T=='H' && B=='H' && M=='P') || (T=='H' && B=='P' && M=='H') || (T=='P' && B=='H' && M=='H')){
    R2=2*H1+P1;
    printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",R2);
}
else if((T=='H' && B=='H' && M=='C') || (T=='H' && B=='C' && M=='H') || (T=='C' && B=='H' && M=='H')){
    F2=2*H2+C2;
    printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",F2);
}
else if((T=='C' && B=='C' && M=='P') || (T=='C' && B=='P' && M=='C') || (T=='P' && B=='C' && M=='C')){
    F3=2*C2+P2;
    printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",F3);
}
else if((T=='C' && B=='C' && M=='H') || (T=='C' && B=='H' && M=='C') || (T=='H' && B=='C' && M=='C')){
    F4=2*C2+H2;
    printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",F4);
}
else if((T=='P' && B=='H' && M=='C') || (T=='P' && B=='C' && M=='H') || (T=='H' && B=='P' && M=='C') || (T=='H' && B=='C' && M=='P') || (T=='C' && B=='H' && M=='P') || (T=='C' && B=='P' && M=='H')){
    F5=P2+H2+C2;
    R3=(P1+H1+C1)-(P1*10/100);
    printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",F5);
    printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",R3);
}

return 0;
    


}
