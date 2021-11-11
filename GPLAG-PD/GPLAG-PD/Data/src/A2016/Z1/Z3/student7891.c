#include <stdio.h>

int main() {
	
	char j;
	int a=0,b=0,c=0,d=0,e=0,f,ukupno=0;
	float procenatA, procenatB, procenatC, procenatD, procenatE;
	printf("Unesite vozila: ");

	do
	{
	 	scanf("%c", &j);
	 	if(j=='k' ||j=='K') break; 
	 	else if(j=='c' ||j=='C') {ukupno++; a++;}
	 	else if(j=='b' ||j=='B') { ukupno++; b++;}
	 	else if(j=='s' ||j=='S') {ukupno++; c++;}
	 	else if(j=='v' ||j=='V') {ukupno++; d++;}
	 	else if(j=='p' ||j=='P') {ukupno++; e++;}
	 	else if(j!='c' && j!='C' && j!='b' && j!='B'&& j!='s' &&j!='S' && j!='v'&&j!='V' && j!='p' &&j!='P') printf("Neispravan unos\n");	
	 	
	 } 	 while (j!='k' || j!='K');
	 printf("Ukupno evidentirano %d vozila.\n", ukupno); 
	 
	 f=a;
	 if(b>f) f=b;
	 if(c>f) f=c;
	 if(d>f) f=d;
	 if(e>f) f=e;
	 
	 procenatA=(float)a*100/ukupno;
	 procenatB=(float)b*100/ukupno;
	 procenatC=(float)c*100/ukupno;
	 procenatD=(float)d*100/ukupno;
	 procenatE=(float)e*100/ukupno;
	
	if(ukupno==0) {printf("Najpopularnija boja je crna (0.00%)."); }
	else if(f==a) printf("Najpopularnija boja je crna (%.2f%).", procenatA);
	else if(f==b) printf("Najpopularnija boja je bijela (%.2f%).", procenatB);
	else if(f==c) printf("Najpopularnija boja je siva (%.2f%).", procenatC);
	else if(f==d) printf("Najpopularnija boja je crvena (%.2f%).", procenatD);
	else if(f==e) printf("Najpopularnija boja je plava (%.2f%).", procenatE);
	
	return 0;
}
