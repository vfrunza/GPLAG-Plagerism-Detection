#include <stdio.h>
#include <math.h>

int main() 
{
	int a[1000], b[1000], c[1000], d[1000], i, j=0, x, y, z, k, t;
	
	printf("Unesite velicinu niza: ");
	scanf("%d", &x);
	
	printf("Unesite clanove niza: ");
	for(i=0; i<x; i++) scanf("%d", &a[i]);
	
	for(i=0; i<x; i++)
	{
		y=a[i];
		z=0;
		
		do
		{
			z=z*10;
			z=z+y%10;
			y=y/10;
			
		}while(y>0);
		
		do
		{
			c[j]=z%10;
			z=z/10;
			j++;
			
		}while(z>0);
	}
	y=0;
	t=0;
	x=0;
	
	for(i=0; i<j; i++)
	{
		z=1;
		
		for(k=i+1; k<j; k++)
		{
			if(c[i]==c[k]) z++;
			else break;
		}
		i=i+z-1;
		b[y]=z;
		y++;
		
		d[t]=c[i];
		d[t+1]=b[x];

		t=t+2;
		x++;
	}
	
	printf("Finalni niz glasi: \n");
	
	for(i=0; i<t; i++) printf("%d ", d[i]);
	
	return 0;
}