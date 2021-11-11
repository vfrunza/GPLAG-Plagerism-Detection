#include <stdio.h>

int main() {
	char x;
	int brojac=0,c=0, b=0,s=0,v=0,p=0;
	float u;
	printf("Unesite vozila: ");
	do
	{
	
		x = getchar();
		if(x == 'k' || x == 'K')
			break;
		if(x == 'c' || x == 'C'){
			brojac++;
			c++;
		}
		else if(x == 'b' || x == 'B'){
			brojac++;
			b++;
		}
		else if(x == 's' || x == 'S'){
			brojac++;
			s++;
		}
		else if(x == 'v' || x == 'V'){
			brojac++;
			v++;
		}
		else if(x == 'p' || x == 'P'){
			brojac++;
			p++;
		}
		else if(x != 'k' && x!='K' && x!= 'c' && x!= 'C' && x!='s' && x!='S' && x!='v' && x!='V' && x!='p' && x!='P')
			printf("Neispravan unos\n");
		
		
		
	}while(x != 'k' && x != 'K');
	
	
	printf("Ukupno evidentirano %d vozila.\n", brojac);
	
	if(brojac != 0){
		
		if(c >= b && c >= s && c>= p && c>= v){
		u = (float) c*100/brojac;
		printf("Najpopularnija boja je crna (%.2f%).",u);
	}
	
		else if(b >= c &&  b>= s &&  b>= p &&  b>=v){
		u = (float)b*100/brojac;
		printf("Najpopularnija boja je bijela (%.2f%).",u);
	}
		else if(s >= c && s>= b && s>= p && s>= v){
		u = (float)s*100/brojac;
		printf("Najpopularnija boja je siva (%.2f%).",u);
	}
		
		else if(v >= c &&  v >= b && v >= s &&  v >= p){
		u = (float)v*100/brojac;
		printf("Najpopularnija boja je crvena (%.2f%).",u);
	}
		
		else if(p >= c && p>= b && p >= s && p >= v){
		u = (float)p*100/brojac;
		printf("Najpopularnija boja je plava (%.2f%).",u);
	}
		
	
	
	}
	
	else if (brojac == 0)
		printf("Najpopularnija boja je crna (0.00%%).");
	
		
	
	
	
	
	return 0;
}
