#include <stdio.h>
int main() {
	char slovo;
	int crna=0,siva=0,plava=0,bijela=0,crvena=0;
	float postotak;
	printf("Unesite vozila: ");
	do {
		scanf("%c" , &slovo);
		if(slovo!='c' && slovo!='C' && slovo!='s' && slovo!='S' && slovo!='p' && slovo!='P' && slovo!='b' && slovo!='B' && slovo!='v' && slovo!='V' && slovo!='k' && slovo!='K' )
printf("Neispravan unos\n");
if(slovo=='c'|| slovo=='C')
crna++;
if(slovo=='s'|| slovo=='S')
siva++;
if(slovo=='p'|| slovo=='P')
plava++;
if(slovo=='b'|| slovo=='B')
bijela++;
if(slovo=='v'|| slovo=='V')
crvena++;
if(slovo=='k'|| slovo=='K')
break;
	} while(slovo!='k' || slovo!='K');
	int sve=plava+bijela+siva+crvena+crna;
	float sve1=sve;
	printf("Ukupno evidentirano %d vozila.\n", sve);
	if((crna>=siva) && (crna>=plava) && (crna>=crvena) && (crna>=bijela)) {
		postotak=crna*(100/sve1);
		if(sve1==0)
		postotak=0;
		printf("Najpopularnija boja je crna (%.2f%%).", postotak);
		return 0;
	}
		if((bijela>=siva) && (bijela>=plava) && (bijela>=crvena) && (bijela>=crna)){
		postotak=bijela*(100/sve1);
		if(sve1==0)
		postotak=0;
		printf("Najpopularnija boja je bijela (%.2f%%).", postotak);
		return 0;
	}
		if((crvena>=siva) && (crvena>=plava) && (crvena>=crna)&& (crvena>=bijela)){
		postotak=crvena*(100/sve1);
		if(sve1==0)
		postotak=0;
		printf("Najpopularnija boja je crvena (%.2f%%).", postotak);
		return 0;
	}
		if((plava>=siva) && (plava>=crna) && (plava>=crvena) && (plava>=bijela)){
		postotak=plava*(100/sve1);
		if(sve1==0)
		postotak=0;
		printf("Najpopularnija boja je plava (%.2f%%).", postotak);
		return 0;
	}
		if((siva>=crna) && (siva>=plava) && (siva>=crvena) && (siva>=bijela)){
		postotak=siva*(100/sve1);
		if(sve1==0)
		postotak=0;
		printf("Najpopularnija boja je siva (%.2f%%).", postotak);
		return 0;
	}
	
	return 0;
}
