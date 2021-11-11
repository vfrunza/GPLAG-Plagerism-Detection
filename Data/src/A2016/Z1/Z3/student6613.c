#include <stdio.h>

int main() {
	char x;
	int j,ubv=0,c=0,b=0,s=0,v=0,p=0,max;
	float pc,ps,pv,pp,pb;
	printf("Unesite vozila: ");


	for(j=0; j<=100000; j++) {
		
		scanf("%c",&x);
	
		
		if(x=='c' || x=='C') c++;
		else if(x=='b' || x=='B') b++;
		else if(x=='s' || x=='S') s++;
		else if(x=='v' || x=='V') v++;
		else if(x=='p' || x=='P') p++;
		else if(x=='k' || x=='K') {break;} 
	
		if(x!='C' && x!='c' && x!='b' && x!='B' && x!='s' && x!='S' && x!='v' && x!='V' && x!='P' && x!='p')
		printf("Neispravan unos\n");
		else ubv++;
			
	}
	
	
	
	printf("Ukupno evidentirano %d vozila.",ubv);

	max=c;
	if(b>max) max=b;
	if(s>max) max=s;
   	if(v>max) max=v;
	if(p>max) max=p;
	
	pc=(float)c/ubv*100;
	pb=(float)b/ubv*100;
	ps=(float)s/ubv*100;
	pv=(float)v/ubv*100;
	pp=(float)p/ubv*100;
	if(ubv==0) {
		pc=0;
		pb=0;
		ps=0;
		pv=0;
		pp=0;
	}
	
	if(max==c) printf("\nNajpopularnija boja je crna (%.2f%%).",pc);
	else if(max==b) printf("\nNajpopularnija boja je bijela (%.2f%%).",pb);
	else if(max==s) printf("\nNajpopularnija boja je siva (%.2f%%).",ps);
	else if(max==v) printf("\nNajpopularnija boja je crvena (%.2f%%).",pv);
	else if(max==p) printf("\nNajpopularnija boja je plava (%.2f%%).",pp);
	return 0;
}
