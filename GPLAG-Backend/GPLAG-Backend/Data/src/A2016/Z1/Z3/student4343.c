#include <stdio.h>
int main() {
	int brojac=0,c=0,b=0,s=0,v=0,p=0, max;
	float proc=0,n;
	char a;
	printf("Unesite vozila: ");
	do {
		scanf("%c",&a);
	if(a!='\n') 
		{
		if (a!='C' && a!='c' && a!='B' && a!='b'&& a!='S' && a!='s' && a!='V' && a!='v' && a!='P' && a!='p')
			{  if (a=='k' || a=='K') break; printf("Neispravan unos\n");  }

        {
			if (a=='C' || a=='c')	
			{ brojac++; c++;	}
			if (a=='B' || a=='b')	
			{ brojac++; b++;	}
			if (a=='S' || a=='s')	
			{ brojac++; s++;	}
			if (a=='V' || a=='v')
			{ brojac++; v++;	}
			if (a=='P' || a=='p')	
			{ brojac++; p++;	}
			
			max=0;
			if (max<c) max=c;
			if (max<b) max=b;
			if (max<s) max=s;
			if (max<v) max=v;
			if (max<p) max=p;
        }
			if (a=='k' || a=='K') break;
        }	

}while(a!='K' || a!='k');

	printf("Ukupno evidentirano %i vozila.",brojac);
	n=brojac;
	if (max>=1)
	{
	if (max==c){
		proc=(c*100)/n;	printf("\nNajpopularnija boja je crna (%.2f%%).",proc);	return 0;
	}
	if (b==max ){
		proc=(b*100)/n;	printf("\nNajpopularnija boja je bijela (%.2f%%).",proc);return 0;
	}
    if (max==s){
		proc=(s*100)/n;	printf("\nNajpopularnija boja je siva (%.2f%%).",proc); return 0;
	}
	if (max==v){
		proc=(v*100)/n;	printf("\nNajpopularnija boja je crvena (%.2f%%).",proc);return 0;
	}
	if (max==p){
		proc=(p*100)/n;	printf("\nNajpopularnija boja je plava (%.2f%%).",proc);return 0;
	}
}
else printf ("\nNajpopularnija boja je crna (0.00%%).");	return 0;
}