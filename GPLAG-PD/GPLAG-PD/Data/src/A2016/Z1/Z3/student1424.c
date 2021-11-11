#include <stdio.h>

int main() {
	char v;
	int crna,bijela,siva,crvena,plava,u;
	float npb;
	crna=0;
	bijela=0;
	siva=0;
	crvena=0;
	plava=0;
	printf("Unesite vozila: ");
	do{
	scanf("%c",&v);
	if(v!='C' && v!='c' && v!='B' && v!='b' && v!='S' && v!='s' && v!='V' && v!='v' && v!='P' && v!='p' && v!='K' && v!='k'){
		printf("Neispravan unos \n");
	}
	if(v=='C' || v=='c'){
		crna++;
	}else
	if(v=='B' || v=='b'){
		bijela++;
	}else
	if(v=='S' || v=='s'){
		siva++;
	}else
	if(v=='V' || v=='v'){ 
		crvena++;
	}else
	if(v=='P' || v=='p'){
		plava++;
	}
	
	}while(v!='K' && v!='k');
	
	u=crna+bijela+siva+crvena+plava;
	printf("Ukupno evidentirano %d vozila.",u);
	if(u==0){
		npb=0;
		printf("\nNajpopularnija boja je crna (%.2f%%).",npb);
	}else
	if(crna>=bijela && crna>=siva && crna>=crvena && crna>=plava){
		npb=crna*(1./u)*100;
		printf("\nNajpopularnija boja je crna (%.2f%%).",npb);
	}else
	if(bijela>crna && bijela>=siva && bijela>=crvena && bijela>=plava){
		npb=bijela*(1./u)*100;
		printf("\nNajpopularnija boja je bijela (%.2f%%).",npb);
	}else
	if(siva>crna && siva>bijela && siva>=crvena && siva>=plava){
		npb=siva*(1./u)*100;
		printf("\nNajpopularnija boja je siva (%.2f%%).",npb);
	}else
	if(crvena>crna && crvena>bijela && crvena>siva && crvena>=plava){
		npb=crvena*(1./u)*100;
		printf("\nNajpopularnija boja je crvena (%.2f%%).",npb);
	}else
	if(plava>crna && plava>bijela && plava>siva && plava>crvena){
		npb=plava*(1./u)*100;
		printf("\nNajpopularnija boja je plava (%.2f%%).",npb);
	}
	
	return 0;
}
