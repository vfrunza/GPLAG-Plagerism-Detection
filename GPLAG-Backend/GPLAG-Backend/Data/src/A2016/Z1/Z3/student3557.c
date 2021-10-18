#include <stdio.h>
#include <math.h>
int main() {
	
	int znak, i=1;
	float br=0, br1=0, br2=0, br3=0, br4=0, br5=0;
	
	printf("Unesite vozila: ");
	// scanf("%d", &znak);
	
	
	while(1)
	{
		
		znak=getchar();
		if(znak=='k' || znak=='K')
		break;
		
	//	if(znak==' ') printf("Nesto %d", i);
		if( znak!='c' && znak!='C' && znak!='b' && znak!='B' && znak!='s' && znak!='S' && znak!='v' && znak!='V' && znak!='p' && znak!='P'  ) {
		printf("Neispravan unos\n");continue;} 
		br++;
	//	i++;
		
		 if (znak=='c' || znak=='C') br1++;
		 if (znak=='b' || znak=='B') br2++;
		 if (znak=='s' || znak=='S') br3++;
		 if (znak=='v' || znak=='V') br4++;
		 if (znak=='p' || znak=='P') br5++;
	
	}

	printf("Ukupno evidentirano %.0f vozila.\n", br);
	if(br==0) printf("Najpopularnija boja je crna (%.2f%).",br1);
	
	else if(br1>=br2 && br1>=br3 && br1>=br4 && br1>=br5) 
	printf("Najpopularnija boja je crna (%.2f%).", (br1/br)*100);
	
	else if(br2>=br1 && br2>=br3 && br2>=br4 && br2>=br5) 
	printf("Najpopularnija boja je bijela (%.2f%).", (br2/br)*100);
	
	else if(br3>=br2 && br3>=br2 && br3>=br4 && br3>=br5) 
	printf("Najpopularnija boja je siva (%.2f%%).",(br3/br)*100);
	
	else if(br4>=br1 && br4>=br2 && br4>=br3 && br4>=br5) 
	printf("Najpopularnija boja je crvena (%.2f%).", (br4/br)*100);
	
	else if(br5>=br1 && br5>=br2 && br5>=br3 && br5>=br4) 
	printf("Najpopularnija boja je plava (%.2f%)." ,(br5/br)*100);
	
	
	
	return 0;
	
}
