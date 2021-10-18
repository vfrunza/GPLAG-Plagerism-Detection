#include <stdio.h>

int main() {
	int niz1[100];
	int niz2[1000];
	int i,j=0,k=0,a=0,m=0,p=1,r=0;
	int br=0,suma=0,n;
	printf("Unesite velicinu niza: ");
	scanf("%d", &n);
	printf("Unesite clanove niza: ");
	for(i=0; i<n; i++){
		scanf("%d", &a);
		m=a;
		p=a;
		while(m!=0){
			suma++;
			m=m/10;
		}
		if(a==0){
			suma++;
			j=suma-1;
			niz1[j]=0;
		}
		j=suma-1;
		while(a!=0){
			r=a%10;
			niz1[j]=r;
			a=a/10;
			j--;
		}
	}
	for(i=0; i<suma; i++){
		br=0;
		for(j=i; j<suma; j++){
			if(niz1[j]==niz1[i]) br++;
			else break;
		}
		niz2[k]=niz1[i];
		niz2[++k]=br;
		k++;
		i=i+br-1;
	}
	printf("Finalni niz glasi: ");
	printf("\n");
	for(i=0; i<k; i++){
		printf("%d ", niz2[i]);
	}
	return 0;
}
			
		