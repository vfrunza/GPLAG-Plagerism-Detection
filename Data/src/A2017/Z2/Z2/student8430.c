#include <stdio.h>

int main() {
	int niz[100], n=0, i=0, broj, cifra, prethodni, c, br=0, prvi, k=0;
	int novi[1000], j=0, vel=0;
	int pomocni[1500];
	
	do {
	printf("Unesite velicinu niza: ");
	scanf("%d", &n);
	}
	while (n<=0); 
	
	printf("Unesite clanove niza: ");
	
	for(i=0; i<n; i++) {
		scanf("%d", &broj);
		if(broj > 0) {
		niz[i] = broj;
		}
		else i--;
	}
	
	/* glavni dio*/
	for(i=0; i<n; i++) {
		c = niz[i];
		while(c != 0) {
			cifra = c%10;
			c /= 10;
			pomocni[j++] = cifra;
		
		}
	}
	
	printf("Pomocni \n");
	for(i=0; i<j; i++) printf("%d ", pomocni[j]);
	
	
	prethodni = pomocni[0];
	for(i=0; i<j; i++) { 
		prvi = pomocni[i];
		if(prvi != prethodni) 
	 {
			novi[k++] = prethodni;
			novi[k++] = br;
			br = 0;
			prethodni = prvi;
		}
		else br++;
	}
	
	printf("Finalni niz glasi:\n");
	for(i=0; i<k; i++) printf("%d ", novi[i]);
	
	
	return 0;
}




/*	if(prva == 0) {
			cifra = c%10;
			prethodni = c%10; }
			
			else {
			cifra = c%10; }
			
				for(i=0; i<n; i++) {
		c = niz[i];
		while(c>0) {
			
			cifra = c%10;
	if(prva ==0) prethodni = c%10; 

			if(cifra == prethodni) {br++; }
			else {
				novi[j] = prethodni; j++;
				novi[j] = br;
				br =0;
				j++;
				vel++;
				prethodni = cifra;
			}
			
			c = c/10;
			prva = 1;
	
		
		}
	}*/
	
	/*
		/* glavni dio
	for(i=0; i<n; i++) {
		c = niz[i];
		while(c != 0) {
			cifra = c%10; 
			c /= 10;
			
			if(prva == 0) 
				{ prethodni = cifra;
					prva =1; }
			if(cifra == prethodni) br++;
			
			else {
				novi[j++] = prethodni;
				novi[j++] = br;
				br=0;
				prethodni = cifra;
			}
			prethodni = cifra;
		
		}
	}
	*/