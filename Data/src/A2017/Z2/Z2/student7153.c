#include <stdio.h>

int main() {
	int i, n, niz1[100], niz2[1000], a, b, c, brojac, globalni_brojac=0, j, niz3[1000], counter, berina=0;
	do{
	printf("Unesite velicinu niza: ");
	scanf("%d", &n);
	}
	while(n<1 || n>100);
	
	printf("Unesite clanove niza: ");
	for(i=0; i<n; i++) {
		scanf("%d", &a);
		if(a>=0) {
			niz1[i]=a;
		}
		else {
			i--;
		}
	}
	
	for(i=0; i<n; i++) {
		b=1;
		brojac=1;
		c=niz1[i];
		while(niz1[i]>9) {
			niz1[i]=niz1[i]/10;
			b=b*10;
			brojac++;
		}
		
		 
			for(j=0; j<brojac; j++) {
				if(j==brojac)
				break;
				else {
				
				niz2[j+globalni_brojac]=c/b;
				c=c%b;
				b=b/10;
				}
			}
	
		
		globalni_brojac=globalni_brojac+brojac;
	}
	
	counter=1;
	j=0;
	niz2[globalni_brojac]=-1;
	for(i=0; i<globalni_brojac; i++) {
		
		
			if (niz2[i]==niz2[i+1]) {
				counter++;
			}
			else {
				niz3[j]=niz2[i];
				berina++;
				niz3[j+1]=counter;
				berina++;
				j=j+2;
				counter=1;
				
			}

	}
	
	printf("Finalni niz glasi:\n");
	for(i=0; i<berina; i++) {
		if(i==berina-1) {
		printf("%d", niz3[i]); }
		else {
			printf("%d ", niz3[i]);
		}
	}
	
	
	
	return 0;
}
