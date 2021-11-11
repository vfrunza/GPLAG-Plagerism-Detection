#include <stdio.h>

int main() {
	int velNiza, clanNiza[100], clanFniza[1000], clanIzl[1000];
	int i=0, j=0, k=0, pomocni, brojac, m;
	while (1) {
		printf("Unesite velicinu niza:");
		scanf("%d",&velNiza);
		if (velNiza<100 && velNiza>0) break;
	}
	
	printf("Unesite clanove niza:");
	
	for (i=0; i<velNiza; i++) {
		scanf("%d", &pomocni);
		if (pomocni >= 0) {
			clanNiza[i]=pomocni;
	}
	}
	
	for (i=1; i<=velNiza; i++) {
		brojac = 0;
		pomocni = clanNiza[i-1];
		while(pomocni>0) {
			pomocni/=10;
			brojac++;
		}
		pomocni = clanNiza[i-1];
		m = brojac;
		while(1) {
			clanFniza[j+brojac-1]=pomocni%10;
			brojac--;
			if(brojac==0) break;
			pomocni/=10;
			
		}
		j+=m;
		}
	for(i=0; i<j; i++){
		clanIzl[k]=clanFniza[i];
		brojac = 0;
		m=i;
		if(m<j) {
			while(clanIzl[k]==clanFniza[m++]){
				brojac++;
			}
		}
			k++;
			clanIzl[k++]=brojac;
			i+=--brojac;
		}
printf("Finalni niz glasi:\n");
for(i = 0; i<k; i++) {
printf("%d ", clanIzl[i]);
}
		
	return 0;
}
//Unesite velicinu niza: 5
//Unesite clanove niza: 233 38 17777 7737 152
//Finalni niz glasi:
	//2 1 3 3 8 1 1 1 7 6 3 1 7 1 1 1 5 1 2 1
