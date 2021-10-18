#include <stdio.h>

int main() {
	char x;
	int i=0,j=0,k=0,m=0,n=0,ukupno;
	float a;
	printf("Unesite vozila: ");
	do {
	
     	scanf("%c",&x);
		if (x=='c'|| x=='C')
		i++;
		else if (x=='b'|| x=='B')
		j++;
		else if (x=='s'|| x=='S')
		k++;
		else if (x=='v'|| x=='V')
		m++;
		else if (x=='p'||x=='P')
		n++;
		else if(x=='k' || x=='K')
		break;
		else printf("Neispravan unos\n");
		
	}
	while (1);
	
     
	ukupno=i+j+k+m+n;
	printf("Ukupno evidentirano %d vozila.\n",ukupno);
	if (ukupno==0){
		printf("Najpopularnija boja je crna (0.00%%).");
		return 0;
	}
	
	if (i>=j && i>=k && i>=m && i>=n){
		a=(100.*i)/ukupno;
		printf("Najpopularnija boja je crna (%.2f%%).",a);
		return 0;
	}
	
	if (j>=i && j>=k && j>=m && j>=n){
	     a=(100.*j)/ukupno;
	     printf("Najpopularnija boja je bijela (%.2f%%).",a);
	   return 0;
	}
	
	if (k>=i && k>=j && k>=m && k>=n){
		a=(100.*k)/ukupno;
		printf("Najpopularnija boja je siva (%.2f%%).",a);
		return 0;
	}
	
	if (m>=i && m>=j && m>=k && m>=n){
		a=(100.*m)/ukupno;
		printf("Najpopularnija boja je crvena (%.2f%%).",a);
		return 0;
		
	}
	if (n>=i && n>=j && n>=k && n>=m){
		a=(100.*n)/ukupno;
		printf("Najpopularnija boja je plava (%.2f%%).",a);
		return 0;
	}
	return 0;
}
