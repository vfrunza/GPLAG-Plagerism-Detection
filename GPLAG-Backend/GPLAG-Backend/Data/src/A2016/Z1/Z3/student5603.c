#include <stdio.h>

int main() {
	char a;
	int brojac1=0,brojac2=0,brojac3=0,brojac4=0,brojac5=0,brojac=0;
	float br1,br2,br3,br4,br5;
	
	printf("Unesite vozila: ");
     
     do{
     scanf("%c",&a);
     
     
	if(a=='c' || a=='C'){
		brojac1++;
		
	}
	else if(a=='b' || a=='B'){
		brojac2++;
		
	}
	else if(a=='s' || a=='S'){
		brojac3++;
		
	}
	else if(a=='v'||a=='V'){
		brojac4++;
	
	}
	else if(a=='p'||a=='P'){
		brojac5++;
		
	}
	else if (a=='k' || a=='K')
	break;
	else
	printf ("Neispravan unos\n");
     }while(a!='k'||a!='K');
	
brojac = brojac1 + brojac2 + brojac3 + brojac4 + brojac5;
	
	br1=((float)brojac1/brojac)*100;
	br2=((float)brojac2/brojac)*100;
	br3=((float)brojac3/brojac)*100;
	br4=((float)brojac4/brojac)*100;
	br5=((float)brojac5/brojac)*100;
	
	printf("Ukupno evidentirano %d vozila.\n",brojac);
	
	if(brojac==0)
	printf("Najpopularnija boja je crna (%.2f%%).",(float)brojac);
	
	if(br1>=br2 && br1>=br3 && br1>=br4 && br1>=br5){
		printf("Najpopularnija boja je crna (%.2f%%).",br1);
	}
     if(br2>br1 && br2>=br3 && br2>=br4 && br2>=br5){
		printf("Najpopularnija boja je bijela (%.2f%%).",br2);
	}
     if(br3>br1 && br3>br2 && br3>=br4 && br3>=br5){
		printf("Najpopularnija boja je siva (%.2f%%).",br3);
	}
	if(br4>br1 && br4>br2 && br4>br3 && br4>=br5){
		printf("Najpopularnija boja je crvena (%.2f%%).",br4);
	}
     if(br5>br1 && br5>br2 && br5>br3 && br5>br4){
		printf("Najpopularnija boja je plava (%.2f%%).",br5);
	}
	
	
	return 0;
}
