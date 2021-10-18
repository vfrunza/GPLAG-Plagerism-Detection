#include <stdio.h>

int main() {
	int i, crna=0, bijela=0, siva=0, crvena=0, plava=0,evidentirano;
	char a, prvi='0';
	float procenat;
	
	printf("Unesite vozila: ");
	
	for(i=0; i<1500; i++){
		scanf("%c",&a);
		
		
		if(a=='k' || a=='K'){
			break;
		}
		
		if(a!='c' && a!='C' &&  a!='b' && a!='B' &&  a!='s' && a!='S' &&  a!='v' &&  a!='V' &&  a!='p' &&  a!='P' &&  a!='k' &&  a!='K') {
			printf("Neispravan unos\n");
		}
		
		 if(a=='c' || a=='C'){
			crna++;
		}
		 if(a=='b' || a=='B'){
			bijela++;
		}
		 if(a=='s' || a=='S'){
			siva++;
		}
		if(a=='v' || a=='V'){
			crvena++;
		}
	    if(a=='p' || a=='P'){
			plava++;
		}
		if(i==0){
			prvi=a;
		}
	}
	
	evidentirano=crna+bijela+siva+crvena+plava;
	printf("Ukupno evidentirano %d vozila.\n",evidentirano);
	
	
	if(evidentirano==0){
		procenat=0;
		printf("Najpopularnija boja je crna (%.2f%%).",procenat);
		
	}
	if(crna>bijela && crna>siva && crna>crvena &&crna>plava){
		procenat=((float)crna/evidentirano)*100;
		printf("Najpopularnija boja je crna (%.2f%%).",procenat);
	}
	else if(bijela>crna && bijela>siva && bijela>crvena && bijela>plava){
		procenat=((float)bijela/evidentirano)*100;
		printf("Najpopularnija boja je bijela (%.2f%%).",procenat);
	}
	else if(siva>crna && siva>bijela && siva>crvena && siva>plava){
		procenat=((float)siva/evidentirano)*100;
		printf("Najpopularnija boja je siva (%.2f%%).",procenat);
	}
	else if(crvena>crna && crvena>bijela && crvena>siva && crvena>plava){
		procenat=((float)crvena/evidentirano)*100;
		printf("Najpopularnija boja je crvena (%.2f%%).",procenat);
	}
	
	else if(plava>crna && plava>bijela && plava>siva && plava>crvena){
		procenat=((float)plava/evidentirano)*100;
		printf("Najpopularnija boja je plava (%.2f%%).",procenat);
	}
	
	else if(siva==plava && crvena==plava && prvi=='S'){
		procenat=((float)siva/evidentirano)*100;
		printf("Najpopularnija boja je siva (%.2f%%).",procenat);
	}
	
	else if(crna==siva && (prvi=='C' || prvi=='c')){
		procenat=((float)crna/evidentirano)*100;
		printf("Najpopularnija boja je crna (%.2f%%).",procenat);
	}
	
	
	return 0;
}
