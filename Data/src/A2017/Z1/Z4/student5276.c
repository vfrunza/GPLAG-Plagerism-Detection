#include <stdio.h>

int main() {
	int i, j, r, p, l;
	do {
	printf("Unesite broj redova: ");
	scanf("%d", &r);}
	while (r<=0 || r>10);
	do {
	printf("Unesite broj kolona: ");
	scanf("%d", &p);
	} while (p<=0 || p>10);
	do {
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d", &l); }
	while (l<=0 || l>10);
	//r-redovi,p-kolone,l-sirina
	for(i=0; i<2*r+1; i++) //r-broj |, r+1-broj +
	{
		for(j=0; j<p*l+p+1; j++)//p*l-broj -, p+1-broj +
		{
			if(i%2==0 && j%(l+1)==0){
				printf("+");
			}
		   else if(i%2!=0 && j%(l+1)==0){
			printf("|");
		}
	        else if(i%2==0&&j%(l+1)!=0){
	        	printf("-");
	        } else { printf(" ");
	} } printf("\n");}
	return 0;
}
