#include <stdio.h>
#define epsilon 0.00001
int main() {
	char x='i';
	int suma=0;
	double  crna=0, crvena=0, siva=0, plava=0, bijela=0;
	printf("Unesite vozila: ");
	while(x!='K' && x!='k' ){
	scanf("%c", &x);
	if(x!='c' && x!='p' && x!='k' && x!='s' && x!='b'&& x!='v' && x!='p' && x!='C' && x!='P' && x!='K' && x!='S' && x!='B'&& x!='V' && x!='P') printf("Neispravan unos\n");
	if(x=='C'){
	suma+=1;
	crna+=1;}
	if(x=='c'){
	suma+=1;
	crna+=1;
	}
	if(x=='B'){
	suma+=1;
	bijela+=1;
	}
	if(x=='b'){
	suma+=1;
	bijela+=1;
	}
	if(x=='S'){
	suma+=1;
	siva+=1;
	}
	if(x=='s'){
	suma+=1;
	siva+=1;
	}
	if(x=='V'){
	suma+=1;
	crvena+=1;
	}
	if(x=='v'){
	suma+=1;
	crvena+=1;
	}
	if(x=='P'){
	suma+=1;
	plava+=1;
	}
	if(x=='p'){
	suma+=1;
	plava+=1;
	}
	
	}
	
	printf("Ukupno evidentirano %d vozila.\n", suma);
	if(crna>=bijela && crna>=siva && crna>=crvena && crna>=plava)
	printf("Najpopularnija boja je crna (%.2f%%).",crna/(suma+epsilon)*100);
	else if(bijela>=crna && bijela>=siva && bijela>=crvena && bijela>=plava)
	printf("Najpopularnija boja je bijela (%.2f%%).",bijela/(suma+epsilon)*100);
	else if(siva>=crna && siva>=bijela && siva>=crvena && siva>=plava)
	printf("Najpopularnija boja je siva (%.2f%%).",siva/(suma+epsilon)*100);
	else if(crvena>=crna && crvena>=bijela && crvena>=siva && crvena>=plava)
	printf("Najpopularnija boja je crvena (%.2f%%).",crvena/(suma+epsilon)*100);
	else if(plava>=crna && plava>=bijela && plava>=siva && plava>=crvena)
	printf("Najpopularnija boja je plava (%.2f%%).",plava/(suma+epsilon)*100);
	return 0;
}

