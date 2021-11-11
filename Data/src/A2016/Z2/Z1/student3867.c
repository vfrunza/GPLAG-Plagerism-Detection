#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() 
	{
		int i=0;
		long int n,os=0,dd=0,st=0,pre=0,pom,all=0;
		printf("Unesite broj: ");
		scanf("%ld",&n);
		n=abs(n);
		pom=n;
		while(n>0)
		{
			os=n%10;
			n=(int)(n/10);
			if(i>0)
			{
				dd=abs(pre-os);
				st=pow(10,i);
				all=all+(dd*st);
			}
			pre=os;
			i++;
		}
		all=(int)(all/10);
		if(pom<10)
			all=0;
		printf("%ld",all);
		return 0;
	}