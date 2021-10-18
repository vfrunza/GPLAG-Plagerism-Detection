#include <stdio.h>

int main() {
	int i,j;
	int br_reda,br_kolona,sirina;
	do
	{
	printf("Unesite broj redova: ");
	scanf("%d",&br_reda);
	}
	while(br_reda<=0 || br_reda>10);
	
	do
	{
		printf("Unesite broj kolona: ");
		scanf("%d",&br_kolona);
	}
	while(br_kolona<=0 || br_kolona>10);
	
	do{
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d",&sirina);
	}while(sirina<=0 || sirina>10);
	
	for(i=0;i<2*(br_reda)+1;i++)
	for(j=0;j<(br_kolona*(sirina+1)+1);j++)
	{
		if(i%2!=0 && (j%(sirina+1)==0)) printf("|");
		else if(i%2!=0) printf(" ");
		if(i%2==0 && (j%(sirina+1)==0)) printf("+");
		else if(i%2==0) printf("-");
		
		if(j==(br_kolona)*(sirina+1)) printf("\n");
	}
	
	return 0;
}


