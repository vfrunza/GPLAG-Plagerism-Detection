#include <stdio.h>
#include <math.h>
#define e 0.0001
int main() {
int brc,brb,brs,brv,brp,max;
char boja;
float najboja,brauta;
brc=0;
brb=0;
brs=0;
brv=0;
brp=0;
brauta=0;
najboja=0;

printf("Unesite vozila: ");

do {
    scanf("%c",&boja);
    if(boja!='k' && boja!='K'){
    if (boja=='C' || boja=='c'){
        brc++;
        brauta++;
    }
    else if (boja=='B' || boja=='b'){
        brb++;
        brauta++;
    }
    else if (boja=='S' || boja=='s'){
        brs++;
        brauta++;
    }
    else if (boja=='V' || boja=='v'){
        brv++;
        brauta++;
    }
    else if (boja=='P' || boja=='p'){
        brp++;
        brauta++;
    }
    
    else printf("Neispravan unos\n"); }

}
while (boja!='K' && boja!='k');

max=brc;
if (brb>max){
max=brb;}
else if (brs>max){
max=brs;}
else if (brv>max){
max=brv;}
else if (brp>max){
max=brp;}

if(fabs(brauta-0)>e)
najboja=(max*100/brauta);
else if (fabs(brauta-0)<e)
najboja=0;
printf("Ukupno evidentirano %.f vozila. \n",brauta);
if(max==brc){
    printf("Najpopularnija boja je crna (%.2f%%).",najboja);
}
else if(max==brb){
    printf("Najpopularnija boja je bijela (%.2f%%).",najboja);
}
else if(max==brs){
    printf("Najpopularnija boja je siva (%.2f%%).",najboja);
}
else if(max==brp){
    printf("Najpopularnija boja je plava (%.2f%%).",najboja);
}
else if(max==brv){
    printf("Najpopularnija boja je crvena (%.2f%%).",najboja);
}
	return 0;
}
