#include <stdio.h>

int main() {
int crna,bijela,siva,crvena,plava;
char c;
int brojac=0;
int max;
crna=0;
bijela=0;
siva=0;
crvena=0;
plava=0;

printf("Unesite vozila: ");
while(1){
scanf("%c",&c);
if(c!='c'&&c!='C'&&c!='b'&&c!='B'&&c!='s'&&c!='S'&&c!='v'&&c!='V'&&c!='P'&&c!='p'&&c!='k'&&c!='K'){
	printf("Neispravan unos\n");
}

	if(c=='C'||c=='c'){
		brojac++;
	crna++;}
else 	if(c=='B'||c=='b'){
	brojac++;
bijela++;}
else	if(c=='S'||c=='s'){
	brojac++;
siva++;}
else 	if(c=='V'||c=='v'){
	brojac++;
crvena++;}
	else if(c=='P'||c=='p'){
		brojac++;
	plava++;}

else	if(c=='k'||c=='K'){
		break;
	}
}

 max=crna;

if(max<=bijela&&bijela!=crna){
	max=bijela;

}
 if(max<=siva&&siva!=bijela&&siva!=crna){
	max=siva;

}
if(max<=crvena&&crvena!=siva&&crvena!=bijela&&crvena!=crna){
	max=crvena;

}
 if(max<=plava&&plava!=crvena&&plava!=siva&&plava!=crna&&plava!=bijela){
	max=plava;

}
printf("Ukupno evidentirano %d vozila.\n",brojac);

 if(max==crna){
 	if(brojac==0){
 		printf("Najpopularnija boja je crna (0.00%%).");
 	}else
	printf("Najpopularnija boja je crna (%.2f%%).",crna/(float)brojac*100);

}
else if(max==bijela){
	printf("Najpopularnija boja je bijela (%.2f%%).",bijela/(float)brojac*100);

}
else if(max==siva){
	printf("Najpopularnija boja je siva (%.2f%%).",siva/(float)brojac*100);

}
else if(max==crvena){
	printf("Najpopularnija boja je crvena (%.2f%%).",crvena/(float)brojac*100);

}
else if(max==plava){
	printf("Najpopularnija boja je plava (%.2f%%).",plava/(float)brojac*100);

}

	return 0;
}
