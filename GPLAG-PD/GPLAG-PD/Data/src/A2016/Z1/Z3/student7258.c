#include <stdio.h>

int main() {
	char x;
	int c=0,b=0,s=0,v=0,p=0,m;
	float procenat,u;
	printf("Unesite vozila: ");
	scanf("%c",&x);
	while (x!='k' || x!='K') {
		if(x=='C' || x=='c' || x=='B' || x=='b' || x=='S' || x=='s' || x=='V' || x=='v' || x=='P' || x=='p') {
			if(x=='C'||x=='c') {
				c=c+1;
			}
			else if(x=='B'||x=='b') { 
				b=b+1;
			}
			else if(x=='S'||x=='s') {
				s=s+1;
			}	
			else if(x=='V'||x=='v') { 
				v=v+1;
			}	
			else if(x=='P'||x=='p') { 
				p=p+1;
			} 
			else if(x=='k'||x=='K'); break; 
		} else if (x!='C' && x!='c' && x!='B' && x!='b' && x!='S' && x!='s' && x!='V' && x!='v' && x!='P' && x!='p') {
		printf("Neispravan unos\n");
	}
}

	u=c+b+s+v+p;
	m=c;
	if(b>m) m=b;
	if(s>m) m=s;
	if(v>m) m=v;
	if(p>m) m=p;
	procenat=m*100/u;
	printf("Ukupno evidentirano %d vozila.\n",u);
	if(m==c) printf("Najpopularnija boja je crna %.2f%%.\n",procenat);
	else if(m==b) printf("Najpopularnija boja je bijela %.2f%%.\n",procenat);
	else if(m==s) printf("Najpopularnija boja je siva %.2f%%.\n",procenat);
	else if(m==v) printf("Najpopularnija boja je crvena %.2f%%.\n",procenat);
	else if(m==p) printf("Najpopularnija boja je plava %.2f%%.\n",procenat);
	return 0;
}
