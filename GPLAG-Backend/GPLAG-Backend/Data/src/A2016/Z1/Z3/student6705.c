#include <stdio.h>


int main() {
	char n,a;
	int br=0, br1=0,br2=0,br3=0,br4=0,br5=0,i;
	double postotak;
	printf("Unesite vozila: ");
	for(i=0;i>=0;i++)
	{
		scanf(" %c", &n);
		a=n;
		if(a=='C' || a=='c') { br1++; br++; }
		else if(a=='B' || a=='b'){ br2++;  br++;}
		else if(a=='S' || a=='s'){ br3++;  br++;}
		else if(a=='V' || a=='v'){ br4++;  br++;}
		else if(a=='P' || a=='p'){ br5++;  br++;}
		else if(a=='K' || a=='k'){ break;  br++;}
		else printf("Neispravan unos\n");
	}
	printf("Ukupno evidentirano %d vozila. \n", br);

	if(br==0) printf("Najpopularnija boja je crna (0.00%).");
	if((br2<br1 || br3<br1  || br4<br1 || br5<br1) && ( br1==br2 || br1==br3 || br1==br4 || br1==br5)) {double b1=br1; postotak=b1/br; printf("Najpopularnija boja je crna (%.2f%).", postotak*100); return 0; }
	if((br1<br2 || br3<br2  || br4<br2 || br5<br2) && (br2==br3 || br2==br4 || br2==br5)) {double b2=br2; postotak=b2/br; printf("Najpopularnija boja je bijela (%.2f%).", postotak*100); return 0; }
	if((br2<br3 || br1<br3  || br4<br3 || br5<br3) && (br3==br4 || br3==br5)) {double b3=br3; postotak=b3/br; printf("Najpopularnija boja je siva (%.2f%).", postotak*100); return 0; }
	if((br2<br4 || br3<br4  || br1<br4 || br5<br4) && (br4==br5)) {double b4=br4; postotak=b4/br; printf("Najpopularnija boja je crvena (%.2f%).", postotak*100); return 0; }
	if(br2<br5 || br3<br5  || br4<br5 || br1<br5) {double b5=br5; postotak=b5/br; printf("Najpopularnija boja je plava (%.2f%).", postotak*100); return 0; }
	
	return 0; 
}
