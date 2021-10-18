#include <stdio.h>
int main() {
	int br,i=0,m,n,c,pret=0;
	do{
	printf("Unesite broj tacaka: ");
	scanf("%d", &br);
	if(br>0 && br<=10) break;
		else 
		printf("Pogresan unos\n");
	}while(1);
	int niz1[10];
	int niz2[10];
	do{
		printf("Unesite %d. tacku: ", i+1);
		scanf("%d %d", &niz1[i], &niz2[i]);
		if(niz1[i]<0||niz1[i]>19||niz2[i]<0||niz2[i]>19){
			printf("Pogresan unos\n");
			continue;
		}
		i++;
	}while(i<br);
	for(m=0;m<20;m++){
		for(n=0;n<20;n++){
			for(c=0;c<br;c++){
				if(n==niz1[c]&&m==niz2[c]){
					printf("*");break;
				}
				pret++;
			}
		if(pret==br)
			printf(" ");
		pret=0;
		}
		printf("\n");	
	}
	
	return 0;
}