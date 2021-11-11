#include <stdio.h>

int main() {
    int br=0,i,j,x[10]={0},y[10]={0},z;
    char prazno[20][20];
    do{
    printf("Unesite broj tacaka: ");
    scanf("%d",&br);
    if(br<=0 || br>10)
    printf("Pogresan unos\n");
    }while(br<=0 || br>10);
    
    for(i=0;i<20;i++)
    {
    	for(j=0;j<20;j++)
    	{
    		prazno[i][j]=' ';
    	}
    }
    for(i=0;i<br;i++)
    {   do{
    	printf("Unesite %d. tacku: ",i+1);
    	scanf("%d %d",&x[i],&y[i]);
    	if(x[i]>=20 || y[i]>=20 || x[i]<0 || y[i]<0)
    printf("Pogresan unos\n");
    }while(x[i]>=20 || y[i]>=20 || x[i]<0 || y[i]<0);
    }
    for(z=0;z<br;z++)
    {
    	for(i=0;i<20;i++)
    {
    	for(j=0;j<20;j++)
    	{
    		if(i==y[z] && j==x[z])
    		prazno[i][j]='*';
    	}
    }
    }
    
    for(i=0;i<20;i++)
    {
    	for(j=0;j<20;j++)
    	{
    		printf("%c",prazno[i][j]);
    	}
    	printf("\n");
    }
	return 0;
}
