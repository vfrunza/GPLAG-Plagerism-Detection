#include <stdio.h>

int main() {
	int ulaz[100],cifre[1000],izlaz[1000];
	int i=0,j=0,n,m,pom,br,k=0;
	for(;;){
		printf("Unesite velicinu niza: ");
		scanf("%d",&n);
		if(n>0 && n<100) break;
	}
	printf("Unesite clanove niza: ");
	for(;;){
		scanf("%d",&pom);
		if(pom>=0) ulaz[i++]=pom;
		if(i==n) break;
	}
	for(i=0;i<n;i++){
		br=0;
		pom=ulaz[i];
		for(;;){
			pom/=10;
			br++;
			if(pom==0) break;
		}
		pom=ulaz[i];
		m=br;
		for(;;){
			cifre[j+br-1]=pom%10;
			br--;
			if(br==0) break;
			pom/=10;
		}
		j+=m;
	}
	for(i=0;i<j;i++){
		izlaz[k]=cifre[i];
		br=0;
		m=i;
		while(izlaz[k]==cifre[m++]){
			br++;
			if(m==j) break;
		} 
		k++;
		izlaz[k++]=br;
		i+=--br;
	}
	printf("Finalni niz glasi:\n");
	for(i=0;i<k;i++) printf("%d ",izlaz[i]);
	return 0;
}