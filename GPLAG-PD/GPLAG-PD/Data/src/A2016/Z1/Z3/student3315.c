#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
	printf("Unesite vozila: ");
	
	/*varijable za broj pojedinih vozila*/
	int c = 0;
	int b = 0;
	int s = 0;
	int v = 0;
	int p = 0;
	int ukupno = 0;
	char temp;
	while(1) {
		scanf("%c", &temp);
		if(temp == 'k' || temp == 'K') {
			break;
		}
		if(((unsigned char)temp)) {
		switch(temp) {
			case 'c': case 'C':
			c++;
			ukupno++;
			break;
			case 'b': case 'B':
			b++;
			ukupno++;
			break;
			case 's': case 'S':
			s++;
			ukupno++;
			break;
			case 'v': case 'V':
			v++;
			ukupno++;
			break;
			case 'p': case 'P':
			p++;
			ukupno++;
			break;
			default:
			printf("Neispravan unos\n");
			break;
			
		}
		}
	
	}
	
		int max1 = 0;
		int max2 = 0; 
		int max = 0;
		/*najveci broj izmedju crne i bijele*/
		if(c > b) {
			max1 = c;
		} else {
			max1 = b;
		}
		/*najveci broj izmedju sive i plave*/
		if(s > p) {
			max2 = s;
		} else {
			max2 = p;
		}
		
		/*najveci izmedju 2 maxa*/
		if(max1 > max2) {
			max = max1;
		} else {
			max = max2;
		}
		
		/*poredjenje maxa sa crvenom*/
		if(max < v) {
			max = v;
		}
		
		printf("Ukupno evidentirano %d vozila.\n", ukupno);
		float procenat = ((float)max/ukupno)*100.0;
		if(ukupno==0) {
			printf("\nNajpopularnija boja je crna (0.00%).",procenat);
			return 0;
		}
		if(max==b) {
			printf("\nNajpopularnija boja je bijela (%.2f%).",procenat);
		}
		else if(max==c) {
			printf("\nNajpopularnija boja je crna (%.2f%).",procenat);
		}
		else if(max==s) {
			printf("\nNajpopularnija boja je siva (%.2f%).",procenat);
		}
		else if(max==v) {
			printf("\nNajpopularnija boja je crvena (%.2f%).",procenat);
		}
		else if(max==p) {
			printf("\nNajpopularnija boja je plava (%.2f%).",procenat);
		}
			
		

		
		
	return 0;
}
