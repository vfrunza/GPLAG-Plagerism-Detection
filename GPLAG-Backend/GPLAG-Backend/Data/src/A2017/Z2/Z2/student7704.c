#include <stdio.h>

int main() {
	int niz[101],niz2[101],i,j,n=0,brojac=0,brel,max=1,k;
	do{
	printf("Unesite velicinu niza: ");
	scanf("%d",&brel);
	}while(brel<0 || brel>100);
	printf("Unesite clanove niza: ");
	for(i=0;i<brel;i++)
	{
		do{
		scanf("%d",&niz[i]);
		}while(niz[i]<0);
	}
	for(i=brel-1;i>=0;i--)
	{
		do{
			niz2[n]=niz[i]%10;
			niz[i]=niz[i]/10;
			n++;
		}while(niz[i]!=0);
	}
	printf("Finalni niz glasi:\n");
	{
		for(i=n-1;i>=0;i--)
		{
				if(i==n-1){
				max=1;
				k=niz2[i];
				brojac=0;
					for(j=i;j>=0;j--)
					{
						if(k==niz2[j])
						{
							brojac++;
							if(brojac>max) max=brojac;	
						}
						else
						{
							
							
							brojac=0;
							break;
						}
					
					}
				
				printf("%d %d ",k,max);	
			}
			
			if(i!=n-1 && niz2[i]!=niz2[i+1] )
			{
				max=1;
				k=niz2[i];
				brojac=0;
					for(j=i;j>=0;j--)
					{
						if(k==niz2[j])
						{
							brojac++;
							if(brojac>max) max=brojac;	
						}
						else
						{	
							brojac=0;
							break;
						}
						
					}
				printf("%d %d ",k,max);	
			}
		}
	}
	return 0;
}
