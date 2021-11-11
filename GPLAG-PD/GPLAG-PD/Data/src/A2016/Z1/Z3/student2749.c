#include <stdio.h>

int main() {
	char a,hlopta;
	int auta;
	float c,b,s,v,p,max;
	float procenat;
	c= 0;
	b= 0;
	s= 0;
	v= 0;
	p= 0;
	auta= 0;
	printf("Unesite vozila: ");
	do{
		scanf("%c", &a);
		if(a == 'b' || a == 'B' || a == 'c' || a == 'C' || a == 's' || a == 'S' || a == 'v' || a == 'V' || a == 'p' || a == 'P' || a == 'k' || a == 'K'){
			if(a == 'c' || a == 'C') c++;
			else if(a == 'b' || a == 'B') b++; 
			else if(a == 's' || a == 'S') s++; 
			else if(a == 'v' || a == 'V') v++; 
			else if(a == 'p' || a == 'P') p++; 
			auta++;
		}else{
			printf("Neispravan unos\n");
		}
	}while(a != 'k' && a != 'K');
	max = c;
	hlopta = 'c';
	procenat = c*100/(auta-1);
	if(b > max){
		max = b;
		hlopta = 'b';
		procenat = b*100/(auta-1);
	}
	if(s > max){
		max = s;
		hlopta = 's';
		procenat = s*100/(auta-1);
	}
	if(v > max){
		max = v;
		hlopta = 'v';
		procenat = v*100/(auta-1);
	}
	if(p > max){
		max = p;
		hlopta = 'p';
		procenat = p*100/(auta-1);
	}
	printf("Ukupno evidentirano %d vozila.\n",auta-1);	
	if((auta-1) == 0) printf("Najpopularnija boja je crna (0.00%%).\n");
		else{
			switch(hlopta){
				case 'c':
					printf("Najpopularnija boja je crna (%.2f%%).\n",procenat);
					break;
				case 'b':
					printf("Najpopularnija boja je bijela (%.2f%%).\n",procenat);
					break;
				case 's':
					printf("Najpopularnija boja je siva (%.2f%%).\n",procenat);
					break;
				case 'v':
					printf("Najpopularnija boja je crvena (%.2f%%).\n",procenat);
					break;
				case 'p':
					printf("Najpopularnija boja je plava (%.2f%%).\n",procenat);
					break;
					
				
			}
		}
	return 0;
}
