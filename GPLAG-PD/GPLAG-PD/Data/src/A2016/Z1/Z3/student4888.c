#include <stdio.h>

int main() {
	//printf("Zadaća 1, Zadatak 3");
	
	printf ("Unesite vozila: ");
	char u;
	int c=0, b=0, s=0, v=0, p=0, br=0;
	
/*	do {
	//	scanf ("%c", &u);
		u = getchar();
		if (u=='c' || u=='C') c++;
		else if (u=='b' || u=='B') b++;
		else if (u=='s' || u=='S') s++;
		else if (u=='v' || u=='V') v++;
		else if (u=='p' || u=='P') p++;
		br++;
	} while (u=='K' || u=='k');
	*/
	
	u = getchar();
	while ( u!= 'k' && u!='K' ) {
		br++;
		if (u=='c' || u=='C') c++;
		else if (u=='b' || u=='B') b++;
		else if (u=='s' || u=='S') s++;
		else if (u=='v' || u=='V') v++;
		else if (u=='p' || u=='P') p++;
		else {
			printf ("Neispravan unos\n");
			u = 'k';
			br--;
		}
		u = getchar();
	}
	
	printf ("Ukupno evidentirano %d vozila.\n", br);
	float np=0, sum=0;
	if (c>np) np=c;
	if (b>np) np=b;
	if (s>np) np=s;
	if (v>np) np=v;
	if (p>np) np=p;
	sum=c+b+s+v+p;
	if (np==c) printf ("Najpopularnija boja je crna ");
	else if (np==b) printf ("Najpopularnija boja je bijela ");
	else if (np==s) printf ("Najpopularnija boja je siva ");
	else if (np==v) printf ("Najpopularnija boja je crvena ");
	else if (np==p) printf ("Najpopularnija boja je plava ");
	float post=0;
	
/*	if (br=!0) {
		post=100*np/sum;
		printf ("(%.2f%).", post);
	}
	else printf ("(0.00%).");
*/

	if (br==0) printf ("(0.00%).");
	else {
		post=100*np/sum;
		printf ("(%.2f%).", post);
	}

	return 0;
}
