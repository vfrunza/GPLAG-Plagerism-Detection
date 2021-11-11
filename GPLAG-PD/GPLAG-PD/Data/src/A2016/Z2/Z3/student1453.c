#include <stdio.h>

int main() {
	int n, i=0, u, t, a, fake=0;
	do{
	printf("Unesite broj tacaka: ");
	scanf("%d", &n);
	if(n>0&&n<=10)
		break;
	else
		printf("Pogresan unos\n");
	}while(1);
	int niz1[10];
	int niz2[10];
	do{
		printf("Unesite %d. tacku: ", i+1);
		scanf("%d%d", &niz1[i], &niz2[i]);
		if(niz1[i]<0||niz1[i]>19||niz2[i]<0||niz2[i]>19){
			printf("Pogresan unos\n");
			continue;
		}
		
		i++;
	}while(i<n);


	for(u=0;u<20;u++){
		for(t=0;t<20;t++){
			for(a=0;a<n;a++){
				if(t==niz1[a]&&u==niz2[a]){
					printf("*");
					break;
				}
				fake++;
			}
			
		if(fake==n)
			printf(" ");
		fake=0;
		}
		printf("\n");	
	}
	
	return 0;
}
