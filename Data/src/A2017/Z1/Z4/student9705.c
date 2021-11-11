#include <stdio.h>

int main() {
	
	int redovi,kolone,razmaci,i,j,k,z,t;
	
	
	do
{
	printf("Unesite broj redova: ");
	scanf("%d",&redovi);
}
while (redovi<=0 || redovi>10);

	
	
	do
{
	printf("Unesite broj kolona: ");
	scanf("%d",&kolone);
}
while (kolone<=0 || kolone>10);


	do
{
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d",&razmaci);
}
while (razmaci<=0 || razmaci>10);

for(k=0;k<redovi;k++)
{
for(i=0;i<kolone;i++)
{
printf("+");
for(j=0;j<razmaci;j++)
{
	printf("-");
	
}
if(i==kolone-1)
{
	printf("+");
}

}
printf("\n");
for(t=0;t<kolone;t++)
{
	printf("|");
	
	for(z=0;z<razmaci;z++)
	{
		
		printf("brojevi");
		
	}
	
	if(t==kolone-1)
	{
		printf("|");
	}
	

}
printf("\n");

}
for(i=0;i<kolone;i++)
{
printf("+");
for(j=0;j<razmaci;j++)
{
	printf("-");
	
}
if(i==kolone-1)
{
	printf("+");
}
		
}	
	
	
	
	
return 0;	
}
