#include <stdio.h>

int main() {
	int r,k,sk,i,j;
	do{
	printf("Unesite broj redova: ");
	scanf("%d",&r);
	printf("Unesite broj kolona: ");
	scanf("%d",&k);
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d",&sk);
	}
	while(r<0 && r>=10 && k<0 && k>=10 && sk<0 && sk>=10);
	for (i=0;i<((2*r)+1);i++){
		if (i%2!=0){
			for(j=0;j<((sk*k)+k+1);j++){
				if (j=0 || j%(sk+1)==0) printf ("+");
				if (j%(sk+1)!=0) printf("-");
				
			}
			printf("\n");
		}
	}
	return 0;
}
