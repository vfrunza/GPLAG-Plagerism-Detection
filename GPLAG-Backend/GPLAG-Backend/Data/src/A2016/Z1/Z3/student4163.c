#include <stdio.h>

int main() {
	char x='W';
	int br1=0,br2=0,br3=0,br4=0,br5=0,br=0;
	float c=0,b=0,v=0,p=0,s=0;
	printf("Unesite vozila: ");
	while(x!='k' && x!='K'){
	scanf(" %c", &x);
		if(x!='c' && x!='b' && x!='v' && x!='p' && x!='s' && x!='S' && x!='B' && x!='C' && x!='V' && x!='P'
		&& x!='k' && x!='K')
		{
			printf("Neispravan unos\n");
			
		}
		else if(x =='c' || x =='b' || x =='v' || x =='p' || x =='s' || x =='C' || x =='B' || x =='V' || x=='P' || x =='S') {
			br++;
			
		}
		if (x=='k' || x == 'K') break;
		
			 if(x=='c' || x=='C') br1++;
			 if(x=='b' || x=='B') br2++;
			 if(x=='v' || x=='V') br4++;
			 if(x=='p' || x=='P') br5++;
			 if(x=='s' || x=='S') br3++;
		}

		c=((float)br1/br)*100;
		b=((float)br2/br)*100;
		v=((float)br4/br)*100;
		p=((float)br5/br)*100;
		s=((float)br3/br)*100;
		
		
			printf("Ukupno evidentirano %d vozila.\n", br);
			
			if(br1==0 && br2==0 && br3==0 && br4==0 && br5==0) printf("Najpopularnija boja je crna (0.00%%).", c);
			else if(br1>br2 && br1>br5 && br1>br3 && br1>br4) printf("Najpopularnija boja je crna (%.2f%%).", c);
			else if(br2>br1 && br2>br5 && br2>br3 && br2>br4) printf("Najpopularnija boja je bijela (%.2f%%).",b);
			else if(br5>br1 && br5>br2 && br5>br3 && br5>br4) printf("Najpopularnija boja je siva (%.2f%%).",s); 
			else if(br3>br1 && br3>br2 && br3>br4 && br3>br5) printf("Najpopularnija boja je crvena (%.2f%%).",v);
			else if(br4>br1 && br4>br2 && br4>br3 && br4>br5) printf("Najpopularnija boja je plava (%.2f%%).", p); 
			else if(br1==br2 && br2==br5 && br5==br3 && br3==br4) printf("Najpopularnija boja je crna (%.2f%%).",c); 
			else if(br1==br2 && br2>br5 && br2>br3 && br2>br4) printf("Najpopularnija boja je crna (%.2f%%).", c); 
			else if(br1==br2 && br2==br5 && br5>br3 && br5>br4)  printf("Najpopularnija boja je crna (%.2f%%).", c); 
			else if(br1==br2 && br2==br5 && br5==br3 && br3>br4) printf("Najpopularnija boja je crna (%.2f%%).", c); 
			else if(br1==br5 && br5>br2 && br5>br3 && br3>br4) printf("Najpopularnija boja je crna (%.2f%%).", c); 
			else if(br1==br3 && br3>br2 && br3>br4 && br3>br5) printf("Najpopularnija boja je crna (%.2f%%).", c); 
			else if(br1==br4 && br4>br2 && br4>br3 && br4>br5) printf("Najpopularnija boja je crna (%.2f%%).", c); 
			else if(br2==br5 && br5>br1 && br5>br3 && br5>br4) printf("Najpopularnija boja je bijela (%.2f%%).", b); 
			else if(br2==br3 && br3>br1 && br3>br4 && br3>br5) printf("Najpopularnija boja je bijela (%.2f%%).", b); 
			else if(br2==br4 && br4>br1 && br4>br3 && br4>br5) printf("Najpopularnija boja je bijela (%.2f%%).", b); 
			else if(br2==br5 && br5==br3 && br3>br1 && br3>br4) printf("Najpopularnija boja je bijela (%.2f%%).", b); 
			else if(br2==br5 && br5==br3 && br3==br4 && br4>br1) printf("Najpopularnija boja je bijela (%.2f%%).", b); 
			else if(br5==br3 && br3>br1 && br3>br2 && br3>br4) printf("Najpopularnija boja je siva (%.2f%%).", s); 
			else if(br5==br4 && br4>br1 && br4>br2 && br4>br3) printf("Najpopularnija boja je siva (%.2f%%).", s); 
			else if(br5==br3 && br3==br4 && br4>br1 && br4>br2) printf("Najpopularnija boja je siva (%.2f%%).", s); 
			else if(br3==br4 && br4>br1 && br4>br2 && br4>br5) printf("Najpopularnija boja je crvena (%.2f%%).", v); 
			
			
			
	return 0;
}
