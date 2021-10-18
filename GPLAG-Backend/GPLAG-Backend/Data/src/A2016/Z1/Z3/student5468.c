#include <stdio.h>
int main() {
	int i=0,bc=0,bb=0,bs=0,bv=0,bp=0,uba;
	float proc;
	char x;
	printf("Unesite vozila: ");
	do{
		scanf("%c",&x);
		i=i+1;
		if((x=='c') || (x=='C'))
			bc=bc+1;
		if((x=='b') || (x=='B'))
			bb=bb+1;
		if((x=='s') || (x=='S'))
			bs=bs+1;
		if((x=='v') || (x=='V'))
			bv=bv+1;
		if((x=='p') || (x=='P'))
			bp=bp+1;
		if((x=='K') || (x=='k')){
			break;
		}
		if ((x!='c')&&(x!='C')&&(x!='b')&&(x!='B')&&(x!='S')&&(x!='s')&&(x!='V')&&(x!='v')&&(x!='P')&&(x!='p')){
			printf("Neispravan unos\n");
			i=i-1;
		}
	}while(1);
	i=i-1;
	uba=bc+bb+bs+bv+bp;
	printf("Ukupno evidentirano %i vozila.",i);
	if ((bc>=bb) && (bc>=bs) && (bc>=bv) && (bc>=bp)){
		if(uba==0)
		proc=0;
		else
		proc=((float)bc/uba)*100;
		printf("\nNajpopularnija boja je crna (%.2f%%).",proc);
	}
	if ((bb>bc) && (bb>=bs) && (bb>=bv) && (bb>=bp)){
		if(uba==0)
		proc=0;
		else
		proc=((float)bb/uba)*100;
		printf("\nNajpopularnija boja je bijela (%.2f%%).",proc);
	}
	if ((bs>bc) && (bs>bb) && (bs>=bv) && (bs>=bp)){
		if(uba==0)
		proc=0;
		else
		proc=((float)bs/uba)*100;
		printf("\nNajpopularnija boja je siva (%.2f%%).",proc);
	}
	if ((bv>bc) && (bv>bs) && (bv>bb) && (bv>=bp)){
		if(uba==0)
		proc=0;
		else
		proc=((float)bv/uba)*100;
		printf("\nNajpopularnija boja je crvena (%.2f%%).",proc);
	}
	if ((bp>bc) && (bp>bs) && (bp>bv) && (bp>bb)){
		if(uba==0)
		proc=0;
		else
		proc=((float)bp/uba)*100;
		printf("\nNajpopularnija boja je plava (%.2f%%).",proc);
	}
	return 0;
}
