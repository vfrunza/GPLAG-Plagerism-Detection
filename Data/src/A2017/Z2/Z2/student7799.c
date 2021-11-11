#include <stdio.h>

int main() {
	int i, j=0, a, c, k, brojac=0, n[10]={0}, m[10]={0}, l[10]={0};;
	printf("Unesite velicinu niza: ");
	scanf("%d", &a);
	printf("Unesite clanove niza: ");
	for(i=0;i<a;i++) {
		scanf("%d", &n[i]);
	}
	for(i=0;i<a;i++) {
		l[i]=n[i];
	}
	for(i=0;i<a;i++) {
		while(l[i]!=0) {
			c=l[i]%10;
			brojac++;
			l[i]/=10;
		}
	}
	j=0;
	while(j<brojac) {
	for(k=0;k<a;k++) {
			while(n[k]!=0) {
				
			}
		}
	}
	for(j=0;j<brojac;j++) {
		printf("%d ", m[j]);
	}
	return 0;
}
