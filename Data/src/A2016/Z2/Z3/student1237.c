#include <stdio.h>
#define vel 10

int main() {
	int n,niz_x[vel],niz_y[vel],i,br=0,x,y;
printf("Unesite broj tacaka: ");
scanf("%d",&n);
	 while(n<=0 || n>10){
	 printf("Pogresan unos\n");
printf("Unesite broj tacaka: ");
scanf("%d",&n);}
	for(i=1;i<=n;i++){
		PONOVI: printf("Unesite %d. tacku: ",i);
		scanf("%d %d",&niz_x[i-1],&niz_y[i-1]);
		if(niz_x[i-1]>=20 || niz_x[i-1]<0 || niz_y[i-1]>=20 || niz_y[i-1]<0){
			printf("Pogresan unos\n");
			goto PONOVI;
		}
	}
for(y=0;y<20;y++){
	for(x=0;x<20;x++){
		br=0;
		for(i=0;i<n;i++){
			if(niz_x[i]==x && niz_y[i]==y){
				br++;
				break;
			}
		}
		if(br!=0) printf("*");
		else printf(" ");
	}
	printf("\n");
}

	return 0;
}

