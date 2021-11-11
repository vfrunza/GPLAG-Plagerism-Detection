#include <stdio.h>

int main() {

char a;
float brc=0, brb=0,brs=0,brv=0,brp=0;
float x1,y1,z1,x2,y2;
int bru=0;
printf("Unesite vozila: ");
do 
{
    scanf("%c",&a);
    
if(a!='c' && a!='C' && a!='b' && a!='B' && a!='S' && a!='s' && a!='V' && a!='v' && a!='P' && a!='p' && a!='k' && a!='K') 
{printf("Neispravan unos\n");}
else if(a=='c' || a=='C') {brc++;bru++;}
else if(a=='b' || a=='B') {brb++;bru++;}
else if(a=='s' || a=='S') {brs++;bru++;}
else if(a=='v' || a=='V') {brv++;bru++;}
else if(a=='p' || a=='P') {brp++;bru++;}

}

while (a!='k' && a!='K');



if(bru==0) {printf("Ukupno evidentirano 0 vozila.\nNajpopularnija boja je crna (0.00%).");}
else { printf("Ukupno evidentirano %d vozila.",bru);

x1=(brc/bru)*100;
y1=(brb/bru)*100;
z1=(brs/bru)*100;
x2=(brv/bru)*100;
y2=(brp/bru)*100;

printf("\n");


if(x1>=y1 && x1>=z1 && x1>=x2 && x1>=y2) {printf("Najpopularnija boja je crna (%.2f%).", x1);}
else if(y1>=z1 && y1>=x2 && y1>=y2 && y1>=x1){printf("Najpopularnija boja je bijela (%.2f%).",y1);}
else if(z1>=x1 && z1>=y1 && z1>=x2 && z1>=y2){printf("Najpopularnija boja je siva (%.2f%).", z1);}
else if(x2>=x2 && x2>=y1 && x2>=z1 && x2>=y2){printf("Najpopularnija boja je crvena (%.2f%).", x2);}
else if(y2>=x1 && y2>=y1 && y2>=z1 && y2>=x2){printf("Najpopularnija boja je plava (%.2f%).", y2);}
}
	return 0;
}
