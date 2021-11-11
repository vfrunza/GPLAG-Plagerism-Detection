#include <stdio.h>
int main()
{
	char a='a';
	float pa=0;
	float sa=0;
	float ca=0;
	float ba=0;
	float va=0;
	float uk=0;
	float postotakc,postotakb,postotakv,postotaks,postotakp;
	printf("Unesite vozila: ");
	do{
	scanf("%c",&a);
	
	if(a=='c' || a=='C') ca++;
	else if(a=='b' || a=='B') ba++;
	else if (a=='s' || a=='S') sa++;
	else if (a=='v' || a=='V') va++;
	else if (a=='p' || a=='P') pa++;
	else if (a=='k' || a=='K') break;
	else printf("Neispravan unos\n");
	}while(a!='k' && a!='K');
	uk=ba+va+sa+ca+pa;	
	printf("Ukupno evidentirano %g vozila.\n",uk);
	if(uk==0) printf("Najpopularnija boja je crna (0.00%%).");
	else{
	if(ca>=ba && ca>=va && ca>=sa && ca>=pa)	
	{postotakc=(ca/uk)*100	;
	printf("Najpopularnija boja je crna (%.2f%%).",postotakc);	
	}
	else if(ba>=ca && ba>=va && ba>=sa && ba>=pa)	
	{postotakb=(ba/uk)*100	;
	printf("Najpopularnija boja je bijela (%.2f%%).",postotakb);	
	}
	else if(sa>=ca && sa>=va && sa>=ba && sa>=pa)	
	{postotaks=(sa/uk)*100	;
	printf("Najpopularnija boja je siva (%.2f%%).",postotaks);}
	
	else if(va>=ca && va>=ba && va>=sa && va>=pa)	
	{postotakv=(va/uk)*100;	
	printf("Najpopularnija boja je crvena (%.2f%%).",postotakv);	
	}
	else	if(pa>=ca && pa>=va && pa>=sa && pa>=ba)	
	{postotakp=(pa/uk)*100	;
	printf("Najpopularnija boja je plava (%.2f%%).",postotakp);	
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
		
	}
		
		
		
		return 0;
}