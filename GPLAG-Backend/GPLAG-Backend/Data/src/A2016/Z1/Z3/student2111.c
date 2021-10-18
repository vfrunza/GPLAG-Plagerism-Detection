#include <stdio.h>

int main() {
	char a;
	char x='%';
	int i;
	int crna=0,bijela=0,siva=0,crvena=0,plava=0;
	float procenat,najvise,ukupno=0.0;
	char prva_unesena=0;
	printf("Unesite vozila: ");
	
	for(; ;){
	scanf("%c",&a);
	if(a=='c' || a=='C'){
		crna++;
		ukupno++;
		if(prva_unesena==0){
			prva_unesena='c';
		}
		
	}
	else if(a=='b' || a=='B'){
		bijela++;
		ukupno++;
	if(prva_unesena==0)	prva_unesena='b';
	}
									
									
									
									
	else if(a=='s' || a=='S'){ 
		siva++;
		ukupno++;
		if(prva_unesena==0) prva_unesena='s';
	}
									
									
									
									
									
	else if(a=='v' || a=='V'){
	crvena++;
	ukupno++;
		if(prva_unesena==0) prva_unesena='v';
	}
	else if(a=='p' || a=='P'){
		plava++;
		ukupno++;
		if(prva_unesena==0) prva_unesena='p';
	}

	else if(a=='k' || a=='K'){ break;}
	
		else {printf("Neispravan unos\n");}
	}
	if(ukupno==0){
		printf("Ukupno evidentirano 0 vozila.\n");
		printf("Najpopularnija boja je crna (0.00%c).",x);
		return 0;
	}
	printf("Ukupno evidentirano %.0f vozila.\n",ukupno);
	for(i=1000;i>0;i--){
		if(i==crna || i==bijela || i==siva || i==crvena || i==plava){
			najvise=i;
	procenat=najvise/ukupno*100;
	if(najvise==crna && prva_unesena=='c') { printf("Najpopularnija boja je crna (%.2f%c).",procenat,x); return 0; }
	if(najvise==bijela && prva_unesena=='b') { printf("Najpopularnija boja je bijela (%.2f%c).",procenat,x); return 0; }
	if(najvise==siva && prva_unesena=='s') { printf("Najpopularnija boja je siva (%.2f%c).",procenat,x); return 0;}
	if(najvise==crvena && prva_unesena=='v') { printf("Najpopularnija boja je crvena (%.2f%c).",procenat,x); return 0;}
	if(najvise==plava && prva_unesena=='p') { printf("Najpopularnija boja je plava (%.2f%c).",procenat,x); return 0; }
	
	
	if(najvise==crna) { printf("Najpopularnija boja je crna (%.2f%c).",procenat,x); return 0; }
	if(najvise==bijela) { printf("Najpopularnija boja je bijela (%.2f%c).",procenat,x); return 0; }
	if(najvise==siva) { printf("Najpopularnija boja je siva (%.2f%c).",procenat,x); return 0;}
	if(najvise==crvena) { printf("Najpopularnija boja je crvena (%.2f%c).",procenat,x); return 0;}
	if(najvise==plava) { printf("Najpopularnija boja je plava (%.2f%c).",procenat,x); return 0; }
	
		}
	}

	
	return 0;
}
