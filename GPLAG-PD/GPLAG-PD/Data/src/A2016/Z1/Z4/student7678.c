#include <stdio.h>

int main() {
	
	
	int n,g,h,i,j,r=1,d,l,b,s=1,q=1,l1,f,o,e;
	
	do
	{
	printf("Unesite broj n: ");
	scanf("%d",&n);
	if(n<1 || n>50){printf("Pogresan unos\n");}
		
	}while(n<1 || n>50);
	
	if(n==1)
	{
		printf("***");
		return 0;
	}
	
	l=2*n-3-2;
	l1=2*n-3-2;
	
	
		printf("*");
		for(g=1;g<=n*2-3;g++){printf(" ");}
		printf("*");
		for(h=1;h<=n*2-3;h++){printf(" ");}
		printf("*");
		printf("\n");
		
		for(i=1;i<=n-2;i++)
		{
		
		for(j=1;j<=r;j++){printf(" ");}r++;
		printf("*");
		
		for(d=1;d<=l;d++){printf(" ");}l=l-2;
		printf("*");
		for(b=1;b<=q;b++){printf(" ");}q=q+2;
		printf("*");
		for(f=1;f<=l1;f++){printf(" ");}l1=l1-2;
		printf("*");
		
		
		
		
		
		printf("\n");
			
		}
		
		for(o=1;o<=n-1;o++){printf(" ");}
		printf("*");
		for(e=1;e<=n*2-3;e++){printf(" ");}
		printf("*");
		


	
	return 0;
}
