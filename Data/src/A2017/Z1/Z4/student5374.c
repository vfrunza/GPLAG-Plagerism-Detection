#include <stdio.h>

int main() {
int BRredovi,BRkolone,BRrazmak,i,j,k,z,t;
	do{
	printf("Unesite broj redova: "); 
	scanf("%d",&BRredovi);
}while(BRredovi<=0 || BRredovi>10);

do{
	printf("Unesite broj kolona: ");
	scanf("%d",&BRkolone);
}while(BRkolone<=0 || BRkolone>10);

do{
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d",&BRrazmak);
}while(BRrazmak<=0 || BRrazmak>10);



for(k=0;k<BRredovi;k++)

{
		for(i=0;i<BRkolone;i++){
		printf("+");
	
		for(j=0;j<BRrazmak;j++){
	printf("-");
}
if(i==BRkolone-1){
	printf("+");
}
	}
printf("\n");

for(z=0;z<BRkolone;z++)
{
	printf("|");
for(t=0;t<BRrazmak;t++)
{
	printf(" ");
	
}
if(z==BRkolone-1)
{
	printf("|");
}
}
printf("\n");	
}
for(i=0;i<BRkolone;i++)
{
		printf("+");
	
		for(j=0;j<BRrazmak;j++)
		{
	printf("-");
	}
if(i==BRkolone-1)
{
	printf("+");
}
}
	return 0;
}
