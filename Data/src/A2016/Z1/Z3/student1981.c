#include <stdio.h>

int main() {
	
	char l;
	int i,c=0,b=0,s=0,v=0,p=0, u=0;
	float uc,ub,us,uv,up;
	
	printf("Unesite vozila: ");

	for(i=0; i<=10000; i++){
	scanf("%c", &l);
	
	if(l=='C' || l=='c') c++;
	if(l=='B' || l=='b') b++;
	if(l=='S' || l=='s') s++;
	 if(l=='V' || l=='v') v++;
	 if(l=='P' || l=='p') p++; 
	if(l=='K' || l=='k') break;
	
	if(l!='c' && l!='C' && l!='b' && l!='B' && l!='S' && l!='s' && l!='V' && l!='v' &&
	l!='p' && l!='P') printf("Neispravan unos\n");
	else u++;
	}
	
	
	printf("Ukupno evidentirano %d vozila.\n", u);
	
	int max=c;
	
	
	
	if(u==0) printf("Najpopularnija boja je crna (0.00%%).");
	else{

	if(b>max) max=b;
	if(s>max) max=s;
	if(v>max) max=v;
	if(p>max) max=p;
	if(u==0) {
	uc=0; ub=0; us=0; uv=0; up=0;
	}
	uc=(float)c/u*100;
	ub=(float)b/u*100;
	us=(float)s/u*100;
	uv=(float)v/u*100;
	up=(float)p/u*100;
	
	
	if(max==b) printf("Najpopularnija boja je bijela (%.2f%%).", ub);
	else if(max==c) printf("Najpopularnija boja je crna (%.2f%%).", uc);
	else if(max==s) printf("Najpopularnija boja je siva (%.2f%%).", us);
	else if(max==v) printf("Najpopularnija boja je crvena (%.2f%%).", uv);
	else if(max==p) printf("Najpopularnija boja je plava (%.2f%%).", up);
		
}
	return 0;
}
