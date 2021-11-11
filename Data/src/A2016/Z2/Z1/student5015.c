#include<stdio.h>
#include<stdlib.h>
int main()
{
	int br, cif, cif2, n, k=0, t=0, o=0;
	printf("Unesite broj: ");
	scanf("%d", &br);
	if(br<0)
	br=abs(br);
	while(br!=0)
	{
		cif=br%10;
		br=br/10;
		cif2=br%10;
		n=cif-cif2;
		if(n<0)
		n=abs(n);
		k=k*10+n;
	}
	k=k/10;
	while(k!=0)
	{
		o=k%10;
		t=t*10+o;
		k=k/10;
	}
	printf("%d", t);
	return 0;
}