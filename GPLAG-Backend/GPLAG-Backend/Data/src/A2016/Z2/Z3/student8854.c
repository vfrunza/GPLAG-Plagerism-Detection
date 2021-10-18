#include <stdio.h>

int main() 
{
	
int a[10];
int b[10];
int c,d,e,f,g=0;
do
{printf("Unesite broj tacaka: ");
scanf("%d",&c);
if(c<1 || c>10)
printf("Pogresan unos\n");}
while(c<1 || c>10);






for(e=1;e<=c;e++)
{
do
{
printf("Unesite %d. tacku: ",e);
scanf("%d %d",&a[e],&b[e]);
if(a[e]<0 || a[e]>19 || b[e]<0 || b[e]>19 )
printf("Pogresan unos\n");


}
while(a[e]<0 || a[e]>19 || b[e]<0 || b[e]>19 );
}






for(d=0;d<=19;d++)
{
	for(f=0;f<=19;f++)
	{
		
		
		
		g=0;
		for(e=1;e<=c;e++)
		{if(f==a[e] && d==b[e])
		{printf("*");
		break;}
		else
		{
			g++;
			if(g==c)
			printf(" ");
		}
		}
		
		
		
	}printf("\n");
	
}
	
	







	
	
	
	return 0;
}
