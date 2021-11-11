#include <stdio.h>

int main() {
float blek,vajt,blu,red,grej;
float p,c,v,s,b,uk;
int crna=0,plava=0,crvena=0,bijela=0,siva=0,ukupno;
char unos,unos1;
printf("Unesite vozila: ");
for(;;){
	scanf("%c",&unos);
	if(unos=='c' || unos=='C'){crna++;}
	else if(unos=='p' || unos=='P'){plava++;}
	else if(unos=='b' || unos=='B'){bijela++;}
	else if(unos=='v' || unos=='V'){crvena++;}
	else if(unos=='s' || unos=='S'){siva++;}

	if(unos!='K' && unos!='k' && unos!='C'  && unos!='c'  && unos!='b'  && unos!='B'  && unos!='P'  && unos!='p'  && unos!='S'  && unos!='s'  && unos!='V'  && unos!='v' || unos==" "){printf("Neispravan unos\n");}
	if(unos=='K' || unos=='k'){ break;}

}

ukupno=crna+plava+crvena+siva+bijela;
	printf("Ukupno evidentirano %d vozila.\n",ukupno);
	p=plava; c=crna; v=crvena; b=bijela; s=siva,uk=ukupno;
	if(crna>=plava && crna>=crvena && crna>=bijela &&crna>=siva){if(ukupno!=0){ blek=c/uk*100; printf("Najpopularnija boja je crna (%.2f%).",blek);}else printf("Najpopularnija boja je crna (0.00%).");}
else	if(siva>=crna && siva>=crvena && siva>=bijela &&siva>=plava)       { grej=s/uk*100; printf("Najpopularnija boja je siva (%.2f%).",grej);}
else	if(plava>=crna && plava>=crvena && plava>=bijela &&plava>=siva)         { blu=p/uk*100; printf("Najpopularnija boja je plava (%.2f%).",blu);}
else	if(crvena>=crna && crvena>=plava && crvena>=bijela &&crvena>=siva)        { red=v/uk*100; printf("Najpopularnija boja je crvena (%.2f%).",red);}
else	if(bijela>=crna && bijela>=crvena && bijela>=plava &&bijela>=siva)     { vajt=b/uk*100; printf("Najpopularnija boja je bijela (%.2f%).",vajt);}









	return 0;
}