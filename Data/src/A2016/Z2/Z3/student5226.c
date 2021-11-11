#include <stdio.h>

int main() {
	int broj_tacaka,i,j,tacka1[10],tacka2[10],k,b=0;
	do{
	printf("Unesite broj tacaka: ");
	scanf("%d",&broj_tacaka);
	if(broj_tacaka<=10 && broj_tacaka>0)
	break;
	printf("Pogresan unos\n");
	}
	while(broj_tacaka>=11 || broj_tacaka<=0);

	for(i=0;i<broj_tacaka;i++)
	{
		printf("Unesite %d. tacku: ",i+1);
		scanf("%d %d",&tacka1[i],&tacka2[i]);
		if(tacka1[i]>19 || tacka2[i]>19 || tacka1[i]<0 || tacka2[i]<0)
		{
			printf("Pogresan unos\n");
			i=i-1;
			continue;
		}
	
	}

    for(j=0;j<20;j++)
    {
    	for(i=0;i<broj_tacaka;i++)
    	if(j==tacka2[i])
    	{
    		for(k=b;k<20;k++)
    		{
    			
    			if(tacka1[i]==k) {printf("* "); b=k+2; break;}
    		else printf(" ");}
    			
   }
   b=0;
    
    	printf("\n");
    	
    }
		
    	
	
	
	return 0;
}
