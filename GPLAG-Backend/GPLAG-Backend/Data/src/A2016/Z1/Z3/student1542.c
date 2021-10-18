#include <stdio.h>

int main (){
	int  plava=0,crvena=0,siva=0,crna=0,bijela=0,suma=0;
	char znak;
	printf("Unesite vozila: ");
	for(;;){
		scanf("%c", &znak);
		if(znak!='C' && znak!='c' && znak!='B' && znak!='b' && znak!='P' && znak!='p' && znak!='S' && znak!='s' && znak!='V' && znak!='v' && znak!='K' && znak!='k' && znak!='\n'){
		printf("Neispravan unos\n");continue;
			
		}
		
		if(znak=='C' || znak == 'c')crna++;
		if(znak=='B' || znak == 'b')bijela++;
		if(znak=='P' || znak == 'p')plava++;
		if(znak=='S' || znak == 's')siva++;
		if(znak=='V' || znak == 'v')crvena++;
		if(znak == 'K' || znak == 'k') break;
		
	}
	   	suma=crna+bijela+siva+crvena+plava;
	  	printf("Ukupno evidentirano %d vozila.\n",suma);
	  	
		if(crna !=0 && crna>=bijela && crna>=plava && crna>=siva && crna>=crvena)
	  	printf("Najpopularnija boja je crna (%.2f%).",crna/(float)suma*100);
	  	else if(bijela>crna && bijela>=plava && bijela>=siva && bijela>=crvena)
	  	printf("Najpopularnija boja je bijela (%.2f%).",bijela/(float)suma*100);
	  	else if(siva>bijela && siva>crna && siva>=plava && siva >=crvena)
	  	printf("Najpopularnija boja je siva (%.2f%).",siva/(float)suma*100);
	  	else if(crvena>crna && crvena>siva && crvena>bijela && crvena>=plava)
	  	printf("Najpopularnija boja je crvena (%.2f%).",crvena/(float)suma*100);
	  	else if(plava>crna && plava>crvena && plava>siva && plava>bijela)
	  	printf("Najpopularnija boja je plava (%.2f%).",plava/(float)suma*100);
	  	else if(crna==0 && bijela ==0 && crvena==0 && plava==0 && siva==0)
	  	printf("Najpopularnija boja je crna (0.00%).");
	  	
	return 0;
}
