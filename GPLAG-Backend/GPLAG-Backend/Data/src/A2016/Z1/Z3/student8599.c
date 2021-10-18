#include <stdio.h>

int main(){
    int CU=0, BU=0, SU=0, VU=0, PU=0, U;
    char a;
    float x;
    printf("Unesite vozila: ");
    do{
    scanf("%c", &a);
    if(a=='\n') continue;
     if(a!='C' && a!='c' && a!='B' && a!='b' && a!='S' && a!='s' && a!='V' && a!='v' && a!='P' && a!='p' && a!='k' && a!='K'){
    printf("Neispravan unos\n");
     }
    if(a=='C' || a=='c')
        CU+=1;
    else if(a=='B'|| a=='b')
        BU+=1;
    else if(a=='S' || a=='s')
        SU+=1;
        else if(a=='V' || a=='v')
        VU+=1;
        else if(a=='P' || a=='p')
        PU+=1;
    } while(a!='K' && a!='k');
U=CU+BU+SU+VU+PU;
printf("Ukupno evidentirano %d vozila.\n", U);
if(U==0)
    printf("Najpopularnija boja je crna (0.00%).");

else if(CU>=BU && CU>=SU && CU>=VU && CU>=PU){
    x=((float)CU)/U*100;
    printf("Najpopularnija boja je crna (%.2f%%).", x);
}
else if(BU>CU && BU>=SU && BU>=VU && BU>=PU){
    x=((float)BU)/U*100;
    printf("Najpopularnija boja je bijela (%.2f%%).", x);
}
else if(SU>CU && SU>BU && SU>=VU && SU>=PU){
    x=((float)SU)/U*100;
    printf("Najpopularnija boja je siva (%.2f%%).", x);
}
else if(VU>CU && VU>BU && BU>SU && CU>=PU){
    x=((float)VU)/U*100;
    printf("Najpopularnija boja je crvena (%.2f%%).", x);
}
else if(PU>CU && PU>BU && PU>SU && PU>VU){
    x=((float)PU)/U*100;
    printf("Najpopularnija boja je plava (%.2f%%).", x);
}
return 0;
}