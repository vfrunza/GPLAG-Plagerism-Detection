#include <stdio.h>

int main() {
 float brcrna=0,brbijela=0,brsiva=0,brcrvena=0,brplava=0,brvozila=0;
 float crna=0.0,bijela=0.0,siva=0.0,crvena=0.0,plava=0.0;
 char znak;
 printf("Unesite vozila: ");
 do
 {
 	scanf("%c", &znak);
 	if((znak=='C')|| (znak=='c')){
 		brcrna++;
 		continue;
 		}
 	if ((znak=='B') || (znak=='b')){
 		brbijela++;
   continue;
 		}
 	if ((znak=='S') || (znak=='s')){
 		brsiva++; 
 		continue;
 	}
 	if ((znak=='V') || (znak=='v')){
 		brcrvena++;
 		continue;
 	}
 	if ((znak=='P') || (znak=='p')){
 		brplava++; 
 		continue;
 	}
 	if(((znak!='C')&&(znak!='c'))&&((znak!='B')&&(znak!='b'))&&((znak!='S')&&(znak!='s'))&&((znak!='V')&&(znak!='v'))&&((znak!='P')&&(znak!='p'))&&((znak!='K')&&(znak!='k'))){
 	 printf("Neispravan unos\n");
 	}
 	} 
 	while ((znak!='K')&&(znak!='k')); 
 		brvozila=brcrna+brbijela+brsiva+brcrvena+brplava;
 		printf("Ukupno evidentirano %g vozila.\n", brvozila);
 		if(brvozila!=0){
   crna=(brcrna*100)/brvozila;
   bijela=(brbijela*100)/brvozila;
   siva=(brsiva*100)/brvozila;
   crvena=(brcrvena*100)/brvozila;
   plava=(brplava*100)/brvozila;
 		}
 	if((brcrna>=brbijela)&&(brcrna>=brsiva)&&(brcrna>=brcrvena)&&(brcrna>=brplava)){
 	printf("Najpopularnija boja je crna (%.2f%%).", crna);
 	return 0;
 	}
 	if((brsiva>=brcrna)&&(brsiva>=brbijela)&&(brsiva>=brcrvena)&&(brsiva>=brplava)){
  printf("Najpopularnija boja je siva (%.2f%%).", siva);
  return 0;
 	}
  if((brbijela>=brcrna)&&(brbijela>=brsiva)&&(brbijela>=brcrvena)&&(brbijela>=brplava)){ 
  printf("Najpopularnija boja je bijela (%.2f%%).", bijela);
  return 0;
  }
  if((brcrvena>=brcrna)&&(brcrvena>=brsiva)&&(brcrvena>=brbijela)&&(brcrvena>=brplava)){
  printf("Najpopularnija boja je crvena (%.2f%%).", crvena);
  return 0;
  }
  if((brplava>=brcrna)&&(brplava>=brsiva)&&(brplava>=brbijela)&&(brplava>=brcrvena)){
  printf("Najpopularnija boja je plava (%.2f%%).", plava);
  return 0;
}
return 0;
}