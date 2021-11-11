#include <stdio.h>

int main() {
	
	char a;
	int i=0,j=0,z=0,m=0,n=0,b=0,max,h=0;
	float postotak,pp;
	
	printf("Unesite vozila: ");
	
	for(b;b<=1000;b++)
	{
		
		scanf("%c",&a);
		if(a=='c' || a=='C'){i=i+1;}
		if(a=='b' || a=='B'){j=j+1;}
		if(a=='s' || a=='S'){z=z+1;}
		if(a=='v' || a=='V'){m=m+1;}
		if(a=='p' || a=='P'){n=n+1;}
		if(a=='k' || a=='K'){break;}
		
		
		if(a!='c' && a!='b' && a!='s' && a!='v' && a!='p' && a!='k' && a!='C' && a!='B' && a!='S' && a!='V'&&  a!='P' && a!='K')
		{printf("Neispravan unos \n");}
		else{h++;}
		
	
		}
		
		printf("Ukupno evidentirano %d vozila.\n",h);
		
		
		max=i;
		if(j>max){max=j;}
		if(z>max){max=z;}
		if(m>max){max=m;}
		if(n>max){max=n;}
		
		 pp=(float)max/h;
		 postotak=pp*100;
		
			if(h==0){printf("Najpopularnija boja je crna (0.00%%).");return 0;}
		
		if(i==max){printf("Najpopularnija boja je crna (%.2f%%).\n",postotak);}
		else if(j==max){printf("Najpopularnija boja je bijela (%.2f%%).\n",postotak);}
		else if(z==max){printf("Najpopularnija boja je siva (%.2f%%).\n",postotak);}
		else if(m==max){printf("Najpopularnija boja je crvena (%.2f%%).\n",postotak);}
		else if(n==max){printf("Najpopularnija boja je plava (%.2f%%).\n",postotak);}
		
	
		
		
		
		
		
		
	return 0;
}
