#include <stdio.h>

int main() {
	int c=0,b=0,s=0,v=0,p=0,zbir=0;
	char x;
	float u, max=0;
		printf("Unesite vozila: ");
	do{
		scanf("%c", &x);
		if ((x=='c' || x=='C') || (x=='b' || x=='B') || (x=='s' || x=='S') || (x=='v' || x=='V') || (x=='p' || x=='P')||(x=='k' || x=='K')) {
		if (x=='c' || x=='C'){
			c=c+1;
			zbir++;
		}
		if (x=='b' || x=='B'){
			b=b+1;
			zbir++;
		}
		if (x=='s' || x=='S'){
			s=s+1;
			zbir++;
		}
		if (x=='v' || x=='V'){
			v=v+1;
			zbir++;
		}
		if (x=='p' || x=='P'){
			p=p+1;
			zbir++;
		}
		}
		else printf("Neispravan unos\n");
	}
	while(x!='k' && x!='K');
	printf("Ukupno evidentirano %d vozila.\n", zbir);
	
		max=c;
	
	if (b>max && b>=s && b >= v && b>=p && zbir != 0){ max=b;
		u=(max / zbir)*100;
		printf("Najpopularnija boja je bijela (%.2f%%).", u);
		
	}
	else if (s>max && s>=b && s >= v && s>=p && zbir != 0){ max=s;
		u=(max / zbir)*100;
		printf("Najpopularnija boja je siva (%.2f%%).", u);
	}
	else if (v>max && v>=b && v>=s && v>=p && zbir != 0){ max=v;
		u=(max / zbir)*100;
		printf("Najpopularnija boja je crvena (%.2f%%).", u);
	}
	else if (p>max && p>=b && p>=s && p>=v && zbir != 0){ max=p;
		u=(max / zbir)*100;
		printf("Najpopularnija boja je plava (%.2f%%).", u);
	}
	else {
		if (zbir!=0){
		u=(max / zbir)*100;
		printf("Najpopularnija boja je crna (%.2f%%).", u);}
		else {
		printf("Najpopularnija boja je crna (0.00%%).");}
		
	}
	
	return 0;
}
