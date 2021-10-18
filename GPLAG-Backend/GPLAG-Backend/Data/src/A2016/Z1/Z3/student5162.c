#include <stdio.h>

int main() {
	char z;
	float br=0,br1=0,br2=0,br3=0,br4=0,br5=0;
	float npb;
	printf("Unesite vozila: ");
	while(1)
	{
		scanf("%c",&z);
		if(z == 'k' || z=='K') break;
		if(z!='C' && z!='c' && z!='B' && z!='b' && z!='V' && z!='v' && z!='S' && z!='s' && z!='P' && z!='p' && z!='K' && z!='k'){ printf("Neispravan unos\n"); continue;}
		br++;
		if(z=='C' || z=='c') br1++;
		if(z=='B' || z=='b') br2++;
		if(z=='S' || z=='s') br3++;
		if(z=='V' || z=='v') br4++;
		if(z=='P' || z=='p') br5++;
	}
	printf("Ukupno evidentirano %.0f vozila.\n",br);
	if(br==0) printf("Najpopularnija boja je crna (%.2f%%).",br1);
	
	else if(br1>=br2 && br1>=br3 && br1>=br4 && br1>=br5){
		npb=(br1/br)*100;
		printf("Najpopularnija boja je crna (%.2f%%).",npb);
	} else if(br2>=br1 && br2>=br3 && br2>=br4 && br2>=br5){
		npb=(br2/br)*100;
		printf("Najpopularnija boja je bijela (%.2f%%).",npb);
	} else if(br3>=br1 && br3>=br2 && br3>=br4 && br3>=br5){
		npb=(br3/br)*100;
		printf("Najpopularnija boja je siva (%.2f%%).",npb);
	} else if(br4>=br1 && br4>=br2 && br4>=br3 && br4>=br5){
		npb=(br4/br)*100;
		printf("Najpopularnija boja je crvena (%.2f%%).",npb);
	} else if(br5>=br1 && br5>=br2 && br5>=br3 &&br5>=br4){
		npb=(br5/br)*100;
		printf("Najpopularnija boja je plava (%.2f%%).",npb);
	}
	
	
	return 0;
}
