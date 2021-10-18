#include <stdio.h>


int main() {
	int a[10],b[10];
	int i,n=0,m=0;
	printf("Unesite elemente niza A: ");
	for(i=0;i<10;i++)
	{
	    scanf("%d",&a[i]);
	    if(a[i]==-1)
	        break;
	    n++;
	}
	printf("Unesite elemente niza B: ");
	for(i=0;i<10;i++)
	{
	    scanf("%d",&b[i]);
	    if(b[i]==-1)
	        break;
	    m++;
	}
	

	if(n==0)
	{
	    printf("Niz C glasi: ");
	    for(i=0;i<m;i++)
	{
		if(m==9)
			printf("%d",b[i]);
		else
	        printf("%d,",b[i]);
	}
	    return -1;
	}
	
	
	if(m==0)
	{
	    printf("Niz C glasi: ");
	    for(i=0;i<n;i++)
	{
			if(i==n-1)
				printf("%d",a[i]);
			else
	        	printf("%d,",a[i]);
	}
	    return -1;
	}
	printf("Niz C glasi: ");
	for(i=0;i<n;i++)
	{
	    printf("%d,",a[i]);
	}
	for(i=0;i<m;i++)
	{
	    if(i==m-1)
	        printf("%d",b[i]);
	    else
	        printf("%d,",b[i]);
	    
	}
	return 0;
	
}
