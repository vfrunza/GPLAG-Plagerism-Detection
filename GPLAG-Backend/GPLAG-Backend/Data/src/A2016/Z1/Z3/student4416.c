#include <stdio.h>

int main() {
	char a;
	int x=0,i=0,c=0,b=0,s=0,v=0,p=0,y=0;
	float pr;
	printf("Unesite vozila: ");
	for (;;) {
	scanf ("%c",&a);
	if (a!='c' && a!='C' && a!='b' && a!='B' && a!='s' && a!='S' && a!='v' && a!='V' && a!='p' && a!='P' && a!='k' && a!='K') {
		printf ("Neispravan unos\n");
	}
	switch (a) {
		case 'c': c+=1; i++;
		  break;
		case 'C': c+=1; i++;
		  break;
		case 'b': b+=1; i++;
		  break;
		case 'B': b+=1; i++;
		  break;
		case 's': s+=1;i++;
		  break;
		case 'S': s+=1;i++;
		  break;
		case 'v': v+=1; i++;
		  break;
		case 'V': v+=1; i++;
		  break;
		case 'p': p+=1; i++;
		  break;
		case 'P': p+=1; i++;
		  break;
		case 'k':
		  x++;
		  break;
		  case 'K':
		  x++;
		  break;
	}
	if (x==1) break;
	}
	printf ("Ukupno evidentirano %d vozila.\n",i);
	if (i==0) i++;
	y=0;
	if (c>y) y=c;
	if (b>y) y=b;
	if (s>y) y=s;
	if (v>y) y=v;
	if (p>y) y=p;
	if (y==c) {
		pr=(float)c/i*100;
		printf ("Najpopularnija boja je crna (%.2f%%).",pr);
		}
		else if (y==b) {
		pr=(float) b/i*100;
		printf ("Najpopularnija boja je bijela (%.2f%%).",pr);
		}
		else if (y==s) {
		pr= (float) s/i*100;
		printf ("Najpopularnija boja je siva (%.2f%%).",pr);
		}
		else if (y==v) {
		pr=(float) v/i*100;
		printf ("Najpopularnija boja je crvena (%.2f%%).",pr);
		}
		else if (y==p) {
		pr=(float)p/i*100;
		printf ("Najpopularnija boja je plava (%.2f%%).",pr);
	}
	return 0;
}
