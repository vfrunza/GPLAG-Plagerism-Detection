#include <stdio.h>

int main() {
	char a='o'; 
float p=0;
int u=0,C1=0,B1=0,S1=0,V1=0,P1=0;
	printf("Unesite vozila: ");
	
	while(a!='k') {
		scanf("%c", &a);
		
		if (a=='C' || a=='c') {
			C1++;
		}
		
		else if(a=='B' || a=='b') {
			B1++;
		}
		else if(a=='S' || a=='s') {
			S1++;
		}
		else if(a=='V' || a=='v') {
			V1++;
		}
		else if(a=='P' || a== 'p') {
			P1++;
		}
		else if (a!='B' && a!='b' && a!='S' && a!='s' && a!='V' && a!='v' && a!='P' && a!='p' && a!='C' && a!='c' &&a!='k' &&a!='K'){
			printf("Neispravan unos\n");
			continue;
		}
		else if (a=='k' || a=='K') {
			break;
		}
		
	}
	u=C1+B1+V1+S1+P1;

	printf("Ukupno evidentirano %d vozila.", u);

	if((C1>B1 && C1>V1 && C1>S1 && C1>P1) || (C1==B1 && C1>V1 && C1>S1 && C1>P1) || (C1>B1 && C1>V1 && C1==S1 && C1>P1) || (C1>B1 && C1>V1 && C1>S1 && C1==P1) || (C1==B1 && C1==S1 && C1==V1 && C1==P1))
	{   
		p=((float) C1/(float) u)*100;
		if (u==0) {
			p=0;
		}
			
		
		printf("\nNajpopularnija boja je crna (%.2f%%).", p);
	}
	
	
	
		if ((B1>C1 && B1>V1 && B1>S1 && B1>P1) || (B1>C1 && B1>V1 && B1==S1 && B1>P1) || (B1>C1 && B1>V1 && B1>S1 && B1==P1) || (B1>C1 && B1==V1 && B1>S1 && B1>P1))
	{
		p=((float) B1/(float) u)*100;
		printf("\nNajpopularnija boja je bijela (%.2f%%).", p);
	}
		else if ((C1==B1 && B1>V1 && B1>S1 && B1>P1))
	{
		p=((float) C1/(float) u)*100;
		printf("\nNajpopularnija boja je crna (%.2f%%).",p);
	}

	
	
		if ((S1>B1 && S1>V1 && S1>C1 && S1>P1) || (S1==V1 && S1>P1 && S1>C1 && S1>B1) || (S1==P1 && S1>V1 && S1>B1 && S1>C1) || (S1==P1 && S1==V1 && S1>C1 && S1>B1))
	{
		p=((float) S1/(float) u)*100;
		printf("\nNajpopularnija boja je siva (%.2f%%).", p);
	}
		else if (S1==B1 && S1==C1 && S1>V1 && S1>P1)
	{
		p=((float) 	C1/(float) u)*100;
		printf("\nNajpopularnija boja je crna (%.2f%%).",p);
	}
	else if (B1>C1 && B1>V1 && B1==S1 && B1>P1) 
	{
		p=((float) B1/(float) u)*100;
		printf("\nNajpopularnija boja je bijela (%.2f%%).",p);
	}
	
	
	
   if((V1>C1 && V1>B1 && V1>S1 && V1>P1) || (V1==P1 && V1>C1 && V1>B1 && V1>S1))
   {
   	p=((float) 	V1/(float) u)*100;
   	printf("\nNajpopularnija boja je crvena (%.2f%%).",p);
   }

else if ( (V1==P1  && V1==S1 && V1==B1 && V1>C1) || (V1==S1 && V1==B1 && V1>C1 && V1>P1)  ) {
	p=((float) B1/(float) u)*100;
		printf("\nNajpopularnija boja je bijela (%.2f%%).", p);
}
	
	else if ( (V1==S1 && V1==B1 && V1==C1 && V1>P1) || (V1==C1 && V1>B1 && V1>S1 && V1>P1) )
	{
		p=((float) C1/(float) u)*100;
		printf("\nNajpopularnija boja je crna (%.2f%%).", p);
	}
	
	
	
	if (P1>V1 && P1>S1 && P1>B1 && P1>C1)  {
			p=((float) P1/(float) u)*100;
		printf("\nNajpopularnija boja je plava (%.2f%%).", p);
	
	}
	else if  (P1==V1 && P1==S1 && P1==B1 && P1>C1) {
			p=((float) B1/(float) u)*100;
		printf("\nNajpopularnija boja je bijela (%.2f%%).", p);
	
	}
	
	
	
	
	
	
	
	return 0;
}
