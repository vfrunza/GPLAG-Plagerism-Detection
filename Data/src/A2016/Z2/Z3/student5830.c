#include <stdio.h>

int main() {
	int a[10];
	int b[10];
	char m[20][20];
	int n,i,j,k;
    do{
	printf("Unesite broj tacaka: ");
	scanf("%d",&n);
	if(n<1 || n>10){printf("Pogresan unos\n");
	}}while(n<1 || n>10);

	for(i=0;i<n;i++)
{

printf("Unesite %d. tacku: ",i+1);
	scanf("%d %d",&a[i],&b[i]);
	if(a[i]<0 || a[i]>=20 || b[i]<0 || b[i]>=20){
		printf("Pogresan unos\n"); i--;} 
	
}
	for(i=0;i<20;i++)
	{
		for(j=0;j<20;j++)
		{
			m[i][j]=' ';
		}}
for (k=0;k<n;k++)
{
	for(i=0;i<20;i++)
	{
		for(j=0;j<20;j++)
		{
		if(a[k]==j && b[k]==i) {m[i][j]='*';}
	}	

}
}
	for(i=0;i<20;i++)
	{
		for(j=0;j<20;j++)
		{
		printf("%c",m[i][j]);
	}	
printf("\n");
}
	return 0;
}
