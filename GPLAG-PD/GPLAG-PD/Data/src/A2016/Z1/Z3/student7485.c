#include <stdio.h>

int main() {
	
	char a;
	int ub,bc=0,bb=0,bs=0,bv=0,bp=0,max=0;
	float proc;
	
	printf("Unesite vozila: ");
	
	do{
		scanf("%c", &a);
	if((a=='c') || (a=='C')){
		bc++;
	}
	else if((a=='b') || (a=='B')){
		bb++;
	}
	else if((a=='s') || (a=='S')){
		bs++;
	}
	else if((a=='v') || (a=='V')){
		bv++;
	}
	else if((a=='p') || (a=='P')){
		bp++;
	}
	else if ((a=='k') || (a=='K'))
		break;
	else {
		printf("Neispravan unos\n");}
	
	ub=bc+bb+bs+bv+bp;
	} while(1);
  printf("Ukupno evidentirano %d vozila. \n", ub);
  
 max=bc;
 if(bb>max) max=bb;
 if(bs>max) max=bs;
 if(bv>max) max=bv;
 if(bp>max) max=bp;

if (ub==0){
	printf("Najpopularnija boja je crna (0.00%%).");
}
else if (max==bc){
	proc=((float)bc/ub)*100;
	printf("Najpopularnija boja je crna (%.2f%%).", proc);
}
else if(max==bb){
	proc=((float)bb/ub)*100;
	printf("Najpopularnija boja je bijela (%.2f%%).", proc);
}
else if (max==bs){
	proc=((float)bs/ub)*100;
	printf("Najpopularnija boja je siva (%.2f%%).", proc);
}
else if (max==bv){
	proc=((float)bv/ub)*100;
	printf("Najpopularnija boja je crvena (%.2f%%).", proc);
}
else if (max==bp){
	proc=((float)bp/ub)*100;
	printf("Najpopularnija boja je plava (%.2f%%).", proc);
}
	return 0;
}
